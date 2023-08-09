#pragma once
class DLList
{
public:
	DLList();
	~DLList();

	struct node {
		int data;
		struct node* prev;
		struct node* next;
	};

	node* head = NULL;
	node* end = head;


	void insertFront(int data);
	void insertEnd(int data);
	void insertNode(int pos, int data);
	void deleteFront();
	void deleteEnd();
	void deleteNodeP(int pos);
	void deleteNodeN(int num);
	int nodeTotal();
	bool Empty();
	int startNode();
	int endNode();
	void displayNodes();
	int NodeData(int pos);
	void sortList(int nodeTotal);

	void clearAllNodes();
};

