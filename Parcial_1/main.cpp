/*
 * Alejandro Pérez Ramírez
 * C.C 8´029.742
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;
#define PI 3.1415926535897932384626433832795
int main(int argc, char *argv[])
{
    double Pos_X_Blanco;
    double Pos_Y_Blanco;
    double Velocidad=50;
    double Pos_X_Canyon;
    double Pos_Y_Canyon;
    double Angulo;
    double Radianes;
    int intentos;
    int acierto=0;
    double DistanciaY;
    double Gravedad=9.8;
    float RedondeoDistanciaY;
    float RedondeoPosY;
    // Definir variables de inicialización
    Pos_X_Canyon = 0.0;
    Pos_Y_Canyon = 0.0;
    printf("\nPosicion X del blanco.....: ");
    scanf(" %lf",&Pos_X_Blanco);
    printf("Posicion Y del blanco.....: ");
    scanf(" %lf",&Pos_Y_Blanco);
    //printf("Velocidad Inicial.........: ");
    //scanf(" %lf",&Velocidad);
    // realizar la petición de los intentos
    intentos=0;


    while(intentos<3 && acierto==0)
    {
       cout<<"Angulo......: ";
       scanf(" %lf",&Angulo);
       Radianes=(Angulo/180.0)*PI;
      // Calculo de la distancia Y
      //DistanciaY=(Velocidad*(sin(Radianes))*Tiempo)-((1/2)*Gravedad*(Tiempo*Tiempo));
      DistanciaY = tan(Radianes)*Pos_X_Blanco-((Gravedad*(Pos_X_Blanco*Pos_X_Blanco))/(2*(Velocidad*Velocidad)*cos(Radianes)*cos(Radianes)));
       // Si la distancia en Y coincide con la pos Y dada
       RedondeoDistanciaY=DistanciaY;
       RedondeoPosY=Pos_Y_Blanco;
       if ( RedondeoPosY+1>= RedondeoDistanciaY && RedondeoPosY-1<=RedondeoDistanciaY ) {
          printf("Has Acertado\n");
          acierto=1;
       }
       intentos++;
    }
  system("No acerto");
  return 0;
}
