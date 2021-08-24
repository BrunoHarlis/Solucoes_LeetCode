# Fonte: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
# Autor: Bruno Harlis
# Data: 24/08/2021

"""
PROBLEMA PROPOSTO:
Você recebe uma string 's' e um array de strings 'words' do mesmo comprimento. 
Retorne todos os índices iniciais de substring (s) em s que seja uma concatenação
de cada palavra words exatamente uma vez , em qualquer ordem e sem nenhum caractere 
intermediário.

Você pode retornar a resposta em qualquer ordem .

Exemplo 1:

Entrada: s = "barfoothefoobarman", words = ["foo", "bar"]
Saída: [0,9]
 Explicação: Substrings começando no índice 0 e 9 são "barfoo" e "foobar" 
 respectivamente. 
A ordem de saída não importa, retornar [9,0] também é adequado.

Tempo de execução: 888 ms, mais rápido do que 33,78 % das envios.
Uso de memória: 14,6 MB, menos de 59,27 % dos envios.
"""


def findSubstring(s, words):
    answer = []
    sizeW = len(words[0])

    for i in range(0, len(s)):
        copyWords = words.copy()

        if (len(words) * sizeW) > len(s) - i:
            return answer

        for j in range(i, len(s), sizeW):
            word = s[j:j+sizeW]
            try:
                copyWords.remove(word)
                if len(copyWords) == 0:
                    answer.append(i)
                    break
            except ValueError:
                break

    return answer


if __name__ == '__main__':
    print(findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", [
        "fooo", "barr", "wing", "ding", "wing"]))
