#include "Structures.h"
#include <typeinfo>

class Animal {
public :
	
	Animal(string name) {
		_name = name;
	}

	string GetName() {
		return _name;
	}

	void SetOrder(int ord) {
		_order = ord;
	}

	int GetOrder() {
		return _order;
	}

private:
	string _name;
	int _order;
};

class Dog : public Animal {};
class Cat : public Animal {};

class AnimalShelter {

public:
	AnimalShelter() { _order = 0; }
	
	void Enqueue(Animal animal) {
		
		animal.SetOrder(_order++);

		if (typeid(animal).operator==(typeid(_dogShelter))) {
			_dogShelter.Enqueue(animal);
		}
		else {
			_catShelter.Enqueue(animal);
		}
	}

	Animal DequeueAny() {
		if (_dogShelter.peek().GetOrder() < _catShelter.peek().GetOrder)
			return DequeueDog();
		else
			return DequeueCat();
	}

	Animal DequeueDog() {
		return _dogShelter.dequeue();
	}

	Animal DequeueCat() {
	
		return _catShelter.dequeue();
	}

private:
	Queue<Animal> _dogShelter;
	Queue<Animal> _catShelter;
	int _order;
};