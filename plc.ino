#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h> 

Adafruit_SSD1306 display(-1); 

int CounterSelector = 0;
int c0=0,b0=0; int c1=0,b1=0; int c2=0,b2=0; int c3=0,b3=0; int c4=0,c5=0,b5=0,c6=0,b6=0,c7=0,c8=0,b7=0;
int b11=0,c10=0,b10=0,c11=0,c9=0;
int loops=0;
String op1[] = {"OR","AN","N","D","T1","T2","T3","Q1","Q2","Q3","Q4"};
String op2[] = {"|","&","!",">"};
String op5[] = {"1)","2)","3)","4)","Q1","Q2","Q3","Q4","T","F"};
String opr1A;  String opr2A;  String opr3A;  String opr4A;
String opr1B;  String opr2B;  String opr3B;  String opr4B;
String opr1C;  String opr2C;  String opr3C;  String opr4C;
String outputs;
String outputs1,outputs2,outputs3;
bool Q1=false,Q2=false,Q3=false,Q4=false,Qb1,Qb2,Qb3,Qb4;
bool op3[17];
bool op4[17];
bool oprQ1,oprQ2,oprQ3;

bool v0A= false,v1A=false,v0B=false,v1B=false,v0C=false,v1C=false,v1D=false,v0D=false;
void setup()  
{                
 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  Serial.begin(9600);
 
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("(1)");

  display.setCursor(0,8);
  display.println("(2)");
 
  display.setCursor(0,16);
  display.println("(3)");

  display.setCursor(0,24);
  display.println("(4)");
 
  display.display();
  delay(1000);
  //display.clearDisplay();
  pinMode(2,INPUT_PULLUP);  //Selector
  pinMode(3,INPUT_PULLUP);  //Enter
  pinMode(4,INPUT_PULLUP);  
  pinMode(5,INPUT_PULLUP);

  pinMode(13,OUTPUT); //Q1
  pinMode(12,OUTPUT); //Q2
  pinMode(11,OUTPUT); //Q3
  pinMode(10,OUTPUT); //Q4


  pinMode(6,INPUT); //I1
  pinMode(7,INPUT); //I2
  pinMode(8,INPUT); //I3
  pinMode(9,INPUT); //I4
  selectorCuror();

 
}
void INT(){
  display.setCursor(0,0);
  display.println("1)");

  display.setCursor(0,8);
  display.println("2)");
 
  display.setCursor(0,16);
  display.println("3)");

  display.setCursor(0,24);
  display.println("4)");
 
  display.display();
 
}

void loop() {
         op3[0]=digitalRead(6); op3[1]=digitalRead(7); op3[2]=digitalRead(8); op3[3]=digitalRead(9);
         op3[4]=!digitalRead(6);op3[5]=!digitalRead(7);op3[6]=!digitalRead(8);op3[7]=!digitalRead(9);

         op4[0]=digitalRead(13); op4[1]=digitalRead(12); op4[2]=digitalRead(11); op4[3]=digitalRead(10);
         op4[4]=!digitalRead(13);op4[5]=!digitalRead(12);op4[6]=!digitalRead(11);op4[7]=!digitalRead(10);

         INT();
          
        display.setCursor(28,0);
        display.println(opr1A);
   if(opr1A == "Q1" || opr1A == "Q2" || opr1A == "Q3" || opr1A == "Q4")
        {
          display.setCursor(45,0);
          display.println("-");
          display.setCursor(50,0);
          display.println("-");                
        }
        else
        {
        display.setCursor(45,0);
        display.println(b0);
        display.setCursor(50,0);
        display.println(c0);
        }
       if(opr2A == "Q1" || opr2A == "Q2" || opr2A == "Q3" || opr2A == "Q4")
        {
          display.setCursor(45,8);
          display.println("-");
          display.setCursor(50,8);
          display.println("-");                
        }
        else
        {
          display.setCursor(45,8);
          display.println(b3);
          display.setCursor(50,8);
          display.println(c3);
        }
        if(opr3A == "Q1" || opr3A == "Q2" || opr3A == "Q3" || opr3A == "Q4")
        {
          display.setCursor(45,16);
          display.println("-");
          display.setCursor(50,16);
          display.println("-");                
        }
        else
        {
          display.setCursor(45,16);
          display.println(b6);
          display.setCursor(50,16);
          display.println(c6);
        }
        if(opr4A == "Q1" || opr4A == "Q2" || opr4A == "Q3" || opr4A == "Q4")
        {
          display.setCursor(45,24);
          display.println("-");
          display.setCursor(50,24);
          display.println("-");                
        }
        else
        {
          display.setCursor(45,24);
          display.println(b10);
          display.setCursor(50,24);
          display.println(c10);
        }
        display.setCursor(56,0);
        display.println(opr1B);
        display.setCursor(71,0);
        display.println(opr1C);
        display.setCursor(100,0);
        display.println(outputs);
       
        check();
       
        //-------------------OUTPUTs--------------------
       
        if(outputs=="Q1"){digitalWrite(13,Qb1);}
        if(outputs=="Q2"){digitalWrite(12,Qb1);}
        if(outputs=="Q3"){digitalWrite(11,Qb1);}
        if(outputs=="Q4"){digitalWrite(10,Qb1);}
        check();
        if(outputs1=="Q1"){digitalWrite(13,Qb2);}
        if(outputs1=="Q2"){digitalWrite(12,Qb2);}
        if(outputs1=="Q3"){digitalWrite(11,Qb2);}
        if(outputs1=="Q4"){digitalWrite(10,Qb2);}
        check();
        if(outputs2=="Q1"){digitalWrite(13,Qb3);}
        if(outputs2=="Q2"){digitalWrite(12,Qb3);}
        if(outputs2=="Q3"){digitalWrite(11,Qb3);}
        if(outputs2=="Q4"){digitalWrite(10,Qb3);}
        check();
        if(outputs3=="Q1"){digitalWrite(13,Qb4);}
        if(outputs3=="Q2"){digitalWrite(12,Qb4);}
        if(outputs3=="Q3"){digitalWrite(11,Qb4);}
        if(outputs3=="Q4"){digitalWrite(10,Qb4);}
 
        display.setCursor(28,8);
        display.println(opr2A);
        display.setCursor(55,8);
        display.println(opr2B);
        display.setCursor(71,8);
        display.println(opr2C);
        display.setCursor(100,8);
        display.println(outputs1);

        display.setCursor(28,16);
        display.println(opr3A);
        display.setCursor(55,16);
        display.println(opr3B);
        display.setCursor(71,16);
        display.println(opr3C);
        display.setCursor(100,16);
        display.println(outputs2);
       
        display.setCursor(28,24);
        display.println(opr4A);
        display.setCursor(55,24);
        display.println(opr4B);
        display.setCursor(71,24);
        display.println(opr4C);
        display.setCursor(100,24);
        display.println(outputs3);
       
        display.display();
       
  if(digitalRead(2)==LOW)
  {
    delay(50);
    CounterSelector++;
    selectorCuror();
    if(CounterSelector > 3){CounterSelector=0; selectorCuror();}
  }

  if(digitalRead(3)==LOW)
  {
    delay(50);
    function();
  }
  //************************************************************
}
void function(){
  if(CounterSelector == 0)
  {
    display.clearDisplay();
    INT();
    display.setCursor(18,0);
    display.println("--");
    display.display();
    while(digitalRead(3)!=LOW)
    {
      if(digitalRead(2)==LOW)
      {
        delay(100);
        display.clearDisplay();
       
        INT();
        display.setCursor(18,0);
        display.println("--");
        display.setCursor(28,0);    
        display.println(op1[c0]);
        opr1A = op1[c0];
        oprQ1 = op2[c0];
        display.display();
        c0++;
        if(c0>10){c0=0;}
      }
      if(digitalRead(4)==LOW)
      {
        display.clearDisplay();
        if(opr1A=="Q1" || opr1A=="Q2" || opr1A=="Q3" || opr1A=="Q4"){goto L1;}
        INT();
        c0++;
        if(c0>4){c0=1;}
        display.setCursor(28,0);
        display.println(opr1A);
        display.setCursor(55,0);
        display.println(c0);
        display.display();
        b0=c0;                  
      }
      if(digitalRead(5)==LOW)
      {
        display.clearDisplay();
        if(opr1A=="N" || opr1A=="D" || opr1A=="Q1" || opr1A=="Q2" || opr1A=="Q3" || opr1A=="Q4"){goto L1;}
        INT();
        c0++;
        if(c0>4){c0=1;}
        display.setCursor(28,0);
        display.println(opr1A);
        display.setCursor(55,0);
        display.println(b0);
        display.setCursor(88,0);
        display.println(c0);
        display.display();   
       
      }
    delay(100);
    }
    //c=0;
    while(digitalRead(3)==LOW){L1: display.clearDisplay();}
    while(digitalRead(3)!=LOW)
    {
        INT();
        display.setCursor(28,0);
        display.println(opr1A);
        if(opr1A == "Q1" || opr1A == "Q2" || opr1A == "Q3" || opr1A == "Q4")
        {
          display.setCursor(45,0);
          display.println("-");
          display.setCursor(50,0);
          display.println("-");
        }
        else
        {
          display.setCursor(45,0);
          display.println(b0);
          display.setCursor(50,0);
          display.println(c0);
        }
       
        if(digitalRead(2)==LOW)
        {
         
          display.clearDisplay();
          display.setCursor(28,0);
          display.println(opr1A);
          display.setCursor(56,0);
          display.println(op2[c1]);
          display.display();
          opr1B = op2[c1];    
          c1++;
          if(c1>3){c1=0;}
         
        }
    }
    delay(40);
    while(digitalRead(3)==LOW){display.clearDisplay();}
    while(digitalRead(3)!=LOW)
    {
          INT();
          //display.clearDisplay();
          display.setCursor(28,0);
          display.println(opr1A);
          display.setCursor(56,0);
          display.println(opr1B);
          display.setCursor(66,0);
          display.println("-");
          display.display();

          if(digitalRead(2)==LOW)
        {
          display.clearDisplay();
          display.setCursor(71,0);
          opr1C = op5[c2];
          display.println(opr1C); 
          display.display();
          c2++;
          if(c2>9){c2=0;}
         
        }
       
       delay(100);
    }

    while(digitalRead(3)==LOW){display.clearDisplay();}
    while(digitalRead(3)!=LOW)
    {
       INT();
          display.setCursor(28,0);
          display.println(opr1A);
          display.setCursor(56,0);
          display.println(opr1B);
          display.setCursor(66,0);
          display.println("-");
          display.setCursor(71,0);
          display.println(opr1C);
          display.setCursor(88,0);
          display.println("-");
          display.display();
        if(digitalRead(2)==LOW)
        {
          display.clearDisplay();
          INT();
          display.setCursor(28,0);
          display.println(opr1A);
          display.setCursor(56,0);
          display.println(opr1B);
          display.setCursor(66,0);
          display.println("-");
          display.setCursor(71,0);
          display.println(opr1C);  
          display.setCursor(100,0);
          if(b2==0){outputs="Q1";}
          if(b2==1){outputs="Q2";}
          if(b2==2){outputs="Q3";}
          if(b2==3){outputs="Q4";}
         
          display.println(outputs); 
          display.display();
          b2++;
          if(b2>3){b2=0;}
        }
        delay(200);
    }
  }
  if(CounterSelector == 1)
  {
    display.clearDisplay();
    INT();
    display.setCursor(18,8);
    display.println("--");
    display.display();
    while(digitalRead(3)!=LOW)
    {
      if(digitalRead(2)==LOW)
      {
        delay(100);
        display.clearDisplay();
       
        INT();
        display.setCursor(18,8);
        display.println("--");
        display.setCursor(28,8);   
        display.println(op1[c3]);
        opr2A = op1[c3];
        //oprQ1 = op2[c3];
        display.display();
        c3++;
        if(c3>10){c3=0;}
      }
      if(digitalRead(4)==LOW)
      {
        display.clearDisplay();
        if(opr2A=="Q1" || opr2A=="Q2" || opr2A=="Q3" || opr2A=="Q4"){goto L1;}
        INT();
        c3++;
        if(c3>4){c3=1;}
        display.setCursor(28,8);
        display.println(opr2A);
        display.setCursor(55,8);
        display.println(c3);
        display.display();
        b3=c3;
      }
      if(digitalRead(5)==LOW)
      {
        display.clearDisplay();
        if(opr2A=="N" || opr2A=="D" || opr2A=="Q1" || opr2A=="Q2" || opr2A=="Q3" || opr2A=="Q4"){goto L3;}
        INT();
        c3++;
        if(c3>4){c3=1;}
        display.setCursor(28,8);
        display.println(opr1A);
        display.setCursor(55,8);
        display.println(b3);
        display.setCursor(88,8);
        display.println(c3);
        display.display();
       
      }
    delay(100);
    }
    //c=0;
    while(digitalRead(3)==LOW){L3: display.clearDisplay();}
    while(digitalRead(3)!=LOW)
    {
        INT();
        display.setCursor(28,8);
        display.println(opr2A);
        if(opr2A == "Q1" || opr2A == "Q2" || opr2A == "Q3" || opr2A == "Q4")
        {
          display.setCursor(45,8);
          display.println("-");
          display.setCursor(50,8);
          display.println("-");
        }
        else
        {
          display.setCursor(45,8);
          display.println(b3);
          display.setCursor(50,8);
          display.println(c3);
        }
       
        if(digitalRead(2)==LOW)
        {
         
          display.clearDisplay();
          display.setCursor(28,8);
          display.println(opr2A);
          display.setCursor(56,8);
          display.println(op2[c4]);
          display.display();
          opr2B = op2[c4];
          c4++;
          if(c4>3){c4=0;}
         
        }
    }
    delay(40);
    while(digitalRead(3)==LOW){display.clearDisplay();}
    while(digitalRead(3)!=LOW)
    {
          INT();
          //display.clearDisplay();
          display.setCursor(28,8);
          display.println(opr2A);
          display.setCursor(56,8);
          display.println(opr2B);
          display.setCursor(66,8);
          display.println("-");
          display.display();

          if(digitalRead(2)==LOW)
        {
          display.clearDisplay();
          display.setCursor(71,8);
          opr2C = op5[c5];
          display.println(opr2C);
          display.display();
          c5++;
          if(c5>9){c5=0;}
         
        }
       
       delay(100);
    }

    while(digitalRead(3)==LOW){display.clearDisplay();}
    while(digitalRead(3)!=LOW)
    {
       INT();
          display.setCursor(28,8);
          display.println(opr1A);
          display.setCursor(56,8);
          display.println(opr2B);
          display.setCursor(66,8);
          display.println("-");
          display.setCursor(71,8);
          display.println(opr2C);
          display.setCursor(88,8);
          display.println("-");
          display.display();
        if(digitalRead(2)==LOW)
        {
          display.clearDisplay();
          INT();
          display.setCursor(28,8);
          display.println(opr2A);
          display.setCursor(56,8);
          display.println(opr2B);
          display.setCursor(66,8);
          display.println("-");
          display.setCursor(71,8);
          display.println(opr2C);  
          display.setCursor(100,8);
          if(b5==0){outputs1="Q1";}
          if(b5==1){outputs1="Q2";}
          if(b5==2){outputs1="Q3";}
          if(b5==3){outputs1="Q4";}
         
          display.println(outputs1);
          display.display();
          b5++;
          if(b5>3){b5=0;}
        }
        delay(200);
    }
  }
  if(CounterSelector == 2)
  {
    display.clearDisplay();
    INT();
    display.setCursor(18,16);
    display.println("--");
    display.display();
    while(digitalRead(3)!=LOW)
    {
      if(digitalRead(2)==LOW)
      {
        delay(100);
        display.clearDisplay();
       
        INT();
        display.setCursor(18,16);
        display.println("--");
        display.setCursor(28,16);
        display.println(op1[c6]);
        opr3A = op1[c6];
        //oprQ1 = op2[c3];
        display.display();
        c6++;
        if(c6>10){c6=0;}
      }
      if(digitalRead(4)==LOW)
      {
        display.clearDisplay();
        if(opr3A=="Q1" || opr3A=="Q2" || opr3A=="Q3" || opr3A=="Q4"){goto L1;}
        INT();
        c6++;
        if(c6>4){c6=1;}
        display.setCursor(28,16);
        display.println(opr3A);
        display.setCursor(55,16);
        display.println(c6);
        display.display();
        b6=c6;
      }
      if(digitalRead(5)==LOW)
      {
        display.clearDisplay();
        if(opr3A=="N" || opr3A=="D" || opr3A=="Q1" || opr3A=="Q2" || opr3A=="Q3" || opr3A=="Q4"){goto L5;}
        INT();
        c6++;
        if(c6>4){c6=1;}
        display.setCursor(28,16);
        display.println(opr3A);
        display.setCursor(55,16);
        display.println(b6);
        display.setCursor(88,16);
        display.println(c6);
        display.display();
       
      }
    delay(100);
    }
    //c=0;
    while(digitalRead(3)==LOW){L5: display.clearDisplay();}
    while(digitalRead(3)!=LOW)
    {
        INT();
        display.setCursor(28,16);
        display.println(opr3A);
        if(opr3A == "Q1" || opr3A == "Q2" || opr3A == "Q3" || opr3A == "Q4")
        {
          display.setCursor(45,16);
          display.println("-");
          display.setCursor(50,16);
          display.println("-");
        }
        else
        {
          display.setCursor(45,16);
          display.println(b6);
          display.setCursor(50,16);
          display.println(c6);
        }
       
        if(digitalRead(2)==LOW)
        {
         
          display.clearDisplay();
          display.setCursor(28,16);
          display.println(opr3A);
          display.setCursor(56,16);
          display.println(op2[c7]);
          display.display();
          opr3B = op2[c7]; 
          c7++;
          if(c7>3){c7=0;}
         
        }
    }
    delay(40);
    while(digitalRead(3)==LOW){display.clearDisplay();}
    while(digitalRead(3)!=LOW)
    {
          INT();
          //display.clearDisplay();
          display.setCursor(28,16);
          display.println(opr3A);
          display.setCursor(56,16);
          display.println(opr3B);
          display.setCursor(66,16);
          display.println("-");
          display.display();

          if(digitalRead(2)==LOW)
        {
          display.clearDisplay();
          display.setCursor(71,16);
          opr3C = op5[c8];
          display.println(opr3C);
          display.display();
          c8++;
          if(c8>9){c8=0;}
         
        }
       
       delay(100);
    }

    while(digitalRead(3)==LOW){display.clearDisplay();}
    while(digitalRead(3)!=LOW)
    {
       INT();
          display.setCursor(28,16);
          display.println(opr3A);
          display.setCursor(56,16);
          display.println(opr3B);
          display.setCursor(66,16);
          display.println("-");
          display.setCursor(71,16);
          display.println(opr3C);
          display.setCursor(88,16);
          display.println("-");
          display.display();
        if(digitalRead(2)==LOW)
        {
          display.clearDisplay();
          INT();
          display.setCursor(28,16);
          display.println(opr3A);
          display.setCursor(56,16);
          display.println(opr3B);
          display.setCursor(66,16);
          display.println("-");
          display.setCursor(71,16);
          display.println(opr3C);  
          display.setCursor(100,16);
          if(b7==0){outputs2="Q1";}
          if(b7==1){outputs2="Q2";}
          if(b7==2){outputs2="Q3";}
          if(b7==3){outputs2="Q4";}
         
          display.println(outputs2);
          display.display();
          b7++;
          if(b7>3){b7=0;}
        }
        delay(200);
    }
  }
  if(CounterSelector == 3)
  {
    display.clearDisplay();
    INT();
    display.setCursor(18,24);
    display.println("--");
    display.display();
    while(digitalRead(3)!=LOW)
    {
      if(digitalRead(2)==LOW)
      {
        delay(100);
        display.clearDisplay();
       
        INT();
        display.setCursor(18,24);
        display.println("--");
        display.setCursor(28,24);
        display.println(op1[c10]);
        opr4A = op1[c10];
        //oprQ1 = op2[c3];
        display.display();
        c10++;
        if(c10>10){c10=0;}
      }
      if(digitalRead(4)==LOW)
      {
        display.clearDisplay();
        if(opr4A=="Q1" || opr4A=="Q2" || opr4A=="Q3" || opr4A=="Q4"){goto L8;}
        INT();
        c10++;
        if(c10>4){c10=1;}
        display.setCursor(28,24);
        display.println(opr4A);
        display.setCursor(55,24);
        display.println(c10);
        display.display();
        b10=c10;
      }
      if(digitalRead(5)==LOW)
      {
        display.clearDisplay();
        if(opr4A=="N" || opr4A=="D" || opr4A=="Q1" || opr4A=="Q2" || opr4A=="Q3" || opr4A=="Q4"){goto L8;}
        INT();
        c10++;
        if(c10>4){c10=1;}
        display.setCursor(28,24);
        display.println(opr4A);
        display.setCursor(55,24);
        display.println(b10);
        display.setCursor(88,24);
        display.println(c10);
        display.display();
       
      }
    delay(100);
    }
    //c=0;
    while(digitalRead(3)==LOW){L8: display.clearDisplay();}
    while(digitalRead(3)!=LOW)
    {
        INT();
        display.setCursor(28,24);
        display.println(opr4A);
        if(opr4A == "Q1" || opr4A == "Q2" || opr4A == "Q3" || opr4A == "Q4")
        {
          display.setCursor(45,24);
          display.println("-");
          display.setCursor(50,24);
          display.println("-");
        }
        else
        {
          display.setCursor(45,24);
          display.println(b10);
          display.setCursor(50,24);
          display.println(c10);
        }
       
        if(digitalRead(2)==LOW)
        {
         
          display.clearDisplay();
          display.setCursor(28,24);
          display.println(opr4A);
          display.setCursor(56,24);
          display.println(op2[c9]);
          display.display();
          opr4B = op2[c9]; 
          c9++;
          if(c9>3){c9=0;}
         
        }
    }
    delay(40);
    while(digitalRead(3)==LOW){display.clearDisplay();}
    while(digitalRead(3)!=LOW)
    {
          INT();
          //display.clearDisplay();
          display.setCursor(28,24);
          display.println(opr4A);
          display.setCursor(56,24);
          display.println(opr4B);
          display.setCursor(66,24);
          display.println("-");
          display.display();

          if(digitalRead(2)==LOW)
        {
          display.clearDisplay();
          display.setCursor(71,24);
          opr4C = op5[c11];
          display.println(opr4C);
          display.display();
          c11++;
          if(c8>9){c8=0;}
         
        }
       
       delay(100);
    }

    while(digitalRead(3)==LOW){display.clearDisplay();}
    while(digitalRead(3)!=LOW)
    {
       INT();
          display.setCursor(28,24);
          display.println(opr4A);
          display.setCursor(56,24);
          display.println(opr4B);
          display.setCursor(66,24);
          display.println("-");
          display.setCursor(71,24);
          display.println(opr4C);
          display.setCursor(88,24);
          display.println("-");
          display.display();
        if(digitalRead(2)==LOW)
        {
          display.clearDisplay();
          INT();
          display.setCursor(28,24);
          display.println(opr4A);
          display.setCursor(56,24);
          display.println(opr4B);
          display.setCursor(66,24);
          display.println("-");
          display.setCursor(71,24);
          display.println(opr4C);  
          display.setCursor(100,24);
          if(b11==0){outputs3="Q1";}
          if(b11==1){outputs3="Q2";}
          if(b11==2){outputs3="Q3";}
          if(b11==3){outputs3="Q4";}
         
          display.println(outputs3);
          display.display();
          b11++;
          if(b11>3){b11=0;}
        }
        delay(200);
    }
  }
  selectorCuror();
}
void selectorCuror(){
  if(CounterSelector == 0)
  {
    display.clearDisplay();
    display.setCursor(17,0);
    display.println("*");
    INT();
  }
  if(CounterSelector == 1)
  {
    display.clearDisplay();
    display.setCursor(17,8);
    display.println("*");
    INT();
  }
  if(CounterSelector == 2)
  {
    display.clearDisplay();
    display.setCursor(17,16);
    display.println("*");
    INT();
  }
  if(CounterSelector == 3)
  {
    display.clearDisplay();
    display.setCursor(17,24);
    display.println("*");
    INT();
  }
  display.display();
}
void check()
{
         op3[0]=digitalRead(6); op3[1]=digitalRead(7); op3[2]=digitalRead(8); op3[3]=digitalRead(9);
         op3[4]=!digitalRead(6);op3[5]=!digitalRead(7);op3[6]=!digitalRead(8);op3[7]=!digitalRead(9);

         op4[0]=digitalRead(13); op4[1]=digitalRead(12); op4[2]=digitalRead(11); op4[3]=digitalRead(10);
         op4[4]=!digitalRead(13);op4[5]=!digitalRead(12);op4[6]=!digitalRead(11);op4[7]=!digitalRead(10);
         
        if(opr1A=="OR"){ v0A =op3[b0-1] or op3[c0-1];} if(opr2A=="OR"){v0B=op3[b3-1] or op3[c3-1];}   if(opr3A=="OR"){v0C=op3[b6-1] or op3[c6-1];}    if(opr4A=="OR"){v0D=op3[b10-1] or op3[c10-1];}
       
        if(opr1A=="AN"){ v0A=op3[b0-1] and op3[c0-1];} if(opr2A=="AN"){v0B=op3[b3-1] and op3[c3-1];}  if(opr3A=="AN"){v0C=op3[b6-1] and op3[c6-1];}   if(opr4A=="AN"){v0D=op3[b10-1] and op3[c10-1];}
       
        if(opr1A=="N"){ v0A=!op3[b0-1];}  if(opr2A=="N"){ v0B=!op3[b3-1];}      if(opr3A=="N"){ v0C=!op3[b6-1];}    if(opr4A=="N"){ v0D=!op3[b10-1];}
       
        if(opr1A=="D"){ v0A=op3[b0-1];}   if(opr2A=="D"){ v0B=op3[b3-1];}       if(opr3A=="D"){ v0C=op3[b6-1];}     if(opr4A=="D"){ v0D=op3[b10-1];}
       
        if(opr1A=="Q1"){ v0A=op4[0];}     if(opr2A=="Q1"){v0B=op4[0];}          if(opr3A=="Q1"){v0C=op4[0];}        if(opr4A=="Q1"){v0D=op4[0];}
       
        if(opr1A=="Q2"){ v0A=op4[1];}     if(opr2A=="Q2"){v0B=op4[1];}          if(opr3A=="Q2"){v0C=op4[1];}        if(opr4A=="Q2"){v0D=op4[1];}
       
        if(opr1A=="Q3"){ v0A=op4[2];}     if(opr2A=="Q3"){v0B=op4[2];}          if(opr3A=="Q3"){v0C=op4[2];}        if(opr4A=="Q3"){v0D=op4[2];}
       
        if(opr1A=="Q4"){ v0A=op4[3];}     if(opr2A=="Q4"){v0B=op4[3];}          if(opr3A=="Q4"){v0C=op4[3];}        if(opr4A=="Q4"){v0D=op4[3];}
       
        //------------------Channel 3-----------------------
       
        //--------------------------------------------
        if(opr1C=="1)"){v1A = op3[c2-1];} if(opr2C=="1)"){v1B = op3[c5-1];}   if(opr3C=="1)"){v1C = op3[c8-1];}     if(opr4C=="1)"){v1D = op3[c11-1];}
       
        if(opr1C=="2)"){v1A = op3[c2-1];} if(opr2C=="2)"){v1B = op3[c5-1];}   if(opr3C=="2)"){v1C = op3[c8-1];}     if(opr4C=="2)"){v1D = op3[c11-1];}
       
        if(opr1C=="3)"){v1A = op3[c2-1];} if(opr2C=="3)"){v1B = op3[c5-1];}   if(opr3C=="3)"){v1C = op3[c8-1];}     if(opr4C=="3)"){v1D = op3[c11-1];}
       
        if(opr1C=="4)"){v1A = op3[c2-1];} if(opr2C=="4)"){v1B = op3[c5-1];}   if(opr3C=="4)"){v1C = op3[c8-1];}     if(opr4C=="4)"){v1D = op3[c11-1];}
       
        if(opr1C=="Q1"){v1A = op4[0];}    if(opr2C=="Q1"){v1B = op4[0];}      if(opr3C=="Q1"){v1C = op4[0];}        if(opr4C=="Q1"){v1D = op4[0];}
       
        if(opr1C=="Q2"){v1A = op4[1];}    if(opr2C=="Q2"){v1B = op4[1];}      if(opr3C=="Q2"){v1C = op4[1];}        if(opr4C=="Q2"){v1D = op4[1];}
       
        if(opr1C=="Q3"){v1A = op4[2];}    if(opr2C=="Q3"){v1B = op4[2];}      if(opr3C=="Q3"){v1C = op4[2];}        if(opr4C=="Q3"){v1D = op4[2];}
       
        if(opr1C=="Q4"){v1A = op4[3];}    if(opr2C=="Q4"){v1B = op4[3];}      if(opr3C=="Q4"){v1C = op4[3];}        if(opr4C=="Q4"){v1D = op4[3];}
       
        if(opr1C=="T"){v1A = true;}       if(opr2C=="T"){v1B = true;}         if(opr3C=="T"){v1C = true;}           if(opr4C=="T"){v1D = true;}
       
        if(opr1C=="F"){v1A = false;}      if(opr2C=="F"){v1B = false;}        if(opr3C=="F"){v1C = false;}          if(opr4C=="F"){v1D = false;}
        //-------------------Midel----------------------  ---------------------------------------------------------------------------------------------
        if(opr1B=="&"){ Qb1 = v0A and v1A;}  if(opr2B=="&"){ Qb2 = v0B and v1B;}    if(opr3B=="&"){ Qb3 = v0C and v1C;}   if(opr4B=="&"){ Qb4 = v0D and v1D;}
       
        if(opr1B=="|"){ Qb1 = v0A or v1A;}   if(opr2B=="|"){ Qb2 = v0B or v1B;}     if(opr3B=="|"){ Qb3 = v0C or v1C;}    if(opr4B=="|"){ Qb4 = v0D or v1D;}
       
        if(opr1B=="!"){ Qb1 = !v0A and v1A;} if(opr2B=="!"){ Qb2 = !v0B and v1B;}   if(opr3B=="!"){ Qb3 = !v0C and v1C;}  if(opr4B=="!"){ Qb4 = !v0D and v1D;}
       
        if(opr1B==">"){ Qb1 = v0A and !v1A;} if(opr2B==">"){ Qb2 = v0B and !v1B;}   if(opr3B==">"){ Qb3 = v0C and !v1C;}  if(opr4B==">"){ Qb4 = v0D and !v1D;}     
}
