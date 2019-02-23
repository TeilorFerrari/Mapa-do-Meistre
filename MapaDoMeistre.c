#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

	int x;
	int y;

	scanf("%d", &x);
	scanf("%d", &y);
	int aux = y;
	y=x;
	x=aux;
	char matriz[x][y];
	int matrizAux[x][y];
	int i = 0;
	int j = 0;
	int tamanho=0;

	for(int k = 0; k< x; k++){
		for (int m = 0; m < y; ++m){
			scanf("%c", &matriz[k][m]);
			if (matriz[k][m] == '\n'){
				m--;
			}
		}
	}	

	for(int k = 0; k< x; k++){
		for (int m = 0; m < y; ++m)
			matrizAux[k][m] = -1;
	}
	while(1){

		if(matriz[i][j] == '>'){
			if(matrizAux[i][j] == 1){
				printf("!\n");
				return 0;
			}else{
				matrizAux[i][j] = 1;
				j++;
				if(matriz[i][j] == '*'){
					printf("*");
					return 0;
				}else if(matriz[i][j] != '^' && matriz[i][j] != 'v' && matriz[i][j] != '<'){
					if(i < x && j < y && i >= 0 && j >= 0){
						if(matriz[i][j] == '.'){				//anda para a direita
							while (matriz[i][j] == '.'){
								j++;
							}	
						}
					}
				}
			}
		}else if(matriz[i][j] == 'v'){
			if(matrizAux[i][j] == 1){
				printf("!\n");
				return 0;
			}else{
				matrizAux[i][j] = 1;
				i++;
				if(matriz[i][j] == '*'){
					printf("*");
					return 0;
				}else if(matriz[i][j] != '^' && matriz[i][j] != '>' && matriz[i][j] != '<'){
					if(i < x && j < y && i >= 0 && j >= 0){
						if(matriz[i][j] == '.'){				//anda para baixo
							while (matriz[i][j] == '.'){
								i++;
								
							}
						
						}
					}
				}
			}
		}else if(matriz[i][j] == '^'){
			if(matrizAux[i][j] == 1){
				printf("!\n");
				return 0;
			}else{
				matrizAux[i][j] = 1;
				i--;
				if(matriz[i][j] == '*'){
					printf("*");
					return 0;
				}else if(matriz[i][j] != '>' && matriz[i][j] != 'v' && matriz[i][j] != '<'){
					if(i < x && j < y && i >= 0 && j >= 0){
						if(matriz[i][j] == '.'){				//anda para cima
							while (matriz[i][j] == '.'){
								i--;			
							}
						}
					}
				}
			}
		}else if(matriz[i][j] == '<'){
			if(matrizAux[i][j] == 1){
				printf("!\n");
				return 0;
			}else{
				matrizAux[i][j] = 1;
				j--;
				if(matriz[i][j] == '*'){
					printf("*");
					return 0;
				}else if(matriz[i][j] != '^' && matriz[i][j] != 'v' && matriz[i][j] != '>'){
					if(i < x && j < y && i >= 0 && j >= 0){
						if(matriz[i][j] == '.'){			//anda para a esquerda
							while (matriz[i][j] == '.'){
								j--;
							}
						}
					}
				}
			}
		}else if(matriz[i][j] == '*'){
			printf("*\n");
			exit(1);
		}else if ( i < 0 || i >= x || j >= y || j < 0){
			break;
		}
	}
	printf("!\n");
	return 0;

}