int numeros_7seg[] = {0b00111111, 0b00000110, 0b11011011, 0b01001111, 0b01100110, 0b01101101, 0b11111101, 0b00000111, 0b11111111, 0b01100111};
bit flag_freq;
int num_atual = 0;

//formula_timer = (2^n - TMR0)(0,5*10^-6*PRES_SCALER)
	
void Interrupt_High() iv 0x0008 ics ICS_AUTO {
     if(flag_freq == 0) {
		TMR0L = 0xEE;
		TMR0H = 0x85; // 34286
		T0CON = 0b10000101;
	} else {
		TMR0L = 0x7B;
		TMR0H =	0xE1; // 57723
		T0CON = 0b10000101;
	}
	num_atual = (num_atual + 1) %10;
        INTCON.TMR0IF = 0;
}

void main() {
     INTCON.GIEH = 1;
     INTCON.GIEL = 1;
     RCON.IPEN = 1;

     INTCON.TMR0IF = 0;  //flag de interrupção

     INTCON2.TMR0IP = 1;
     INTCON.TMR0IE = 1;

     T0CON.TMR0ON = 1;

     ansela = 0;
     trisa = 0b11111110;
     
     anselb = 0;
     trisb = 0b11111111;
     anseld = 0;
     PORTD = 0x00; //Set Port D as output
     TRISD = 0x00; //define PORTD as a output pin
    
    TMR0L = 0xEE;
    TMR0H = 0x85; // 34286
    T0CON = 0b10000101;
    


     while(1) {
     //inicio do timer
             if(portb.rb1 == 0) {
                          flag_freq = 0;

			  // acertar tempo certo t = (65536 - TMR0) * (1 / 8e6) * 256
                          TMR0L = 0xEE;
                          TMR0H = 0x85; // 34286
  	                  T0CON = 0b10000101;
  	                  
  	                  
  	                  
             }
             if (portb.rb0 == 0) {
               flag_freq = 1;

               TMR0L = 0x7B;
               TMR0H = 0xE1; // 57723
               T0CON = 0b10000101;
               }
               
               latd = numeros_7seg[num_atual];


	}
 }


