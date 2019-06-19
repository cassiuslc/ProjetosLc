//Fucapi 2018 - By Lc, Cassius Leon
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//Definicoes
#define MAX 3
#define X 1
#define O 2
#define S 3
///Funções/Procedimentos
     void Mcima(int * linha){ if(*linha==0)*linha=3; else if(*linha>0)*linha=*linha-1;menu(*linha);}
    void Mbaixo(int * linha){ if(*linha==3)*linha=0; else if(*linha<3)*linha=*linha+1;menu(*linha);}

     void Tcima(int * coluna,int * linha){ if(*linha==0)*linha=2; else if(*linha>0)*linha=*linha-1;}
    void Tbaixo(int * coluna,int * linha){ if(*linha==2)*linha=0; else if(*linha<2)*linha=*linha+1;}
  void Tdireita(int * coluna,int * linha){ if(*coluna==2)*coluna=0; else if(*coluna<2)*coluna=*coluna+1;}
 void Tesquerda(int * coluna,int * linha){ if(*coluna==0)*coluna=2; else if(*coluna>0)*coluna=*coluna-1;}
//Funçao Win (Verifica se Usuario Ganhou)
int win(int vez,int * JG[][MAX]){
if(vez==X){
    if(JG[0][0]==X&&JG[0][1]==X&&JG[0][2]==X)return 1;
    if(JG[1][0]==X&&JG[1][1]==X&&JG[1][2]==X)return 1;
    if(JG[2][0]==X&&JG[2][1]==X&&JG[2][2]==X)return 1;

    if(JG[0][0]==X&&JG[1][0]==X&&JG[2][0]==X)return 1;
    if(JG[0][1]==X&&JG[1][1]==X&&JG[2][1]==X)return 1;
    if(JG[0][2]==X&&JG[1][2]==X&&JG[2][2]==X)return 1;

    if(JG[0][0]==X&&JG[1][1]==X&&JG[2][2]==X)return 1;
    if(JG[0][2]==X&&JG[1][1]==X&&JG[2][0]==X)return 1;
    if(JG[0][0]!=0&&JG[0][1]!=0&&JG[0][2]!=0&&JG[1][0]!=0&&JG[1][1]!=0&&JG[1][2]!=0&&JG[2][0]!=0&&JG[2][1]!=0&&JG[2][2]!=0){
    return -3;}
    return -1;
}else if(vez==O){
    if(JG[0][0]==O&&JG[0][1]==O&&JG[0][2]==O)return 1;
    if(JG[1][0]==O&&JG[1][1]==O&&JG[1][2]==O)return 1;
    if(JG[2][0]==O&&JG[2][1]==O&&JG[2][2]==O)return 1;

    if(JG[0][0]==O&&JG[1][0]==O&&JG[2][0]==O)return 1;
    if(JG[0][1]==O&&JG[1][1]==O&&JG[2][1]==O)return 1;
    if(JG[0][2]==O&&JG[1][2]==O&&JG[2][2]==O)return 1;

    if(JG[0][0]==O&&JG[1][1]==O&&JG[2][2]==O)return 1;
    if(JG[0][2]==O&&JG[1][1]==O&&JG[2][0]==O)return 1;
    if(JG[0][0]!=0&&JG[0][1]!=0&&JG[0][2]!=0&&JG[1][0]!=0&&JG[1][1]!=0&&JG[1][2]!=0&&JG[2][0]!=0&&JG[2][1]!=0&&JG[2][2]!=0){
    return -3;}
    return -1;
}
}
//Funçao IMP (Verifica a melhor jogada)
int imp(int * jg[][MAX]){int i;
    ///Sempre que voce puder Ganhar ganhe
    if(jg[0][0]==O&&jg[0][1]==O&&jg[0][2]!=X)return 3;
    if(jg[1][0]==O&&jg[1][1]==O&&jg[1][2]!=X)return 6;
    if(jg[2][0]==O&&jg[2][1]==O&&jg[2][2]!=X)return 9;
//Int Ganhar na lateral pela Direita
    if(jg[0][1]==O&&jg[0][2]==O&&jg[0][0]!=X)return 1;
    if(jg[1][1]==O&&jg[1][2]==O&&jg[1][0]!=X)return 4;
    if(jg[2][1]==O&&jg[2][2]==O&&jg[2][0]!=X)return 7;
//int Ganhar na Horizontal de cima
    if(jg[0][0]==O&&jg[1][0]==O&&jg[2][0]!=X)return 7;
    if(jg[0][1]==O&&jg[1][1]==O&&jg[2][1]!=X)return 8;
    if(jg[0][2]==O&&jg[1][2]==O&&jg[2][2]!=X)return 9;
//int Ganhar na Horizontal de baixo
    if(jg[2][0]==O&&jg[1][0]==O&&jg[0][0]!=X)return 1;
    if(jg[2][1]==O&&jg[1][1]==O&&jg[0][1]!=X)return 2;
    if(jg[2][2]==O&&jg[1][2]==O&&jg[0][2]!=X)return 3;
//int Ganhar na Cruzada
    if(jg[0][0]==O&&jg[1][1]==O&&jg[2][2]!=X)return 9;
    if(jg[0][2]==O&&jg[1][1]==O&&jg[2][0]!=X)return 7;
    if(jg[2][2]==O&&jg[1][1]==O&&jg[0][0]!=X)return 1;
    if(jg[2][0]==O&&jg[1][1]==O&&jg[0][2]!=X)return 3;
    ///Ganhe de Meio
//Int Bloqueio lateral
    if(jg[0][0]==O&&jg[0][2]==O&&jg[0][1]!=X)return 2;
    if(jg[1][0]==O&&jg[1][2]==O&&jg[1][1]!=X)return 5;
    if(jg[2][0]==O&&jg[2][2]==O&&jg[2][1]!=X)return 8;
//int Bloqueio Horizontal de cima
    if(jg[0][0]==O&&jg[2][0]==O&&jg[1][0]!=X)return 4;
    if(jg[0][1]==O&&jg[2][1]==O&&jg[1][1]!=X)return 5;
    if(jg[0][2]==O&&jg[2][2]==O&&jg[1][2]!=X)return 6;
//int Bloqueio de Cruzada
    if(jg[0][0]==O&&jg[2][2]==O&&jg[1][1]!=X)return 5;
    if(jg[0][2]==O&&jg[2][0]==O&&jg[1][1]!=X)return 5;
    ///Bloqueios de Jogadas
//Bloquei a estrategia dos tres
    if((jg[1][1]==O&&jg[0][0]==X)&&jg[0][1]==0&&jg[0][2]==0&&jg[1][0]==0&&jg[1][1]==0&&jg[1][2]==0&&jg[2][0]==0&&jg[2][1]==0&&jg[2][2]==0)return 2;
    if((jg[1][1]==O&&jg[0][2]==X)&&jg[0][0]==0&&jg[0][1]==0&&jg[1][0]==0&&jg[1][1]==0&&jg[1][2]==0&&jg[2][0]==0&&jg[2][1]==0&&jg[2][2]==0)return 6;
    if((jg[1][1]==O&&jg[2][0]==X)&&jg[0][0]==0&&jg[0][1]==0&&jg[0][2]==0&&jg[1][0]==0&&jg[1][1]==0&&jg[1][2]==0&&jg[2][1]==0&&jg[2][2]==0)return 4;
    if((jg[1][1]==O&&jg[2][2]==X)&&jg[0][0]==0&&jg[0][1]==0&&jg[0][2]==0&&jg[1][0]==0&&jg[1][1]==0&&jg[1][2]==0&&jg[2][0]==0&&jg[2][1]==0)return 8;
//Int Bloqueio lateral pela esquerda
    if(jg[0][0]==X&&jg[0][1]==X&&jg[0][2]!=O)return 3;
    if(jg[1][0]==X&&jg[1][1]==X&&jg[1][2]!=O)return 6;
    if(jg[2][0]==X&&jg[2][1]==X&&jg[2][2]!=O)return 9;
//Int Bloqueio lateral pela Direita
    if(jg[0][1]==X&&jg[0][2]==X&&jg[0][0]!=O)return 1;
    if(jg[1][1]==X&&jg[1][2]==X&&jg[1][0]!=O)return 4;
    if(jg[2][1]==X&&jg[2][2]==X&&jg[2][0]!=O)return 7;
//int Bloqueio Horizontal de cima
    if(jg[0][0]==X&&jg[1][0]==X&&jg[2][0]!=O)return 7;
    if(jg[0][1]==X&&jg[1][1]==X&&jg[2][1]!=O)return 8;
    if(jg[0][2]==X&&jg[1][2]==X&&jg[2][2]!=O)return 9;
//int Bloqueio Horizontal de baixo
    if(jg[2][0]==X&&jg[1][0]==X&&jg[0][0]!=O)return 1;
    if(jg[2][1]==X&&jg[1][1]==X&&jg[0][1]!=O)return 2;
    if(jg[2][2]==X&&jg[1][2]==X&&jg[0][2]!=O)return 3;
//int Bloqueio de Cruzada
    if(jg[0][0]==X&&jg[1][1]==X&&jg[2][2]!=O)return 9;
    if(jg[0][2]==X&&jg[1][1]==X&&jg[2][0]!=O)return 7;
    if(jg[2][2]==X&&jg[1][1]==X&&jg[0][0]!=O)return 1;
    if(jg[2][0]==X&&jg[1][1]==X&&jg[0][2]!=O)return 3;
    ///Bloqueio de Meio
//Int Bloqueio lateral
    if(jg[0][0]==X&&jg[0][2]==X&&jg[0][1]!=O)return 2;
    if(jg[1][0]==X&&jg[1][2]==X&&jg[1][1]!=O)return 5;
    if(jg[2][0]==X&&jg[2][2]==X&&jg[2][1]!=O)return 8;
//int Bloqueio Horizontal de cima
    if(jg[0][0]==X&&jg[2][0]==X&&jg[1][0]!=O)return 4;
    if(jg[0][1]==X&&jg[2][1]==X&&jg[1][1]!=O)return 5;
    if(jg[0][2]==X&&jg[2][2]==X&&jg[1][2]!=O)return 6;
//int Bloqueio de Cruzada
    if(jg[0][0]==X&&jg[2][2]==X&&jg[1][1]!=O)return 5;
    if(jg[0][2]==X&&jg[2][0]==X&&jg[1][1]!=O)return 5;
    ///Jogadas Estrategicas
//Caso usuario inicie na Cruz linha 1
if(jg[0][1]==X&&jg[0][0]==0&&jg[0][2]==0&&jg[1][0]==0&&jg[1][1]==0&&jg[1][2]==0&&jg[2][0]==0&&jg[2][1]==0&&jg[2][2]==0){
    for(;;){i = rand() % 10;
    if(i==1||i==3||i==5||i==8)break;
    }return i;}
//Caso usuario inicie na Cruz linha 2 Esquerda
if(jg[1][0]==X&&jg[0][0]==0&&jg[0][1]==0&&jg[0][2]==0&&jg[1][1]==0&&jg[1][2]==0&&jg[2][0]==0&&jg[2][1]==0&&jg[2][2]==0){
    for(;;){i = rand() % 10;
    if(i==5||i==6||i==1||i==7)break;
    }return i;}
//Caso usuario inicie na Cruz linha 2 Direita
if(jg[1][2]==X&&jg[0][0]==0&&jg[0][1]==0&&jg[0][2]==0&&jg[1][0]==0&&jg[1][1]==0&&jg[2][0]==0&&jg[2][1]==0&&jg[2][2]==0){
    for(;;){i = rand() % 10;
    if(i==5||i==4||i==3||i==9)break;
    }return i;}
//Caso usuario inicie na Cruz linha 3
if(jg[2][1]==X&&jg[0][0]==0&&jg[0][1]==0&&jg[0][2]==0&&jg[1][0]==0&&jg[1][1]==0&&jg[1][2]==0&&jg[2][0]==0&&jg[2][2]==0){
    for(;;){i = rand() % 10;
    if(i==5||i==2||i==7||i==9)break;
    }return i;}
//Caso usuario inicie no Meio marque nas laterais
if(jg[1][1]==X&&jg[0][0]==0&&jg[0][1]==0&&jg[0][2]==0&&jg[1][0]==0&&jg[1][2]==0&&jg[2][0]==0&&jg[2][1]==0&&jg[2][2]==0){
    for(;;){i = rand() % 10;
    if(i==1||i==3||i==7||i==9)break;
    }return i;}
//Sempre tente conseguir o Meio
if(jg[1][1]!=X&&jg[1][1]!=O)return 5;
//O Caso nao foi catalogado retorne aleatorio
return -1;
}
///Inicio Codigo
void main(){
titulo();
menu(0);
int mlinha=0,linha=0,coluna=0,tecla=0;
for(;;){
///Menu Principal
titulo();
menu(0);
for(;;){tecla = getch();//Pega tecla

    if(tecla==72||tecla==119){/*Setas (Cima) ou W*/ Mcima(&mlinha);}

    if(tecla==80||tecla==115){/*Setas (Baixo) ou S*/ Mbaixo(&mlinha);}

    if((tecla==13||tecla==32)){/*Enter ou Espaco*/ break;}
}
///Ações
    if(mlinha==0){//Menu 1
        mlinha=0;
        system("cls");
system("color F0");
titulo();
char p1[99],p2[99],aux[10];
int soma=0,gh=0;
//Jogo da Velha - Mini Game
printf("\n\n   [S] Oi ? vamos decidir quem deve iniciar jogando ?\n");
printf("\n     [S] Digite o nome do Player 1 (Impar): ");
scanf("%s",&p1);
getchar();
for(;;){
system("cls");
titulo();
printf("\n\n   [S] Oi ? vamos decidir quem deve iniciar jogando ?\n");
printf("\n     [S] Digite o nome do Player 1 (Impar): %s",p1);
printf("\n     [S] Digite um Numero (Impar): ");
scanf("%s",&aux);
if(atoi(aux)!=0)break;
system("color CF");
}soma=atoi(aux);getchar();
system("color F0");
printf("\n     [S] Digite o nome do Player 2 (Par): ");
scanf("%s",&p2);
getchar();
for(;;){
system("cls");
titulo();
printf("\n\n   [S] Oi ? vamos decidir quem deve iniciar jogando ?\n");
printf("\n     [S] Digite o nome do Player 1 (Impar): %s",p1);
printf("\n     [S] Digite um Numero (Impar): %i",soma);
printf("\n\n     [S] Digite o nome do Player 2 (Par): %s",p2);
printf("\n     [S] Digite um Numero (Par): ");
scanf("%s",&aux);
if(atoi(aux)!=0)break;
system("color CF");
}soma=soma+atoi(aux);
srand( (unsigned)time(NULL) );
system("color F0");
if((rand() % 100)>49){
printf("\n   [S] Aleatoriamente Foi escolhido que voces Trocam de selecao (Impar/Par)!\n");
if(soma%2==0){//Par ganhou player 1 (troca)
    gh=1;
}else if(soma%2!=0){
gh=2;
}
}else{
printf("\n   [S] Aleatoriamente Foi escolhido que voces Mantem selecao (Impar/Par)!\n");
if(soma%2==0){//Par ganhou player 2 (Mantem)
    gh=2;
}else if(soma%2!=0){
gh = 1;
}
}
printf("\n   [S] ");
system("pause");
if(gh==2){//Player 2
system("cls");
titulo();printf("\n\n  [S] %i (%s), O Player 2 [%s] ganhou, Ele escolhe quem e [X] ou [O]!\n",soma,(soma%2==0)?"Par":"Impar",p2);
printf("\n  [S] ");
system("pause");
system("cls");
titulo();printf("\n\n  [S] %i (%s), O Player 2 [%s] ganhou, Ele escolhe quem e [X] ou [O]!\n",soma,(soma%2==0)?"Par":"Impar",p2);
printf("\n  [S] Iniciando em 5...\n");
sleep(1);
system("cls");
titulo();printf("\n\n  [S] %i (%s), O Player 2 [%s] ganhou, Ele escolhe quem e [X] ou [O]!\n",soma,(soma%2==0)?"Par":"Impar",p2);
printf("\n  [S] Iniciando em 4...\n");
sleep(1);
system("cls");
titulo();printf("\n\n  [S] %i (%s), O Player 2 [%s] ganhou, Ele escolhe quem e [X] ou [O]!\n",soma,(soma%2==0)?"Par":"Impar",p2);
printf("\n  [S] Iniciando em 3...\n");
sleep(1);
system("cls");
titulo();printf("\n\n  [S] %i (%s), O Player 2 [%s] ganhou, Ele escolhe quem e [X] ou [O]!\n",soma,(soma%2==0)?"Par":"Impar",p2);
printf("\n  [S] Iniciando em 2...\n");
sleep(1);
system("cls");
titulo();printf("\n\n  [S] %i (%s), O Player 2 [%s] ganhou, Ele escolhe quem e [X] ou [O]!\n",soma,(soma%2==0)?"Par":"Impar",p2);
printf("\n  [S] Iniciando em 1...\n");
sleep(1);
}else if(gh==1){//Player 1
system("cls");
titulo();printf("\n\n  [S] %i (%s), O Player 1 [%s] ganhou, Ele escolhe quem e [X] ou [O]!\n",soma,(soma%2==0)?"Par":"Impar",p1);
printf("\n  [S] ");
system("pause");
system("cls");
titulo();printf("\n\n  [S] %i (%s), O Player 1 [%s] ganhou, Ele escolhe quem e [X] ou [O]!\n",soma,(soma%2==0)?"Par":"Impar",p1);
printf("\n  [S] Iniciando em 5...\n");
sleep(1);
system("cls");
titulo();printf("\n\n  [S] %i (%s), O Player 1 [%s] ganhou, Ele escolhe quem e [X] ou [O]!\n",soma,(soma%2==0)?"Par":"Impar",p1);
printf("\n  [S] Iniciando em 4...\n");
sleep(1);
system("cls");
titulo();printf("\n\n  [S] %i (%s), O Player 1 [%s] ganhou, Ele escolhe quem e [X] ou [O]!\n",soma,(soma%2==0)?"Par":"Impar",p1);
printf("\n  [S] Iniciando em 3...\n");
sleep(1);
system("cls");
titulo();printf("\n\n  [S] %i (%s), O Player 1 [%s] ganhou, Ele escolhe quem e [X] ou [O]!\n",soma,(soma%2==0)?"Par":"Impar",p1);
printf("\n  [S] Iniciando em 2...\n");
sleep(1);
system("cls");
titulo();printf("\n\n  [S] %i (%s), O Player 1 [%s] ganhou, Ele escolhe quem e [X] ou [O]!\n",soma,(soma%2==0)?"Par":"Impar",p1);
printf("\n  [S] Iniciando em 1...\n");
sleep(1);
}
//Codigo do Jogo da Velha Player vs Player
        int jg[MAX][MAX] = {0},vez=X; //Declarando a Matriz Jogo e a Vez que sempre inicia X
        tecla=0;linha=0;coluna=0;
        tela(linha,coluna,vez,&jg);
    for(;;){tecla = getch();//Pega tecla

    if(tecla==77||tecla==100){/*Setas (Direita) ou D*/ Tdireita(&coluna,&linha); tela(linha,coluna,vez,&jg);}

    if(tecla==75||tecla==97){/*Setas (Esquerda) ou A*/ Tesquerda(&coluna,&linha); tela(linha,coluna,vez,&jg);}

    if(tecla==72||tecla==119){/*Setas (Cima) ou W*/ Tcima(&coluna,&linha); tela(linha,coluna,vez,&jg);}

    if(tecla==80||tecla==115){/*Setas (Baixo) ou S*/ Tbaixo(&coluna,&linha); tela(linha,coluna,vez,&jg);}

    if((tecla==13||tecla==32)||(tecla==120&&vez==X)||(tecla==111&&vez==O)){/*Enter ou Espaco*/
        if(jg[linha][coluna]==X||jg[linha][coluna]==O){
            system("color CF");
            printf("\n [S]: Local Invalido !!!");
        }else{
            if(vez==X){
                jg[linha][coluna]=X;
                if(win(vez,&jg)==1){
                    tela(linha,coluna,vez,&jg);
                    system("color FD");
                    printf("\n   [S]: X Ganhou a partida !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(vez,&jg)==-3){
                    system("color CF");
                    vez = 3;
                    tela(linha,coluna,vez,&jg);
                    printf("\n   [S]: O Jogo deu Velha !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }
                vez = (vez==X)?O:X;
                tela(linha,coluna,vez,&jg);
            }else if(vez==O){
                jg[linha][coluna]=O;
                if(win(vez,&jg)==1){
                    tela(linha,coluna,vez,&jg);
                    system("color F3");
                    printf("\n   [S]: O Ganhou a partida !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(vez,&jg)==-3){
                    system("color CF");
                    vez = 3;
                    tela(linha,coluna,vez,&jg);
                    printf("\n   [S]: O Jogo deu Velha !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }
                vez = (vez==X)?O:X;
                tela(linha,coluna,vez,&jg);
            }
        }
    }
}
    }
//Codigo do Jogo da Velha Player vs Maquina (Aleatorio)
    if(mlinha==1){//Menu 2
    mlinha=0;
    int jg[MAX][MAX] = {0},vez=X,i=0;
        tecla=0;linha=0;coluna=0;
        tela(linha,coluna,vez,&jg);
for(;;){tecla = getch();//Pega tecla

    if(tecla==77||tecla==100){/*Setas (Direita) ou D*/ Tdireita(&coluna,&linha); tela(linha,coluna,vez,&jg);}

    if(tecla==75||tecla==97){/*Setas (Esquerda) ou A*/ Tesquerda(&coluna,&linha); tela(linha,coluna,vez,&jg);}

    if(tecla==72||tecla==119){/*Setas (Cima) ou W*/ Tcima(&coluna,&linha); tela(linha,coluna,vez,&jg);}

    if(tecla==80||tecla==115){/*Setas (Baixo) ou S*/ Tbaixo(&coluna,&linha); tela(linha,coluna,vez,&jg);}

        if((tecla==13||tecla==32)||(tecla==120&&vez==X)||(tecla==111&&vez==O)){//Enter ou Espaco
            if(jg[linha][coluna]==X||jg[linha][coluna]==O){
                system("color CF");
                printf("\n [S]: Local Invalido !!!");
        }else{
            if(vez==X){
            srand( (unsigned)time(NULL) );//Alimenta a Funcao Time com Seed
                jg[linha][coluna]=X;
                tela(linha,coluna,O,&jg);
                if(win(O,&jg)!=-3&&win(O,&jg)!=1){
                    for(;;){
                    if(win(X,&jg)==1)break;
                    i=rand() % 10;//faz um aleatorio de 0 a 9
                        if(i==1){
                            if(jg[0][0]==X||jg[0][0]==O)continue;
                            else jg[0][0]=O;
                            vez=X;
                            break;
                        }
                        if(i==2){
                            if(jg[0][1]==X||jg[0][1]==O)continue;
                            else jg[0][1]=O;
                            vez=X;
                            break;
                        }
                        if(i==3){
                            if(jg[0][2]==X||jg[0][2]==O)continue;
                            else jg[0][2]=O;
                            vez=X;
                            break;
                        }
                        if(i==4){
                            if(jg[1][0]==X||jg[1][0]==O)continue;
                            else jg[1][0]=O;
                            vez=X;
                            break;
                        }
                        if(i==5){
                            if(jg[1][1]==X||jg[1][1]==O)continue;
                            else jg[1][1]=O;
                            vez=X;
                            break;
                        }
                        if(i==6){
                            if(jg[1][2]==X||jg[1][2]==O)continue;
                            else jg[1][2]=O;
                            vez=X;
                            break;
                        }
                        if(i==7){
                            if(jg[2][0]==X||jg[2][0]==O)continue;
                            else jg[2][0]=O;
                            vez=X;
                            break;
                        }
                        if(i==8){
                            if(jg[2][1]==X||jg[2][1]==O)continue;
                            else jg[2][1]=O;
                            vez=X;
                            break;
                        }
                        if(i==9){
                            if(jg[2][2]==X||jg[2][2]==O)continue;
                            else jg[2][2]=O;
                            vez=X;
                            break;
                        }
                    }}
                //printf("Numero Aleatorio: %d\n",rand() % 10);
                if(win(vez,&jg)==1){
                    tela(linha,coluna,vez,&jg);
                    system("color FD");
                    printf("\n   [S]: X Ganhou a partida !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(vez,&jg)==-3){
                    system("color CF");
                    vez = 3;
                    tela(linha,coluna,vez,&jg);
                    printf("\n   [S]: O Jogo deu Velha !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(O,&jg)==1){
                system("color CF");
                    vez = O;
                    tela(linha,coluna,vez,&jg);
                    printf("\n   [S]: O Ganhou a partida !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(O,&jg)==-3){
                system("color CF");
                    vez = 3;
                    tela(linha,coluna,vez,&jg);
                    printf("\n   [S]: O Jogo deu Velha !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }
                vez=X;
                tela(linha,coluna,vez,&jg);
            }
        }
    }
    }}
//Codigo do Jogo da Velha Player vs Maquina (I)
    if(mlinha==2){//Menu 3
    mlinha=0;
    int jg[MAX][MAX] = {0},vez=X,i;
        tecla=0;linha=0;coluna=0;
        tela(linha,coluna,vez,&jg);
    for(;;){tecla = getch();//Pega tecla

    if(tecla==77||tecla==100){/*Setas (Direita) ou D*/ Tdireita(&coluna,&linha); tela(linha,coluna,vez,&jg);}

    if(tecla==75||tecla==97){/*Setas (Esquerda) ou A*/ Tesquerda(&coluna,&linha); tela(linha,coluna,vez,&jg);}

    if(tecla==72||tecla==119){/*Setas (Cima) ou W*/ Tcima(&coluna,&linha); tela(linha,coluna,vez,&jg);}

    if(tecla==80||tecla==115){/*Setas (Baixo) ou S*/ Tbaixo(&coluna,&linha); tela(linha,coluna,vez,&jg);}

        if((tecla==13||tecla==32)){//Enter ou Espaco
            if(jg[linha][coluna]==X||jg[linha][coluna]==O){
                system("color CF");
                printf("\n [S]: Local Invalido !!!");
        }else{
            if(vez==X){
            srand( (unsigned)time(NULL) );//Alimenta seed do aleatorio
                jg[linha][coluna]=X;
                tela(linha,coluna,O,&jg);
                if(win(O,&jg)!=-3&&win(O,&jg)!=1){
                    for(;;){
                    if(win(X,&jg)==1)break;
                    i=rand() % 10;//Aleatorio de 0 a 9
                    if(imp(&jg)!=-1){i=imp(&jg);}
                        if(i==1){
                            if(jg[0][0]==X||jg[0][0]==O)continue;
                            else jg[0][0]=O;
                            vez=X;
                            break;
                        }
                        if(i==2){
                            if(jg[0][1]==X||jg[0][1]==O)continue;
                            else jg[0][1]=O;
                            vez=X;
                            break;
                        }
                        if(i==3){
                            if(jg[0][2]==X||jg[0][2]==O)continue;
                            else jg[0][2]=O;
                            vez=X;
                            break;
                        }
                        if(i==4){
                            if(jg[1][0]==X||jg[1][0]==O)continue;
                            else jg[1][0]=O;
                            vez=X;
                            break;
                        }
                        if(i==5){
                            if(jg[1][1]==X||jg[1][1]==O)continue;
                            else jg[1][1]=O;
                            vez=X;
                            break;
                        }
                        if(i==6){
                            if(jg[1][2]==X||jg[1][2]==O)continue;
                            else jg[1][2]=O;
                            vez=X;
                            break;
                        }
                        if(i==7){
                            if(jg[2][0]==X||jg[2][0]==O)continue;
                            else jg[2][0]=O;
                            vez=X;
                            break;
                        }
                        if(i==8){
                            if(jg[2][1]==X||jg[2][1]==O)continue;
                            else jg[2][1]=O;
                            vez=X;
                            break;
                        }
                        if(i==9){
                            if(jg[2][2]==X||jg[2][2]==O)continue;
                            else jg[2][2]=O;
                            vez=X;
                            break;
                        }
                    }}
                //printf("Numero Aleatorio: %d\n",rand() % 10);
                if(win(vez,&jg)==1){
                    tela(linha,coluna,vez,&jg);
                    system("color FD");
                    printf("\n   [S]: X Ganhou a partida !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(vez,&jg)==-3){
                    system("color CF");
                    vez = 3;
                    tela(linha,coluna,vez,&jg);
                    printf("\n   [S]: O Jogo deu Velha !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(O,&jg)==1){
                system("color CF");
                    vez = O;
                    tela(linha,coluna,vez,&jg);
                    printf("\n   [S]: O Ganhou a partida !!! !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(O,&jg)==-3){
                system("color CF");
                    vez = 3;
                    tela(linha,coluna,vez,&jg);
                    printf("\n   [S]: O Jogo deu Velha !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }
                vez=X;
                tela(linha,coluna,vez,&jg);
            }
        }
    }
    }
    }
    if(mlinha==3){//Menu 4
    titulo();
        menu(3);
    system("color CF");
        printf("\n[S] saindo ...");
        sleep(1);
    titulo();
        menu(3);
        printf("\n[S] saindo. ..");
        sleep(1);
    titulo();
        menu(3);
        printf("\n[S] saindo.. .");
        sleep(1);
    titulo();
        menu(3);
        printf("\n[S] saindo... ");
    break;
    }
///Fim Codigo
}}
///Funções Graficas/Telas
void titulo(){
system("cls");
printf("º-----------------------------------------------------------------------------º\n");
printf("º      __ _____ _____ _____    ____  _____    _____ _____ __    _____ _____   º\n");
printf("º   __|  |     |   __|     |  |    \\|  _  |  |  |  |   __|  |  |  |  |  _  |  º\n");
printf("º  |  |  |  |  |  |  |  |  |  |  |  |     |  |  |  |   __|  |__| Cassius Lc|  º\n");
printf("º  |_____|_____|_____|_____|  |____/|__|__|   \\___/|_____|_____|__|__|__|__|  º\n");
printf("º                                                                             º\n");
}
//Menu Principal
void menu(int linha){
titulo();
if(linha==0||linha==1)system("color F0");
if(linha==3)system("color CF");
if(linha==2)system("color F1");
printf("\n\n");
printf("                          %s  Jogador vs Jogador  %s  \n\n",(linha==0)?"(O)":"   ",(linha==0)?"(X)":"   ");
printf("                          %s  Jogador vs Maquina  %s  \n\n",(linha==1)?"(X)":"   ",(linha==1)?"(O)":"   ");
printf("                          %s   Modo Inteligente   %s  \n\n",(linha==2)?"(+)":"   ",(linha==2)?"(+)":"   ");
printf("                          %s     Sair do Jogo     %s  \n\n",(linha==3)?"(-)":"   ",(linha==3)?"(-)":"   ");
}
//Tabuleiro do Jogo
void tela(int l,int c,int vez,int * jg[][MAX]){//Linha Coluna Vez Matriz Jogo
if(vez==X){system("color DF");}else if(vez==O){system("color 3F");}else if(vez==3){system("color CF");}
titulo();
printf("º           Vez = %c                                                           º\n",(vez==X)?'X':'O');
printf("ºº                             %c%c%cº%c%c%cº%c%c%c                                   ºº\n",/* 1 */(l==0&&c==0)?'[':' ',(jg[0][0]==X)?'X':(jg[0][0]==O)?'O':' ',(l==0&&c==0)?']':' ',/* 2 */(l==0&&c==1)?'[':' ',(jg[0][1]==X)?'X':(jg[0][1]==O)?'O':' ',(l==0&&c==1)?']':' ',/* 3 */(l==0&&c==2)?'[':' ',(jg[0][2]==X)?'X':(jg[0][2]==O)?'O':' ',(l==0&&c==2)?']':' ');
printf("ºº                             ---º---º---                                   ºº\n");
printf("ºº                             %c%c%cº%c%c%cº%c%c%c                                   ºº\n",/* 4 */(l==1&&c==0)?'[':' ',(jg[1][0]==X)?'X':(jg[1][0]==O)?'O':' ',(l==1&&c==0)?']':' ',/* 5 */(l==1&&c==1)?'[':' ',(jg[1][1]==X)?'X':(jg[1][1]==O)?'O':' ',(l==1&&c==1)?']':' ',/* 6 */(l==1&&c==2)?'[':' ',(jg[1][2]==X)?'X':(jg[1][2]==O)?'O':' ',(l==1&&c==2)?']':' ');
printf("ºº                             ---º---º---                                   ºº\n");
printf("ºº                             %c%c%cº%c%c%cº%c%c%c                                   ºº\n",/* 7 */(l==2&&c==0)?'[':' ',(jg[2][0]==X)?'X':(jg[2][0]==O)?'O':' ',(l==2&&c==0)?']':' ',/* 8 */(l==2&&c==1)?'[':' ',(jg[2][1]==X)?'X':(jg[2][1]==O)?'O':' ',(l==2&&c==1)?']':' ',/* 9 */(l==2&&c==2)?'[':' ',(jg[2][2]==X)?'X':(jg[2][2]==O)?'O':' ',(l==2&&c==2)?']':' ');
}
