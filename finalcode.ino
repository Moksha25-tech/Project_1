#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Pin assignments
#define DHTPIN 4          // DHT sensor pin
#define DHTTYPE DHT22     // DHT22 sensor type
#define SSD1306_I2C_ADDRESS 0x3C // OLED I2C address
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1     // Reset pin (not used)
#define SENSOR1_PIN 9     // IR Sensor 1 pin
#define SENSOR2_PIN 13    // IR Sensor 2 pin
#define LED_PIN1 3        // LED 1 (PWM)
#define LED_PIN2 5        // LED 2 (PWM)
#define LED_PIN3 6        // LED 3 (PWM)
#define IR_SENSOR1 8      // IR sensor 1
#define IR_SENSOR2 9      // IR sensor 2
#define IR_SENSOR3 10     // IR sensor 3
#define sensorPin  12     // LDR sensor pin

// Constants
const float distance = 0.5; // Distance between IR sensors in meters
const int dimBrightness = 1;  // Low brightness (turned off for light detection)
const int maxBrightness = 255; // Max brightness (fully on for IR sensor detection)

// Objects and variables
DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
float hum = 0.0, temp = 0.0, velocity = 0.0;
unsigned long timeSensor1 = 0, timeSensor2 = 0;
int currentBrightness1 = dimBrightness;
int currentBrightness2 = dimBrightness;
int currentBrightness3 = dimBrightness;

void setup() {
  // Serial Monitor initialization
  Serial.begin(9600);

  // Initialize DHT sensor
  dht.begin();

  // Initialize OLED display
  if (!display.begin(SSD1306_I2C_ADDRESS, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("System Initializing..."));
  display.display();
  delay(2000);

  // Set sensor pins as input
  pinMode(SENSOR1_PIN, INPUT);
  pinMode(SENSOR2_PIN, INPUT);
  pinMode(IR_SENSOR1, INPUT);
  pinMode(IR_SENSOR2, INPUT);
  pinMode(IR_SENSOR3, INPUT);
  pinMode(sensorPin, INPUT);  // LDR sensor pin

  // Set LED pins as output
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
}

void loop() {
  // Check LDR sensor value to decide LED behavior
  int ldrValue = digitalRead(sensorPin); // Read the LDR value

  if (ldrValue == LOW) {
    // If light is detected (LDR is in light), turn off LEDs
    analogWrite(LED_PIN1, 0);
    analogWrite(LED_PIN2, 0);
    analogWrite(LED_PIN3, 0);
  } else {
    // If no light is detected (LDR is in darkness), control LEDs based on IR sensors
    controlLEDs();
  }

  // Update DHT sensor data
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  
  // Display temperature and humidity
  if (!isnan(hum) && !isnan(temp)) {
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
  } else {
    Serial.println(F("Failed to read from DHT sensor!"));
  }

  // Check IR sensors for velocity calculation
  if (digitalRead(SENSOR1_PIN) == LOW) {
    timeSensor1 = micros();
    delay(5); // Debounce
  }

  if (digitalRead(SENSOR2_PIN) == LOW) {
    timeSensor2 = micros();
    float timeTaken = (timeSensor2 - timeSensor1) / 1e6;
    if (timeTaken > 0) {
      velocity = distance / timeTaken;
      Serial.print("Time Taken: ");
      Serial.print(timeTaken, 6);
      Serial.println(" seconds");
      Serial.print("Velocity: ");
      Serial.print(velocity, 2);
      Serial.println(" m/s");
    } else {
      velocity = 0.0;
      Serial.println("Invalid time taken");
    }
    timeSensor1 = 0;
    timeSensor2 = 0;
  }

  // Update OLED display
  displayData();
  
  delay(10); // Short delay for stability
}

void controlLEDs() {
  // Check IR sensors for object detection
  int irValue1 = digitalRead(IR_SENSOR1);
  int irValue2 = digitalRead(IR_SENSOR2);
  int irValue3 = digitalRead(IR_SENSOR3);

  int targetBrightness1 = (irValue1 == LOW) ? maxBrightness : dimBrightness;
  int targetBrightness2 = (irValue2 == LOW) ? maxBrightness : dimBrightness;
  int targetBrightness3 = (irValue3 == LOW) ? maxBrightness : dimBrightness;

  adjustBrightness(LED_PIN1, currentBrightness1, targetBrightness1);
  adjustBrightness(LED_PIN2, currentBrightness2, targetBrightness2);
  adjustBrightness(LED_PIN3, currentBrightness3, targetBrightness3);
}

void adjustBrightness(int ledPin, int &currentBrightness, int targetBrightness) {
  if (currentBrightness < targetBrightness) {
    currentBrightness++;
  } else if (currentBrightness > targetBrightness) {
    currentBrightness--;
  }
  analogWrite(ledPin, currentBrightness);
}

void displayData() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("Temp & Humidity"));
  display.setCursor(0, 10);
  display.print("Temp: ");
  display.print(temp);
  display.println(" C");
  display.setCursor(0, 20);
  display.print("Hum: ");
  display.print(hum);
  display.println(" %");
  display.setCursor(0, 35);
  display.println(F("Velocity"));
  display.setCursor(0, 45);
  display.print("Speed: ");
  display.print(velocity, 2);
  display.println(" m/s");
  display.display();
}
