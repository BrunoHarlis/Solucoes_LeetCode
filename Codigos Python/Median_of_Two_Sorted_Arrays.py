# Fonte: https://leetcode.com/problems/median-of-two-sorted-arrays/
# Autor: Bruno Harlis
# Data: 29/07/2021
"""
PROBLEMA PROPOSTO:
Dadas duas matrizes classificadas nums1 e nums2 de tamanho m e n respectivamente, 
retorna a mediana das duas matrizes classificadas.

A complexidade geral do tempo de execução deve ser O(log (m+n)).

Exemplo 1:
Entrada: nums1 = [1,3], nums2 = [2]
Saída: 2,00000
Explicação: matriz mesclada = [1,2,3] e a mediana é 2.

Tempo de execução : 88 ms, mais rápido do que 84,93 % dos envios online do Python3.
Uso de Memória : 14,4 MB, menos de 81,38 % de python3.
"""


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        for i in nums2:
        nums1.append(i)

        nums1.sort()

        par = True
        if len(nums1) % 2 != 0:
            par = False

        meio = len(nums1) // 2

        if par:
            return (nums1[meio] + nums1[meio - 1]) / 2
        else:
            return nums1[meio]
