#ifndef QUERY
#define QUERY

#include "IndexClass.h"
#include <iomanip>
struct QueryNode
{
	char word[16];
	char word1[16];
	int docF;
	int freq;
	QueryNode* next;
	
	QueryNode()
	{
		freq=0;
		docF=0;
	}
	
};



class QueryClass
{
	QueryNode* first;
	IndexClass* index;
	enum {and,or,not} op;

	public:
		QueryClass()
		{
			first=NULL;
		}

		void operator = (char* q);
		void operator = (IndexClass&);
		void orderedItems();
		int getTermDocFreq(int n);
		char* operator [](int n);
		QueryNode* retF();	
		
		friend class SearchIndexClass;

		
};

#endif