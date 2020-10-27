const long interval = 1000;
const long interval2 = 200;
unsigned long lasttime = 0;
//  14 ----- 27 ----- 26
// red     yellow    green

bool statusr = false;
bool statusy = false;
bool statusg = false;

int red = 14;
int yellow = 27;
int green = 26;

int intervalr = 3000;
int intervaly = 1750;
int intervalg = 5000;

unsigned long lasttimer = 0;
unsigned long lasttimey = 0;
unsigned long lasttimeg = 0;

int rstat = LOW;
int ystat = LOW;
int gstat = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(26, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  //pinMode(4, INPUT);
}

void redlight(){
  unsigned long currenttime = millis();
  if(currenttime - lasttimer >= intervalr && gstat==LOW && ystat==LOW){
    lasttimer = currenttime;
    if(rstat == LOW){
      rstat = HIGH;
      ystat = LOW;
      gstat = LOW;
    }
    else{
      rstat = LOW;
    }
  digitalWrite(red, rstat);
  statusr = !statusr;
  }
}


void yellowlight(){
  unsigned long currenttime = millis();
  if(currenttime - lasttimey >= intervaly && rstat==LOW && gstat==LOW){
    lasttimey = currenttime;
    if(ystat == LOW){
      rstat = LOW;
      ystat = HIGH;
      gstat = LOW;
    }
    else{
      ystat = LOW;
    }
  digitalWrite(yellow, ystat);
  statusy = !statusy;
  }
}


void greenlight(){
  unsigned long currenttime = millis();
  if(currenttime - lasttimeg >= intervalg && rstat==LOW && ystat==LOW){
    lasttimeg = currenttime;
    if(gstat == LOW){
      rstat = LOW;
      ystat = LOW;
      gstat = HIGH;
    }
    else{
      gstat = LOW;
    }
  digitalWrite(green, gstat);
  statusg = !statusg;
  }
}


void loop() {
  greenlight();
  yellowlight();
  redlight();
}
