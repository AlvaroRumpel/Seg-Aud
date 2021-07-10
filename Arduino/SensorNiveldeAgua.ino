#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:


int verde = 3; //Define o nome azul para a porta digital 7
int amarelo = 4; //Define o nome amarelo para a porta digital 6
int vermelho = 6; //Define o nome vermelho para a porta digital 5
int buzzer = 9;
int boia = 8;
int boia2 = 7;

int contBeep = 0;
int diaSem = 1;
long hora;
long minuto;

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

void setup() {
  pinMode(boia,INPUT);
  pinMode(boia2,INPUT);
  pinMode(verde, OUTPUT); //Define o led azul como saída de dados
  pinMode(amarelo, OUTPUT); //Define o led amarelo como saída de dados
  pinMode(vermelho, OUTPUT); //Define o led vermelho como saída de dados
  pinMode(buzzer, OUTPUT);
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Ethernet WebServer Example");

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // start the server
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {

  digitalWrite(verde, LOW); //Garante que o led azul está apagado
  digitalWrite(amarelo, LOW); //Garante que o led amarelo está apagado
  digitalWrite(vermelho, LOW); //Garante que o led vermelho está apagado

  int estado = digitalRead(boia);
  int estado2 = digitalRead(boia2);
  Serial.print("Leitura do Sensor: ");
  Serial.println(estado, estado2);

  if(contBeep>300){
    contBeep=0;
  }

  if(diaSem>=30){
    diaSem=1;
  }
  
  hora = random(00,23);
  minuto = random(00,60);
  
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // output the value of each analog input pin
          
          if(estado==1 && estado2==1){
            client.print(diaSem+10);
            client.print(",");
            client.print(hora+10);
            client.print(",");
            client.print(minuto+10);
            client.print(",");
            client.print("0");
            client.print(",");
            client.println("N");
            digitalWrite(vermelho, 0);
            digitalWrite(amarelo, 0);
            digitalWrite(verde, 1);
            delay(3000);
          }else if(estado==0 && estado2==1){
            client.print(diaSem+10);
            client.print(",");
            client.print(hora+10);
            client.print(",");
            client.print(minuto+10);
            client.print(",");
            client.print("1");
            client.print(",");
            client.println("N");
            digitalWrite(vermelho, 0);
            digitalWrite(amarelo, 1);
            digitalWrite(verde, 0);
            delay(3000);
          }else{
            client.print(diaSem+10);
            client.print(",");
            client.print(hora+10);
            client.print(",");
            client.print(minuto+10);
            client.print(",");
            client.print("2"); //nivel
            client.print(",");
            client.println("S"); //emitir alerta
            digitalWrite(vermelho, 1);
            digitalWrite(amarelo, 0);
            tone(buzzer, 261+contBeep);
            contBeep+=20;
            delay(3000); //Aguarda 2 segundos para mostrar a temperatura novamente  
            noTone(buzzer);
            digitalWrite(verde, 0);
          }
          client.println("</html>");
          diaSem = diaSem+1;
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}
