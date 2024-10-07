const int trigPin = 2;
const int echoPin = 3;
const int ledPin = 13;  // ビルトインLEDが接続されているピン

double duration = 0;
double distance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);  // LEDピンを出力に設定
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("距離は");
  Serial.print(distance);
  Serial.println(" cmです");

  if (distance < 30) {
    tone(8, 240);
    delay(500);
    noTone(8);
    digitalWrite(ledPin, HIGH);  // 30cm未満ならLEDを点灯
    Serial.println("居眠りですか？");
  } else {
    digitalWrite(ledPin, LOW);   // 30cm以上ならLEDを消灯
  }

  delay(1000);  // 1秒待つ
}


