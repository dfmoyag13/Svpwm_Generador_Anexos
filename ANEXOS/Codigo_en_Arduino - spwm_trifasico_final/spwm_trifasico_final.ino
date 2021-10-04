
int banco1 = 11;//3;
int banco2 = 12;//6;
int banco3 = 13;//10;

int sw0 = 9;
int sw1 = 8;
int sw2 = 4;
int sw3 = 5;
int sw4 = 6;
int sw5 = 7;

int reg = 20;

double frecuencia = 50; //hz
float periodo = (1 / frecuencia);
double ancho = (periodo / 2) * 1000000;

int pwmv = 10;
int pulsador = A2;

double tikporcentaje[13] = {5, 5, 7.5, 5, 12.5, 5, 20, 5, 12.5, 5, 7.5, 5, 5};
int tikval[13] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
void setup() {
  // put your setup code here, to run once:
  pinMode(pulsador, 0);
  pinMode(banco1, OUTPUT);
  pinMode(banco2, OUTPUT);
  pinMode(banco3, OUTPUT);

  digitalWrite(banco1, LOW);
  digitalWrite(banco2, LOW);
  digitalWrite(banco3, LOW);

  pinMode(sw0, OUTPUT);
  pinMode(sw1, OUTPUT);
  pinMode(sw2, OUTPUT);
  pinMode(sw3, OUTPUT);
  pinMode(sw4, OUTPUT);
  pinMode(sw5, OUTPUT);

  pinMode(pwmv, OUTPUT);

  digitalWrite(banco1, LOW);
  digitalWrite(banco2, LOW);

  digitalWrite(sw0, LOW);
  digitalWrite(sw1, LOW);
  digitalWrite(sw2, LOW);
  digitalWrite(sw3, LOW);
  digitalWrite(sw4, LOW);
  digitalWrite(sw5, LOW);
  Serial.begin(9600);
  Serial.println("oki doki :3");
  //Serial.println(periodo);
  //Serial.println(ancho);
  analogWrite(pwmv, 255);
}
int tik = 0;
int volt = 255;
int regv = 0;

long int tb = 0;
int ct = 0;

int t0 = 33 + ct;
int t1 = 36 + ct;
int t2 = 98 + ct;
int t7 = t0;

void loop() {

  if (digitalRead(pulsador) == 0) {
    ct = map(analogRead(A0), 0, 1023, 10, 100);
    regv = map(analogRead(A1), 0, 1023, 0, 90);//hasta 70> 19 v, hasta 46> 15v
    t0 = 33 + ct;
    t1 = 36 + ct;
    t2 = 98 + ct;
    t7 = t0;
    //Serial.print(t0);
    //Serial.print(" ");
    //Serial.print(t1);
    //Serial.print(" ");
    //Serial.print(t2);
    //Serial.print(" ");
    //Serial.println(t7);
    reg = ct;
    analogWrite(pwmv, regv);
    Serial.print("ancho: ");
    Serial.print(reg);
    Serial.print(" voltaje: ");
    Serial.println(regv);
    delay(400);
  }
  digitalWrite(sw0, 0);
  digitalWrite(sw1, 1);
  delay(reg / 3);
  digitalWrite(sw2, 0);
  digitalWrite(sw3, 1);
  delay(reg / 3);
  digitalWrite(sw4, 0);
  digitalWrite(sw5, 1);
  delay(reg / 3);

  digitalWrite(sw0, 1);
  digitalWrite(sw1, 0);
  delay(reg / 3);
  digitalWrite(sw2, 1);
  digitalWrite(sw3, 0);
  delay(reg / 3);
  digitalWrite(sw4, 1);
  digitalWrite(sw5, 0);
  delay(reg / 3);

}
void aux() {
  digitalWrite(banco1, HIGH);
  delay(reg / 3);
  digitalWrite(banco2, HIGH);
  delay(reg / 3);
  digitalWrite(banco3, HIGH);
  delay(reg / 3);
  digitalWrite(banco1, LOW);
  delay(reg / 3);
  digitalWrite(banco2, LOW);
  delay(reg / 3);
  digitalWrite(banco3, LOW);
  delay(reg / 3);
}
void aux1() {
  //sector 0
  digitalWrite(sw0, 0);
  digitalWrite(sw1, 1);
  digitalWrite(sw2, 0);
  digitalWrite(sw3, 1);
  digitalWrite(sw4, 0);
  digitalWrite(sw5, 1);
  delayMicroseconds(t0);
  //sector 1
  digitalWrite(sw0, 1);
  digitalWrite(sw1, 0);
  digitalWrite(sw2, 0);
  digitalWrite(sw3, 1);
  digitalWrite(sw4, 0);
  digitalWrite(sw5, 1);
  delayMicroseconds(t1);
  //sector 2
  digitalWrite(sw0, 1);
  digitalWrite(sw1, 0);
  digitalWrite(sw2, 1);
  digitalWrite(sw3, 0);
  digitalWrite(sw4, 0);
  digitalWrite(sw5, 1);
  delayMicroseconds(t2);
  //sector 3
  digitalWrite(sw0, 0);
  digitalWrite(sw1, 1);
  digitalWrite(sw2, 1);
  digitalWrite(sw3, 0);
  digitalWrite(sw4, 0);
  digitalWrite(sw5, 1);
  delayMicroseconds(t7);
  //sector 4
  digitalWrite(sw0, 0);
  digitalWrite(sw1, 1);
  digitalWrite(sw2, 1);
  digitalWrite(sw3, 0);
  digitalWrite(sw4, 1);
  digitalWrite(sw5, 0);
  delayMicroseconds(t0);
  //sector 5
  digitalWrite(sw0, 0);
  digitalWrite(sw1, 1);
  digitalWrite(sw2, 0);
  digitalWrite(sw3, 1);
  digitalWrite(sw4, 1);
  digitalWrite(sw5, 0);
  delayMicroseconds(t2);
  //sector 6
  digitalWrite(sw0, 1);
  digitalWrite(sw1, 0);
  digitalWrite(sw2, 1);
  digitalWrite(sw3, 0);
  digitalWrite(sw4, 1);
  digitalWrite(sw5, 0);
  delayMicroseconds(t1);
  //sector 7
  digitalWrite(sw0, 1);
  digitalWrite(sw1, 0);
  digitalWrite(sw2, 1);
  digitalWrite(sw3, 0);
  digitalWrite(sw4, 1);
  digitalWrite(sw5, 0);
  delayMicroseconds(t7);
}
