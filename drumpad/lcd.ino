
void clearLCD(){
   Serial1.write(0xFE);   //command flag
   Serial1.write(0x01);   //clear command.
   delay(10);
}

void positionReset(){  //puts the cursor at line 0 char 0.
   Serial1.write(0xFE);   //command flag
   Serial1.write(128);    //position
   delay(2);
}

void selectLineTwo(){  //puts the cursor at line 0 char 0.
   Serial1.write(0xFE);   //command flag
   Serial1.write(192);    //position
   delay(2);
}
