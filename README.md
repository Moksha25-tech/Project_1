# **Project Title : Smart Street Lights**

## **Overview**
This project focuses on creating smart street lights that automatically adjust brightness based on object detection and environmental conditions, promoting energy efficiency and safety.

## **Problem Statement**
Traditional streetlights consume excessive energy by staying at full brightness throughout the night, even when not needed. This project aims to address this issue by making streetlights smarter, incorporating IoT-based solutions for enhanced control and monitoring.

## **Importance in IoT-Based Systems**
IoT-enabled smart street lights are a cornerstone of modern smart cities. They:
- Enhance energy efficiency by automating lighting based on environmental data.
- Reduce operational costs with remote monitoring and control.
- Improve public safety through real-time detection and analysis of environmental conditions.
- Lay the foundation for integration with other smart city systems, like traffic monitoring and emergency response.

## **Features**
- **Motion Detection:** IR sensors detect objects and adjust brightness.
- **Environmental Monitoring:** Measures atmospheric temperature and humidity.
- **Energy Efficiency:** Lights glow only during darkness or at night.
- **Object Velocity Measurement:** Calculates the speed of passing objects.

## **Project Journey**
The journey of creating this project was both challenging and rewarding:
1. **Brainstorming Ideas**: After several discussions, we finalized the idea of developing an energy-efficient street light system using IoT and sensors.
2. **Finding Efficient Sensors**: We conducted extensive research to select cost-effective yet reliable components, such as the DHT11 for temperature measurement and MQ-135 for AQI detection.
3. **48+ Hours of Hard Work**: We dedicated countless hours working on the breadboard, ensuring proper connections and functionality of all components.
4. **Debugging for 5+ Hours**: Overcoming multiple issues, we fine-tuned the sensors and microcontroller code for accurate and stable performance.
5. **Final Assembly**: After successful testing, we completed the soldering process to make the system robust and portable.

## **Components Used**
- **Microcontroller:** Arduino Uno
- **Sensors:** 
  - IR sensor for motion detection
  - LDR sensor for detecting darkness / night 
  - DHT22 for temperature and humidity measurement
- **Lighting:** LED lights
- **Other Components:** Resistors, jumper wires, breadboard, PCBs, Soldering Kit, OLED display, power supply

## **Setup Instructions**

### **Hardware Connections**
1. **IR Sensor**: Connect the output pin to a digital pin on the Arduino, VCC to 5V, and GND to ground.
2. **LDR Sensor**: Connect the output pin to a digital pin on the Arduino, VCC to 5V, and GND to ground.
3. **DHT22 Sensor**: Connect the data pin to a digital pin on the Arduino, VCC to 5V, and GND to ground.
4. **LEDs**: Connect the positive leg to PWM pins on the Arduino via resistors and the negative leg to GND.
5. Ensure proper connections and double-check the circuit before powering it on.

### **About the Code**
- The code initializes the sensors, reads their data, and controls the LED brightness based on object detection within the range and environmental parameters.
- Load the provided `finalcode.ino` file into the Arduino IDE, compile it, and upload it to the Arduino.

### **Testing the System**
1. Test the motion detection functionality using the IR sensor.
2. Verify the temperature and humidity readings by comparing them with a standard device.
3. Observe the LED brightness adjustments under different conditions.

## **Future Applications**
- Integration with smart city infrastructure.
- Real-time monitoring and analytics through IoT platforms.
- Solar-powered operation for greater energy savings.
- Use in highways and industrial areas for enhanced safety and visibility.

## **Project Images**
[Circuit Images]
<br>
(![WhatsApp Image 2024-12-28 at 17 36 54_4b3f233b](https://github.com/user-attachments/assets/f84f4385-764a-41ec-b504-14008c6cf5f5)
)
(![WhatsApp Image 2024-12-28 at 17 36 54_34ed5a3f](https://github.com/user-attachments/assets/002290ce-7b23-4816-b0d9-17f290799205)
)

## **Contributions**
**By:** 
<br>
Moksha Choksi 
<br>
Dhanika Kothari  
<br>
This project is a result of collaborative efforts, dedication, passion and innovation. We welcome collaborations from like-minded individuals and organizations to explore new possibilities and create a sustainable future!
