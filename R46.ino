//ada// include the library code:
#include <LiquidCrystal.h>
#include <Wire.h>
#include <avr/pgmspace.h> //save to flash.

#define REDLITE 4
#define GREENLITE 5
#define BLUELITE 6
#define LEFTBTN 2
#define RIGHTBTN 3

//R46 LCD Codemap (saved on Flash)
const char sign0[] PROGMEM = "!,WELCOME TO THE , R46 SIGN SIM! ";
const char sign1[] PROGMEM = "A,  8 AV EXPRESS , FULTON ST EXP , ROCKAWAY PARK ,via JFK AIRPORT";
const char sign2[] PROGMEM = "A,  8 AV EXPRESS , FULTON ST EXP ,  OZONE PARK   , LEFFERTS BLVD ";
const char sign3[] PROGMEM = "A,  8 AV EXPRESS , FULTON ST EXP ,  FAR ROCKAWAY ,via JFK AIRPORT";
const char sign4[] PROGMEM = "A, FULTON ST EXP ,  8 AV EXPRESS ,to207 ST/MANHTN";
const char sign5[] PROGMEM = "B,   6 AV EXP    ,CENT PK W LOCAL,     145 ST    ";
const char sign6[] PROGMEM = "B,   6 AV EXP    , BRIGHTON EXP  ,BRIGHTON BEACH ";
const char sign7[] PROGMEM = "B,   6 AV EXP    ,CENT PK W LOCAL, CONCOURSE LCL ,BEDFORD PK BLVD";
const char sign8[] PROGMEM = "C,  OZONE PARK   , LEFFERTS BLVD ,   8 AV LCL     , FULTON ST LCL ";
const char sign9[] PROGMEM = "C,  8 AV LOCAL   , to EUCLID AV  ";
const char sign10[] PROGMEM = "C,   8 AV LINE   ,to168 ST/MANHTN";
const char sign11[] PROGMEM = "D,   6 AV EXP    ,CENT PK W EXP  ,CONCOURSE EXP  ,NORWOOD-205 ST ";
const char sign12[] PROGMEM = "D,   6 AV EXP    ,   WEST END    , CONEY ISLAND  ";
const char sign13[] PROGMEM = " ,LETS DO THE FORK,IN THE GARBAGE,DISPOSAL,DING DING DING";
const char sign14[] PROGMEM = "E,  8 AV LOCAL   ,WORLD TRADE CTR";
const char sign15[] PROGMEM = "E,  KEW GARDENS  ,   UNION TPK   ";
const char sign16[] PROGMEM = "E, QUEENS BL EXP ,  JAMAICA CTR  , PARSONS-ARCHER,   via 53 ST   ";
const char sign17[] PROGMEM = "E,to FAR ROCKAWAY,8 AV/FULTON EXP";
const char sign18[] PROGMEM = "E, JAMAICA-179 ST,    8 AV LCL   ,  QUEENS BL EXP";
const char sign19[] PROGMEM = "F,   6 AV LOCAL  ,   KINGS HWY   ,   via 63 ST   ";
const char sign20[] PROGMEM = "F, QUEENS BL EXP , JAMAICA-179 ST,   via 63 ST   ,   6 AV LOCAL  ";
const char sign21[] PROGMEM = "F,   6 AV LOCAL  ,EUCLID AV/BKLYN, via FULTON ST ,   via 63 ST   ";
const char sign22[] PROGMEM = "F,   6 AV LOCAL  ,  CULVER LOCAL ,  CONEY ISLAND ,   via 63 ST   ";
const char sign23[] PROGMEM = "G,CROSSTOWN LOCAL,  SMITH-9 STS  ";
const char sign24[] PROGMEM = "G,CROSSTOWN LOCAL, LONG IS. CITY ,    COURT SQ   ";
const char sign25[] PROGMEM = "G,CROSSTOWN LOCAL, CULVER LOCAL  ,KENSNGTON-BKLYN,   CHURCH AV   ";
const char sign26[] PROGMEM = "G,  18 AV/BKLYN  ,CROSSTOWN LOCAL";
const char sign27[] PROGMEM = "H,    SHUTTLE    , BROAD CHANNEL ";
const char sign28[] PROGMEM = "H,    SHUTTLE    , ROCKAWAY PARK ";
const char sign29[] PROGMEM = "H,    SHUTTLE    ,  to EUCLID AV ";
const char sign30[] PROGMEM = "J,NASSAU ST LINE ,  JAMAICA CTR  ,PARSONS-ARCHER";
const char sign31[] PROGMEM = "J,NASSAU ST LINE ,to CHAMBERS ST ";
const char sign32[] PROGMEM = "J,NASSAU ST LINE ,  to BROAD ST  ";
const char sign33[] PROGMEM = "K,   8 AV LCL    ,WORLD TRADE CTR";
const char sign34[] PROGMEM = "K,   8 AV LCL    ,WASHINGTON HTS ,    168 ST    ";
const char sign35[] PROGMEM = "L,  14 ST LINE   ,toROCKAWAY PKWY";
const char sign36[] PROGMEM = "L,  14 ST LINE   , to 8 AV/14 ST ";
const char sign37[] PROGMEM = "M,NASSAU ST LINE ,METROPOLITAN AV";
const char sign38[] PROGMEM = " ,  FUNG WAH RR  ,    15 DOLLA   ,  AT FUNG WAH  ,   WE CRASH    ";
const char sign39[] PROGMEM = "M,NASSAU ST LINE ,to CHAMBERS ST ";
const char sign40[] PROGMEM = "M, NASSAU ST LCL , WEST END LCL  ,to BAY PARKWAY";
const char sign41[] PROGMEM = "N, BROADWAY EXP  ,    ASTORIA    , DITMARS BLVD ";
const char sign42[] PROGMEM = "N, BROADWAY LCL  ,    ASTORIA    , DITMARS BLVD ";
const char sign43[] PROGMEM = "N, BROADWAY LCL  ,SEA BEACH LOCAL, CONEY ISLAND ";
const char sign44[] PROGMEM = "N, BROADWAY LCL  , SEA BEACH EXP , CONEY ISLAND ";
const char sign45[] PROGMEM = "N, BROADWAY EXP  ,SEA BEACH LOCAL, CONEY ISLAND ";
const char sign46[] PROGMEM = "N, BROADWAY EXP  , SEA BEACH EXP , CONEY ISLAND ";
const char sign47[] PROGMEM = "Q,to 21 ST/QUEENS,  6 AV EXPRESS ";
const char sign48[] PROGMEM = "Q, BROADWAY EXP  ,ASTORIA-DITMARS";
const char sign49[] PROGMEM = "Q, BROADWAY EXP  , BRIGHTON LCL  , CONEY ISLAND ";
const char sign50[] PROGMEM = "R,    SHUTTLE    ,  36 ST-BKLYN  ";
const char sign51[] PROGMEM = "R,BROADWAY LOCAL ,BAY RIDGE-95 ST,   via 60 ST  ";
const char sign52[] PROGMEM = "R,JAMAICA CENTER ,PARSONS-ARCHER , BROADWAY LCL ";
const char sign53[] PROGMEM = "R, BROADWAY LCL  ,QUEENS BL LOCAL,FOREST HILLS-71,   via 60 ST   ";
const char sign54[] PROGMEM = "R,    SHUTTLE    ,BAY RIDGE-95 ST";
const char sign55[] PROGMEM = "S,    SHUTTLE    ,  FRANKLIN AV  ";
const char sign56[] PROGMEM = "S,    SHUTTLE    , BROAD CHANNEL ";
const char sign57[] PROGMEM = "S,    SHUTTLE    ,  ROCKAWAY PK  ";
const char sign58[] PROGMEM = "S,    SHUTTLE    ,  PROSPECT PK  ";
const char sign59[] PROGMEM = "V,  6 AV LOCAL   ,   via 53 ST   ,QUEENS BL LOCAL,FOREST HILLS-71";
const char sign60[] PROGMEM = "V, CONEY ISLAND  ,   6 AV LCL    ,CULVER EXPRESS ";
const char sign61[] PROGMEM = "V,   6 AV LCL    , LOWER E. SIDE ,     2 AV      ,   via 53 ST   ";
const char sign62[] PROGMEM = "W, BROADWAY LCL  ,ASTORIA-DITMARS";
const char sign63[] PROGMEM = "W, CONEY ISLAND  , via BROADWAY  , via WEST END  ";
const char sign64[] PROGMEM = "W,BROADWAY LOCAL , WHITEHALL ST  ";
const char sign65[] PROGMEM = "Z,NASSAU ST LINE ,  JAMAICA CTR  ,PARSONS-ARCHER ";
const char sign66[] PROGMEM = "Z,NASSAU ST LINE ,to CHAMBERS ST ";
const char sign67[] PROGMEM = "Z,NASSAU ST LINE ,  to BROAD ST  ";
const char sign68[] PROGMEM = " ,   LAST STOP   ";
const char sign69[] PROGMEM = " ,NOT IN SERVICE ";
const char sign70[] PROGMEM = " ,    SPECIAL    ";
const char sign71[] PROGMEM = " ,    SHUTTLE    ";
const char sign72[] PROGMEM = " ,WALK THRU TRAIN";

//Set up referencing table.
const char* const sign_table[] PROGMEM = {sign0,sign1, sign2, sign3, sign4, sign5, sign6, sign7, sign8, sign9, sign10, sign11, sign12, sign13, sign14, sign15, sign16, sign17, sign18, sign19, sign20, sign21, sign22, sign23, sign24, sign25, sign26, sign27, sign28, sign29, sign30, sign31, sign32, sign33, sign34, sign35, sign36, sign37, sign38, sign39, sign40, sign41, sign42, sign43, sign44, sign45, sign46, sign47, sign48, sign49, sign50, sign51, sign52, sign53, sign54, sign55, sign56, sign57, sign58, sign59, sign60, sign61, sign62, sign63, sign64, sign65, sign66, sign67, sign68, sign69, sign70, sign71, sign72};
char buffer[81]; //Makes enough for 5 16-char displays + 1 route number (not including commas)

// initialize the library with the numbers of the byteerface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// you can change the overall brightness by range 0 -> 255
byte brightness = 255;

//R46 via, to special lettering
byte v[7] = {B0,B0,B10001,B10001,B10001,B1010,B100,};
byte i[7] = {B0,B0,B1110,B100,B100,B100,B1110,};
byte a[7] = {B0,B0,B110,B1001,B1111,B1001,B1001,};
byte t[7] = {B0,B0,B11111,B100,B100,B100,B100,};
byte o[7] = {B0,B0,B110,B1001,B1001,B1001,B110,};
//byte plane[7] = {B100,B100,B1110,B11111,B10101,B100,B1010};

//global variables
  byte btnL = 0;
  byte btnR = 0;
  volatile float sign_index = 0.5; //Sign index in table.
  volatile byte sign_changed = 0;
  
//*********************************
//
//SETUP FUNCTION.

void setup() {
  lcd.clear();
  // set up the LCD's number of rows and columns:
  lcd.begin(16, 2);
  //Define custom chars above.
  lcd.createChar(1, v);
  lcd.createChar(2, i);
  lcd.createChar(3, a);
  lcd.createChar(4, t);
  lcd.createChar(5, o);
  
  Serial.begin(9600); //Start up serial comm
  while(!Serial);
  Serial.println("OK"); //OK.

  pinMode(REDLITE, OUTPUT);
  pinMode(GREENLITE, OUTPUT);
  pinMode(BLUELITE, OUTPUT);
  pinMode(LEFTBTN, INPUT_PULLUP);
  pinMode(RIGHTBTN, INPUT_PULLUP);
  pinMode(13,OUTPUT);

  
  brightness = 50;
  setBacklight(255, 255, 0);
  btnL = digitalRead(LEFTBTN);
  btnR = digitalRead(RIGHTBTN);

  attachInterrupt(digitalPinToInterrupt(2), buttonpress_Lon, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), buttonpress_Ron, CHANGE);
}

//scanning & replacing lowercases with the special "via" and "to" characters.
void scan_replace(String sign) {
  byte pos = 0;

  lcd.setCursor(0, 1);
  while (pos < 17) {
    if (String(sign.charAt(pos)) == "v")
    {
      lcd.setCursor(pos + 1, 1);
      lcd.write(1);
    }
    else if (String(sign.charAt(pos)) == "i")
    {
      lcd.setCursor(pos + 1, 1);
      lcd.write(2);
    }
    else if (String(sign.charAt(pos)) == "a")
    {
      lcd.setCursor(pos + 1, 1);
      lcd.write(3);
    }
    else if (String(sign.charAt(pos)) == "t")
    {
      lcd.setCursor(pos + 1, 1);
      lcd.write(4);
    }
    else if (String(sign.charAt(pos)) == "o")
    {
      lcd.setCursor(pos + 1, 1);
      lcd.write(5);
    }
    pos = pos + 1;
  }
}

void loop()
{
//Display sign goes here.

 beginning:
  strcpy_P(buffer, (char*)pgm_read_word(&(sign_table[round(abs((int)(sign_index)))])));
  Serial.println(buffer);
 //bullet is first column of data, so we separate that first.
  String displays = strtok(buffer, ",");
  char bullet = displays.charAt(0);
  displays = strtok(NULL, ",");
    
    sign_continue:
    lcd.clear(); //Refresh screen.
    lcd.setCursor(0,0);
    lcd.write(bullet);
    lcd.setCursor(1, 1);
    lcd.print(displays);
    byte sign_length = displays.length();
    String debug_info = ':' + displays + ".," + sign_length;
    Serial.println(debug_info);
    scan_replace(displays);
    
    //Foreshadowing here.
    displays = strtok(NULL, ",");
    sign_length = displays.length();
    for (int wait=0; wait < 3001; wait++){
      if(sign_changed == 1){
        break;
      }
    delay(1);
    }
      if(sign_changed == 1){
        goto button_request_change;
      }
    Serial.println(sign_length); //Print next line's length and "foreshadow" to loop?
    
    if (sign_length != 0){
      goto sign_continue;
    }

    goto beginning;

    button_request_change:
    lcd.clear();
    while(sign_changed == 1){}

}


void buttonpress_Lon(){
  Serial.println("Left Interrupt!");
  sign_index = sign_index - 0.5; //Two button presses. 0.5 * 2 = 1
  sign_changed = !sign_changed;
  Serial.println(sign_index);
    }


void buttonpress_Ron(){
  Serial.println("Right Interrupt!");
  sign_index = sign_index + 0.5;
  sign_changed = !sign_changed;
  Serial.println(sign_index);
  }


  
void setBacklight(uint8_t r, uint8_t g, uint8_t b) {
  // normalize the red LED - its brighter than the rest!
  r = map(r, 0, 255, 0, 100);
  g = map(g, 0, 255, 0, 150);

  r = map(r, 0, 255, 0, brightness);
  g = map(g, 0, 255, 0, brightness);
  b = map(b, 0, 255, 0, brightness);

  // common anode so invert!
  r = map(r, 0, 255, 255, 0);
  g = map(g, 0, 255, 255, 0);
  b = map(b, 0, 255, 255, 0);
  Serial.print(" R = "); Serial.print(r, DEC);
  Serial.print(" G = "); Serial.print(g, DEC);
  Serial.print(" B = "); Serial.println(b, DEC);
  analogWrite(REDLITE, r);
  analogWrite(GREENLITE, g);
  analogWrite(BLUELITE, b);
}
