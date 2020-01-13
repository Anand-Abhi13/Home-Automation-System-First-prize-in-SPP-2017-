String voice;

int led1 = 8;
int led2 = 9;
int led3 = 10;
int lcd = 12;
int motor = 11;
void allon() {
  digitalWrite (led1, HIGH);
  digitalWrite (led2, HIGH);
  digitalWrite (led3, HIGH);
  digitalWrite (lcd, HIGH);
  analogWrite (motor, 255);
}

void alloff() {
  digitalWrite (led1, LOW);
  digitalWrite (led2, LOW);
  digitalWrite (led3, LOW);
  digitalWrite (lcd, LOW);
  analogWrite (motor, 0);
}
void led1on() {
  digitalWrite (led1, HIGH);
}
void led1off() {
  digitalWrite (led1, LOW);
}
void led2on() {
  digitalWrite (led2, HIGH);
}
void led2off() {
  digitalWrite (led2, LOW);
}
void led3on() {
  digitalWrite (led3, HIGH);
}
void led3off() {
  digitalWrite (led3, LOW);
}
void lcdon() {
  digitalWrite (lcd, HIGH);
}
void lcdoff() {
  digitalWrite (lcd, LOW);
}
void motorlow()
{
  analogWrite(motor, 60);
}
void motormid()
{
  analogWrite(motor, 140);
}
void motorhigh()
{
  analogWrite(motor, 255);
}
void motoroff()
{
  analogWrite(motor, 0);
}


void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(lcd, OUTPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  while(Serial.available()) {
    delay(10);
    char c=Serial.read();
    if(c=='#')
    {break; }
    voice += c;
}

if (voice.length() > 0) {
  Serial.println(voice);
  if (voice == "*all on")
  {allon() ; }
  if (voice == "*light one on")
  {led1on() ; }
  if (voice == "*light to on")
  {led2on() ; }
  if (voice == "*light 3 on")
  {led3on() ; }
  if (voice == "*light one of")
  {led1off() ; }
  if (voice == "*light to off")
  {led2off() ; }
  if (voice == "*light number 3 of")
  {led3off() ; }
  if (voice == "*LCD on")
  {lcdon() ; }
  if (voice == "*LCD of")
  {lcdoff() ; }
  if (voice == "*fan speed minimum")
  {motorlow() ; }
  if (voice == "*fan speed medium")
  {motormid() ; }
  if (voice == "*fan speed maximum")
  {motorhigh() ; }
   if (voice == "*fan on")
  {motorhigh() ; }
   if (voice == "*fan of")
  {motoroff() ; }
  else if (voice == "*all of")
  {alloff() ; }
  
  
voice="";
}}

