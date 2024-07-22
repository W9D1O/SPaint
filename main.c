#include <stdbool.h>
#include <stdio.h>
#include "include/raylib.h"
#include <stdlib.h>

#define pixel 10
#define ancho 80
#define alto 60
typedef struct Nodo{
  Color c;
  int x,y; 
  struct Nodo *sig;
}Nodo;

void list_c(Nodo **pun,int i,int j,Color clr)
{
  Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
  aux->x = i ;
  aux->y = j ;
  aux->c = clr;
  aux->sig = *pun;
  pun = &aux;

}

void mouse(bool m[][ancho],int *i,int *j )
{
  Vector2 Mposi = GetMousePosition();
  int x, y;
  if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
  {
    x = Mposi.x / pixel;
    y = Mposi.y / pixel;
    m[y][x] = true;
    *i = x ;
    *j = y ;
  }
}
void e_color(Color c[], Color *clr, int n, bool *Vf)
{
  n = GetCharPressed();

  if (n >= 48 && n <= 57)
  {
    int num = n - 48;
    printf("Si llega\n");
    *clr = c[num];
    *Vf = true;
  }
  /* else{
   return *clr = c[22];
   }*/
}
void colorear(bool m[][ancho], Color c[], int *n, bool *Vf, Nodo *pun)
{
  Color Clr = BLACK;
  int i,j;
  mouse(m,&i,&j);
  if(m[i][j]){
  list_c(&pun,i,j,Clr);
  }
  if (!*Vf)
  {
    e_color(c, &Clr, *n, Vf);
    printf("*Entra\n");
  }
  printf("%p\n",pun);
  Nodo *aux = pun; 

  while (aux != NULL) { 
    printf("Llego aca %d\n",aux->x);
      if (m[aux->x][aux->y])
      {
        DrawRectangle(aux->x*pixel ,aux->y*pixel , pixel, pixel, aux->c);
        printf("Te rompes despues de aca?\n");
      }
      aux = aux->sig;
  }
}

int main()
{
  bool matrix[alto][ancho] = {false};
  bool Vf = false;
  int num;
  Nodo *pun = NULL;
  Color c[26] = {LIGHTGRAY, GRAY, DARKGRAY, YELLOW, GOLD, ORANGE, PINK, RED, MAROON,
                 GREEN, LIME, DARKGREEN, SKYBLUE, BLUE, DARKBLUE, PURPLE, VIOLET, DARKPURPLE,
                 BEIGE, BROWN, DARKBROWN, WHITE, BLACK, BLANK, MAGENTA, RAYWHITE};

  //  SetTargetFPS(7);
  InitWindow(ancho * pixel, alto * pixel, "Paint de la Salada");
  while (!WindowShouldClose())
  {
    // num = GetKeyPressed();
    // printf("%d\n",getchar());
    BeginDrawing();
    ClearBackground(c[21]);
    colorear(matrix, c, &num, &Vf,pun);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
