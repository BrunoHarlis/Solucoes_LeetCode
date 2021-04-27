
//Fonte: https://leetcode.com/problems/add-two-numbers/
//Autor: Bruno Harlis


/*****************************************************************************************
* PROBLEMA PROPOSTO
* Você recebe duas listas vinculadas não vazias que representam dois inteiros não negativos. 
* Os dígitos são armazenados em ordem reversa e cada um de seus nós contém um único dígito. 
* Adicione os dois números e retorne a soma como uma lista vinculada.
*
* Você pode assumir que os dois números não contêm nenhum zero à esquerda, exceto o próprio número 0
*
* Exemplo:
* Entrada: l1 = [2,4,3], l2 = [5,6,4]
* Saída: [7,0,8]
* Explicação: 342 + 465 = 807.
*
* SOLUÇÃO
* Demorei para solucionar essa kkkk.
* Recebemos dois ponteiros (l1 e l2) do tipo "ListNode" que representa uma lista de nós onde cada nó
* tem um numero. 
* 
* Primeiro criamos uma nova lista (l3) e uma lista temporária (temp) que recebe l3 como cópia par
* podermos manipular l3.
* 
* Criamos uma variável "int elevado" para quando a soma de dois nós for maior ou igual a 10. Ele receberá 1
* e asicionado a soma do próximo nó.
* 
* O loop while será executado enquando não atingirmos o final das duas listas e nao tivermos nenhum numero
* para ser elevado.
* 
* O primeiro "if" serve para sabermos precisamos elevar um número ou não. Caso sim, usamos "mod 10"
* para remover a casa da dezena e adicionamos 1 a variável "elevado".
* 
* Feito isso, finalmente adicionamos a soma a nossa lista "l3" e passamos o ponteiro de temp para o próximo nó.
* Também avançamos os nós de l1 e l2 caso ainda não estiverem no final (nullptr).
* 
* Para finalizar, retornamos nossa lista l3 com a soma realizada.
* 
*
* TESTE DE EFICIÊNCIA
* Tempo de Execução: 16 ms
* Memória Usada: 71.2 MB
*****************************************************************************************/
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

 };
 
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* l3{ new ListNode() };
        ListNode* temp{ l3 };

        int elevado{ 0 };
        
        while (l1 != nullptr || l2 != nullptr || elevado > 0)
        {
            int soma = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + elevado;

            if (soma >= 10)
            {
                soma = soma % 10;
                elevado = 1;
            }
            else
            {
                elevado = 0;
            }

            temp->next = new ListNode(soma);
            temp = temp->next;

            if (l1) { l1 = l1->next; }
            if (l2) { l2 = l2->next; }

        }

        return l3->next;
    }
};