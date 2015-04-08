// NeoPixel clock
//based on exsamples on Adafruit Neopixel library 
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library


#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

//needed for RTC
#include <DS1307RTC.h>
#include <Time.h>
#include <Wire.h> //I2C library

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      60

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() 
{
  randomSeed(analogRead(0)); // Random seed using "random" value from A0
  pixels.begin(); // This initializes the NeoPixel library.
    Serial.begin(9600);
      //while (!Serial) ; // wait for serial
  delay(200);
  Serial.println("DS1307RTC Read Test");
  Serial.println("-------------------");

}

void loop() 
{

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
//initialize clock
  tmElements_t tm;

     while (1)
    {
      
      //read clock
      RTC.read(tm);
      
      //test code for clock
                    
    if (RTC.read(tm)) {
      Serial.print("Ok, Time = ");
      print2digits(tm.Hour);
      Serial.write(':');
      print2digits(tm.Minute);
      Serial.write(':');
      print2digits(tm.Second);
      Serial.print(", Date (D/M/Y) = ");
      Serial.print(tm.Day);
      Serial.write('/');
      Serial.print(tm.Month);
      Serial.write('/');
      Serial.print(tmYearToCalendar(tm.Year));
      Serial.println();
    } else {
      if (RTC.chipPresent()) {
        Serial.println("The DS1307 is stopped.  Please run the SetTime");
        Serial.println("example to initialize the time and begin running.");
        Serial.println();
      } else {
        Serial.println("DS1307 read error!  Please check the circuitry.");
        Serial.println();
      }
    }
     print_time (tm.Hour,tm.Minute,random(30),random(30),random(30));

   /* test code
    for (int i=0; i<24;i++)
    {
     for (int x=0;x<60;x++)
     {
            print_time (i,x,random(30),random(30),random(30));
           // delay (50);
     }
    }
    */
    
    
    
     delay (60000);
     turn_all_off();
    
}
}
  
int drawNumber (int number,int place, int red, int green, int blue)
{
int i= (place *15);
switch (number){ 
 case 0: 
 pixels.setPixelColor(i+0, pixels.Color( red, green, blue));    
 pixels.setPixelColor(i+1, pixels.Color( red, green, blue));  
 pixels.setPixelColor(i+2, pixels.Color( red, green, blue));  
 pixels.setPixelColor(i+3, pixels.Color( red, green, blue));  
 pixels.setPixelColor(i+4, pixels.Color( red, green, blue));
 
 pixels.setPixelColor(i+5, pixels.Color( red, green, blue));  
 pixels.setPixelColor(i+6, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+7, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+8, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+9, pixels.Color( red, green, blue));  

 pixels.setPixelColor(i+10, pixels.Color( red, green, blue));  
 pixels.setPixelColor(i+11, pixels.Color( red, green, blue));  
 pixels.setPixelColor(i+12, pixels.Color( red, green, blue));  
 pixels.setPixelColor(i+13, pixels.Color( red, green, blue));  
 pixels.setPixelColor(i+14, pixels.Color( red, green, blue));  

 pixels.show();
break ;

 case 1:
// ykkönen
 pixels.setPixelColor(i+0, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+1, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+2, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+3, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+4, pixels.Color(0,0,0));  

 pixels.setPixelColor(i+5, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+6, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+7, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+8, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+9, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+10, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+11, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+12, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+13, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+14, pixels.Color(0,0,0));  
 
 pixels.show();
break ;

case 2:
 pixels.setPixelColor(i+0, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+1, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+2, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+3, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+4, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+5, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+6, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+7, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+8, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+9, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+10, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+11, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+12, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+13, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+14, pixels.Color(red, green, blue));  

pixels.show();
break;

case 3:
 pixels.setPixelColor(i+0, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+1, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+2, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+3, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+4, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+5, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+6, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+7, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+8, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+9, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+10, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+11, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+12, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+13, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+14, pixels.Color(red, green, blue));  

pixels.show();
break;


case 4:
 pixels.setPixelColor(i+0, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+1, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+2, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+3, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+4, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+5, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+6, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+7, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+8, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+9, pixels.Color(0,0,0));  

 pixels.setPixelColor(i+10, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+11, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+12, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+13, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+14, pixels.Color(red, green, blue));  

pixels.show();
break;


case 5:
 pixels.setPixelColor(i+0, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+1, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+2, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+3, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+4, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+5, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+6, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+7, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+8, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+9, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+10, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+11, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+12, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+13, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+14, pixels.Color(red, green, blue));  

pixels.show();
break;

case 6:
 pixels.setPixelColor(i+0, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+1, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+2, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+3, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+4, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+5, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+6, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+7, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+8, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+9, pixels.Color(0,0,0));  

 pixels.setPixelColor(i+10, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+11, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+12, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+13, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+14, pixels.Color(0,0,0));  

pixels.show();
break;

case 7:
 pixels.setPixelColor(i+0, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+1, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+2, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+3, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+4, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+5, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+6, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+7, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+8, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+9, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+10, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+11, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+12, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+13, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+14, pixels.Color(red, green, blue));  

pixels.show();
break;


case 8:
 pixels.setPixelColor(i+0, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+1, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+2, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+3, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+4, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+5, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+6, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+7, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+8, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+9, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+10, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+11, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+12, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+13, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+14, pixels.Color(red, green, blue));  

pixels.show();
break;

case 9:
 pixels.setPixelColor(i+0, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+1, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+2, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+3, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+4, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+5, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+6, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+7, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+8, pixels.Color(0,0,0));  
 pixels.setPixelColor(i+9, pixels.Color(red, green, blue));  

 pixels.setPixelColor(i+10, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+11, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+12, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+13, pixels.Color(red, green, blue));  
 pixels.setPixelColor(i+14, pixels.Color(red, green, blue));  

pixels.show();
break;



  }
}
  
void turn_all_off(void) 
{
    
  for(int i=0; i<60; i++) 
  {
      pixels.setPixelColor(i, 0);
      pixels.show();
      
  }  
 
}
void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}

void print_time (int tunnit, int minuutit, int red, int green, int blue)
{
 
  if (tunnit >= 0 && tunnit < 10) 
  {
   drawNumber (tunnit,1,red,green,blue);  
  }  
  else if (tunnit >= 10 && tunnit < 20)
 {
      drawNumber ((tunnit-10),1,red,green,blue);  
      drawNumber (1,0,red,green,blue);  

 } 
 
   else if (tunnit >= 20 && tunnit < 30)
 {
      drawNumber ((tunnit-20),1,red,green,blue);  
      drawNumber (2,0,red,green,blue);  
 }
 
  if (minuutit >= 0 && minuutit < 10) 
  {
   drawNumber (minuutit,3,red,green,blue);  
   drawNumber (0,2,red,green,blue);  

  }  
  else if (minuutit >= 10 && minuutit < 20)
 {
      drawNumber ((minuutit-10),3,red,green,blue);  
      drawNumber (1,2,red,green,blue);  

 } 
 
   else if (minuutit >= 20 && minuutit < 30)
 {
      drawNumber ((minuutit-20),3,red,green,blue);  
      drawNumber (2,2,red,green,blue);  
 }
 
   else if (minuutit >= 30 && minuutit < 40)
 {
      drawNumber ((minuutit-30),3,red,green,blue);  
      drawNumber (3,2,red,green,blue);  
 }
 
   else if (minuutit >= 40 && minuutit < 50)
 {
      drawNumber ((minuutit-40),3,red,green,blue);  
      drawNumber (4,2,red,green,blue);  
 }
 
   else if (minuutit >= 50 && minuutit < 60)
 {
      drawNumber ((minuutit-50),3,red,green,blue);  
      drawNumber (5,2,red,green,blue);  
 }
 
}
