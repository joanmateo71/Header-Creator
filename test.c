/*Una empresa de casinos en línia, ens demana que desenvolupar un programa per jugar al 21
Black Jack de Poker, el joc tindrà dos jugadors, l'usuari i el crupier (banca). Les regles del joc són
les següents, es comença donant una carta (aleatòria) a l'usuari i després una altra a la banca,
guanyarà el que més s'aproxime al 21 sense superar-lo, en cas de fer-ho es perd la partida. En
cada ronda se li pregunta a l'usuari si vol seguir. Valor de les cartes: la 1 val 1, la 2 val 2... i així
fins a 10. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Declaració de funcions
void joc();
int obtenir_carta();
void mostrar_carta(int carta);
int obtenir_valor(int carta);
void mostrar_ma(int *ma, int num_cartas);
int obtenir_punts(int *ma, int num_cartas);
int determinar_guanyadorador(int punts, int punts_banca);
bool continuar_jugant();


void joc() {
   int baralla[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};
   int ma_jugador[11] = {0};
   int ma_banca[11] = {0};
   int num_cartes_jugadors = 0;
   int num_cartes_banca = 0;
   int carta = 0;
   int punts = 0;
   
   // Mescla la baralla
   for (int i = 0; i < 52; i++) {
      int temp = baralla[i];
      int random_index = rand() % 52;
      baralla[i] = baralla[random_index];
      baralla[random_index] = temp;
   }
   
   // Repartiment de cartes
   carta = obtenir_carta(baralla);
   ma_jugador[num_cartes_jugadors] = carta;
   num_cartes_jugadors++;
   
   carta = obtenir_carta(baralla);
   ma_banca[num_cartes_banca] = carta;
   num_cartes_banca++;
   
   carta = obtenir_carta(baralla);
   ma_jugador[num_cartes_jugadors] = carta;
   num_cartes_jugadors++;
   
   carta = obtenir_carta(baralla);
   ma_banca[num_cartes_banca] = carta;
   num_cartes_banca++;
   
   // Mostrar las cartes del jugador
   printf("Les teves cartes son:\n");
   mostrar_ma(ma_jugador, num_cartes_jugadors);
   
   // Mostrar una carta de la banca
   printf("La carta visible de la banca es:\n");
   mostrar_carta(ma_banca[0]);
   
   // Pedir al jugador que continui jugant o es planti
while (1) {
   punts = obtenir_punts(ma_jugador, num_cartes_jugadors);
   
   if (punts == 21) {
      printf("¡Blackjack! ¡Has guanyat!\n");
      return;
   } else if (punts > 21) {
      printf("T'has passat de 21. ¡Has perdut!\n");
      return;
   }
   
   bool continuar = true;
   if (punts >= 21) {
      continuar = false;
   }
   
   while (continuar) {
      printf("¿Vols demanar una altre carta (s/n)? ");
      char opcio;
      scanf(" %c", &opcio);
   
      if (opcio == 's' || opcio == 'S') {
         carta = obtenir_carta(baralla);
         ma_jugador[num_cartes_jugadors] = carta;
         num_cartes_jugadors++;
      
         printf("Les teves cartes ara son:\n");
         mostrar_ma(ma_jugador, num_cartes_jugadors);
         
         punts = obtenir_punts(ma_jugador, num_cartes_jugadors);
         if (punts >= 21) {
            continuar = false;
         }
      } else if (opcio == 'n' || opcio == 'N') {
         continuar = false;
      } else {
         printf("Opció inválida. Intenta de nou.\n");
      }
   }
}

   
   // Juga la banca
   printf("La banca juga les seves cartes.\n");
   mostrar_ma(ma_banca, num_cartes_banca);
   
   while (1) {
   punts = obtenir_punts(ma_banca, num_cartes_banca);
   
   if (punts >= 17) {
      return; // salir de la función que contiene el bucle
   } else {
      carta = obtenir_carta(baralla);
      ma_banca[num_cartes_banca] = carta;
      num_cartes_banca++;
      
      printf("La banca treu una carta.\n");
      mostrar_ma(ma_banca, num_cartes_banca);
   }
}

   
   // Determina el resultat
   punts = obtenir_punts(ma_jugador, num_cartes_jugadors);
   int punts_banca = obtenir_punts(ma_banca, num_cartes_banca);
   
   if (punts_banca > 21) {
      printf("¡La banca s'ha passat de 21! ¡Has guanyat!\n");
      return;
   }
   
   if (punts > punts_banca) {
      printf("¡Has guanyat!\n");
   } else if (punts == punts_banca) {
      printf("¡Empat!\n");
   } else {
      printf("¡Has perdut!\n");
   }
}

// Funció per obtenir una carta
int obtenir_carta(int *baralla) {
   int carta = baralla[0];
   
   for (int i = 0; i < 51; i++) {
      baralla[i] = baralla[i+1];
   }
   
   baralla[51] = carta;
   
   return carta;
}

// Funció per a mostrar una carta
void mostrar_carta(int carta) {
   if (carta == 1) {
      printf("As\n");
   } else if (carta == 11) {
      printf("Jota\n");
   } else if (carta == 12) {
      printf("Reina\n");
   } else if (carta == 13) {
      printf("Rei\n");
   } else {
      printf("%d\n", carta);
   }
}

// Funció per obtenir el valor duna carta
int obtenir_valor(int carta) {
   if (carta > 10) {
      return 10;
   } else if (carta == 1) {
      return 11;
   } else {
      return carta;
   }
}

// Funció per mostrar una ma de cartes
void mostrar_ma(int *ma, int num_cartas) {
   for (int i = 0; i < num_cartas; i++) {
      mostrar_carta(ma[i]);
   }
}

// Función para obtenir els punt d'una ma
int obtenir_punts(int *ma, int num_cartas) {
   int punts = 0;
   int num_ases = 0;
   
   for (int i = 0; i < num_cartas; i++) {
      int valor = obtenir_valor(ma[i]);
      
      if (valor == 11) {
         num_ases++;
      }
      
      punts += valor;
   }
   
   while (num_ases > 0 && punts > 21) {
      punts -= 10;
      num_ases--;
   }
   
   return punts;
}


int determinar_guanyador(int punts, int punts_banca) {
    if (punts > 21) { // el jugador s'ha passat 
        return -1;
    } else if (punts_banca > 21) { // la banca s'ha passat de 21 puntos
        return 1;
    } else if (punts > punts_banca) { // el jugador te més punts que la banca
        return 1;
    } else if (punts < punts_banca) { // la banca té més punts que el jugador
        return -1;
    } else { // Els punts dels jugador i la banca son els mateixos
        return 0;
    }
}

bool continuar_jugant() {
   while (true) {
      printf("Vols continuar jugant (s/n)? ");
      char opcio;
      scanf(" %c", &opcio);

      if (opcio == 's' || opcio == 'S') {
         return true;
      } else if (opcio == 'n' || opcio == 'N') {
         return false;
      } else {
         printf("Opció invàlida. Intenta de nou.\n");
      }
   }
}



int main() {
   srand(time(NULL));
   
    do{
      joc();
   }while (continuar_jugant());
   
   printf("Gràcies per jugar!\n");
   return 0;
}