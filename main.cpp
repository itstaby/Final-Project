/*-- All Rights Reserved --*/
/*-- Muhammad Tayyab Anwar --*/
/*-- i11-0076 Section A --*/

/*-- Final Project - CP --*/
/*-- Search Engine --*/

  
#include <iostream>
#include <conio.h>
#include <fstream>
#include "documentClass.h"
#include "indexClass.h"
#include "queryClass.h"
#include "SearchIndexClass.h"
#include "RankingModelClass.h"
#include <string>
using namespace std;



void main()
{
	system("color f0");
	system("mode 1366,768");

	
	DocumentClass doc,doc1,doc2,doc3,doc4,doc5;
	doc = "doc.1.txt";
	doc1 = "doc.2.txt";
	doc3 = "doc.3.txt";
	doc2 = "doc.5.txt";
	doc4 = "doc.6.txt";
	doc5 = "doc.4.txt";

	doc.parseDocument();
	doc1.parseDocument();
	doc2.parseDocument();
	doc3.parseDocument();
	doc4.parseDocument();
	doc5.parseDocument();
	IndexClass index;
	index+=(doc);
	index+=(doc1);
	index+=(doc2);
	index+=(doc3);
	index+=(doc4);
	index+=(doc5);

	QueryClass query;

	query= "article or this";

	query = index;

	SearchIndexClass obj;

	obj = query;

	obj = index;

	obj.processQuery();

	Ranking rm;

	rm=obj;

	rm.rankDocuments();

	cout<<obj;

}
