#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
	//estrutura de dados
	char jogo[3][3];
	int l, c, linha, coluna, jogador, ganhou, jogadas, opcao;
	
	setlocale(LC_ALL,"");
	
	do{
		jogador = 1;
		ganhou = 0;
		jogadas = 0;
		//incicializar jogo
		for(l = 0; l < 3; l++){
			for(c = 0; c < 3; c++){
				jogo[l][c] = ' ';
			}
		}
		do{
			system("cls");
			//imprimir jogo
			printf("\n\n\t 0   1   2\n\n");
			for(l = 0; l < 3; l++){
				for(c = 0; c < 3; c++){
					if(c == 0){
						printf("\t");
					}
					printf(" %c ", jogo[l][c]);
					if(c < 2) {
						printf("|");
					}
					if(c == 2) {
						printf(" %d", l);
					}
				}
				if(l < 2) {
					printf("\n\t-----------");
				}
				printf("\n");
			}
			
			//ler coordenadas
			do{
			printf("JOGADOR %d - Digite a linha que deseja jogar: ", jogador);
			scanf("%d", &linha);
			printf("JOGADOR %d - Digite a coluna que deseja jogar: ", jogador);
			scanf("%d", &coluna);
			}while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');
			
			//salvar coordenadas
			if(jogador == 1){
				jogo[linha][coluna] = 'O'; 
				jogador++;
			}else{
				jogo[linha][coluna] = 'X';
				jogador--;
			}
			jogadas++;
			
			//ganhou por linha
			if(jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O' || 
			   jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O' ||
			   jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O'){
			   	printf("\n\t----PARABÉNS JOGADOR 1 VOCÊ VENCEU----\n");
			   	ganhou = 1;
			}
			
			if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' || 
			   jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
			   jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){
			   	printf("\n\t----PARABÉNS JOGADOR 2 VOCÊ VENCEU----\n");
			   	ganhou = 1;
			}
				
			//GANHOU POR COLUNA
			if(jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O' || 
			   jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O' ||
			   jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O'){
			   	printf("\n\t----PARABÉNS JOGADOR 1 VOCÊ VENCEU----\n");
			   	ganhou = 1;
			}
			
			if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' || 
			   jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
			   jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'){
			   	printf("\n\t----PARABÉNS JOGADOR 2 VOCÊ VENCEU----\n");
			   	ganhou = 1;
			}
			
			//GANHOU POR DIAGONAL 1
			if(jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O'){
				printf("\n\t----PARABÉNS JOGADOR 1 VOCÊ VENCEU----\n");
				ganhou = 1;
			}
			
			if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
				printf("\n\t----PARABÉNS JOGADOR 2 VOCÊ VENCEU----\n");
				ganhou = 1;
			}
			
			//GANHOU POR DIAGONAL 2
			if(jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O'){
				printf("\n\t----PARABÉNS JOGADOR 1 VOCÊ VENCEU----\n");
				ganhou = 1;
			}
			
			if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
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