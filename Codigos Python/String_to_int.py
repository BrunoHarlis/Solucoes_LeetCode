# Fonte: https://leetcode.com/problems/string-to-integer-atoi/
# Autor: Bruno Harlis
# Data: 03/08/2021

"""
Implemente a função myAtoi(string s), que converte uma string em um
inteiro assinado de 32 bits (semelhante à função C / C ++ atoi).

O algoritmo para myAtoi(string s) é o seguinte:

Leia e ignore qualquer espaço em branco à esquerda.

Verifique se o próximo caractere (se ainda não estiver no final da string) 
é '-' ou '+'. Leia este caractere se for algum. Isso determina se o resultado 
final é negativo ou positivo, respectivamente. Suponha que o resultado seja 
positivo se nenhum estiver presente.

Leia a seguir os caracteres até que o próximo caractere não digitado ou o 
final da entrada seja alcançado. O resto da string é ignorado.

Converta esses dígitos em um número inteiro (ou seja "123" -> 123, "0032" -> 32). 

Se nenhum dígito foi lido, o número inteiro é 0. Altere o sinal conforme 
necessário (da etapa 2).

Se o inteiro estiver fora do intervalo de inteiros com sinal de 32 bits, fixe 
o inteiro para que ele permaneça no intervalo. Especificamente, números inteiros 
menores do que deveriam ser fixados e inteiros maiores do que deveriam ser fixados.
[-231, 231 - 1]-231-231231 - 1231 - 1

Retorne o inteiro como o resultado final.

Observação:
Apenas o caractere de espaço ' ' é considerado um caractere de espaço em branco.
Não ignore nenhum caractere além do espaço em branco inicial ou o resto da string após os dígitos.

Tempo de execução : 36 ms, mais rápido que 60,05 % dos envios.
Uso da memória : 14,5 MB, menos de 26,10 % dos envios.
"""


def myAtoi(s):
    s = s.strip()
    negativo = False
    i = 0
    r = 0

    if len(s) == 0:
        return 0

    if s[i] == '-':
        negativo = True
        i += 1
    elif s[i] == '+':
        i += 1

    while i < len(s):
        if s[i].isnumeric():
            temp = int(s[i:i+1])
            r = r * 10 + temp
            if negativo:
                if r * -1 < -2**31:
                    return -2**31
            elif r > 2**31 - 1:
                return 2**31 - 1
            i += 1
        else:
            break

    if negativo:
        return r * -1
    else:
        return r
