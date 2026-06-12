#include <iostream>
using namespace std;

struct node
{
	float data;
	struct node *next;
};

int main()
{
	struct node l;
	l.data=0;
	l.next=NULL;
	cout<<l.data<<l.next;
	return 0;
}
