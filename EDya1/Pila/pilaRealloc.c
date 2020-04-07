#include <stdio.h>
#include <stdlib.h>

typedef struct _pila{
  int *datos;
  int ultimo; //indice de el tope la pila
  int cap;
}* Pila;


Pila pila_crear(int tam){
  Pila nueva = malloc(sizeof(struct _pila));
  nueva->datos = malloc(sizeof(int) * tam);
  nueva->cap = tam;
  nueva->ultimo = -1;
  return nueva;
}

int pila_es_vacia(Pila pila){
  return(pila->ultimo == -1);
}

int pila_es_llena(Pila pila){
  return(pila->ultimo + 1 == pila->cap);
}

void pila_push(Pila pila, int dato){
  if(pila_es_llena(pila)){
    int value = pila->cap * 2;
    pila->datos = realloc(pila->datos,sizeof(int) * value);
    pila->cap = value;
  }
  pila->ultimo++;
  pila->datos[pila->ultimo] = dato;
}


int pila_top(Pila pila){
  if(pila_es_vacia(pila)){
    printf("La pila se encuentra vacia retorno -1\n");
    return -1;
  }
  return(pila->datos[pila->ultimo]);
}


void pila_pop(Pila pila){
  if(pila_es_vacia(pila))return;
  pila->ultimo--;
}

void pila_imprimir(Pila pila){ //imprimo como si fuera una pila de platos
  if(pila_es_vacia(pila))return;
  for(int i = pila->ultimo ; i >= 0 ; i--){
    printf("%d\n",pila->datos[i]);
  }
}

void pila_destruir(Pila pila){
  free(pila->datos);
  free(pila);
}

int capacidad_de_la_pila(Pila pila){
  return(pila->cap);
}

int main(){
  Pila pila = pila_crear(5);
  pila_push(pila,4);
  pila_push(pila,6);
  pila_push(pila,7);
  pila_push(pila,8);
  pila_push(pila,9);
  pila_push(pila,10);
  pila_push(pila,11);
  pila_imprimir(pila);
  printf("la capacidad de la pila es:::%d\n",capacidad_de_la_pila(pila));
  pila_destruir(pila);
  return 0;
}
