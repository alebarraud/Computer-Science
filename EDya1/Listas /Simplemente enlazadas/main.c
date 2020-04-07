#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int comparacion(int dato, int dato2){
  return(dato == dato2);
}

int main(int argc, char *argv[]) {

  SList lista = slist_crear();
  SList lista1 = slist_crear();
  SList intersecada = slist_crear();
  SList intercalar = slist_crear();

  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 1);
  lista = slist_agregar_final(lista, 10);

  lista1 = slist_agregar_inicio(lista1,11);
  //lista1 = slist_agregar_final(lista1,13);
  //lista1 = slist_agregar_inicio(lista1,10);
  
  puts("Lista");
  slist_recorrer(lista, imprimir_entero);
  puts("\nLista1");
  slist_recorrer(lista1, imprimir_entero);
  
  //printf("longitud de la lista: %d\n",slist_longitud(lista));
  /*lista = slist_concatenar(lista,lista1);
  puts("\nlista concatenada lista:lista1");
  slist_recorrer(lista, imprimir_entero);*/

  //puts("\n insertar dato en posicion arbitraria de la lista");
  ///lista = slist_insertar(lista,1234,4);
  //puts("\n eliminar en posicion arbitraria");
  //lista = slist_eliminar(lista,3);
  //puts("\n la lista contiene dato indice");
  //printf("%d---------\n",slist_indice(lista,4));
 // puts("\n interseccion listas");
  //intersecada = slist_intersecar_custom(lista,lista1,comparacion);


  //puts("\n ordenar listas");
  //lista1 = slist_ordenar(lista1,0);
  //puts("\n reverso de la lista");
  //lista1 = slist_reverso(lista1);
  puts("\n Intercalar");
  intercalar = slist_intercalar(lista,lista1);
  slist_recorrer(intercalar, imprimir_entero);
  slist_destruir(lista);
  slist_destruir(lista1);

  return 0;
}
