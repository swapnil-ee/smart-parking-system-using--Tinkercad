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