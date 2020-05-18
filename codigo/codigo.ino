#include <WiFi.h>
#include "FirebaseESP32.h"
#include "FirebaseJson.h"
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

FirebaseData firebaseData;
String ruta = "/sensor1";


void setup() 
{


pinMode(35,INPUT);

 
  Serial.begin(115200);
  Serial.println();
  Serial.println();

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

  
  //----------------------------------------------
  //---------------Eliminar datos-----------------
  //----------------------------------------------
 
  //Firebase.deleteNode(firebaseData, "/sensor_temperatura");
  
  
  //----------------------------------------------
  //-------------Escritura de datos---------------
  //----------------------------------------------
  
  // Escribe un entero
  // Firebase.setInt(firebaseData, ruta + "/numerico", 123);
  
  
  // Escribe un decimal;
  //Firebase.setFloat(firebaseData, ruta + "/numerico", 123.45);
  
  // Escribe un binario
  //Firebase.setBool(firebaseData, ruta + "/logico", false);

  // Escribe un texto
  //Firebase.setString(firebaseData, ruta + "/texto", "Hola choco");

  // Escribe un JSON
  /*String cadena="Hola choco con JSON";
  float numerico=876.45;
  bool logico=true;
  String JSONdata = "{\"numerico\":" + String(numerico) +", \"logico\":"+ String (logico) +", \"texto\":\""+ cadena + "\"}";
  Firebase.setJSON(firebaseData, ruta + "/hijo", JSONdata);
  Serial.println(JSONdata);*/

  //----------------------------------------------
  //---------------Lectura de datos---------------
  //----------------------------------------------
  
  //leer Entero
  //Firebase.getInt(firebaseData, ruta + "/hijo/logico");
  //Serial.println(firebaseData.intData());

  //leer Decimal
  //Firebase.getFloat(firebaseData, ruta + "/hijo/numerico");
  //Serial.println(firebaseData.floatData());
  
  //leer Texto
  //Firebase.getString(firebaseData, ruta + "/hijo/texto");
  //Serial.println(firebaseData.stringData());

  //leer JSON
  //Firebase.getJSON(firebaseData, ruta + "/hijo");
  //Serial.println(firebaseData.jsonData());

  //----------------------------------------------
  //----------------Push de datos-----------------
  //----------------------------------------------
    
  //push Entero
  //Firebase.pushInt(firebaseData, ruta + "/Push/numerico", 123);

  //push Decimal
 // Firebase.pushFloat(firebaseData, ruta + "/Push/entero", 123);

  //push String
  //Firebase.pushString(firebaseData, ruta + "/Push/texto", "asdsd");

  //push Binario
  //Firebase.pushBool(firebaseData, ruta + "/Push/funcionando", false);


  while(true){
    double adc = analogRead(35); 
    double adc2 = adc/12;
    Serial.println(String(adc));
  //  push JSON
  String JSONdata = "{\"sensora\":" + String(adc) +", \"sensorb\":"+ String(adc2) +", \"Texto\":\""+ "Valor variables" + "\"}";
  Firebase.pushJSON(firebaseData, ruta + "/", JSONdata);
  

  delay(5000);
  }
  //----------------------------------------------
  //------------------Streaming-------------------
  //----------------------------------------------

  //streaming
  //Serial.println("Inicio de streaming");
  //Serial.println("RUTA: "+ruta + "/hijo/entero");
  //Firebase.beginStream(firebaseData, ruta + "/hijo/texto");

  //----------------------------------------------
  //-------------Finaliza la conexion-------------
  //----------------------------------------------

  //Firebase.end(firebaseData);



}

void loop() 
{
  //----------------------------------------------
  //--------------Streaming de datos--------------
  //----------------------------------------------

Firebase.readStream(firebaseData);    
if (firebaseData.streamAvailable()) 
  {  
      Serial.println(firebaseData.stringData()); // El tipo de dato debe coincidir con el dato cargado en la nube
      delay(50);                                 // El delay es para que solo se haga una lectura, caso contrario repetira la lectura varias veces,
  }                                              // Si el loop es mas largo, no se requiere este delay.
}
