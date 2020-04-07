#include "clist.h"
#include <stdio.h>
#include <stdlib.h>

CList clist_crear(){
  return NULL;
}

int clist_es_vacia(CList lista){
  return lista == NULL;
}

void clist_destruir(CList lista){
  CNodo *eliminar;
  CNodo *temp = lista->sig;
  while(temp != lista){
    eliminar = temp;
    temp = temp->sig;
    free(eliminar);
  }
  free(lista);
}

CList clist_agregar_inicio(CList lista, int dato){
  CNodo *nuevo = malloc(sizeof(struct _CNodo));
  nuevo->dato = dato;
  if(clist_es_vacia(lista)){
    nuevo->sig = nuevo;
    return nuevo;
  }
  nuevo->sig = lista;
  CNodo *temp = lista;
  for(;temp->sig != lista; temp = temp ->sig);
  temp->sig = nuevo;
  return nuevo;
}

CList clist_agregar_final(CList lista, int dato){
  CNodo *nuevo = malloc(sizeof(struct _CNodo));
  nuevo->dato = dato;
  if(clist_es_vacia(lista)){
    nuevo->sig = nuevo;
    return nuevo;
  }
  nuevo->sig = lista;
  CNodo *temp = lista;
  for(;temp->sig != lista; temp = temp ->sig);
  temp->sig = nuevo;
  return lista;
}

void clist_recorrer(CList lista, FuncionVisitante visit){
  if(clist_es_vacia(lista))return;
  CNodo *temp = lista;
  for(;temp->sig != lista; temp = temp->sig){
    visit(temp->dato);
  }
  visit(temp->dato);
}

int clist_longitud(CList lista){
  if(clist_es_vacia(lista))return 0;
  CNodo *temp = lista;
  int i = 1;
  for(;temp->sig != lista;temp = temp->sig, i++);
  return i;
}

CList clist_concatenar(CList lista, CList lista2){
  if(clist_es_vacia(lista))return lista2;
  else if(clist_es_vacia(lista2))return lista;
  CNodo * temp = lista;
  for(;temp->sig != lista; temp = temp->sig);
  temp->sig = lista2;
  CNodo *temp2 = lista2;
  for(;temp2->sig != lista2; temp2 = temp2->sig);
  temp2->sig = lista;
  return lista;
}

CList clist_insertar(CList lista, int dato, int posicion){
  int longitud = clist_longitud(lista);
  if((posicion > longitud) || (longitud < 0)){
    //esta seria una posicion incorrecta asi que retornamos la misma lista
    return lista;
  }
  else if(posicion == 0){
    return clist_agregar_inicio(lista,dato);
  }
  CNodo *nuevo = malloc(sizeof(struct _CNodo));
  nuevo->dato = dato;
  CNodo *temp = lista;
  int i = 1;
  for(;i != posicion; temp = temp->sig,i++);
  nuevo->sig = temp->sig;
  temp->sig = nuevo;
  return lista;
}

CList clist_eliminar(CList lista, int posicion){
  int longitud = clist_longitud(lista);
  if(clist_es_vacia(lista) || posicion < 0 || posicion >= longitud){
    return lista;
  }
  CNodo *temp = lista;
  if(posicion == 0){
    for(;temp->sig != lista; temp = temp->sig);
    temp->sig = lista->sig;
    free(lista);
    return (temp->sig);
  }
 
  int i = 1;
  for(;i != posicion;i++, temp = temp->sig);
  CNodo *eli = temp->sig;
  temp->sig = temp->sig->sig;
  free(eli);
  return lista;
}

int clist_contiene(CList lista, int dato){
  if(clist_es_vacia(lista))return 0;
  CNodo *temp = lista;
  for(;temp->sig != lista && temp->dato != dato; temp = temp->sig);
  return(temp->dato == dato);
}

int clist_indice(CList lista, int dato){
  if(clist_es_vacia(lista))return -1;//en el caso de que no este el elemento en la lista retornamos el indice -1
  CNodo *temp = lista;
  int i = 0;
  for(;temp->sig != lista && temp->dato != dato; temp = temp->sig,i++);
  if(temp->dato == dato)return i;
  return -1;
}

CList clist_intersecar(CList lista, CList lista1){
  if(clist_es_vacia(lista) || clist_es_vacia(lista1))return NULL; //en caso de que una de las listas sea vacia retorno NULL
  int longitud1 = clist_longitud(lista);
  int longitud2 = clist_longitud(lista1);
  int i = 0;
  int j;
  CList nueva = clist_crear();
  for(CNodo *temp = lista ; i < longitud1 ; i++, temp = temp->sig){
    j = 0;
    CNodo *temp1 = lista1;
    for(; j < longitud2 ; j++, temp1 = temp1->sig){
      if(temp->dato == temp1->dato){
        nueva = clist_agregar_inicio(nueva, temp->dato);
      }
    }
  }
  return nueva;
}

CList clist_intersecar_custom(CList lista, CList lista1, FuncionComparacion visit){
  if(clist_es_vacia(lista) || clist_es_vacia(lista1))return NULL;
  int longitud1 = clist_longitud(lista);
  int longitud2 = clist_longitud(lista1);
  int i = 0;
  int j;
  CList nueva = clist_crear();
  for(CNodo *temp = lista ; i < longitud1 ; i++, temp = temp->sig){
    j = 0;
    CNodo *temp1 = lista1;
    for(; j < longitud2 ; j++, temp1 = temp1->sig){
      if(visit(temp->dato, temp1->dato)){
        nueva = clist_agregar_inicio(nueva, temp->dato);
      }
    }
  }
  return nueva;
}



CList clist_ordenar(CList lista){
  if(clist_es_vacia(lista)) return lista;
  int longitud = clist_longitud(lista);
  CNodo *temp;
  for(int iter = 0 ; iter < longitud - 1 ; iter++){
    temp = lista;
    for(int i = 0 ; i < longitud - iter - 1 ; i++,temp = temp->sig){
      if(temp->dato > temp->sig->dato){
        int temporal = temp->dato;
        temp->dato = temp->sig->dato;
        temp->sig->dato = temporal;
      }
    }
  }
  return lista;
}

CList clist_reverso(CList lista){
  if(clist_es_vacia(lista))return NULL;
  CList reversa = clist_crear();
  CNodo *temp = lista;
  for(;temp->sig != lista; temp = temp->sig){
    reversa = clist_agregar_inicio(reversa,temp->dato);
  }
  reversa = clist_agregar_inicio(reversa,temp->dato);
  return reversa;
}

CList clist_intercalar(CList lista, CList lista1){
  if(clist_es_vacia(lista))return lista1;
  else if(clist_es_vacia(lista1))return lista;
  int longitud1 = clist_longitud(lista);
  int longitud2 = clist_longitud(lista1);
  CList nueva = clist_crear();
  CNodo *temp1 = lista;
  CNodo *temp2 = lista1;
  int i = 0;
  int j = 0;
  for(;j< longitud2 || i < longitud1;i++,j++){
        if(i == longitud1){
          nueva = clist_agregar_final(nueva,temp2->dato);
          temp2 = temp2->sig;
        }
        else if(j == longitud2){
          nueva = clist_agregar_final(nueva,temp1->dato);
          temp1 = temp1->sig;
        }
        else{
          nueva = clist_agregar_final(nueva,temp1->dato);
          nueva = clist_agregar_final(nueva,temp2->dato);
          temp1 = temp1->sig;
          temp2 = temp2->sig;
        }
  }
  return nueva;
}
