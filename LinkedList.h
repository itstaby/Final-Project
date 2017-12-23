#ifndef LIST
#define LIST

//#include "indexClass.h"

struct wordNode
{
     char word[50];
	 int rep;
//	 IndexClass* first;
	 
     wordNode  *next;
	 wordNode()
	 {
		 rep=1;
		 
	 }
}; 
class docList{
private:	// Declare a structure for the list	
	
	wordNode *first;
	int total;
	public:	
		docList(void)	// Constructor		
		{
			first = NULL;
			total=0;
		}
		
		void appendwordNode(char*);	
		void insertwordNode(float);	
		void deletewordNode(float);	
		void displayList(void);
		bool checkRepeat(char*);
		friend class DocumentClass;
		friend class IndexClass;


};

#endif