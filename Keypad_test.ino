#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,4);


char c = 'A';

void setup() {
  lcd.init();                      // initialize the lcd 
  
  lcd.backlight();
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(5, INPUT);
  pinMode(6,INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);

  

  Wire.begin();
  Wire.beginTransmission(0x27);
  lcd.begin(16, 2);

  Serial.begin(115200);
  Serial.println("LCD...");
}

void loop() {

  digitalWrite(4, HIGH); digitalWrite(2, LOW); digitalWrite(3, LOW);
  if(digitalRead(5) && (digitalRead(6) == 0) && (digitalRead(7) == 0)  && (digitalRead(8) == 0))
  {
    c = '3';
  }
  if(digitalRead(6) && (digitalRead(5) == 0) && (digitalRead(7) == 0)  && (digitalRead(8) == 0))
  {
    c = '6';
  }
  if(digitalRead(7) && (digitalRead(6) == 0) && (digitalRead(5) == 0)  && (digitalRead(8) == 0))
  {
    c = '9';
  }
  if(digitalRead(8) && (digitalRead(6) == 0) && (digitalRead(7) == 0)  && (digitalRead(5) == 0))
  {
    c = '#';
  }

  delay(30);

  digitalWrite(3, HIGH); digitalWrite(2, LOW); digitalWrite(4, LOW);
  if(digitalRead(5) && (digitalRead(6) == 0) && (digitalRead(7) == 0)  && (digitalRead(8) == 0))
  {
    c = '2';
  }
  if(digitalRead(6) && (digitalRead(5) == 0) && (digitalRead(7) == 0)  && (digitalRead(8) == 0))
  {
    c = '5';
  }
  if(digitalRead(7) && (digitalRead(6) == 0) && (digitalRead(5) == 0)  && (digitalRead(8) == 0))
  {
    c = '8';
  }
  if(digitalRead(8) && (digitalRead(6) == 0) && (digitalRead(7) == 0)  && (digitalRead(5) == 0))
  {
    c ='0';
  }

  delay(30);

  digitalWrite(2, HIGH); digitalWrite(4, LOW); digitalWrite(3, LOW);
  if(digitalRead(5) && (digitalRead(6) == 0) && (digitalRead(7) == 0)  && (digitalRead(8) == 0))
  {
    c ='1';
  }
  if(digitalRead(6) && (digitalRead(5) == 0) && (digitalRead(7) == 0)  && (digitalRead(8) == 0))
  {
    c = '4';
  }
  if(digitalRead(7) && (digitalRead(6) == 0) && (digitalRead(5) == 0)  && (digitalRead(8) == 0))
  {
    c = '7';
  }
  if(digitalRead(8) && (digitalRead(6) == 0) && (digitalRead(7) == 0)  && (digitalRead(5) == 0))
  {
    c = '*';
  }

  delay(30);

  if(c!='A')
  {
    lcd.setCursor(0,0);
    
    lcd.print("Pritisnat e taster:");
    lcd.setCursor(0, 1);
    lcd.print(c);
    Serial.println(c);
    c = 'A';
    Serial.println(c);
  }

}
