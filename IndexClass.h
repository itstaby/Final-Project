
#ifndef INDEX
#define INDEX

#include "indexLinkedList.h"
#include "documentClass.h"

using namespace std;


//This is the main Index Class. It contains the list named "indexed_words" and all the operations to be performed on this list.

class IndexClass
{
	IndexList indexed_words;
	static int doc_num;

	public:
		void operator +=(DocumentClass&);
		void operator -=(int);
		bool checkRepeat(char *word, int fr, DocumentClass);
		void displayIndex();
		void viewDocIds(IndexNode* node);
		IndexNode* retF();
		char* operator [] (int);
		int getTermCount(char*);

		friend class QueryClass;
		friend class SearchIndexClass;

};

#endif
