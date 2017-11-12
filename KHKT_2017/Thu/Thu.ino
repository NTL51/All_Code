#include <SPI.h>
#include "RF24.h"
 
const uint64_t pipe = 0xE9EC08DF41LL; // địa chỉ phát
RF24 radio(9,10);//thay 10 thành 53 với mega

int len=0;  
 
void setup(){
  Serial.begin(9600);
  radio.begin();                     
  radio.setAutoAck(1);              
  radio.setDataRate(RF24_1MBPS);    // Tốc độ dữ liệu
  radio.setChannel(8);               // Đặt kênh
  radio.openReadingPipe(1,pipe);     
  radio.startListening();  
}
 
void loop(){
  if (radio.available()){
    while (radio.available()){
      len = radio.getDynamicPayloadSize();
      char msg[len]="";
      radio.read(&msg, len);
      Serial.println(msg);
    }
  }
}
