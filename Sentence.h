#ifndef Sentence_H
#define Sentence_H


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

class Sentence; 

#include "Word.h"
#include "Paragraph.h"

using namespace std;



class Sentence
{
	public:
		Word *word;
		Sentence *nextSen;

	
		Sentence();	//default constructor

		Sentence(const Sentence &s);

		Sentence(const Sentence *s);

		~Sentence();	//destructor

		Sentence(string s);

		void show()const;	//display values

		Sentence& operator=(Sentence &other);

		Paragraph& operator+(const Paragraph &other);

		Paragraph& operator+(Sentence &other);
	
		Sentence& operator+(Word &other);

		Sentence operator++(int);

		Sentence operator--(int);
	
		Sentence& operator+(int val);

		Sentence& operator++();		//prefix

		Sentence& operator--();		//prefix

		friend ostream& operator<<(ostream& os, Sentence& other);

		Word& first();

		Sentence& rest();




};

#endif
