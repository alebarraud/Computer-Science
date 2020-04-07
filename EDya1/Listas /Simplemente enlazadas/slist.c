#include "slist.h"
#include <stdlib.h>

SList slist_crear() {
  return NULL;
}

void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) {
  return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

int slist_longitud(SList lista){
  int i = 0;
  for(;lista != NULL; lista = lista->sig,i++);
  return i;
}

//modificamos lista1
SList slist_concatenar(SList lista1, SList lista2){
  if(slist_vacia(lista1))return lista2;
  else if(slist_vacia(lista2))return lista1;
  SNodo *temp = lista1;
  for(;temp->sig != NULL; temp = temp->sig);
  temp->sig = lista2;
  return lista1;
}

SList slist_insertar(SList lista, int dato, int pos){
  if(pos == 0){
    return slist_agregar_inicio(lista,dato);
  }
  SNodo *nuevo = malloc(sizeof(SNodo));
  nuevo->dato = dato;
  int i = 1;
  SNodo *temp = lista;
  for(;i != pos; temp = temp->sig,i++);
  nuevo->sig = temp->sig;
  temp->sig = nuevo;
  return lista;
}

//consideraremos que la posicion ingresada es válida
SList slist_eliminar(SList lista, int pos){
  if(pos == 0){
    SNodo *ret = lista->sig;
    free(lista);
    return ret;
  }
  int i = 1;
  SNodo *temp = lista;
  SNodo *eliminar;
  for(;i != pos; i++, temp = temp->sig);
  eliminar = temp->sig;
  temp->sig = temp->sig->sig;
  return lista;
}

int slist_contiene(SList lista, int dato){
  for(;lista != NULL && lista->dato != dato;lista = lista->sig);
  if(lista == NULL)return 0;
  return 1;
}

int slist_indice(SList lista, int dato){
  int i = 0;
  for(;lista != NULL && lista->dato != dato ; lista = lista->sig, i++);
  if(slist_vacia(lista))return -1;
  return i;
} 

SList slist_intersecar(SList lista, SList lista2){
  if(slist_vacia(lista) || slist_vacia(lista2))return NULL;
  SList nueva = slist_crear();
  for(SNodo *temp1 = lista ; temp1 != NULL ; temp1 = temp1->sig){
    for(SNodo *temp2 = lista2 ; temp2 != NULL ; temp2 = temp2->sig){
      if(temp1->dato == temp2->dato){
        nueva = slist_agregar_inicio(nueva, temp1->dato);
      }
    }
  }
  return nueva;
}

SList slist_intersecar_custom(SList lista, SList lista2, FuncionVisitante1 visit)
{
  if(slist_vacia(lista) || slist_vacia(lista2))return NULL;
  SList nueva = slist_crear();
  for(SNodo *temp1 = lista ; temp1 != NULL ; temp1 = temp1->sig){
    for(SNodo *temp2 = lista2 ; temp2 != NULL ; temp2 = temp2->sig){
      if(visit(temp1->dato, temp2->dato)){
        nueva = slist_agregar_inicio(nueva, temp1->dato);
      }
    }
  }
  return nueva;
}

void bubblesort(int array[], int longitud){
  for(int iter = 0 ; iter < longitud - 1 ;iter++){
    for(int i = 0 ; i < longitud - iter - 1 ; i++){
      if(array[i] > array[i+1]){
        int temp = array[i+1];
        array[i+1] = array[i];
        array[i] = temp;
      }
    }
  }
}

SList slist_ordenar_menor_a_mayor(SList lista, int longitud){
  for(int iter = 0 ; iter < longitud - 1 ; iter++){
    SNodo *temp = lista;
    for(int i = 0 ; i < longitud - iter - 1 ; i++,temp = temp->sig){
      if(temp->dato > temp->sig->dato){
        int temp1 = temp->sig->dato;
        temp->sig->dato = temp->dato;
        temp->dato = temp1;
      }
    }
  }
  return lista;
}

SList slist_ordenar_mayor_a_menor(SList lista, int longitud){
  for(int iter = 0 ; iter < longitud - 1 ; iter++){
    SNodo *temp = lista;
    for( int i = 0; i < longitud - iter - 1 ; i++,temp = temp->sig){
      if(temp->dato < temp->sig->dato){
        int temp1 = temp->sig->dato;
        temp->sig->dato = temp->dato;
        temp->dato = temp1;
      }
    }
  }
  return lista;
}

SList slist_ordenar(SList lista, Orden o){
  if(slist_vacia(lista))return NULL;
  else if(o == 0){
    return(slist_ordenar_mayor_a_menor(lista,slist_longitud(lista)));
  }
  return(slist_ordenar_menor_a_mayor(lista,slist_longitud(lista)));
}

SList slist_reverso(SList lista){
  if(slist_vacia(lista))return NULL;
  SNodo *temp = lista;
  SList nueva = slist_crear();
  for(; temp != NULL ; temp = temp->sig){
    nueva = slist_agregar_inicio(nueva, temp->dato);
  }
  return nueva;
}

SList slist_intercalar(SList lista, SList lista1){
  if(slist_vacia(lista))return lista1;
  else if(slist_vacia(lista1)) return lista;
  SList nueva = slist_crear();
  SNodo * temp1 = lista;
  SNodo * temp2 = lista1;
  for(;temp1 != NULL || temp2 != NULL;){
    if(temp1 != NULL && temp2 != NULL){
      nueva = slist_agregar_final(nueva, temp1->dato);
      nueva = slist_agregar_final(nueva, temp2->dato);
      temp1 = temp1->sig;
      temp2 = temp2->sig;
    }
    else if(temp1 == NULL){
      nueva = slist_agregar_final(nueva,temp2->dato);
      temp2 = temp2->sig;
    }
    else if(temp2 == NULL){
      nueva = slist_agregar_final(nueva,temp1->dato);
      temp1 = temp1->sig;
    }
  }
  return nueva;
}