#include <iostream>
#include <string>
#include <math.h>


class Solution 
{
public:
    int reverse(int x) 
    {
        int invertido{ 0 };
        int numero{ 0 };
        while (x != 0)
        {
            numero = x % 10;   //Pega o ultimo numero
            x -= x % 10;       //subtrai o ultimo numero do numero original
            x = x / 10;        //retira a ultima casa decimal do numero original
            if (invertido > INT_MAX / 10 || (invertido == INT_MAX / 10 && numero > 7)) return 0;
            if (invertido < INT_MIN / 10 || (invertido == INT_MIN / 10 && numero < -8)) return 0;
            invertido = invertido * 10 + numero; //Adicionamos o ultimo digito com as casas decimais    
        }
        
        return invertido;
    }
};

int main()
{
    int x{ -321 };

    Solution s;

    std::cout << s.reverse( x);
}