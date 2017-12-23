#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include "queryClass.h"
#include "IndexClass.h"
#include "stem.h"

using namespace std;

void QueryClass::operator = (char* q)
{
	cout<<"The query you entered is: "<<q<<endl<<endl;
	char* r=new char [strlen(q)];
	strcpy(r,q);
	for(int i=0; r[i]!='\0'; i++)
		if(isupper(r[i]))
		{
			r[i]=(char)tolower(r[i]);
		}
	QueryNode* temp=first;

	if(first==NULL)
	{
		first=new QueryNode;
		temp=first;
		strtok(r," ");
		strcpy(first->word,r);
		strcpy(first->word1,r);
		temp->word[stem(temp->word,0,strlen(temp->word)-1)+1] = 0;
		temp->next=new QueryNode;
		temp=temp->next;
		strcpy(temp->word,strtok(NULL," "));
		strcpy(temp->word1,temp->word);
		if(strcmp(temp->word,"and")==0)
			this->op=QueryClass::and;
		else if(strcmp(temp->word,"or")==0)
			this->op=QueryClass::or;
		else if(strcmp(temp->word,"not")==0)
			this->op=QueryClass::not;

		
		strcpy(temp->word,temp->word1);
		temp->word[stem(temp->word,0,strlen(temp->word)-1)+1] = 0;
		temp->next=new QueryNode;
		temp=temp->next;
		strcpy(temp->word,strtok(NULL," "));
		strcpy(temp->word1,temp->word);
		temp->word[stem(temp->word,0,strlen(temp->word)-1)+1] = 0;
		temp->next=NULL;

		temp=first->next;
		first->next=first->next->next;
		delete temp;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new QueryNode;
		temp=temp->next;

		strtok(r," ");
		strcpy(temp->word,r);
		temp->word[stem(temp->word,0,strlen(temp->word)-1)+1] = 0;

		temp->next=new QueryNode;
		temp=temp->next;
		strcpy(temp->word,strtok(NULL," "));
		if(strcmp(temp->word,"and")==0)
			this->op=QueryClass::and;
		else if(strcmp(temp->word,"or")==0)
			this->op=QueryClass::or;
		else if(strcmp(temp->word,"not")==0)
			this->op=QueryClass::not;


		temp->word[stem(temp->word,0,strlen(temp->word)-1)+1] = 0;
		temp->next=new QueryNode;
		temp=temp->next;
		strcpy(temp->word,strtok(NULL," "));
		temp->word[stem(temp->word,0,strlen(temp->word)-1)+1] = 0;
		temp->next=NULL;

	}


}

void QueryClass::operator =(IndexClass& in)
{
	index=&in;
	IndexNode* temp;
	QueryNode* tempQ=first;
	while(tempQ!=NULL)
	{
		temp= index->indexed_words.first;

		while(temp!=NULL)
		{
			if(strcmp(temp->word,tempQ->word)==0)
			{
				tempQ->freq=temp->rep;
				tempQ->docF=temp->docF;
			}
			temp=temp->next;
		}

		tempQ=tempQ->next;
	}
}

void QueryClass::orderedItems()
{
	QueryNode*temp=first;
	QueryNode*temp2=first;

	if(temp2->freq<temp2->next->freq)
	{	
		temp=new QueryNode;
		*temp=*(temp2->next);

		strcpy(temp2->next->word,temp2->word);
		strcpy(temp2->next->word1,temp2->word1);
		temp2->next->freq=temp2->freq;
		temp2->next->docF=temp2->docF;
		
		strcpy(temp2->word,temp->word);
		strcpy(temp2->word1,temp->word1);
		temp2->freq=temp->freq;
		temp2->docF=temp->docF;
		
	}


}

char* QueryClass::operator [](int n)
{
	int x=0;
	QueryNode* temp=first;
	while(temp!=NULL)
	{
		if(n==x)
		{
			return temp->word1;
		}
		x++;
		temp=temp->next;
	}

	cout<<"\nThe value you entered is too large.\n";
	return NULL;
}

int QueryClass::getTermDocFreq(int n)
{
	int x=0;
	QueryNode* temp=first;
	while(temp!=NULL)
	{
		if(n==x)
		{
			return temp->docF;
		}
		x++;
		temp=temp->next;
	}

	cout<<"\nThe value you entered is too large.\n";
	return NULL;
}

QueryNode* QueryClass::retF()
{
	return first;
}