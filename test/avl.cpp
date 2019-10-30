#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <vector>
#include "../avl.h"

int main(int argc, char **argv) {
	avl t = avl();
	t.print();
	t.dump();
	printf("---\n");
	t.insert(5, 10);
	t.print();
	t.dump();
	printf("---\n");
	t.insert(3, 6);
	t.print();
	t.dump();
	printf("---\n");
	t.insert(4, 8);
	t.print();
	t.dump();
	printf("---\n");
	t.insert(15, 30);
	t.print();
	t.dump();
	printf("---\n");
	t.insert(5, 77);
	t.print();
	t.dump();
	printf("---\n");
	printf("val of 3: %d\n", t.lookup(3));
	printf("val of 5: %d\n", t.lookup(5));
	return 0;
}
