//fonte: https://leetcode.com/problems/longest-substring-without-repeating-characters/
//Autor: Bruno Harlis


/*****************************************************************************************
* PROBLEMA PROPOSTO
* Dada uma string s, encontre o comprimento da substring mais longa sem repetir os caracteres.
*
* EXEMPLO
* Entrada: s = "abcabcbb"
* Sa�da: 3
* Explica��o: A resposta � "abc", com o comprimento de 3.
*
* SOLU��O
* Criamos um vector com tamanho 128 (porque � a quantidade de caracteres que existem e s�o representados por decimais
* de 0 a 127. Ex: 'a' = 97) para armazenar a contagem de repeti��o de cada letra.
* Criamos duas variaveis (direita, esquera) para andar pela string e respresentar o intervalo em que as letras n�o se repetem.
* Vari�vel "soma" ser� para guardar o maior comprimento da substring (ser� nossa resposta ao problema).
* Em seguida temos dois whiles, um para andar � direita pela string e outro quando houver ocorr�ncia de letra repetida.
* Agora pegamos o primeiro caractere da string e colocamos ele em nosso vector para armazenar que ele aparece uma vez (ex: 'a'
* tem valor 97, ent�o no �ndice 97 adicionamos 1. O pr�ximo 'a' adicionar� + 1 ao mesmo �ndice).
* O segundo while aciona quando houver alguma repeti��o, ent�o movemos o ponto da esquerda at� encontrar onde o caractere se 
* repete e removemos ele do nosso vector.
* No final a cada caractere que n�o se repete no range, adicionamos ele a nossa vari�vel soma.
*
* TESTE DE EFICI�NCIA
* Tempo de Execu��o: 4 ms
* Mem�ria Usada: 7.6 MB
*****************************************************************************************/

#include <iostream>
#include <vector> //std::vector 
#include <string> //std::string
#include <algorithm> //std::max


class Solution 
{
public:
    int lengthOfLongestSubstring(std::string& s)
    {
        std::vector<int> letras(128);

        int direita{ 0 };
        int esquerda{ 0 };
        int soma{ 0 };

        while (direita < s.size())
        {
            char d{ s[direita] };
            ++letras[d];

            while (letras[d] > 1)
            {
                char e{ s[esquerda] };
                --letras[e];
                ++esquerda;
            }

            soma = std::max(soma, direita - esquerda + 1);

            ++direita;
        }

        return soma;
    }

};

int main()
{
    Solution x;
    std::string s{ "abcdefgf" };
    std::cout << x.lengthOfLongestSubstring(s);
}