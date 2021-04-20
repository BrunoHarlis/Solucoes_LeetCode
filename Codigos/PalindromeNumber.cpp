//fonte: https://leetcode.com/problems/palindrome-number/
//Autor: Bruno Harlis

/*****************************************************************************************
* PROBLEMA PROPOSTO
* Implemente a fun��o myAtoi(string s) que converte uma string em um inteiro assinado de 32 bits 
* (semelhante � fun��o C / C ++ atoi).
*
* Exemplo 1:
* Entrada: x = 121
* Sa�da: true
* 
* Exemplo 2:
* Entrada: x = -121
* Sa�da: false
* 
* Exemplo 3:
* Entrada: x = 10
* Sa�da: false
* 
* Exemplo 4:
* Entrada: x = -101
* Sa�da: false
* 
* Restricoes:
* Inteiro n�o pode estourar.
* 
* TESTE DE EFICI�NCIA
* Tempo de Execu��o: 12 ms
* Mem�ria Usada: 5.7 MB
*****************************************************************************************/
#include <iostream>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) { return false; } //Se o x for negativo, nao eh palindromo

        int temp{ x };
        int palin{ 0 };

        while (temp != 0) //Vamos inverter o numero.
        {
            int mod = temp % 10;
            temp /= 10;
            if (palin > INT_MAX / 10 || (palin == INT_MAX / 10 && mod > 7)) return false;
            if (palin < INT_MIN / 10 || (palin == INT_MIN / 10 && mod < -8)) return false;
            palin = palin * 10 + mod;
        }

        //Compara se o numero invertido eh igual ao x
        return (palin == x) ? true : false;
    }
};

int main()
{
    int x{ 21232 };

    Solution s;
    std::cout << s.isPalindrome( x );
}