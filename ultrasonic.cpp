//จากอุกรณ์อัลตราโซนิก กำหนดขาที่ใช้
int pingPinEcho = 13 ;//  รับคลื่นเสียงสะท้อนกลับ ขาส่ง
int inPinTring = 12; // ส่งสัญญาคลื่นเสียง ขารับ//
void setup() {
  Serial.begin(9600); // ส่งและรับค่าข้อมูล ความเร็ว 9600 ที่จะส่งสัญญาณ
  pinMode(pingPinEcho ,OUTPUT); // ขา 13 ส่งออก
  pinMode( inPinTring,INPUT); // ตั้งขา 12 รอขาส่ง รับเข้ามา
}
void loop() 
{
  long duration, cm;//ระยะเวลา และ ระยะมิลลิ

  digitalWrite(pingPinEcho,HIGH); //  คบคุมขา13ที่สั่งเปิดสั่งปิด ให้มีแสงออกมา ส่งคลื่นออกมา
  delayMicroseconds(2); // ความหน่วงเวลา
  digitalWrite(pingPinEcho, LOW); // ควบคุมขาให้แสงตํ่าลง 
  delayMicroseconds(5); // หน่วงเวลา 5 วินาที

  duration = pulseIn( inPinTring,HIGH); // เวลารอการไปกลับ รอhigh pulseIn วัดความกว้าง

  cm = MicrosecondsToCentimeters(duration); //  แปลงเวลาเป้นมิลลิ

  Serial.print(cm); 
  Serial.print("cm"); 
  Serial.println(); 
  delay(100); // รอถึง100 ก่อนทำต่อ
}
long MicrosecondsToCentimeters(long microseconds){ 

  return microseconds /29/2;
}









    
