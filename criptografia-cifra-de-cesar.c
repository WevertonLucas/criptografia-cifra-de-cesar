#include <stdio.h>
#include <string.h>
#include <locale.h>

char opcao,tabela[94],mensagem[128],texto_final[128],chave[11];
int tamanho_mensagem,tamanho_chave,i,j;

void carregatabela(){
	for(i=0;i<94;i++){
		tabela[i] = '!' + i;
	}
}

void criptografar(){
	fflush(stdin);
	printf("Digite a mensagem a ser criptografada: ");
	scanf("%[^\n]s",&mensagem);
	
	tamanho_mensagem = strlen(mensagem);
	
	if(tamanho_mensagem <= 128){
		fflush(stdin);
		printf("Digite a chave: ");
		scanf("%s",&chave);
		
		tamanho_chave = strlen(chave);
		
		if(tamanho_chave <= 11){
			if(strcmp(chave,"impeachment") == 0){
				for (i=0;i<=tamanho_mensagem;i++){
					for (j=0;j<=94;j++){
						if (mensagem [i] == ' '){
							texto_final[i] = '!';
						}
						if (mensagem[i]==tabela[j]){
							texto_final[i] = tabela[j + 3];
						}
					}
				}
				
				printf("\nTexto Criptografado: ");
				for (i=0;i<=tamanho_mensagem-1;i++){
					printf("%c",texto_final[i]);
				}
			}else{
				printf("Chave incorreta.");
			}
		}else{
			printf("A chave deve ter no máximo 11 caracteres.\n");
		}
		printf("\n\n");
	}else{
		printf("Mensagem deve ter no máximo 128 caracteres.\n\n");
	}
	printf("\n\n");
}

void descriptografar(){
	fflush(stdin);
	printf("Digite a mensagem a ser descriptografada: ");
	scanf("%[^\n]s",&mensagem);
	
	tamanho_mensagem = strlen(mensagem);
	
	if(tamanho_mensagem <= 128){
		fflush(stdin);
		printf("Digite a chave: ");
		scanf("%s",&chave);
		
		tamanho_chave = strlen(chave);
		
		if(tamanho_chave <= 11){
			if(strcmp(chave,"impeachment") == 0){
				for (i=0;i<=tamanho_mensagem;i++){
					for (j=0;j<=94;j++){
						if (mensagem [i] == '!'){
							texto_final[i] = ' ';
						}
						if (mensagem[i]==tabela[j]){
							texto_final[i] = tabela[j - 3];
						}
					}
				}
				
				printf("\nTexto Descriptografado: ");
				for (i=0;i<=tamanho_mensagem-1;i++){
					printf("%c",texto_final[i]);
				}
			}else{
				printf("Chave incorreta.");
			}
		}else{
			printf("A chave deve ter no máximo 11 caracteres.\n");
		}
		printf("\n\n");
	}else{
		printf("Mensagem deve ter no máximo 128 caracteres.\n\n");
	}
	printf("\n\n");
}

void menu(){
	do{
		printf("==========================================\n");
		printf("Programa de Criptografia e Descriptografia\n");
		printf("==========================================\n");
		
		printf("\nOBS: Este programa não aceita caracteres acentuados.\n\n");
		
		printf("Escolha uma opção \n");
		printf("1- Criptografar \n2- Descriptografar \n3- Sair do Programa \n");
		printf("Digite o número da opção desejada: ");
		scanf(" %c",&opcao);
		
		switch(opcao){
			case '1':
				criptografar();
				break;
			case '2':
				descriptografar();
				break;
			case '3':
				printf("Programa encerrado.");
				break;
			default:
				printf("\nOpção inválida! Tente novamente. \n\n");
				printf("\n\n");	
				break;
		}
	}while(opcao != '3');
}
	
int main(){
	
	setlocale(LC_ALL,"portuguese");
	
	carregatabela();
	menu();
	
	getchar();
	return 0;
}
