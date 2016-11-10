#include <DHT11.h>
int pin=7;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT11 dht11(pin); 
void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Reading Values..");
   Serial.begin(9600);
  while (!Serial) {
      ; // wait for serial port to connect. Needed for Leonardo only
    }
}

void loop()
{
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
    lcd.print("Temp:");
    lcd.print(temp);
    lcd.setCursor(0, 1);
    lcd.print("Humidity:");
    lcd.print(humi);
    Serial.print("Temp:");
    Serial.print(temp);
    Serial.println();
    Serial.print("Humidity:");
    Serial.print(humi);
    Serial.println();
  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();  
    lcd.println();
    lcd.print("Error No :");
    lcd.print(err);
    lcd.println();     
  }
  //delay(10000);
  delay(DHT11_RETRY_DELAY); //delay for reread
    lcd.clear();

}



