#include <iostream>
#include "DLList.h"

DLList::DLList() {
	struct node* head;

}

DLList::DLList(int i) {
	//constructor
	struct node* head;
	struct node* NewNode = new node;
	NewNode->data = i;
	NewNode->prev = NULL;
	NewNode->next = NULL;
}

DLList::~DLList() {
	//Destructor



}

void DLList::insertFront(struct node** head, int data) {
	
	struct node* NewNode = new node;

	NewNode->data = data;

	NewNode->next = (*head);

	NewNode->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = NewNode;


	(*head) = NewNode;

}

void DLList::insertEnd(struct node** head, int data) {
	
	struct node* NewNode = new node;

	NewNode->data = data;

	NewNode->next = NULL;

	struct node* temp = *head;


	if (*head == NULL) {
		NewNode->prev = NULL;
		*head = NewNode;
		return;
	}

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = NewNode;

	NewNode->prev = temp;

	free(temp);

}

void DLList::insertNode(struct node* prev_node, int data) {
	
	if (prev_node == NULL) {
		std::cout << "Previous node CANNOT be NULL" << std::endl;
		return;
	}

	struct node* NewNode = new node;

	NewNode->data = data;

	NewNode->next = prev_node->next;
	prev_node->next = NewNode;

	NewNode->prev = prev_node;

	if (NewNode->next != NULL)
		NewNode->next->prev = NewNode;

}

void DLList::deleteNode(struct node** head, struct node* del_node) {

	if (*head == NULL || del_node == NULL) {
		return;
	}

	if (*head == del_node) {
		*head = del_node->next;
	}

	if (del_node->prev != NULL) {
		del_node->prev->next = del_node->next;
	}

	if (del_node->next != NULL) {
		del_node->next->prev = del_node->prev;
	}

	free(del_node);
}

void DLList::deleteNode(struct node** head, int pos) {

	if (*head == NULL || pos <= 0) {
		return;
	}

	struct node* temp = *head;


	for (int i = 0; temp != NULL || i < pos; i++) {
		temp = temp->next;
	}

	if (temp == NULL) {
		return;
	}
	
	deleteNode(head, temp);
	free(temp);
}

int DLList::nodeTotal(struct node** head) {
	
	int count;

	struct node* temp = *head;

	while (temp->next != NULL) {
		count++;
		temp = temp->next;
	}

	free(temp);

	return count;

}

bool DLList::listEmpty(struct node** head) {
	
	if (*head == NULL) {
		std::cout << "HEAD is NULL" << std::endl;
		return true;
	}
	return false;
}

int DLList::startNode(struct node** head) {
	

}

int DLList::endNode(struct node** head) {

}

void DLList::displayNodes(struct node* head) {
	while (head != NULL) {
		std::cout << head->data << "->";
		head = head->next;
	}
}

void DLList::sortList(struct node** head) {

}
