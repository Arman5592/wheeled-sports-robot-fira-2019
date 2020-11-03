
int silverline;

int RgreenR,RgreenG,RgreenB = 888;

int RblueR,RblueG,RblueB = 888;

int RredR,RredG,RredB = 888;

int RyellowR,RyellowG,RyellowB = 888;

int RsilverR,RsilverG,RsilverB = 888;

//int RwhiteR,RwhiteG,RwhiteB = 888;

//int RblackR,RblackG,RblackB = 888;

int LgreenR,LgreenG,LgreenB = 888;

int LblueR,LblueG,LblueB = 888;

int LredR,LredG,LredB = 888;

int LyellowR,LyellowG,LyellowB = 888;

int LsilverR,LsilverG,LsilverB = 888;

//int LwhiteR,LwhiteG,LwhiteB = 888;

//int LblackR,LblackG,LblackB = 888;

int rightR,rightG,rightB = 0;
int leftR,leftG,leftB = 0;

int chapool=0;
int colorflagsum =0;
int x=0;
int rightcolor=0;
int leftcolor=0;
//sedifi va siahie zamin baraye sensor rang ke dar tabe e calibre taiin mishavand

const int dirPin = 9;
const int stepPin = 8;
const int stepsPerRevolution = 200;

int greenflag = 0;
int blueflag = 0;
int redflag = 0;
int yellowflag = 0;
int silverflag = 0;
//flag ha

int sensor[13];
int SenCal[13];

int linedetect = 0;
//chandta az sensor hayi ke dar yek khate rast hastand be onvane marja entekhab mishavand , harkodam ke
//siah did , linedetect ra +1 mikonad va be in shekl khate amood bar khate masir tashkhis dade mishavad



int rightiswhite = 0;
int rightisblack = 0;

int rightisgreen = 0;
int rightisblue = 0;
int rightisred = 0;
int rightisyellow = 0;
int rightissilver = 0;
int leftiswhite,leftisblack,leftisgreen,leftisblue,leftisred,leftisyellow,leftissilver = 0;
//flag baraye rahatie tashkhise range zamin , maghadir tavasote tabe e rang taiin mishavand
//================================================================
void whitebalance();
void rightcolordetect() ;
void leftcolordetect() ;
//==============================================



    #define S0 22
    #define S1 23
    #define S2 24
    #define S3 25
    #define sensorOut 26
    int frequency = 0;
    #define S0L 28
    #define S1L 29
    #define S2L 30
    #define S3L 31
    #define sensorOutL 32
    int frequencyL = 0;



#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
Servo rast;
Servo chap;
Servo zard;

LiquidCrystal_I2C lcd(0x27,16,2);

    
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
      pinMode(S0, OUTPUT);
      pinMode(S1, OUTPUT);
      pinMode(S2, OUTPUT);
      pinMode(S3, OUTPUT);
      pinMode(sensorOut, INPUT);
      
      // Setting frequency-scaling to 20%
      digitalWrite(S0,HIGH);
      digitalWrite(S1,LOW);
      pinMode(S0L, OUTPUT);
      pinMode(S1L, OUTPUT);
      pinMode(S2L, OUTPUT);
      pinMode(S3L, OUTPUT);
      pinMode(sensorOutL, INPUT);
      
      // Setting frequency-scaling to 20%
      digitalWrite(S0L,HIGH);
      digitalWrite(S1L,LOW);
      pinMode(2, OUTPUT);
      pinMode(3, OUTPUT);
      pinMode(4, OUTPUT);
      pinMode(5, OUTPUT);
      pinMode(6, OUTPUT);
      pinMode(7, OUTPUT);

     pinMode(stepPin, OUTPUT);
     pinMode(dirPin, OUTPUT);

     rast.attach(10);
  chap.attach(11);
  zard.attach(12);


  lcd.init();
  lcd.backlight();
  rast.write(90);
  chap.write(0);
  zard.write(90);
  whitebalance();
  //silverbalance();
  colorcalibrate();
 
  

}
//=====================================================================================================================================================================

void loop() {
  
 
  
  start:
 rangerast();
 rangechap();
 rightcolordetect();
 leftcolordetect();
 
 
  value();
  linePlus();
  //lcd.setCursor(8,1);
  //lcd.print(leftcolor);
  //lcd.setCursor(10,1);
  //lcd.print(rightcolor);
  //lcd.setCursor(0,0);
  //lcd.print(analogRead(5));
  lcd.setCursor(13,0);
  lcd.print("goo");
  /*lcd.setCursor(0,0);
  lcd.print(sensor[12]);
  for (int h=0; h<12 ; h++) {
    lcd.setCursor(h+1,0);
    lcd.print(sensor[h]);
  }
  lcd.setCursor(0,1);
  lcd.print(analogRead(12));*/
 
 if(rightcolor==1){
  
  if(greenflag==0) {
    lcd.setCursor(13,0);
    lcd.print("gre");
    int ru=0;
    int shoot=0; //agar 1 bod rast mizane agar 2 bod chap mizane agar 0 mond mizane jolo
    //digitalWrite(2,HIGH);
    //digitalWrite(3,LOW);
    //digitalWrite(5,LOW);
    //digitalWrite(6,HIGH);
    //analogWrite(4,150);
    //analogWrite(13,150);
    //delay(250);
    /*digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,95);
    analogWrite(13,95);
    delay(120);*/
    for (int c2=0;c2<800;c2++){
      value();
      lineRight();
    }
    while(ru==0){
      value();
      lineMinus();
      
      if(shoot==0){
      if(sensor[11]==1 || sensor[10] ==1){
        shoot=1;
      }
      else if(sensor[12]==1 || sensor[0] ==1){
        shoot=2;
      }
      }
      if(sensor[9]==1 || sensor[10]==1 || sensor[11]==1){
        //vaysa,shoot kon
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(13,LOW);
        delay(2000);
        if (shoot==1){
          rast.write(0);
          delay(1000);
          rast.write(90);
        }
        else if(shoot==2){
          chap.write(90);
          delay(1000);
          chap.write(0);
        }
        else {
          //shoot jolo :(
          rast.write(0);
          chap.write(90);
          delay(1000);
          rast.write(90);
          chap.write(0);
          
        }
        ru=1;
      }
      /*d=0;
      for(int q=0;q<13;q++){
        d+=sensor[q];
      }*/
    }
        
        //dore kamel
          digitalWrite(2,LOW);
          digitalWrite(3,HIGH);
          digitalWrite(6,LOW);
          digitalWrite(5,HIGH);
          analogWrite(4,240);
          analogWrite(13,240);
          delay(370);
        //tabee line bere vali ba 7 sensore vasat , vaghti resid be barcode rangi begire samte rast va mamoli bere
         while(ru==1){
          value();
          lineMinus();
          rangechap();
          leftcolordetect();
          if(sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
            greenflag=1;
            //begir samte rast
            //====================baraye chap avaz shavadd!!===============
           for(int t=0;t<800;t++){
          value();
          lineRight();
        }
            goto start;
          }
        
    }
      
      










  
  }
  
 }
 else if(leftcolor==1){
  if(greenflag==0) {
    
  lcd.setCursor(13,0);
    lcd.print("gre");
    int ru=0;
    int shoot=0; //agar 1 bod rast mizane agar 2 bod chap mizane agar 0 mond mizane jolo
    //digitalWrite(2,HIGH);
    //digitalWrite(3,LOW);
    //digitalWrite(5,LOW);
    //digitalWrite(6,HIGH);
    //analogWrite(4,150);
    //analogWrite(13,150);
    //delay(250);
    /*digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,95);
    analogWrite(13,95);
    delay(120);*/
    for (int c2=0;c2<800;c2++){
      value();
      lineLeft();
    }
    while(ru==0){
      value();
      lineMinus();
      
      if(shoot==0){
      if(sensor[11]==1 || sensor[10] ==1){
        shoot=1;
      }
      else if(sensor[12]==1 || sensor[0] ==1){
        shoot=2;
      }
      }
      if(sensor[12]==1 || sensor[0]==1 || sensor[1]==1){
        //vaysa,shoot kon
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(13,LOW);
        delay(2000);
        if (shoot==1){
          rast.write(0);
          delay(1000);
          rast.write(90);
        }
        else if(shoot==2){
          chap.write(90);
          delay(1000);
          chap.write(0);
        }
        else {
          rast.write(0);
          chap.write(90);
          delay(1000);
          rast.write(90);
          chap.write(0);
        }
        ru=1;
      }
      /*d=0;
      for(int q=0;q<13;q++){
        d+=sensor[q];
      }*/
    }
        
        //dore kamel
          digitalWrite(2,LOW);
          digitalWrite(3,HIGH);
          digitalWrite(6,LOW);
          digitalWrite(5,HIGH);
          analogWrite(4,240);
          analogWrite(13,240);
          delay(370);
        //tabee line bere vali ba 7 sensore vasat , vaghti resid be barcode rangi begire samte rast va mamoli bere
         while(ru==1){
          value();
          lineMinus();
          rangerast();
          rightcolordetect();
          if(sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
            greenflag=1;
            //begir samte chap
            
            for(int t=0;t<800;t++){
          value();
          lineLeft();
        }
            goto start;
          }
         }
  }
  //==========================================================================================
 }
 else if(rightcolor==2){
 
  if(blueflag==0) {
   lcd.setCursor(13,0);
  lcd.print("blu");
  int go=1;
  int lap=0;
  int counter=0;
  while(go==1){
    value();
    lineRight();
    rangerast();
    rightcolordetect();
    counter++;
    if(rightcolor==2){
      if(counter>150){
      lap++;
      counter=0;
      }
    }
    lcd.setCursor(6,1);
    lcd.print(lap);
    
    if(lap==3){
      blueflag=1;
      goto start;
    }
  }
  }
 }
 //============================================
 else if(leftcolor==2){
  if(blueflag==0) {
   lcd.setCursor(13,0);
  lcd.print("blu");
  int go=1;
  int lap=0;
  int counter=0;
  while(go==1){
    value();
    lineLeft();
    rangechap();
    leftcolordetect();
    counter++;
    if(leftcolor==2){
      if(counter>150){
      lap++;
      counter=0;
      }
    }
    lcd.setCursor(6,1);
    lcd.print(lap);
    
    if(lap==3){
      blueflag=1;
      goto start;
    }
  }
  }
  
 }
 //========================================================================================
 else if(rightcolor==3){
  if(redflag==0) {
    int go=0;
    int s=0;
    lcd.setCursor(13,0);
    lcd.print("red");
    while (go==0) {
    value();
    lineRight();
    lcd.setCursor(13,0);
    lcd.print("mh2");
    //s=0;
    //for(int o=0;o<13;o++){
    //  s+=sensor[o];
    //}
    
    if (sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
      go=2;
      redflag=1;
      digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(13,LOW);
      //boland kardane vazne ; stepper biad bala!
      //========
      digitalWrite(dirPin, HIGH);

  // Spin motor slowly
 
  delay(1000); // Wait a second
  //==============
      
      delay(2000);
    }
    }
      while(go==2){
        digitalWrite(3,LOW);
        digitalWrite(6,LOW);
        digitalWrite(2,HIGH);
        digitalWrite(5,HIGH);
        analogWrite(4,100);
        analogWrite(13,100);
        if (redflag==1){
          delay(500);
        }
        redflag=2;
        //s=0;
        //for(int g=0;g<13;g++){
        // s+=sensor[g]; 
        //}
        value();
        if(sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
          digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(13,LOW);
          //stepper biad paiin
          //====================
          digitalWrite(dirPin, LOW);

  // Spin motor quickly
  
  delay(1000); // Wait a second
  //======================
          
          delay(2000);
          //dore baraks bezane,yekam bargarde aghab
          digitalWrite(3,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(5,LOW);
    analogWrite(4,100);
    analogWrite(13,100);
    delay(500);
          digitalWrite(2,LOW);
          digitalWrite(3,HIGH);
          digitalWrite(6,LOW);
          digitalWrite(5,HIGH);
          analogWrite(4,240);
          analogWrite(13,240);
          delay(370);
         
          go=3;
          redflag=1;
        }
      }
          while(go==3){
            value();
            lineRight();
            rangechap();
            leftcolordetect();
            if(sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
              for(int t=0;t<800;t++){
          value();
          lineRight();
        }
              goto start;
            }
          }
        
      
    
  
  }
 }
 else if(leftcolor==3){
   if(redflag==0) {
    lcd.setCursor(13,0);
    lcd.print("red");
    int go=0;
    int s=0;
    while (go==0) {
    value();
    lineLeft();
    lcd.setCursor(13,0);
    lcd.print("mh2");
    //s=0;
    //for(int o=0;o<13;o++){
    //  s+=sensor[o];
    //}
    
    
    if (sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
      go=2;
      redflag=1;
      //boland kardane vazne ; stepper biad bala!
      digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(13,LOW);
        digitalWrite(dirPin, HIGH);

  // Spin motor slowly
  
  delay(1000); // Wait a second
      delay(2000);
    }
    }
      while(go==2){
        digitalWrite(3,LOW);
        digitalWrite(6,LOW);
        digitalWrite(2,HIGH);
        digitalWrite(5,HIGH);
        analogWrite(4,100);
        analogWrite(13,100);
        if (redflag==1){
          delay(400);
        }
        redflag=2;
        //s=0;
        //for(int g=0;g<13;g++){
        // s+=sensor[g]; 
        //}
        value();
        if(sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
          //stepper biad paiin
          digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(13,LOW);
        digitalWrite(dirPin, LOW);

  // Spin motor quickly
 
  delay(1000); // Wait a second
          delay(2000);
          //dore baraks bezane,yekam bargarde aghab
          digitalWrite(3,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(5,LOW);
    analogWrite(4,100);
    analogWrite(13,100);
    delay(500);
          digitalWrite(2,LOW);
          digitalWrite(3,HIGH);
          digitalWrite(6,LOW);
          digitalWrite(5,HIGH);
          analogWrite(4,240);
          analogWrite(13,240);
          delay(370);
          
          go=3;
          redflag=1;
        }
      }
          while(go==3){
            value();
            lineLeft();
            rangerast();
            rightcolordetect();
            if(sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
              for(int t=0;t<800;t++){
          value();
          lineLeft();
        }
              goto start;
            }
          }
        }
      
  
  
 }
 //=============================================================================================================================
 else if(rightcolor==4){
  if(yellowflag==0){
    lcd.setCursor(13,0);
  lcd.print("yel");
    int go=1;
    int a=0;
    for (int c2=0;c2<800;c2++){
      value();
      lineRight();
    }
    while(go==1){
      //a=0;
      value();
      
      //for(int o=0;o<13;o++){
      //  a+=sensor[o];
      //}
      linePlus();
      
      if (sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
        //vaysa
        go=2;
        yellowflag=1;
        //shelike tir ya zadane toop ya vazne ya...
        //dore 180 daraje
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(13,LOW);
        delay(1000);
        zard.write(30);
        delay(1000);
        digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    analogWrite(4,240);
    analogWrite(13,240);
    delay(370);
        while(go==2){
          value();
          lineRight();
          rangechap();
          leftcolordetect();
          if(sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
            for(int t=0;t<800;t++){
          value();
          lineRight();
        }
            goto start;
          }
        }
      }
    }
  }
  
 }
 else if(leftcolor==4){
   if(yellowflag==0){
    lcd.setCursor(13,0);
  lcd.print("yel");
    int go=1;
    int a=0;
    for (int c2=0;c2<800;c2++){
      value();
      lineLeft();
    }
    while(go==1){
      //a=0;
      value();
      
      //for(int o=0;o<13;o++){
      //  a+=sensor[o];
      //}
      linePlus();
      
      if (sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
        //vaysa
        go=2;
        yellowflag=1;
        //shelike tir ya zadane toop ya vazne ya...
        //dore 180 daraje
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(13,LOW);
        delay(1000);
        zard.write(60);
        delay(1000);
        digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    analogWrite(4,240);
    analogWrite(13,240);
    delay(370);
        while(go==2){
          value();
          lineLeft();
          rangerast();
          rightcolordetect();
          
          if(sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
            for(int t=0;t<800;t++){
          value();
          lineLeft();
        }
            goto start;
          }
        }
      }
    }
    
  }
  
 }
 //===============================================================
 else if(rightcolor==5){
  if(silverflag==0){
    
    lcd.setCursor(13,0);
  lcd.print("sil");
    int go=0;
    int m=0;
    int y=0;
    for (int c2=0;c2<800;c2++){
      value();
      lineRight();
    }
    while(go==0){
      
      value();
      linePlus();
      
      if(sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=3){
        lcd.clear();
        lcd.print("residim");
        while(y==0){
          digitalWrite(3,LOW);
          digitalWrite(6,LOW);
          digitalWrite(2,HIGH);
          digitalWrite(5,HIGH);
          analogWrite(4,100);
          analogWrite(13,100);
          if (analogRead(4)+analogRead(5)+analogRead(6) > SenCal[4]+SenCal[5]+SenCal[6]+11){
            lcd.clear();
            lcd.print("tahekhat");
            go=1;
            y=1;
           }
        }
      }
      
      
      
      
    }
    //dande aghab
    digitalWrite(3,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(5,LOW);
    analogWrite(4,100);
    analogWrite(13,100);
    delay(500);
    //dore kamel
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    analogWrite(4,240);
    analogWrite(13,240);
    delay(370);
    silverflag=1;
    while(go==1){
      value();
      lineRight();
      rangechap();
      leftcolordetect();
      
      lcd.clear();
      if (sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
        //digitalWrite(2,HIGH);
        //digitalWrite(3,LOW);
        //digitalWrite(5,LOW);
        //digitalWrite(6,HIGH);
        //analogWrite(4,255);
        //analogWrite(13,255);
        //delay(170);
        for(int t=0;t<800;t++){
          value();
          lineRight();
        }
        
        goto start;
      }
    }
    
  }
  
 }
 //====================================================
 else if(leftcolor==5){
  if(silverflag==0){
    lcd.setCursor(13,0);
  lcd.print("sil");
   int go=0;
    int m=0;
    int y=0;
    for (int c2=0;c2<800;c2++){
      value();
      lineLeft();
    }
    while(go==0){
      
      value();
      linePlus();
      
      if(sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=3){
        lcd.clear();
        lcd.print("residim");
        while(y==0){
          digitalWrite(3,LOW);
          digitalWrite(6,LOW);
          digitalWrite(2,HIGH);
          digitalWrite(5,HIGH);
          analogWrite(4,100);
          analogWrite(13,100);
          if (analogRead(4)+analogRead(5)+analogRead(6) > SenCal[4]+SenCal[5]+SenCal[6]+11){
            lcd.clear();
            lcd.print("tahekhat");
            go=1;
            y=1;
           }
        }
      }
      
      
      
      
    }
    //dande aghab
    digitalWrite(3,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(5,LOW);
    analogWrite(4,100);
    analogWrite(13,100);
    delay(500);
    //dore kamel
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    analogWrite(4,240);
    analogWrite(13,240);
    delay(370);
    silverflag=1;
    while(go==1){
      value();
      lineLeft();
      rangerast();
      rightcolordetect();
      
      lcd.clear();
      if (sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]>=4){
            //digitalWrite(2,LOW);
            //digitalWrite(3,HIGH);
            //digitalWrite(6,LOW);
            //digitalWrite(5,HIGH);
            //analogWrite(4,255);
            //analogWrite(13,255);
            //delay(170);
        for(int t=0;t<800;t++){
          value();
          lineLeft();
        }
        goto start;
      }
    }
    
    
  }
  
 }
 
  

  if(greenflag+blueflag+redflag+yellowflag+silverflag == 5){
    lcd.setCursor(0,0);
    lcd.print("ok");
    if (sensor[3]+sensor[4]+sensor[5]+sensor[6]+sensor[7]+sensor[0]+sensor[1]+sensor[2]+sensor[8]+sensor[9]+sensor[10]+sensor[11]+sensor[12] >= 6){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    analogWrite(4,0);
    analogWrite(13,0);
    delay(4000);
    lcd.setCursor(0,0);
    lcd.print("tamoome");
    }
  }
  
 
  
  //lcd.setCursor(0,0);
  //lcd.print(analogRead(4));
  //lcd.setCursor(4,0);
  //lcd.print(analogRead(5));
  //lcd.setCursor(8,0);
  //lcd.print(analogRead(6));
  
}
//======================================================================================================================================
void lineRight() {
    if (sensor[11] == 1) {
    //90 rast
    /*for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    analogWrite(4,150);
    analogWrite(13,150);
    delay(90);
  
  }
  else if (sensor[10] == 1) {
    /* for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    analogWrite(4,90);
    analogWrite(13,150);
    delay(60);
    
 
  }
  else if (sensor[9] == 1) {
     /*for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,0);
    analogWrite(13,130);
   
//==============================   
  }
  else if (sensor[8] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,0);
    analogWrite(13,110);
   
  }
  else if (sensor[7] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,30);
    analogWrite(13,110);
   
  }
  else if (sensor[6] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,60);
    analogWrite(13,110);
    
  }
  else if (sensor[5] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,110);
    analogWrite(13,110);
   // digitalWrite(44,HIGH);
    
  }
  else if (sensor[4] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,110);
    analogWrite(13,60);
    
  }
  else if (sensor[3] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,110);
    analogWrite(13,30);
  }
  else if (sensor[2] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,110);
    analogWrite(13,0);
   
  }
  else if (sensor[1] == 1) {
    /*for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,130);
    analogWrite(13,0);
   
    
  }
  else if (sensor[0] == 1){
    /* for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    analogWrite(4,150);
    analogWrite(13,90);
    delay(60);
   

  }
  else if (sensor[12] == 1) {
    //90 chap
    /*for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    analogWrite(4,150);
    analogWrite(13,150);
    delay(90);
   
  }
  else {
    
      //berim jolo
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,90);
    analogWrite(13,90);
    
   
  }

}
//================================================================
void lineLeft() {
  if (sensor[12] == 1) {
    //90 chap
    /*for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    analogWrite(4,150);
    analogWrite(13,150);
    delay(90);
   
  }
  else if (sensor[0] == 1){
    /* for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    analogWrite(4,150);
    analogWrite(13,90);
    delay(60);
  }
  else if (sensor[1] == 1) {
    /*for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,130);
    analogWrite(13,0);
   
    
  }
  else if (sensor[2] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,110);
    analogWrite(13,0);
   
  }
   else if (sensor[3] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,110);
    analogWrite(13,30);
  }
  else if (sensor[4] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,110);
    analogWrite(13,60);
    
  }
  else if (sensor[5] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,110);
    analogWrite(13,110);
   // digitalWrite(44,HIGH);
    
  }
  else if (sensor[6] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,60);
    analogWrite(13,110);
    
  }
  else if (sensor[7] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,30);
    analogWrite(13,110);
   
  }
  else if (sensor[8] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,0);
    analogWrite(13,110);
   
  }
  else if (sensor[9] == 1) {
     /*for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,0);
    analogWrite(13,130);
   
//==============================   
  }
  else if (sensor[10] == 1) {
    /* for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    analogWrite(4,90);
    analogWrite(13,150);
    delay(60);
    
 
  }
  else if (sensor[11] == 1) {
    //90 rast
    /*for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    analogWrite(4,150);
    analogWrite(13,150);
    delay(90);
  
  }
  else {
    
      //berim jolo
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,90);
    analogWrite(13,90);
    
   
  }
  
  
  
  
}



//===================================================================================================================================================================================
void value(){
  for(int y=0 ; y<13 ; y++) {
     if (analogRead(y) < SenCal[y] - 200) {
    sensor[y] = 1;
  }
  else {
    sensor[y] = 0;
  }
  }
}

void linePlus() {
  //chapool = 0;
  //digitalWrite(44,LOW);
  if (sensor[5] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,110);
    analogWrite(13,110);
   // digitalWrite(44,HIGH);
    
  }
  else if (sensor[4] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,110);
    analogWrite(13,60);
    
  }
  else if (sensor[6] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,60);
    analogWrite(13,110);
    
  }
  else if (sensor[3] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,110);
    analogWrite(13,30);
    
  }
  else if (sensor[7] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,30);
    analogWrite(13,110);
   
  }
  else if (sensor[2] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,110);
    analogWrite(13,0);
   
  }
  else if (sensor[8] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,0);
    analogWrite(13,110);
   
  }


  else if (sensor[1] == 1) {
    /*for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,130);
    analogWrite(13,0);
   
    
  }
  else if (sensor[9] == 1) {
     /*for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,0);
    analogWrite(13,130);
   
//==============================   
  }
  else if (sensor[0] == 1){
    /* for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    analogWrite(4,150);
    analogWrite(13,90);
    delay(60);
   

  }
  else if (sensor[10] == 1) {
    /* for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    analogWrite(4,90);
    analogWrite(13,150);
    delay(60);
    
 
  }

  
  else if (sensor[11] == 1) {
    //90 rast
    /*for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    analogWrite(4,150);
    analogWrite(13,150);
    delay(90);
  
  }
  else if (sensor[12] == 1) {
    //90 chap
    /*for(int p=2;p<8;p++) {
      digitalWrite(p,HIGH);
      //both motors brake
    }
    delay(100);*/
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    analogWrite(4,150);
    analogWrite(13,150);
    delay(90);
   
  }
  else {
    
      //berim jolo
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,90);
    analogWrite(13,90);
    
   
  }
  //delay(50);
  //=====================================================================================================
}
void lineMinus() {
  if (sensor[5] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,90);
    analogWrite(13,90);
   // digitalWrite(44,HIGH);
    
  }
  else if (sensor[4] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,90);
    analogWrite(13,60);
    
  }
  else if (sensor[6] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,60);
    analogWrite(13,90);
    
  }
  else if (sensor[3] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,90);
    analogWrite(13,30);
    
  }
  else if (sensor[7] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,30);
    analogWrite(13,90);
   
  }
  else if (sensor[2] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,110);
    analogWrite(13,20);
   
  }
  else if (sensor[8] == 1) {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,20);
    analogWrite(13,110);
   
  }
  else {
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(4,90);
    analogWrite(13,90);
  }

}
//===========================================================




//================================================================
void rangerast() {
  // anjame code baraye tashkhis dadane range sensor range samte rast va taiine righcolor
  
    
//===================================================
//===================================================     
      digitalWrite(S2,LOW);
      digitalWrite(S3,LOW);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      rightR = frequency;

      // Setting Green filtered photodiodes to be read
      digitalWrite(S2,HIGH);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      rightG = frequency;


      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2,LOW);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      rightB = frequency;



      






    
}
//=================================================================
void rangechap() {
  // anjame code baraye tashkhis dadane range sensor range samte chap va taiine leftcolor
  
   

      
      digitalWrite(S2L,LOW);
      digitalWrite(S3L,LOW);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      leftR = frequencyL;

      // Setting Green filtered photodiodes to be read
      digitalWrite(S2L,HIGH);
      digitalWrite(S3L,HIGH);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      leftG = frequencyL;
      


      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2L,LOW);
      digitalWrite(S3L,HIGH);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      leftB = frequencyL;








    
}
//=================================================================================================================
void rightcolordetect() {
 
if (rightR < RgreenR + 15 && rightR > RgreenR - 15 && rightG < RgreenG + 15 && rightG > RgreenG - 15 && rightB < RgreenB + 15 && rightB > RgreenB - 15){
    

    rightcolor=1;
    
  }
  else if (rightR < RblueR + 23 && rightR > RblueR - 23 && rightG < RblueG + 23 && rightG > RblueG - 23 && rightB < RblueB + 23 && rightB > RblueB - 23) {

    rightcolor=2;
  }
  else if (rightR < RredR + 20 && rightR > RredR - 20 && rightG < RredG + 20 && rightG > RredG - 20 && rightB < RredB + 20 && rightB > RredB - 20){

    rightcolor=3;
  }
  else if (rightR < RyellowR + 15 && rightR > RyellowR - 15 && rightG < RyellowG + 15 && rightG > RyellowG - 15 && rightB < RyellowB + 15 && rightB > RyellowB - 15){

   rightcolor=4;
  }
  else if (rightR < RsilverR + 4 && rightR > RsilverR - 1 && rightG < RsilverG + 4 && rightG > RsilverG - 1 && rightB < RsilverB + 4 && rightB > RsilverB - 1){

   rightcolor=5;
  }

  
  else {
    rightcolor=0;
  }
  
  
}

void leftcolordetect() {
  if (leftR < LgreenR + 15 && leftR > LgreenR - 15 && leftG < LgreenG + 15&& leftG > LgreenG - 15 && leftB < LgreenB + 15 && leftB > LgreenB - 15){
    

    leftcolor=1;
    
  }
  else if (leftR < LblueR + 23 && leftR > LblueR - 23 && leftG < LblueG + 23 && leftG > LblueG - 23 && leftB < LblueB + 23 && leftB > LblueB - 23) {

    leftcolor=2;
  }
  else if (leftR < LredR + 20 && leftR > LredR - 20 && leftG < LredG + 20 && leftG > LredG - 20&& leftB < LredB + 20 && leftB > LredB - 20){

    leftcolor=3;
  }
  else if (leftR < LyellowR + 15 && leftR > LyellowR - 15 && leftG < LyellowG + 15 && leftG > LyellowG - 15 && leftB < LyellowB + 15 && leftB > LyellowB - 15){

   leftcolor=4;
  }
  else if (leftR < LsilverR + 4 && leftR > LsilverR - 1 && leftG < LsilverG + 4 && leftG > LsilverG - 1 && leftB < LsilverB + 4 && leftB > LsilverB - 1){

    leftcolor=5;
  }

  
  else {
    leftcolor=0;
  }
  
}

/*||================================================================||
 * tavajoh
 * dar hameye marahele anjam dadane karha deghat shavad barcode kodam
 * samte khat ast va olaviatbandi line ontarafi chide shavad
 * 
 * deghat shavad ke dar har marhale yekami delay gonjande shavad
 * 
 * deghat shavad ba flag o .. malom shavad ke robot moghe bargashtan
 * az har mamoriat bayad olaviatesh kodomvari bashe yani bayad bere 
 * kodom var
 * 
 * baraye bargashte robot az har faaliat aval yekam dande aghab biad
 * badesh dore 180 daraje bezane
 * 
 * 
 * 
 * ================================================================||
*/
void green() {
  //football
  //vaghti resid be code rangi bere dar jahate matlob badesh dar masir jahate shoot ro malom kone va shoot kone tu darvaze bad biad aghab dor bezane va bere
}

void red() {
  //vazne bardari 
  //bere jolo vaghti be khate amood resid vayse stepper ta tah bere bala bad bere jolo vaghti resid be khate amoode badi stepper ta tah
  //biad paiin badesh dore kamel bezane bere jolo yekam va khat ro dombal kone
}


void silver() {
  // hol dadan
  //vaghti resid be khate amod saf biad jolo ta berese be khate noghreii bad yekam biad aghab va dor bezane bargarde
}

void finishline() {
  //vaghti resid be khate payan (tedade sensor haye 1 shode kheili ziad shod) vayse va ye LED roshan she ke malom she fahmide (40 emtiaz darad)
}
//===================================================================================================================================================================================================================================================
void colorcalibrate(){
  // calibre kardane rang ha
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("sabz rast");
  while(digitalRead(36) == LOW) {
    delay(50);
  }
  delay(1000);
        digitalWrite(S2,LOW);
      digitalWrite(S3,LOW);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RgreenR = frequency;
      
    
      // Setting Green filtered photodiodes to be read
      digitalWrite(S2,HIGH);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RgreenG = frequency;

      
      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2,LOW);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RgreenB = frequency;
      
//==================================================
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("sabz chap");
  while(digitalRead(36) == LOW) {
    delay(50);
  }
   delay(1000);
          digitalWrite(S2L,LOW);
      digitalWrite(S3L,LOW);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LgreenR = frequencyL;
      
      // Setting Green filtered photodiodes to be read
      digitalWrite(S2L,HIGH);
      digitalWrite(S3L,HIGH);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LgreenG = frequencyL;

      
      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2L,LOW);
      digitalWrite(S3L,HIGH);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LgreenB = frequencyL;
      


  //======================================
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("abi rast");
  while(digitalRead(36) == LOW) {
    delay(50);
  }
   delay(1000);
          digitalWrite(S2,LOW);
      digitalWrite(S3,LOW);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RblueR = frequency;
      
      // Setting Green filtered photodiodes to be read
      digitalWrite(S2,HIGH);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RblueG = frequency;

      
      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2,LOW);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RblueB = frequency;
      
//=========================================================
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("abi chap");
  while(digitalRead(36) == LOW) {
    delay(50);
  }
   delay(1000);
          digitalWrite(S2L,LOW);
      digitalWrite(S3L,LOW);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LblueR = frequencyL;
      
      // Setting Green filtered photodiodes to be read
      digitalWrite(S2L,HIGH);
      digitalWrite(S3L,HIGH);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LblueG = frequencyL;

      
      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2L,LOW);
      digitalWrite(S3L,HIGH);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LblueB = frequencyL;
      
  //=====================================================
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ghermez rast");
  while(digitalRead(36) == LOW) {
    delay(50);
  }
   delay(1000);
         digitalWrite(S2,LOW);
      digitalWrite(S3,LOW);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RredR = frequency;
      
      // Setting Green filtered photodiodes to be read
      digitalWrite(S2,HIGH);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RredG = frequency;

      
      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2,LOW);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RredB = frequency;
      
//==================================================
 lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("ghermez chap");
  while(digitalRead(36) == LOW) {
    delay(50);
  }
   delay(1000);
          digitalWrite(S2L,LOW);
      digitalWrite(S3L,LOW);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LredR = frequencyL;
      
      // Setting Green filtered photodiodes to be read
      digitalWrite(S2L,HIGH);
      digitalWrite(S3L,HIGH);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LredG = frequencyL;

      
      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2L,LOW);
      digitalWrite(S3L,HIGH);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LredB = frequencyL;
      
//==========================================================
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("zard rast");
  while(digitalRead(36) == LOW) {
    delay(50);
  }
   delay(1000);
         digitalWrite(S2,LOW);
      digitalWrite(S3,LOW);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RyellowR = frequency;
      
      // Setting Green filtered photodiodes to be read
      digitalWrite(S2,HIGH);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RyellowG = frequency;

      
      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2,LOW);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RyellowB = frequency;
      
//========================================================
 lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("zard chap");
  while(digitalRead(36) == LOW) {
    delay(50);
  }
   delay(1000);
          digitalWrite(S2L,LOW);
      digitalWrite(S3L,LOW);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LyellowR = frequencyL;
      
      // Setting Green filtered photodiodes to be read
      digitalWrite(S2L,HIGH);
      digitalWrite(S3L,HIGH);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LyellowG = frequencyL;

      
      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2L,LOW);
      digitalWrite(S3L,HIGH);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LyellowB = frequencyL;
      
//============================================================
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("toosi rast");
  while(digitalRead(36) == LOW) {
    delay(50);
  }
   delay(1000);
          digitalWrite(S2,LOW);
      digitalWrite(S3,LOW);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RsilverR = frequency;
      
      // Setting Green filtered photodiodes to be read
      digitalWrite(S2,HIGH);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RsilverG = frequency;

      
      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2,LOW);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequency = constrain(frequency, 0, 1000);
      RsilverB = frequency;
      
      //=============================================
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("toosi chap");
  while(digitalRead(36) == LOW) {
    delay(50);
  }
   delay(1000);
         digitalWrite(S2L,LOW);
      digitalWrite(S3L,LOW);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LsilverR = frequencyL;
      
      // Setting Green filtered photodiodes to be read
      digitalWrite(S2L,HIGH);
      digitalWrite(S3L,HIGH);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LsilverG = frequencyL;

      
      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2L,LOW);
      digitalWrite(S3L,HIGH);
      // Reading the output frequency
      frequencyL = pulseIn(sensorOutL, LOW);
      // Printing the value on the serial monitor
      //in chand khat ro khodam ezafe kardam ke bebinam mishe maghadir
      //ro hefz kard toye yek baze ya na
      frequencyL = constrain(frequencyL, 0, 1000);
      LsilverB = frequencyL;
      
//==================================================================


/*
  //lcd bezar sefid rast va dokmaro bezan
  while(digitalRead(34) == LOW) {
    delay(100);
  }
  //check kardane sefid rast

  //lcd sefid chap dokme
  while(digitalRead(34) == LOW) {
    delay(100);
  }
  //check kardane sefid chap

  //lcd bezar siah rast va dokmaro bezan
  while(digitalRead(34) == LOW) {
    delay(100);
  }
  //check kardane siah rast

  //lcd siah chap dokme
  while(digitalRead(34) == LOW) {
    delay(100);
  }
  //check kardane siah chap
*/  

while(digitalRead(36)==LOW){
  delay(50);
}
lcd.clear();
lcd.print("ok");
delay(500);
while(digitalRead(36)==LOW){
  delay(50);
}
  
}


/*void colorcode() {
  // gheire rangi mishe 0
  // sabz mishe 1
  // abi mishe 2
  // ghermez mishe 3
  // zard mishe 4
  // noghreii mishe 5
  if (rightisgreen==1){
    rightcolor=1;
  }
  else if (rightisblue==1){
    rightcolor=2;
  }
  else if (rightisred==1){
    rightcolor=3;
  }
  else if (rightisyellow==1){
    rightcolor=4;
  }
  else if (rightissilver==1){
    rightcolor=5;
  }
  else {
    rightcolor=0;
  }
  // right is done
  if (leftisgreen==1){
    leftcolor=1;
  }
  else if (leftisblue==1){
    leftcolor=2;
  }
  else if (leftisred==1){
    leftcolor=3;
  }
  else if (leftisyellow==1){
    leftcolor=4;
  }
  else if (leftissilver==1){
    leftcolor=5;
  }
  else {
    leftcolor=0;
  }
}*/
//========================================================================================================================
void whitebalance() {
  lcd.clear();
  lcd.print("white balance");
  while(digitalRead(36) == LOW) {
    delay(50);
    digitalWrite(12,HIGH);
  }
  digitalWrite(12,LOW);
  for(int i=0; i<13 ;i++){
    SenCal[i] = analogRead(i);
  }
  lcd.clear();
  
  
}
void silverbalance(){
  delay(1000);
  lcd.print("silverbalance");
  while(digitalRead(36) == LOW){
    delay(50);
  }
  silverline = analogRead(4);
  silverline += analogRead(5);
  silverline += analogRead(6);
  delay(1000);
}
void arrowPrime() {
  //paiin avordane servo va bala bordane mojadad baraye gozashtane tir dar tirkaman
}
