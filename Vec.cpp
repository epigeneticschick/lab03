/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */
 
#include "Vec.h"
#include <cstdlib>

Vec::Vec() {
	myArray = NULL;
	mySize = 0;
}

Vec::Vec(unsigned size) {
		mySize = size;
	if (size> 0){
		myArray = new double[mySize];
	}
	else{
		myArray = NULL;
	}
	for(unsigned i=0; i < size; ++i){
		myArray[i]=0;
	}
}

Vec::Vec(const Vec& original) {

	mySize = original.mySize;

	if (original.mySize > 0){
		myArray = new Item[mySize];
		for (unsigned i = 0; i< mySize; ++i) {
			myArray[i] = original.myArray[i];
		}
	}
	else {
		mySize = 0;
		myArray = NULL;
	}
   }

Vec::~Vec() {
	delete []myArray;
	mySize = 0;
	myArray = NULL;
}

Vec& Vec::operator=(const Vec& original) {
	if (this != &original) {
		if (mySize != original.mySize) {
			if (mySize > 0) {
				delete []myArray;
				myArray = NULL;
			}
			if (original.mySize > 0) {
				myArray = new Item[original.mySize];
			}
			mySize = original.mySize;
		}
		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = original.myArray[i];
		}
	}
	return *this;
}

unsigned Vec::getSize() const {
	return mySize;
}

void Vec::setItem(unsigned index, const Item& it){
	if (myArray == NULL){
		throw range_error("myArray is empty");
	}
	if(index > mySize - 1){
		throw range_error("Index Out of Bounds");
	}
	else{
		myArray[index] = it;
	}
}


Item Vec::getItem( unsigned index) const {
	if (myArray == NULL){
		throw range_error("myArray is empty");
	}
	if(index > mySize - 1){
		throw range_error("Index Out of Bounds");
	}
	else{
		return myArray[index];
	}
}

void Vec::setSize(unsigned newSize){
	if (mySize != newSize){
		if (newSize == 0){
			delete []myArray;
			myArray = NULL;
			mySize = 0;
		}
		else{
			newArray = new Item[newSize];
			if (mySize < newSize){
				for(unsigned i= 0; i < mySize; ++i){
					newArray[i] = myArray[i];
				}
				for(unsigned i =mySize; i < newSize; ++i) {
					newArray[i]= 0;
				}
			}
			else{
				for(unsigned i = 0; i < newSize ; ++i){
					newArray[i]= myArray[i];
				}
			}
			mySize = newSize;
			delete []myArray;
			myArray = newArray;
		}

	}
}

bool Vec::operator==(const Vec& v2){
	if (mySize != v2.mySize){
		return false;
	}
	for(unsigned i =0; i < mySize; ++i){
		if(myArray[i] != v2.myArray[i]){
			return false;
		}
	}
	return true;

}


void Vec::writeTo(ostream& out) const{
//Insert each value in myArray into out, separated by space, tab, or newline characters, as you prefer.
	for(unsigned i; i < mySize; ++i){
		out << myArray[i] << '\t';
	}


}

void Vec::readFrom(istream& in){
//Extract each value from in, storing each in a different item of myArray.
	for(unsigned i = 0; i < mySize; i++){
			in >> myArray[i];
	}
}





