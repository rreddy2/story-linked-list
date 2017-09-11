#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
#include <algorithm>
#include "Word.h"

using namespace std;

	Word::Word()
	{
		cout << "Entering function Word::Word()." << endl;
		s = "";
		next = NULL;
		isPigLatin = false;
		cout << "Leaving function Word::Word()." << endl;
	}

	Word::Word(const Word &s1)
	{
		cout << "Entering function Word::Word(const Word &s)." << endl;
	
		isPigLatin = false;

		s = s1.s;
		next = NULL;




		cout << "Leaving function Word::Word(const Word &s)." << endl;
	}

	Word::Word(const Word *s1)
	{
		cout << "Entering function Word::Word(const Word &s)." << endl;
	
		isPigLatin = false;

		s = s1->s;
		next = NULL;




		cout << "Leaving function Word::Word(const Word &s)." << endl;
	}
	
	Word::Word(string s1)
	{
		cout << "Entering function Word::Word(string s)." << endl;

		isPigLatin = false;

		s = s1;
		next = NULL;		

		cout << "Leaving functino Word::Word(string s)." << endl;

	}


	void Word::show()const
	{
		cout << "Entering function Word::show()." << endl;




		cout << "Leaving function Word::show()." << endl;
	}
	

	//DONT KNOW WHAT TO DO
	Word::~Word()
	{
		cout << "Entering function Word::~Word()." << endl;

		cout << "Leaving function Word::~Word()." << endl;
	}
	
	
	Word& Word::operator=(const Word &other)
	{
		cout << "Entering function Word::operator=(const Word &other)" << endl;
		
		s = other.s;
		next = other.next;

		isPigLatin = other.isPigLatin;

		return *this;
	}  


	Sentence& Word::operator+(const Sentence &other)
	{
		cout << "Entering function Word::operator+(const Sentence &other)." << endl;
			
		
		Sentence sent(other);		
		Word *g = new Word(*this);
		g->next = sent.word;
		sent.word = g;
		sent.nextSen = NULL;


		cout << "Leaving function Word::operator+(const Sentence &other)." << endl;
		return sent;
	}

	Sentence Word::operator+(const Word &other)	
	{
		cout << "Entering function Word::operator+(const Word &other)." << endl;		
		
		
		Sentence s;	
		
		Word *w2 = new Word(*this);
		Word *w3 = new Word(other);
		s.word = w2;
		
		w2->next = w3;
		w3->next = NULL;
	

		cout << "Leaving function Word::operator+(const Word &other)." << endl;
		return s;
	}

	Word Word::operator++(int val)	
	{
		cout << "Entering function Word::operator++()." << endl;
		
		Word w(this);

		int i;
		for(i = 0; i < s.length(); i++)
		{
			s.at(i) = toupper(s.at(i));
		}

		cout << "Leaving function Word::operator++()." << endl;
		return w;
	}

	Word Word::operator--(int val)	
	{
		cout << "Entering function Word::operator--()." << endl;

		Word w(this);

		int i;
		for(i = 0; i < s.length(); i++)
		{
			s.at(i) = tolower(s.at(i));
		}

		cout << "Leaving function Word::operator--()." << endl;	
		return w;
	}

	Word& Word::operator+(int val)	
	{
		cout << "Entering function Word::operator+1()." << endl;
		if(val == 1)
		{
			this->s.at(0) = toupper(this->s.at(0));
			return *this;
		}

		cout << "Leaving function Word::operator+1()." << endl;
		return *this;
	}

	//ENGLISH->PIG LATIN
	Word& Word::operator++()	
	{
		cout << "Entering function Word::++operator()." << endl;
		oldEnglish = s;
		char arr[1024];
		strcpy(arr,s.c_str());
		if(arr[0] == 'a' || arr[0] == 'A' || arr[0] == 'e' || arr[0] == 'E'|| arr[0] == 'i' || arr[0] == 'I' || arr[0] == 'o' || arr[0] == 'O' || arr[0] == 'u'|| arr[0] == 'U')
		{
			s.insert(strlen(s.c_str()), "way");
	
		}else if(arr[0] == 'b' || arr[0] == 'c' || arr[0] == 'd' || arr[0] == 'f' || arr[0] == 'g' || arr[0] == 'h' || arr[0] == 'j' || arr[0] == 'k' || arr[0] == 'l' || arr[0] == 'm' || arr[0] == 'n' || arr[0] == 'p' || arr[0] == 'q' || arr[0] == 'r' || arr[0] == 's' || arr[0] == 't' || arr[0] == 'v' || arr[0] == 'w' ||  arr[0] == 'x' || arr[0] == 'y' || arr[0] == 'z' || arr[0] == 'B' || arr[0] == 'C' || arr[0] == 'D' || arr[0] == 'F' || arr[0] == 'G' || arr[0] == 'H' || arr[0] == 'J' || arr[0] == 'K' || arr[0] == 'L' || arr[0] == 'M' || arr[0] == 'N' || arr[0] == 'P' || arr[0] == 'Q' || arr[0] == 'R' || arr[0] == 'S' || arr[0] == 'T' || arr[0] == 'V' || arr[0] == 'W' ||  arr[0] == 'X' || arr[0] == 'Y' || arr[0] == 'Z')
		{
			string first;
			first = s.at(0);
			s.erase(0,1);
			s.insert(strlen(s.c_str()), first);
			s.insert(strlen(s.c_str()), "way");
		}

		cout << "Leaving function Word::++operator()." << endl;
		isPigLatin = true;

		return *this;
	}

	//PIG LATIN -> ENGLISH
	Word& Word::operator--()	
	{
		cout << "Entering function Word::--operator()." << endl;

		s = oldEnglish;

		cout << "Leaving function Word::--operator()." << endl;
		return *this;
	}

	ostream& operator<<(ostream& os, Word& other)	
	{
		cout << "\nEntering function operator<<(ostream& os, const Word& other)." << endl;
	

		os << other.s << "\n";

		cout << "\nLeaving function operator<<(ostream& os, const Word& other)." <<endl;
		return os;
		
	}
