#pragma once
class DLList
{
public:
	DLList();
	DLList(int i);
	~DLList();

	struct node {
		int data;
		struct node* prev;
		struct node* next;
	};

	void insertFront(struct node** head, int data);
	void insertEnd(struct node** head, int data);
	void insertNode(struct node* prev_node, int data);
	void insertNode(struct node** prev_node, int pos, int data);
	void deleteNode(struct node** head, struct node* del_node);
	void deleteNode(struct node** head, int pos);
	int nodeTotal(struct node** head);
	bool listEmpty(struct node** head);
	int startNode(struct node** head);
	int endNode(struct node** head);
	void displayNodes(struct node* head);
	int NodeData(struct node** nd, int pos);
	void sortList(struct node** head, int nodeTotal);
};

