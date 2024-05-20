#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

int pontuacaoJogadorUm,pontuacaoJogadorDois;

typedef struct {
	char nome[50];
} Jogador;

void jogo() {
	Jogador jogadores[2];
	int i, jogador, ganhou, jogadas, l, c, linha, coluna, opcao, posicao;
	char jogoVelha[3][3];
	char numbers[3][3];

    numbers[0][0] = '1';
    numbers[0][1] = '2';
    numbers[0][2] = '3';
    numbers[1][0] = '4';
    numbers[1][1] = '5';
    numbers[1][2] = '6';
    numbers[2][0] = '7';
	numbers[2][1] = '8';
    numbers[2][2] = '9';
	
	for(i = 0; i < 2; i++) {
		system("cls");
		fflush(stdin);
		printf("Informe o nome do jogador %d: ", i + 1);
		gets(jogadores[i].nome);
	}

	do {
		system("cls");
		jogador = 1;
		ganhou = 0;
		jogadas = 0;
		
		for(l = 0; l < 3; l++) {
			for(c = 0; c < 3; c++){
				jogoVelha[l][c] = ' ';
			}
		}

		do {
			system("cls");
			
			for(l = 0; l < 3; l++) {
				for(c = 0; c < 3; c++) {
					if(c == 0) {
						printf("\t");
					}
					if(jogoVelha[l][c] != ' ') {
                        printf(" %c ", jogoVelha[l][c]);
                    } else{
                        printf(" %c ", numbers[l][c]);
                    }
					if(c < 2) {
						printf("|");
					}
				}
				if(l < 2) {
					printf("\n\t-----------");
				}
				printf("\n");
			}
			
			do {
				if (jogador == 1) {
			        printf("%s - Digite a posicao desejada: ", jogadores[0].nome);
			        
			    } else {
			        printf("%s - Digite a posicao desejada: ", jogadores[1].nome);
			    }

			    scanf("%d", &posicao);
			    fflush(stdin);
			    
			    linha = (posicao - 1) / 3;
			    coluna = (posicao - 1) % 3;
			
			    if (posicao < 1 || posicao > 9 || jogoVelha[linha][coluna] != ' ') {
			        printf("Posicao invalida. Por favor, escolha outra posicao.\n");
			    }
			    
			} while(posicao < 1 || posicao > 9 || jogoVelha[linha][coluna] != ' ' ) ;
			
			switch(posicao) {
				case 1:
					jogoVelha[0][0] = (jogador == 1) ? 'X' : 'O';
					break;

				case 2:
					jogoVelha[0][1] = (jogador == 1) ? 'X' : 'O';
					break;

				case 3:
					jogoVelha[0][2] = (jogador == 1) ? 'X' : 'O';
					break;

				case 4:
					jogoVelha[1][0] = (jogador == 1) ? 'X' : 'O';
					break;

				case 5:
					jogoVelha[1][1] = (jogador == 1) ? 'X' : 'O';
					break;

				case 6:
					jogoVelha[1][2] = (jogador == 1) ? 'X' : 'O';
					break;

				case 7:
					jogoVelha[2][0] = (jogador == 1) ? 'X' : 'O';
					break;

				case 8:
					jogoVelha[2][1] = (jogador == 1) ? 'X' : 'O';
					break;

				case 9:
					jogoVelha[2][2] = (jogador == 1) ? 'X' : 'O';
					break;
			}
			
			jogador = (jogador == 1) ? 2 : 1;
			jogadas++;
			
			if(jogoVelha[0][0] == 'O' && jogoVelha[0][1] == 'O' && jogoVelha[0][2] == 'O' || 
			   jogoVelha[1][0] == 'O' && jogoVelha[1][1] == 'O' && jogoVelha[1][2] == 'O' ||
			   jogoVelha[2][0] == 'O' && jogoVelha[2][1] == 'O' && jogoVelha[2][2] == 'O') {
			   	system("cls");
				printf("\n\t----PARABENS JOGADOR 2 VOCE VENCEU----\n");
				pontuacaoJogadorDois ++;
			   	ganhou = 1;
			}
			
			if(jogoVelha[0][0] == 'X' && jogoVelha[0][1] == 'X' && jogoVelha[0][2] == 'X' || 
			   jogoVelha[1][0] == 'X' && jogoVelha[1][1] == 'X' && jogoVelha[1][2] == 'X' ||
			   jogoVelha[2][0] == 'X' && jogoVelha[2][1] == 'X' && jogoVelha[2][2] == 'X') {
			   	system("cls");
			    printf("\n\t----PARABENS JOGADOR 1 VOCE VENCEU----\n");				
				pontuacaoJogadorUm ++;
			   	ganhou = 1;
			}

			if(jogoVelha[0][0] == 'O' && jogoVelha[1][0] == 'O' && jogoVelha[2][0] == 'O' || 
			   jogoVelha[0][1] == 'O' && jogoVelha[1][1] == 'O' && jogoVelha[2][1] == 'O' ||
			   jogoVelha[0][2] == 'O' && jogoVelha[1][2] == 'O' && jogoVelha[2][2] == 'O') {
			   	system("cls");
				printf("\n\t----PARABENS JOGADOR 2 VOCE VENCEU----\n");
				pontuacaoJogadorDois ++;
				ganhou = 1;
		 	}
			if(jogoVelha[0][0] == 'X' && jogoVelha[1][0] == 'X' && jogoVelha[2][0] == 'X' || 
			   jogoVelha[0][1] == 'X' && jogoVelha[1][1] == 'X' && jogoVelha[2][1] == 'X' ||
			   jogoVelha[0][2] == 'X' && jogoVelha[1][2] == 'X' && jogoVelha[2][2] == 'X') {
			   	system("cls");
			   	printf("\n\t----PARABENS JOGADOR 1 VOCE VENCEU----\n");
				pontuacaoJogadorUm ++;
			   	ganhou = 1;
			}
			if(jogoVelha[0][0] == 'O' && jogoVelha[1][1] == 'O' && jogoVelha[2][2] == 'O') {
				system("cls");
				printf("\n\t----PARABENS JOGADOR 2 VOCE VENCEU----\n");
				pontuacaoJogadorDois ++;
				ganhou = 1;
			}
			if(jogoVelha[0][0] == 'X' && jogoVelha[1][1] == 'X' && jogoVelha[2][2] == 'X') {
				system("cls");
				printf("\n\t----PARABENS JOGADOR 1 VOCE VENCEU----\n");
				pontuacaoJogadorUm ++;
				ganhou = 1;
			}
			if(jogoVelha[0][2] == 'O' && jogoVelha[1][1] == 'O' && jogoVelha[2][0] == 'O') {
				system("cls");
				printf("\n\t----PARABENS JOGADOR 2 VOCE VENCEU----\n");
				pontuacaoJogadorDois ++;
				ganhou = 1;
			}
			if(jogoVelha[0][2] == 'X' && jogoVelha[1][1] == 'X' && jogoVelha[2][0] == 'X') {
				system("cls");
				printf("\n\t----PARABENS JOGADOR 1 VOCE VENCEU----\n");
				pontuacaoJogadorUm ++;
				ganhou = 1;
			}
			
		} while(ganhou == 0 && jogadas < 9);
		
		if(ganhou == 0) {
			printf("\nO JOGO FINALIZOU SEM GANHADORES!!\n");
		}
		
		printf("\nDigite 1 para revanche:");
		printf("\nDigite 0 para finalizar: \n");  
		scanf("%d", &opcao);
			
	} while(opcao == 1);

	system("cls");
	printf(" ----- Placar Final: -----\n");
	printf("Jogador 1: %d\n", pontuacaoJogadorUm);
	printf("Jogador 2: %d\n", pontuacaoJogadorDois);
	printf("Digite 1 para voltar ao menu: \n");

	fflush(stdin);
	scanf("%d", &opcao);
	
	if(opcao == 1) {
		system("cls");
		pontuacaoJogadorUm = 0;
		pontuacaoJogadorDois = 0;
		
		main();
	} else{
		system("cls");
		printf("Obrigado por jogar! ");
		exit;
	}
	
}

void instrucoes() {
	int opcao;
	
	do{
		system("cls");
		printf("Para jogar utilize os numeros do teclado.\n");
		printf("Cada numero corresponde a uma posicao.\n" );
		printf("                 |                 |                \n");
		printf("        1        |        2        |        3       \n");
		printf("                 |                 |                \n");
		printf("-----------------|-----------------|----------------\n");
		printf("                 |                 |                \n");
		printf("        4        |        5        |        6       \n");
		printf("                 |                 |                \n");
		printf("-----------------|-----------------|----------------\n");
		printf("                 |                 |                \n");
		printf("        9        |        8        |        9       \n");
		printf("                 |                 |                \n");
		printf("\n\nDigite 1 para voltar ao menu: ");
		scanf("%d", &opcao);
		
		if(opcao == 1){
			system("cls");
			main();
		}
	}while(opcao != 1);
}



int main() {
	int opcao;
	
	printf("\t####BEM VINDO AO JOGO DA VELHA ####\n\n");
	printf("01 - Iniciar o jogo.");
	printf("\n02 - Instrucoes.");
	printf("\n03 - Sair.");
	printf("\nESCOLHA A OPCAO: ");
	scanf("%d", &opcao);
	
	switch(opcao) {
		
		case 1:
			jogo();
			break;
		case 2:
			instrucoes();
			break;
		case 3:
			abort();
			break;
		default:
		printf("Opcao invalida!\n");
		break;
	}	
}