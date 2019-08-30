// LCD Screen Switch  LED Setup
#include <LiquidCrystal.h>
#include "pitches.h"
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int LCDswitchPin = 7; //定义菜单/LCD 引脚
int LCDswitchState = 0; //关闭菜单/LCD 开关 
int blueLED = 6; 
int LCDswitchCounter = 0; //记录菜单按下次数，便于以后扩展 
//音乐按键-设置音调   
//设置音调 C, D, E, F, G, A, B  
int notes[] = { 262, 294, 330, 349, 392, 440, 494 };    

//////////////////////////////////////////////  
void setup()    
{   
    Serial.begin(9600);
    lcd.begin(16, 2);
    pinMode(LCDswitchPin, INPUT);
    pinMode(blueLED, OUTPUT);
    digitalWrite(blueLED, LOW); //当开始弹奏时，关闭 LED 灯   
}   

////////////////////////////////////////////// 

void loop() 
{   
    LCDswitchState = digitalRead(LCDswitchPin);  
    int keyVal = analogRead(A0);   
    Serial.println(keyVal);   
    lcd.noDisplay();   
    digitalWrite(blueLED, LOW); //每次主循环启动时，关闭 LED 灯   
    //当按下菜单按钮时点亮 LCD 屏   
    if (LCDswitchState == HIGH)   
    {   
        //打开 LED 显示钢琴模式被禁用，设备处于菜单模式
        digitalWrite(blueLED, HIGH);    
        lcd.display();   
        lcd.clear();   
        LCDstart();  
    }   
    else   
    {  
        lcd.display();   
        lcd.setCursor(0, 0);   
        lcd.print("PLAY BY YOURSELF");   
    }   
    
    // ********************************************************************  
    //按键记录   
    //用梯度电阻改变琴键上的电压   
    if (keyVal > 995)    
    {  
        tone(8, notes[0]); // C   
    }    
    else if (keyVal >= 970 & keyVal <= 995)    
    {  
        tone(8, notes[1]); // D  
    }   
    else if (keyVal >= 930 && keyVal < 970)   
    {   
        tone(8, notes[2]); // E  
    }   
    else if (keyVal >= 850 && keyVal < 930)    
    {   
        tone(8, notes[3]); // F   
    }
    else if (keyVal >= 650 && keyVal <= 710)
    {   
        tone(8, notes[4]);
    } 
    else if (keyVal >= 480 && keyVal <= 550)
    {   
        tone(8, notes[5]); // A
    }  
    else if (keyVal >= 330 && keyVal <= 360)
    {   
        tone(8, notes[6]); // B   
    }   
    else if (keyVal <= 100) //没有按任何键   
    {   
        noTone(8);   
    }   9
} 

///////////////////////////////////////////////////// 
void LCDstart()
{   
    int keyVal = analogRead(A0);   
    LCDswitchState = digitalRead(LCDswitchPin);//判断菜单按钮情况   
    while (LCDswitchState == LOW)//没有按下菜单按钮就继续循环   
    {   
        //每次开始循环的时候检查菜单按钮的情况   
        LCDswitchState = digitalRead(LCDswitchPin);
        //开始第一首歌曲 title 循环 
        if (LCDswitchState == HIGH)//如果菜单按钮被按下
        {    
            LCDswitchCounter++; //状态设置为第一首歌的状态   
            Serial.print("number of button pushes:  "); 
            Serial.println(LCDswitchCounter);  
            delay(300);   
            Song1title();   
            lcd.clear();   
            break;  
        }  
        //否则显示菜单
        else//如果菜单按钮没有被按下  
        {  
            LCDswitchCounter = 0; //状态设置为 0   
            lcd.clear();   
            lcd.setCursor(0, 0);   
            lcd.print("WHICH SONG WOULD");  
            lcd.setCursor(0, 1);
            lcd.print("YOU LIKE TO PLAY");   
            delay(50);
        }   
    }  
}   

// ************* 第一首歌的循环 ************** 
void Song1title()    
{   
    int keyVal = analogRead(A0);   
    LCDswitchState = digitalRead(LCDswitchPin); //再次检查菜单按钮 
    while (LCDswitchState == LOW) //没有按下菜单按钮就继续循环   
    {   
        LCDswitchState = digitalRead(LCDswitchPin); //再次检查菜单按钮   
        if (LCDswitchState == HIGH)//如果菜单按钮被按下
        {   
            LCDswitchCounter++; //设置状态为第二首歌的状态   
            Serial.print("number of button pushes:  ");  
            Serial.println(LCDswitchCounter);   
            delay(300);   
            Song2title();   
            lcd.clear();   
            break;   
        }   
        else //如果菜单按钮没有被按下   
        {   
            int keyVal = analogRead(A0);   
            Serial.println(keyVal);   
            if (keyVal >= 200)   
            {   
                digitalWrite(blueLED, LOW);   
                Song1();   
                break;   
            }   
            lcd.clear();   
            lcd.setCursor(0, 0);   
            lcd.print("SUPER MARIO BROS");   
            lcd.setCursor(0, 1);
            lcd.print("   THEME SONG");   
            delay(50);   
        }   
    }   
}

// ************* 第二首歌的循环 ************** 
void Song2title()    
{   
    int keyVal = analogRead(A0);   
    LCDswitchState = digitalRead(LCDswitchPin); //再次检查菜单按钮 
    while (LCDswitchState == LOW) //没有按下菜单按钮就继续循环   
    {   
        LCDswitchState = digitalRead(LCDswitchPin); //再次检查菜单按钮   
        if (LCDswitchState == HIGH)//如果菜单按钮被按下
        {   
            LCDswitchCounter = 0; //恢复为 0 状态，即弹奏状态   
            Serial.print("number of button pushes:  ");  
            Serial.println(LCDswitchCounter);   
            delay(300);   
            Song2title();   
            lcd.clear();   
            break;   
        }   
        else //如果菜单按钮没有被按下   
        {   
            int keyVal = analogRead(A0);   
            Serial.println(keyVal);   
            if (keyVal >= 200)   
            {   
                digitalWrite(blueLED, LOW);   
                Song2();   
                break;   
            }   
            lcd.clear();   
            lcd.setCursor(0, 0);   
            lcd.print("SUPER MARIO BROS");   
            lcd.setCursor(0, 1);
            lcd.print("   UNDERWORLD");   
            delay(50);   
        }   
    }   
}