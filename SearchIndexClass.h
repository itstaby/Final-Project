#ifndef SEARCH
#define SEARCH

#include "queryClass.h"
#include "indexLinkedList.h"
#include "globalF.h"

class SearchIndexClass
{
	QueryClass* query;
	IndexClass* index;
	int tHits;
	docs* first;
	docs* docQ1;
	docs* docQ2;

public:
	SearchIndexClass()
	{
		tHits=0;
		first=NULL;
	}
	void operator =(QueryClass& );
	void operator = (IndexClass& );
	void processQuery();
	int totalHits();
	docs* retF();
	int operator [](int);

};
#endif