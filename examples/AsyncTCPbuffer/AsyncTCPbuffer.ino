#include <WiFi.h>
#include "AsyncTCP.h"
#include "AsyncTCPbuffer.h"

const char* ssid = "**********";
const char* password = "************";

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.printf("WiFi Failed!\n");
    return;
  }
  Serial.printf("WiFi Connected!\n");
  Serial.println(WiFi.localIP());
  
  AsyncClient* client = new AsyncClient();
  if(!client->connect("www.google.com", 80)){
    Serial.println("Connect Failed");
    return;
  }
  AsyncTCPbuffer buffer(client);
  buffer.write("Hello world!");
  
}

void loop(){
}
