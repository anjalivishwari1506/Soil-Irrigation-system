const int relayPin = 7; 

const int sensorPin = A0; 

const int DRY_THRESHOLD = 600;

void setup() {
  // Initialize the relayPin as an output
  pinMode(relayPin, OUTPUT);
  
  
  digitalWrite(relayPin, HIGH); 
  
  Serial.begin(9600);
  Serial.println("Smart Irrigation System Initialized");
}

void loop() {
  int soilMoistureValue = analogRead(sensorPin); 
  
  Serial.print("Soil Moisture Value: ");
  Serial.println(soilMoistureValue);
  
  if (soilMoistureValue > DRY_THRESHOLD) {
    
    digitalWrite(relayPin, LOW); 
    Serial.println("--- Soil is DRY. Water Pump ON ---");
  } else {
    
    digitalWrite(relayPin, HIGH); 
    Serial.println("--- Soil is Moist. Water Pump OFF ---");
  }
  
  delay(2000); 
}