# Fonte: https://leetcode.com/problems/add-binary/
# Autor: Bruno Harlis
# Data: 17/08/2021

"""
PROBLEMA PROSPOSTO:
Dadas duas cadeias binárias ae b, retornam sua soma como uma cadeia binária .

Exemplo 1:
Entrada: a = "11", b = "1"
Saída: "100"

Exemplo 2:
Entrada: a = "1010", b = "1011"
Saída: "10101"

Tempo de execução : 28 ms, mais rápido do que 91,25 % dos envios
Uso de memória : 14,3 MB, menos de 23,72 % dos envios

"""


def addBinary(a: str, b: str):
    size = 0

    # Caso 'a' e 'b' não tenham o mesmo comprimento, será
    # adicionado zeros na frente do menor para que fiquem iguais
    if len(a) == len(b):
        size = len(a)
    else:
        size = max(len(a), len(b))
        dif = size - min(len(a), len(b))

        if len(a) < len(b):
            a = '0' * dif + a
        else:
            b = '0' * dif + b

    temp = ''
    carry = 0

    # Percorre as strings 'a' e 'b' de trás pra frente
    for i in range(size-1, -1, -1):
        if a[i] == '1' and b[i] == '1':
            if carry == 0:
                temp = '0' + temp
            else:
                temp = '1' + temp
            carry = 1
        elif a[i] == '1' or b[i] == '1':
            if carry == 0:
                temp = '1' + temp
            else:
                temp = '0' + temp
        else:
            if carry == 0:
                temp = '0' + temp
            else:
                temp = '1' + temp
            carry = 0

    if carry == 1:
        temp = '1' + temp

    return temp


if __name__ == '__main__':
    print(addBinary("1010", "1011"))
