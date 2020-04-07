#include <stdio.h>
#include <stdlib.h>

#define MAX_PILA 5

typedef struct _pila{
  int datos[MAX_PILA];
  int ultimo; //indice de el tope la pila
}* Pila;

//represento la pila vacia con ultimo = -1
Pila pila_crear(){
  Pila nueva = malloc(sizeof(struct _pila));
  nueva->ultimo = -1;
  return nueva;
}

int pila_es_vacia(Pila pila){
  return(pila->ultimo == -1);
}

int pila_es_llena(Pila pila){
  return(pila->ultimo + 1 == MAX_PILA);
}

int pila_top(Pila pila){
  if(pila_es_vacia(pila)){
    printf("La pila se encuentra vacia retorno -1\n");
    return -1;
  }
  return(pila->datos[pila->ultimo]);
}

void pila_push(Pila pila, int dato){
  if(pila_es_llena(pila)){
    return; //en este caso la pila esta llena y no se pueden agregar mas elementos, no se modifica la pila
  }
  else{
    pila->ultimo++;
    pila->datos[pila->ultimo] = dato;
  }
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
  free(pila);
}

int main(){
  Pila pila = pila_crear();
  pila_push(pila,4);
  pila_push(pila,6);
  pila_push(pila,7);
  printf("el tope de la pila es:: %d\n",pila_top(pila));
  printf("la pila esta vacia :::%d\n",pila_es_vacia(pila));
  pila_imprimir(pila);
  puts("\n");
  pila_pop(pila);
  pila_pop(pila);
  pila_imprimir(pila);
  pila_destruir(pila);
  return 0;
}
