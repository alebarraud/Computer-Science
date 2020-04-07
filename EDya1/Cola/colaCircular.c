#include <stdio.h>
#include <stdlib.h>

#define MAX_COLA 5

typedef struct _Cola{
  int datos[MAX_COLA];
  int primero;
  int ultimo;
}* Cola;

Cola cola_crear(){
  Cola nueva = malloc(sizeof(struct _Cola));
  nueva->primero = nueva->ultimo = -1;
  return nueva;
}

int cola_es_vacia(Cola cola){
  return(cola->primero == -1);
}

int cola_es_llena(Cola cola){
  return(((cola->ultimo + 1) % MAX_COLA) == cola->primero);
}

int cola_primero(Cola cola){
  if(cola_es_vacia(cola)){
    printf("la cola esta vacia\n");
    return -1;
  }
  return(cola->datos[cola->primero]);
}

void cola_imprimir(Cola cola){
  if(cola_es_vacia(cola))return;
  int i = cola->primero;
  for(;i != cola->ultimo; i = (i + 1) % MAX_COLA){
    printf("%d)%d\n",i,cola->datos[i]);
  }
  printf("%d)%d\n",i,cola->datos[cola->ultimo]);
}

void cola_encolar(Cola cola, int dato){
  if(cola_es_vacia(cola)){
    cola->primero++;
    cola->ultimo++;
    cola->datos[cola->primero] = dato;
  }
  else if(cola_es_llena(cola)){
    printf("la cola esta llena no podemos agregar mas elementos\n");
  }
  else{
    cola->ultimo = (cola->ultimo + 1) % MAX_COLA;
    cola->datos[cola->ultimo] = dato;
  }
}

void cola_desencola(Cola cola){
  if(cola_es_vacia(cola)){
    printf("la cola esta vacia no hay nada para desencolar\n");
  }
  else if(cola->primero == cola->ultimo){//significa que es el ultimo elemento para desencolar
    cola->primero = cola->ultimo = -1;
  }
  else{
    cola->primero = (cola->primero + 1) % MAX_COLA;
  }
}

void cola_destruir(Cola cola){
  free(cola);
}

int main(){
  Cola cola = cola_crear();
  cola_encolar(cola,45);
  cola_encolar(cola,77);
  cola_encolar(cola,12);
  cola_encolar(cola,4);
  cola_encolar(cola,88);
  cola_imprimir(cola);
  puts("\n desencolar");
  cola_desencola(cola);
  cola_desencola(cola);
  cola_desencola(cola);
  cola_desencola(cola);
  cola_desencola(cola);
  cola_desencola(cola);
  // cola_encolar(cola,9999999);
  cola_imprimir(cola);
  cola_destruir(cola);
  return 0;
}
