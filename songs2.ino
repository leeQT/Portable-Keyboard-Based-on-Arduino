//第一首歌的代码   
void Song2()    
{   
    lcd.clear();//显示屏清空   
    //旋律对应数组   
    int melody[] =    
    {   
        NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
        NOTE_AS3, NOTE_AS4, 0,  
        0,   
        NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,   
        NOTE_AS3, NOTE_AS4, 0,   
        0,   
        NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,   
        NOTE_DS3, NOTE_DS4, 0,  
        0,   
        NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,   
        NOTE_DS3, NOTE_DS4, 0,   
        0, NOTE_DS4, NOTE_CS4, NOTE_D4,   
        NOTE_CS4, NOTE_DS4,   
        NOTE_DS4, NOTE_GS3,   
        NOTE_G3, NOTE_CS4,   
        NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,   
        NOTE_GS4, NOTE_DS4, NOTE_B3,   
        NOTE_AS3, NOTE_A3, NOTE_GS3,   
        0, 0, 0
    }; 

    //节拍   
    int noteDurations[] =    
    {   
        12, 12, 12, 12,   
        12, 12, 6,   
        3,   
        12, 12, 12, 12,   
        12, 12, 6,   
        3,  
        12, 12, 12, 12,   
        12, 12, 6,   
        3,  
        12, 12, 12, 12,   
        12, 12, 6,   
        6, 18, 18, 18,
        6, 6, 
        6, 6,
        6, 6,
        18, 18, 18, 18, 18, 18,
        10, 10, 10,   
        3, 3, 3  
    };

    lcd.setCursor(1, 0);   
    lcd.print("Now playing...");   
    lcd.setCursor(0, 1);   
    lcd.print("MARIO UNDERWORLD");   
    
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