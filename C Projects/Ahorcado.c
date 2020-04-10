#include <stdio.h>
#include <string.h>
#include <assert.h>


 /*  
 	  										   ___   ___   ___              ___ 
								  /\    |   | |   | |	| |       /\   |\  |   |
								 /__\	|___| |   | |__/  |		 /__\  | \ |   |
								/    \  |	| |___| |  \  |___  /    \ |_/ |___|
					
*/	


/*Alexis Barraud*/


/*Jugador 1: es aquel que ingresa la palabra que el jugador 2 debe tratar de adivinar,
ingresando una cantidad menor o igual a 5 intentos.
Ya que si este se pasa de los 5 intentos entonces perdera, y finalizara el juego */

#define INTENTOS 5 /*Numero de intentos posibles por el jugador 2*/
#define CARACTER '-' /*Caracter que usamos para representar los guiones o espacios entre letra y letra*/
#define LETRAS 50 /*Representa la cantidad maxima de caracteres que tendra la palabra secreta */

/*---------------------------------------*/
       /*Prototipo de funciones:*/
/*--------------------------------------*/

/*completar:
/*Signatura: char -> string -> int -> void*/
/*Declaracion de proposito: Toma un caracter y va completando un array
(el caracter representa el caracter para generar espacios)*/
/*Ejemplos: */
/*Entrada: */
		/**/
void completar(char caracter,char palabra[],int longitud);


/*perteneceletra*/
/*Signatura: char -> string -> int*/
/*Declaracion de proposito: verifica si el cararacter ingresado como paramaetro se encuentra dentro de la palabra
y si este esta nos retorna 1, en caso contrario nos retorna 0*/
/*Ejemplos: */
/*Entrada: */				/*Salida: */
		/*'a' "alexis"*/		/* 1 */
		/*'b' "juan"*/			/* 0 */
		/*'c' "javier"*/		/* 1*/
int perteneceletra(char letra, char palabra[]);


/*ganar*/
/*Signatura: string->string->int*/
/*Declaracion de proposto: ingresado dos string por parametros veirificamos si estos son iguales,
si son iguales significa que el jugador gano y nos retorna uno en caso contrario 0*/
/*Entrada: */					/*Salida: */
		/*"alexis" "alexis"*/		/* 1 */
		/*"javi" "juan"*/			/* 0 */
		/*"natalia" "javier"*/		/* 0*/
int ganar(char palabra1[], char palabra2[]);


/*grafica*/
/*Signatura: string -> string -> int -> void*/
/*Declaracion de proposito: Muestra por pantalla la palabra descubierta, las letras que se
fueron utilizando y los intentos restantes*/
void grafica(char palabra1[],char palabra2[],int vida);

/*Borrar*/
/*Signatura: void -> void */
/*Declaracion de proposito: Borra el contenido en pantalla, generando 40 \n.*/
void borrar(void);

/*cargarletra*/
/*Signatura: char -> string -> string -> void*/
/*Declaracion de proposito: carga la letra de un string al otro string en el lugar que le corresponde */
void cargaletra(char letra,char palabra1[],char palabra2[]);


int main(void){
	int contador = 0;/*indice de letras usadas*/
	int vida = INTENTOS;
	char letra;
	char letrasusadas[LETRAS] = {""};/*Representa las letras que se fueron utilizando*/
	char palabra[LETRAS];/*Palabra secreta que el jugador 2 debe adivinar*/

	printf("Ingrese palabra secreta (si decide ingresar la palabra en minusculas o mayuscula avisele al jugador 2): ");

	gets(palabra);
	int longitud = strlen(palabra); /*longitud de la palabra secreta*/
	char palabradescubierta[longitud];/*La palabra que se va a ir completando mediante el jugador 2 vaya adivinando las letras*/

	completar(CARACTER,palabradescubierta,longitud);

	grafica(palabradescubierta,letrasusadas,vida);

	borrar();

	while ((vida>0) && (ganar(palabradescubierta,palabra) == 0)){

		printf("Ingrese un caracter \n");
		scanf("%c", &letra);


		while (perteneceletra(letra,letrasusadas) == 1){
			printf("Ingrese otra letra, la que acaba de ingresar ya ha sido utilizada \n");
			scanf(" %c", &letra);
		}

		if (perteneceletra(letra, palabra) == 1){
			letrasusadas[contador] = letra;
			cargaletra(letra,palabra,palabradescubierta);
			contador++;
		}

		else if (perteneceletra(letra, palabra) == 0){
			letrasusadas[contador] = letra;
			contador++;
			--vida;
		}

		borrar();
		grafica(palabradescubierta,letrasusadas,vida);

	}

	if(vida != 0){
		printf("¡USTED HA GANADO! \n");
	}

	else {
		printf("¡USTED HA PERDIDO! \n");
	}

	return 0;

}


int perteneceletra(char letra,char palabra[]){
	int i;
	int resultado = 0;
	for(i=0 ; (palabra[i] != '\0') && (resultado != 1) ; i++){
		if (letra == palabra[i]){
			resultado = 1;
		}
	}
	return resultado;
}

void completar(char caracter,char palabra[],int longitud){
	int i;
	for (i = 0;i <= longitud;i++){
		if (i == longitud){
			palabra[i]='\0';
		}

		else{
			palabra[i] = caracter;
		}
	}
}


void grafica(char palabra1[],char palabra2[],int vida){
	borrar();

	printf("\n==========================================================\n");
	printf("\t Palabra secreta: \t%s\n",palabra1 );
	printf("\t Letras usadas: \t%s",palabra2);
	printf("\n\t Cantidad de vidas:\t%d\n",vida );
	printf("\n==========================================================\n");

	while(getchar()!='\n'); /*lo utilizamos ya que queda un \n en el buffer*/
}

void borrar(void){
	int i;
	for(i = 0; i < 40 ; i++){
		printf("\n");
	}
}

int ganar(char palabra1[],char palabra2[]){
	int resultado=0;
	if(strcmp(palabra1,palabra2) == 0){
		resultado = 1;
	}
	return resultado;
}

void cargaletra(char letra,char palabra1[],char palabra2[]){
	int i;
	for(i=0;palabra1[i]!='\0';i++){
		if(palabra1[i] == letra){
			palabra2[i] = palabra1[i];
		}
	}
}
