#define BAUD 9600
#define DELAY_TIME 100

const char* helloWorld = "Hello, world!\n";

void setup() {
  Serial.begin(BAUD);
  Serial.println(helloWorld);
  delay(DELAY_TIME);
}

void loop() {

}
