#include <SPI.h>
#include <Ethernet.h>
#include <ArduinoJson.h>

const int chipSelect = 4;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,0,200);

String readString;
EthernetServer server(80);

// Integração com os pinos do Arduino
int cooler1 = 2;//cooler
int led1 = 3; //cozinha
int led2 = 4;//sala
int led3 = 6;//quarto
int led4 = 5;//sala


// Variaveis de controle dos LEDs
boolean ledOne=false;
boolean ledTwo=false;
boolean ledThree=false;
boolean ledFour=false;
boolean coolerOne=false;


void setup() {
  
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
  
  // configura pino digital como saída
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(cooler1, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(cooler1, HIGH);
  
  Serial.println("iniciou...");
}

void loop() {
  EthernetClient client = server.available();
  if (client) {
    Serial.println("Cliente Conectado!");
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (readString.length() < 100){
          readString += c;
        
        }
        if (c == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: application/json;charset=utf-8");
          client.println("Server: Arduino");
          client.println("Connection: close");
          client.println();
          client.print("{\"led1\":");
          client.print(ledOne);
          client.print(", \"led2\":");
          client.print(ledTwo);
          client.print(", \"led3\":");
          client.print(ledThree);
          client.print(", \"cooler\":");
          client.print(coolerOne);
          client.println("}");
          client.println();
          break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
     
    }
    delay(1);
    client.stop();
    Serial.println("Cliente Desconectado!");
    
  }
   //CONTROLE DOS LEDS
    if (readString.indexOf("?led1on") >0){
      // liga o LED
      digitalWrite(led1, HIGH);
      ledOne=false;
      Serial.println("Led 1 e 4 ligou.");  
    }

    if (readString.indexOf("?led1off") >0){
      // desliga o LED
      digitalWrite(led1, LOW);
      ledOne=true;
      Serial.println("Led 1 e 4 desligou.");
    }

    if (readString.indexOf("?led2on") >0){
      digitalWrite(led2, HIGH);
      digitalWrite(led4, HIGH);
      ledTwo=true;
      Serial.println("Led 2 ligou.");  
    }

    if (readString.indexOf("?led2off") >0){
      digitalWrite(led2, LOW); 
      digitalWrite(led4, LOW);
      ledTwo=false;
      Serial.println("Led 2 desligou.");
    }

    if (readString.indexOf("?led3on") >0){
      digitalWrite(led3, HIGH);
      ledThree=true;
      Serial.println("Led 3 ligou.");  
    }

    if (readString.indexOf("?led3off") >0){
      digitalWrite(led3, LOW); 
      ledThree=false;
      Serial.println("Led 3 desligou.");
    }

    if (readString.indexOf("?coolerOn") >0){
      digitalWrite(cooler1, HIGH);
      coolerOne=true;
      Serial.println("Cooler ligou.");  
    }

    if (readString.indexOf("?coolerOff") >0){
      digitalWrite(cooler1, LOW); 
      coolerOne=false;
      Serial.println("Cooler desligou.");
    }
    
    readString="";
}
