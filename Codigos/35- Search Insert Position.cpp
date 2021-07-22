//Fonte: https://leetcode.com/problems/search-insert-position/
//Autor: Bruno Harlis
//Data: 22/07/2021

/*****************************************************************************************
* PROBLEMA PROPOSTO
* Dada uma matriz classificada de inteiros distintos e um valor de destino, retorne o índice 
* se o destino for encontrado. Caso contrário, retorne o índice onde estaria se fosse inserido
* em ordem. 
* Você deve escrever um algoritmo com  O(log n)complexidade de tempo de execução.
* 
* Exemplo:
* Entrada: nums = [1,3,5,6], alvo = 5
* Saída: 2
* 
* Entrada: nums = [1,3,5,6], meta = 2
* Saída: 1
*
* TESTE DE EFICIÊNCIA
* Tempo de Execução: 0 ms
* Memória Usada: 9.7 MB
* *****************************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) 
{    
    if (nums.size() == 0) return 0;

    vector<int> result{};    
    int ultimo = nums.size() - 1;
    int primeiro{ 0 };
    int indice{};

    while (primeiro <= ultimo)
    {
        int meio{ (primeiro + ultimo) / 2 };

        if (nums[meio] == target)
        {
            return meio;
        }
        else
        {
            if (target < nums[meio])
                ultimo = meio - 1;
            else
                primeiro = meio + 1;
        }

        indice = meio;
    }

    if (target > nums[indice])
        return indice + 1;
        
    return indice;
}

void teste(vector<int>& nums, int target, int resp)
{
    static int a = 1;
    auto x{ searchInsert(nums, target) };

    if (x == resp)
        cout << "teste " << a << "-> Aprovado" << endl;
    else
        cout << "teste " << a << "-> ERRO" << endl;

    a++;
}

int main()
{
    vector<int> n1{ 1,2,3 };
    int t1{ 1 }; 
    int r1{ 0 };

    vector<int> n2{ 1,2,3 };
    int t2{ 2 };
    int r2{ 1 };

    vector<int> n3{ 1,2,3 };
    int t3{ 3 };
    int r3{ 2 };

    vector<int> n4{  };
    int t4{ 1 };
    int r4{ 0 };

    vector<int> n5{ 1 };
    int t5{ 0 };
    int r5{ 0 };

    vector<int> n6{ 1,3,4 };
    int t6{ 2 };
    int r6{ 1 };

    vector<int> n7{ 1,2,4 };
    int t7{ 3 };
    int r7{ 2 };

    vector<int> n8{ 1,2,3 };
    int t8{ 4 };
    int r8{ 3 };


    teste(n1, t1, r1);
    teste(n2, t2, r2);
    teste(n3, t3, r3);
    teste(n4, t4, r4);
    teste(n5, t5, r5);
    teste(n6, t6, r6);
    teste(n7, t7, r7);
    teste(n8, t8, r8);
}