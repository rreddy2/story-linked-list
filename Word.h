#ifndef Word_H
#define Word_H



#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

class Word;
#include "Sentence.h"


using namespace std;

class Word
{
	public:
		string s;
		Word *next;

		bool isPigLatin;
		string oldEnglish;	


		Word();		//default constructor

		Word(const Word &w);

		Word(const Word *s1);
		
		Word(string s);

		~Word();	//destructor

		void show()const;

		Word& operator=(const Word &other);

		Sentence& operator+(const Sentence &other);

		Sentence operator+(const Word &other);

		Word operator++(int);

		Word operator--(int);
	
		Word& operator+(int val);

		Word& operator++();

		Word& operator--();

		friend ostream& operator<<(ostream& os, Word& other);

};

#endif
