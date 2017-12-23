#include <iostream>
#include <conio.h>
#include <fstream>
#include "LinkedList.h"

using namespace std;

void docList::appendwordNode(char* n)
{
	wordNode* temp=first;

	

	if(temp==NULL)
	{
		temp=new wordNode;
		strcpy(temp->word,n);
		temp->next=NULL;
		first=temp;


	}

	else
	{
		
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
	
		temp->next=new wordNode;
		temp=temp->next;
		temp->next=NULL;
		strcpy(temp->word,n);
	}

	total++;
}

void docList::displayList()
{
	wordNode* temp=first;
	int n=0;
	while(temp!=NULL)
	{
		cout<<n<<".\t"<<temp->word<<"\t"<<temp->rep<<endl;
		temp=temp->next;
		n++;
	}
	cout<<"Total number of words in the list: "<<total;
	cout<<"\n\n-----------------------------END OF LIST--------------------------------\n\n";

}

bool docList::checkRepeat(char* word)
{
	wordNode* temp=first;
	while(temp!=NULL)
	{
		if(strcmp(temp->word, word)==0)
		{
			temp->rep++;
			return false;
		}
		temp=temp->next;
	}
	return true;
}