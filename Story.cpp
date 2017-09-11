#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "Story.h"


using namespace std;


	//DEFAULT CONSTRUCTOR	
	Story::Story()
	{
		cout << "Entering function Story::Story()." << endl;
		
		paragraph = NULL;

		cout << "Leaving function Story::Story()." << endl;
	}
	
	//COPY CONSTRUCTOR
	Story::Story(const Story &s)
	{
		cout << "Entering function Story::Story(const Story &s)." << endl;
		
		if(s.paragraph == NULL)
		{
			paragraph = NULL;
			return;
		}
		else
		{

			Paragraph *temp2 = s.paragraph;
			paragraph = new Paragraph(*temp2);
			temp2 = temp2->nextPara;
			Paragraph * temp  = paragraph;
			while(temp2 != NULL)
			{
				temp->nextPara = new Paragraph(*temp2);
				temp = temp->nextPara;				
				temp2 = temp2->nextPara;
			}
			temp->nextPara = NULL;
		}			

		cout << "Leaving function Story::Story(const Story &s)." << endl;
	}
/*
	Story::Story(string s)
	{
		cout << "Entering function Story::Story(string s)." << endl;
		

		cout << "Leaving functino Story::Story(string s)." << endl;

	}
*/

	void Story::show()const
	{
		cout << "Entering function Story::show()." << endl;


		cout << "Leaving function Story::show()." << endl;
	}
	

	//DESTRUCTOR
	Story::~Story()
	{
		cout << "Entering function Story::~Story()." << endl;
		
		Paragraph *temp = paragraph;
		Paragraph *temp2 = paragraph;
	
		while(temp != NULL)
		{		
			temp2 = paragraph->nextPara;
			delete temp;
			temp = temp2;
		}


		cout << "Leaving function Story::~Story()." << endl;
	}

	//ASSIGNMENT OPERATOR
	Story& Story::operator=(Story &other)
	{
		cout << "Entering function Story::operator=(const Story &other)" << endl;
		cout << "Function passes one parameter 'Story &other': ";
		other.show();

		//have to clear out memory space 
		Paragraph *temp = paragraph;
		Paragraph *temp2 = paragraph;
	
		while(temp != NULL)
		{
			temp2 = paragraph->nextPara;
			delete temp;
			temp = temp2;
		}


		//fill up with new Paragraph
		Story *newStory = new Story();
		temp = other.paragraph;

		if(temp != NULL)
		{

			newStory->paragraph = temp;
			other.paragraph = other.paragraph->nextPara;
			temp = temp->nextPara;

		}
	
		return *newStory;
	}  
	
	//POINTER COPY CONSTRUCTOR
	Story::Story(const Story *s)
	{
		cout << "Entering function Sentence::Sentence(const Sentence &s)." << endl;
		cout << "Function passes one parameter 'Sentence &s' : ";
		s->show();

		
		Paragraph *temp = paragraph;

		while(temp != NULL)
		{
			temp = s->paragraph;
			temp = temp->nextPara;
		}

		cout << "Leaving function Sentence::Sentence(const Sentence &s)." << endl;
	}

	//ADD FIRST STORY'S PARAGRAPHS FOLLOWED BY SECOND STORY'S PARAGRAPHS 
	Story& Story::operator+(const Story &other)
	{
		cout << "Entering function Story::operator+(const Story &other)." << endl;
		cout << "Function passes one parameter 'Story &other': ";
		other.show();
		
		Story newStory;		
		Paragraph *temp = this->paragraph;
		Paragraph *temp2 = newStory.paragraph;

		while(temp != NULL)
		{
			temp2 = temp;
			temp = temp->nextPara;
			temp2 = temp2->nextPara;
		}
		
		temp = other.paragraph;
		
		while(temp != NULL)
		{
			temp2 = temp;
			temp = temp->nextPara;
			temp2 = temp2->nextPara;
		}

		cout << "Leaving function Story::operator+(const Story &other)." << endl;
		return newStory;
	}


	Story& Story::operator+(const Paragraph &other)
	{
		cout << "Entering function Story::operator+(const Paragraph &other)." << endl;
		cout << "Function passes one parameter 'Paragraph &other': ";
		other.show();		
		
	
		cout << "Leaving function Story::operator+(const Paragraph &other)." << endl;
		return *this;
	}

	//MAKE STORY BEGINNING ALL CAPS
	Story Story::operator++(int val)
	{
		cout << "Entering function Story::operator++()." << endl;

		Story s(this);
		Paragraph *temp = this->paragraph;
		while(temp != NULL)
		{
			(*temp)++;
			temp = temp->nextPara;
		}

		
		cout << "Leaving function Story::operator++()." << endl;
		return s;
	}

	//LOWERCASE STORY
	Story Story::operator--(int val)
	{
		cout << "Entering function Story::operator--()." << endl;
		
		Story s(this);
		Paragraph *temp = this->paragraph;
		while(temp != NULL)
		{
			(*temp)--;
			temp = temp->nextPara;
		}


		
		cout << "Leaving function Story::operator--()." << endl;
		return s;
	}
	
	//CAPITALIZES THE WORDS IN EACH SENTENCE
	Story& Story::operator+(int val) 
	{
		cout << "Entering function Story::operator+1()." << endl;

		if(val == 1){
			Paragraph *temp = paragraph;
			while(temp != NULL)
			{	
				temp+1;
				temp = temp->nextPara;
			}
			return *this;
		}
		
		cout << "Leaving function Story::operator+1()." << endl;
		return *this;
	}

	//ENGLISH -> PIG LATIN
	Story& Story::operator++()	
	{
		cout << "Entering function Story::++operator()." << endl;

		Paragraph *temp = paragraph;
		while(temp != NULL)
		{
			++(*temp);
			temp = temp->nextPara;
		}
		
		cout << "Leaving function Story::++operator()." << endl;\
		return *this;
	}

	
	Story& Story::operator--()	
	{
		cout << "Entering function Story::--operator()." << endl;

		Paragraph *temp = paragraph;
		while(temp != NULL)
		{
			--(*temp);
			temp = temp->nextPara;
		}

		
		cout << "Leaving function Story::--operator()." << endl;
		return *this;
	}

	ostream& operator<<(ostream& os, Story& other)	
	{
		cout << "Entering function Story::operator<<(std::ostream& os, const Story& other)." <<endl;
		cout << "Function passes two parameters, 'ostream &os', 'Story &other': ";
		other.show();

		Paragraph *temp = other.paragraph;
		while(temp != NULL)
		{
			os << temp->sentence << " ";
			temp = temp->nextPara;
		}



		cout << "Leaving function Story::operator<<(std::ostream& os, const Story& other)." <<endl;
		return os;
		
	}

	Paragraph& Story::first()
	{
		cout << "Entering function Story::first()." << endl;
		

		Paragraph p(this->paragraph);
		
		cout << "Leaving function Story::first()." << endl;
		return p;
	}

	Story& Story::rest()
	{
		cout << "Entering function Story::rest()." << endl;

		Story s;

		Paragraph *temp = this->paragraph;
		temp = temp->nextPara;
		while(temp != NULL)
		{
			s.paragraph = temp;
			s.paragraph = s.paragraph->nextPara;
			temp = temp->nextPara;
		}
		


		cout << "Leaving function Story::rest()." << endl;
		return s;
	}





