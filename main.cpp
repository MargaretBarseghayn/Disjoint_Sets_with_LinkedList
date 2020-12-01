#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	cout << "Implementation LinkedList" << endl;
	Node* x[8]; //only x[1], x[2], ..., x[7] will be used

	for (int i = 1; i <= 7; i++)
	{
		x[i] = new Node(0, i, 0);
		make_set(x[i]);
	}

	un_sets(x[1], x[3]); un_sets(x[5], x[3]);
	un_sets(x[2], x[4]); un_sets(x[4], x[7]);

	print(x, 7);

	return 0;
}