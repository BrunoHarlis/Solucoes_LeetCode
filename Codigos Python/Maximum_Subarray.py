# Fonte: https://leetcode.com/problems/maximum-subarray/
# Autor: Bruno Harlis
# Data: 10/08/2021

"""
PROBLEMA PROPOSTO:
Dado um array de inteiros nums, encontre o subarray contíguo 
(contendo pelo menos um número) que tem a maior soma e retorna sua soma .

Um subarray é uma parte contígua de um array.

Exemplo 1:
Entrada: nums = [-2,1,-3,4,-1,2,1,-5,4]
Saída: 6
Explicação: [4,-1,2,1] tem a maior soma = 6.

Tempo de execução : 60 ms, mais rápido do que 90,57 % dos envios.
Uso de memória : 14,9 MB, menos de 85,16 % dos envios.
"""


def maxSubArray(nums):
    sum = -9223372036854775808
    temp = 0

    for x in range(len(nums)):
        temp += nums[x]

        if temp > sum:
            sum = temp

        if temp < 0:
            temp = 0

    return sum


if __name__ == '__main__':
    x = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(maxSubArray(x))
