 
#include "LiquidCrystal.h"
LiquidCrystal lcd(9,8,7,6,5,4);

int GAS_VAL = 0;

void setup()
{
  pinMode(A0, INPUT); // MQ-5 A0 Pin
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(11,OUTPUT); // LED RED
  pinMode(12,OUTPUT); // LED GREEN
  
  lcd.setCursor(0,1);
  lcd.print("   GAS SENSOR  ");
 
}

void loop()
{
  GAS_VAL = analogRead(A0);
  Serial.println(GAS_VAL);


 if (GAS_VAL > 300)
 {
    lcd.setCursor(0,0);
    lcd.print("GAS LEAK"); //BEEP THE ALARM AND RED LIGHT
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
  }
  
  else
 {
     lcd.setCursor(0,0);
     lcd.print("NO LEAKAGE"); //  GREEN LIGHT
     digitalWrite(11,LOW);
     digitalWrite(12,HIGH);
  }
  
  delay(10); 
}

