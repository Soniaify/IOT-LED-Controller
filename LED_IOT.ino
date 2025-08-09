#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Emmanuel prime";
const char* password = "";

ESP8266WebServer server(80);

int ledpin = D2;

void setup() {
  pinMode(ledpin,OUTPUT);
  Serial.begin(115200);
  Serial.print("connecting to WiFi....");
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("WiFi Connected!\n");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/",[](){
    server.send(200,"text/html",R"rawliteral(
      <div align = "center">
          <h1>IOT Control Dashboard</h1>
          <a href="/led/on"><input type="button" value="Turn On LED" style="color: green;"/></a>
          <a href="/led/off"><input type="button" value="Turn Off LED" style="color: red;"/></a>
      </div>
    )rawliteral");
  });

server.on("/led/on",[](){
  digitalWrite(ledpin,HIGH);
  server.send(200,"text/html", "<p>LED is ON</p><br><a href=\"/\">Back</a>");
});

server.on("/led/off",[](){
  digitalWrite(ledpin,LOW);
  server.send(200,"text/html", "<p>LED is OFF</p><br><a href=\"/\">Back</a>");
});

  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
}
