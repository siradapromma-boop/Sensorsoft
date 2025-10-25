char lebarray[9]={2,3,4,5,6,7,8,9,10};
int pingPinEcho = 13 ;//กำหนดขา จากอัลตราโซนิก รับคลื่นเสียงสะท้อนกลับ ขาส่ง
int inPinTring = 12; 
int maxleng = 400 ;//cm 


void setup() { 
  Serial.begin(9600); // ส่งและรับค่าข้อมูล ความเร็ว 9600 ที่จะส่งสัญญาณ
  pinMode(pingPinEcho ,OUTPUT); // ขา 13 
  pinMode( inPinTring,INPUT); // ตั้งขา 12 รอขาส่ง
  for(int i=0;i<=9;i++){
    pinMode(lebarray[i], OUTPUT); // 
  }


}

void loop() {
  long duration, cm;//ระยะเวลา ระยะมิลลิ

  digitalWrite(pingPinEcho,HIGH); //  คบคุมขาที่สั่งเปิดสั่งปิด ให้มีแสงออกมา ส่งคลื่นออกมา
  delayMicroseconds(2); // ความหน่วงเวลา
  digitalWrite(pingPinEcho, LOW); // ควบคุมขาให้แสงตํ่าลง 
  delayMicroseconds(5); //

  duration = pulseIn( inPinTring,HIGH); // เวลารอการไปกลับ รอhigh

  cm = MicrosecondsToCentimeters(duration); //  แปลงเวลาเป้นมิลลิ 
  float leng_rate = maxleng / 9 ;
  int led_leng = cm /leng_rate ;
  Serial.println(led_leng);
  show_led(led_leng);




  Serial.print(cm); 
  Serial.print("cm"); 
  Serial.println(); 
  delay(100); // รอถึง100 ก่อนทำต่อ
    
  // for(int i=0;i<=9;i++){
  //   forLoopLED(lebarray[i],200);
  // }
  // for(int i=9;i>=0;i--){
  //   digitalWrite(lebarray[i], HIGH);
  //   delay(200);
  //   digitalWrite((lebarray[i]), LOW);
  //   delay(200);
  // }
 
}

void forLoopLED(int pin, int duration){
  digitalWrite(pin,HIGH);
  delay(duration);
  digitalWrite(pin,LOW);
  delay(duration);
}
long MicrosecondsToCentimeters(long microseconds){ 

  return microseconds /29/2;

}
void show_led(int led){
  for(int i=9;i<=0;i--){
    if(i>led){
       digitalWrite(lebarray[i], HIGH);

    }
    else{
      digitalWrite(lebarray[i], LOW);
    }
   


  }
  
}

