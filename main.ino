/*
Entradas e Saídas                     Pinagem (Arduino)

ADC0 - Ignição                        Pino A0
ADC1 - Sensor de Velocidade           Pino A1
ADC2 - Sensor de Combustível          Pino A2
PB2 - Pisca da direita                Pino 10 (PWM)
PB3 - Pisca da esquerda               Pino 11 (PWM)
PD4 - Ligar Pisca Direito             Pino 4
PD5 - Ligar Pisca Esquerdo            Pino 5 (PWM)
PD6 - Injeção Eletrônica              Pino 6 (PWM)
PD7 - Ligar Faróis                    Pino 7

*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

// configuração do ADC
void set_ADC(int mux)
{
  // Registrador de Seleção
  ADMUX &= 11110000;
  switch(mux):
    case 0:
      ADMUX |= 0b01000000; // 01 ref(Vcc); 0 (ADC - SEM ADLAR); 0 (RESERVADO); 0000 (MUX p/ ADC0)
      break;
    case 1:
      ADMUX |= 0b01000001; // 01 ref(Vcc); 0 (ADC - SEM ADLAR); 0 (RESERVADO); 0000 (MUX p/ ADC1)
      break;
    case 2:
      ADMUX |= 0b01000010; // 01 ref(Vcc); 0 (ADC - SEM ADLAR); 0 (RESERVADO); 0000 (MUX p/ ADC2)
      break;
  
  // Registrador de Status
  ADCSRA |= 0b11000111; // 1 (ADEN: Enable); 10 (ADSC: Start Conversion e ADATE: sem auto trigger); 00 (ADIF: Flag de interrupção e ADIE: Interrupt Enable); 111 (Prescaler - Divisão por 128)
  // Habilita uso de interrupção
  sei();
}

int ignition()
{
  
}

void started()
{
  // contar 1 segundo
  // ligar led que indica carro ligado
  while(1)
  {
    
  }
}

void lightsOn()
{
  while(1)
  {
    
  }
}

void stoped()
{
  while(1)
  {
    
  }
}

int main()
{
  Serial.begin(9600);
  uint8_t ad_value;

  DDRB &= 0b11110011; // entrada (PB2 e PB3)
  DDRD |= 0b11110000; // saída (PD4,PD5,PD6,PD7)

  PORTB |= 0b00001100; // pull up (PB2 e PB3)
  PORTD &= 0b00001111; // Saída em nível baixo (PD4 até PD7)

  while (true)
  {
    int state = ignition();
    
    switch(state):
    case 0:
      started();
      break;
    case 1:
      lightsOn();
      break;
    case 2:
      stoped();
      break;
      
    while (!(ADCSRA & 0b00010000)) // aguarda conversao
      ;
    
    ad_value = ADC;
    Serial.println(ad_value);
  }
}
