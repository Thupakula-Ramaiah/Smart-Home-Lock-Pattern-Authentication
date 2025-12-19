# Smart-Home-Lock-Pattern-Authentication

🔐 Smart Home Lock Pattern Authentication (Arduino)
📌 Project Overview
The Smart Home Lock Pattern Authentication System is an Arduino-based security project that unlocks a door only when the correct keypad pattern is entered. It uses a 4×4 keypad for input, a servo motor as the locking mechanism, and an OLED display to show system status.
This project demonstrates embedded systems concepts, hardware–software integration, and secure access control logic, making it ideal for college projects and resumes.

🗂 Project Structure
smart-home-lock-pattern-authentication/
│
├── main.ino    // Arduino source code

⚙️ Components Used

Arduino UNO
4×4 Matrix Keypad
Servo Motor (for lock/unlock)
OLED Display (SSD1306 – I2C)
Jumper Wires
Breadboard
Power Supply / USB Cable

🔌 Working Principle
The user enters a 5-key pattern using the keypad
The Arduino compares the entered pattern with the stored correct pattern
If the pattern matches:
Servo motor rotates to unlock position
OLED displays “Access Granted”
If the pattern does not match:
Servo remains in locked position
OLED displays “Access Denied”

🧠 Features
Secure pattern-based authentication
Real-time eedback on OLED display
Servo-based physical locking mechanism
Easy to modify pattern and lock angles
Beginner-friendly and interview-ready logic

🛠 Technologies & Libraries Used
Arduino (C)
Keypad.h
Servo.h
Wire.h
Adafruit_GFX.h
Adafruit_SSD1306.h

▶️ How to Run the Project
Connect all hardware components correctly
Open Arduino IDE
Install required libraries from Library Manager
Open main.ino
Select correct Board and Port
Upload the code to Arduino
Enter the pattern using the keypad

🔑 Default Unlock Pattern
1 → 2 → 3 → 6 → 9
(Can be changed in the code)

📈 Applications
Smart home door locks
Electronic lockers
Access control systems
Educational embedded projects

🎯 Future Enhancements
Add buzzer or LED indication
GSM / WiFi alerts
Mobile app integration
EEPROM-based pattern storage

👩‍💻 Author
T.Ramaiah
B.Tech – Electronics and Communication Engineering
