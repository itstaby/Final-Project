#ifndef DOC
#define DOC

#include <iostream>
#include "LinkedList.h"

using namespace std;


class DocumentClass
{
	char* path;
	docList list;
	static int doc_num;

	public:
		void operator =(char* p);
		void parseDocument();
		int documentLength();
		int getTermFrequency(int);
		void removeBottomTerms(int);
		void removeTopTerms(int n);
		char* operator [](int);
		friend void operator << (ostream out, DocumentClass doc)
		{
			std::cout<<"\nThis document contains the following set of wrods: \n";

			doc.list.displayList();
		}
		friend class IndexClass;

		

};

#endif
