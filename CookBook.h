#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

struct Ingredient;
struct Recipe;
struct DataBase;
struct Menu;

struct Ingredient{
	string name; 
	int quantity;
	string unit;
	
	Ingredient(){
		name = " ";
		quantity = 0;
		unit = "";
	}
	
	Ingredient(string _name, int _quantity, string _unit){
		name = _name;
		quantity = _quantity;
		unit = _unit;
		cout << "ingredient constructor working"<<endl;
	}
	
	void deleteIngredient();
	void print();
};



struct Recipe{
	string name;
	int portion;
	Ingredient ingredients[30];
	
	int size;
	int counter;
	
	Recipe(){
		counter=0; //count how many ingreds does this recipe have so far
		size=30;
		
		name= "";
		portion = 0;
		ingredients[size];	
	}
	
	Recipe(string _name, int _portion){ 	
		size=30;
		name = _name;
		portion = _portion;
		ingredients[size];
}

	int addIngredient(string , int , string);
	int findIngredient(string);
	void printAllIngredients();
	void deleteAllIngredients();
	void modifyIngredientQuantity(int, int);
};

struct DataBase{
	int size;
	Recipe recipes[100];
	
	int counter;
	
	DataBase(){
		int size=100;
		recipes[size];
		int counter=0; //count how many recipes are there in here
	}
	
	int addRecipe(string, int);
	int findRecipe(string);
	Recipe deleteRecipe(string);
	void printAllRecipes(); 
	void modifyRecipeName(int, string);
	void moveLeft(int);
	void measurePortions(string, int);
	void printOneRecipe(string);
};




struct Menu{
	DataBase database;
	int option;
		
	Menu(){
		welcomeMessage();
		menuOptions();
		string option, option1;
		cout << "Option: ";
		cin >> option;
		
		while(true){
			if(option=="1"){
				optionOne();
			}
			else if(option=="2"){
				optionTwo();
			}
			else if(option=="3"){
				optionThree();
			}
			else if(option=="4"){
				optionFour();
			}
			else if(option=="5"){
				optionFive();
			}
			else if(option=="6"){
				optionSix();
			}
			else if(option=="7"){
				optionSeven();
			}
			else if(option=="8"){
				optionEight();
			}
			else if(option=="9"){
				break;
			}
			option.clear();
			cout << endl << "Do something else? Answer YES or NO: ";
			cin >> option1;
			cin.ignore();
			
			if (option1=="no" || option1=="NO" || option1=="No"){
				break;	
			}
			else if (option1=="yes" || option1=="Yes" || option1=="YES" || option1=="yES" || option1 == "yeS" || option1=="YEs"){
				menuOptions();
				cin >> option;
			}
			else{
				cout << "Please enter valid option.";
			}
			//cin.clear();
		}	
	}
	void welcomeMessage();
	void menuOptions();
	int optionOne();
	int optionTwo();
	int optionThree();
	int optionFour();
	int optionFive();
	int optionSix();
	int optionSeven();
	int optionEight();
};

		
