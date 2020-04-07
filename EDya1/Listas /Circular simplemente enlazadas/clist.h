#ifndef __CLIST_H__
#define __CLIST_H__

typedef struct _CNodo{
  int dato;
  struct _CNodo *sig;
}CNodo;

typedef CNodo* CList;
typedef void (*FuncionVisitante)(int dato);
typedef int (*FuncionComparacion)(int dato1, int dato2);

CList clist_crear();

int clist_es_vacia(CList lista);

CList clist_agregar_inicio(CList lista, int dato);

CList clist_agregar_final(CList lista, int dato);

void clist_recorrer(CList lista, FuncionVisitante visit);

void clist_destruir(CList lista);

int clist_longitud(CList lista);

CList clist_concatenar(CList lista, CList lista2);

CList clist_insertar(CList lista, int dato, int posicion);

CList clist_eliminar(CList lista, int posicion);

int clist_contiene(CList lista, int dato);

int clist_indice(CList lista, int dato);

CList clist_intersecar(CList lista, CList lista1);

CList clist_intersecar_custom(CList lista, CList lista1, FuncionComparacion visit);

CList clist_ordenar(CList lista);

CList clist_reverso(CList lista);

CList clist_intercalar(CList lista, CList lista1);

#endif
