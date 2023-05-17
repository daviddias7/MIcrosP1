int TIMERH;
int TIMERL;

void Interrupt_High() iv 0x0008 ics ICS_AUTO {

}


void main() {

     INTCON2.RBPU = 0; // PULL UP
     WPUB = 0XFF; // PULL UP PORTA B
     
     // CONFIGS TIMER E INTERRUPCOES
     INTCON.GIEH = 1;
     INTCON.GIEL = 1;
     RCON.IPEN = 1;

     INTCON.TMR0IF = 0;  //flag de interrupção

     INTCON2.TMR0IP = 1;
     INTCON.TMR0IE = 1;

     T0CON.TMR0ON = 1;
     
     
     ANSELB = 0; // DEFININDO PORTA B COMO DIGITAL
     TRISB = 0B00001111; // RB7 A RB4 COMO SAIDA (0) E RB3 A RB0 COMO ENTRADA (1)
     

     ANSELA = 0;
     TRISA = 0X00;
     

     while(1) {
                 latb = 0b11100000;

                 if(PORTB.RB0 == 0){
                        // 65295
                        TMR0L = 0X73;
                        TMR0H = 0XFF;
                 } 
                 if(PORTB.RB1 == 0){
                              //65323
                        PORTA.F1 = 1;
                 } 
                 if(PORTB.RB2 == 0){
                              //65346
                        PORTA.F2 = 1;
                 }
                 
                 latb = 0b11010000;
                 if(PORTB.RB0 == 0){
                              //65357
                        PORTA.F3 = 1;
                 } 
                 if(PORTB.RB1 == 0){
                              //65376
                        PORTA.F4 = 1;
                 } 
                 if(PORTB.RB2 == 0){
                              //65394
                        PORTA.F5 = 1;
                 }
                 
                 latb = 0b10110000;
                 if(PORTB.RB0 == 0){
                              //65409
                        PORTA.F6 = 1;
                 } 
                 if(PORTB.RB1 == 0){
                                //65415
                        PORTA.F7 = 1;
                 }
     }
}
