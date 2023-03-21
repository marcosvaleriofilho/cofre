/* 1º. PASSO – Algumas definições
• Trabalhar com barras de 20 posições
• Supor que o controle sempre começa a partir a primeira posição
• Inicializar os valores que constituirão a barra. Construir essa parte do programa de forma que a
professora possa alterar os valores a serem inseridos na barra no programa fonte
• Definir a Senha CORRETA
• Permitir que o usuário faça no máximo 4 deslizamentos
• Os dígitos a serem considerados para a construção da barra são: 0, 1, 5, 7, 9
2º. PASSO – Entrada - Cálculo
• O sistema deverá ir perguntando, ao usuário, a posição que ele deseja que o controle vá na barra, a
partir da posição em que ele se encontra.
• Determinar, em cada deslizamento, quantidade de cada dígito
• Permitir que o usuário faça no máximo 4 deslizamentos. Como opcional, permitir também que o
usuário faça menos deslizamentos
3º. PASSO – Saída
• Imprimir a senha obtida pelos deslizamentos do usuário e informar se o sistema foi aberto ou não
• O sistema deve permitir que o usuário tente no máximo 3 vezes acertar a senha
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
    printf("\nPosição no vetor: | 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 |\n");
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
                printf("\nDeseja Continuar? Digite 0 para sim e qualquer outro para não: ");
                scanf("%d",&opcao);
                if(opcao!=0)
                {
                    break;
                }
            }
            printf("\nDigite para qual posição deseja deslizar: ");
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
