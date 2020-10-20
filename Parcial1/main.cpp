#include <iostream>
#include <cmath>
using namespace std;
// 45 es el angulo para que alcance mayor distancia en el eje horizontal
// si se encunetran en el mismo tiempo y mismo angulo van a COLISIONAR.
bool espacio_colision();

// dados dos puntos me dice que angulo y que velocidad debo tener.
float anguloyvelocidad ( float, float, float);
//entra el angulo del disparo
int disparoO (int);
// hallar la posicion del disparo ofensivo para disparar el defensivo
void posdisparo(float, float, float, float);

float *angulo1P, *angulo2P, *angulo3P;
float *xP, *yP, *anguloD;
int main()
{
    // posicion de los cañones
    float posOx, posOy, posDx, posDy;
    float angulo1,angulo2, angulo3;

    float v1 , v2 , v3;
    // rangos de tolerancia para loscañones
    float rangod = 0.025, rangoO = 0.05;



    // posiciones de los cañones;
    cout << "Ingrese la posicion del cañon ofensivo en la coordenada X: ";
    cin >> posOx;

    cout << "Ingrese la posicion del cañon ofensivo en la coordenada Y: ";
    cin >> posOy;

    cout << "Ingrese la posicion del cañon Defensivo en la coordenada X: ";
    cin >> posDx;

    cout << "Ingrese la posicion del cañon Defensivo en la coordenada Y: ";
    cin >> posDy;



    //hallar tiros para darle al defensivo.

    // disp1
    // por temas de tiempo voy a ingresar tres velocidades y angulos aleatorios y ver si colisionan
    angulo1 = 45;
    angulo2 = 40;
    angulo3 = 35;

    v1 = 10;
    v2 = 20;
    v3 = 30;
    cout <<"Disparo ofensivo 1 dado en: x="<<posOx<<" y= "<<posOy<<endl;



    // disparo1
    cout <<"Disparo defensivo 1 dado en";
    posdisparo(angulo1, v1, posOx, posOy);

    cout <<"Disparo defensivo 2 dado en";
    posdisparo(angulo2, v2, posOx, posOy);

    cout <<"Disparo defensivo 3 dado en";
    posdisparo(angulo3, v3, posOx, posOy);

    return 0;
}

void posdisparo(float angulo, float v, float posx, float posy){
    float x, y, anguloD;



    x = posx + v*2.5;
    y = posy + v*2.5-(4.9*6.25);

    cout <<": x="<<x<<" y= "<<y<<endl;


}

