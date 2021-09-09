# Fonte: https://leetcode.com/problems/excel-sheet-column-number/
# Autor: Bruno Harlis
# Data: 08/09/2021

"""
Dada uma string columnTitleque representa o título da coluna
conforme aparece em uma planilha do Excel, retorne o número 
da coluna correspondente.

Por exemplo:

A -> 1 
B -> 2 
C -> 3 
... 
Z -> 26 
AA -> 27 
AB -> 28 
...
 
Exemplo 1:
Entrada: columnTitle = "A"
 Saída: 1

Exemplo 2:
Entrada: columnTitle = "AB"
 Saída: 28

Exemplo 3:
Entrada: columnTitle = "ZY"
 Saída: 701

Exemplo 4:
Entrada: columnTitle = "FXSHRXW"
 Saída: 2147483647

TEMPO DE EXECUÇÃO:
Tempo de execução: 35 ms, mais rápido do que 48,84 % dos envios.
Uso da memória: 14,2 MB, menos de 72,14 % dos envios.
"""


def titleToNumber(c: str) -> int:
    answer = ord(c[len(c) - 1]) - 64
    c = c[:len(c) - 1]
    length = len(c)

    if length == 0:
        return answer

    for i in c[::-1]:
        length -= 1
        answer += (ord(i) - 64) * (26 ** (len(c) - length))

    return answer


print(titleToNumber("A"))
print(titleToNumber("AB"))
print(titleToNumber("AZ"))
print(titleToNumber("ZY"))
print(titleToNumber("FXSHRXW"))
