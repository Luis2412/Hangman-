#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int aciertos = 0;
int intentos = 0; 
void menu();
#define MAX_WORDS 23


const char* get_random_word(void);

const char *word_collection[MAX_WORDS]= {
                    "palabra","cientifico","barco","espera","identificar",
                    "consentir","santo","genuino","libertad",
                    "sabiduria","agregar","realidad","cantidad","comida",
                    "numeros","amigo","modificar","desear","finalidad",
                    "minimo","maximo","variables","funciones"
                    };

const char* get_random_word(void){
    // seed the random generator.
    srand ( time (0) );
    // obtain a 0 < randon number < MAX_WORDS
    int random_position = rand() % MAX_WORDS;
    //printf("Random number is: %i\n", random_position);
    return word_collection[random_position];
}

void clearscreen(){ 
  system("@cls||clear");
}

void menu_principal(){
int opcion;
printf("\n\n Ingrese 0 para regresar al menu prinicipal\n");
scanf("%d",&opcion);
  switch(opcion){
    case 0:
     menu();
     break;
  }
}


void Empezar_a_jugar(){
  char nombre_jugador[20];
        int intentos=0;
        const char* palabra_elegida=get_random_word();
        int lengthw=strlen(palabra_elegida);
        char letra[50];
        int mask[lengthw];
        aciertos =0;
        clearscreen();
        
        printf("\n\n Ingrese su nombre o alias: \n");
        scanf("%s", nombre_jugador);
        clearscreen();
        
        printf("\n\nLenght %ld\n\n",strlen(palabra_elegida));
        for (int i=0; i < lengthw; ++i) {
          mask[i] = 0;
          }
 
        int gameover = 0;
        while ((! gameover)&& (intentos<10)&& (aciertos!= lengthw) ){
          clearscreen();
        printf("\n ADIVINA LA PALABRA LOS ANTES POSIBLE! \n");
        printf("NOMBRE DEL  JUGADOR: %s",nombre_jugador);
        printf("\n Intentos: %d/10", intentos); 
        printf("\n Aciertos: %d \n", aciertos);    
        intentos=intentos+1; 
      
          printf("\n Encuentra la palabra oculta:\n\n\n");
          for(int j=0; j < lengthw; ++j) {
            if (mask[j]) {
              printf("%c", palabra_elegida[j]);
            }
            else {
              printf(" _ ");
            }
          }
          printf("\n");

          char guess;
          char letra_intento;
  
      printf("\n\n Ingresa la letra:  "); 
      scanf("%c", &letra_intento);
      
      if(letra_intento==0){
         clearscreen();
        exit(0);
      }
      if(letra_intento!=0){
         fflush(stdout);
      scanf(" %c", &guess);
      
 
 //Aciertos en el juego
 for (int i = 0; i < lengthw; i++) {
      if (guess == palabra_elegida[i]) {
      mask[i] = guess;
      aciertos++;
      } else {}
    }
      
      for(int k=0; k < lengthw; ++k) {
        if (palabra_elegida[k] == guess) {
    mask[k] = 1;
        }
 
      // Determine whether the player has won!
      gameover = 1;
      for(int m = 0; m < lengthw; ++m) {
        if (!mask[m]) {
          gameover = 0;
          break;
        }
      }
    }
    if(aciertos==lengthw){
  printf("\n VICTORIA! La palabra esocondida era: \"%s\".\n", palabra_elegida);
    }
   else{
  printf("\n GAMEOVER! La palabra esocondida era: \"%s\".\n", palabra_elegida);
          }  
        }
     } 
     menu_principal();
}

 

void salida(){
  int opcion;
  clearscreen();
printf("Presione 0 para salir y 1 para regresar al menu.\n");
scanf("%d",&opcion);

switch(opcion){
  case 0:
     exit (0);
     break;
  case 1:
     menu();
     break;   
}
}

void instrucciones(){
  clearscreen();
printf("Este juego consiste en adivinar una palabra escogida aleatoriamente. Para adivinar la palabra escondida, ingresar letra por letra. Cada vez que ingrese una letra que no ocrresponda con la palabra esocondida, ira perdiendo perdiendo vidas. En total tiene 10 vidas.\n ");
menu_principal();
}

void about(){
  clearscreen();
  printf("Nombre: Gustavo Godoy, Luis Monterroso\n");
  printf("Correo: gustavogodoy@ufm.edu , luismontecar@ufm.edu\n");
  menu_principal(); 
}

void menu(){
  int opcion; 
  clearscreen();
printf(" _________________________________________\n");
printf("|______________HANGMAN MENU______________|\n");
printf("|         1) Empezar a jugar             |\n");
printf("|         2) Leer instrucciones          |\n");
printf("|         3) About                       |\n");
printf("|         4) Salir                       |\n");     
printf("|________________________________________|\n");
printf("\n\n");
printf("Elija la opcion que desea\n");
scanf("%d",&opcion);
switch(opcion){
  case 1:
     Empezar_a_jugar();
     break;
  case 2:
     instrucciones();
     break;  
  case 3:
     about(); 
     break;  
  case 4:
     salida();
     break;    
}
}
int main(){
menu();

return 0;

}
