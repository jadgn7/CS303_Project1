#include <cstddef>
template <typename ItemType>

class Polynomial{
private://================================================================================================
			struct Term{
			//term components
			ItemType coefficient;
			ItemType exponent;
			//Pointer to next term
			Term* next;
			//Pointer to previous term
			Term* prev;

			//Term Constructor
			Term (const ItemType& givenCoefficient, const ItemType& givenExponent, 
				Term* prevValue = NULL, Term* nextValue =NULL) :
				coefficient(givenCoefficient), exponent(givenExponent), prev(prevValue), next(nextValue){}
		};

		//reference to head
		Term* leadingTerm;
		//reference to tail
		Term* lowestTerm;

		//current number of terms
		size_t numTerms;
		//overload operators to test exponents
		/*bool operator >(const Term& other){
				return (exponent>other.exponent);
		}
		bool operator <(const Term& other){
				return (exponent<other.exponent);
		}*/
public://==========================================================
	
#include "const_Polynomial_It.h"
	friend class iterator;
#include "Polynomial_It.h"
	friend class const_iterator;

	//Polynomial constructor 
	Polynomial() : leadingTerm(NULL),lowestTerm(NULL),numTerms(0){}


	//Polynomial copy constructor
	Polynomial(const Polynomial<ItemType>& other) :
		leadingTerm(NULL),lowestTerm(NULL),numTerms(0){
			for (const_iterator itr = other.begin(); itr!= other.end(); itr++){
				push_back(*itr);
			}
	}
	// Polynomial Destructor
	~Polynomial(){
		while (leadingTerm!=NULL){
			Term* current = leadingTerm;
			leadingTerm = leadingTerm->next;
			delete current;
		}
		lowestTerm = NULL;
		numTerms = 0;
	}

//*Polynomial functions*//------------------------------------------------------
	
	//operator~Polynomial overwrite--not yet working
	/*
	Polynomial<ItemType>& operator=(const Polynomial<ItemType>& other){
		Polynomial<ItemType> temp(other);
		swap(temp);
		return *this;
	}*/

	//function~push new Term to front of polynomial
	void push_front(const ItemType& coefficientIN, const ItemType& exponentIN){
		leadingTerm = new Term(coefficientIN,exponentIN, NULL, leadingTerm);//create new Term
		if (leadingTerm->next !=NULL)//if next Term is not null, Make next term's previous this Term
			leadingTerm->next->prev = leadingTerm;
		if (lowestTerm==NULL)//if Polynomial was empty, leading term is also lowest term
			lowestTerm = leadingTerm;
		numTerms++;//increase number of terms in Polynomial
	}
	//function~push new Term to back of polynomial
	void push_back(const ItemType& coefficientIN, const ItemType& exponentIN){
		if (lowestTerm!=NULL){//if at least one term present, create new term after lowest
			lowestTerm->next = new Term(coefficientIN, exponentIN, lowestTerm, NULL);
			lowestTerm = lowestTerm->next;//make current lowest Term's next the new lowest term
			numTerms++;//increase number of terms
		}
		else //Polynomial was empty, 
			push_front(coefficientIN, exponentIN);
	}
	//function~remove leading Term of Polynomial
	void pop_front(){
		if (leadingTerm==NULL)//prevent attempt to pop empty list
			throw std::invalid_argument("Cannot Pop from empty list!");
		Term* removedTerm = leadingTerm;//save pointer to leading term 
		leadingTerm = leadingTerm->next;//2nd highest term is new leading term
		delete removedTerm; //delete previous leading term
		if (leadingTerm != NULL)//if polynomial is not empty, make sure leading term has none before it
			leadingTerm->prev = NULL;
		else{
			lowestTerm = NULL;//if polynomial is empty, reset lowest term;
		}
		numTerms--;//decrease number of terms
	}
	//function~remove lowest term of Polynomial
	void pop_back(){
		if (lowestTerm==NULL)
			throw std::invalid_argument("Cannot Pop from empty list!");
		Term* removedTerm = lowestTerm;//save pointer to lowest term
		lowestTerm = lowestTerm->prev;//2nd lowest is new lowest term
		delete removedTerm;//delete previous lowest term
		if (lowestTerm!=NULL)//if not empty, make sure lowest term is last
			lowestTerm->next=NULL;
		else
			leadingTerm = NULL;//if polynomial is empty, reset leading term;
		numTerms--;
	}

		//iterator definition


//*iterator functions*//------------------------------------------------
	//function~send iterator to beginning of Polynomial
	iterator begin(){
		return iterator(this, leadingTerm);
	}
	//function~send const iterator to beginning of Polynomial
	const_iterator begin() const{
		return const_iterator(this, leadingTerm);
	}
	//function~send iterator to end of Polynomial
	iterator end(){
		return iterator(this, NULL);
	}
	//function~send const iterator to end of Polynomial
	const_iterator end() const{
		return const_iterator(this, NULL);
	}
	//function~insert new Term based on iterator position
	iterator insert(iterator position, const ItemType& coefficientIN, const ItemType& exponentIN){
		if (position.current == leadingTerm){//iterator at begin()
			push_front(coefficientIN, exponentIN);
			return begin();
		}
		else if (position.current==NULL){//iterator at end()
			push_back(coefficientIN, exponentIN);
			return iterator(this, lowestTerm);
		}

	}

};
