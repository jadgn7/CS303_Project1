#ifndef POLYNOMIAL_ITERATOR_H
#define POLYNOMIAL_ITERATOR_H
class iterator{
	//Parent Class Access
	friend class Polynomial<ItemType>;

private:
	//reference to parent
	Polynomial<ItemType>* parent;
	//pointer to selected term
	typename Polynomial<ItemType>::Term* current;

	//iterator constructor
	iterator(Polynomial<ItemType>* itParent, Term* position) :
		parent(itParent), current(position) {}

public:

	//operator~returns reference to selected Term if valid
	ItemType& operator*() const {
		if (current == NULL)
			throw std::invalid_argument("Cannot dereference end()");
		return current->exponent;
	}

	//operator~enforce pointer to selected Term if valid
	ItemType& operator->(){
		if (current == NULL)
			throw std::invalid_argument("Cannot dereference end()");
		return &(current->exponent)
	}

	//operator~advance iterator
	iterator& operator++(){
		if (current == parent->leadingTerm)
			throw std::invalid_argument("Cannot advance past end()");
		current = current->next;
		return *this;
	}

	//operator~retreat iterator
	iterator& operator--(){
		if (current == parent->lowestTerm)
			throw std::invalid_argument("Cannot retreat before begin()");
		current = current->prev;
		return *this;
	}
	//operator~return value prior to advance
	iterator operator++(int){
		iterator originalValue =*this;
		++(*this);
		return originalValue;
	}
	//operator~return value prior to retreat
	iterator operator--(int){
		iterator originalValue = *this;
		--(*this);
		return originalValue;
	}

	//operator~equality operator
	bool operator ==(const iterator& other){
		return current == other.current;
	}
	//operator~!=inequality operator
	bool operator !=(const iterator& other){
		return current != other.current;
	}

	};

#endif