#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// If using software SPI (the default case):
#define OLED_MOSI  15
#define OLED_CLK   13
#define OLED_DC    0
#define OLED_CS    4
#define OLED_RESET 2

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 23
#define BME_MISO 21
#define BME_MOSI 22
#define BME_CS 19

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK);

void setup()   {                
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  bme.begin();
}

void loop()
{
  long int pres = bme.readPressure();
  double temp = bme.readTemperature();
  double altitude = bme.readAltitude(1013.25);
  double humidity=bme.readHumidity();
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Temp = ");
  display.print(temp);
  Serial.print(temp);
  display.print(" C\n");
  display.print("Pressure = ");
  display.print(pres);
  display.print(" Pa\n");
  display.print("Altitude = ");
  display.print(altitude);
  display.print(" m\n");
  display.print("humidity = ");
  display.print(humidity);
  display.print(" %\n");
  display.display();
  delay(2000);
}
