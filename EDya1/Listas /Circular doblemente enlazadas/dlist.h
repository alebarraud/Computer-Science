#ifndef  __DLIST_H__
#define __DLIST_H__

//vamos a implementar listas doblemente enlazadas de manera circular
typedef struct _DNodo{
  int dato;
  struct _DNodo *sig;
  struct _DNodo *ant;
}DNodo;

typedef enum{
  RECORRIDO_HACIA_ADELANTE = 0,//0
  RECORRIDO_HACIA_ATRAS = 1//1
}Recorrido;

typedef DNodo* DList;
typedef void (*FuncionVisitante)(int dato);
typedef int (*FuncionComparacion)(int dato, int dato1);

DList dlist_crear();

int dlist_vacia(DList lista);

void dlist_destruir(DList lista);

DList dlist_agregar_inicio(DList lista, int dato);

DList dlist_agregar_final(DList lista, int dato);

void recorrido_adelante(DList lista, FuncionVisitante visit);

void recorrido_atras(DList lista, FuncionVisitante visit);

void dlist_recorrer(DList lista, FuncionVisitante visit, Recorrido num);

int dlist_longitud(DList lista);

DList dlist_concatenar(DList lista, DList lista2);

DList dlist_insertar(DList lista, int dato, int pos);

DList dlist_eliminar(DList lista, int pos);

int dlist_contiene(DList lista, int dato);

int dlist_indice(DList lista, int dato);

DList dlist_intersecar(DList lista, DList lista1);

DList dlist_intersecar_custom(DList lista, DList lista1, FuncionComparacion visit);

DList dlist_ordenar(DList lista);

DList dlist_reverso(DList lista);

#endif
