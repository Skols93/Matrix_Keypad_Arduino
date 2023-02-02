#include <LiquidCrystal_I2C.h>  //Using Liquid crystal library

LiquidCrystal_I2C lcd(0x3F,16,4); //Make an instance object of the class LiquidCrystal_I2C


char c = 'A'; // use a charachter variable and give a value of 'A' to it

void setup() {
  lcd.init();                      // initialize the lcd 
  
  lcd.backlight();
  
  //INPUT and OUTPUTS of the Arduino which the keypad is attached
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

  Serial.begin(115200); //serial begin with 115200 baud rate
  
}

void loop() {
  
  // in the loop we make the multiplexing method 
  //we put on the row pins 001, 010 and 100 on the row pins and we scan the column pins
  //
  digitalWrite(4, HIGH); digitalWrite(2, LOW); digitalWrite(3, LOW); // combination of '001' on the row pins
  //with the if cases we scan and determine the pressed key
  // logical AND is used to take just one pressed key
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

  digitalWrite(3, HIGH); digitalWrite(2, LOW); digitalWrite(4, LOW); //combination of '010' on the row pins
  //with the if cases we scan and determine the pressed key
  // logical AND is used to take just one pressed key
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

  digitalWrite(2, HIGH); digitalWrite(4, LOW); digitalWrite(3, LOW); //combination of '100' on the row pins
  //with the if cases we scan and determine the pressed key
  // logical AND is used to take just one pressed key
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

  if(c!='A') // if key is being pressed the code is printing on the serial and LCD display 
  {
    lcd.setCursor(0,0);
    
    lcd.print("Pushed key:");
    lcd.setCursor(0, 1);
    lcd.print(c);
    Serial.println(c);
    c = 'A';                     // we give a value 'A' again just that we want to see once a key is pressed, after the key is pressed the old key is rewriten with the new one
    // and we go over again 
    Serial.println(c);
  }

}
