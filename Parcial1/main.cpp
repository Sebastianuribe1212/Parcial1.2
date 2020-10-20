#include <iostream>
#include <cmath>
using namespace std;
// 45 es el angulo para que alcance mayor distancia en el eje horizontal
// si se encunetran en el mismo tiempo y mismo angulo van a COLISIONAR.



//entra la distancia y el angulo de disparo.
//retorna velocidad en 'x' y 'y' y y tiempo en el que llega al cañon defensivo.
int disparoO (int, int);
// hallar la posicion del disparo ofensivo para disparar el defensivo
void posdisparo(float, float, float, float);

float *angulo1P, *angulo2P, *angulo3P;
float *xP, *yP, *anguloD;
float *vOxp, *vOyp;
int main()
{
    // posicion de los cañones
    float posOx, posOy, posDx, posDy;
    float angulo1,angulo2, angulo3;

    int t1 , t2 , t3;
    // rangos de tolerancia para loscañones
    //float rangod = 0.025, rangoO = 0.05;

    int d;

    cout<<"Ingrese la distancia entre los cañones: ";
    cin >> d;

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
    t1 =  disparoO (d, angulo1);
    angulo2 = 40;
    t2 = disparoO(d, angulo2 );
    angulo3 = 35;
    t3 = disparoO(d, angulo3);







    return 0;
}

/*
void posdisparo(float angulo, float v, float posx, float posy){
    float x, y, anguloD;



    x = posx + v*2.5;
    y = posy + v*2.5-(4.9*6.25);

    cout <<": x="<<x<<" y= "<<y<<endl;


}

*/

int disparoO (int distancia, int angulo){
    float posOx, posOy;
    float vOx, vOy, pi = 3.1416, g = 9.8, dO = 0.05*distancia ;
    float aO = angulo * pi/180;

    int tiempo;

    for(int vO = 0; vO<=100; vO+=5){
        vOx =vO*cos(aO);
        vOy =vO*sin(aO);
        for (int t = 0; t<=1000; t++){
            posOx = vOx*t;
            posOy = (-100) + vOy*t - (0.5*g*t*t);
            if(sqrt(((posOx-distancia)*(posOx-distancia)+(posOy-0)*(posOy-0)))<=dO){ // defensivo en x = d defensivo en y = h (altura)
                tiempo = t;
                break;
            }
        }
    }
    return tiempo;
}















