// Jogo da Velha em C, criada com suporte do ChatGPT.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char matrix[3][3];

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

int main(void)
{
  setlocale(LC_ALL, "Portuguese");
  char done;

  printf("Este � o jogo da velha.\n");
  printf("Sua Jogada � marcada pelo 'X'.\n");
  printf("Voc� estar� jogando contra o computador.\n");

  done =  ' ';
  init_matrix();

  do {
    disp_matrix();
    get_player_move();
    done = check(); 
    if(done!= ' ') break; 
    get_computer_move();
    done = check(); 
  } while(done== ' ');

  if(done=='X') printf("Voc� ganhou!\n");
  else printf("Voc� Perdeu!!!!\n");
  disp_matrix(); 

  return 0;
}

void init_matrix(void)
{
  int i, j;

  for(i=0; i<3; i++)
    for(j=0; j<3; j++) matrix[i][j] =  ' ';
}

void get_player_move(void)
{
  int x, y;

  printf("Digite as coordenadas para o X:\n");
  scanf("%d%*c%d", &x, &y);

  x--; y--;

  if(matrix[x][y]!= ' '){
    printf("Posi��o inv�lida, tente novamente.\n");
    get_player_move();
  }
  else matrix[x][y] = 'X';
}

void get_computer_move(void)
{
  int i, j;
  for(i=0; i<3; i++){
    for(j=0; j<3; j++)
      if(matrix[i][j]==' ') break;
    if(matrix[i][j]==' ') break;
  }

  if(i*j==9)  {
    printf("empate\n");
    exit(0);
  }
  else
    matrix[i][j] = 'O';
}

void disp_matrix(void)
{
  int t;

  for(t=0; t<3; t++) {
    printf(" %c | %c | %c ",matrix[t][0],
            matrix[t][1], matrix [t][2]);
    if(t!=2) printf("\n---|---|---\n");
  }
  printf("\n");
}

char check(void)
{
  int i;

  for(i=0; i<3; i++)  
    if(matrix[i][0]==matrix[i][1] &&
       matrix[i][0]==matrix[i][2]) return matrix[i][0];

  for(i=0; i<3; i++)  
    if(matrix[0][i]==matrix[1][i] &&
       matrix[0][i]==matrix[2][i]) return matrix[0][i];

  if(matrix[0][0]==matrix[1][1] &&
     matrix[1][1]==matrix[2][2])
       return matrix[0][0];

  if(matrix[0][2]==matrix[1][1] &&
     matrix[1][1]==matrix[2][0])
       return matrix[0][2];

  return ' ';
}