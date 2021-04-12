void setup() {
  pinMode(3, OUTPUT);//กำหนดขา 13 เป็นโหมด Output
  pinMode(4, OUTPUT);//กำหนดขา 13 เป็นโหมด Output
}

void loop() {
  digitalWrite(3, HIGH);// สั่งให้เปิดไฟที่ขา 13
  // digitalWrite(13, 1);// สั่งให้เปิดไฟที่ขา 13 เขียนอีกแบบได้เหมือนกัน

}
