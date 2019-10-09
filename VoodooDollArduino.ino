/*
 * Henry Amador
 * Voodoo Doll
 */
 #include <Adafruit_CircuitPlayground.h>
 #include <Adafruit_NeoPixel.h>
 #include <Wire.h>
 #include <SPI.h>
const uint8_t spHELLO[]             PROGMEM ={0x00,0xC0,0x80,0x60,0x59,0x08,0x10,0x3D,0xB7,0x00,0x62,0x64,0x3D,0x55,0x4A,0x9E,0x66,0xDA,0xF6,0x56,0xB7,0x3A,0x55,0x76,0xDA,0xED,0x92,0x75,0x57,0xA3,0x88,0xA8,0xAB,0x02,0xB2,0xF4,0xAC,0x67,0x23,0x73,0xC6,0x2F,0x0C,0xF3,0xED,0x62,0xD7,0xAD,0x13,0xA5,0x46,0x8C,0x57,0xD7,0x21,0x0C,0x22,0x4F,0x93,0x4B,0x27,0x37,0xF0,0x51,0x69,0x98,0x9D,0xD4,0xC8,0xFB,0xB8,0x98,0xB9,0x56,0x23,0x2F,0x93,0xAA,0xE2,0x46,0x8C,0x52,0x57,0x66,0x2B,0x8C,0x07};
const uint8_t spOH[]                PROGMEM = {0xC6,0xC9,0x71,0x5A,0xA2,0x92,0x14,0x2F,0x6E,0x97,0x9C,0x46,0x9D,0xDC,0xB0,0x4D,0x62,0x1B,0x55,0x70,0xDD,0x55,0xBE,0x0E,0x36,0xC1,0x33,0x37,0xA9,0xA7,0x51,0x1B,0xCF,0x3C,0xA5,0x9E,0x44,0xAC,0x3C,0x7D,0x98,0x7B,0x52,0x96,0x72,0x65,0x4B,0xF6,0x1A,0xD9,0xCA,0xF5,0x91,0x2D,0xA2,0x2A,0x4B,0xF7,0xFF,0x01};
const uint8_t spUH[]                PROGMEM = {0x2B,0x68,0x6E,0xD4,0xD4,0x56,0x9D,0xA0,0xB9,0x75,0x13,0x69,0x75,0x82,0xEA,0x2B,0x5C,0x6D,0xD5,0x89,0x5B,0xC8,0x72,0x95,0x45,0x2B,0xAF,0x3E,0x53,0xDD,0x6E,0x8F,0xBA,0xF8,0x4C,0x75,0xBB,0x5D,0xDA,0x5C,0xC3,0xD5,0x2B,0xD6,0xFF,0x05,0x55};
const uint8_t spA1[]                PROGMEM ={ 0xAD,0x36,0x25,0x46,0x7C,0x2C,0xCD,0x66,0x36,0xB3,0xED,0x6D,0xEF,0x72,0xE7,0xBB,0xD8,0x3F,0x00,0x00};
const uint8_t spUHOH[]              PROGMEM ={0x2B,0xB5,0x31,0x46,0x3C,0x6D,0x9D,0x38,0xB8,0x6A,0xE7,0x5C,0x7C,0x7C,0x53,0xCA,0xCD,0xD7,0xEA,0x76,0xBA,0x45,0x00,0xAD,0xAB,0x00,0x10,0x20,0x6A,0x46,0x08,0xBC,0xCB,0x31,0xB5,0x3A,0x2B,0xF7,0x3A,0x37,0x9C,0xBA,0xDD,0xE2,0x56,0xB7,0xBA,0xD5,0xAA,0x8C,0xAA,0x0B,0xC7,0xB4,0xB3,0x1A,0x95,0x56,0xFD,0x62,0x92,0xB6,0x55,0x8E,0xF5,0x9B,0x29,0xFB,0x52,0xC9,0x38,0x1E,0x46,0x4E,0x44,0xC5,0x9B,0xB7,0xB1,0xC9,0x79};
const uint8_t spNO[]                PROGMEM ={0xA1,0xF2,0x0E,0x3E,0xD3,0xA9,0x94,0x3A,0x78,0xB8,0xA8,0xA0,0x93,0x6A,0xEF,0xE0,0xA3,0x9C,0xF1,0xAA,0xA2,0xE7,0x32,0xF3,0x24,0xA7,0xB0,0xDE,0xDB,0xDC,0xDB,0xDC,0xFC,0xE6,0x37,0x5F,0x95,0xF2,0xB9,0x61,0xD4,0x65,0x57,0xBB,0x6E,0x2D,0x8F,0xB3,0x6A,0xD4,0xA5,0x76,0xB5,0x0F,0x3D,0xDD,0x1B,0xAA,0x92,0xC8,0xF7,0x0F,0x00,0x00};
const uint8_t spBYE[]               PROGMEM ={0xAE,0xC2,0xA6,0xCC,0x2D,0xD2,0x9E,0xC2,0xA7,0x78,0x91,0xC8,0x74,0xAB,0x53,0xB9,0x34,0xA3,0x30,0x8E,0x6F,0x75,0xAB,0x5B,0x9D,0xDA,0x95,0x6E,0x93,0xB1,0x7F,0xEB,0xDB,0xAC,0x2E,0x4C,0x4B,0xC9,0x96,0xDC,0xBB,0xD6,0x85,0xE2,0x61,0x19,0xA5,0x5B,0x1F,0x8A,0xA9,0x77,0x44,0xEE,0x7D,0xEE,0x62,0x2F,0xFB,0x07,0x00,0x00};

//setup arduino variables
 int PIN = 9;
 Adafruit_NeoPixel strip = Adafruit_NeoPixel(15, PIN, NEO_GRB + NEO_KHZ800);
 int heartPin = 12; // pin designated for heart kill switch
 int heart;
 int bottomPin = 4; //built in buttons
 int bottom;
 int topPin = 19; //built in buttons
 int top;
 int suffering;
 int vib1 = 10;  //unused vibrating motor pin
 int vib2 = 6;  //unused vibrating motor pin
 int vib3 = 3;  //unused vibrating motor pin
 float wake = 0;
 
 //setup arduino pins
void setup() 
 {
 pinMode(heartPin,INPUT_PULLUP);
 pinMode(vib1,OUTPUT);
 pinMode(vib2,OUTPUT);
 pinMode(vib3,OUTPUT);
 pinMode(top,INPUT);
 pinMode(bottom,INPUT);
 //set up serial for trouble shooting
 Serial.begin(9600);
 CircuitPlayground.begin();
 CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);
 strip.begin();
 strip.setBrightness(30);
 strip.show();}

void loop() {
  suffer();
//************************************************************
  switch(suffering){
    case 1:
    {   //pain
      Pain();
      delay(5);
      CircuitPlayground.speaker.say(spA1);
      Serial.println("pain");
        break;
    }
    case 2:
    {   //agony
      Agony();
      CircuitPlayground.speaker.say(spOH);
      delay(20);
      Blank();
      Serial.print("agony  ");
      break;
    }
    case 3:
    {
      //die
      wake = CircuitPlayground.motionZ();
      Death();
      Serial.print("die   ");
      CircuitPlayground.speaker.say(spUHOH);
      Blank();
      delay(700);
      Death();
      CircuitPlayground.speaker.say(spBYE);
      
      while(wake < 70)
      {
        Blank();
        wake = CircuitPlayground.motionZ();
        Serial.println(wake);
      }
      break;
    }
    default:
    {
      Norm(); //expresion
    }
  }
}
//**********************************************************
//NeoPixel expressions page of code
/*Faces
 *           4
 *       (3)   (5)
 *     2           6
 *    1     13     7
 *    0 12      14 8
 *       11     9
 *          10
 * 
 */
void Blank()
  {
    Serial.println("Blank");
    uint32_t blank = strip.Color(0, 0, 0);
    strip.setPixelColor(3, blank);//EYES
    strip.setPixelColor(5, blank);//EYES
  
    strip.setPixelColor(7, blank);//BLANK GAPS
    strip.setPixelColor(6, blank);
    strip.setPixelColor(4, blank);
    strip.setPixelColor(2, blank);
    strip.setPixelColor(1, blank);//BLANK GAPS
  
    strip.setPixelColor(14, blank);//TOP LIP
    strip.setPixelColor(13, blank);
    strip.setPixelColor(12, blank);//TOP LIP

    strip.setPixelColor(8, blank);//CORNER OF MOUTH
    strip.setPixelColor(0, blank);//CORNER OF MOUTH
  
    strip.setPixelColor(11, blank);//BOTTOM LIP
    strip.setPixelColor(10, blank);
    strip.setPixelColor(9, blank);//BOTTOM LIP

    strip.show();
  }

void Norm()
  {
    Serial.println("Normal");
    uint32_t green = strip.Color(0, 255, 0);
    uint32_t blank = strip.Color(0, 0, 0);
    strip.setPixelColor(3, green);//EYES
    strip.setPixelColor(5, green);//EYES
  
    strip.setPixelColor(7, blank);//BLANK GAPS
    strip.setPixelColor(6, blank);
    strip.setPixelColor(4, blank);
    strip.setPixelColor(2, blank);
    strip.setPixelColor(1, blank);//BLANK GAPS
  
    strip.setPixelColor(14, blank);//TOP LIP
    strip.setPixelColor(13, blank);
    strip.setPixelColor(12, blank);//TOP LIP

    strip.setPixelColor(8, green);//CORNER OF MOUTH
    strip.setPixelColor(0, green);//CORNER OF MOUTH
  
    strip.setPixelColor(11, green);//BOTTOM LIP
    strip.setPixelColor(10, green);
    strip.setPixelColor(9, green);//BOTTOM LIP

    strip.show();
  }

void Pain()
  {
    Serial.println("Pain");
    uint32_t redish = strip.Color(255, 12, 12);
    uint32_t blank = strip.Color(0, 0, 0);
  
    strip.setPixelColor(3, redish);//EYES
    strip.setPixelColor(5, redish);

    strip.setPixelColor(7, blank);//GAPS
    strip.setPixelColor(6, blank);
    strip.setPixelColor(4, blank);
    strip.setPixelColor(2, blank);
    strip.setPixelColor(1, blank);
  
    strip.setPixelColor(14, redish);//TOP LIP
    strip.setPixelColor(13, redish);
    strip.setPixelColor(12, redish);
  
    strip.setPixelColor(8, redish);//CORNERS
    strip.setPixelColor(0, redish);
  
    strip.setPixelColor(11, blank);//BOTTOM
    strip.setPixelColor(10, blank);
    strip.setPixelColor(9, blank);
  
    strip.show();
  }

void Agony()
  {
    digitalWrite(vib1, HIGH);
    uint32_t red = strip.Color(255, 0, 0);
    uint32_t blank = strip.Color(0, 0, 0);
  
    strip.setPixelColor(3, red);//EYES
    strip.setPixelColor(5, red);

    strip.setPixelColor(7, blank);//GAPS
    strip.setPixelColor(6, blank);
    strip.setPixelColor(4, blank);
    strip.setPixelColor(2, blank);
    strip.setPixelColor(1, blank);
  
    strip.setPixelColor(14, red);//TOP LIP
    strip.setPixelColor(13, red);
    strip.setPixelColor(12, red);
  
    strip.setPixelColor(8, blank);//CORNERS
    strip.setPixelColor(0, blank);
  
    strip.setPixelColor(11, red);//BOTTOM
    strip.setPixelColor(10, red);
    strip.setPixelColor(9, red);
  
    strip.show();
  }
  
void Death()
  {
    uint32_t red = strip.Color(255, 0, 0);
    uint32_t blank = strip.Color(0, 0, 0);
  
    strip.setPixelColor(3, red);//EYES
    strip.setPixelColor(5, red);

    strip.setPixelColor(7, blank);//GAPS
    strip.setPixelColor(6, blank);
    strip.setPixelColor(4, blank);
    strip.setPixelColor(2, blank);
    strip.setPixelColor(1, blank);
  
    strip.setPixelColor(14, red);//TOP LIP
    strip.setPixelColor(13, red);
    strip.setPixelColor(12, red);
  
    strip.setPixelColor(8, blank);//CORNERS
    strip.setPixelColor(0, blank);
  
    strip.setPixelColor(11, red);//BOTTOM
    strip.setPixelColor(10, red);
    strip.setPixelColor(9, red);
  
    strip.show();
  }
  //*********************************************************************************
  //Suffering code function
  void suffer()
{
  bottom = digitalRead(bottomPin);
  top = digitalRead(topPin);
  heart = digitalRead(heartPin);


  if (heart == 1)
  {
    suffering = 3;
  }
  
  if (top == 1 && bottom == 0 && heart == 0)
  {
    suffering = 1;
  }
  
  if (bottom == 1 && top == 0 && heart == 0)
  {
    suffering = 1;
  }
  
  if (top == 1 && bottom == 1 && heart == 0)
  {
    suffering = 2;
  }
  
  if (top == 0 && bottom == 0 && heart == 0)
  {
    suffering = 0;
  }
}
