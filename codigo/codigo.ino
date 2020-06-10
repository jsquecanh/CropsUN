#include <WiFi.h>
#include "FirebaseESP32.h"
#include "FirebaseJson.h"
#include "DHT.h"
#include <Adafruit_Sensor.h>

// Datos de conexion  a base de datos y a internet. 
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

// Pin sensor DHT11 
#define DHTPIN 4
#define DHTTYPE DHT11


// Inicializa la base de datos 
FirebaseData firebaseData;
String ruta = "/sensor1";


DHT dht(DHTPIN, DHTTYPE);
void setup() 
{
 //  Salidas y entradas por sensor y actuador. 
 pinMode(2,OUTPUT); 
pinMode(35,INPUT);
 
 // Inicializar .
   Serial.begin(115200);
  Serial.println();
  Serial.println();
 dht.begin();

 

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectado al Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Conectado con IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  while(true){
    // Lectura se sensor FC-28
    float humedadsuelo = analogRead(35); 
   // si la tierra es seca se enciende el actuador dado por el pin . Espera dos segundos y vuelve a realizar el monitoreo . 
if(humedadsuelo<50){
  digitalWrite(2,HIGH); 
  delay(1000); 
  digitalWrite(2,LOW); 
  delay(1000); 
  
  }
   // Se hacen las respectivas medidas  de humedad y temperatura.  
   
    float humedad = dht.readHumidity(); 
    float temperatura = dht.readTemperature();

   // Se comprueba si  funciona el sensor DHT 11 
   
   if (isnan(humedad) || isnan(temperatura)) {                                                
  
    humedad = 0 ;
    temperatura = 0 ; 
  }
  // Imprime  el valor de los sensores , antes del envio . 
    Serial.println(humedad);
    Serial.println(temperatura);
    Serial.println(humedadsuelo);
   
  //  push JSON para poner los datos en la  ESP32
   
  String JSONdata = "{\"sensora\":" + String(humedad) +", \"sensorb\":"+ String(temperatura) +", \"sensorc\":\""+ String(humedadsuelo) + "\"}";
  Firebase.pushJSON(firebaseData, ruta + "/", JSONdata);
   


  delay(5000);
  }
}

void loop() 
{
  //----------------------------------------------
  //--------------Medida de datos-------------
  //----------------------------------------------
float humedad = dht.readHumidity(); 
float temperatura = dht.readTemperature();
 // Stream de datos. 
Firebase.readStream(firebaseData);    
if (firebaseData.streamAvailable()) 
  {  
      Serial.println(firebaseData.stringData()); // El tipo de dato debe coincidir con el dato cargado en la nube
      delay(50);                                 // El delay es para que solo se haga una lectura, caso contrario repetira la lectura varias veces,
  }                                              // Si el loop es mas largo, no se requiere este delay.
}
