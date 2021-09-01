"""
PROBLEMA PROPOSTO
Dado um número inteiro "columnNumber", retorna o título da coluna correspondente conforme aparece em uma planilha do Excel.
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
Entrada: columnNumber = 1
 Saída: "A"

Exemplo 2:
Entrada: columnNumber = 701
 Saída: "ZY"

Exemplo 3:
Entrada: columnNumber = 2147483647
 Saída: "FXSHRXW"

TEMPO DE EXECUÇÃO
Tempo de execução: 28 ms, mais rápido do que 76,37 % dos envios.
Uso da memória: 14,2 MB, menos de 42,97 % dos envios.
"""


def convertToTitle(columnNumber):
    alpha = ['A',  'B', 'C', 'D',  'E',  'F',  'G', 'H', 'I', 'J',  'K,',  'L',
             'M', 'N', 'O', 'P',  'Q',  'R',  'S',  'T',  'U', 'V', 'W', 'X',  'Y',  'Z']
    answer = ''

    while columnNumber > 0:
        tempN = (columnNumber - 1) % 26
        answer = alpha[tempN] + answer

        columnNumber = (columnNumber - 1) // 26

    return answer


print(convertToTitle(52))
print(convertToTitle(701))
print(convertToTitle(2147483647))
