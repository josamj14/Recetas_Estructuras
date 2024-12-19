#include "CookBook.h"

int DataBase::addRecipe(string _name, int _portion){
	if (counter<size && findRecipe(_name)==-1){
		recipes[counter].name = _name;
		recipes[counter].portion = _portion;
		return counter++;
	}
	return -1;
}

int DataBase::findRecipe(string _name){
	for (int i=0; i<100;i++){
		if (recipes[i].name==_name)
			return i;}
    return -1;
}

Recipe DataBase::deleteRecipe(string _name){
	int space = findRecipe(_name);
	Recipe deleted[1];
	if (space==-1)
		return deleted[0];
	deleted[0] = recipes[space];
	recipes[space].name="";
	recipes[space].portion=0;
	recipes[space].deleteAllIngredients();
	moveLeft(space);
	counter--;
	return deleted[0];
}

void DataBase::printOneRecipe(string name){
	int space =  findRecipe(name);
	if (space!=-1){
		cout << "Recipe: ";
		recipes[space].printAllIngredients();
	}
	else{
		cout << "Recipe was not found" <<endl;
	}
}

void DataBase::printAllRecipes(){
	cout << endl << "This is your whole cookbook"<<endl<<endl;
	for (int i=0; i<100 ; i++){
		cout << "Recipe " << i+1 << " = " ;
		if (recipes[i].portion==0){
			cout << "empty recipe" << endl;}
		else{
		recipes[i].printAllIngredients();
		cout<<endl;}
	}
}

void DataBase::moveLeft(int space){
	for (int i=space; i<99 ;i++){
		recipes[i]=recipes[i+1];
	}
}

void DataBase::modifyRecipeName(int space, string _name){
	recipes[space].name=_name;
}

void DataBase::measurePortions(string name, int servingsWanted){
	int space=findRecipe(name);
	if (space!=-1){
		double ingredientPerPortion;
		double portions = recipes[space].portion;
		cout << recipes[space].name << " for " << servingsWanted << " servings. " << endl;
		for (int i=0 ; i<30 ; i++){
			if (recipes[space].ingredients[i].quantity!=0){
				ingredientPerPortion=(recipes[space].ingredients[i].quantity / portions) * servingsWanted;
				cout << recipes[space].ingredients[i].name << ": " << ingredientPerPortion << " "<< recipes[space].ingredients[i].unit << endl;}
		}	
	}	
}


