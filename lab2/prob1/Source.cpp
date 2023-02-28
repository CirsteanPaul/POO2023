#include <iostream>
#include "NumberList.h"

int main()
{
	NumberList list = NumberList();
	list.Init();
	// initialize list so we can use it
	list.Add(5);
	list.Add(9);
	list.Add(1);
	list.Add(4);

	list.Print(); // should print 5 9 1 4

	list.Sort();

	list.Print(); // should print 1 4 5 9
}