#include <stdio.h>
#include <string.h>
int main (){
	int n;
	char afazer[20][51];
	char andamento[20][51];
	char concluido[40][51];
	
	printf("===========================================\n");
	printf("Organizacao de Atividades:\n");
	printf("1: Cadastrar atividade.\n");
	printf("2: Listar atividades.\n");
	printf("3: Movimentar atividades.\n");
	printf("4: Consultar quantidade de atividades.\n");
	printf("5: Buscar atividade.\n");
	printf("6: Sair.\n");
	printf("===========================================\n");
	printf("Informe o que deseja fazer: ");
	do{
		scanf("%d", &n);
		switch (n){
			case 1: 
				printf("===========================================\n");
				printf("CADASTRO DE ATIVIDADES\n");
				printf("===========================================\n");
				printf("Quantas atividades deseja registrar? ");
				int n, i;
				scanf("%d", &n);
				getchar();
				
				break;
			case 2:
				printf("===========================================\n");
				printf("LISTA DE ATIVIDADES\n");      
				printf("===========================================\n");
				printf("Quantas atividades deseja registrar? ");
				
		}
		if(n == 6){
			printf("Encerrando programa...");
			return 0;
		}
		if(n > 6 || n < 1){
			while(n > 6 || n < 1){
				printf("Selecao de opcao inexistente, por favor tente novamente: ");
				scanf("%d", &n);
				
			}
		}
		printf("Informe o que deseja fazer agora: ");
	}while(n != 6);
}
