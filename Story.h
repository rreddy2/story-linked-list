#ifndef Story_h
#define Story_h

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

class Story;

#include "Paragraph.h"

using namespace std;

//class Paragraph;

class Story
{
	public:
		Paragraph *paragraph;

		Story();	//default constructor

		Story(const Story &s);

		Story(string s);

		~Story();	//destructor

		void show()const;

		Story& operator=(Story &other);

		Story(const Story *s);

		Story& operator+(const Story &other);

		Story& operator+(const Paragraph &other);

		Story operator++(int);

		Story operator--(int);
	
		Story& operator+(int val);

		Story& operator++();		//prefix

		Story& operator--();		//prefix

		friend ostream& operator<<(ostream& os, Story& other);

		Paragraph& first();

		Story& rest();

};

#endif
