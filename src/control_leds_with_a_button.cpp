bool puls  = false;
bool previousPuls = true;
bool running = false;
unsigned long previousMillis = 0;
int currentLed = 0;

const int buttonPin=7;
const int pinYellow=11;
const int pinRed=12;
const int pinGreen=13;

const unsigned long interval = 500;

void setup()
{
    Serial.begin(9600);
  
	pinMode(buttonPin, INPUT_PULLUP);
	pinMode(pinRed, OUTPUT);
	pinMode(pinGreen, OUTPUT);
	pinMode(pinYellow, OUTPUT);
}

void loop()
{
	puls=digitalRead(buttonPin);
  
 	if (previousPuls==HIGH && puls==LOW)
	{
		running = !running;
        Serial.println(running ? "Started" : "Stopped");
        if(!running)
    	{
        	digitalWrite(pinRed, LOW);
        	digitalWrite(pinYellow, LOW);
        	digitalWrite(pinGreen, LOW);
      		currentLed = 0;
    	}
	}
    
    previousPuls=puls;
    puls=digitalRead(buttonPin);
  
    if (running && (millis() - previousMillis >= interval))
    {
        previousMillis = millis();

        digitalWrite(pinRed, LOW);
        digitalWrite(pinYellow, LOW);
        digitalWrite(pinGreen, LOW);

        if (currentLed == 0)
        {
            digitalWrite(pinRed, HIGH);
        	currentLed++;
        }
        else if (currentLed == 1)
        {
            digitalWrite(pinYellow, HIGH);
        	currentLed++;
        }
        else
        {
            digitalWrite(pinGreen, HIGH);
        	currentLed++;
        }
      
		if (currentLed > 2)
		{
    		currentLed = 0;
		}
    }
}