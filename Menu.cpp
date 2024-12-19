#include "CookBook.h"
#include <iostream>

void Menu::welcomeMessage(){
	cout << endl << "You have entered your new cookbook" << endl;
	cout << endl;
}

void Menu::menuOptions(){
	cout << "------------------------------------------------" << endl;
	cout << endl;
	cout << "You can ..." << endl;
	cout << "1. Add Recipe" << endl;
	cout << "2. Find Recipe" << endl;
	cout << "3. Delete Recipe" << endl;
	cout << "4. Print all recipes" << endl;
	cout << "5. Modify recipe's name" << endl;
	cout << "6. Modify ingredient's quantity" << endl;
	cout << "7. Add ingredient to a recipe" << endl;
	cout << "8. Measure portions" << endl;
	cout << "9. Exit" << endl << endl;
	cout << "What would you like to do?" << endl;
}

int Menu::optionOne(){
	cout << "You chose ADD A RECIPE "<< endl;
	string name;
	cout << "Please write the recipe's name: ";
	cin.ignore();
	getline(cin,name);
	int portion;
	cout << "Please write how many servings: ";
	cin >> portion;	
	while (1){
		if (cin.fail()){
			cin.clear();
			cout<<endl << "Please write a valid number for the servings:";
			cin.ignore();
			cin >> portion;
		}
		if (!cin.fail())
			break;
	}
	if (portion!=0){
		int recipeSpace=database.addRecipe(name, portion);
	if(recipeSpace==-1){
		cout << "Recipe could not be added to cookbook" << endl;
		return -1;
	}
	cout << "Recipe "<<name << " was succesfully added to cookbook. "<<endl;
	cout << "Would you like to add an ingredient?"<<endl;
	string answer;
	while (true){
		cin.ignore();
		cin.clear();
		cout << "YES or NO: ";
		cin >> answer;
		
		if (answer=="YES" or answer=="yes" or answer=="Yes"){
			
			cin.clear();
			cin.ignore();
			string name;
			int quantity;
			string unit;
			cout << "What's the ingredients name? : ";
			getline(cin,name);
			cout << "How much of that ingredient? Please use the format 00 unit divided with a space" << endl << "Quantity: ";
			cin >> quantity >> unit ; 
			if (quantity==0){
				cout << "Invalid quantity" << endl;}
			else if (database.recipes[recipeSpace].addIngredient(name,quantity,unit)!=-1)
				cout << "Ingredient was succesfully added" << endl;
			else{
				cout << "Ingredient could not be added" << endl;
				}
			cout << "Would you like to add another ingredient?: " << endl;
		}
		else if (answer=="No" or answer=="NO" or answer=="no"){
			break;}	
		}	
	}
	else {
		cout << "Recipe cannot be made for 0 servings . " << endl;
	}
	
		
}

int Menu::optionTwo(){
	cout << "You chose FIND A RECIPE "<< endl;
	string name;
	cout << "Please write the recipe's name: ";
	cin.ignore();
	getline(cin,name);
	database.printOneRecipe(name);
}

int Menu::optionThree(){
	
	cout << "You chose DELETE A RECIPE" << endl;
	string name;
	cout << "Please write the recipe's name: ";
	cin.ignore();
	getline(cin,name);
	Recipe deletedRecipe=database.deleteRecipe(name);
	if (deletedRecipe.portion!=0){
		deletedRecipe.printAllIngredients();
		cout << "was succesfully deleted. " << endl;
	}
	else{
		cout << "Recipe doesn't exist" << endl;
	}
		
}

int Menu::optionFour(){
	cout << "You chose PRINT ALL RECIPES" <<endl;
	database.printAllRecipes();
}

int Menu::optionFive(){
	
	cout << "You chose MODIFY RECIPE'S NAME" <<endl;
	string name;
	cout << "Please write the ACTUAL recipe's name: ";
	cin.ignore();
	getline(cin,name);
	int space = database.findRecipe(name);
	if (space!=-1){
		string newName;
		cin.clear();
		cout << "Please write the NEW recipe's name: ";
		getline(cin,newName);
		if (database.findRecipe(newName)==-1){
			database.modifyRecipeName(space,newName);
			cout << "Recipe's name was succesfully changed" << endl;
		}
		else {
			cout << "Another recipe already has that name" << endl;
		}
	}
	else{
		cout << "Recipe was not found in cookbook" << endl;
	}}

int Menu::optionSix(){
	
	cout << "You chose MODIFY INGREDIENT'S QUANTITY"<<endl;
	string name;
	cout << "Please write the recipe's name: ";
	cin.ignore();
	getline(cin,name);
	int space = database.findRecipe(name);
	if (space!=-1){
		string ingName;
		cout << "Please write the ingredient's name: ";
		getline(cin,ingName);
		int ingSpace = database.recipes[space].findIngredient(ingName);
		if (ingSpace!=-1){
			int newQuantity;
			cout << "New quantity: ";
			cin >> newQuantity ; 
			while (1){
			if (cin.fail()){
				cin.clear();
				cout << "Please write a valid number for the new quantity:";
				cin.ignore();
				cin >> newQuantity;
			}
			if (!cin.fail())
				break;
			}
			database.recipes[space].modifyIngredientQuantity(ingSpace,newQuantity);
			cout << "Ingredient's quantity was modified succesfully" << endl;
			
		}
		else{
			cout << "Ingredient was not found in this recipe" << endl;
		}
	}
	else{
		cout << "Recipe was not found in cookbook" << endl;
	}
}

int Menu::optionSeven(){
	cout << "You chose ADD INGREDIENT TO A RECIPE" << endl;
	string name;
	cout << "Please write the recipe's name: ";
	cin.ignore();
	getline(cin,name);
	int space = database.findRecipe(name);
	if (space!=-1){
		string name;
		int quantity;
		string unit;
		cout << "What's the ingredients name? : ";
		getline(cin,name);
		cout << "How much of that ingredient? Please use the format 00 unit divided with a space" << endl << "Quantity: ";
		cin >> quantity >> unit ; 
		if (quantity==0){
			cout << "Invalid quantity" << endl;}
		else if (database.recipes[space].addIngredient(name,quantity,unit)!=-1)
			cout << "Ingredient was succesfully added" << endl;
		else{
			cout << "Ingredient could not be added" << endl;
			}
	}
	else{
		cout << "Recipe was not found in cookbook" << endl;
	}
	return 1;
	}

int Menu::optionEight(){
	
	cout << "You chose MEASURE A RECIPE" << endl;
	string name;
	cout << "Please write the recipe's name: ";
	cin.ignore();
	getline(cin,name);
	if (database.findRecipe(name)==-1){
		cout << "Recipe was not found in cookbook." << endl;
		return 1;
	}
	int portion;
	cout << "Please write how many servings you wish to have: ";
	cin >> portion;
	while (1){
		if (cin.fail()){
			cin.clear();
			cout << "Please write a valid number for the servings:";
			cin.ignore();
			cin >> portion;
		}
		if (!cin.fail())
			break;
	}
	cout<<endl;
	if (portion!=0)
		database.measurePortions(name,portion);
	else{
		cout << "Invalid serving desired. " << endl;}
}
