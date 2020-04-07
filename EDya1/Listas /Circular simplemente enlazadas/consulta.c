#include <stdio.h>
#include <stdlib.h>

typedef struct _CNodo{
  int dato;
  struct _CNodo *sig;
}CNodo;

typedef CNodo* CList;
typedef void (*FuncionVisitante)(int dato);


CList clist_crear(){
  return NULL;
}

int clist_es_vacia(CList lista){
  return lista == NULL;
}

void clist_destruir(CList lista){
  if(lista == NULL)return;
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

void imprimir_entero(int dato){
  printf("%d\n",dato);
}

int main(){
  CList lista = clist_crear();
  CList lista2 = clist_crear();

  //lista1
  lista = clist_agregar_inicio(lista,1);
  lista = clist_agregar_final(lista,2);
  lista = clist_agregar_final(lista,3);
  lista = clist_agregar_inicio(lista,0);
  printf("lista1\n");
  clist_recorrer(lista,imprimir_entero);

  //longitud de la lista1
  //printf("longitud de la lista: %d\n",slist_longitud(lista));
  puts("");


  // lista 2
  lista2 = clist_agregar_inicio(lista2,66);
  lista2 = clist_agregar_final(lista2,77);
  lista2 = clist_agregar_final(lista2,88);
  lista2 = clist_agregar_inicio(lista2,99);
  printf("lista2\n");
  clist_recorrer(lista2,imprimir_entero);
  puts("");

  /*concatenacion de listas : a la hora de liberar memoria solo debo liberar de lista ya que la lista se encuentra modificada y es la concatenacion
  de ambas listas asi que con solo liberar memoria de lista tambien estoy liberando la memoria de la lista2
  lista = clist_concatenar(lista,lista2);
  printf("lista concatenada\n");
  clist_recorrer(lista,imprimir_entero);
*/
  //insertar en posicion arbitraria
  lista = clist_insertar(lista,1111,1);
  printf("inserto dato posicion arbitraria\n");
  clist_recorrer(lista,imprimir_entero);

  clist_destruir(lista);
  clist_destruir(lista2);
  return 0;
}
