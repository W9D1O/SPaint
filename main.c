#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>

#define pixel 10
#define ancho 80
#define alto 60
typedef struct Nodo{
  Color c;
  int x,y; 
  struct Nodo *sig;
}Nodo;

Nodo *list_c(Nodo *pun,int i,int j,Color clr)
{
  Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
  aux->x = i ;
  aux->y = j ;
  aux->c = clr;
  aux->sig = pun;
  return aux;

}

void mouse(int *j,int *i )
{
  Vector2 Mposi = GetMousePosition();
  int x, y;
  if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
  {
    x = Mposi.x / pixel;
    y = Mposi.y / pixel;
    *j = x ;
    *i = y ;
    
  }
}

void e_color(Color c[], Color *clr, int n, bool *Vf)
{
  n = GetCharPressed();

  if (n >= 48 && n <= 57)
  {
    int num = n - 48;
    *clr = c[num];
    *Vf = false;
  }
  
}

void colorear(Color c[], int *n, bool *Vf, Nodo *pun,int *j,int *i,Color *Clr)
{
  mouse(i,j);
  if (!*Vf)
  {
    e_color(c, Clr, *n, Vf);
  }
  Nodo *aux = pun; 
  int cont = 0;
  while (aux != NULL) { 
      DrawRectangle(aux->x*pixel ,aux->y*pixel , pixel, pixel, aux->c);
      aux = aux->sig;
     cont ++; 
  }
  printf("%d\n",cont);
}

int main()
{
  Color Clr = BLACK;
  bool Vf = false;
  int num,x,y;
  Vector2 posA;
  bool matrix[alto][ancho] = {false};
  Nodo *pun = NULL;
  Color c[26] = {LIGHTGRAY, GRAY, DARKGRAY, YELLOW, GOLD, ORANGE, PINK, RED, MAROON,
                 GREEN, LIME, DARKGREEN, SKYBLUE, BLUE, DARKBLUE, PURPLE, VIOLET, DARKPURPLE,
                 BEIGE, BROWN, DARKBROWN, WHITE, BLACK, BLANK, MAGENTA, RAYWHITE};
  InitWindow(ancho * pixel, alto * pixel, "Paint de la Salada");
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(c[21]);
    colorear( c, &num, &Vf,pun,&y,&x,&Clr);
  if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) ){
      posA = GetMousePosition();
      if (!matrix[(int)posA.x / pixel][(int)posA.y / pixel]) {
        matrix[(int)posA.x / pixel][(int)posA.y / pixel] = true;
        pun = list_c(pun,x,y,Clr);
      }
    colorear(c, &num, &Vf,pun,&y,&x,&Clr);

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
}
