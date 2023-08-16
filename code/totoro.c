/*
Набор для обчения пайки Totoro
Иркутск, июль 2023
ra0sms@bk.ru
Внутренний генератор 8 МГц

  */


void PIC_Init(){
GPIO = 0;
INTCON = 0;
T1CON = 0;
CMCON0 = 255;          //turn off comp
VRCON = 0;
ADCON0 = 0;
ANSEL = 0;
PCON = 0;
TRISIO = 0b00001100;          //GPIO2 - input
OPTION_REG = 0b10000000;      //interrupt - low level GPIO2
GIE_bit = 1;
INTE_bit=1;
PIE1=0;
INTF_bit=0;
}

void Tone1() {
  Sound_Play(659, 250);
}

void Tone2() {
  Sound_Play(698, 250);
}

void Tone3() {
  Sound_Play(784, 250);
}

void Melody() {
  Tone1(); Tone2(); Tone3(); Tone3();
  Tone1(); Tone2(); Tone3(); Tone3();
  Tone1(); Tone2(); Tone3();
  Tone1(); Tone2(); Tone3(); Tone3();
  Tone1(); Tone2(); Tone3();
  Tone3(); Tone3(); Tone2(); Tone2(); Tone1();
}

void F_note(){
     Sound_Play(1397, 125);
}

void G_note(){
     Sound_Play(1568, 125);
}

void A_note(){
     Sound_Play(1760, 125);
}

void A_dies(){
     Sound_Play(1864, 125);
}

void A_note_long(){
     Sound_Play(1760, 250);
}

void A_dies_long(){
     Sound_Play(1864, 250);
}

void C_up(){
     Sound_Play(2093, 125);
}

void E_note(){
     Sound_Play(1318, 125);
}

void D_up(){
     Sound_Play(2349, 125);
}

void C_up_long(){
     Sound_Play(2093, 250);
}

void F_note_long(){
     Sound_Play(1397, 250);
}

void D_note(){
     Sound_Play(1244, 125);
}

void E_up(){
     Sound_Play(2637, 125);
}

void C_up_up(){
     Sound_Play(4186, 125);
}

void F_up(){
     Sound_Play(2794, 125);
}

void G_up(){
     Sound_Play(3136, 125);
}

void C_note(){
     Sound_Play(1046, 125);
}

void Totoro (){
     GPIO.B0=1;
     GPIO.B4=1;
     GPIO.B5=1;
     F_note(); G_note(); A_note(); A_dies(); C_up(); Delay_ms(50);
     GPIO.B0=0;
     GPIO.B4=0;
     GPIO.B5=0;
     A_note(); F_note(); Delay_ms(25); C_up(); Delay_ms(25); A_dies_long(); Delay_ms(25); G_note();
     GPIO.B0=1;
     GPIO.B4=1;
     GPIO.B5=1;
     Delay_ms(500);
     GPIO.B0=0;
     GPIO.B4=0;
     GPIO.B5=0;
     A_dies(); Delay_ms(25); G_note(); E_note(); Delay_ms(25); A_dies(); Delay_ms(25); A_note_long(); F_note();
     GPIO.B0=1;
     GPIO.B4=1;
     GPIO.B5=1;
     Delay_ms(500);
     GPIO.B0=0;
     GPIO.B4=0;
     GPIO.B5=0;
     D_note(); D_up(); C_up(); A_dies(); A_note(); A_dies(); C_up_long(); F_note(); F_note_long();
     GPIO.B0=1;
     GPIO.B4=1;
     GPIO.B5=1;
     A_note(); A_dies(); A_note(); F_note(); A_dies(); A_note(); F_note(); D_up(); C_up_long(); C_up_long(); C_up_long();
     GPIO.B0=0;
     GPIO.B4=0;
     GPIO.B5=0;
     C_up(); D_up(); E_up(); G_up(); C_up_up(); Delay_ms(50);
     GPIO.B0=1;
     GPIO.B4=1;
     GPIO.B5=1;
     C_note(); C_note(); A_dies(); A_note(); G_note(); A_note(); F_note_long(); F_note_long(); F_note_long();
     
}


void interrupt(){
 if (INTF_bit==1)
 {
   INTF_bit=0;
 }
}

void main() {
     PIC_Init();
     Sound_Init (&GPIO,1);
     Sound_Play(1864, 500);

     do {
     asm sleep;
     Totoro();
     GPIO.B0=0;
     GPIO.B4=0;
     GPIO.B5=0;
     Delay_ms(200);
     GPIO.B0=1;
     GPIO.B4=1;
     GPIO.B5=1;
     Delay_ms(200);
     GPIO.B0=0;
     GPIO.B4=0;
     GPIO.B5=0;
     Delay_ms(200);
     GPIO.B0=1;
     GPIO.B4=1;
     GPIO.B5=1;
     Delay_ms(200);
     GPIO.B0=0;
     GPIO.B4=0;
     GPIO.B5=0;
     Delay_ms(200);
     }while(1);

}