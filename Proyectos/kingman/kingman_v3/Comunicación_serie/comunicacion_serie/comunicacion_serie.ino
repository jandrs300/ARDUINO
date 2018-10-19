
#define GPIO_32 32
#define GPIO_33 33
#define GPIO_34 25
#define GPIO_35 26

void setup() {
 
  Serial.begin(9600);
  Serial.print("Hola");
}

void loop() {
  int val = analogRead(GPIO_32);
  int val1 = analogRead(GPIO_33);
  int val2 = analogRead(GPIO_34);
  int val3 = analogRead(GPIO_35);

  val = map(val, 0, 4095, 0, 250);
  val1 = map(val1, 0, 4095, 0, 250);
  val2 = map(val2, 0, 4095, 0, 250);
  val3 = map(val3, 0, 4095, 0, 250);
  
  Serial.print(val);
  Serial.print(", ");
  Serial.print(val1);
  Serial.print(", ");
  Serial.print(val2);
  Serial.print(", ");
  Serial.println(val3);
  delay(500);
}
