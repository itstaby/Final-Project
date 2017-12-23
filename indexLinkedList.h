#ifndef INDEXLIST
#define INDEXLIST
#include <iostream>

using namespace std;
//This structure is to hold the document id's
struct docs
{
	int doc_id;
	int termF;
	char* path;
	
	docs* next;

	docs()
	{
		
		termF=0;
	}
};


//This structure holds the indexed word, its frequency, and the first pointer to the linked list with document id's
struct IndexNode
{
	char*word;
	int rep;
	int minFreq;
	int maxFreq;
	int docF;
	
	IndexNode* next;
	docs* first;

	IndexNode()
	{
		first=NULL;
		minFreq=0;
		maxFreq=0;
		docF=0;
	}
};

//This is the class for the list
class IndexList
{
	IndexNode* first;

public:
	IndexList()
	{
		first=NULL;
	}
	friend class IndexClass;
	friend class QueryClass;
	friend void operator <<(ofstream out, IndexClass index);
	friend class SearchIndexClass;

};

#endif
