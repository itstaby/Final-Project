#ifndef RANK
#define RANK

#include "SearchIndexClass.h"
#include "indexLinkedList.h"

class Ranking
{
	docs* first;
	public:
		void operator = (SearchIndexClass&);
		void rankDocuments();
};

#endif