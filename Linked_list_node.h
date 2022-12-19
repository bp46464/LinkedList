#pragma once
#include<iostream>

template<typename T>
class Linked_list_node
{
public:
    T data;
    Linked_list_node* next;
    Linked_list_node* prev;

    Linked_list_node();
    Linked_list_node(T);


};

template<typename T>
inline Linked_list_node<T>::Linked_list_node()
{
    next = NULL;
    prev = NULL;
    data = NULL;
}

template<typename T>
inline Linked_list_node<T>::Linked_list_node(T dane)
{
    next = NULL;
    prev = NULL;
    data = dane;
}