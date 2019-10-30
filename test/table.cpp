#include <cstdint>
#include <cstdio>
#include <vector>
#include "../avl.h"
#include "../symtable.h"


int main(int argc, char **argv) {
	char *testing[] = {"hello", "Schema", ":", "World", NULL};
	uint32_t hashes[] = {0, 0, 0, 0, 0};
	symtable t = symtable();

	for(int i = 0; testing[i] != NULL; i++) {
		for( int j = 0; testing[i][j]; j++) {
			t.intern(testing[i][j]);
		}
		hashes[i] = t.commit();
	}
	
	for(int i = 0; hashes[i]; i++) {
		printf("%d ", hashes[i]);
	}
	printf("\n");
	for(int i = 0; hashes[i]; i++) {
		printf("%s\n", t.bank.data() + t.outtern(hashes[i]));
	}
	return 0;
}
