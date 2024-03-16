  #include <nRF24L01.h>
  #include <RF24.h>

  RF24 radio(9, 10); 
  
  const byte address[5]= "0007";  

void setup() {
  Serial.println("Setup is being Initialized");

  if(!radio.begin()){
    Serial.println("Hardware not connected");
  }
  else {
    Serial.println("Hardware connected");
  }
  radio.openWritingPipe(address);
  radio.stopListening();
  radio.setAutoAck(false);
  radio.setCRCLength(RF24_CRC_8);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);   
  radio.setChannel(108);
  Serial.begin(250000);
  delay(1000);
  const char Rtext[] = "Connected";

  if(radio.available()){
    radio.write(&Rtext,sizeof(Rtext));
    Serial.println("Transmitted");
  }
}


void loop() {
 
}
