# Fonte: https://leetcode.com/problems/sqrtx/
# Autor: Bruno Harlis
# Data: 18/08/2021

"""
Dado um número inteiro x não negativo, calcule e retorne a
raiz quadrada de x .
Como o tipo de retorno é um inteiro, os dígitos decimais são
truncados e apenas a parte inteira do resultado é retornada.

Nota: Você não tem permissão para usar nenhuma função expoente
ou operador embutido, como pow(x, 0.5) ou  x ** 0.5.

Exemplo 1:

Entrada: x = 4
Saída: 2
Exemplo 2:

Entrada: x = 8
Saída: 2
Explicação: A raiz quadrada de 8 é 2,82842 ... e, como a parte 
decimal está truncada, 2 é retornado.

Tempo de execução: 32 ms, mais rápido do que 87,42 % das submissões.
Uso de memória: 14,1 MB, menos de 90,02 % dos envios.
"""


class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0 or x == 1:
            return x

        first = 0
        last = x

        while first <= last:
            raiz = (first + last) // 2
            if (raiz * raiz) > x:
                last = raiz - 1
            elif (raiz * raiz) <= x:
                if (raiz + 1) * (raiz + 1) > x:
                    return raiz
                else:
                    first = raiz + 1
