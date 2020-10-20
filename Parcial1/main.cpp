/*
 *Sebastián Uribe Álvarez-1000438232
 *
 *
 */
#include <iostream>
#include <cmath>
using namespace std;
// 45 es el angulo para que alcance mayor distancia en el eje horizontal
// si se encunetran en el mismo tiempo y mismo angulo van a COLISIONAR.



//entra la distancia y el angulo de disparo, la altura del cañon ofensivo y defensivo
//retorna velocidad en 'x' y 'y' y y tiempo en el que llega al cañon defensivo.
int disparoO (int, int, int, int);

//entra la distancia y el angulo de disparo, la altura del cañon ofensivo y defensivo
//retorna velocidad en 'x' y 'y' y y tiempo en el que llega al cañon ofensivo.
int disparoD (int, int, int, int);

//entra, tiempo, velocidad y angulo del disparo ofensivo,
//sale, velocidad y angulo para impactar en el disparo ofensivo.
int disparodefensivo(int, int, int);


float *angulo1P, *angulo2P, *angulo3P;
float *xP, *yP, *anguloD;
int *vOxp, *vOyp,*vDxp, *vDyp;
int main()
{
    int Ho, Hd;

    float angulo1,angulo2, angulo3;
    int vOx1, vOy1,  vOx2, vOy2, vOx3, vOy3;
    int tO1 , tO2 , tO3;

    int vDx1, vDy1,  vDx2, vDy2, vDx3, vDy3;
    int tD1 , tD2 , tD3;


    int d;

    cout<<"Ingrese la distancia entre los canones: ";
    cin >> d;

    cout<<"Ingrese altura del canon ofensivo: ";
    cin >> Ho;

    cout<<"Ingrese la altura del canon defensivo: ";
    cin >> Hd;


    // tiros ofensivos para dañar el cañon defensivo.
   //hallar tiros para darle al defensivo.
  //angulos aleatorios y ver si colisionan
    angulo1 = 45;
    tO1 =  disparoO (d, angulo1, Ho, Hd);
    vOx1 =  *vOxp;
    vOy1 = *vOyp;
    angulo2 = 40;
    tO2 = disparoO(d, angulo2, Ho, Hd );
    vOx2 =  *vOxp;
    vOy2 = *vOyp;
    angulo3 = 35;
    tO3 = disparoO(d, angulo3, Ho, Hd);
    vOx3 =  *vOxp;
    vOy3 = *vOyp;

    cout << "1. (angulo 45) tiempo: "<<tO1<<" velocidad en x: "<<vOx1<<" velocidad en y: "<<vOy1<<endl;
    cout << "2. (angulo 40) tiempo: "<<tO2<<" velocidad en x: "<<vOx2<<" velocidad en y: "<<vOy2<<endl;
    cout << "3. (angulo 35) tiempo: "<<tO3<<" velocidad en x: "<<vOx3<<" velocidad en y: "<<vOy3<<endl;
    cout << "si la salida es 0 es porque no colisiona."<<endl;


    cout <<" "<<endl;
    cout <<"punto2 tiros defensivos que golpean al canon defensivo"<<endl;
   angulo1 = 45;
    tD1 =  disparoD (d, angulo1, Ho, Hd);
    vDx1 =  *vDxp;
    vDy1 = *vDyp;
    angulo2 = 40;
    tD2 = disparoD(d, angulo2, Ho, Hd );
    vDx2 =  *vDxp;
    vDy2 = *vDyp;
    angulo3 = 35;
    tD3 = disparoD(d, angulo3, Ho, Hd);
    vDx3 =  *vDxp;
    vDy3 = *vDyp;

    cout << "1. (angulo 45) tiempo: "<<tD1<<" velocidad en x: "<<vDx1<<" velocidad en y: "<<vDy1<<endl;
    cout << "2. (angulo 40) tiempo: "<<tD2<<" velocidad en x: "<<vDx2<<" velocidad en y: "<<vDy2<<endl;
    cout << "3. (angulo 35) tiempo: "<<tD3<<" velocidad en x: "<<vDx3<<" velocidad en y: "<<vDy3<<endl;
    cout << "si la salida es 0 es porque no colisiona."<<endl;


    return 0;
}


 //entra la distancia y el angulo de disparo.
//retorna velocidad en 'x' y 'y' y y tiempo en el que llega al cañon defensivo.
int disparoO (int distancia, int angulo, int Ho, int Hd){
    float posOx, posOy;
    float pi = 3.1416, g = 9.81, dO = 0.05*distancia ;
    float aO = angulo * pi/180;
    int  vOx, vOy, cero =0;
    int tiempo=0;
    bool flag = false;
    for(int vO = 0; vO<=100; vO+=5){
        vOx =vO*cos(aO);
        vOy =vO*sin(aO);
        for (int t = 0; t<=100; t++){//
            posOx = vOx*t;
            posOy =( Ho + vOy*t) - (0.5*g*(t*t));
            if(sqrt(pow(distancia-posOx,2)+pow(Hd-posOy,2))<=dO){ // defensivo en x = d defensivo en y = h (altura)
                 tiempo = t;
                 vOxp = &vOx;
                 vOyp = &vOy;
                 flag = true;
                 return tiempo;
                 break;
            }
        }
    }
   if (flag == false){
       tiempo = 0;
       vOxp = &cero;
       vOyp = &cero;
   }
   return tiempo;
}

int disparoD (int distancia, int angulo, int Ho, int Hd){
    float posOx, posOy;
    float pi = 3.1416, g = 9.81, dO = 0.05*distancia ;
    float aO = angulo * pi/180;
    int  vOx, vOy, cero =0;
    int tiempo=0;
    bool flag = false;
    for(int vO = 0; vO<=100; vO+=5){
        vOx =vO*cos(aO);
        vOy =vO*sin(aO);
        for (int t = 0; t<=100; t++){//
            posOx = vOx*t;
            posOy =( Hd + vOy*t) - (0.5*g*(t*t));
            if(sqrt(pow(distancia-posOx,2)+pow(Ho-posOy,2))<=dO){ // defensivo en x = d defensivo en y = h (altura)
                 tiempo = t;
                 vDxp = &vOx;
                 vDyp = &vOy;
                 flag = true;
                 return tiempo;
                 break;
            }
        }
    }
   if (flag == false){
       tiempo = 0;
       vDxp = &cero;
       vDyp = &cero;
   }
   return tiempo;
}

int disparodefensivo(int, int, int);












