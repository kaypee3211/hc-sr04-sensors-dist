#define trgg 21
#define echo 18




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(echo, INPUT);
  pinMode(trgg, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float dist = readDistance();
  Serial.println(dist);
  delay(300);
}
float readDistance() {
  digitalWrite(trgg, LOW);
  delayMicroseconds(10);
  digitalWrite(trgg, HIGH);
  delayMicroseconds(10);
  digitalWrite(trgg, LOW);
  float distance = pulseIn(echo, HIGH) / 58.00;
  if (distance > 400  || distance <=0 ) {
    return -1;
  }
  return distance;

}
