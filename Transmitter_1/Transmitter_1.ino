//Header Section
  #include <nRF24L01.h>
  #include <RF24.h>

  #include <Adafruit_SSD1306.h>

// Define Section
  #define OLED_RESET 4  


Adafruit_SSD1306 display(OLED_RESET);

  RF24 radio(9, 10); 
  
  const byte address[6]= "0007";  

  bool status=true;


//Fuction section

void Setup_display() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void display_items(int x,int y,char string[]){
  display.setCursor(x,y);
  display.println(string);
  display.display();
  display.clearDisplay();
  delay(1000);
  display.display();
}


void setup() {
  Setup_display();
  display_items(0,0,"Setup is being       Initialized");

  if(!radio.begin()){
    display_items(0,0,"Hardware not connected");
  }
  else {
    display_items(0,0,"Hardware connected");
  }
  radio.openReadingPipe(1, address);
  radio.startListening();
  radio.setAutoAck(false);
  radio.setCRCLength(RF24_CRC_8);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);   
  radio.setChannel(108);

  display_items(0,0,"Setup Done");

while(status) {
if (radio.available()) {
    byte check=100;;
  radio.read(&check,sizeof(check));
  if(check==007){
   display_items(0,0,"Paired successfully");
  status = false;
  delay(1000);
  } 
  
} else {
  display_items(0,0,"Pairing");
}
}

}
void loop() {
 
}
