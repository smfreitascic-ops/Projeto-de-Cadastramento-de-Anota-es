#include <stdio.h>
#include <string.h>
// verifica se a atividade eh vazia ou so de espaco
int vaziaespaco(char str[]){
	int i;
	if (strlen(str) == 0){
		return 1;
	}
	for(i = 0; str[i] != '\0'; i++){
		if(str[i] != ' ' && str[i] != '\t'){
			return 0; // se eh zero ent nn eh so de espaco ou vazia
		}
	}
	return 1;
}

//verifica se a atividade q se quer cadastrar ja existe
int repetido(char matriz[][51], int qtd, char str[]){
	int i;
	for(i = 0; i < qtd; i++){
		if(strcmp(matriz[i], str) == 0){
			return 1;
		}
	}
	return 0; // se eh 0 ent nn ta repetido
}

int main (){
	int opcao;
	char afazer[20][51];
	char andamento[20][51];
	char concluido[40][51];
	char termo_busca[51];
	int qtd_afazer = 0;
    int qtd_andamento = 0;
    int qtd_concluido = 0;
	int i, move, opc, qtd_cadastro,qtd_total;
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
		scanf("%d", &opcao);
		switch (opcao){
			case 1: 
				printf("===========================================\n");
				printf("CADASTRO DE ATIVIDADES\n");
				printf("===========================================\n");
				printf("Quantas atividades deseja registrar? ");
				
				scanf("%d", &qtd_cadastro);
				getchar();
				printf ("Insira o nome das atividades: \n");
				for(i = 0; i < qtd_cadastro; i++) {
                    if(qtd_afazer < 20) {
                    	char temp[51];
                    	int valido = 0;
                        do{
                        	fgets(temp, 51, stdin);
                        	temp[strcspn(temp, "\n")] = '\0';
                        	if (vaziaespaco(temp)){
                        		printf("Atividade sem nome, tente novamente: ");
                        		valido = 0;
							}else if(repetido(afazer, qtd_afazer, temp)){
								printf("Atividade repetida, tente novamente: ");
								valido = 0;
							}else{
								valido = 1;
							}
						}while(valido == 0);
						strcpy(afazer[qtd_afazer], temp);
						qtd_afazer++;
                    } else {
                        printf("Lista de A Fazer cheia!\n");
                        break;
                    }
                }
				break;
			case 2:
				printf("===========================================\n");
				printf("LISTA DE ATIVIDADES\n");      
				printf("===========================================\n");
			
				printf("AFAZER:\n");
                for(i = 0; i < qtd_afazer; i++) {
                    printf("  %d. %s\n", i + 1, afazer[i]);
                }
                
                printf("\nEM ANDAMENTO:\n");
                for(i = 0; i < qtd_andamento; i++) {
                    printf("  %d. %s\n", i + 1, andamento[i]);
                }
                
                printf("\nCONCLUIDO:\n");
                for(i = 0; i < qtd_concluido; i++) {
                    printf("  %d. %s\n", i + 1, concluido[i]);
                }
                break;
			case 3:
				printf("===========================================\n");
				printf("MOVIMENTAR ATIVIDADES\n");      
				printf("===========================================\n");
				printf("O que deseja mover?\n");
				printf("Opcao 1: AFAZER -> ANDAMENTO\n");
				printf("Opcao 2: ANDAMENTO -> CONCLUIDO\n");
			
				scanf("%d",&opc);
				switch(opc){
					case 1: 
						printf("Qual atividade deseja mover?\n");
						for(i=0;i<qtd_afazer;i++) {
						if (i==0){
							printf("AFAZER:\n");
						}
						printf("%d.%s\n",i+1,afazer[i]);
						}
						scanf("%d",&move);
						if(move >= 0 && move <=qtd_afazer) {
                           
                            strcpy(andamento[qtd_andamento], afazer[move-1]);
                            qtd_andamento++;
                            
                         
                            for(i = move-1; i < qtd_afazer - 1; i++) {
                                strcpy(afazer[i], afazer[i + 1]);
                            }
                            qtd_afazer--; 
                            
                            printf("MOVIMENTACAO CONCLUIDA\n");
                        } else {
                            printf("Opcao invalida.\n");
                        }
                        break;
                    case 2:
                    	printf("Qual atividade deseja mover?\n");
						for(i=0;i<qtd_andamento;i++) {
						if (i==0){
							printf("ANDAMENTO:\n");
						}
						printf("%d.%s\n",i+1,andamento[i]);
						}
						scanf("%d",&move);
						if(move >= 0 && move <=qtd_andamento) {
                           
                            strcpy(concluido[qtd_concluido], andamento[move-1]);
                            qtd_concluido++;
                            
                         
                            for(i = move-1; i < qtd_andamento - 1; i++) {
                                strcpy(andamento[i], andamento[i + 1]);
                            }
                            qtd_andamento--; 
                            
                            printf("MOVIMENTACAO CONCLUIDA\n");
                        } else {
                            printf("Opcao invalida.\n");
                        }
                        break;
                    	
					break;
						
				}
				break;
			case 4:
				printf("===========================================\n");
				printf("QUANTIDADE DE ATIVIDADES\n");      
				printf("===========================================\n");
				qtd_total=qtd_afazer + qtd_andamento + qtd_concluido;
				printf("A fazer: %d\n",qtd_afazer);
				printf("Em andamento: %d\n",qtd_andamento);
				printf("Concluido: %d\n\n",qtd_concluido);
				printf("Total: %d\n",qtd_total);
				break;
				
	     	case 5:
	     		printf("===========================================\n");
				printf("BUSCA DE ATIVIDADE\n");      
				printf("===========================================\n");
	     		printf("Busque a atividade: ");
			    getchar();
			    fgets(termo_busca, 51, stdin);
			    termo_busca[strcspn(termo_busca, "\n")] = '\0';
			   
				int achou = 0;
				printf("\n---RESULTADOS DA BUSCA---\n");
				
				for(i = 0; i < qtd_afazer; i++) {
					if(strstr(afazer[i], termo_busca) != NULL) {
						printf("Atividade encontrada!\n\n");
						printf("Etapa atual:\n");
	                    printf("A fazer\n\n");
	                achou = 1;	
					}
				}
			
				for(i = 0; i < qtd_andamento; i++) {
						if(strstr(andamento[i], termo_busca) != NULL) {
							printf("Atividade encontrada!\n\n");
							printf("Etapa atual:\n");
		                    printf("Andamento\n\n");
		                achou = 1;
		            }
		        }
         
				for(i = 0; i < qtd_concluido; i++) {
					if(strstr(concluido[i], termo_busca) != NULL) {
						printf("Atividade encontrada!\n\n");
						printf("Etapa atual:\n");
		                printf("Concluido\n\n");
		            	achou = 1;  
		            }
		     	}
     	
		     	if(achou == 0){
		     		printf("Atividade nao encontrada \n\n");
				 }
				 break;
		}
			
		if(opcao == 6){
			printf("Encerrando programa...");
			return 0;
		}
		if(opcao > 6 || opcao < 1){
			while(opcao > 6 || opcao < 1){
				printf("Selecao de opcao inexistente, por favor tente novamente: ");
				scanf("%d", &opcao);
				
			}
		}
		printf("Informe o que deseja fazer agora: ");
	}while(opcao != 6);
}
