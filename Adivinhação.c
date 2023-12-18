#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n");
    printf("          P  /_\\  P                               \n");
    printf("         /_\\_|_|_/_\\                             \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao      \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!  \n");
    printf("    |" "  |  |_|  |"  " |                          \n");
    printf("    |_____| ' _ ' |_____|                          \n");
    printf("          \\__|_|__/                               \n");
    printf("\n\n");

    int segundos = time(0); //numeros de segundos passados desde 1970
    srand(segundos); // passa a seed para o rand onde ele ira sempre se basear em time(0) que esta sempre mudando

    int numeroSecreto = rand() % 100;
    int tentativa;
    int tentativasNu = 0;
    int certo = 0;
    double pontos = 1000;
    int numeroTentativas;

    printf("Escolha um nivel de dificuldade:\n");
    printf("1. Facil\n2. Médio\n 3. Dificíl\n");
    int nivel;
    scanf("%d", &nivel);

    switch (nivel)
    {
    case 1:
        numeroTentativas = 20;
        break;
    case 2:
        numeroTentativas = 10;
        break;
    default:
        numeroTentativas = 5;
        break;
    }
    
    for(int i = 0; i <= numeroTentativas; i++){

        printf("Digite um numero:\n");
        scanf("%d", &tentativa);
        if(tentativa < 0){
            printf("Não pode chutar números negativos\n");
            continue;
        }

        int maior = (tentativa > numeroSecreto);
        certo = (tentativa == numeroSecreto);

        printf("Tentatica número: %d\n", tentativasNu+1);

        if (certo){
            break;
        }

        else if(maior){
        printf("O numero que pensei é menor\n");
        }

        else{
        printf("O numero que pensei é maior\n");
        }
        tentativasNu++;
    
        //código lê da direita para a esquerda, então colocando o 2.0 ele identifica que a conta sera em double, se n tivesse ele iria realizar em int pois o numeroSecreto esta em int, oq geraria um bug
        double pontosPerdidos = abs(tentativasNu - numeroSecreto) / (double)2;
        //(double)2, faz um casting, ele converte o numero para outro tipo, pode ser usado em variaveis da mesma forma, assim vc pode a variavel por outro tipo só naquele momento sem precisar modificar sua declaração.
        //abs = faz uma conversão de negativo para positivo, para garantir que os pontos perdidos sempre irão crescer, o mesmo que usar a multiplicação pelo -1.
        pontos = pontos - pontosPerdidos;
    }

    printf("Fim de Jogo!\n");
    if(certo){
        printf("Você acertou!!\n Parabéns\n");
        printf("Acertou em %d tentativas", tentativasNu);
        printf("Sua pontuação total é de %.1f\n", pontos);
    }
    else{
        printf("Você perdeu, tente novamente\n");
    }
    

    return 0;
    
}