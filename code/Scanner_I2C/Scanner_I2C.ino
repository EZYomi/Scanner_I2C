/*
 CIEL 2 - Mini-Project - Scanner I2C LCD
 FAIT PAR GAINCHE VALENTIN
*/
#include <Wire.h>
#include <LiquidCrystal.h>

// Initialisation de l'écran LCD (rs, en, d4, d5, d6, d7)
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 

void setup() {
  Wire.begin();
  lcd.begin(16, 2);
  lcd.print("Scan I2C ... ");
  delay(1000);
}

void loop() {
  for (byte i = 1; i < 127; i++){
    lcd.clear();
    lcd.print("Test : 0x")
    if (i <16) lcd.print("0");
    lcd.print(i,HEX);
    Wire.beginTransmission(i);
    byte erreur = Wire.endTransmission();

    if (erreur == 0){
      lcd.clear();
      lcd.print("Adresse : ");
      lcd.setCursor(0,1);
      lcd.print("Adresse : 0x");
      if (i<16) lcd.print("0");
      lcd.print(i,HEX);
      delay(3000);
    }
   delay(150);
  }
  lcd.clear();
  lcd.print("Aucun composant");
  delay(2000);
}
