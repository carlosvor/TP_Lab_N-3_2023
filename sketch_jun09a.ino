#include <math.h>
#include <stdio.h>

void cinemdirecta(double theta1, double theta2, double theta3)
 {
    double alpha1 = 3.14 / 2;
    double alpha2 = 0;
    double alpha3 = 0;
    double d1 = 8.9;
    double d2 = 0;
    double d3 = 0;
    double a1 = 0;
    double a2 = 3.6;
    double a3 = 7.7;
    char buffer[10];
    int x,y,z;

    double H01[4][4] = {{cos(theta1), -cos(theta1)*sin(alpha1), sin(theta1)*sin(alpha1), a1*cos(theta1)},
                        {sin(theta1), cos(theta1)*cos(alpha1), -cos(theta1)*sin(alpha1), a1*sin(theta1)},
                        {0, sin(alpha1), cos(alpha1), d1},
                        {0, 0, 0, 1}};

    double H12[4][4] = {{cos(theta2), -cos(theta2)*sin(alpha2), sin(theta2)*sin(alpha2), a2*cos(theta2)},
                        {sin(theta2), cos(theta2)*cos(alpha2), -cos(theta2)*sin(alpha2), a2*sin(theta2)},
                        {0, sin(alpha2), cos(alpha2), d2},
                        {0, 0, 0, 1}};

    double H23[4][4] = {{cos(theta3), -cos(theta3)*sin(alpha3), sin(theta3)*sin(alpha3), a3*cos(theta3)},
                        {sin(theta3), cos(theta3)*cos(alpha3), -cos(theta3)*sin(alpha3), a3*sin(theta3)},
                        {0, sin(alpha3), cos(alpha3), d3},
                        {0, 0, 0, 1}};

    double H03[4][4] = {0};

   
    for (int i = 0; i < 4; i++)
     {
        for (int j = 0; j < 4; j++)
         {
            for (int k = 0; k < 4; k++) 
            {
                H03[i][j] += H01[i][k] * H12[k][j];
            }
        }
    }

    for (int i = 0; i < 4; i++)
     {
        for (int j = 0; j < 4; j++) 
        {
            H03[i][j] *= H23[i][j];
        }
    }

    // x = H03[0][3];
    // y = H03[1][3];
    // z = H03[2][3];



  // Imprimir los resultados por la comunicación serial
  Serial.println("Posición final:");
  
  Serial.print("X=");
  dtostrf(H03[0][3], 8, 5, buffer);
  Serial.println(buffer);

  Serial.print("Y= ");
    //Serial.println(y);
 dtostrf(H03[1][3], 8, 5, buffer);
  Serial.println(buffer);

  Serial.print("Z= ");
  //  Serial.println(z);
   dtostrf(H03[2][3], 8, 5, buffer);
  Serial.println(buffer);
  
}

void setup()
 {
  // Inicializar la comunicación serial a una velocidad de 9600 baudios
  Serial.begin(9600);
}

void loop()
 {
  // Calcular la posición y orientación del sistema de coordenadas final
 cinemdirecta(1.192, 1.2333, 2.9427);
  delay(1000);
  delay(1000);
  delay(1000);
}
