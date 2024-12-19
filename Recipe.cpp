#include "CookBook.h"

int Recipe::addIngredient(string _name, int _quantity, string _unit){
	if (counter<size && findIngredient(_name)==-1){
		ingredients[counter].name= _name;
		ingredients[counter].quantity= _quantity;
		ingredients[counter].unit= _unit;
		return counter++;
	}
	return -1;
}

int Recipe::findIngredient(string _name){
	for (int i=0; i<size; i++){
		if (ingredients[i].name==_name){
			return i;}}
	return -1;
}

void Recipe::printAllIngredients(){
	cout << name << " for " << portion << " servings. " << endl;
	for (int i=0; i<size; i++){
		if (ingredients[i].name!=" "){
			cout<<i+1<<"- ";
			ingredients[i].print();}
		}}

void Recipe::deleteAllIngredients(){
	for (int i=0; i<size; i++){
		ingredients[i].deleteIngredient();
		}}


void Recipe::modifyIngredientQuantity(int space, int _quantity){
	ingredients[space].quantity=_quantity;
}


