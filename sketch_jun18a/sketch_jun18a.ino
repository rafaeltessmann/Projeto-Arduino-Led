#include <SPI.h>
#include <Ethernet.h>

const int chipSelect = 4;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,200);

String readString;
EthernetServer server(80);

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
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
           Serial.println("Conectado!");
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html><form method=post action=192.168.1.200>");
          client.println("<body>");
          client.println("<center><h1>Controlando Nossa Casinha</h1></center><br>");
          client.println("<br>");       
         client.println("<br></form><br>");     
         client.println("<p> <font size='7px'>Controles:</font> </p>");      
         client.println("<h1><a href=\"/?button1\"\">Luz A</a></h1>");
         client.println("<br><br>");
         client.println("<h1><a href=\"/?button2\"\">Luz B</a></h1>"); 
          client.println("</body>");         
          client.println("</html>");        
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
    
   
    if (readString.indexOf("?button1") >0){
      
      Serial.println("Luz A acendeu.");   
    }
    
    if (readString.indexOf("?button2") >0){
      Serial.println("Luz B acendeu.");
    
    }
   
    
    readString="";
      
  }
}


