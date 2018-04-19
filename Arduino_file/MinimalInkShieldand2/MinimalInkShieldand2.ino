//Impressao Robotizada

#include <InkShield.h> //biblioteca instalada

InkShieldA2A5 MyInkShield(2); //configuracao dos pinos a2a3a5a5
                              //sinal de saída para o cartucho no 2
                              
const int controle = 8; //entrada do sinal I/O

void setup()
{
    pinMode(controle, INPUT); //tipo de entrada
}

void loop()
{
    boolean val = digitalRead(controle); //le posicao do I/O
   if(val == LOW)
{
    MyInkShield.spray_ink(0b0000000000000011); //bin
   //MyInkShield.spray_ink(0x0FFF); //usar todos os jatos
   delay(10); //FAZER TESTE PARA DEFINIR
}

//fim do loop

}
