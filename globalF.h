#ifndef GLOBAL
#define GLOBAL

#include <iostream>
#include "SearchIndexClass.h"

using namespace std;


ostream& operator << (ostream out, SearchIndexClass obj);
ostream& operator << (ostream out, IndexClass obj);
ostream& operator <<(ostream& out, QueryClass query);


#endif