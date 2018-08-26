#include <SPI.h>
#include <Ethernet.h>

const int chipSelect = 4;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,200);

String readString;
EthernetServer server(80);

// LED conectado ao pino digital 9
int led1 = 9;
int led2 = 8;
int led3 = 7;

void setup() {
  
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
  
  // configura pino digital como saída
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT);
  
  Serial.println("iniciou...");
}

void loop() {
  EthernetClient client = server.available();                   
 
  if (client) {
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        //Serial.write(c);
        
        if (readString.length() < 100){
          readString += c;
        
        }
        
        if (c == '\n' && currentLineIsBlank) {

          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close"); // the connection will be closed after completion of the response
          //client.println("Refresh: 2");  refresh the page automatically every 5 sec
          client.println();
          client.println("");
          client.println("");
          
               
        break;     
        if (c == '\n') {
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }  
      }
  }
    delay(1);
    client.stop();
    
   //LED 1
    if (readString.indexOf("?led1on") >0){
      // liga o LED
      digitalWrite(led1, HIGH);
      Serial.println("Led 1 ligou.");  
    }

    if (readString.indexOf("?led1off") >0){
      // desliga o LED
      digitalWrite(led1, LOW); 
      Serial.println("Led 1 desligou.");
    }

    //LED 2
     if (readString.indexOf("?led2on") >0){
      // liga o LED
      digitalWrite(led2, HIGH);
      Serial.println("Led 2 ligou.");  
    }
    
    if (readString.indexOf("?led2off") >0){
      // desliga o LED
      digitalWrite(led2, LOW); 
      Serial.println("Led 2 desligou.");
    }

    //LED 3
     if (readString.indexOf("?led3on") >0){
      // liga o LED
      digitalWrite(led3, HIGH);
      Serial.println("Led 3 ligou.");  
    }
    
    if (readString.indexOf("?led3off") >0){
      // desliga o LED
      digitalWrite(led3, LOW); 
      Serial.println("Led 3 desligou.");
    }
   
    
    readString="";
      
  } 
}

