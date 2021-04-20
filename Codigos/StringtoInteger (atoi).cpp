//fonte: https://leetcode.com/problems/string-to-integer-atoi/
//Autor: Bruno Harlis


/*****************************************************************************************
* PROBLEMA PROPOSTO
* Implemente a função myAtoi(string s) que converte uma string em um inteiro assinado de 32 bits 
* (semelhante à função C / C ++ atoi).
*
* Exemplo 1:
* Entrada: s = "42"
* Saída: 42
* 
* Exemplo 2:
* Entrada: s = "  -42"
* Saída: 42
* 
* Exemplo 3:
* Entrada: s = "4193 com palavras" 
* Saída: 4193
* 
* Exemplo 4:
* Entrada: s = "palavras e 987" 
* Saída: 987
* 
* Exemplo 5:
* Entrada: s = "-91283472332" 
* Saída: -2147483648
* 
* TESTE DE EFICIÊNCIA
* Tempo de Execução: 4 ms
* Memória Usada: 8 MB
*****************************************************************************************/

#include <iostream>
#include <string>
#include <map>

class Solution 
{
public:
    int myAtoi(const std::string& s) 
    {
        std::map<char, int> num; //Lista de numeros aceitos
        num['0'] = 0;
        num['1'] = 1;
        num['2'] = 2;
        num['3'] = 3;
        num['4'] = 4;
        num['5'] = 5;
        num['6'] = 6;
        num['7'] = 7;
        num['8'] = 8;
        num['9'] = 9;

        int i{ 0 }; //Variavel para percorrer a string
        while (s[i] == ' ')  { ++i; } //Elimina todos os epacos em branco
        
        //Verifica se o numero eh positivo ou negativo
        bool numNegativo{ };
        if (s[i] == '-' )
        {
            ++i;
            numNegativo = true;
        }
        else if (s[i] == '+')
        {
            ++i;
            numNegativo = false;
        }
        
        //Caso haja zeros na frente do numero, retiramos eles tambem
        while (s[i] == '0') { ++i; }
        
        int resposta{ 0 };
        for (i; i < s.size(); ++i) //Aqui um laco para percorrer toda a string
        {            
            if(num.find(s[i]) != num.end()) //Verifica se o caracter esta na lista de numeros
            {
                if (numNegativo) //Ver se o numero (+/-) vai estourar. Caso sim, retorna o numero de estouro.
                {
                    if (resposta * -1 < INT_MIN / 10 || (resposta * -1 == INT_MIN / 10 && num[s[i]] >= 8)) return INT_MIN;
                }
                else
                {
                    if (resposta > INT_MAX / 10 || (resposta == INT_MAX / 10 && num[s[i]] > 7)) return INT_MAX;
                }

                resposta = resposta * 10 + num[s[i]]; 
            }
            else //Nao percorremos toda a string, mas o caracter nao existe na lista, entao retornamos o resultado.
            {
                if (numNegativo) { resposta *= -1; }
                return resposta;
            }
        }

        //Percorremos toda a string e retornamos o resultado.
        if (numNegativo) { resposta *= -1; }
        return resposta;
    }
};
int main()
{
    std::string x{ "-2147483648" };

    Solution s;
    std::cout << s.myAtoi( x );
}