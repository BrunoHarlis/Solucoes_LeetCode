# Fonte: https://leetcode.com/problems/climbing-stairs/
# Autor: Bruno Harlis
# Data: 19/08/2021

"""
PROBLEMA PROSPOSTO:
Você está subindo uma escada. São necessários alguns n passos
para chegar ao topo.
Cada vez você pode subir 1ou 2degraus. De quantas maneiras
distintas você pode chegar ao topo?

Exemplo 1:
Entrada: n = 2
 Saída: 2
 Explicação: Existem duas maneiras de subir até o topo.
1. 1 etapa + 1 etapa
2. 2 etapas

Exemplo 2:
Entrada: n = 3
 Saída: 3
 Explicação: Existem três maneiras de subir até o topo.
1. 1 etapa + 1 etapa + 1 etapa
2. 1 etapa + 2 etapas
3. 2 etapas + 1 etapa

Tempo de execução: 32 ms, mais rápido do que 49,77 % dos envios.
Uso de memória: 14,3 MB, menos de 44,64 % dos envios.

"""


def climbStairs(n: int) -> int:
    prox = 1
    ant = 0
    resp = 0
    for i in range(n):
        resp = ant + prox
        ant = prox
        prox = resp
    return resp


print(climbStairs(0))
print(climbStairs(1))
print(climbStairs(2))
print(climbStairs(3))
print(climbStairs(4))
print(climbStairs(5))
print(climbStairs(6))
print(climbStairs(7))
print(climbStairs(8))
print(climbStairs(9))
