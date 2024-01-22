# ESP32 WIFI

This is based on ESP32-Arduino

There are two modules: AP hotspot mode and STA client mode.

AP hotspot: computer and cellphone connected to the hotspot from ESP32. If a computer connected to AP hotspot, it is able to connect to internet. 

Therefore, when computer communicates with the module through network, it is better to use STA mode. Meaning, computer and device connected to a router that is under the same network.

## Code
Some common library functions of using Wi-Fi:
1. `WiFi.begin(ssid, password)`: use to connect to Wi-Fi network, need to provide network SSID and password as params
2. `WiFi.disconnect()`: disconnect disconnect current Wi-Fi connections
3. `WiFi.status()`: return current Wi-Fi connection status:
   - `WL_CONNECTED`: connect to Wi-Fi network
   - `WL_DISCONNECTED`: not connect to Wi-Fi network
   - `WL_IDLE_STATUS`: Wi-Fi is idle
   - `WL_NO_SSID_AVAIL`: have not found specified SSID
4. `WiFi.localIP()`: return the local ESP32 IP address that is given by the Wi-Fi network
5. `WiFi.macAddress()`: return the MAC address of ESP32
6. `WiFi.scandNetworks()`: use to scan available Wi-Fi networks. It returns an integer, representing the number of networks it scanned. We can use other functions (eg. `WiFi.SSID()` and `WiFi.RSSI()`) to retrieve specific information about each network.
7. `WiFi.SSID(networkIndex)`: return the Wi-Fi network SSID based on a specific index

```cpp
#include <WiFi.h>


#define LED   2


// specify thed wifi name and password
const char * ssid = "WiFi name";
const char * password = "WiFi password";

void setup() {
  Serial.begin(9600);

  // disconnect from previous connection
  WiFi.disconnect(true);
  // connect to wifi
  WiFi.begin(ssid, password);

  Serial.print("Connecting  Wi-Fi");

  // detect if connection is established
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
  Serial.println("Success");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // use the board LED to indicate successful connection
  pinMode(LED, OUTPUT);
  
  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  delay(100);

  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  delay(100);

  digitalWrite(LED, HIGH);
  delay(1500);
  digitalWrite(LED, LOW);
}

void loop() {
}

```