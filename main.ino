int main(){
  DDRB &= 0b11110011; // entrada (PB2 e PB3)
  DDRD |= 0b11110000; // saída (PD4, PD5,PD6,PD7)

  PORTB |= 0b00001100; // pull up (PB2 e PB3)
  PORTD &=0b00001111; // Saída em nível baixo (PD4 até PD7)
  
  while(true){
    // configuração do ADC
    ADMUX |= 0b01000000;// 01 ref(Vcc) ; 0 (ADC - SEM ADLAR) ; 0 (RESERVADO) ; 0000 (ADC0) 
    ADCSRA
    if(){
      
    }else{
      
    }
    
  }
}

