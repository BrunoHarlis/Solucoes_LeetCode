# Fonte: https://leetcode.com/problems/contains-duplicate/
# Autor: Bruno Harlis
# Data: 01/09/2021

"""
Dado um array inteiro nums, retorne truese algum valor aparecer pelo menos duas vezes no array e retorne falsese cada elemento for distinto.

 

Exemplo 1:

Entrada: nums = [1,2,3,1]
 Saída: verdadeiro
Exemplo 2:

Entrada: nums = [1,2,3,4]
 Saída: falso

TEMPO DE EXECUÇÃO
Tempo de execução: 163 ms , mais rápido do que 24,54 % dos envios.
Uso de memória: 20 MB, menos de 62,18 % dos envios.
"""


def containsDuplicate(nums) -> bool:
    x = set(nums)

    if len(x) != len(nums):
        return True
    else:
        return False
