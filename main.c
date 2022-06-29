#include <stdlib.h>
#include <stdio.h>
#include "cards.h"
#include <string.h>
#include <stdbool.h>


char* qualValor(int valor)
{
  switch (valor) {
    case 1:
      return "A";
    case 11:
      return "J";
    case 12:
      return "Q";
    case 13:
      return "K";
    default:
      return "INVÁLIDO";
  }
}

char* qualNaipe(int naipe)
{
  switch (naipe) {
    case 0:
      return "OUROS";
    case 1:
      return "ESPADAS";
    case 2:
      return "COPAS";
    case 3:
      return "BASTOS";
    default:
      return "INVÁLIDO";
  }
}

bool cartaUsada(int cartas[][2], int pos)
{
  return cartas[pos][0] == 999;
}

bool posOk(CARTA_T Tabuleiro[5][5], int lin, int col)
{
  return Tabuleiro[lin][col].valor == -1;
}

void auxEspacamento(CARTA_T Tabuleiro[5][5], int lin, int col)
{
  if (Tabuleiro[lin][col].valor==10) {
    if (strlen(qualNaipe(Tabuleiro[lin][col].naipe))==5) {
      printf("   ");
    } else if (strlen(qualNaipe(Tabuleiro[lin][col].naipe))==6) {
       printf("  ");
    } else if (strlen(qualNaipe(Tabuleiro[lin][col].naipe))==7) {
      printf(" ");
    }
  } else if (Tabuleiro[lin][col].valor!=10 && Tabuleiro[lin][col].valor != -1){
    if (strlen(qualNaipe(Tabuleiro[lin][col].naipe))==5) {
      printf("    ");
    } else if (strlen(qualNaipe(Tabuleiro[lin][col].naipe))==6) {
      printf("   ");
    } else if (strlen(qualNaipe(Tabuleiro[lin][col].naipe))==7) {
      printf("  ");
    }
  } else {
    printf("      ");
  }
}

void imprimeTabuleiro(CARTA_T Tabuleiro[5][5])
{
  int i, j, k, m, n, p;
  
  printf("\n");
  for (i=0;i<5+((5/3)+8);i++) printf(" ");
  printf("                     ");
  printf("» POKER SQUARE « \n\n");
  printf("Coluna >");
  printf("        ");

  for (j=0;j<5;j++) {
    printf("%d            ", j+1);
  }
  printf("\n");
  printf("Linha V");
  printf("   ");
  for (k=0;k<5;k++) {
    if (k<9) {
      printf("==============");
    } else {
      printf("============");
    }
  }
  printf("\n");
 
  for (m=0;m<5;m++) {
    if (m < 10) {
      printf("     ");
      printf("%d", m+1);
      printf("   ");
      printf("|   ");
      for (n=0;n<5;n++) {
        if(Tabuleiro[m][n].valor > 1 && Tabuleiro[m][n].valor <= 10) {
          printf("[%i %s]", Tabuleiro[m][n].valor, qualNaipe(Tabuleiro[m][n].naipe));
        } else if (Tabuleiro[m][n].valor == 1 || Tabuleiro[m][n].valor >= 11) {
          printf("[%s %s]", qualValor(Tabuleiro[m][n].valor), qualNaipe(Tabuleiro[m][n].naipe));
        } else {
          printf("[%s]", "Vazio");
        }
        auxEspacamento(Tabuleiro, m, n);
      }
      printf("|");
      printf("\n");
    }
  }
  printf("         ");
  for (p=0;p<5;p++) {
    if (p<9) {
      printf("==============");
    } else {
      printf("============");
    }
  }
  printf("\n");
}

void imprimeCartas(int cartas[][2], int inicio)
{
  int inicio_for = inicio;
  int final = inicio+5;
  bool flag = false;
  int k, l;
  
  printf("\n                     ");
  printf("Você recebeu as seguintes cartas:");
  printf("\n");
  
  for(k=0;k<5;k++) {
    printf("   ");
    printf("------------");
  }
  printf("\n");
  for(k=0;k<5;k++) {
    printf("   ");
    printf("|");
    printf(" %i° Carta ", k+1);
    printf("|");
  }
    printf("\n");
  for(k=0;k<5;k++) {
    printf("   ");
    printf("|");
    printf("          ");
    printf("|");
  }
    printf("\n");
  for(l=inicio_for;l<final;l++) {
    printf("   ");
    printf("| ");
    if (cartas[l][0] == 10) {
      printf("   ");
      printf("%i", cartas[l][0]);
      printf("   ");
    } else if (cartas[l][0] != 10 && !cartaUsada(cartas, l)) {
      printf("   ");
      if(cartas[l][0] > 1 && cartas[l][0] <10) {
        printf("%i", cartas[l][0]);
      } else {
        printf("%s", qualValor(cartas[l][0]));
      }
      printf("    ");
    } else {
      printf("   ");
      printf("%s", "JÁ");
      printf("   ");
    }
    printf(" ");
    printf("|");
  }
    printf("\n");
  for(k=0;k<5;k++) {
    printf("   ");
    printf("|");
    printf("          ");
    printf("|");
  }
    printf("\n");
  for(l=inicio_for;l<final;l++) {
    printf("   ");
    printf("|  ");
    if (!cartaUsada(cartas, l)) {
      printf("%s", qualNaipe(cartas[l][1]));
    } else {
      printf("%s", "USADA");
      flag = true;
    }
    if(strlen(qualNaipe(cartas[l][1]))==5 && !flag) {
      printf("  ");
    } else if(strlen(qualNaipe(cartas[l][1]))==6 && !flag) {
      printf(" ");
    }
    if(flag) {
      printf("  ");
      flag=false;
    }
    printf(" ");
    printf("|");
  }
  printf("\n");
  for(k=0;k<5;k++) {
    printf("   ");
    printf("|");
    printf("          ");
    printf("|");
  }
  printf("\n");
  for(k=0;k<5;k++) {
    printf("   ");
    printf("|");
    printf("          ");
    printf("|");
  }
    printf("\n");
  for(k=0;k<5;k++) {
    printf("   ");
    printf("------------");
  }
}

void zeraMatriz(CARTA_T Tabuleiro[5][5])
{
  int i, j;
  for(i=0; i<5; i++) {
    for(j=0; j<5; j++) {
      Tabuleiro[i][j].valor = -1;
      Tabuleiro[i][j].naipe = -1;
    }
  }
}

void trocaCarta(CARTA_T Tabuleiro[5][5])
{
  CARTA_T aux[2];
  int lin = 0, lin2 = 0, col = 0, col2 = 0, auxtroca = 0, nrtroca = 0;
  
  printf("\n\nVocê tem direito a duas trocas, quer realizar?\n");
  printf("Digite 1 para SIM e 0 para NAO:\n");
  scanf("%d", &auxtroca);
  if(auxtroca == 0) return;
 
 while(nrtroca!=2) {
    if(nrtroca==1) {
      printf("Você tem mais uma troca, quer realizar?\n");
      printf("Digite 1 para SIM e 0 para NAO:\n");
      scanf("%d", &auxtroca);
      if(auxtroca == 0) return;
    }
    printf("Digite a LINHA e a COLUNA da PRIMEIRA CARTA:\n");
    scanf("%d %d", &lin, &col);
    printf("Digite a LINHA e a COLUNA da SEGUNDA CARTA:\n");
    scanf("%d %d", &lin2, &col2);
    aux[0].valor = Tabuleiro[lin-1][col-1].valor;
    aux[0].naipe = Tabuleiro[lin-1][col-1].naipe;
    aux[1].valor = Tabuleiro[lin2-1][col2-1].valor;
    aux[1].naipe = Tabuleiro[lin2-1][col2-1].naipe;
    Tabuleiro[lin-1][col-1].valor = aux[1].valor;
    Tabuleiro[lin-1][col-1].naipe = aux[1].naipe;
    Tabuleiro[lin2-1][col2-1].valor = aux[0].valor;
    Tabuleiro[lin2-1][col2-1].naipe = aux[0].naipe;
    imprimeTabuleiro(Tabuleiro);
    nrtroca++;
  }
  
}

void efetuaJogada(CARTA_T Tabuleiro[5][5], int cartas[][2], int inicio)
{
  int nrJogadas = 0;
  int aux_inicio = inicio;
  while (nrJogadas < 5) {
    int aux_jogada = 0;
    int lin = 0;
    int col = 0;
    printf("\n\nDigite o número da carta que deseja jogar (ex: 1):\n");
    scanf("%d", &aux_jogada);
    while(cartaUsada(cartas, aux_jogada-1+inicio)) {
      printf("\n\nEssa carta já foi usada - digite novamente outra carta:\n");
      scanf("%d", &aux_jogada);
    }
    printf("Digite a LINHA e a COLUNA do tabuleiro que deseja colocar a carta (ex:1 2):\n");
    scanf("%d %d", &lin, &col);
    while(lin > 5 || lin < 1 || col > 5 || col < 1) {
      printf("\n\nLINHA ou COLUNA inválida - digite novamente de acordo com o tabuleiro:\n");
      scanf("%d %d", &lin, &col);
    }
    
    if(aux_jogada == 1 && posOk(Tabuleiro, lin-1, col-1)) {
        Tabuleiro[lin-1][col-1].valor = cartas[0+inicio][0];
        Tabuleiro[lin-1][col-1].naipe = cartas[0+inicio][1];
        cartas[0+inicio][0] = 999;
        nrJogadas++;
    } else if(aux_jogada == 2 && posOk(Tabuleiro, lin-1, col-1)) {
        Tabuleiro[lin-1][col-1].valor = cartas[1+inicio][0];
        Tabuleiro[lin-1][col-1].naipe = cartas[1+inicio][1];
        cartas[1+inicio][0] = 999;
        nrJogadas++;
    } else if (aux_jogada == 3 && posOk(Tabuleiro, lin-1, col-1)) {
        Tabuleiro[lin-1][col-1].valor = cartas[2+inicio][0];
        Tabuleiro[lin-1][col-1].naipe = cartas[2+inicio][1];
        cartas[2+inicio][0] = 999;
        nrJogadas++;
    } else if (aux_jogada == 4 && posOk(Tabuleiro, lin-1, col-1)) {
        Tabuleiro[lin-1][col-1].valor = cartas[3+inicio][0];
        Tabuleiro[lin-1][col-1].naipe = cartas[3+inicio][1];
        cartas[3+inicio][0] = 999;
        nrJogadas++;
    } else if (aux_jogada == 5 && posOk(Tabuleiro, lin-1, col-1)) {
        Tabuleiro[lin-1][col-1].valor = cartas[4+inicio][0];
        Tabuleiro[lin-1][col-1].naipe = cartas[4+inicio][1];
        cartas[4+inicio][0] = 999;
        nrJogadas++;
    } else {
        printf("JOGADA INVÁLIDA TENTE NOVAMENTE");
        efetuaJogada(Tabuleiro, cartas, aux_inicio);
    }
    imprimeTabuleiro(Tabuleiro);
    imprimeCartas(cartas, aux_inicio);
  }
}

void preparaCinco(int aux_cartas[][2], int cartas[][2], int inicio) {
  int final = inicio+5;
  
  while(inicio != final) {
    aux_cartas[inicio][0] = cartas[inicio][0];
    aux_cartas[inicio][1] = cartas[inicio][1];
    inicio++;
  }
}

void ordenaMao(CARTA_T mao[5])
{
  int i, j, temp;
  for(i=0; i<5; i++) {
    for(j=i+1; j<5; j++) {
      if(mao[j].valor <mao[i].valor) {
        temp = mao[i].valor;
        mao[i].valor = mao[j].valor;
        mao[j].valor = temp;
      }
    }
  }
}

void realizaContagem(CARTA_T Tabuleiro[5][5])
{
  int i, j, pontos = 0;
  CARTA_T mao[5];
  
  for(i=0;i<5;i++) {
    for(j=0;j<5;j++) {
      mao[j] = Tabuleiro[i][j];
    }
    ordenaMao(mao);
    pontos += contaPontos(mao);
  }
  
  for(i=0;i<5;i++) {
    for(j=0;j<5;j++) {
      mao[j] = Tabuleiro[j][i];
    }
    ordenaMao(mao);
    pontos += contaPontos(mao);
  }
  
  for(i=0;i<5;i++) {
    mao[i] = Tabuleiro[i][i];
  }
  ordenaMao(mao);
  pontos += contaPontos(mao);
  
  for(i=5;i<1;i--) {
    mao[i] = Tabuleiro[i][i];
  }
  ordenaMao(mao);
  pontos += contaPontos(mao);
  printf("\n\n Você fez: %d \n\n", pontos);
}

void iniciarJogo(CARTA_T Tabuleiro[5][5], int cartas[][2])
{
  int cont = 0, inicio = 0;
  int aux_cartas[TAM_DEQUE][2];
  system("clear");
  printf("O Poker Square vai começar!!!\n\n");
  printf("-> Pressione enter para iniciar. <-");
  getchar();
  system("clear");
  while (cont != 5){
    preparaCinco(aux_cartas, cartas, inicio);
    imprimeTabuleiro(Tabuleiro);
    imprimeCartas(aux_cartas, inicio);
    efetuaJogada(Tabuleiro, aux_cartas, inicio);
    cont++;
    inicio+=5;
  }
  trocaCarta(Tabuleiro);
  imprimeTabuleiro(Tabuleiro);
  realizaContagem(Tabuleiro);
  printf("\n\nO jogo acabou.");
}

int main(){
	int cartas[TAM_DEQUE][2];
	CARTA_T Tabuleiro[5][5];

	criaBaralho(cartas);
	embaralha(cartas, SEMENTE);
  zeraMatriz(Tabuleiro);
  
  iniciarJogo(Tabuleiro, cartas);
	exit(0);
}