#include "AIS_SIM7020E_API.h"

String address      = "115.78.92.253";    // Your Server IP
String serverPort   = "40003";    // Your Server Port
String payload = "#860186054706334#MT700#0000#HT#1#35$GPRMC,,V,,,,,,,,,,A*5C##";
//String payload = "23383630313836303534373036333334234d5437303023303030302348542331233335244750524d432c2c562c2c2c2c2c2c2c2c2c2c412a3543232331";
String data_return;

const long interval = 60000;  //millisecond 
unsigned long previousMillis = 0;

AIS_SIM7020E_API nb;
void setup() {
    
  Serial.begin(9600);
  nb.begin(address, serverPort);
  Serial.println(F("\n-------------BEGIN-------------"));
  //Serial.print(F(">>DeviceIP: "));
  //Serial.println(nb.getDeviceIP());
  //nb.pingIP(address);
  previousMillis = millis();
}

void loop() {
  
  data_return = "";
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval){      
      // Send data in String 
      //nb.sendMsgSTR(address,serverPort,payload+String(cnt));
      nb.sendStr(address, serverPort, payload);
      
      // Send data in HexString     
      //nb.sendMsgHEX(address,serverPort,payload+String(cnt));
      previousMillis = currentMillis;  
  }
  nb.waitResponse(data_return, address);
  if (data_return != "") {
    Serial.println("# Receive : " + data_return);
  }
  
  
}
