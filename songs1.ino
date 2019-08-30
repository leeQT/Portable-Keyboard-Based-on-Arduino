//第一首歌的代码   
void Song1()    
{   
    lcd.clear();//显示屏清空   
    //旋律对应数组   
    int melody[] =    
    {   
        NOTE_E7, NOTE_E7, 0, NOTE_E7,   
        0, NOTE_C7, NOTE_E7, 0,   
        NOTE_G7, 0, 0,  0,   
        NOTE_G6, 0, 0, 0,   
        
        NOTE_C7, 0, 0, NOTE_G6,   
        0, 0, NOTE_E6, 0,   
        0, NOTE_A6, 0, NOTE_B6,   
        0, NOTE_AS6, NOTE_A6, 0,   
        
        NOTE_G6, NOTE_E7, NOTE_G7,   
        NOTE_A7, 0, NOTE_F7, NOTE_G7,   
        0, NOTE_E7, 0, NOTE_C7,   
        NOTE_D7, NOTE_B6, 0, 0,   
        
        NOTE_C7, 0, 0, NOTE_G6,  
        0, 0, NOTE_E6, 0,   
        0, NOTE_A6, 0, NOTE_B6,   
        0, NOTE_AS6, NOTE_A6, 0,   
        
        NOTE_G6, NOTE_E7, NOTE_G7,   
        NOTE_A7, 0, NOTE_F7, NOTE_G7,   
        0, NOTE_E7, 0, NOTE_C7,   
        NOTE_D7, NOTE_B6, 0, 0
    }; 

    //节拍   
    int noteDurations[] =    
    {   
        12, 12, 12, 12,   
        12, 12, 12, 12,   
        12, 12, 12, 12,   
        12, 12, 12, 12, 

        12, 12, 12, 12,   
        12, 12, 12, 12,   
        12, 12, 12, 12,   
        12, 12, 12, 12, 

        9, 9, 9,   
        12, 12, 12, 12,   
        12, 12, 12, 12,   
        12, 12, 12, 12, 

        12, 12, 12, 12,   
        12, 12, 12, 12,   
        12, 12, 12, 12,   
        12, 12, 12, 12, 

        9, 9, 9,   
        12, 12, 12, 12,   
        12, 12, 12, 12,   
        12, 12, 12, 12, 
    };

    lcd.setCursor(1, 0);   
    lcd.print("Now playing...");   
    lcd.setCursor(0, 1);   
    lcd.print("MARIO THEME SONG");   
    
    int size = sizeof(melody) / sizeof(int);  
    for (int thisNote = 0; thisNote < size; thisNote++)    
    {   
        //要计算音符持续时间，取 1 秒除以音符类型，例如四分音符 = 1000 / 4。 
        int noteDuration = 1000 / noteDurations[thisNote];   
        
        tone(8, melody[thisNote], noteDuration); 
        
        //设置一个最小时间间隔以区分每一个音   
        int pauseBetweenNotes = noteDuration * 1.30;   
        delay(pauseBetweenNotes);   
        tone(8, 0, noteDuration);   
    }  
    Song1title(); 
}