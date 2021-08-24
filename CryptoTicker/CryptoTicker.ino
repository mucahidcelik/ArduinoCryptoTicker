#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
const int BUFFER_SIZE = 50;
char buf[BUFFER_SIZE];
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()) {
    lcd.home();
    lcd.setCursor(0, 0);
    lcd.print("ETH: ");
    int rlen = Serial.readBytes(buf, BUFFER_SIZE);
    for (int i = 0; i < 6; i++)
      lcd.print(buf[i]);
    lcd.print("     ");
    lcd.setCursor(0, 1);
    lcd.print("BTC: ");
    for (int i = 6; i < rlen; i++)
      lcd.print(buf[i]);
    lcd.print("    ");
  }


}
