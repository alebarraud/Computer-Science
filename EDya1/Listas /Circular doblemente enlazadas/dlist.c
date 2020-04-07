#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>

DList dlist_crear(){
  return NULL;
}

int dlist_vacia(DList lista){
  return(lista == NULL);
}

void dlist_destruir(DList lista){//verificar
  if(dlist_vacia(lista)){
    return;
  }
  lista->ant->sig = NULL;
  DNodo *temp = lista;
  DNodo *eliminar;
  while(temp != NULL){
    eliminar = temp;
    temp = temp->sig;
    free(eliminar);
  }
}

DList dlist_agregar_inicio(DList lista, int dato){
  DNodo *nuevo = malloc(sizeof(struct _DNodo));
  nuevo->dato = dato;
  if(dlist_vacia(lista)){
    nuevo->sig = nuevo->ant = nuevo;
    return nuevo;
  }
  nuevo->sig = lista;
  nuevo->ant = lista->ant;
  lista->ant->sig = nuevo;
  lista->ant = nuevo;
  return nuevo;
}

DList dlist_agregar_final(DList lista, int dato){
  DNodo *nuevo = malloc(sizeof(struct _DNodo));
  nuevo->dato = dato;
  if(dlist_vacia(lista)){
    nuevo->sig = nuevo->ant = nuevo;
    return nuevo;
  }
  nuevo->sig = lista;
  nuevo->ant = lista->ant;
  lista->ant->sig = nuevo;
  lista->ant = nuevo;
  return lista;
}

void recorrido_adelante(DList lista, FuncionVisitante visit){
  DNodo *temp = lista;
  for(;temp->sig != lista; temp = temp->sig){
    visit(temp->dato);
  }
  visit(temp->dato);
}

void recorrido_atras(DList lista, FuncionVisitante visit){
  DNodo* temp = lista->ant;
  for(;temp != lista; temp = temp->ant){
    visit(temp->dato);
  }
  visit(lista->dato);
}

void dlist_recorrer(DList lista, FuncionVisitante visit, Recorrido num){
  if(dlist_vacia(lista))return;
  else if(num == 0){
    recorrido_adelante(lista,visit);
  }
  else{
    recorrido_atras(lista,visit);
  }
}

int dlist_longitud(DList lista){
  if(dlist_vacia(lista))return 0;
  int i = 0;
  DNodo *temp = lista;
  for(;temp->sig != lista;i++,temp = temp->sig);
  return(i+1);
}

DList dlist_concatenar(DList lista, DList lista2){
  if(dlist_vacia(lista))return lista2;
  if(dlist_vacia(lista2))return lista;
  DNodo *ult = lista2->ant;
  lista2->ant->sig = lista;
  lista2->ant = lista->ant;
  lista->ant->sig = lista2;
  lista->ant = ult;
  return lista;
}

DList dlist_insertar(DList lista, int dato, int pos){
  int longitud = dlist_longitud(lista);
  if(pos != 0 && dlist_vacia(lista))return lista;
  else if(pos == 0 || dlist_vacia(lista)){
    return(dlist_agregar_inicio(lista,dato));
  }
  else if(pos > longitud || pos < 0){
    return lista;//posicion incorrecta, devolvemos la misma lista
  }
  //else if(pos == longitud){   ES MAS EFICIENTE ESTO VERDAD??
    //return(dlist_agregar_final(lista,dato));
  //}
  DNodo *nuevo = malloc(sizeof(struct _DNodo));
  nuevo->dato = dato;
  DNodo *temp = lista;
  int i = 1;
  for(;i != pos;i++, temp = temp->sig);
  nuevo->sig = temp->sig;
  nuevo->ant = temp;
  temp->sig->ant = nuevo;
  temp->sig = nuevo;
  return lista;
}

DList dlist_eliminar(DList lista, int pos){
  int longitud = dlist_longitud(lista);
  if(dlist_vacia(lista))return lista;//no hay elementos para eliminar
  else if(pos < 0 || pos >= longitud){ //esta seria una posicion invalida
    return lista;
  }
  else if(pos == 0){
    DNodo *elim = lista;
    lista->sig->ant = lista->ant;
    lista->ant->sig = lista->sig;
    lista = lista->sig;
    free(elim);
    return lista;
  }
  int i = 0;
  DNodo* temp = lista;
  for(;i != pos;i++,temp = temp->sig);
  DNodo* elim = temp;
  temp->ant->sig = temp->sig;
  temp->sig->ant = temp->ant;
  free(elim);
  return lista;
}

int dlist_contiene(DList lista, int dato){
  if(dlist_vacia(lista))return 0;
  DNodo *temp = lista;
  for(;temp->sig != lista && temp->dato != dato; temp = temp->sig);
  return(temp->dato == dato);
}

int dlist_indice(DList lista, int dato){
  if(dlist_vacia(lista))return -1;
  DNodo *temp = lista;
  int i = 0;
  for(;temp->sig != lista && temp->dato != dato; temp = temp->sig,i++);
  if(temp->dato == dato)return i;
  return -1;
}

DList dlist_intersecar(DList lista, DList lista1){
  if(dlist_vacia(lista) || dlist_vacia(lista1))return NULL;
  lista->ant->sig = NULL;
  lista1->ant->sig = NULL;
  DList nueva = NULL;
  for(DNodo* temp = lista ; temp != NULL; temp = temp->sig){
    for(DNodo* temp1 = lista1 ; temp1 != NULL ; temp1 = temp1->sig){
      if(temp->dato == temp1->dato){
        nueva = dlist_agregar_inicio(nueva,temp1->dato);
      }
    }
  }
  lista->ant->sig = lista;
  lista1->ant->sig = lista1;
  return nueva;
}


DList dlist_intersecar_custom(DList lista, DList lista1, FuncionComparacion visit){
  if(dlist_vacia(lista) || dlist_vacia(lista1))return NULL;
  lista->ant->sig = NULL;
  lista1->ant->sig = NULL;
  DList nueva = NULL;
  for(DNodo* temp = lista ; temp != NULL; temp = temp->sig){
    for(DNodo* temp1 = lista1 ; temp1 != NULL ; temp1 = temp1->sig){
      if(visit(temp->dato, temp1->dato)){
        nueva = dlist_agregar_inicio(nueva,temp1->dato);
      }
    }
  }
  lista->ant->sig = lista;
  lista1->ant->sig = lista1;
  return nueva;
}

DList dlist_ordenar(DList lista){
  if(dlist_vacia(lista))return lista;
  else if(lista->sig == lista)return lista;
  int longitud = dlist_longitud(lista);
  DNodo *temp;
  for(int iter = 0 ;iter < longitud - 1; iter++){
    temp = lista;
    for(int i = 0 ; i < longitud - iter -1 ; i++,temp = temp->sig){
      if(temp->dato > temp->sig->dato){
        int temporal  = temp->dato;
        temp->dato = temp->sig->dato;
        temp->sig->dato = temporal;
      }
    }
  }
  return lista;
}

DList dlist_reverso(DList lista){
  if(dlist_vacia(lista))return lista;
  else if(lista->sig == lista) return lista;
  DList reversa = NULL;
  DNodo *temp = lista->ant;
  for(;temp != lista; temp = temp->ant){
    reversa = dlist_agregar_final(reversa,temp->dato);
  }
  reversa = dlist_agregar_final(reversa,temp->dato);
  return reversa;
}
