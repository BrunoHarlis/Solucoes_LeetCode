# Fonte: https://leetcode.com/problems/plus-one/
# Autor: Bruno Harlis
# Data: 10/08/2021

"""
Dada uma matriz não vazia de dígitos decimais representando um 
inteiro não negativo, incremente um para o inteiro.

Os dígitos são armazenados de forma que o dígito mais significativo
esteja no topo da lista e cada elemento na matriz contenha um único dígito.

Você pode assumir que o inteiro não contém nenhum zero à esquerda, 
exceto o próprio número 0.

Exemplo 1:
Entrada: dígitos = [1,2,3]
 Saída: [1,2,4]
 Explicação: A matriz representa o inteiro 123.

Exemplo 2:
Entrada: dígitos = [4,3,2,1]
 Saída: [4,3,2,2]
 Explicação: A matriz representa o inteiro 4321.

Tempo de execução : 28 ms, mais rápido do que 88,60 % das submissões.
Uso de memória : 14,2 MB, menos de 76,32 % dos envios.
"""


def plusOne(digits):
    index = len(digits)-1
    count = 0

    for i in range(len(digits)-1, -1, -1):
        if digits[i] == 9:
            digits.pop()
            index -= 1
            count += 1
        else:
            digits[i] += 1
            break

    if index < 0:
        digits.append(1)

    for x in range(count):
        digits.append(0)

    return digits


if __name__ == '__main__':
    print(plusOne([1, 2, 3]))
    print(plusOne([4, 3, 2, 1]))
    print(plusOne([0]))
    print(plusOne([9]))
    print(plusOne([9, 9]))
    print(plusOne([1, 9, 9]))
