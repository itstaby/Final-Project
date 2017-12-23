#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include "SearchIndexClass.h"
#include "IndexLinkedList.h"

void SearchIndexClass::operator = (QueryClass& q)
{
	query=&q;
}

void SearchIndexClass::operator = (IndexClass& s)
{
	index=&s;
}

void SearchIndexClass::processQuery()
{
	int sizeQ1=query->first->docF;
	int sizeQ2=query->first->next->docF;
	docs* docQ1= new docs [query->first->docF];
	docs* docQ2= new docs[query->first->next->docF];
	int n=0;
	int x=0;
	cout<<"\nProcessing Query..\n";
	cout<<"\nSearching..\n";
	IndexNode* temp=query->index->indexed_words.first;
	docs *t;
	
	while(temp!=NULL)
	{
		if(strcmp(temp->word,query->first->word)==0)
		{
			t=temp->first;
			while(t!=NULL)
			{
				docQ1[x]=*t;
				x++;
				t=t->next;
			}
		}

		if(strcmp(temp->word,query->first->next->word)==0)
		{
			t=temp->first;
			while(t!=NULL)
			{
				docQ2[n]=*t;
				n++;
				t=t->next;
			}
		}

		temp=temp->next;
	}


	if(query->op==QueryClass::and)
	{
		
		for(int k=0; k<sizeQ1; k++)
		{
			
			for(int l=0; l<sizeQ2; l++)
			{
				if(docQ1[k].doc_id==docQ2[l].doc_id)
				{
					if(first==NULL)
					{
						first= new docs;
						*first=docQ2[l];
						first->termF=docQ1[k].termF+docQ2[l].termF;
						first->next=NULL;
						tHits++;
					}
					else
					{
						docs* t=first;
						while(t->next!=NULL)
						{
							t=t->next;
						}
						t->next=new docs;
						t=t->next;
						*t=docQ2[l];
						t->termF=docQ1[k].termF+docQ2[l].termF;
						t->next=NULL;
						tHits++;

					}
				}

			}
		}

	}
	else if(query->op==QueryClass::or)
	{
			
		for(int l=0; l<sizeQ2; l++)
		{
			if(first==NULL)
			{
				first= new docs;
				*first=docQ2[l];
				first->next=NULL;
				tHits++;
			}
			else
			{
				docs* t=first;
				while(t->next!=NULL)
				{
					t=t->next;
				}
				t->next=new docs;
				t=t->next;
				*t=docQ2[l];
				t->next=NULL;
				tHits++;

			}
		}
	

		for(int k=0; k<sizeQ1; k++)
		{
			int c=0;
			
			for(int l=0; l<sizeQ2; l++)
			{
				if(docQ1[k].doc_id==docQ2[l].doc_id)
				{
					
					c=1;
					docs* t=first;
					while(t->doc_id!=docQ2[l].doc_id)
					{
						t=t->next;
					}
					t->termF+=docQ1[k].termF;
					break;


				}

			}

			if(c==0)
			{

				if(first==NULL)
				{
					first= new docs;
					*first=docQ1[k];
					first->next=NULL;
					tHits++;
				}
				else
				{
					docs* t=first;
					while(t->next!=NULL)
					{
						t=t->next;
					}
					t->next=new docs;
					t=t->next;
					*t=docQ1[k];
					t->next=NULL;
					tHits++;

				}
			}
		}

		

	}
	else if(query->op==QueryClass::not)
	{
		
		for(int k=0; k<sizeQ1; k++)
		{
			int c=0;
			
			for(int l=0; l<sizeQ2; l++)
			{
				if(docQ1[k].doc_id==docQ2[l].doc_id)
				{
					c=1;
				}

			}
			if(c==0)
			{
				if(first==NULL)
				{
					first= new docs;
					*first=docQ1[k];
					first->next=NULL;
					tHits++;
				}
				else
				{
					docs* t=first;
					while(t->next!=NULL)
					{
						t=t->next;
					}
					t->next=new docs;
					t=t->next;
					*t=docQ1[k];
					t->next=NULL;
					tHits++;

				}
			}
		}

		
	}
}

int SearchIndexClass::totalHits()
{
	return tHits;
}

docs* SearchIndexClass::retF()
{
	return first;
}

int SearchIndexClass::operator [](int n)
{
	docs* t=first;
	int x=0;
	while(t!=NULL)
	{
		if(x==n)
			return t->doc_id;

		x++;
		t=t->next;
	}
	
	cout<<"\nThe number you entered exceeds the number of search results.\n";
	return NULL;
}