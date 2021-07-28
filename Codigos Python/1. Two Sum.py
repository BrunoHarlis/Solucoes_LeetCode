# Fonte: https://leetcode.com/problems/two-sum/
# Autor: Bruno Harlis

"""
PROBLEMA PROPOSTO:
Dado um array de inteiros nums e um inteiro target, retorna os índices dos dois 
números de forma que eles se somamtarget.

Você pode presumir que cada entrada teria exatamente uma solução e não pode usar
o mesmo elemento duas vezes.

Você pode retornar a resposta em qualquer ordem.

Exemplo 1:
Entrada: nums = [2,7,11,15], destino = 9
Saída: [0,1]
Explicação: Como nums [0] + nums [1] == 9, retornamos [0, 1].

Tempo de execução: 4496 ms
Uso de memória: 14,9 MB
"""


def twoSum(nums, target):
    result = []

    for i in range(len(numbers)):
        for j in range(i+1, len(numbers)):
            if ((numbers[i] + numbers[j]) == target):
                result.append(i)
                result.append(j)

    return result


numbers = [2, 7, 11, 15]
target = 9

print(twoSum(numbers, target))
