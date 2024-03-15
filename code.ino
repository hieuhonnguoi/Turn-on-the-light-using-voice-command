int gio = 0;
int phut = 0;
int giay = 0;
int relay1 = 8;
int relay2 = 9;
int relay3 = 10;
int lenh;
void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, HIGH);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay2, HIGH);
  pinMode(relay3, OUTPUT);
  digitalWrite(relay3, HIGH);
  //===Khoi tao hien thi thoi gian===
  (gio < 10) ? Serial.print("0") : NULL;
  Serial.print(gio);
  Serial.print(":");
  (phut < 10) ? Serial.print("0") : NULL;
  Serial.print(phut);
  Serial.print(":");
  (giay < 10) ? Serial.print("0") : NULL;
  Serial.println(giay);
}
String voice;
void loop() {
  if (Serial.available() > 0)
  {
    voice = "";
    voice = Serial.readString();
    lenh = Serial.read();
    (gio < 10) ? Serial.print("0") : NULL;
    Serial.print(gio);
    Serial.print(":");
    (phut < 10) ? Serial.print("0") : NULL;
    Serial.print(phut);
    Serial.print(":");
    (giay < 10) ? Serial.print("0") : NULL;
    Serial.println(giay);
  }
  //====Control with voice and button===
  if (voice == "mở đèn xanh")
  {
    digitalWrite(relay1, LOW);
  }
  if (voice == "tắt đèn xanh")
  {
    digitalWrite(relay1, HIGH);
  }
  if (voice == "mở đèn đỏ")
  {
    digitalWrite(relay2, LOW);
  }
  if (voice == "tắt đèn đỏ")
  {
    digitalWrite(relay2, HIGH);
  }
  if (voice == "mở đèn vàng")
  {
    digitalWrite(relay3, LOW);
  }
  if (voice == "tắt đèn vàng")
  {
    digitalWrite(relay3, HIGH);
  }
  if ((voice == "mở đèn đỏ và đèn xanh") || (voice == "mở đèn xanh và đèn đỏ"))
  {
    digitalWrite(relay2, LOW);
    digitalWrite(relay1, LOW);
  }
  if ((voice == "tắt đèn đỏ và đèn xanh") || (voice == "tắt đèn xanh và đèn đỏ"))
  {
    digitalWrite(relay2, HIGH);
    digitalWrite(relay1, HIGH);
  }
  if ((voice == "mở đèn đỏ và đèn vàng") || (voice == "mở đèn vàng và đèn đỏ"))
  {
    digitalWrite(relay3, LOW);
    digitalWrite(relay1, LOW);
  }
  if ((voice == "tắt đèn đỏ và đèn xanh") || (voice == "tắt đèn xanh và đèn đỏ"))
  {
    digitalWrite(relay3, HIGH);
    digitalWrite(relay1, HIGH);
  }
  if ((voice == "mở đèn vàng và đèn xanh") || (voice == "mở đèn xanh và đèn vàng"))
  {
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
  }
  if ((voice == "tắt đèn đỏ và đèn xanh") || (voice == "tắt đèn xanh và đèn đỏ"))
  {
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
  }
  if (voice == "mở hết đèn")
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
  }
  if (voice == "tắt hết đèn")
  {
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
  }
  //===Phim tang giam gio===
  if (lenh == '1')
  {
    gio += 1;
    delay(200);
    if (gio > 24)
    {
      gio = 0;
    }
  }
  if (lenh == '2')
  {
    gio -= 1;
    delay(200);
    if (gio < 0)
    {
      gio = 24;
    }
  }
  //===Phim tang giam phut===
  if (lenh == '3')
  {
    phut += 1;
    delay(200);
    if (phut > 59)
    {
      phut = 0;
      gio += 1;
    }
  }
  if (lenh == '4')
  {
    phut -= 1;
    delay(200);
    if (phut < 0)
    {
      phut = 59;
      gio -= 1;
    }
  }
  //===Phim tang giam giay===
  if (lenh == '5')
  {
    giay += 1;
    delay(200);
    if (giay > 59)
    {
      giay = 0;
      phut += 1;
    }
  }
  if (lenh == '6')
  {
    giay -= 1;
    delay(200);
    if (giay < 0)
    {
      giay = 59;
      phut -= 1;
    }
  }
  //===Phim hen gio relay1,relay2,relay3===
  if (lenh == '7' || lenh == '8' || lenh == '9')
  {
    (gio < 10) ? Serial.print("0") : NULL;
    Serial.print(gio);
    Serial.print(":");
    (phut < 10) ? Serial.print("0") : NULL;
    Serial.print(phut);
    Serial.print(":");
    (giay < 10) ? Serial.print("0") : NULL;
    Serial.println(giay);
    demnguoc();
    delay(1000);
  }
  //===Bat tat relay===
  if (gio == 0 && phut == 0 && giay == 0)
  {
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
  }
  if ((gio > 0 || phut > 0 || giay > 0) && lenh == '7')
  {
    digitalWrite(relay1, LOW);
  }
  if ((gio > 0 || phut > 0 || giay > 0) && lenh == '8')
  {
    digitalWrite(relay3, LOW);
  }
  if ((gio > 0 || phut > 0 || giay > 0) && lenh == '9')
  {
    digitalWrite(relay2, LOW);
  }
}
void demnguoc()
{
  if (giay > 0)
  {
    giay -= 1;
  }
  else
  {
    if (phut > 0) {
      giay = 59;
      phut -= 1;
    }
    else {
      if (gio > 0) {
        giay = 59;
        phut = 59;
        gio -= 1;
      }
    }
  }
}
