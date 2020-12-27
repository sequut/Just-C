#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000000
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Tree_s {
	int value;
	struct Tree_s* left;
	struct Tree_s* right;
} Tree;

int sost = 0;

void print_tree(Tree* tree, FILE* output) {
	if (tree != NULL) {
		print_tree(tree->left, output);
		fwrite(&tree->value, sizeof(int), 1, output);
		print_tree(tree->right, output);
	}
}

void free_tree(Tree* tree) {
	if (tree != NULL) {
		free_tree(tree->left);
		free_tree(tree->right);
		free(tree);
	}
}

Tree* addleaf(int a, Tree* tree) {
	if (tree == NULL) {
		tree = (Tree*)malloc(sizeof(Tree));
		if (tree == 0)
			exit(666);
		tree->value = a;
		tree->left = NULL;
		tree->right = NULL;
	}
	else {
		if (a == tree->value) {
			if (rand()%2 == 1)
				tree->left = addleaf(a, tree->left);
			else 
				tree->right = addleaf(a, tree->right);
		}
		else if (a < tree->value)
			tree->left = addleaf(a, tree->left);
		else
			tree->right = addleaf(a, tree->right);
	}
	return tree;
}

void shuffle(int* aa, int n) {
	for (int i = 0; i < n; i++) {
		int k = rand() % (i + 1);
		int help = aa[i];
		aa[i] = aa[k];
		aa[k] = help;
	}
}

int main() {
	FILE* input = fopen("input.bin", "rb");
	FILE* output = fopen("output.bin", "wb");

	int n;
	fread(&n, sizeof(int), 1, input);
	Tree* root = NULL;
	int a;

	int* aa = (int*)calloc(n, sizeof(int));
	if (aa == 0)
		exit(666);
	fread(aa, sizeof(int), n, input);
	shuffle(aa, n);

	for (int i = 0; i < n; i++)
		root = addleaf(aa[i], root);

	print_tree(root, output);
	free_tree(root);
	free(aa);
	fclose(input);
	fclose(output);
	return 0;
}
