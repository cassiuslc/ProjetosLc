#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int show(int * jogo[][MAX]){
system("cls");
printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= JOGO DA VELHA =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
printf("\n\n\n");// X = 1 | O = -1 | [ ] = 3 | [X] = 4 | [O] = 5
printf("\t\t\t\t%s|%s|%s\n",((jogo[0][0]==1)?" X ":(jogo[0][0]==-1)?" O ":(jogo[0][0]==3)?"[ ]":(jogo[0][0]==4)?"[X]":(jogo[0][0]==5)?"[O]":"   "),((jogo[0][1]==1)?" X ":(jogo[0][1]==-1)?" O ":(jogo[0][1]==3)?"[ ]":(jogo[0][1]==4)?"[X]":(jogo[0][1]==5)?"[O]":"   "),((jogo[0][2]==1)?" X ":(jogo[0][2]==-1)?" O ":(jogo[0][2]==3)?"[ ]":(jogo[0][2]==4)?"[X]":(jogo[0][2]==5)?"[O]":"   "));
printf("\t\t\t\t---|---|---\n");
printf("\t\t\t\t%s|%s|%s\n",((jogo[1][0]==1)?" X ":(jogo[1][0]==-1)?" O ":(jogo[1][0]==3)?"[ ]":(jogo[1][0]==4)?"[X]":(jogo[1][0]==5)?"[O]":"   "),((jogo[1][1]==1)?" X ":(jogo[1][1]==-1)?" O ":(jogo[1][1]==3)?"[ ]":(jogo[1][1]==4)?"[X]":(jogo[1][1]==5)?"[O]":"   "),((jogo[1][2]==1)?" X ":(jogo[1][2]==-1)?" O ":(jogo[1][2]==3)?"[ ]":(jogo[1][2]==4)?"[X]":(jogo[1][2]==5)?"[O]":"   "));
printf("\t\t\t\t---|---|---\n");
printf("\t\t\t\t%s|%s|%s\n",((jogo[2][0]==1)?" X ":(jogo[2][0]==-1)?" O ":(jogo[2][0]==3)?"[ ]":(jogo[2][0]==4)?"[X]":(jogo[2][0]==5)?"[O]":"   "),((jogo[2][1]==1)?" X ":(jogo[2][1]==-1)?" O ":(jogo[2][1]==3)?"[ ]":(jogo[2][1]==4)?"[X]":(jogo[2][1]==5)?"[O]":"   "),((jogo[2][2]==1)?" X ":(jogo[2][2]==-1)?" O ":(jogo[2][2]==3)?"[ ]":(jogo[2][2]==4)?"[X]":(jogo[2][2]==5)?"[O]":"   "));
}
void sel(int * la,int l,int * ant,int * jogo[][MAX]){
switch(*ant){
        case -1:
        jogo[l][0]=3;
        if(*ant!=-1)jogo[*la][*ant]= 0;
        *ant=0;
        *la=l;
        break;
        case 0:
        jogo[l][1]=3;
        if(*ant!=-1)jogo[*la][*ant]= 0;
        *ant=1;
        *la=l;
        break;
        case 1:
        jogo[l][2]=3;
        if(*ant!=-1)jogo[*la][*ant]= 0;
        *ant=2;
        *la=l;
        break;
        case 2:
        jogo[l][0]=3;
        if(*ant!=-1)jogo[*la][*ant]= 0;
        *ant=0;
        *la=l;
        break;
    default:
    printf("");
    }
}
void seld(int * la,int l,int * ant,int * jogo[][MAX]){
switch(*ant){
        case -1:
        jogo[l][2]=3;
        if(*ant!=-1)jogo[*la][*ant]= 0;
        *ant=0;
        *la=l;
        break;
        case 0:
        jogo[l][2]=3;
        if(*ant!=-1)jogo[*la][*ant]= 0;
        *ant=2;
        *la=l;
        break;
        case 1:
        jogo[l][0]=3;
        if(*ant!=-1)jogo[*la][*ant]= 0;
        *ant=0;
        *la=l;
        break;
        case 2:
        jogo[l][1]=3;
        if(*ant!=-1)jogo[*la][*ant]= 0;
        *ant=1;
        *la=l;
        break;
    default:
    printf("");
    }
}
void main(){
int jogo[MAX][MAX];
int tecla=0,ant=-1,linha=0,la=0;
show(&jogo);
for(;;){
if(tecla==13){
    show(&jogo);
    printf("Local: [%i][%i] ",linha,ant);
}
if(tecla==80){
    if(linha>=0&&linha<2){
        la=linha;
        linha++;
        sel(&la,linha,&ant,&jogo);
        show(&jogo);
    }else if(linha==2){
        la=linha;
        linha=0;
        sel(&la,linha,&ant,&jogo);
        show(&jogo);
    }
}
if(tecla==72){
    if(linha==0){
        la=linha;
        linha=2;
        sel(&la,linha,&ant,&jogo);
        show(&jogo);
    }else if(linha<=2&&linha>0){
        la=linha;
        linha--;
        sel(&la,linha,&ant,&jogo);
        show(&jogo);
    }
}

if(tecla==77){
sel(&la,linha,&ant,&jogo);
show(&jogo);
}
if(tecla==75){
seld(&la,linha,&ant,&jogo);
show(&jogo);
}
tecla = getch();
//printf("%s",((tecla==77)?"Direta ":(tecla==72)?"Cima ":(tecla==80)?"Baixo ":(tecla==75)?"Esquerda ":""));
}
}
