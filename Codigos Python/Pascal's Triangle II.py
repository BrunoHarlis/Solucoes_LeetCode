# Fonte: https://leetcode.com/problems/pascals-triangle-ii/
# Autor: Bruno Harlis
# Data: 23/08/2021

"""
PROBLEMA PROPOSTO:
Dado um número inteiro rowIndex, retorna a linha (indexada em 0) do triângulo de Pascal rowIndexth.
No triângulo de Pascal , cada número é a soma dos dois números diretamente acima dele, conforme mostrado:

    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

Exemplo 1:
Entrada: rowIndex = 3
 Saída: [1,3,3,1]

Exemplo 2:
Entrada: rowIndex = 0
 Saída: [1]

Tempo de execução: 28 ms, mais rápido do que 85,90 % dos envios.
Uso de memória: 14,3 MB, menos de 52,02 % dos envios.
"""


def getRow(self, n: int):
    if n == 0:
        return [1]
    if n == 1:
        return [1, 1]

    l = [[1], [1, 1]]
    for i in range(1, n):
        l.append([1])
        for j in range(0, len(l[i])):
            if l[i][j+1] == 1:
                l[i+1].append(l[i][j] + l[i][j+1])
                break
            l[i+1].append(l[i][j] + l[i][j+1])
        l[i+1].append(1)

    return l[n]


if __name__ == '__main__':
    resp = getRow(1)
    print(resp)
