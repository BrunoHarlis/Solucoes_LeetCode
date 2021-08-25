# Fonte: https://leetcode.com/problems/single-number/
# Autor: Bruno Harlis
# Data: 24/07/2021

"""
PROBLEMA pROPOSTO:
Dada uma  matriz não vazia de inteiros nums, cada elemento aparece 
duas vezes, exceto um. Encontre aquele único.

Você deve implementar uma solução com uma complexidade de tempo de 
execução linear e usar apenas espaço extra constante.

Exemplo 1:
Entrada: nums = [2,2,1]
 Saída: 1

Exemplo 2:
Entrada: nums = [4,1,2,1,2]
 Saída: 4

Exemplo 3:
Entrada: nums = [1]
 Saída: 1

Tempo de execução: 124 ms, mais rápido do que 93,08 % dos envios.
Uso de memória: 16,7 MB, menos de 19,65 % dos envios.
"""


def singleNumber(nums):
    if len(nums) == 1:
        return nums[0]

    nums.sort()
    i = 0

    while i < len(nums):
        try:
            if nums[i] != nums[i+1]:
                return nums[i]
            else:
                i += 2
        except IndexError:
            return nums[i]


if __name__ == '__main__':
    print(singleNumber([4, 1, 2, 1, 2]))
    print(singleNumber([1]))
    print(singleNumber([2, 2, 1]))
