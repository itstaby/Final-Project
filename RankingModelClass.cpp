#include "RankingModelClass.h"
#include <iostream>

using namespace std;

void Ranking::operator = (SearchIndexClass& obj)
{
	first=obj.retF();
}

void Ranking::rankDocuments()
{
	docs* t=first;
	docs* t1=first;
	int n=0;

	while(t1!=NULL)
	{
		t=first;
		while(t->next!=NULL)
		{
			int x=10;
			if(t->termF<t->next->termF)
			{
				docs* hold=new docs;
				*hold=*t;
				

				char temp[100];

				strcpy(temp,t->path);

				
				t->doc_id=t->next->doc_id;
				strcpy(t->path,t->next->path);
				t->termF=t->next->termF;

				t->next->doc_id=hold->doc_id;
				strcpy(t->next->path,temp);
				t->next->termF=hold->termF;

			}
			t=t->next;
		}
		t1=t1->next;
	}
	
}