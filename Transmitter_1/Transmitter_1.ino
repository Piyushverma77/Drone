  #include <nRF24L01.h>
  #include <RF24.h>

  RF24 radio(9, 10); 
  
  const byte address[6]= "0007";  

  bool status=true;



void setup() {
  Serial.begin(250000);
  Serial.println("Setup is being Initialized");

  if(!radio.begin()){
    Serial.println("Hardware not connected");
  }
  else {
    Serial.println("Hardware connected");
  }

  delay(3000);
 
  radio.openReadingPipe(1, address);
  radio.startListening();
  radio.setAutoAck(false);
  radio.setCRCLength(RF24_CRC_8);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);   
  radio.setChannel(108);



while(status) {
if (radio.available()) {
    byte check=100;;
  radio.read(&check,sizeof(check));
  if(check==007){
     Serial.println("Paired Successful");
  status = false;
  } 
  delay(5000);
} else {
  Serial.println("Pairing");
}
}

}
void loop() {
 
}
