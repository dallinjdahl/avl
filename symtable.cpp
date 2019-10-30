#include <cstdint>
#include <cstdio>
#include <vector>
#include <cstring>
#include "avl.h"
#include "symtable.h"

symtable::symtable() {
	table = avl();
	hash = 5381;
}

void symtable::intern(char c) {
	bank.push_back(c);
	hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
}

uint32_t symtable::commit() {
	bank.push_back('\0');
	uint32_t res = table.lookup(hash);
	if (table.error()) {
		table.insert(hash, end);
		end = bank.size();
		return hash;
	}
	bool col = !strcmp(bank.data()+end, bank.data()+res);
	if (!col) {
		printf("E: collision error\n");
		return -1;
	}
	res = hash;
	hash = 5381;
	bank.resize(end);
	return res;
}

uint32_t symtable::outtern(uint32_t sym) {
	uint32_t res = table.lookup(sym);
	if(table.error()) {
		printf("E: nonexistent symbol\n");
		return -1;
	}
	return res;
}

