#include <iostream>
#include<string>
#include <ctime>
#include<chrono>
#include"Linked_list.h"
using namespace std;
int main()
{
	clock_t start = clock();
	Linked_list<int>* l1 = new Linked_list<int>();

	int r = 10000000;


	for (int i = 0; i < r; i++)
	{
		l1->add(i);
		//std::cout << l1->get(i)<<"\n";
	}
	clock_t t1 = clock();
	std::cout << "Time:" << (float)(t1 - start) / (float)CLOCKS_PER_SEC << endl;
	std::cout << "Time ps:" << (float)(t1 - start) / (float)CLOCKS_PER_SEC / r << endl;

	l1->add_s(85);//dodanie wartosci na poczatku
	
	l1->del_last();//usuniecie ostatniego

	l1->del_first();//usuniecie pierwszego

	l1->swap(2, 14);//swap (index, element)

	l1->sear_del(3, l1);
	//l1->clear();
	/*for (int i = 0; i < l1->size; i++)
	{
		std::cout << l1->get(i) << "\n";
	}
	*/
	//std::cout << std::boolalpha << l1->sear_del(9, l1)<<endl;//usun index, lista

	//std::cout << l1->convert();
	clock_t end = clock();
	std::cout << "\nTotal Time:" << (float)(end - start) / (float)CLOCKS_PER_SEC << endl;
}