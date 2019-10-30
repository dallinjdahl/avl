#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "avl.h"

avl::avl() {
	node n = {0, 0, 0, 0, 0};
	v.push_back(n);
}

void avl::print() {
	printtree(v[0].l, 0);
}

void avl::dump() {
	for(int i = 0; i < v.size(); i++) {
		printf("i: %d k: %d v: %d l: %d r: %d h: %d\n", i, v[i].k, v[i].v, v[i].l, v[i].r, v[i].h);
	}
}

void avl::printtree(uint32_t i, uint8_t indent) {
	if(v[i].l) {
		printtree(v[i].l, indent+4);
	}
	for(int i = 0; i < indent; i++,printf(" "));
	printf("%d:%d\n",v[i].k, v[i].v); 
	if(v[i].r) {
		printtree(v[i].r, indent+4);
	}
}

void avl::setroot(uint32_t i) {
	v[0].l = i;
}

int8_t avl::bf(uint32_t i) {
	uint8_t disc = !(v[i].l) << 1 + !(v[i].r); //!l !r
	switch(disc) {
	case 0:
		return v[v[i].r].h - v[v[i].l].h; 
	case 1:
		return -v[v[i].l].h;
	case 2:
		return v[v[i].r].h;
	default:
		return 0;
	}
}

uint32_t avl::rrotate(uint32_t i) {
	uint32_t z = v[i].l;
	v[i].l = v[z].r;
	v[z].r = i;
	v[z].h++;
	v[i].h--;
	return z;
}

uint32_t avl::lrotate(uint32_t i) {
	uint32_t z = v[i].r;
	v[i].r = v[z].l;
	v[z].l = i;
	v[z].h++;
	v[i].h--;
	return z;
}

uint32_t avl::balance(uint32_t i) {
	int8_t b = bf(i);
//printf("bf: %d\n", b);
	if(-2 < b && b < 2) {
		return i;
	}
	b <<= 2;
	if (b < 0) {
		b += bf(v[i].l + 1);
	} else {
		b += bf(v[i].r + 1);
	}

	switch(b) {
	case -8: //ll
	case -7:
		return rrotate(i);
	case -6: //lr
		v[i].l = lrotate(v[i].l);
		return rrotate(i);
	case 8: //rl
		v[i].r = rrotate(v[i].r);
		return lrotate(i);
	case 9:
	case 10: //rr
		return lrotate(i);
	default:
		printf("E: balance switch %d\n", b);
		return i;
	}

}

void avl::insert(uint32_t key, uint32_t val) {
	cvalid = false;
	v[0].l = recuri(v[0].l, key, val);
}

#define max(a,b) (a > b ? a : b)
uint32_t avl::recuri(uint32_t i, uint32_t key, uint32_t val) {
//printf("%d %d %d\n", i, key, val);
	if(v[i].k == key) {
		v[i].v = val;
		return i;
	}
	uint8_t disc = ((v[i].k < key) << 2) + (!(v[i].l) << 1) + !(v[i].r); // lb !l !r
//printf("%d\n", disc);
	switch(disc) {
	case 0: //rb _ r
	case 2:
		v[i].r = recuri(v[i].r, key, val);
		break;
	case 4: //lb l _
	case 5:
		v[i].l = recuri(v[i].l, key, val);
		break;
	case 1:  //rb _ !r
	case 3: {
		node n = {key, val, 0, 0, 0};
		uint32_t s = v.size();
		v.push_back(n);
		v[i].r = s;
		break;
	}
	case 6:  //lb !l _
	case 7: {
		node n = {key, val, 0, 0, 0};
		uint32_t s = v.size();
		v.push_back(n);
		v[i].l = s;
		break;
	} //case
	} //switch
//printf("ri\n");
	v[i].h = genheight(i);
	return balance(i);
}

uint8_t avl::genheight(uint32_t i) {
	uint8_t disc = !(v[i].l) << 1 + !(v[i].r); //!l !r
	switch(disc) {
	case 0:
		return max(v[v[i].r].h, v[v[i].l].h) + 1;
	case 1:
		return v[v[i].l].h + 1;
	case 2:
		return v[v[i].r].h + 1;
	default:
		return 0;
	}
}

uint32_t avl::lookup(uint32_t key) {
	if(cvalid && ck == key) {
		return cv;
	}
	return recurl(v[0].l, key);
}

uint32_t avl::recurl(uint32_t i, uint32_t key) {
	if(v[i].k == key) {
		return v[i].v;
	}
	uint8_t disc = ((v[i].k < key) << 2) + (!(v[i].l) << 1) + !(v[i].r); // lb !l !r
	switch(disc) {
	case 0: //rb _ r
	case 2:
		return recurl(v[i].r, key);
	case 4: //lb l _
	case 5:
		return recurl(v[i].l, key);
	default:
		error_p = true;
		return 0;
	}
}

bool avl::error() {
	bool e = error_p;
	error_p = false;
	return e;
}
