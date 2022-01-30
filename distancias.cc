
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct distancia
    {
        char primero[20];
        char segundo[20];
        char cantidad[20];
    };

typedef struct distancia Distancias;

struct soporte
    {
        char auxiliar[100];
    };

soporte Soporte;

FILE *fichero;
FILE *fich;
int caracter;
char delimitador[] = ";";
char primero[20],segundo[20];

void Eleminarinto(char cadena[200]) {
  cadena[strlen(cadena)-1]='\0';
}

soporte Separador(char cadena[100],int valor) {
  int i = 0;
  int j=0;
  char auxiliar[100];
  for (i = valor; i < strlen(cadena); i++){
      if (cadena[i] != ';'){
        auxiliar[j]=cadena[i];
        j++;
      }else{
        auxiliar[j]='\0';
        strcpy(Soporte.auxiliar, auxiliar);

        return Soporte;
      }
    }
}

void Solucion(){
  Distancias medidas;
  char cadenacopia[100];


  if ((fich=fopen("TablaKM.txt","r"))==NULL) {
      printf("ERROR | El fichero no existe.");
    }else{
      fichero=fopen ("TablaKM.dat", "wb");



      do {
          fgets(cadenacopia,100,fich);
          strcpy(medidas.primero, Separador(cadenacopia,0).auxiliar);
          strcpy(medidas.segundo, Separador(cadenacopia,strlen(medidas.primero)+1).auxiliar);
          strcpy(medidas.cantidad, Separador(cadenacopia,strlen(medidas.primero)+strlen(medidas.segundo)+2).auxiliar);



          fwrite(&medidas,sizeof(medidas),1,fichero);

                    //printf ("[1] %s\n", medidas.primero);

      } while(!feof(fich));
      fclose(fichero);
      fclose(fich);
    }



  //printf ("\nLa distancia entre los destinos es de: %s", medidas.primero);
}

void Contesta(){
  Distancias medidas;
  fichero=fopen ("TablaKM.dat", "rb");
  while (fread(&medidas,sizeof(medidas),1,fichero)) {
    if (strcmp(primero, medidas.primero)==0) {
      if (strcmp(segundo, medidas.segundo)==0) {
        printf("Son %sKM\n", medidas.cantidad);
      }
    }
  }
  fclose(fichero);
}

void Preguntar(){
  system("cls");
  printf ("Salida: \n");
  fgets(primero, 20, stdin);Eleminarinto(primero);
  printf ("Llegada: \n");
  fgets(segundo, 20, stdin);Eleminarinto(segundo);

  Contesta();
}

int main(){

  Solucion();
  Preguntar();





  return 0;
}
