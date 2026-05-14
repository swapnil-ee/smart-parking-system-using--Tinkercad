# smart-parking-system-using--Tinkercad


This project automatically detects vehicles near the parking gate and opens the gate when parking is available.

---

# 📌 Features

✅ Vehicle Detection using Ultrasonic Sensor  
✅ Automatic Gate Opening using Servo Motor  
✅ Green & Red LED Indicators  
✅ LCD Display Status Messages  
✅ Real-Time Distance Monitoring  
✅ Fully Virtual Simulation using Tinkercad  

---

# 🛠 Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Servo Motor | 1 |
| 16x2 LCD I2C Display | 1 |
| Green LED | 1 |
| Red LED | 1 |
| 220Ω Resistor | 2 |
| Breadboard | 1 |
| Jumper Wires | Multiple |

---

# 💻 Software Used

- Tinkercad Circuits
- Arduino IDE

---

# ⚙️ Working Principle

1. Ultrasonic sensor detects vehicle distance.
2. Arduino calculates distance.
3. If vehicle distance is less than 10 cm:
   - Green LED turns ON
   - Servo motor opens gate
   - LCD displays "Parking Free"
4. After few seconds gate closes automatically.
5. If no vehicle detected:
   - Red LED turns ON
   - LCD shows waiting message.

---

# 🔌 Circuit Connections

## Ultrasonic Sensor Connections

| HC-SR04 Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | Pin 9 |
| ECHO | Pin 10 |

---

## Servo Motor Connections

| Servo Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| Signal | Pin 6 |

---

## LED Connections

| LED | Arduino Pin |
|---|---|
| Green LED | Pin 3 |
| Red LED | Pin 4 |

---

## LCD I2C Connections

| LCD Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

---

# 📟 Arduino Code

```cpp
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo gate;

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 10;

const int greenLED = 3;
const int redLED = 4;

long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  gate.attach(6);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Smart Parking");

  lcd.setCursor(0,1);
  lcd.print("System Ready");

  delay(2000);

  lcd.clear();

  gate.write(0);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance < 10)
  {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Parking Free");

    lcd.setCursor(0,1);
    lcd.print("Gate Opening");

    gate.write(90);

    delay(3000);

    gate.write(0);

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Gate Closed");
  }
  else
  {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("No Vehicle");

    lcd.setCursor(0,1);
    lcd.print("Waiting...");
  }

  delay(500);
}
```

# 🔗 Tinkercad Simulation

https://www.tinkercad.com/things/lwoDuJWxqj6-smart-parking?sharecode=2j-pzjRgWSebbejSViUb_jO3_bW7h1AVeNeoGPxmSnc

---

# 🎯 Learning Outcomes

Through this project I learned:

- Arduino programming basics
- Sensor interfacing
- Servo motor control
- LCD display interfacing
- Automation logic
- Real-time embedded system concepts

---

# 👨‍💻 Author

Swapnil Sakhare  
Electronics Engineering Student  
Government College of Engineering, Yavatmal

---

# ⭐ If You Like This Project

Give this repository a star ⭐
