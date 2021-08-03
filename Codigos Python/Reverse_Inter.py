# Fonte: https://leetcode.com/problems/reverse-integer/
# Autor: Bruno Harlis Oliveira Xavier
# Data: 20/08/2021

"""
Dado um número inteiro de 32 bits com sinal x, retorna x com
seus dígitos invertidos . Se a reversão xfizer com que o valor 
saia do intervalo de inteiros de 32 bits com sinal , retorne .[-231, 231 - 1]0

Exemplo 1:
Entrada: x = 123
Saída: 321

Exemplo 2:
Entrada: x = -123
Saída: -321

"""


class Solution:
    def reverse(self, x: int) -> int:
        if x > 0:
            r = str(x)
            r = r[::-1]
            if int(r) <= 2**31-1:
                return int(r)
            else:
                return 0
        else:
            r = str(x*-1)
            r = r[::-1]
            if int(r) <= 2**31:
                return int(r)*-1
            else:
                return 0
