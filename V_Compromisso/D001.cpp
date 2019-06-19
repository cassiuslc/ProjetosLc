//Fucapi - Cassius Leon - Ra: 149339
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#define MAX 99       
using namespace std;
typedef struct{
	char data[10];
	int codigo;
	char titulo[80];
	char descricao[200];
}Comp;

typedef struct aux{
	Comp a;
	struct aux* proximo;
	struct aux* anterior;
}Elemento;

typedef struct{
	Elemento* inicio;
	Elemento* fim;
	int tam;
}Lista;

void iniciar(Lista* l){
	l->fim = NULL;
	l->inicio = NULL;
	l->tam = 0;	
}
int add(Lista *l,Comp c){
	//Alocar e Setar Dados
	Elemento *NewElem = (Elemento *) malloc(sizeof(Elemento));
	c.codigo = l->tam + 1;
	NewElem->a=c;
	//Inserir
	if(NewElem != NULL){//Verifica Alocacao do Novo Elemento
		if(l->tam==0){//Inserindo Lista Vazia
		l->inicio=NewElem;
		l->fim=NewElem;
		NewElem->anterior=NULL;
		NewElem->proximo=NULL;
		l->tam++;
		return 0;
		}else{//Inserindo no Meio
			Elemento *aux = l->inicio;
			for(;;){
				if(strcmp(aux->a.data,c.data)==1||strcmp(aux->a.data,c.data)==0){
					NewElem->anterior=aux->anterior;
					NewElem->proximo=aux;
					if(aux!=l->inicio)aux->anterior->proximo=NewElem;
					if(aux==l->inicio)l->inicio=NewElem;
					aux->anterior=NewElem;
					l->tam++;
					return 0;
				}else if(aux->proximo==NULL){
					NewElem->anterior=aux;
					NewElem->proximo=NULL;
					//aux->anterior->proximo=aux;
					aux->proximo=NewElem;
					l->fim=NewElem;
					l->tam++;
					return 0;
				}
			//Condicao de Parada
			if(aux->proximo==NULL)break;
			aux=aux->proximo;	
			}
			return 1;
		}
	}
	return 2;
}

int remove(Lista *l,int codigo){
	if(l->tam==0)return 1;//Verificar Vazio
	Elemento * aux;
	if(l->tam==1){
		if(l->inicio->a.codigo!=codigo)return 2;
		aux=l->inicio;
		l->inicio=NULL;
		l->fim==NULL;
		free(aux);
		l->tam=0;
		return 0;
	}else{
		int x;
		aux=l->inicio;
		for(x=0;x<l->tam;x++){
			if(aux->a.codigo==codigo){
				if(aux==l->inicio){//Removendo Inicio
				l->inicio=aux->proximo;
				aux->proximo->anterior=NULL;
				free(aux);	
				l->tam--;
				return 0;
				}
				if(aux==l->fim){//Removendo Fim
				l->fim=aux->anterior;
				aux->anterior->proximo=NULL;
				free(aux);
				l->tam--;
				return 0;																				
				}
				//Removendo Meio
					aux->anterior->proximo=aux->proximo;
					aux->proximo->anterior=aux->anterior;
					free(aux);
					l->tam--;
					return 0;
			}
		//Proximo
		aux=aux->proximo;
		}
		return 3;
	}


}
int **alocar(){//Alocando Matriz
	int i,**tela = (int **) calloc(2,sizeof(int*)); //Alocacao do ponteiro de matriz
	for(i =0 ; i<2;i++){
		tela[i] = (int *) calloc(2,sizeof(int));
	}tela[0][0]=1;
	return tela;
}

void t_Menu(int **tela){//Imprimindo a tela
	
	system("cls");//Limpar Tela
	if(tela[0][0]==1)system("color F9");
	if(tela[0][1]==1)system("color FD");
	if(tela[1][0]==1)system("color FC");
	if(tela[1][1]==1)system("color F4");
		printf("    |-|                                                                                      |-|\n");
		printf("    |-|                                                                                      |-|\n");
		printf("    |-|                   %s%s   Incluir   %s%s              %s%s    Listar    %s%s                  |-|\n",((tela[0][0]==1)?"|":" "),((tela[0][0]==1)?"|":" "),((tela[0][0]==1)?"|":" "),((tela[0][0]==1)?"|":" ")   ,((tela[0][1]==1)?"|":" "),((tela[0][1]==1)?"|":" "),((tela[0][1]==1)?"|":" "),((tela[0][1]==1)?"|":" "));
		printf("    |-|                   %s%s Compromisso %s%s              %s%s Compromissos %s%s                  |-|\n",((tela[0][0]==1)?"|":" "),((tela[0][0]==1)?"|":" "),((tela[0][0]==1)?"|":" "),((tela[0][0]==1)?"|":" ")   ,((tela[0][1]==1)?"|":" "),((tela[0][1]==1)?"|":" "),((tela[0][1]==1)?"|":" "),((tela[0][1]==1)?"|":" "));
		printf("    |-|                                                                                      |-|\n");
		printf("    |-|                                                                                      |-|\n");
		printf("    |-|                   %s%s   Excluir   %s%s              %s%s   Encerrar   %s%s                  |-|\n",((tela[1][0]==1)?"|":" "),((tela[1][0]==1)?"|":" "),((tela[1][0]==1)?"|":" "),((tela[1][0]==1)?"|":" ")   ,((tela[1][1]==1)?"|":" "),((tela[1][1]==1)?"|":" "),((tela[1][1]==1)?"|":" "),((tela[1][1]==1)?"|":" "));
		printf("    |-|                   %s%s Compromisso %s%s              %s%s   Programa   %s%s                  |-|\n",((tela[1][0]==1)?"|":" "),((tela[1][0]==1)?"|":" "),((tela[1][0]==1)?"|":" "),((tela[1][0]==1)?"|":" ")   ,((tela[1][1]==1)?"|":" "),((tela[1][1]==1)?"|":" "),((tela[1][1]==1)?"|":" "),((tela[1][1]==1)?"|":" "));
	  //printf("|-|   %i  %i                                                                               |-|\n",tela[0][0],tela[0][1]);
	  //printf("|-|   %i  %i                                                                               |-|\n",tela[1][0],tela[1][1]);
		printf("    |-|                                                                                      |-|\n");
		printf("    |-|                                                                                      |-|\n");
}

int **move(int ** tela){//Movimento do usuario
	int tecla;
	for(;;){
		
		tecla =  getch();
		if(tecla==13){
			if(tela[0][0]==1)tela[0][0]=2;
			if(tela[0][1]==1)tela[0][1]=2;
			if(tela[1][0]==1)tela[1][0]=2;
			if(tela[1][1]==1)tela[1][1]=2;
			return tela;
		}
		if(tecla==77||tecla==100||tecla==109||tecla==75||tecla==97||tecla==110){//Direita e Esquerda
			if(tela[0][0]==1){
				tela[0][0]=0; tela[0][1]=1;
				return tela;
			}
			if(tela[0][1]==1){
				tela[0][1]=0; tela[0][0]=1;
				return tela;
			}
			if(tela[1][0]==1){
				tela[1][0]=0; tela[1][1]=1;
				return tela;
			}
			if(tela[1][1]==1){
				tela[1][1]=0; tela[1][0]=1;
				return tela;
			}
		}
		if(tecla==72||tecla==119||tecla==80||tecla==115){//Cima
			if(tela[0][0]==1){
				tela[0][0]=0; tela[1][0]=1;
				return tela;
			}
			if(tela[0][1]==1){
				tela[0][1]=0; tela[1][1]=1;
				return tela;
			}
			if(tela[1][0]==1){
				tela[1][0]=0; tela[0][0]=1;
				return tela;
			}
			if(tela[1][1]==1){
				tela[1][1]=0; tela[0][1]=1;
				return tela;
			}
		}
	}
}

int **selecao (int ** tela,Lista *l){//Iniciando Acao da Tela
	if(tela[0][0]==2){//Acao 1
			system("cls");
			Comp b;
			b.codigo=l->tam+1;
			char t[80],dia[2],mes[2],ano[4];
			printf("|+| Incluir Compromisso\n");
			printf("\n    [+] Qual e o titulo do evento ?\n\n         R: ");
			//if(l->tam!=0)getchar();
			scanf("%[^\n]s",&b.titulo);
			strcpy(t,b.titulo);
			
			//Validar Data
			for(;;){
			//Dia
			printf("\n    [+] Certo, Quando e o evento ? (Digite somenta dia DD)\n\n         R: ");
				scanf("%s",&dia);
				if(atoi(dia)>0&&atoi(dia)<=9&&dia[0]!='0'){
				//ERRO
				system("cls");
				system("color CF");
				printf("|+| Incluir Compromisso\n");
				printf("\n    [+] Qual e o titulo do evento ?\n\n         R: %s",t);
				printf("\n\n    [+] Ocorreu um Erro de Validacao do Dia (Ex de dia: 0%s) !!!\n",dia);
				continue;	
				}
			//Mes
			system("cls");
			printf("|+| Incluir Compromisso\n");
			printf("\n    [+] Qual e o titulo do evento ?\n\n         R: %s",t);
			printf("\n\n    [+] Certo, Quando e o evento ? (Digite somente o mes MM)\n\n         R: %s/",dia);
				scanf("%s",&mes);
				if(atoi(mes)>0&&atoi(mes)<=9&&mes[0]!='0'){
				//ERRO
				system("cls");
				system("color CF");
				printf("|+| Incluir Compromisso\n");
				printf("\n    [+] Qual e o titulo do evento ?\n\n         R: %s",t);
				printf("\n\n    [+] Ocorreu um Erro de Validacao do Mes (Ex de Mes: 0%s) !!!\n",mes);
				continue;	
				}
			//Ano
			system("cls");
			printf("|+| Incluir Compromisso\n");
			printf("\n    [+] Qual e o titulo do evento ?\n\n         R: %s",t);
			printf("\n\n    [+] Certo, Quando e o evento ? (Digite somente o ano AAAA)\n\n         R: %s/%s/",dia,mes);
			if(/*Valida XXX9*/(atoi(ano)>0&&atoi(ano)<=9&&(ano[0]!='0'||ano[1]!='0'||ano[2]!='0')) || /*Valida XX99*/(atoi(ano)>10&&atoi(ano)<=99&&(ano[0]!='0'||ano[1]!='0')) || /*Valida X999*/(atoi(ano)>100&&atoi(ano)<=999&&ano[0]!='0')){
				//ERRO
				system("cls");
				system("color CF");
				printf("|+| Incluir Compromisso\n");
				printf("\n    [+] Qual e o titulo do evento ?\n\n         R: %s",t);
				printf("\n\n    [+] Ocorreu um Erro de Validacao do Ano (Ex de Ano: 0001) !!!\n");
				continue;	
				}
				scanf("%s",&ano);			
			//Valida Toda Data
				if(atoi(dia)>0&&atoi(dia)<30){
					if(atoi(mes)>0&&atoi(mes)<=12){
						if(atoi(ano)>0){
							strcpy(b.data,ano);
							strcat(b.data,"-");
							strcat(b.data,mes);
							strcat(b.data,"-");
							strcat(b.data,dia);
							break;
						}
					}	
				}
			//ERRO
			system("cls");
			system("color CF");
			printf("|+| Incluir Compromisso\n");
			printf("\n    [+] Qual e o titulo do evento ?\n\n         R: %s",t);
			printf("\n\n    [+] Ocorreu um Erro de Validacao da Data !!!\n");	
			}
			system("color F9");
			printf("\n    [+] Ok, sobre o que e o evento ?\n\n         R: ");
			getchar();
			scanf("%[^\n]s",&b.descricao);
			strcpy(b.titulo,t);
			cout << "\n    [+] Muito bem, Voce tem um evento chamado " << b.titulo; 
			printf(" em %c%c/%c%c/%c%c\n",b.data[8],b.data[9],b.data[5],b.data[6],b.data[2],b.data[3]);
			printf("\n        Sobre: %s\n",b.descricao);
			if(add(l,b)==0){
				system("color 3F");
				printf("\n\n    [+] Compromisso adicionado com sucesso. . . .\n\n");
			}else{
				system("color CF");
				printf("\n\n    [+] Ocorreu um Erro na adicao do compromisso. . . .\n\n");
			}
			//Voltar	
			printf("\n    [+] Pressione qualquer tecla para voltar ao menu. . . . ");
			getchar();
			getchar();
			tela[0][0]=1;
			t_Menu(tela);
			return tela;
		}
	if(tela[0][1]==2){//Acao 2
			Elemento *aux = l->inicio;
			int tecla,M[4]={1,0,0,0},mtam=1;
			if(l->tam==0){
				system("cls");
			system("color CF");
			printf("|-|                                                                      |-|\n");
			printf("|-|               Voce nao tem compromisso. . .                          |-|\n");
			printf("|-|                                                                      |-|\n\n\n\n");
			
			printf("\n    [+] Pressione qualquer tecla para voltar ao menu. . . . ");
			getchar();
			}else{
			system("cls");
			system("color F5");
			printf("|-|                                                                                                |-|\n",M[0],M[1],M[2],M[3]);
			printf("|-|                        Visualizando Compromisso  - (%s%i/%s%i)                                  |-|\n",(mtam<10)?"0":"",mtam,(l->tam<10)?"0":"",l->tam);
			printf("|-|                                                                                             |-|\n");
			printf("                                [S] Titulo: %s\n\n",aux->a.titulo);
			printf("                                [S] Data: %s\n\n",aux->a.data);
			printf("                                [S] Descricao: %s\n\n",aux->a.descricao);
		    printf("    %s Compromisso %s   %s   Proximo   %s   %s   <---  %s   %s   Buscar  %s\n",(M[0]==1)?"|-|":"   ",(M[0]==1)?"|-|":"   ",(M[1]==1)?"|-|":"   ",(M[1]==1)?"|-|":"   ",(M[2]==1)?"|-|":"   ",(M[2]==1)?"|-|":"   ",(M[3]==1)?"|-|":"   ",(M[3]==1)?"|-|":"   ");
		    printf("    %s   Anterior  %s   %s Compromisso %s   %s  Voltar %s   %s  Por Data %s\n",(M[0]==1)?"|-|":"   ",(M[0]==1)?"|-|":"   ",(M[1]==1)?"|-|":"   ",(M[1]==1)?"|-|":"   ",(M[2]==1)?"|-|":"   ",(M[2]==1)?"|-|":"   ",(M[3]==1)?"|-|":"   ",(M[3]==1)?"|-|":"   ");
            
			for(;;){
			if(tecla!=224&&(tecla==13||tecla==77||tecla==75)){
				if(M[0]==0&&M[1]==0&&M[2]==0&&M[3]==0)M[0]=1;
			system("cls");
			system("color F5");
			printf("|-|                                                                                                |-|\n",M[0],M[1],M[2],M[3]);
			printf("|-|                        Visualizando Compromisso  - (%s%i/%s%i)                                  |-|\n",(mtam<10)?"0":"",mtam,(l->tam<10)?"0":"",l->tam);
			printf("|-|                                                                                             |-|\n");
			printf("                                [S] Titulo: %s\n\n",aux->a.titulo);
			printf("                                [S] Data: %s\n\n",aux->a.data);
			printf("                                [S] Descricao: %s\n\n\n\n",aux->a.descricao);
		    printf("    %s Compromisso %s   %s   Proximo   %s   %s   <---  %s   %s   Buscar  %s\n",(M[0]==1)?"|-|":"   ",(M[0]==1)?"|-|":"   ",(M[1]==1)?"|-|":"   ",(M[1]==1)?"|-|":"   ",(M[2]==1)?"|-|":"   ",(M[2]==1)?"|-|":"   ",(M[3]==1)?"|-|":"   ",(M[3]==1)?"|-|":"   ");
		    printf("    %s   Anterior  %s   %s Compromisso %s   %s  Voltar %s   %s  Por Data %s\n",(M[0]==1)?"|-|":"   ",(M[0]==1)?"|-|":"   ",(M[1]==1)?"|-|":"   ",(M[1]==1)?"|-|":"   ",(M[2]==1)?"|-|":"   ",(M[2]==1)?"|-|":"   ",(M[3]==1)?"|-|":"   ",(M[3]==1)?"|-|":"   ");
            }		
			tecla = getch();
				if(tecla==13){
					if(M[0]==1){
						if(mtam==1){
							aux=l->fim;
							mtam=l->tam;
							continue;
						}
						aux=aux->anterior;
						mtam--;
						continue;
					}
					if(M[1]==1){
						if(mtam==l->tam){
							aux=l->inicio;
							mtam=1;
							continue;
						}
						aux=aux->proximo;
						mtam++;
						continue;
					}
					if(M[2]==1){
						break;
					}
					if(M[3]==1){
						char pesdata[10];
						printf("\n\n    [S] Ok, Preciso que me diga a data que deseja buscar. [AAAA-MM-DD]\n\n         R: ");
						int q,j=0;
						cin >> pesdata;
						aux=l->inicio;
						printf("\n    [S] Imprimindo Busca:  \n\n");
						system("color DF");
						for(q=0;q<l->tam;q++){
							if(strcmp(aux->a.data,pesdata)==0){
							printf("\n        >>[N%i] Titulo: %s\n",q,aux->a.titulo);	
							printf("        >>[N%i] Data: %c%c/%c%c/%c%c\n",q,aux->a.data[8],aux->a.data[9],aux->a.data[5],aux->a.data[6],aux->a.data[2],aux->a.data[3]);
							printf("        >>[N%i] Descricao: %s\n",q,aux->a.descricao);
							j=1;
							}
							aux=aux->proximo;
						}
						if(j==0)printf("    [S] Nao encontramos compromissos nessa data. . . [%s]\n\n",pesdata);
						else printf("\n\n     [S] Busca Concluida com sucesso. . . \n\n");
						printf("\n    [+] Pressione qualquer tecla para limpar busca . . . ");
						getchar();
						getchar();
						
						//Return
						aux=l->inicio;
					}
				}
				if(tecla==77){//Direita
					if(M[0]==1){
						M[0]=0;M[1]=1;M[2]=0;M[3]=0;
						continue;
					}
					if(M[1]==1){
						M[0]=0;M[1]=0;M[2]=1;M[3]=0;
						continue;
					}
					if(M[2]==1){
						M[0]=0;M[1]=0;M[2]=0;M[3]=1;
						continue;
					}
					if(M[3]==1){
						M[1]=1;M[1]=0;M[2]=0;M[3]=0;
						continue;
					}
				}
				if(tecla==75){//Esquerda
					if(M[0]==1){
						M[0]=0;M[1]=0;M[2]=0;M[3]=1;
						continue;
					}
					if(M[1]==1){
						M[0]=1;M[1]=0;M[2]=0;M[3]=0;
						continue;
					}
					if(M[2]==1){
						M[0]=0;M[1]=1;M[2]=0;M[3]=0;
						continue;
					}	
					if(M[3]==1){
						M[0]=0;M[1]=0;M[2]=1;M[3]=0;
						continue;
					}	
				}
			}
			}
			tela[0][1]=1;
			t_Menu(tela);
			return tela;
		}
    if(tela[1][0]==2){//Acao 3
			system("cls");
			if(l->tam==0){
			system("color CF");
			printf("|-|                                                                      |-|\n");
			printf("|-|               Voce nao tem compromisso. . .                          |-|\n");
			printf("|-|                                                                      |-|\n\n\n\n");
			
			printf("\n    [+] Pressione qualquer tecla para voltar ao menu. . . . ");
			getchar();
			tela[1][0]=1;
			t_Menu(tela);
			return tela;
			}else{
			printf("|-|                                                               |-|\n");
			printf("|-|       Listando Todos os Compromisso  - (%s%i)                   |-|\n",(l->tam<10)?"0":"",l->tam);
			printf("|-|                                                               |-|\n\n");
			int x;
			Elemento *aux = l->inicio;
				for(x=0;x<l->tam;x++){
		    	printf("\n        >>[S] Codigo: %i\n",aux->a.codigo);
				printf("        >>[S] Titulo: %s\n",aux->a.titulo);	
				printf("        >>[S] Data: %s\n",aux->a.data);
				printf("        >>[S] Descricao: %s\n\n",aux->a.descricao);	
				if(x!=l->tam)aux=aux->proximo;
				}
				int Auxcodigo;
				printf("\n    [+] Qual e o codigo do compromisso que deseja excluir ?\n\n         R: ");
				cin >> Auxcodigo;
				if(remove(l,Auxcodigo)==0){
				system("color 3F");
				printf("\n\n    [+] Compromisso Excluido com sucesso. . . .\n\n");
				}else{
				system("color CF");
				printf("\n\n    [+] Ocorreu um Erro na exclussao do compromisso. . . .\n\n");	
				}
				
			//Sair
			printf("\n    [+] Pressione qualquer tecla para voltar ao menu . . . ");
			getchar();
			getchar();
			tela[1][0]=1;
			t_Menu(tela);
			return tela;
		}
		}
	if(tela[1][1]==2){//Sair
			int t,sair[2]={1,0};
			for(;;){
			system("cls");
			cout << "[S] Deseja Finalizar o programa ?" << endl << endl;
			printf("    %s   <---   %s        %s  Confirmar %s\n",(sair[0]==1)?"|-|":"   ",(sair[0]==1)?"|-|":"   ",(sair[1]==1)?"|-|":"   ",(sair[1]==1)?"|-|":"   ");
			printf("    %s  Voltar  %s        %s    Saida   %s\n",(sair[0]==1)?"|-|":"   ",(sair[0]==1)?"|-|":"   ",(sair[1]==1)?"|-|":"   ",(sair[1]==1)?"|-|":"   ");
			t = getch();
			    if(t==13){
					if(sair[0]==1){
						sair[0]=2;
						tela[1][1]=1;
						t_Menu(tela);
						return tela;
					}
					if(sair[1]==1){
						sair[1]=2;
						cout << "\n\n[S] Finalizando programa. . . \n" << endl;
						system("pause");
						exit(0);
						break;
					}
			    }
				if(t==77||t==100||t==109||t==75||t==97||t==110){
					if(sair[0]==1){
						sair[0]=0;sair[1]=1;
						continue;
					}
					if(sair[1]==1){
						sair[1]=0;sair[0]=1;
						continue;
					}
				}
			}
		}
}

main(){
	int ** tela = alocar();
	Lista * l = (Lista *) malloc(sizeof(Lista));
	t_Menu(tela);
	
	for(;;){
		for(;;){
		t_Menu(move(tela));
			if(tela[0][0]==2||tela[0][1]==2||tela[1][0]==2||tela[1][1]==2)break;
		}
		selecao(tela,l);
		//getchar();
	}
	
}
