/* 1�. PASSO � Algumas defini��es
� Trabalhar com barras de 20 posi��es
� Supor que o controle sempre come�a a partir a primeira posi��o
� Inicializar os valores que constituir�o a barra. Construir essa parte do programa de forma que a
professora possa alterar os valores a serem inseridos na barra no programa fonte
� Definir a Senha CORRETA
� Permitir que o usu�rio fa�a no m�ximo 4 deslizamentos
� Os d�gitos a serem considerados para a constru��o da barra s�o: 0, 1, 5, 7, 9
2�. PASSO � Entrada - C�lculo
� O sistema dever� ir perguntando, ao usu�rio, a posi��o que ele deseja que o controle v� na barra, a
partir da posi��o em que ele se encontra.
� Determinar, em cada deslizamento, quantidade de cada d�gito
� Permitir que o usu�rio fa�a no m�ximo 4 deslizamentos. Como opcional, permitir tamb�m que o
usu�rio fa�a menos deslizamentos
3�. PASSO � Sa�da
� Imprimir a senha obtida pelos deslizamentos do usu�rio e informar se o sistema foi aberto ou n�o
� O sistema deve permitir que o usu�rio tente no m�ximo 3 vezes acertar a senha
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 20
#define max2 5
int main()
{
    int senhaCorreta[max2] = {2,2,3,4,2};
    int senha[max2];
    int num_desliza= 0,posAtual=0,posFinal=0,num0=0,num1=0,num5=0,num7=0,num9=0,tent=0,priExec=0,certo=0,opcao=0;
    setlocale(LC_ALL, "Portuguese");
    int numeros[max] = {5,9,1,7,5,5,9,0,7,1,5,9,1,7,5,5,9,0,7,1};
    printf("\nBarra numerica:   |  5 |  9 |  1 |  7 |  5 |  5 |  9 |  0 |  7 |  1 |  5 |  9 |  1 |  7 |  5 |  5 |  9 |  0 |  7 |  1 |\n");
    printf("\nPosi��o no vetor: | 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 |\n");
    while (tent < 3)
    {
        num_desliza= 0;
        posAtual=0;
        posFinal=0;
        num0=0;
        num1=0;
        num5=0;
        num7=0;
        num9=0;
        priExec=0;
        certo=0;
        opcao=0;
        while (num_desliza <= 3)
        {
            if(priExec!=0)
            {
                printf("\nDeseja Continuar? Digite 0 para sim e qualquer outro para n�o: ");
                scanf("%d",&opcao);
                if(opcao!=0)
                {
                    break;
                }
            }
            printf("\nDigite para qual posi��o deseja deslizar: ");
            scanf("%d",&posFinal);
            num_desliza++;
            if(priExec == 0)
            {
                for(int i=posAtual; i<=posFinal; i++)
                {
                    switch (numeros[i])
                    {
                    case 0:
                        num0++;
                        break;
                    case 1:
                        num1++;
                        break;
                    case 5:
                        num5++;
                        break;
                    case 7:
                        num7++;
                        break;
                    case 9:
                        num9++;
                        break;
                    }
                }
            priExec++;
            }
            else if (posAtual+1<posFinal)
            {
                for(int i=posAtual; i<=posFinal; i++)
                {
                    switch (numeros[i])
                    {
                    case 0:
                        num0++;
                        break;
                    case 1:
                        num1++;
                        break;
                    case 5:
                        num5++;
                        break;
                    case 7:
                        num7++;
                        break;
                    case 9:
                        num9++;
                        break;
                    }
                }
            }
            else
            {
                for(int i=posAtual-1; i>=posFinal; i--)
                {
                    switch (numeros[i])
                    {
                    case 0:
                        num0++;
                        break;
                    case 1:
                        num1++;
                        break;
                    case 5:
                        num5++;
                        break;
                    case 7:
                        num7++;
                        break;
                    case 9:
                        num9++;
                        break;
                    }
                }
            }
            posAtual=posFinal;
            senha[0]=num0;
            senha[1]=num1;
            senha[2]=num5;
            senha[3]=num7;
            senha[4]=num9;
        }
        for (int i=0; i<max2; i++)
        {
            if(senhaCorreta[i] != senha[i])
            {
                certo = 1;
            }
        }
        printf("\nSenha: %d%d%d%d%d\n",num0,num1,num5,num7,num9);
        if(certo==0)
        {
            printf("\nSenha Certa! Abrindo cofre...\n");
            break;
        }
        else
        {
            printf("\nSenha Errada! Tente novamente...\n");
            tent++;
        }
    }
}
