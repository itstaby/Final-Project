#include "globalF.h"
#include "queryClass.h"
#include "conio.h"

using namespace std;

ostream& operator << (ostream out, SearchIndexClass obj)
{
	docs* t=obj.retF();
	if(t==NULL)
	{
		cout<<"\nThe search returned no results.\n";
	}
	else
	{
		cout<<"\nThe processed search returned the following result: \n\n";
		cout<<endl<<setw(15)<<"DOC ID"<<(setw(25))<<"Path"<<setw(20)<<"QUERY TERM COUNT"<<endl;	

		while(t!=NULL)
		{
			cout<<endl<<setw(15)<<t->doc_id<<(setw(25))<<t->path<<setw(20)<<t->termF<<endl;
			t=t->next;
		}

	}

	return out;

}

ostream& operator << (ostream out, IndexClass obj)
{
	cout<<"\nThe index consists of the following words:\n\n";
	IndexNode* temp=obj.retF();
	int n=0;
	cout<<"Serial"<<setw(12)<<"Term"<<setw(10)<<"Frequency"<<setw(30)<<"In Documents\n";;
	while(temp!=NULL)
	{
		cout<<setw(6)<<n<<". "<<setw(10)<<temp->word<<setw(12)<<temp->rep;
		obj.viewDocIds(temp);
		temp=temp->next;
		n++;
		if(n%20==0)
		{
			cout<<"\nPress any key to display further.\n";
			getch();
		}
	}
	cout<<"\n\n--------- END OF LIST ---------.\n";
	getch();
	return out;
}

ostream& operator <<(ostream& out, QueryClass query)
{
	QueryNode* temp=query.retF();

	cout<<"\n\n";
	cout<<setw(10)<<"QUERY"<<setw(15)<<"TERM COUNT"<<setw(20)<<"DOCUMENT FREQUENCY"<<endl<<endl;
	while(temp!=NULL)
	{
		cout<<setw(10)<<temp->word1<<setw(15)<<temp->freq<<setw(20)<<temp->docF<<endl;
		temp=temp->next;
	}

	return out;
}