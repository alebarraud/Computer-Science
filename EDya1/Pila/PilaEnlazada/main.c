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
  lista = slist_agregar_final(lista,2);
  lista = slist_agregar_inicio(lista,8);
  lista = slist_agregar_final(lista,24);
  lista = slist_agregar_inicio(lista,11);
  slist_recorrer(lista, imprimir_entero);
  puts("\nreverso utilizando pilas\n");
  slist_recorrer(slist_reverso1(lista),imprimir_entero);
/*  Pila pila = pila_crear();
  pila = pila_push(pila,4);
  pila = pila_push(pila,5);
  pila = pila_push(pila,7);
  pila_imprimir(pila, imprimir_entero);
  puts("\n");
  pila = pila_pop(pila);
  //pila = pila_pop(pila);
  //pila = pila_pop(pila);
  //pila = pila_pop(pila);
  pila_imprimir(pila, imprimir_entero);

  printf("el tope de la pila es :::::::%d\n",pila_top(pila));
  pila_destruir(pila);*/
  slist_destruir(lista);
  return 0;
}
