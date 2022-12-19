#pragma once
#include"Linked_list_node.h"
#include<string>
template<typename T>
class Linked_list
{
public:
    Linked_list_node<T>* head;
    Linked_list_node<T>* tail;
    int size = 0;

    void add(T);
    void add_s(T);
    void del_last();
    void del_first();
    void swap(int index, T dane);
    int search(int, Linked_list<T>*);
    bool sear_del(int, Linked_list<T>*);
    void clear();
    std::string convert();
    T get(int);
};

template<typename T>
inline void Linked_list<T>::add(T dane)
{
    Linked_list_node<T>* node = new Linked_list_node<T>();
    size++;
    node->data = dane;
    if (head == NULL)//jezeli nie ma pierwszego elementu
    {
        head = node;//prev=null domyslnie
    }
    node->prev = tail; //polaczenie ogona
    tail = node;//teraz node jest ostatnim elementem
    if (node->prev != NULL)//jezeli wczesniej jest juz jakis wagonik
    {
        node->prev->next = node;//zrobić link poprzedni<->aktualny (skleić je)
    }
}

template<typename T>
inline void Linked_list<T>::add_s(T dane)
{
    Linked_list_node<T>* node = new Linked_list_node<T>();
    size++;
    node->data = dane;
    head->prev = node;//przypisanie do przed head nowej wartosci
    node->next = head;//od teraz w całości połączone są nowy head z listą
    head = node; //wpisanie do head nowych wartości
}

template<typename T>
inline void Linked_list<T>::del_last()
{
    Linked_list_node<T>* scnd = head;//mamy na poczatku
    while (scnd->next->next != NULL) //while nastepny->nastepny nie jest pusty
        scnd = scnd->next;
    delete(scnd->next);//usuniecie nastepnego po przedostatnim node
    scnd->next = NULL;//wyzerowanie nastepnego pola
    size--;//zmniejszenie rozmiaru 
}

template<typename T>
inline void Linked_list<T>::del_first()
{
    if (head == NULL)
        std::cout << "Brak elementow w liscie.\n";
    else
    {
        Linked_list_node<T>* frst = head; //ustawiam na poczatku
        head = head->next;//head staje się drugim elementem listy
        delete(frst);//czyszczenie
        size--;
    }

}

template<typename T>
inline void Linked_list<T>::swap(int index, T dane)
{
    Linked_list_node<T>* wsk = head;

    if (index > size && size == 0)
    {
        return;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            wsk = wsk->next;
        }
        wsk->data = dane;
    }

}

template<typename T>
inline int Linked_list<T>::search(int dane, Linked_list<T> * src)
{
    Linked_list<T>* tmp = src;
    Linked_list_node<T>* tmp2 = tmp->head;
    while (tmp2 != NULL)
    {
        if (tmp2->data == dane)
            return tmp2->data;
        tmp2 = tmp2->next;
    }
    return NULL;
}

template<typename T>
inline bool Linked_list<T>::sear_del(int dane, Linked_list<T> * src)
{
    Linked_list<T>* tmp = src;
    Linked_list_node<T>* tmp2 = tmp->head;
    if (dane < size && size != 0)
    {
        if (dane == 0)
        {
            tmp->del_first();
            return true;
        }

        if (dane == src->size)
        {
            tmp->del_last();
            return true;
        }
        else
        {
            for (int i = 0; i < dane; i++)
            {
                tmp2 = tmp2->next;
            }
            tmp2->prev->next = tmp2->next;
            delete(tmp2);
            size--;
            return true;
        }


    }
    else
        return false;
}

template<typename T>
inline void Linked_list<T>::clear()
{
    Linked_list_node<T>* frst = head; //ustawiam na poczatku
    Linked_list_node<T>* scnd = head;
    while (frst != NULL)
    {
        scnd = frst->next;//w taki sposob przechodze do nastepnych node
        delete(frst);//usuwam pierwszy
        frst = scnd;//drugi staje sie pierwszym itp

        size--;
    }
    delete(scnd);
}

template<typename T>
inline std::string Linked_list<T>::convert()
{
    Linked_list_node<T>* tmp = head;
    std::string s;

    while (tmp != NULL)
    {
        s += std::to_string(tmp->data);
        s += " ";
        tmp = tmp->next;
    }
    return s;
}


template<typename T>
inline T Linked_list<T>::get(int numer)
{
    Linked_list_node<T>* node = head; //zaczynam od pocztku listy
    if (size != 0)//wiadomo, ograniczenia
    {
        if (numer > size)
            return NULL;
        else
        {
            for (int i = 0; i < numer; i++)
            {
                node = node->next;//bierzemy nastepnego node
            }
        }
    }
    return node->data;
}