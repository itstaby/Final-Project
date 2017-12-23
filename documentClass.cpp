#include <iostream>
#include <fstream>
#include <conio.h>
#include "stem.h"
#include "documentClass.h"

using namespace std;

void DocumentClass::operator =(char*p)

{

	path = new char [strlen(p)];
	strcpy(path,p);		

}

void DocumentClass::parseDocument()
{
	doc_num++;
	cout<<"\n---- PARSING DOCUMENT "<<doc_num<<" -----\n";
	ifstream fin;
	fin.open(path);
	if(fin.fail())
	{
		cout<<"\nFailed to open file.\n";
		getch();
	}
	else 
	{
		cout<<"\nFile has been successfully opened.\n";
	

		char data[100];
		
		cout<<"\nReading File..\n";
		int n=0;

		while(!fin.eof())
		{
			fin.getline(data,100,' ');
			
			strtok(data,"!,.-_+=[]{}':;*@#$%^&*()~`");
			
			if(strlen(data)!=0)
			{
				for(int i=0; data[i]!='\0'; i++)
					if(isupper(data[i]))
					{
						data[i]=(char)tolower(data[i]);
					}
				if ( (strcmp(data,"the")) != 0 && (strcmp(data,"a")) != 0 && (strcmp(data,"of")) != 0 && (strcmp(data,"on")) != 0 && (strcmp(data,"and")) != 0 && (strcmp(data,"are")) != 0  && (strcmp(data,"is")) != 0  && (strcmp(data,"but")) != 0  && (strcmp(data,"or")) != 0  && (strcmp(data,"for")) != 0  && (strcmp(data,"a")) != 0  && (strcmp(data,"an")) != 0  && (strcmp(data,"by")) != 0  && (strcmp(data,"in")) != 0 && (strcmp(data,"it")) != 0 && (strcmp(data,"to")) != 0 && (strcmp(data,"so")) != 0 && (strcmp(data,"if")) != 0 && (strcmp(data,"as")) != 0 && (strcmp(data,"has")) != 0 && (strcmp(data,"was")) != 0 && (strcmp(data,"have")) != 0 && (strcmp(data,"had")) != 0 && (strcmp(data,"were")) != 0 && (strcmp(data,"too")) != 0 && (strcmp(data,"yet")) != 0 && (strcmp(data,"do")) != 0 && (strcmp(data,"this") != 0))
				{	
					data[stem(data,0,strlen(data)-1)+1] = 0;
					if(list.checkRepeat(data))
					{
						list.appendwordNode(data);
					}
				}
			}
			

		}

	}

	fin.close();

	cout<<"\nParsing Complete.\n";
	

}

int DocumentClass::documentLength()
{
	ifstream fin(path);
	if(fin.fail())
	{
		cout<<"\nFailed to open file.";
		return NULL;
	}
	else
	{
		int count=0;
		char data[100];
		while(!fin.eof())
		{
			
			fin.getline(data,100,' ');
			if(strlen(data)!=0)
				count+=(strlen(data)+1);
		}
		count--;

		return count;
	}

	
}

char* DocumentClass::operator [](int wordNumber)
{
	
	if(wordNumber<0)
	{
		cout<<"Incorrect Value Entered. Negative Value not acceptable.\n";
	}
	else if(wordNumber>list.total)
	{
		cout<<"\nThe number you have entered exceeds the number of terms is in the list.\n";
		
	}
	else 
	{

		wordNode* temp=list.first;
		int n=1;
		while(temp!=NULL)
		{
			
			if(n-1==wordNumber)
				return temp->word;
			temp=temp->next;
			n++;	
		}
	}
	
	return "";
}

int DocumentClass::getTermFrequency(int wordNumber)
{
	wordNode* temp=list.first;
	if(wordNumber>list.total)
	{
		cout<<"\nThe number you have entered exceeds the number of terms is in the list.\n";
	}

	else
	{
			
		
		
		int n=1;

		while(temp!=NULL)
		{
			if(n-1==wordNumber)
			{
				cout<<"\nThe frequency of this term is: "<<temp->rep<<endl;
				return temp->rep;
			}
			else
			{
				temp=temp->next;
				n++;
			}
		}
	}
	

	return 0;
}

void DocumentClass::removeBottomTerms(int n)
{
	wordNode* temp;
	if(list.first==NULL)
	{
		cout<<"\nList Empty";
	}
	else 
	{

		while(list.first->rep<n)
		{
			temp=list.first;
			list.first=list.first->next;
			delete temp;
							
		}
		
		wordNode* hold;
		wordNode *temp=list.first;
		
		while(temp->next!=NULL)
		{
			
			
			if(temp->next->rep<n)
			{	

				hold=temp->next->next;
				delete temp->next;
				temp->next=hold;
				

			}
			else
			{
				temp=temp->next;
				if(temp==NULL)
					break;
			}
		
		}
		
	}
}

void DocumentClass::removeTopTerms(int n)
{

	wordNode* temp;
	if(list.first==NULL)
	{
		cout<<"\nList Empty";
	}
	else 
	{
		
		while(list.first->rep>n)
		{
			cout<<"\nChecking first term.";
			cout<<" The term "<<list.first->word<<" has been deleted\n";
			temp=list.first;
			list.first=list.first->next;
			delete temp;
							
		}
	
		wordNode *temp=list.first;
		wordNode* hold;
		
		while(temp->next!=NULL)
		{
			
			
			if(temp->next->rep>n)
			{	
				

				hold=temp->next->next;
				delete temp->next;
				temp->next=hold;
				

			}
			else
			{
				temp=temp->next;
				if(temp==NULL)
					break;
			}

			


		}

		
	}
}
int DocumentClass::doc_num=0;