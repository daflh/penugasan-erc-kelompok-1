#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int waterLevel = A0;
const int UStrig = 9;
const int USecho = 10;
const int interruptPin = 2;

LiquidCrystal_I2C lcd (0x27, 16, 2);

long bowlPercentage;
const int threshold = 30;
long distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(UStrig, OUTPUT);
  pinMode(USecho, INPUT);
  lcd.begin(16, 2);
  attachInterrupt(digitalPinToInterrupt(interruptPin), fillWater, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  getTankLevel(&distance);
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(1, 0);
  lcd.print("Status: ");

  if (distance > 28) {
    lcd.setCursor(9, 0);
    lcd.print("Refill"); 
  } else {
    lcd.setCursor(9, 0);
    lcd.print("Terisi");
  }

  getBowlPercentage(&bowlPercentage);
  if (bowlPercentage < threshold) {
    digitalWrite(interruptPin, LOW);
    delay(10);
  }

  delay(10000); // delay 10 detik
  lcd.clear();
}

void getTankLevel(long *distance) {
  digitalWrite(UStrig, LOW);
  delayMicroseconds(2);
  digitalWrite(UStrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(UStrig, LOW);

  long duration = pulseIn(USecho, HIGH);
  *distance = duration * 0.0343 / 2;
}

void getBowlPercentage(long *bowlPercentage) {
  *bowlPercentage = map(analogRead(waterLevel), 0, 1023, 0, 100);
}

void fillWater() {

}