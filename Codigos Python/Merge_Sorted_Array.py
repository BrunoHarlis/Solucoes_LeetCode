# Fonte: https://leetcode.com/problems/merge-sorted-array/
# Autor: Bruno Harlis
# Data: 20/08/2021

"""
PROBLEMA PROSPOSTO:
São fornecidos dois arrays inteiros nums1 e nums2, classificados
em ordem não decrescente , e dois inteiros me n, representando 
o número de elementos em nums1 e, nums2 respectivamente.

Mesclar nums1 e nums2 em uma única matriz classificada em ordem 
não decrescente .

O array final classificado não deve ser retornado pela função, mas
sim armazenado dentro do array nums1 . Para acomodar isso, nums1tem
um comprimento de m + n, onde os primeiros melementos denotam os 
elementos que devem ser mesclados e os últimos n elementos são definidos
como 0e devem ser ignorados. nums2tem um comprimento de n.

Exemplo 1:
Entrada: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 Saída: [1,2,2,3,5,6]
 Explicação: As matrizes que estamos mesclando são [1,2,3] e [2,5,6]. 
O resultado da fusão é [ 1 , 2 , 2, 3 , 5,6] com os elementos sublinhados vindos de nums1.

Tempo de execução: 36 ms, mais rápido do que 69,84 % dos envios.
Uso de memória: 14,3 MB, menos de 33,18 % dos envios.
"""


def merge(nums1, m: int, nums2, n: int) -> None:
    del nums1[m:]
    del nums2[n:]

    if m == 0 or n == 0:
        nums1 += nums2
    else:
        j = 0
        i = 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                i += 1
            else:
                nums1.insert(i, nums2[j])
                j += 1
                i += 1
        nums1 += nums2[j:]
    print(nums1)


merge(nums1=[1, 2, 3, 0, 0, 0], m=3, nums2=[2, 5, 6], n=3)
merge(nums1=[0], m=0, nums2=[1], n=1)
merge(nums1=[1], m=1, nums2=[], n=0)
merge(nums1=[0, 0, 0, 0], m=4, nums2=[1, 2, 3, 3], n=4)
merge([4, 0, 0, 0, 0, 0], 1, [1, 2, 3, 5, 6], 5)
