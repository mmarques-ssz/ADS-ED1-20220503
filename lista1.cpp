#include <iostream>
using  namespace std;

struct Lista
{
	int dado;
	Lista* ant;
};

Lista* init()
{
	return NULL;
}

int isEmpty(Lista* lista)
{
	return (lista == NULL);
}

Lista* insert(Lista* lista, int i)
{
	Lista* novo = new Lista();
	novo->dado = i;
	novo->ant = lista;
	return novo;
}

int count(Lista* lista)
{
	int k = 0;
	Lista* aux;
	aux = lista;
	while (aux != NULL)
	{
		++k;
		aux = aux->ant;
	}
	return k;
}

void print(Lista* lista)
{
	Lista* aux;
	aux = lista;
	while (aux != NULL)
	{
        cout << "Dado: " << aux->dado << endl;
		aux = aux->ant;
	}
	cout << "----------" << endl;
}

Lista* find(Lista* lista, int i)
{
	Lista* aux;
	aux = lista;
	while (aux != NULL && aux->dado != i)
	{
		aux = aux->ant;
	}
	return aux;
}

Lista* remove(Lista* lista, int i)
{
	Lista *aux;
	
	Lista *anterior = NULL;

	aux = lista;
	while (aux != NULL && aux->dado != i)
	{
		anterior = aux;
		aux = aux->ant;
	}
	
	if (aux == NULL)
	{
		return lista;
	}
	
	if (anterior == NULL)
	{
		lista = aux->ant; 
	}
	else
	{
   	    anterior->ant = aux->ant;
	}
	free(aux);
	return lista;
}



int main(int argc, char** argv)
{
	Lista* minhaLista;
	minhaLista = init();
	cout << "Lista vazia: " << (isEmpty(minhaLista)?"SIM":"NAO") << endl;
    cout << "Qtde de elementos: " << count(minhaLista) << endl;
	
	minhaLista = insert(minhaLista, 5);
	cout << "Endereço do dado 5 - " << minhaLista << endl;
	cout << "Lista vazia: " << (isEmpty(minhaLista)?"SIM":"NAO") << endl;
    cout << "Qtde de elementos: " << count(minhaLista) << endl;
    
    minhaLista = insert(minhaLista, 10);
    minhaLista = insert(minhaLista, 20);
    
	cout << "Lista vazia: " << (isEmpty(minhaLista)?"SIM":"NAO") << endl;
    cout << "Qtde de elementos: " << count(minhaLista) << endl;
    print(minhaLista);
    
    Lista* buscado = find(minhaLista,5);
    if (buscado == NULL)
	{
		cout << "Não encontrado" << endl;
	}
	else
	{
		    cout << "Dado do buscado: " << buscado->dado << endl;
		    cout << "Endereço do anterior ao buscado: " << buscado->ant << endl;
	}
	
	minhaLista = remove(minhaLista, 10);
	print(minhaLista);
	
	
	return 0;
}
