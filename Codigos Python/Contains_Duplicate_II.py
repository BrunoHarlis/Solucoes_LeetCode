# Fonte: https://leetcode.com/problems/contains-duplicate-ii/
# Autor: Bruno Harlis
# Data: 21/09/2021

"""
PROBLEMA PROSPOSTO:
Dado um array inteiro nums e um inteiro k, retorna true se houver dois 
índices distintos i e j no array tal nums[i] == nums[j] e abs(i - j) <= k.

Exemplo 1:
Entrada: nums = [1,2,3,1], k = 3
 Saída: verdadeiro

Exemplo 2:
Entrada: nums = [1,0,1,1], k = 1
 Saída: verdadeiro

Exemplo 3:
Entrada: nums = [1,2,3,1,2,3], k = 2
 Saída: falso

Tempo de execução: 588 ms, mais rápido do que 90,50 % dos envios.
Uso de memória: 25,9 MB, menos de 83,66 % dos envios. 

"""


def containsNearbyDuplicate(nums, k):
    if len(nums) == len(set(nums)):
        return False

    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i] == nums[j]:
                if abs(i-j) <= k:
                    return True
                else:
                    break

    return False
