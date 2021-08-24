//Fonte: https://leetcode.com/problems/implement-strstr/
//Autor: Bruno Harlis
//Data: 22/06/2020

/*****************************************************************************************
* PROBLEMA:
* Implemente strStr().
* Retorna o índice da primeira ocorrência de agulha em palheiro, ou -1 se needle não fizer
* parte de haystack.
* 
* Esclarecimento:
* O que devemos retornar quando needleé uma string vazia? Esta é uma ótima pergunta para se
* fazer durante uma entrevista.
* Para o propósito deste problema, retornaremos 0 quando needlefor uma string vazia. Isso é
* consistente com strstr () do C  e indexOf () do Java  .
* 
* Exemplo 1:
* Entrada: haystack = "olá", agulha = "ll"
*  Resultado: 2
* 
* Exemplo 2:
* Entrada: haystack = "aaaaa", agulha = "bba"
* Resultado: -1
* 
* Tempo de execução: 4 ms
* Uso de memória: 6,8 MB
*****************************************************************************************/

#include <iostream>
#include <string>

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        return haystack.find(needle);
    }
};