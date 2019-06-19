//Fucapi 2018 - By Lc, Cassius Leon
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 3
#define X 1
#define O 2
#define S 3
#define Sx -1
#define So -2
#define L 0
#define C 1
void titulo(){
printf("บ-----------------------------------------------------------------------------บ\n");
printf("บ      __ _____ _____ _____    ____  _____    _____ _____ __    _____ _____   บ\n");
printf("บ   __|  |     |   __|     |  |    \\|  _  |  |  |  |   __|  |  |  |  |  _  |  บ\n");
printf("บ  |  |  |  |  |  |  |  |  |  |  |  |     |  |  |  |   __|  |__| Cassius Lc|  บ\n");
printf("บ  |_____|_____|_____|_____|  |____/|__|__|   \\___/|_____|_____|__|__|__|__|  บ\n");
printf("บ                                                                             บ\n");
}
void tela(int vez,int * TL[][MAX]){
system("cls");
if(vez==X){
    system("color DF");
}else if(vez==O){
    system("color 3F");
}else if(vez==3){
system("color CF");
}
titulo();
printf("บ     Vez = %s                                                                 บ\n",(vez==X)?"X":(vez==O)?"O":"V");
printf("บบ  %s                                                             บบ\n",(vez==X)?"[Cor: Roxo] ":(vez==O)?"[Cor: Azul] ":"[Cor: VELHA]");
printf("บบ                            %sบ%sบ%s                                    บบ\n",(TL[0][0]==S)?"[ ]":(TL[0][0]==X)?" X ":(TL[0][0]==O)?" O ":(TL[0][0]==Sx)?"[X]":(TL[0][0]==So)?"[O]":"   ",(TL[0][1]==S)?"[ ]":(TL[0][1]==X)?" X ":(TL[0][1]==O)?" O ":(TL[0][1]==Sx)?"[X]":(TL[0][1]==So)?"[O]":"   ",(TL[0][2]==S)?"[ ]":(TL[0][2]==X)?" X ":(TL[0][2]==O)?" O ":(TL[0][2]==Sx)?"[X]":(TL[0][2]==So)?"[O]":"   ");
printf("บบ                            ---บ---บ---                                    บบ\n");
printf("บบ                            %sบ%sบ%s                                    บบ\n",(TL[1][0]==S)?"[ ]":(TL[1][0]==X)?" X ":(TL[1][0]==O)?" O ":(TL[1][0]==Sx)?"[X]":(TL[1][0]==So)?"[O]":"   ",(TL[1][1]==S)?"[ ]":(TL[1][1]==X)?" X ":(TL[1][1]==O)?" O ":(TL[1][1]==Sx)?"[X]":(TL[1][1]==So)?"[O]":"   ",(TL[1][2]==S)?"[ ]":(TL[1][2]==X)?" X ":(TL[1][2]==O)?" O ":(TL[1][2]==Sx)?"[X]":(TL[1][2]==So)?"[O]":"   ");
printf("บบ                            ---บ---บ---                                    บบ\n");
printf("บบ                            %sบ%sบ%s                                    บบ\n",(TL[2][0]==S)?"[ ]":(TL[2][0]==X)?" X ":(TL[2][0]==O)?" O ":(TL[2][0]==Sx)?"[X]":(TL[2][0]==So)?"[O]":"   ",(TL[2][1]==S)?"[ ]":(TL[2][1]==X)?" X ":(TL[2][1]==O)?" O ":(TL[2][1]==Sx)?"[X]":(TL[2][1]==So)?"[O]":"   ",(TL[2][2]==S)?"[ ]":(TL[2][2]==X)?" X ":(TL[2][2]==O)?" O ":(TL[2][2]==Sx)?"[X]":(TL[2][2]==So)?"[O]":"   ");
}
void mennu(int p){
//system("color 1F");
system("cls");
titulo();
printf("\n\n");
if(p==0){
system("color F0");
printf("                           [X] Jogador vs Jogador [O] \n\n");
printf("                               Jogador vs Maquina     \n\n");
printf("                                Modo Inteligente      \n\n");
printf("                                  Sair do Jogo        \n\n");
}else if(p==1){
system("color F1");
printf("                               Jogador vs Jogador      \n\n");
printf("                           [O] Jogador vs Maquina [X]  \n\n");
printf("                                Modo Inteligente       \n\n");
printf("                                  Sair do Jogo         \n\n");
}else if(p==2){
system("color 1F");
printf("                               Jogador vs Jogador      \n\n");
printf("                               Jogador vs Maquina      \n\n");
printf("                            [?] Modo Inteligente [?]   \n\n");
printf("                                  Sair do Jogo         \n\n");
}
else if(p==3){
system("color CF");
printf("                               Jogador vs Jogador      \n\n");
printf("                               Jogador vs Maquina      \n\n");
printf("                                Modo Inteligente       \n\n");
printf("                              [-] Sair do Jogo [-]     \n\n");
}
}
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
    for(;;){
    i = rand() % 10;
    if(i==1||i==3||i==5||i==8)break;
    }
    return i;
}
//Caso usuario inicie na Cruz linha 2 Esquerda
if(jg[1][0]==X&&jg[0][0]==0&&jg[0][1]==0&&jg[0][2]==0&&jg[1][1]==0&&jg[1][2]==0&&jg[2][0]==0&&jg[2][1]==0&&jg[2][2]==0){
    for(;;){
    i = rand() % 10;
    if(i==5||i==6||i==1||i==7)break;
    }
    return i;
}
//Caso usuario inicie na Cruz linha 2 Direita
if(jg[1][2]==X&&jg[0][0]==0&&jg[0][1]==0&&jg[0][2]==0&&jg[1][0]==0&&jg[1][1]==0&&jg[2][0]==0&&jg[2][1]==0&&jg[2][2]==0){
    for(;;){
    i = rand() % 10;
    if(i==5||i==4||i==3||i==9)break;
    }
    return i;
}
//Caso usuario inicie na Cruz linha 3
if(jg[2][1]==X&&jg[0][0]==0&&jg[0][1]==0&&jg[0][2]==0&&jg[1][0]==0&&jg[1][1]==0&&jg[1][2]==0&&jg[2][0]==0&&jg[2][2]==0){
    for(;;){
    i = rand() % 10;
    if(i==5||i==2||i==7||i==9)break;
    }
    return i;
}
//Caso usuario inicie no Meio marque nas laterais
if(jg[1][1]==X&&jg[0][0]==0&&jg[0][1]==0&&jg[0][2]==0&&jg[1][0]==0&&jg[1][2]==0&&jg[2][0]==0&&jg[2][1]==0&&jg[2][2]==0){
    for(;;){
    i = rand() % 10;
    if(i==1||i==3||i==7||i==9)break;
    }
    return i;
}

//Sempre tente conseguir o Meio
if(jg[1][1]!=X&&jg[1][1]!=O)return 5;

//O Caso nao foi catalogado retorne aleatorio
return -1;
}
void main(){
int menu=0,mov=0,a=0;
char ass[30]= "Fucapi | Cassius ";
mennu(0);
for(;;){
if(a==-70){
mennu(0);
a=0;
}
menu = getch();
if(menu==72||menu==119){//Cima
    if(mov==0)mov=3;
    else if(mov>0)mov--;
mennu(mov);
}
if(menu==80||menu==115){//Baixo
    if(mov==3)mov=0;
    else if(mov>=0)mov++;
    mennu(mov);
}
 if((menu==13||menu==32)){//enter ou espaco
        if(mov==3){
        a=-1;
        }else if(mov==0){
        a=1;
        }else if(mov==1){
        a=2;
        }else if(mov==2){
        a=7;
        }
 }
 char lc[2]="Lc";
//printf("\n[S] Digite COD-A [Sair = -1]: ");
//scanf("%i",&menu);
if(a==7){
a=-70;
mov=0;
    a=-70;
srand( (unsigned)time(NULL) );
int i=rand() % 10;
mov=0;
system("cls");
//srand( (unsigned)time(NULL) );
//printf("Numero Aleatorio: %d\n",rand() % 10);
a=-70;
mov=0;
int tl[MAX][MAX] = {0},jg[MAX][MAX] = {0},tecla,ATL[2]= {0},ATR[2]= {0};
int vez=X;//X start;
tl[0][0]=S;//Selecao Inicial
tela(X,&tl);
for(;;){
tecla = getch();
    if((tecla==13||tecla==32)||(tecla==120&&vez==X)||(tecla==111&&vez==O)){//Enter ou Espaco (Clique)
        if(jg[ATL[L]][ATL[C]]==X||jg[ATL[L]][ATL[C]]==O){
            system("color CF");
            printf("\n [S]: Local Invalido !!!");
        }else{
            if(vez==X){
            srand( (unsigned)time(NULL) );
                jg[ATL[L]][ATL[C]]=X;
                tl[ATL[L]][ATL[C]]=Sx;
                tela(O,&jg);
                if(win(O,&jg)!=-3&&win(O,&jg)!=1){
                    for(;;){
                    if(win(X,&jg)==1)break;
                    i=rand() % 10;
                    printf("[%i]",i);
                    if(imp(&jg)!=-1){i=imp(&jg);}
                        if(i==1){
                            if(jg[0][0]==X||jg[0][0]==O)continue;
                            else jg[0][0]=O;
                            vez=X;
                            tl[0][0]=O;
                            break;
                        }
                        if(i==2){
                            if(jg[0][1]==X||jg[0][1]==O)continue;
                            else jg[0][1]=O;
                            vez=X;
                            tl[0][1]=O;
                            break;
                        }
                        if(i==3){
                            if(jg[0][2]==X||jg[0][2]==O)continue;
                            else jg[0][2]=O;
                            vez=X;
                            tl[0][2]=O;
                            break;
                        }
                        if(i==4){
                            if(jg[1][0]==X||jg[1][0]==O)continue;
                            else jg[1][0]=O;
                            vez=X;
                            tl[1][0]=O;
                            break;
                        }
                        if(i==5){
                            if(jg[1][1]==X||jg[1][1]==O)continue;
                            else jg[1][1]=O;
                            vez=X;
                            tl[1][1]=O;
                            break;
                        }
                        if(i==6){
                            if(jg[1][2]==X||jg[1][2]==O)continue;
                            else jg[1][2]=O;
                            vez=X;
                            tl[1][2]=O;
                            break;
                        }
                        if(i==7){
                            if(jg[2][0]==X||jg[2][0]==O)continue;
                            else jg[2][0]=O;
                            vez=X;
                            tl[2][0]=O;
                            break;
                        }
                        if(i==8){
                            if(jg[2][1]==X||jg[2][1]==O)continue;
                            else jg[2][1]=O;
                            vez=X;
                            tl[2][1]=O;
                            break;
                        }
                        if(i==9){
                            if(jg[2][2]==X||jg[2][2]==O)continue;
                            else jg[2][2]=O;
                            vez=X;
                            tl[2][2]=O;
                            break;
                        }
                    }}
                //printf("Numero Aleatorio: %d\n",rand() % 10);
                if(win(vez,&jg)==1){
                    tela(vez,&tl);
                    system("color FD");
                    printf("\n   [S]: X Ganhou a partida !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(vez,&jg)==-3){
                    system("color CF");
                    vez = 3;
                    tela(vez,&tl);
                    printf("\n   [S]: O Jogo deu Velha !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(O,&jg)==1){
                system("color CF");
                    vez = O;
                    tela(vez,&tl);
                    printf("\n   [S]: O Ganhou a partida !!! !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(O,&jg)==-3){
                system("color CF");
                    vez = 3;
                    tela(vez,&tl);
                    printf("\n   [S]: O Jogo deu Velha !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }
                vez=X;
                tela(vez,&tl);
            }
        }
    }
    if(tecla==72||tecla==119){//Cima
        ATR[C]=ATL[C];
        ATR[L]=ATL[L];
        if(ATL[L]==0){
                ATL[L]=2;
        }else if(ATL[L]>0){
                ATL[L]--;
        }

        tl[ATR[L]][ATR[C]]=(tl[ATR[L]][ATR[C]]==S)?0:(tl[ATR[L]][ATR[C]]==Sx)?X:(tl[ATR[L]][ATR[C]]==So)?O:0;
        tl[ATL[L]][ATL[C]]=(tl[ATL[L]][ATL[C]]==X)?Sx:(tl[ATL[L]][ATL[C]]==O)?So:(tl[ATL[L]][ATL[C]]==0)?S:0;
        tela(vez,&tl);
    }
    if(tecla==80||tecla==115){//Baixo
        ATR[C]=ATL[C];
        ATR[L]=ATL[L];
        if(ATL[L]<2){
                ATL[L]++;
        }else if(ATL[L]==2){
                ATL[L]=0;
        }
        tl[ATR[L]][ATR[C]]=(tl[ATR[L]][ATR[C]]==S)?0:(tl[ATR[L]][ATR[C]]==Sx)?X:(tl[ATR[L]][ATR[C]]==So)?O:0;
        tl[ATL[L]][ATL[C]]=(tl[ATL[L]][ATL[C]]==X)?Sx:(tl[ATL[L]][ATL[C]]==O)?So:(tl[ATL[L]][ATL[C]]==0)?S:0;
        tela(vez,&tl);
    }
    if(tecla==77||tecla==100){//Direita
        ATR[C]=ATL[C];
        ATR[L]=ATL[L];
        if(ATL[C]<2){
                ATL[C]++;
        }else if(ATL[C]>=2){
                ATL[C]=0;
        }
        tl[ATR[L]][ATR[C]]=(tl[ATR[L]][ATR[C]]==S)?0:(tl[ATR[L]][ATR[C]]==Sx)?X:(tl[ATR[L]][ATR[C]]==So)?O:0;
        tl[ATL[L]][ATL[C]]=(tl[ATL[L]][ATL[C]]==X)?Sx:(tl[ATL[L]][ATL[C]]==O)?So:(tl[ATL[L]][ATL[C]]==0)?S:0;
        tela(vez,&tl);
    }
    if(tecla==75||tecla==97){//Esquerda
        ATR[C]=ATL[C];
        ATR[L]=ATL[L];
        if(ATL[C]==0){
                ATL[C]=2;
        }else if(ATL[C]>0){
                ATL[C]--;
        }
        tl[ATR[L]][ATR[C]]=(tl[ATR[L]][ATR[C]]==S)?0:(tl[ATR[L]][ATR[C]]==Sx)?X:(tl[ATR[L]][ATR[C]]==So)?O:0;
        tl[ATL[L]][ATL[C]]=(tl[ATL[L]][ATL[C]]==X)?Sx:(tl[ATL[L]][ATL[C]]==O)?So:(tl[ATL[L]][ATL[C]]==0)?S:0;
        tela(vez,&tl);
    }
}
}else if(a==1){
a=-70;
mov=0;
titulo();
char p1[30],p2[30];
printf("\n\n   [S] Oi ? vamos decidir quem deve iniciar jogando ?\n");
printf("\n   [Player 1] Digite o nome do Player 1: ");
scanf("%s",&p1);
printf("\n   [Player 2] Digite o nome do Player 2: ");
scanf("%s",&p2);
int tl[MAX][MAX] = {0},jg[MAX][MAX] = {0},tecla,ATL[2]= {0},ATR[2]= {0};
int vez=X;//X start;
tl[0][0]=S;//Selecao Inicial
tela(X,&tl);
for(;;){
tecla = getch();
    if((tecla==13||tecla==32)||(tecla==120&&vez==X)||(tecla==111&&vez==O)){//Enter ou Espaco (Clique)
        if(jg[ATL[L]][ATL[C]]==X||jg[ATL[L]][ATL[C]]==O){
            system("color CF");
            printf("\n [S]: Local Invalido !!!");
        }else{
            if(vez==X){
                jg[ATL[L]][ATL[C]]=X;
                tl[ATL[L]][ATL[C]]=Sx;
                if(win(vez,&jg)==1){
                    tela(vez,&tl);
                    system("color FD");
                    printf("\n   [S]: X Ganhou a partida !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(vez,&jg)==-3){
                    system("color CF");
                    vez = 3;
                    tela(vez,&tl);
                    printf("\n   [S]: O Jogo deu Velha !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }
                vez=O;
                tela(vez,&tl);
            }else if(vez==O){
                jg[ATL[L]][ATL[C]]=O;
                tl[ATL[L]][ATL[C]]=So;
                if(win(vez,&jg)==1){
                    tela(vez,&tl);
                    system("color F3");
                    printf("\n   [S]: O Ganhou a partida !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(vez,&jg)==-3){
                    system("color CF");
                    vez = 3;
                    tela(vez,&tl);
                    printf("\n   [S]: O Jogo deu Velha !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }
                vez=X;
                tela(vez,&tl);
            }
        }
    }
    if(tecla==72||tecla==119){//Cima
        ATR[C]=ATL[C];
        ATR[L]=ATL[L];
        if(ATL[L]==0){
                ATL[L]=2;
        }else if(ATL[L]>0){
                ATL[L]--;
        }

        tl[ATR[L]][ATR[C]]=(tl[ATR[L]][ATR[C]]==S)?0:(tl[ATR[L]][ATR[C]]==Sx)?X:(tl[ATR[L]][ATR[C]]==So)?O:0;
        tl[ATL[L]][ATL[C]]=(tl[ATL[L]][ATL[C]]==X)?Sx:(tl[ATL[L]][ATL[C]]==O)?So:(tl[ATL[L]][ATL[C]]==0)?S:0;
        tela(vez,&tl);
    }
    if(tecla==80||tecla==115){//Baixo
        ATR[C]=ATL[C];
        ATR[L]=ATL[L];
        if(ATL[L]<2){
                ATL[L]++;
        }else if(ATL[L]==2){
                ATL[L]=0;
        }
        tl[ATR[L]][ATR[C]]=(tl[ATR[L]][ATR[C]]==S)?0:(tl[ATR[L]][ATR[C]]==Sx)?X:(tl[ATR[L]][ATR[C]]==So)?O:0;
        tl[ATL[L]][ATL[C]]=(tl[ATL[L]][ATL[C]]==X)?Sx:(tl[ATL[L]][ATL[C]]==O)?So:(tl[ATL[L]][ATL[C]]==0)?S:0;
        tela(vez,&tl);
    }
    if(tecla==77||tecla==100){//Direita
        ATR[C]=ATL[C];
        ATR[L]=ATL[L];
        if(ATL[C]<2){
                ATL[C]++;
        }else if(ATL[C]>=2){
                ATL[C]=0;
        }
        tl[ATR[L]][ATR[C]]=(tl[ATR[L]][ATR[C]]==S)?0:(tl[ATR[L]][ATR[C]]==Sx)?X:(tl[ATR[L]][ATR[C]]==So)?O:0;
        tl[ATL[L]][ATL[C]]=(tl[ATL[L]][ATL[C]]==X)?Sx:(tl[ATL[L]][ATL[C]]==O)?So:(tl[ATL[L]][ATL[C]]==0)?S:0;
        tela(vez,&tl);
    }
    if(tecla==75||tecla==97){//Esquerda
        ATR[C]=ATL[C];
        ATR[L]=ATL[L];
        if(ATL[C]==0){
                ATL[C]=2;
        }else if(ATL[C]>0){
                ATL[C]--;
        }
        tl[ATR[L]][ATR[C]]=(tl[ATR[L]][ATR[C]]==S)?0:(tl[ATR[L]][ATR[C]]==Sx)?X:(tl[ATR[L]][ATR[C]]==So)?O:0;
        tl[ATL[L]][ATL[C]]=(tl[ATL[L]][ATL[C]]==X)?Sx:(tl[ATL[L]][ATL[C]]==O)?So:(tl[ATL[L]][ATL[C]]==0)?S:0;
        tela(vez,&tl);
    }
}}else if(a==2){
a=-70;
srand( (unsigned)time(NULL) );
int i=rand() % 10;
mov=0;
system("cls");
//srand( (unsigned)time(NULL) );
//printf("Numero Aleatorio: %d\n",rand() % 10);
a=-70;
mov=0;
int tl[MAX][MAX] = {0},jg[MAX][MAX] = {0},tecla,ATL[2]= {0},ATR[2]= {0};
int vez=X;//X start;
tl[0][0]=S;//Selecao Inicial
tela(X,&tl);
for(;;){
tecla = getch();
    if((tecla==13||tecla==32)||(tecla==120&&vez==X)||(tecla==111&&vez==O)){//Enter ou Espaco (Clique)
        if(jg[ATL[L]][ATL[C]]==X||jg[ATL[L]][ATL[C]]==O){
            system("color CF");
            printf("\n [S]: Local Invalido !!!");
        }else{
            if(vez==X){
            srand( (unsigned)time(NULL) );
                jg[ATL[L]][ATL[C]]=X;
                tl[ATL[L]][ATL[C]]=Sx;
                tela(O,&jg);
                if(win(O,&jg)!=-3&&win(O,&jg)!=1){
                    for(;;){
                    i=rand() % 10;
                        if(i==1){
                            if(jg[0][0]==X||jg[0][0]==O)continue;
                            else jg[0][0]=O;
                            vez=X;
                            tl[0][0]=O;
                            break;
                        }
                        if(i==2){
                            if(jg[0][1]==X||jg[0][1]==O)continue;
                            else jg[0][1]=O;
                            vez=X;
                            tl[0][1]=O;
                            break;
                        }
                        if(i==3){
                            if(jg[0][2]==X||jg[0][2]==O)continue;
                            else jg[0][2]=O;
                            vez=X;
                            tl[0][2]=O;
                            break;
                        }
                        if(i==4){
                            if(jg[1][0]==X||jg[1][0]==O)continue;
                            else jg[1][0]=O;
                            vez=X;
                            tl[1][0]=O;
                            break;
                        }
                        if(i==5){
                            if(jg[1][1]==X||jg[1][1]==O)continue;
                            else jg[1][1]=O;
                            vez=X;
                            tl[1][1]=O;
                            break;
                        }
                        if(i==6){
                            if(jg[1][2]==X||jg[1][2]==O)continue;
                            else jg[1][2]=O;
                            vez=X;
                            tl[1][2]=O;
                            break;
                        }
                        if(i==7){
                            if(jg[2][0]==X||jg[2][0]==O)continue;
                            else jg[2][0]=O;
                            vez=X;
                            tl[2][0]=O;
                            break;
                        }
                        if(i==8){
                            if(jg[2][1]==X||jg[2][1]==O)continue;
                            else jg[2][1]=O;
                            vez=X;
                            tl[2][1]=O;
                            break;
                        }
                        if(i==9){
                            if(jg[2][2]==X||jg[2][2]==O)continue;
                            else jg[2][2]=O;
                            vez=X;
                            tl[2][2]=O;
                            break;
                        }
                    }}
                //printf("Numero Aleatorio: %d\n",rand() % 10);
                if(win(vez,&jg)==1){
                    tela(vez,&tl);
                    system("color FD");
                    printf("\n   [S]: X Ganhou a partida !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(vez,&jg)==-3){
                    system("color CF");
                    vez = 3;
                    tela(vez,&tl);
                    printf("\n   [S]: O Jogo deu Velha !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(O,&jg)==1){
                system("color CF");
                    vez = O;
                    tela(vez,&tl);
                    printf("\n   [S]: O Ganhou a partida !!! !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }else if(win(O,&jg)==-3){
                system("color CF");
                    vez = 3;
                    tela(vez,&tl);
                    printf("\n   [S]: O Jogo deu Velha !!!\n\n");
                    system("pause");
                    sleep(1);
                    break;
                }
                vez=X;
                tela(vez,&tl);
            }
        }
    }
    if(tecla==72||tecla==119){//Cima
        ATR[C]=ATL[C];
        ATR[L]=ATL[L];
        if(ATL[L]==0){
                ATL[L]=2;
        }else if(ATL[L]>0){
                ATL[L]--;
        }

        tl[ATR[L]][ATR[C]]=(tl[ATR[L]][ATR[C]]==S)?0:(tl[ATR[L]][ATR[C]]==Sx)?X:(tl[ATR[L]][ATR[C]]==So)?O:0;
        tl[ATL[L]][ATL[C]]=(tl[ATL[L]][ATL[C]]==X)?Sx:(tl[ATL[L]][ATL[C]]==O)?So:(tl[ATL[L]][ATL[C]]==0)?S:0;
        tela(vez,&tl);
    }
    if(tecla==80||tecla==115){//Baixo
        ATR[C]=ATL[C];
        ATR[L]=ATL[L];
        if(ATL[L]<2){
                ATL[L]++;
        }else if(ATL[L]==2){
                ATL[L]=0;
        }
        tl[ATR[L]][ATR[C]]=(tl[ATR[L]][ATR[C]]==S)?0:(tl[ATR[L]][ATR[C]]==Sx)?X:(tl[ATR[L]][ATR[C]]==So)?O:0;
        tl[ATL[L]][ATL[C]]=(tl[ATL[L]][ATL[C]]==X)?Sx:(tl[ATL[L]][ATL[C]]==O)?So:(tl[ATL[L]][ATL[C]]==0)?S:0;
        tela(vez,&tl);
    }
    if(tecla==77||tecla==100){//Direita
        ATR[C]=ATL[C];
        ATR[L]=ATL[L];
        if(ATL[C]<2){
                ATL[C]++;
        }else if(ATL[C]>=2){
                ATL[C]=0;
        }
        tl[ATR[L]][ATR[C]]=(tl[ATR[L]][ATR[C]]==S)?0:(tl[ATR[L]][ATR[C]]==Sx)?X:(tl[ATR[L]][ATR[C]]==So)?O:0;
        tl[ATL[L]][ATL[C]]=(tl[ATL[L]][ATL[C]]==X)?Sx:(tl[ATL[L]][ATL[C]]==O)?So:(tl[ATL[L]][ATL[C]]==0)?S:0;
        tela(vez,&tl);
    }
    if(tecla==75||tecla==97){//Esquerda
        ATR[C]=ATL[C];
        ATR[L]=ATL[L];
        if(ATL[C]==0){
                ATL[C]=2;
        }else if(ATL[C]>0){
                ATL[C]--;
        }
        tl[ATR[L]][ATR[C]]=(tl[ATR[L]][ATR[C]]==S)?0:(tl[ATR[L]][ATR[C]]==Sx)?X:(tl[ATR[L]][ATR[C]]==So)?O:0;
        tl[ATL[L]][ATL[C]]=(tl[ATL[L]][ATL[C]]==X)?Sx:(tl[ATL[L]][ATL[C]]==O)?So:(tl[ATL[L]][ATL[C]]==0)?S:0;
        tela(vez,&tl);
    }
}
}else if(a==-1){
printf("\n[Ass] %s %c%c...",ass,lc[0],lc[1]);
sleep(2);
printf("\n[S] saindo...");
break;
}
}
printf("\n\n");
system("pause");
}
