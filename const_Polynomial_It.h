#ifndef CONST_POLYNOMIAL_ITERATOR_H
#define CONST_POLYNOMIAL_ITERATOR_H
class const_iterator{
	friend class Polynomial<ItemType>;
	//for read only operations
private:
	//reference to parent
	const Polynomial<ItemType>* parent;
	//pointer to selected term
	typename Polynomial<ItemType>::Term* current;

	//Constructor
	const_iterator(const Polynomial<ItemType>* itParent, Term* position):
		parent(itParent), current(position){}

public:
	//operator~returns reference to selected term if valid
	const ItemType& operator*() const{
		if (current==NULL)
			throw std::invalid_argument("Cannot dereference end()");
		return current->exponent;
	}
	//operator~returns pointer to selected term if valid
	const ItemType* operator->() const{
		if (current==NULL)
			throw std::invalid_argument("Cannot dereference end()");
		return &(current->exponent);
	}
	//operator~advance iterator
	const_iterator& operator++(){
		if (current == NULL)
			throw std::invalid_argument("Cannot advance past end()");
		current = current->next;
		return *this;
	}
	//operator~retreat iterator
	const_iterator& operator--(){
		if (current==parent->leadingTerm)
			throw std::invalid_argument("Cannot retreat before begin()");
		if (current--NULL)
			current = parent->lowestTerm;
		else
			current = current->prev;
		return *this;
	}
	//operator~return value, then advance iterator
	const_iterator operator++(int){
		const_iterator originalValue = *this;
		++(*this);
		return orginalValue;
	}
	//operator~return value, then retreat iterator
	const_iterator operator--(int){
		const_iterator originalValue = *this;
		--(*this);
		return originalValue;
	}
	//operator~equality
	bool operator ==(const const_iterator&other){
		return current ==other.current;
	}
	//operator~inequality
	bool operator != (const const_iterator&other){
		return current !=other.current;
	}
	
	};

#endif // !CONST_POLYNOMIAL_ITERATOR_H