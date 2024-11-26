
void setup() {
  // put your setup code here, to run once:
pinMode(13,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int light_value = analogRead(13);
Serial.println(light_value);
delay(100);
}
