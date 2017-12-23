#include "indexClass.h"
#include "stem.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

void IndexClass::operator +=(DocumentClass& doc)
{
	IndexNode* temp_index;
	temp_index=indexed_words.first;
	wordNode* temp_doc;
	temp_doc=doc.list.first;
	doc_num++;
	cout<<"\n---- INDEXING DOCUMENT "<<doc_num<<" -----\n";
	cout<<"\nIndexing words...\n\n";
	
	

	do
	{
		if(indexed_words.first==NULL) // If the list is initially empty.
		{
			indexed_words.first= new IndexNode;
			indexed_words.first->word=new char [strlen(doc.list.first->word)];
			strcpy(indexed_words.first->word,doc.list.first->word);
			indexed_words.first->rep=doc.list.first->rep;

			indexed_words.first->next=NULL;
			temp_index=indexed_words.first;

			temp_index->rep=temp_doc->rep;

			temp_doc=temp_doc->next;

			if(temp_index->first==NULL)
			{
				temp_index->first=new docs;
				temp_index->first->next=NULL;
				temp_index->first->doc_id=doc_num;
				temp_index->first->termF=temp_doc->rep;
				temp_index->first->path=new char [strlen(doc.path)];
				strcpy(temp_index->first->path,doc.path);
				temp_index->docF++;
				
			}
			else
			{
				docs* hold= temp_index->first;

				while(hold->next!=NULL)
					hold=hold->next;

				hold->next=new docs;
				hold->next->path=new char [strlen(doc.path)];
				strcpy(hold->next->path,doc.path);
				hold->next->doc_id=doc_num;
				hold->next->termF=temp_doc->rep;
				hold->next->next=NULL;
				temp_index->docF++;
			}			
		}
		else
		{
			if(checkRepeat(temp_doc->word,temp_doc->rep,doc))
			{	
				while(temp_index->next!=NULL)
				{
				
					temp_index=temp_index->next;
				}
				
				
				temp_index->next=new IndexNode;
				temp_index->next->word=new char [strlen(temp_doc->word)];
				strcpy(temp_index->next->word,temp_doc->word);
				temp_index->next->rep=temp_doc->rep;
			
				temp_index->next->next=NULL;
				temp_index=temp_index->next;
				
				temp_index->first=new docs;
				temp_index->first->next=NULL;
				temp_index->first->doc_id=doc_num;
				temp_index->first->termF=temp_doc->rep;
				temp_index->first->path=new char [strlen(doc.path)];
				strcpy(temp_index->first->path,doc.path);
				temp_index->docF++;
			}
		
			temp_doc=temp_doc->next;

		}
	}while(temp_doc!=NULL);
	cout<<"Indexing Complete.\n";
}


void IndexClass::operator -=(int id)
{
	IndexNode*temp=indexed_words.first;

	while(temp!=NULL)
	{
		docs* hold=temp->first;
		if(hold->doc_id==id)
		{
			temp->rep-=hold->termF;
			temp->first=temp->first->next;
		}
		else
		{
			
			while(hold->next!=NULL)
			{
				if(hold->next->doc_id==id)
				{
					temp->rep-=hold->next->termF;
					docs* t=hold->next;
					hold->next=hold->next->next;
					delete t;
				}
				if(hold->next!=NULL)
				hold=hold->next;//getch();
			}
		}
		temp=temp->next;
	}

	temp=indexed_words.first;
	while(temp->rep<=0)
	{
		indexed_words.first=indexed_words.first->next;
		delete temp;
		temp=indexed_words.first;
	}
	while(temp->next!=NULL)
	{
		
		if(temp->next->rep<=0)
		{
			//cout<<"\nHere";getch();
			IndexNode* t=temp->next;
			temp->next=temp->next->next;
		}
		else if(temp->next!=NULL)
			temp=temp->next;
	}
	
}

bool IndexClass::checkRepeat(char* word, int fr, DocumentClass doc)
{
	IndexNode* temp_index= this->indexed_words.first;
	while(temp_index!=NULL)
	{
		if(strcmp(temp_index->word,word)==0)
		{
			temp_index->rep+=fr;
		

			docs* hold= temp_index->first;

			while(hold->next!=NULL)
			{
				
				if(fr<temp_index->minFreq)
					temp_index->minFreq=fr;

				if(fr>temp_index->maxFreq)
					temp_index->maxFreq=fr;
				hold=hold->next;
			}

			hold->next=new docs;
			hold->next->doc_id=doc_num;
			hold->next->path=new char [strlen(doc.path)];
			strcpy(hold->next->path,doc.path);
			hold->next->termF=fr;
			hold->next->next=NULL;
			temp_index->docF++;
		//	temp_index->
		
			return false;
		}
		temp_index=temp_index->next;

	}

	return true;
}


void IndexClass::displayIndex()
{

	cout<<"The index consists of the following words:\n\n";
	IndexNode* temp=this->indexed_words.first;
	int n=0;
	cout<<"Serial"<<setw(12)<<"Term"<<setw(10)<<"Frequency"<<setw(30)<<"In Documents\n";;
	while(temp!=NULL)
	{
		cout<<setw(6)<<n<<". "<<setw(10)<<temp->word<<setw(12)<<temp->rep;
		viewDocIds(temp);
		temp=temp->next;
		n++;
		if(n%20==0)
		{
			cout<<"\nPress any key to display further.\n";
			getch();
		}
	}
	cout<<"\n\nThese are the indexed words of the document.\n";
	getch();
}

void IndexClass::viewDocIds(IndexNode* node)
{
	//cout<<"\nThe word is repeated in the following documents:\n";
	cout<<"     ";
	docs* temp=node->first;
	while(temp!=NULL)
	{
		cout<<temp->doc_id<<"("<<temp->termF<<")";
		temp=temp->next;
		if(temp!=NULL)
		{
			cout<<",";
		}
	}
	cout<<endl<<endl;
}

char* IndexClass::operator [] (int term)
{
	IndexNode* temp= indexed_words.first;
	int n=0;
	while(temp!=NULL)
	{
		if(n==term)
			return temp->word;
		
		n++;
		temp=temp->next;
	}
	cout<<"The number is greater than the number of indexed words.\n";
	return NULL;
}

int IndexClass::getTermCount(char* c)
{
	char*r=new char [strlen(c)];
	strcpy(r,c);
	
	r[stem(r,0,strlen(r)-1)+1] = 0;
	cout<<r;
	
	IndexNode* temp= indexed_words.first;
	while(temp!=NULL)
	{
		if(strcmp(temp->word,r)==0)
		{
			return temp->rep;
			cout<<"True";
		}

		temp=temp->next;
	}

	return 0;
}

IndexNode* IndexClass::retF()
{
	return this->indexed_words.first;
}
int IndexClass::doc_num=0;