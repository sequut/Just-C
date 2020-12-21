#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


typedef struct Node {
	struct Node* prev, * next;
	double value;
}Node;

const int vichet = 2 * sizeof(Node*) / sizeof(double);

double* initList() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == 0)
		exit(666);

	head->prev = head;
	head->next = head;
	return &head->value;
}

void freeList(double* head) {
	Node* curr = (Node*)(head - vichet);
	Node* need_to_free;

	need_to_free = curr;
	curr = curr->next;
	free(need_to_free);

	while (curr != ((Node*)(head - vichet))) {
		need_to_free = curr;
		curr = curr->next;
		free(need_to_free);
	}
}

double* getNext(double* curr) {
	Node* ret = (Node*)(curr - vichet);
	return &ret->next->value;
}

double* getPrev(double* curr) {
	Node* ret = (Node*)(curr - vichet);
	return &ret->prev->value;
}

double* addAfter(double* where, double newval) {
	Node* curr = (Node*)(where - vichet);

	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == 0)
		exit(666);

	new_node->prev = curr;
	new_node->next = curr->next;
	new_node->value = newval;

	curr->next->prev = new_node;
	curr->next = new_node;

	return &new_node->value;
}

double* addBefore(double* where, double newval) {
	Node* curr = (Node*)(where - vichet);

	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == 0)
		exit(666);

	new_node->next = curr;
	new_node->prev = curr->prev;


	new_node->value = newval;

	curr->prev->next = new_node;
	curr->prev = new_node;

	return &new_node->value;
}

void erase(double* what) {
	Node* curr = (Node*)(what - vichet);
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	free(curr);
}

void printList(double* head) {
	Node* start = (Node*)(head - vichet);
	Node* tek = start->prev;
	while (tek != start) {
		printf("%0.3lf\n", tek->value);
		tek = tek->prev;
	}
}
double* aa[100001];
double** a = aa + 1;
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d\n", &t);

	int q;

	int type;
	int where;
	int kol;

	double val;


	for (int i = 0; i < t; i++) {
		scanf("%d\n", &q);
		a[-1] = initList();
		kol = 0;

		for (int j = 0; j < q; j++) {
			scanf("%d %d ", &type, &where);
			if (type == 1) {
				scanf("%lf\n", &val);
				a[kol] = addBefore(a[where], val);
				kol += 1;
			}
			else if (type == -1) {
				scanf("%lf\n", &val);
				a[kol] = addAfter(a[where], val);
				kol += 1;
			}
			else {
				double print = *a[where];
				printf("%0.3lf\n", print);
				erase(a[where]);
			}
		}
		printf("===\n");
		printList(a[-1]);
		freeList(a[-1]);
		printf("===\n");
	}

	return 0;
}
