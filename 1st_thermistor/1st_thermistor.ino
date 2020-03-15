#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

int low = 0;
int midLow = 20;
int midMid = 60.6;
int midMid2 = 65.2;
int midHigh = 67.1;
int high = 75;

//TMP36 Pin Variables
int sensorPin = 0; 

int LEDGREEN = 2;
int LEDBLUE = 3;
int LEDRED = 4;


//The size of a display.
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

//Makes a display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
void setup()
{
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 

//   Make the actual display and run the Logo
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  
  //Next slide material
  display.display();
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDBLUE, OUTPUT);
  pinMode(LEDRED, OUTPUT);
}
 
void loop()                     // run over and over again
{
 double reading = analogRead(sensorPin);   
 
 double voltage = reading * 5.0;
 
 voltage /= 1024.0; 
 Serial.println(voltage);
 double temperatureC = 95.12232415902203 * voltage -43.24908256880784 ;
 Serial.println(temperatureC); Serial.println(" degrees C");
 
 

 display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print("Voltage: ");
  display.println(voltage);
  display.setCursor(0, 40);
  display.print("Temperature: ");
  display.println(temperatureC);
  
  
  display.display();
  if(temperatureC< midLow && temperatureC>= low)
  {
    digitalWrite(LEDGREEN,LOW);
    digitalWrite(LEDRED, HIGH);
    digitalWrite(LEDBLUE, LOW);
  }
  else if(temperatureC< midMid && temperatureC>= midLow)
  {
    digitalWrite(LEDGREEN,LOW);
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDBLUE, LOW);
  }
  else if(temperatureC< midMid2  && temperatureC>= midMid)
  {
    digitalWrite(LEDGREEN,HIGH);
    digitalWrite(LEDRED, HIGH);
    digitalWrite(LEDBLUE, LOW);
  }
  else if(temperatureC< midHigh && temperatureC>= midMid2)
  {
    digitalWrite(LEDGREEN,HIGH);
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDBLUE, LOW);
  }
  else if(temperatureC< high && temperatureC>= midHigh)
  {
    digitalWrite(LEDGREEN,LOW);
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDBLUE, HIGH);
  }
 
 delay(1000);                                     //waiting a second
}
