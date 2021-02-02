#include <iostream>
using namespace std;
const int size = 11;
class Hashing
{
	struct Node
	{
		int data;
		Node *next;
	};
	Node HashTable[size];

public:
	Hashing()
	{
		for (int i = 0; i < size; i++)
		{
			HashTable[i].data = -99999;
			HashTable[i].next = NULL;
		}
	}
	void insert(int n)
	{
		int key = hashFun1(n); 
		if (HashTable[key].data == -99999)
			HashTable[key].data = n;
		else
			HashTable[key].next=insertRec(HashTable[key].next,n);
	}
	int hashFun1(int n)
	{
		return n%size;
	}
	void getList(int n)
	{
		int key = hashFun1(n);
		outputList(HashTable[key].next);
	}
	Node* insertRec(Node *temp, int n)
	{
		if (temp == NULL)
		{
			Node *ptr = new Node;
			ptr->data = n;
			ptr->next = NULL;
			return ptr;
		}
		else
			temp->next = insertRec(temp->next, n);
		return temp;
	}
	void outputList(Node *temp)
	{
		Node *ptr = temp;
		while (ptr != NULL)
		{
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
	~Hashing()
	{
		for (int i = 0; i < size; i++)
		{
			Node *ptr=HashTable[i].next;
			while (ptr)
			{
				Node *temp = ptr;
				ptr = ptr->next;
				delete temp;
			}
		}
	}
};

int main()
{
	Hashing  hash;
	hash.insert(5);
	hash.insert(38);
	hash.insert(71);
	hash.insert(104);
	cout << "List at index 5\n";
	hash.getList(5);
	system("pause>0");
}