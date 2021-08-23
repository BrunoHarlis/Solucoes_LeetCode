# Fonte: https://leetcode.com/problems/pascals-triangle/
# Autor: Bruno Harlis
# Data: 23/08/2021

"""
PROBLEMA PROPOSTO:
Dado um inteiro numRows, retorna o primeiro numRows do triângulo de Pascal.
No triângulo de Pascal , cada número é a soma dos dois números diretamente 
acima dele, conforme mostrado:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

Exemplo 1:
Entrada: numRows = 5
 Saída: [[1], [1,1], [1,2,1], [1,3,3,1], [1,4,6,4,1]]

Tempo de execução: 32 ms, mais rápido do que 59,95 % das submissões.
Uso de Memória: 14,2 MB, menos de 81,98 % de python3 submissões.
"""


def generate(n: int):
    if n == 1:
        return [[1]]

    l = [[1], [1, 1]]
    for i in range(1, n-1):
        l.append([1])
        for j in range(0, len(l[i])):
            if l[i][j+1] == 1:
                l[i+1].append(l[i][j] + l[i][j+1])
                break
            l[i+1].append(l[i][j] + l[i][j+1])
        l[i+1].append(1)

    return l


if __name__ == '__main__':
    resp = generate(4)
    print(resp)
