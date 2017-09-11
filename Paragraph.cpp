#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <cstring>
#include "Paragraph.h"


using namespace std;

	
	//DEFAULT CONSTRUCTOR
	Paragraph::Paragraph()
	{
		cout << "Entering function Paragraph::Paragraph()." << endl;

		sentence = NULL;
		nextPara = NULL;

		cout << "Leaving function Paragraph::Paragraph()." << endl;
	}

	//COPY CONSTRUCTOR
	Paragraph::Paragraph(const Paragraph &p)
	{
		cout << "Entering function Paragraph::Paragraph(Paragraph &p)." << endl;
		
		if(p.sentence == NULL)
		{
			sentence = NULL;
			return;
		}
		else
		{

			Sentence *temp2 = p.sentence;
			sentence = new Sentence(*temp2);
			temp2 = temp2->nextSen;
			Sentence * temp  = sentence;
			while(temp2 != NULL)
			{
				temp->nextSen = new Sentence(*temp2);
				temp = temp->nextSen;				
				temp2 = temp2->nextSen;
			}
			temp->nextSen = NULL;
		}

	


		cout << "Leaving function Paragraph::Paragraph(Paragraph &p)." << endl;
	}
	
	//POINTER COPY CONSTRUCTOR
	Paragraph::Paragraph(const Paragraph *p)
	{
		cout << "Entering function Sentence::Sentence(const Sentence &s)." << endl;
		
		if(p->sentence == NULL)
		{
			sentence = NULL;
			return;
		}
		else
		{

			Sentence *temp2 = p->sentence;
			sentence = new Sentence(*temp2);
			temp2 = temp2->nextSen;
			Sentence * temp  = sentence;
			while(temp2 != NULL)
			{
				temp->nextSen = new Sentence(*temp2);
				temp = temp->nextSen;				
				temp2 = temp2->nextSen;
			}
			temp->nextSen = NULL;
		}

		cout << "Leaving function Sentence::Sentence(const Sentence &s)." << endl;
	}





/*
	Paragraph::Paragraph(string s)
	{
		cout << "Entering function Paragraph::Paragraph(string s)." << endl;
		

		cout << "Leaving functino Paragraph::Paragraph(string s)." << endl;

	}

*/

	void Paragraph::show()const
	{
		cout << "Entering function Paragraph::show()." << endl;


		cout << "Leaving function Paragraph::show()." << endl;
	}


	//DESTRUCTOR
	Paragraph::~Paragraph()
	{
		cout << "Entering function Paragraph::~Paragraph()." << endl;

		Sentence *temp = sentence;
		Sentence *temp2 = sentence;
	
		while(temp != NULL)
		{
			temp2 = sentence->nextSen;
			delete temp;
			temp = temp2;
		}	

		cout << "Leaving function Paragraph::~Paragraph()." << endl;
	}


	//ASSIGNMENT OPERATORS
	Paragraph& Paragraph::operator=(Paragraph &other)
	{
		cout << "Entering function Paragraph::operator=(const Paragraph &other)" << endl;
		cout << "Function passes one parameter 'Paragraph &other': ";
		other.show();

		//have to clear out memory space 
		Sentence *temp = sentence;
		Sentence *temp2 = sentence;
	
		while(temp != NULL)
		{
			temp2 = sentence->nextSen;
			delete temp;
			temp = temp2;
		}


		//fill up with new Paragraph
		Paragraph *newParagraph = new Paragraph();
		temp = other.sentence;

		if(temp != NULL)
		{

			newParagraph->sentence = temp;
			other.sentence = other.sentence->nextSen;
			temp = temp->nextSen;

		}
		
		newParagraph->nextPara = NULL;

		return *newParagraph;
	}  

	//ADD A PARAGRAPH TO BEGINNING
	Story& Paragraph::operator+(const Story &other)
	{
		cout << "Entering function Paragraph::operator+(const Story &other)." << endl;
		cout << "Function passes one parameter 'Story &other': ";
		other.show();

		Story s;
		s.paragraph = this;
		
		Paragraph *temp = other.paragraph;
		Paragraph *temp2 = s.paragraph;
		
		temp2 = temp2->nextPara;
		
		while(temp != NULL)
		{
			temp2 = temp;
			temp = temp->nextPara;
			temp2 = temp2->nextPara;
		}
	

		cout << "Leaving function Paragraph::operator+(const Story &other)." << endl;
		return s;
	}

	//NEW PARAGRAPH WITH SENTENCES FROM FIRST FOLLOWED BY SENTENCES IN SECOND
	Paragraph& Paragraph::operator+(const Paragraph &other)
	{
		cout << "Entering function Paragraph::operator+(const Paragraph &other)." << endl;
		cout << "Function passes one parameter 'Paragraph &other': ";	
		other.show();

		Paragraph newParagraph;
		
		Sentence *temp = this->sentence;
		Sentence *temp2 = newParagraph.sentence;

		while(temp != NULL)
		{
			temp2 = temp;
			temp2 = temp2->nextSen;
			temp = temp->nextSen;
		}
		
		temp = other.sentence;

		while(temp != NULL)
		{
			temp2 = temp;
			temp2 = temp2->nextSen;
			temp = temp->nextSen;
		}
	

		cout << "Leaving function Paragraph::operator+(const Paragraph &other)." << endl;
		return newParagraph;
	}

	//EVALUATES A PARAGRAPH WITH AN ADDITIONAL SENTENCE AT THE END
	Paragraph& Paragraph::operator+(Sentence &other)
	{
		cout << "Entering function Paragraph::operator+(const Sentence &other)." << endl;
		cout << "Function passes one parameter 'Sentence &other': ";
		other.show();

		Paragraph newParagraph;
		
		Sentence *temp = this->sentence;
		Sentence *temp2 = newParagraph.sentence;

		while(temp != NULL)
		{
			temp2 = temp;
			temp2 = temp2->nextSen;
			temp = temp->nextSen;
		}
		
		temp = &other;
		
		cout << "Leaving function Paragraph::operator+(const Sentence &other)." << endl;
		return newParagraph;
	}

	//MAKES THE WHOLE SENTENCE ALL CAPS
	Paragraph Paragraph::operator++(int val)
	{
		cout << "Entering function Paragraph::operator++()." << endl;
		Paragraph p(this);

		Sentence *temp = this->sentence;
		while(temp != NULL)
		{
			(*temp)++;
			temp = temp->nextSen;
		}

		cout << "Leaving function Paragraph::operator++()." << endl;
		return p;
	}

	//MAKES THE WHOLE SENTENCE LOWERCASE
	Paragraph Paragraph::operator--(int val)
	{
		cout << "Entering function Paragraph::operator--()." << endl;

		Paragraph p(this);
		Sentence *temp = this->sentence;
		while(temp != NULL)
		{
			(*temp)--;
			temp = temp->nextSen;
		}


		cout << "Leaving function Paragraph::operator--()." << endl;
		return p;
	}

	//CAPITALIZE THE FIRST LETTERS IN EVERY SENTENCE
	Paragraph& Paragraph::operator+(int val)
	{
		cout << "Entering function Paragraph::operator+1()." << endl;
		if(val == 1)
		{
			Sentence *temp = this->sentence;
			while(temp != NULL)
			{	
				temp+1;
				temp = temp->nextSen;
			}

			return *this;
		}

		cout << "Leaving function Paragraph::operator+1()." << endl;
		return *this;
	}

	//CONVERTS FROM ENGLISH -> PIG LATIN
	Paragraph& Paragraph::operator++()
	{
		cout << "Entering function Paragraph::++operator()." << endl;

		Sentence *temp = this->sentence;
		while(temp != NULL)
		{
			++(*temp);
			temp = temp->nextSen;
		}

		cout << "Leaving function Paragraph::++operator()." << endl;
		return *this;
	}

	//CONVERT FROM PIG LATIN -> ENGLISH
	Paragraph& Paragraph::operator--()
	{
		cout << "Entering function Paragraph::--operator()." << endl;

		Sentence *temp = this->sentence;
		while(temp != NULL)
		{
			--(*temp);
			temp = temp->nextSen;
		}


		cout << "Leaving function Paragraph::--operator()." << endl;
		return *this;
	}

	ostream& operator<<(ostream& os, Paragraph& other)	
	{
		cout << "Entering function operator<<(ostream& os, Story& other)." <<endl;
		cout << "Function passes two parameters 'ostream &os, Story &other': ";
		other.show();

		Sentence *temp = other.sentence;
		while(temp != NULL)
		{
			os << temp->word << " ";
			temp = temp->nextSen;
		}


		cout << "Leaving function operator<<(ostream& os, Story& other)." <<endl;
		return os;
		
	}

	//FIRST SENTENCE
	Sentence& Paragraph::first()
	{
		cout << "Entering function Paragraph::first()." << endl;

		Sentence s(this->sentence);
		cout << "Leaving function Paragraph::first()." << endl;
		return s;
	}

	//WHOLE PARAGRAPH MINUS FIRST SENTENCE
	Paragraph& Paragraph::rest()
	{
		cout << "Entering function Paragraph::rest()." << endl;
		Paragraph p;
		
		Sentence *temp = this->sentence;
		temp = temp->nextSen;
		while(temp != NULL)
		{
			p.sentence = temp;
			p.sentence = p.sentence->nextSen;
			temp = temp->nextSen;
		}
		
		p.sentence->nextSen = NULL;



		cout << "Leaving function Paragraph::rest()." << endl;
		return p;
	}


