#include <FirebaseESP8266.h>
#include <FirebaseESP8266HTTPClient.h>
#include <FirebaseJson.h>
#include <jsmn.h>



#include <ESP8266WiFi.h>
#include<ESP8266WIFI.h>
#define FIREBASE_HOST "salinemonitoring.firebaseio.com"
#define FIREBASE_AUTH "0lR47wmzeVe1MtWkVXpTQwut9LtHDkrwx1fMO4es"
#define WIFI_SSID "B4FM-YXNoaXNobmlyYWR3YXI"
#define WIFI_PASSWORD ""
const int interruptPin = 5;
byte length1;
 byte length2;
String dropfactor;
String inivol ;
unsigned int inivolint;
unsigned int dropfactorint;
unsigned int count = 1;
unsigned long previous = 0;
unsigned int elapsed ;
float rate = 0.00;
unsigned int volremain;
float timeremain;
 FirebaseData firebaseData;
void ICACHE_RAM_ATTR  handleInterrupt()
{
  count++;
Serial.println(count);
elapsed=millis()-previous;
if(elapsed!=0)
rate=1000*60/elapsed;
previous=millis();
}
void setup() {

  pinMode(interruptPin, INPUT);
Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected..");
  Serial.print(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  while(!(Firebase.getString(firebaseData,"Ini_vol")))
  { 
    delay(500);
  }

  inivol=(firebaseData.stringData());
  length1=inivol.length();
  inivol.remove(0,2);

 
  inivol.remove(length1-4,2); 
  inivolint=inivol.toInt();
  Serial.println(inivolint);
  
  while(!(Firebase.getString(firebaseData,"Drop_fact")))
    {
      delay(500);
    }
  dropfactor=(firebaseData.stringData());
   length2=dropfactor.length();
  dropfactor.remove(0,2);
  dropfactor.remove(length2-4,2); 
  dropfactorint=dropfactor.toInt();
  Serial.println(dropfactorint);
  
  previous= millis();
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, FALLING);

}
void loop() {
  if (count % 5== 0)
  {
    // rate=rate/10;
    // Serial.print("rate");
    //Serial.println(rate);
    Firebase.setFloat(firebaseData,"Drop_rate", rate);
   }
  
  if (count % 10 == 0)
  {
    volremain = inivolint - (count /dropfactorint);
    Firebase.setInt(firebaseData,"Liquid_rem", volremain);
   
  }
  if (count % 12==0&&rate!=0)
  {
    timeremain = float(volremain * dropfactorint) / rate;
    Firebase.setFloat(firebaseData,"Time_re", timeremain);
}
 

}

/*void calibra()
{  
while(DigitalRead(5))
{
]
  // get value
  // pushbutton=Firebase.getFloat("Push_but"));
  //delay(1000);

  unsigned int i;
  irled = 0;
  for (i = 0; i < 100; i++) {
    //temp=analogRead(A0);
    //rled=irled + temp;
    delay(100);
  }
  iravg = irled / 100;

  Serial.print(iravg);
  irled = 0;
}*/
