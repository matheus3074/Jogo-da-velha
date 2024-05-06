#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>


typedef struct {
	char nome[50];
}Jogador;

void jogo() {
	Jogador jogadores[2];
	int i, jogador, ganhou, jogadas, l, c, linha, coluna, opcao, posicao,validarPosicao;
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
	

	for(i = 0; i < 2; i++){
		system("cls");
		fflush(stdin);
		printf("Informe o nome do jogador: ");
		gets(jogadores[i].nome);
	}

	do{
		system("cls");
		jogador = 1;
		ganhou = 0;
		jogadas = 0;
		
		
		//incicializar jogo
		for(l = 0; l < 3; l++){
			for(c = 0; c < 3; c++){
				jogoVelha[l][c] = ' ';
			}
		}
		do{
			system("cls");
			
			//imprimir jogo
			for(l = 0; l < 3; l++){
				for(c = 0; c < 3; c++){
					if(c == 0){
						printf("\t");
					}
					if(jogoVelha[l][c] != ' '){
                        printf(" %c ", jogoVelha[l][c]);
                    }else{
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
			
			
			do{
				if (jogador == 1) {
			        printf("%s - Digite a posicao desejada: ", jogadores[0].nome);
			        
			    } else {
			        printf("%s - Digite a posicao desejada: ", jogadores[1].nome);
			    }
			    scanf("%d", &posicao);
			    fflush(stdin);
			    
			    // Calcular linha e coluna baseado na posição escolhida
			    linha = (posicao - 1) / 3;
			    coluna = (posicao - 1) % 3;
			
			    // Verificar se a posição já foi escolhida antes
			    if (posicao < 1 || posicao > 9 || jogoVelha[linha][coluna] != ' ' && !posicao >= 1 && !posicao <= 9) {
			        printf("Posicao invalida. Por favor, escolha outra posicao.\n");
			    }
			    
			} while (posicao < 1 || posicao > 9 || jogoVelha[linha][coluna] != ' ' ) ;
			
		
			
			switch(posicao){
				case 1:
					if(jogador == 1){
						jogoVelha[0][0] = 'X'; 
						jogador++;
					}else{
						jogoVelha[0][0] = 'O';
						jogador--;
					}
					break;
				case 2:
					if(jogador == 1){
						jogoVelha[0][1] = 'X'; 
						jogador++;
					}else{
						jogoVelha[0][1] = 'O';
						jogador--;
					}
					break;
				case 3:
					if(jogador == 1){
						jogoVelha[0][2] = 'X'; 
						jogador++;
					}else{
						jogoVelha[0][2] = 'O';
						jogador--;
					}
					break;
				case 4:
					if(jogador == 1){
						jogoVelha[1][0] = 'X'; 
						jogador++;
					}else{
						jogoVelha[1][0] = 'O';
						jogador--;
					}
					break;
				case 5:
					if(jogador == 1){
						jogoVelha[1][1] = 'X'; 
						jogador++;
					}else{
						jogoVelha[1][1] = 'O';
						jogador--;
					}
					break;
				case 6:
					if(jogador == 1){
						jogoVelha[1][2] = 'X'; 
						jogador++;
					}else{
						jogoVelha[1][2] = 'O';
						jogador--;
					}
					break;
				case 7:
					if(jogador == 1){
						jogoVelha[2][0] = 'X'; 
						jogador++;
					}else{
						jogoVelha[2][0] = 'O';
						jogador--;
					}
					break;
				case 8:
					if(jogador == 1){
						jogoVelha[2][1] = 'X'; 
						jogador++;
					}else{
						jogoVelha[2][1] = 'O';
						jogador--;
					}
					break;
				case 9:
					if(jogador == 1){
						jogoVelha[2][2] = 'X'; 
						jogador++;
					}else{
						jogoVelha[2][2] = 'O';
						jogador--;
					}
					break;
			}
			
			jogadas++;
			
			//ganhou por linha
			if(jogoVelha[0][0] == 'O' && jogoVelha[0][1] == 'O' && jogoVelha[0][2] == 'O' || 
			   jogoVelha[1][0] == 'O' && jogoVelha[1][1] == 'O' && jogoVelha[1][2] == 'O' ||
			   jogoVelha[2][0] == 'O' && jogoVelha[2][1] == 'O' && jogoVelha[2][2] == 'O'){
			   	printf("\n\t----PARABÉNS JOGADOR 1 VOCÊ VENCEU----\n");
			   	ganhou = 1;
			}
			
			if(jogoVelha[0][0] == 'X' && jogoVelha[0][1] == 'X' && jogoVelha[0][2] == 'X' || 
			   jogoVelha[1][0] == 'X' && jogoVelha[1][1] == 'X' && jogoVelha[1][2] == 'X' ||
			   jogoVelha[2][0] == 'X' && jogoVelha[2][1] == 'X' && jogoVelha[2][2] == 'X'){
			   	printf("\n\t----PARABÉNS JOGADOR 2 VOCÊ VENCEU----\n");
			   	ganhou = 1;
			}
				
			//GANHOU POR COLUNA
			if(jogoVelha[0][0] == 'O' && jogoVelha[1][0] == 'O' && jogoVelha[2][0] == 'O' || 
			   jogoVelha[0][1] == 'O' && jogoVelha[1][1] == 'O' && jogoVelha[2][1] == 'O' ||
			   jogoVelha[0][2] == 'O' && jogoVelha[1][2] == 'O' && jogoVelha[2][2] == 'O'){
			   	printf("\n\t----PARABÉNS JOGADOR 1 VOCÊ VENCEU----\n");
			   	ganhou = 1;
			}
			
			if(jogoVelha[0][0] == 'X' && jogoVelha[1][0] == 'X' && jogoVelha[2][0] == 'X' || 
			   jogoVelha[0][1] == 'X' && jogoVelha[1][1] == 'X' && jogoVelha[2][1] == 'X' ||
			   jogoVelha[0][2] == 'X' && jogoVelha[1][2] == 'X' && jogoVelha[2][2] == 'X'){
			   	printf("\n\t----PARABÉNS JOGADOR 2 VOCÊ VENCEU----\n");
			   	ganhou = 1;
			}
			
			//GANHOU POR DIAGONAL 1
			if(jogoVelha[0][0] == 'O' && jogoVelha[1][1] == 'O' && jogoVelha[2][2] == 'O'){
				printf("\n\t----PARABÉNS JOGADOR 1 VOCÊ VENCEU----\n");
				ganhou = 1;
			}
			
			if(jogoVelha[0][0] == 'X' && jogoVelha[1][1] == 'X' && jogoVelha[2][2] == 'X'){
				printf("\n\t----PARABÉNS JOGADOR 2 VOCÊ VENCEU----\n");
				ganhou = 1;
			}
			
			//GANHOU POR DIAGONAL 2
			if(jogoVelha[0][2] == 'O' && jogoVelha[1][1] == 'O' && jogoVelha[2][0] == 'O'){
				printf("\n\t----PARABÉNS JOGADOR 1 VOCÊ VENCEU----\n");
				ganhou = 1;
			}
			
			if(jogoVelha[0][2] == 'X' && jogoVelha[1][1] == 'X' && jogoVelha[2][0] == 'X'){
				printf("\n\t----PARABÉNS JOGADOR 2 VOCÊ VENCEU----\n");
				ganhou = 1;
			}
			
		
		}while(ganhou == 0 && jogadas < 9);
		
		if(ganhou == 0){
			printf("\nO JOGO FINALIZOU SEM GANHADORES!!\n");
		}
		printf("\nDigite 1 para jogar novamente: \n");  
		scanf("%d", &opcao);
			
	}while(opcao == 1);	
	
}

void instrucoes() {
	system("cls");
	printf("Nenhuma instrucao");
}

int main(){
	setlocale(LC_ALL, "");
	int opcao;
	
	printf("\t####BEM VINDO AO JOGO DA VELHA####\n\n");
	printf("01 - Iniciar o jogo.");
	printf("\n02 - Instrucoes.");
	printf("\n03 - Sair.");
	printf("\nESCOLHA A OPCAO: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		
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
		printf("Opção inválida!\n");
		break;
		}	
}