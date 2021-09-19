# Fonte: https://leetcode.com/problems/happy-number/
# Autor: Bruno Harlis
# Data: 19/09/2021

"""
PROBLEMA PROSPOSTO:
Escreva um algoritmo para determinar se um número n está feliz.
Um número feliz é um número definido pelo seguinte processo:

-Começando com qualquer número inteiro positivo, substitua o número 
pela soma dos quadrados de seus dígitos.
-Repita o processo até que o número seja igual a 1 (onde ele 
permanecerá), ou ele faz um loop infinito em um ciclo que não inclui 1.
-Aqueles números para os quais este processo termina em 1 são felizes.
-Retorne true se n for um número feliz e false se não for.

Exemplo 1:
Entrada: n = 19
 Saída: True
 Explicação: 
1 2 + 9 2 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Tempo de execução: 36 ms, mais rápido que 65,12 % dos envios.
Uso de memória: 14,2 MB, menos de 48,31 % dos envios.

"""


def isHappy(n: int) -> bool:
    while n != 1:
        x = 0
        for i in str(n):
            x += int(i)**2

        if int(x) == 4:
            return False

        n = int(x)
    return True
