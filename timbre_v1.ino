#include <Wire.h>
#include "RTClib.h"




RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int rele = 6;




// Hours de clase tiempo en minutos

String Hours[] = {
  "7:02 am",
  "8:00 am", 
  "8:50 am", 
  "9:40 am", 
  "10:00 am", 
  "10:50 am", 
  "11:40 am", 
  "12:20 pm", 
  "1:00 pm", 
  "1:50 pm", 
  "2:40 pm"
};





void setup(){
 
  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH);  
  Serial.begin(9600);
  
if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

 
   
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
   
  
  
 
}






void loop() {

  DateTime now = rtc.now();

  
  
  int weekDay   = now.day();
  int hourDay   = now.hour();
  int minuteDay = now.minute();
  int secondDay = now.second();
 
  // Button state on, not weekend, not woking hours 
  String timeNowString = ""+ String(hourDay) +""+ String(minuteDay);
  int caseSwitch = timeNowString.toInt();
  Serial.println(caseSwitch);
  
  
  if( ( weekDay > 0 && weekDay < 7) && (hourDay > 6 && hourDay < 15 )) {
      
    switch (caseSwitch) {
        case 72:
              ring();   
        break;
        
        case 80:
              ring();
        break;
        
        case 850:
              ring();
        break;
        
        case 940:
              ring();
        break;
        
        case 100:
              ring();
        break;
        
        case 1050:
              ring();
        break;
        
        case 1140:
              ring();
        break;
        
        case 1220:
              ring();
        break;
        
        case 130:
              ring();
        break;
        
        case 1350:
              ring();
        break;
        
        
        case 1440:
              Serial.println("Bye!!, end the day.");
              ring();
        break;
        
        default:
            Serial.println("Time between hours doorbell off");
            printTime();
            digitalWrite(rele, HIGH); 
        break;
    }
   
    

  } 
  else {
    Serial.println("In weekend or not working hours and doorbell off");
    digitalWrite(rele, HIGH);
    printTime();
  }
  
  
  
}


void ring() {
 printTime();
 Serial.println("doorbell on");  
 digitalWrite(rele, LOW);

 waitRing();
 
 digitalWrite(rele, HIGH);     
 Serial.println("doorbell off");
 waitMinute();
}


void printTime(){
  
  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
 
  delay(1000);
}



void waitMinute() {
   DateTime now = rtc.now();


  int minuteWait = now.minute();
  
  while(minuteWait == now.minute()){
    delay(1000);
  }
   
   
}


void waitRing() {
    
  DateTime now = rtc.now();
  
  int waitSeconds = now.second();

  while((now.second() - waitSeconds)  < 6){
    delay(1000);
  }
  
}
