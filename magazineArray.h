#pragma once
#include "magazine.h"

class Magazinearray
{
private:
	int capacity;
	int size;
	Magazine* mag;

public:
	Magazinearray(int capacity);
	~Magazinearray();

	void addMagazine(Magazine mag);
	bool searchMagazineByISBN(int isbn);
	void deleteMagazineByISBN(int isbn);
	void updateMagazineByISBN(int isbn, Magazine mag);

	void printAllMagazines();
	void printOrderedMagazines();
	void printreturnMagazines();


	void searchmagazine(int isbn);

	Magazine getmagazineobj(int isbn);

};