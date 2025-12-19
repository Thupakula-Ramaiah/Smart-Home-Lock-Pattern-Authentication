//Smart Home Lock Pattern Authentication
#include <Keypad.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

/* ---------- OLED CONFIG ---------- */
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

/* ---------- SERVO ---------- */
Servo lockServo;
int servoPin = 10;     // Servo signal pin
int lockPos = 0;       // Locked position
int unlockPos = 90;   // Unlocked position

/* ---------- KEYPAD CONFIG ---------- */
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};   // R1–R4
byte colPins[COLS] = {5, 4, 3, 2};   // C1–C4

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/* ---------- PATTERN SETTINGS ---------- */
char correctPattern[] = {'1','2','3','6','9'};
char inputPattern[5];
int index = 0;

void setup() {
  Serial.begin(9600);

  lockServo.attach(servoPin);
  lockServo.write(lockPos);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while(true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  display.println("Smart Lock System");
  display.println("Enter Pattern");
  display.display();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);

    inputPattern[index] = key;
    index++;

    display.clearDisplay();
    display.setCursor(0, 20);
    display.print("Pattern: ");
    for (int i = 0; i < index; i++) {
      display.print("* ");
    }
    display.display();

    if (index == 5) {
      checkPattern();
      index = 0;
      delay(1500);
      resetDisplay();
    }
  }
}

void checkPattern() {
  bool match = true;
  for (int i = 0; i < 5; i++) {
    if (inputPattern[i] != correctPattern[i]) {
      match = false;
      break;
    }
  }

  display.clearDisplay();
  display.setCursor(0, 20);

  if (match) {
    display.println("Access Granted");
    lockServo.write(unlockPos);
  } else {
    display.println("Access Denied");
    lockServo.write(lockPos);
  }
  display.display();
}

void resetDisplay() {
  display.clearDisplay();
  display.setCursor(0, 20);
  display.println("Enter Pattern");
  display.display();
}
