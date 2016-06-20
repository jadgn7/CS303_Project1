
#include "OrderedPoly.h"
#include<iostream>
#include<string>

using namespace std;

void printPoly(const Polynomial<int>& f){
	Polynomial<int>::const_piterator iter =  f.begin();
	cout<<"E C"<<endl<<"-------"<<endl;
	while (iter!=f.end()){
		cout<< *iter<<" "<<iter.getCo()<<endl;
		++iter;
		if (iter != f.end())
			cout<<endl;
	}
}

void printOrderedPoly(const OrderedPoly<int>& f){
	OrderedPoly<int>::const_piterator iter =  f.begin();
	while (iter!=f.end()){
		if ((f.getLeadDegree() != *iter)&& (iter.getCo()>0))
			cout << "+";
		if (*iter == 0) {
			cout << "1";
			++iter;
		}
		else {
			if (iter.getCo() != 1) {
				cout << iter.getCo();
			}
			cout << "x";
			if ((*iter != 1)) {
				cout << "^" << *iter;
			}
			}
			++iter;
	}
	cout << endl << endl;
}

void main(void){

	cout<<"Things are okay"<<endl<<endl;
	//test normal list functions

	cout<<endl<<"Ordered"<<endl<<endl;
	//OrderedPoly test
	OrderedPoly<int> o;
	o.insert(2,3);
	o.insert(3,2);
	o.insert(4,1);
	o.insert(1,7);
	o.insert(0, 4);
	o.insert(4, 0);
	o.insert(5, 3);
	o.insert(-5, 5);
	o.insert(5, -5);
	printOrderedPoly(o);
}
