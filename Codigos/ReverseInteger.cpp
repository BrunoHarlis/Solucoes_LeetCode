//fonte: https://leetcode.com/problems/reverse-integer/
//Autor: Bruno Harlis


/*****************************************************************************************
* PROBLEMA PROPOSTO
* Dado um número inteiro x de 32 bits com sinal, retorna x com seus dígitos invertidos.
* Se a reversão de x fizer com que o valor saia do intervalo de inteiros de 32 bits com sinal [-231, 231 - 1],
* retorne 0.
*
* Exemplo 1:
* Entrada: x = 123
* Saída: 321
*
* Exemplo 2:
* Entrada: x = -123
* Saída: -321
*
* SOLUÇÃO
*
*
* TESTE DE EFICIÊNCIA
* Tempo de Execução: 0 ms
* Memória Usada: 5.7 MB
*****************************************************************************************/
#include <iostream>

class Solution
{
public:
    int reverse(int x)
    {
        int invertido{ 0 };
        int numero{ 0 };

        while (x != 0)
        {
            numero = x % 10;   //Pega o ultimo numero.
            x -= x % 10;       //subtrai o ultimo numero do numero original.
            x = x / 10;        //retira a ultima casa decimal do numero original.

            //Caso o numero va estourar, retorna 0
            if (invertido > INT_MAX / 10 || (invertido == INT_MAX / 10 && numero > 7)) return 0;
            if (invertido < INT_MIN / 10 || (invertido == INT_MIN / 10 && numero < -8)) return 0;

            invertido = invertido * 10 + numero; //Adicionamos o ultimo digito com as casas decimais .   
        }

        return invertido;
    }
};

int main()
{
    int x{ -321 };

    Solution s;
    std::cout << s.reverse(x);
}