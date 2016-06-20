
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
	cout<<"E C"<<endl<<"-------"<<endl;
	while (iter!=f.end()){
		cout<< *iter<<" "<<iter.getCo()<<endl;
		++iter;
		if (iter != f.end())
			cout<<endl;
	}
}

void main(void){

	cout<<"Things are okay"<<endl<<endl;
	cout<<endl<<"Unordered"<<endl<<endl;
	//test normal list functions

	//Polynomial test
	Polynomial<int> p;
	p.push_back(2,3);
	p.push_back(3,2);
	p.push_front(4,1);
	p.push_back(1,7);
	p.push_front(0,0);
	p.push_back(0,0);
	p.pop_back();
	p.pop_front();
	printPoly(p);
	cout<<endl<<"Ordered"<<endl<<endl;

	//OrderedPoly test
	OrderedPoly<int> o;
	o.insert(2,3);
	o.insert(3,2);
	o.insert(4,1);
	o.insert(1,7);
	printOrderedPoly(o);
}
