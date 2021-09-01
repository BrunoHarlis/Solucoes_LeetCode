# Fonte: https://leetcode.com/problems/majority-element/
# Autor: Bruno Harlis
# Data: 01/09/2021

"""
PROBLEMA PROPOSTO
Dado um array "nums" de tamanho "n", retorna o elemento majoritário.
O elemento majoritário é o elemento que aparece mais do que ⌊n/2⌋ vezes.
Você pode presumir que o elemento majoritário sempre existe na matriz.

Exemplo 1:
Entrada: nums = [3,2,3]
 Saída: 3

Exemplo 2:
Entrada: nums = [2,2,1,1,1,2,2]
 Saída: 2

TEMPO DE EXECUÇÃO
Tempo de execução: 164 ms, mais rápido que 74,88 % dos envios.
Uso de memória: 15,7 MB, menos de 11,60 % dos envios.
"""


def majorityElement(nums):
    d = {}

    for i in nums:
        try:
            d[i] += 1
        except KeyError:
            d[i] = 1

    repet = 0
    num = 0

    for x, quantity in d.items():
        if quantity > repet:
            repet = quantity
            num = x

    return num


print(majorityElement([2, 2, 1, 1, 1, 2, 2]))
