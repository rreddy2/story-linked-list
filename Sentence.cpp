#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "Sentence.h"


using namespace std;


	//DEFAULT CONSTRUCTOR
	Sentence::Sentence()
	{
		cout << "Entering function Sentence::Sentence()." << endl;

		this->word = NULL;
		this->nextSen = NULL;
	
		cout << "Leaving function Sentence::Sentence()." << endl;
	}
	
	//COPY CONSTRUCTOR
	Sentence::Sentence(const Sentence &s)
	{
		cout << "Entering function Sentence::Sentence(const Sentence &s)." << endl;

	
		if(s.word == NULL)
		{
			word = NULL;
			return;
		}
		else
		{

			Word *temp2 = s.word;
			word = new Word(*temp2);
			temp2 = temp2->next;
			Word * temp  = word;
			while(temp2 != NULL)
			{
				temp->next = new Word(*temp2);
				temp = temp->next;				
				temp2 = temp2->next;
			}
			temp->next = NULL;
		}

		cout << "Leaving function Sentence::Sentence(const Sentence &s)." << endl;
	}

	//POINTER COPY CONSTRUCTOR
	Sentence::Sentence(const Sentence *s)
	{
		cout << "Entering function Sentence::Sentence(const Sentence *s)." << endl;
		cout << "Function passes one parameter 'Sentence &s' : ";
		s->show();

		
		if(s->word == NULL)
		{
			word = NULL;
			return;
		}
		else
		{

			Word *temp2 = s->word;
			word = new Word(*temp2);
			temp2 = temp2->next;
			Word * temp  = word;
			while(temp2 != NULL)
			{
				temp->next = new Word(*temp2);
				temp = temp->next;				
				temp2 = temp2->next;
			}
			temp->next = NULL;
		}



		cout << "Leaving function Sentence::Sentence(const Sentence &s)." << endl;
	}


/*
	Sentence::Sentence(string s)
	{
		cout << "Entering function Sentence::Sentence(string s)." << endl;
		
		

		cout << "Leaving functino Sentence::Sentence(string s)." << endl;

	}


*/
	void Sentence::show()const
	{
		cout << "Entering function Sentence::show()." << endl;
		
		
		
		cout << "Leaving function Sentence::show()." << endl;
	}

	//DESTRUCTOR
	Sentence::~Sentence()
	{
		cout << "Entering function Sentence::~Sentence()." << endl;

		Word *temp = word;
		Word *temp2 = word;
	
		while(temp != NULL)
		{
			temp2 = word->next;
			delete temp;
			temp = temp2;
		}	

		cout << "Leaving function Sentence::~Sentence()." << endl;
	}

	//ASSIGNMENT OPERATOR
	Sentence& Sentence::operator=(Sentence &other)
	{
		cout << "Entering operator=(other)" << endl;
		

		//Have to empty current space

		Word *temp = word;
		Word *temp2 = word;
	
		while(temp != NULL || temp2 != NULL)
		{
			temp2 = word->next;
			delete temp;
			temp = temp2;
			
		}
		cout << "DONE" << endl;
		//Fill the place up with new Sentence

		Sentence newSentence(*this);
		temp = other.word;

		while(temp != NULL)
		{

			word = temp;
			word = word->next;
			temp = temp->next;

		}
		
		newSentence.nextSen = NULL;
		

		cout << "Leaving operator=(other)" << endl;
		return newSentence;
	
	}  



	//CREATE A PARAGRAPH WITH SENTENCE AT BEGINNING
	Paragraph& Sentence::operator+(const Paragraph &other)
	{
		cout << "Entering function Sentence::operator+(const Paragraph &other)." << endl;
		cout << "Function passes a parameter 'Paragraph &other': ";
		other.show();
		
		Sentence s = new Sentence(*this);	
		
		
		Paragraph p(other);
		s.nextSen = p.sentence;
		p.sentence = &s;
		
/*
		Sentence *temp2 = p.sentence->nextSen;

		while(temp != NULL)
		{
			temp2 = temp;
			temp = temp->nextSen;
			temp2 = temp2->nextSen;
		}
*/		
		p.nextPara = NULL;
		

		cout << "Leaving function Sentence::operator+(const Paragraph &other)." << endl;
		return p;
	}


	//CREATE A PARAGRAPH WITH TWO SENTENCES
	Paragraph& Sentence::operator+(Sentence &other)
	{
		cout << "Entering function Sentence::operator+(const Sentence &other)." << endl;
		cout << "Function passes a parameter 'Sentence &other': ";
		other.show();
		
		Paragraph *p;
		
		p->sentence = this;
		p->sentence->nextSen = &other;


		cout << "Leaving function Sentence::operator+(const Sentence &other)." << endl;
		return *p;
	}

	//ADD A WORD TO THE END OF A SENTENCE
	Sentence& Sentence::operator+(Word &other)
	{
		cout << "Entering function Sentence::operator+(const Word &other)." << endl;
		

		Sentence s(*this);
	
		Word *w = new Word(other);
                Word *temp(s.word);
                
                while(temp->next != NULL)	//PROBLEM LINE
		{
	          temp = temp->next;
		}
		temp->next = w;

                 //temp->next = &other;
		temp = temp->next;
		temp->next = NULL;



		cout << "Leaving function Sentence::operator+(const Word &other)." << endl;
		return s;
	}
	
	//MAKE THE WHOLE SENTENCE CAPITALIZED
	Sentence Sentence::operator++(int val)
	{
		cout << "Entering function Sentence::operator++()." << endl;
		Sentence s(*this);

		Word *temp = word;
		while(temp != NULL)
		{
			(*temp)++;
			temp = temp->next;
		}
		
		cout << "Leaving function Sentence::operator++()." << endl;
		return s;
	}

	//MAKE THE WHOLE SENTENCE LOWERCASE
	Sentence Sentence::operator--(int val)
	{
		cout << "Entering function Sentence::operator--()." << endl;
		
		Sentence s(this);
		Word *temp = this->word;
		
		while(temp != NULL)
		{
			(*temp)--;
			temp = temp->next;
		}

		cout << "Leaving function Sentence::operator--()." << endl;
		return s;
	}
	
	//CAPITALIZE THE FIRST LETTER OF SENTENCE
	Sentence& Sentence::operator+(int val)
	{
		cout << "Entering function Sentence::operator+1()." << endl;
		if(val == 1)
		{
			word->s.at(0) = toupper(word->s.at(0));
			return *this;
		}

		cout << "Leaving function Sentence::operator+1()." << endl;
		return *this;
	}


	//ENGLISH TO PIG LATIN
	Sentence& Sentence::operator++()
	{
		cout << "Entering function Sentence::++operator()." << endl;

		Word *temp = new Word(word);
		while(temp != NULL)
		{
			++(*temp);
			temp = temp->next;
		}

		cout << "Leaving function Sentence::++operator()." << endl;
		return *this;
	}

	//PIG LATIN TO ENGLISH
	Sentence& Sentence::operator--()
	{
		cout << "Entering function Sentence::--operator()." << endl;
		Word *temp = new Word(word);
		while(temp != NULL)
		{
			--(*temp);
			temp = temp->next;
		}

		cout << "Leaving function Sentence::--operator()." << endl;
		return *this;
	}

	//OUTPUT
	ostream& operator<<(ostream& os, Sentence& other)	
	{
		cout << "Entering function operator<<(ostream& os, Sentence& other)." <<endl;
		cout << "Function passes two parameters 'ostream &os, Sentence &other': ";
		other.show();

		Word *temp = other.word;
		while(temp != NULL)
		{
			os << (*temp).s << " ";
			temp = temp->next;
		}
		os << "\n\n";


		cout << "Leaving function operator<<(ostream& os, Sentence& other)." <<endl;
		return os;
		
	}

	//RETURN THE FIRST WORD
	Word& Sentence::first()
	{
		cout << "Entering function Sentence::first()." << endl;

		Word w(this->word);

		cout << "Leaving function Sentence::first()." << endl;
		return w;
	}

	//RETURN THE REST OF THE SENTENCE
	Sentence& Sentence::rest()
	{
		cout << "Entering function Sentence::rest()." << endl;

		Sentence s;
		
		Word *temp = this->word;
		temp = temp->next;
		while(temp != NULL)
		{
			s.word = temp;
			s.word = s.word->next;
			temp = temp->next;
		}
		
		s.word->next = NULL;

		cout << "Leaving function Sentence::rest()." << endl;
		
		return s;
	}








