#ifndef Paragraph_H
#define Paragraph_H


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

class Paragraph;

#include "Sentence.h"
#include "Story.h"




using namespace std;

class Paragraph
{
	public:
		Sentence *sentence;
		Paragraph *nextPara;


		Paragraph();	//default constructor

		Paragraph(const Paragraph &p);

		~Paragraph();	//destructor

		Paragraph(string s);

		Paragraph(const Paragraph *s);

		void show()const;	//neatly displays all of the values

		Paragraph& operator=(Paragraph &other);

		Story& operator+(const Story &other);

		Paragraph& operator+(const Paragraph &other);
	
		Paragraph& operator+(Sentence &other);

		Paragraph operator++(int);

		Paragraph operator--(int);
	
		Paragraph& operator+(int val);

		Paragraph& operator++();		//prefix

		Paragraph& operator--();		//prefix

		friend ostream& operator<<(ostream& os, Paragraph& other);

		Sentence& first();

		Paragraph& rest();


};

#endif
