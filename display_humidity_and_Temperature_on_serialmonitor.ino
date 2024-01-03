#include <DHT.h>

#define DHT22_PIN 7  // Replace with the actual pin you have connected the DHT sensor to
#define DHTTYPE DHT22 // Replace with the correct DHT type if you are using a different sensor

DHT dht(DHT22_PIN, DHTTYPE); // Create an instance of the DHT class

float hum;  // Stores humidity value
float temp; // Stores temperature value

void setup() {
    Serial.begin(9600);
}

void loop() {
    dht.begin(); // You may want to include this line to initialize the DHT sensor

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (!isnan(temperature) && !isnan(humidity)) {
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.print(" %, Temp: ");
        Serial.print(temperature);
        Serial.println(" Celsius");
        delay(2000);
    } else {
        Serial.println("Error reading sensor data. Please check the connection.");
    }
}
