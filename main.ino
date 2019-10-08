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
void set_ADC(void)
{
  // Registrador de Seleção
  ADMUX |= 0b01000000; // 01 ref(Vcc); 0 (ADC - SEM ADLAR); 0 (RESERVADO); 0000 (MUX p/ ADC0)
  // Registrador de Status
  ADCSRA |= 0b10000111; // 1 (ADEN: Enable); 00 (ADSC: nenhum efeito e ADATE: sem auto trigger); 00 (ADIF: Flag de interrupção e ADIE: Interrupt Enable); 111 (Prescaler)
  // Habilita uso de interrupção
  sei();
}

int main()
{
  uint8_t ad_value;

  DDRB &= 0b11110011; // entrada (PB2 e PB3)
  DDRD |= 0b11110000; // saída (PD4,PD5,PD6,PD7)

  PORTB |= 0b00001100; // pull up (PB2 e PB3)
  PORTD &= 0b00001111; // Saída em nível baixo (PD4 até PD7)

  while (true)
  {
    set_ADC();
    while (!(ADCSRA & 0b00010000))
      ;
    ad_value = ADC;

    if ()
    {
    }
    else
    {
    }
  }
}
