#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>

void imprimir_entero(int dato){
  printf("%d\n",dato);
}

int comparacion(int dato, int dato1){
  return(dato == dato1);
}

int main(){
  DList lista = dlist_crear();
  DList lista1 = dlist_crear();

  lista = dlist_agregar_inicio(lista,7);
  lista = dlist_agregar_final(lista,4);
  lista = dlist_agregar_final(lista,2);
  lista = dlist_agregar_inicio(lista,-1);

  lista1 = dlist_agregar_inicio(lista1,7);
  lista1 = dlist_agregar_final(lista1,3);
  lista1 = dlist_agregar_final(lista1,0);
  lista1 = dlist_agregar_inicio(lista1,11);
  puts("lista");
  dlist_recorrer(lista,imprimir_entero,0);


  puts("\nlista2");
  dlist_recorrer(lista1,imprimir_entero,0);

  puts("");
  printf("longitud de la lista %d\n",dlist_longitud(lista));

  //puts("\n concatenacion");
  //dlist_recorrer(dlist_concatenar(lista,lista1),imprimir_entero, 0);
  //puts("\nrecorrido hacia atras");
  //dlist_recorrer(dlist_concatenar(lista,lista1),imprimir_entero, 1);
  /*puts("\n insertar en posicion arbitraria");
  lista = dlist_insertar(lista,777,-1);*/
  //printf("eliminar en posicion arbitraria\n");
  //lista = dlist_eliminar(lista,4);
  //dlist_recorrer(lista,imprimir_entero,0);

  //puts("\n contiene dato");
  //printf("---------------------------------(%d)\n",dlist_indice(lista,0));

  //puts("\nintersecar");
  //dlist_recorrer(dlist_intersecar_custom(lista,lista1,comparacion),imprimir_entero,0);
  //puts("\n ordenar lista");
  puts("\nreversa de una lista");
  dlist_recorrer(dlist_reverso(lista),imprimir_entero,1);
  dlist_destruir(lista);
  //dlist_destruir(lista1);
  return 0;
}
