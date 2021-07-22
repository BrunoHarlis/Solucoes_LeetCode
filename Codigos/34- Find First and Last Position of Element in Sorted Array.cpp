//Fonte: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//Autor: Bruno Harlis
//Data: 22/07/2021

/*****************************************************************************************
* PROBLEMA PROPOSTO
* Dada uma matriz "nums" de inteiros classificados em ordem crescente, encontre a posição inicial
* e final de um determinado valor "target".
* 
* Se "target" não for encontrado na matriz, retorna [-1, -1]. 
* Você deve escrever um algoritmo com  O(log n)complexidade de tempo de execução.
* 
* Exemplo:
* Entrada: nums = [5,7,7,8,8,10], alvo = 8
* Saída: [3,4]
*
* TESTE DE EFICIÊNCIA
* Tempo de Execução: 8 ms
* Memória Usada: 13.6 MB
* *****************************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> result{};
        
    int ultimo = nums.size() - 1;
    int primeiro{ 0 };
    int indexDireito{ -1 };
    int indexExquerdo{ -1 };

    while (primeiro <= ultimo)
    {
        int meio{ (primeiro + ultimo) / 2 };

        if (nums[meio] == target)
        {
            indexDireito = meio;
            primeiro = meio + 1;
        }
        else
        {
            // metodo de busca binaria
            if (target < nums[meio])
                ultimo = meio - 1;
            else
                primeiro = meio + 1;

            meio = (primeiro + ultimo) / 2;
        }
    }

    ultimo = nums.size() - 1;
    primeiro = 0;

    while (primeiro <= ultimo)
    {
        int meio{ (primeiro + ultimo) / 2 };

        if (nums[meio] == target)
        {
            indexExquerdo = meio;
            ultimo = meio - 1;
        }
        else
        {
            // metodo de busca binaria
            if (target < nums[meio])
                ultimo = meio - 1;
            else
                primeiro = meio + 1;

            meio = (primeiro + ultimo) / 2;
        }
    }

    result.push_back(indexExquerdo);
    result.push_back(indexDireito);
    return result;
}

void teste(vector<int>& nums, int target, vector<int>& resp)
{
    static int a = 1;
    auto x{ searchRange(nums, target) };

    if (x == resp)
        cout << "teste " << a << "-> Aprovado" << endl;
    else
        cout << "teste " << a << "-> ERRO" << endl;

    a++;
}

int main()
{
    vector<int> n1{ 1,2,3 };//00
    int t1{ 1 }; 
    vector<int> r1{ 0,0 };

    vector<int> n2{ 1 }; //00
    int t2{ 1 };
    vector<int> r2{ 0,0 };

    vector<int> n3{ };//-1-1
    int t3{ 1 };
    vector<int> r3{ -1,-1 };

    vector<int> n4{ 1 };//-1-1
    int t4{ 0 };
    vector<int> r4{ -1,-1 };

    vector<int> n5{ 1,2,3 };//22
    int t5{ 3 };
    vector<int> r5{ 2,2 };

    vector<int> n6{ 1,2,3 };//11
    int t6{ 2 };
    vector<int> r6{ 1,1 };

    vector<int> n7{ 1,1,2 };//01
    int t7{ 1 };
    vector<int> r7{ 0,1 };

    vector<int> n8{ 1,1,2,3,3 };//34
    int t8{ 3 };
    vector<int> r8{ 3,4 };

    vector<int> n9{ 1,2,3,3 };//23
    int t9{ 3 };
    vector<int> r9{ 2,3 };

    vector<int> n10{ 1,1,2,3 };//01
    int t10{ 1 };
    vector<int> r10{ 0,1 };

    vector<int> n11{ 1,1,1 };//02
    int t11{ 1 };
    vector<int> r11{ 0,2 };


    teste(n1, t1, r1);
    teste(n2, t2, r2);
    teste(n3, t3, r3);
    teste(n4, t4, r4);
    teste(n5, t5, r5);
    teste(n6, t6, r6);
    teste(n7, t7, r7);
    teste(n8, t8, r8);
    teste(n9, t9, r9);
    teste(n10, t10, r10);
    teste(n11, t11, r11);
}