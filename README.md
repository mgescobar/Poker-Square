# Poker Square em C

##################################################################
#							  	                                               #
#			                Funcionamento				                       #
#							 	                                                 #
##################################################################

O jogo foi criado de acordo com as regras especificadas no
enunciado do trabalho, de vídeos e do WikiPedia.

Foi adicionado printf's intuitivos para que o jogador não se perca
em suas jogadas, bem como a verificações de possiveis erros como
o de jogadas inválidas (cartas já usadas/fora da matriz tabuleiro).

Não foi modificado os arquivos auxiliares fornecidos pelo professor

O jogador deve utilizar de entradas digitas pelo teclado

@@@@@@@@@@@@@@@@ Estruturas estáticas mais usadas @@@@@@@@@@@@@@@@

@@@ CARTA_T Tabuleiro[5][5] @@@
matriz do tipo struct CARTA_T que contem tudo do tabuleiro

@@@ CARTA_T mao[5] @@@
vetor do tipo struct CARTA_T que é a "mão" contida no tabuleiro

@@@ int cartas[][2] @@@
vetor de cartas, utilizado para armazenar as cartas embaralhadas


##################################################################
#							  	 #
#     Para facilitar a correção do trabalho, realizei a criação	 #
#     de apenas um unico arquivo .c (main.c) que contém todas as #
#     as funções necessarias para se rodar o jogo. 		 #
#								 #
##################################################################
#A declaração das funções implementadas e seus comentários de uso#
##################################################################

//Recebe um número e diz a carta caso
//ela seja "especial"
char* qualValor(int valor)

//Recebe um número e diz qual o naipe
char* qualNaipe(int naipe)

//Recebe o tabuleiro e a posição e verifica se a jogada pode ser efetuada
bool posOk(CARTA_T Tabuleiro[5][5], int lin, int col)

//Função que recebe as cartas do baralho e a posição
//e diz se a carta já foi usada pelo jogador.
bool cartaUsada(int cartas[][2], int pos)

//Função que auxilia no espaçamento da impressão do tabuleiro
void auxEspacamento(CARTA_T Tabuleiro[5][5], int lin, int col)

//Recebe as cartas, as dimensões e imprime o tabuleiro.
void imprimeTabuleiro(CARTA_T Tabuleiro[5][5])

//Recebe as cartas e um auxiliar que dita o inicio do baralho auxiliar
//e serve para tirar as 5 cartas que serão jogadas
void imprimeCartas(int cartas[][2], int inicio)

//Recebe uma estruct/matriz do tipo CARTA_T e zera ela colocando -1 em todas as posições
//para que posteriormente não seja confundido com cartas
void zeraMatriz(CARTA_T Tabuleiro[5][5])

//Recebe o tabuleiro, as cartas ja embaralhadas e a variavel inicio que irá auxiliar
//a dar a posição do inicio do baralho auxiliar de 5 cartas.
//irá ler a jogada e executar enquanto chama as funções para imprimir o tabuleiro
void efetuaJogada(CARTA_T Tabuleiro[5][5], int cartas[][2], int inicio)

//Recebe um vetor auxiliar de baralho, o baralho original já devidamente embaralhado e o inicio
//e prepara o auxiliar com as 5 cartas de acordo com o inicio
void preparaCinco(int aux_cartas[][2], int cartas[][2], int inicio)

//Recebe uma mao e a ordena ascendentemente por valor
void ordenaMao(CARTA_T mao)

//Recebe o tabuleiro e realiza a contagem das maos, printando o resultado dos pontos no final.
void realizaContagem(CARTA_T Tabuleiro[5][5])

//Recebe o tabuleiro matriz do tipo CARTA_T, o baralho de cartas para a retirada e uma mao do tipo CARTA_T
//e realiza as chamadas de função para se jogar o jogo.
void iniciarJogo(CARTA_T Tabuleiro[5][5], int cartas[][2], CARTA_T mao[5])

//Recebe o tabuleiro e realiza a troca se o jogador preferir
trocaCarta(CARTA_T Tabuleiro[5][5])

##################################################################
