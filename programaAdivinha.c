#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculaErro(int alvo, int chute){
	double resultado;
	if(alvo > chute)
		resultado = (double)(alvo -chute)/ 2.0;
	else
		resultado = (double)(chute -alvo)/ 2.0;
	return resultado;

}

int main(void)
{
	srand(time(NULL));
	int valor_aleatorio = rand()%100;
	int chute = -1;	
	int numero_de_tentativas;
	int numero_chutes = 0;
	int nivel;
	double pontuacao = 1000;
	printf("**************************\n");
	printf("Bem-vindo ao jogo do chute\n");
	printf("**************************\n");
	printf("Escolha seu nível, básico(1), médio(2) ou avançado(3)\n");
	scanf("%d", &nivel);
	switch (nivel) {
		case 1:
			numero_de_tentativas =20;
			break;
		case 2:
			numero_de_tentativas =10;
			break;
		default:
			numero_de_tentativas = 6;	
			break;
	}

	while (chute != valor_aleatorio && numero_de_tentativas >= 0) {
		printf("Por favor chute um número\n");

		scanf("%d", &chute);

		if(chute < 0)
		{
			printf("Chutes devem ser sempre positivos!\n");
			continue;
		}

		numero_chutes++;
		if(chute == valor_aleatorio){
			printf("Parabéns, você acertou!\n");
			printf("O número de tentativas foi de %d\n", numero_chutes);
			printf("Sua pontuacao foi de %.1f\n", pontuacao);
		}else if(chute < valor_aleatorio){
			printf("Pena, você errou, número muito pequeno\n");
		}else {
			printf("Pena, você errou, número muito grande\n");
		}
		pontuacao -= calculaErro(chute, valor_aleatorio);
		numero_de_tentativas--;
	}
	if(chute != valor_aleatorio){
		printf("Pena, você não consegui acetar\n");
		printf("Sua pontuacao foi de %.1f\n", pontuacao);
	}
}
