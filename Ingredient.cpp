#include "CookBook.h"

void Ingredient::print(){
	cout<< name << ": " << quantity << " " << unit << endl;
}

void Ingredient::deleteIngredient(){
	name="";
	quantity=0;
	unit="";
}

