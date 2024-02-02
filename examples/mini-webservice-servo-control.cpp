#include <WiFi.h>
#include <ESP32Servo.h>
// put function declarations here:
// #define X_IN    26
// #define Y_IN    27
// #define Z_IN    14

#define RESOLUTION  12
#define SERVO       13
#define CHANNEL     0
#define FREQ        50

// make ESP32 a mini webserver to receive command from clients
// the command is use to control servo motor

// only work in local area network

const char * ssid = "The Retreat";
const char * password = "";         // my wifi does not have password

// set service port to 80, this will enable TCP
WiFiServer server(80);     

// servo object
Servo my_servo;

// use to store HTTP request 
String header;

// get current time
unsigned long currentTime = millis();
// previous time
unsigned long previousTime = 0;
// setting timeout interval (2000ms for now)
const long timeoutInterval = 2000;
int value = 0;

void setup() {
  Serial.begin(9600); // baud rate
  
  ESP32PWM::allocateTimer(0);         // setup timer 0, we will use the fast channel
  my_servo.setPeriodHertz(FREQ);      // set up PWM frequency
  my_servo.attach(SERVO, 500, 2500);  // set up duty cycle time, min = 500us, max = 2500us
  my_servo.write(0);
  delay(200);

  Serial.print("Connecting...");
  Serial.println(ssid);
  WiFi.begin(ssid);   // we do not need to provide password, cuz we do not have one
  
  while(WiFi.status() != WL_CONNECTED){ // keep checking if the conenction can be established
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");     
  Serial.println(WiFi.localIP());     // print out the IP, so that user can connect to it
  server.begin();                     // activate the server
}

void loop() {
  
  // check for incoming data
  WiFiClient client = server.available();
  
  if(client){
    currentTime = millis();   // get current time
    previousTime = currentTime;
    Serial.println("a client connected.");
    String currentLine = "";  // used to save data from client
    while(client.connected() && currentTime - previousTime <= timeoutInterval){ // check client connection and request
      currentTime = millis(); // get current time
      if (client.available()){
        char a_byte = client.read();
        Serial.write(a_byte);     // print to serial monitor
        header += a_byte;
        if(a_byte == '\n'){
          if(currentLine.length() == 0){
            // setup HTTP response
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:application/json"); // change this to text/html, for webpage
            client.println("Content-Length: 0");  // this field is optional if we want to transmit a webpage...
            client.println("Connection: close");  
            client.println();

            if(header.indexOf("GET /inc") >= 0 ){
              Serial.println("servo inc degree");
              value = min(180, value + 20); // limit the degree to 180
              my_servo.write(value);
              // delay(100);
            }
            else if(header.indexOf("GET /dec") >= 0){
              Serial.println("servo dec degree");
              value = max(0, value - 20); // limit the degree to 0
              my_servo.write(value);
              // delay(100);
            }
            else if(header.indexOf("GET /180") >= 0){
              Serial.println("servo 180 degree");
              value = 180;
              my_servo.write(180);
            }
            else if(header.indexOf("GET /0") >= 0){
              Serial.println("servo 0 degree");
              value = 0;
              my_servo.write(0);
            }

            client.println(""); // HTTP ending, another newline
            break;
          }  
          else{
            currentLine = ""; // if there is a new line, then clear currentline
          }
        }
        else if(a_byte != '\r'){
          currentLine += a_byte; // keep constructing the line that we read
        }
      }


    }

    // clear header
    header = "";

    // close connection, doing this can help us save some resources
    client.stop();
    Serial.println("client disconnected");
    Serial.println("");

  }
}

// put function definitions here:


