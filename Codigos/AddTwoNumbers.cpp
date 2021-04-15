
//Fonte: https://leetcode.com/problems/add-two-numbers/
//Autor: Bruno Harlis


/*****************************************************************************************
* PROBLEMA PROPOSTO
* Voc� recebe duas listas vinculadas n�o vazias que representam dois inteiros n�o negativos. 
* Os d�gitos s�o armazenados em ordem reversa e cada um de seus n�s cont�m um �nico d�gito. 
* Adicione os dois n�meros e retorne a soma como uma lista vinculada.
*
* Voc� pode assumir que os dois n�meros n�o cont�m nenhum zero � esquerda, exceto o pr�prio n�mero 0
*
* Exemplo:
* Entrada: l1 = [2,4,3], l2 = [5,6,4]
* Sa�da: [7,0,8]
* Explica��o: 342 + 465 = 807.
*
* SOLU��O
* Demorei para solucionar essa kkkk.
* Recebemos dois ponteiros (l1 e l2) do tipo "ListNode" que representa uma lista de n�s onde cada n�
* tem um numero. 
* 
* Primeiro criamos uma nova lista (l3) e uma lista tempor�ria (temp) que recebe l3 como c�pia par
* podermos manipular l3.
* 
* Criamos uma vari�vel "int elevado" para quando a soma de dois n�s for maior ou igual a 10. Ele receber� 1
* e asicionado a soma do pr�ximo n�.
* 
* O loop while ser� executado enquando n�o atingirmos o final das duas listas e nao tivermos nenhum numero
* para ser elevado.
* 
* O primeiro "if" serve para sabermos precisamos elevar um n�mero ou n�o. Caso sim, usamos "mod 10"
* para remover a casa da dezena e adicionamos 1 a vari�vel "elevado".
* 
* Feito isso, finalmente adicionamos a soma a nossa lista "l3" e passamos o ponteiro de temp para o pr�ximo n�.
* Tamb�m avan�amos os n�s de l1 e l2 caso ainda n�o estiverem no final (nullptr).
* 
* Para finalizar, retornamos nossa lista l3 com a soma realizada.
* 
*
* TESTE DE EFICI�NCIA
* Tempo de Execu��o: 16 ms
* Mem�ria Usada: 71.2 MB
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