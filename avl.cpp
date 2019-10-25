typedef struct node {
	uint32_t k;
	uint32_t v;
	uint32_t l;
	uint32_t r;
	int8_t h;
} node;

class avl {
	public:
		avl();
		void insert(uint32_t k, uint32_t v);
		uint32_t lookup(uint32_t k);
		void print();
	private:
		vector<node> v;
		void rrotate(uint32_t i);
		void lrotate(uint32_t i);
		void balance(uint32_t i);
		void setroot(uint32_t i);
		void printtree(uint32_t i);
}

avl::avl() {
	node n = {0, 0, 0, 0, 0};
	v.push_back(n);
}

void avl::print() {
	printtree(v[0].l, 0);
}

void avl::printtree(uint32_t i, uint8_t indent) {
	if(v[k].l) {
		printtree(v[k].l, indent+4);
	}
	for(int i = 0; i < indent; i++,printf(" "));
	printf("%d:%d\n",v[k].k, v[k].v); 
	if(v[k].r) {
		printtree(v[k].r, indent+4);
	}
}

void avl::setroot(uint32_t i) {
	v[0].l = i;
}


void avl::rrotate(uint32_t i) {
	
}

void avl::lrotate(uint32_t i) {
	
}

void avl::balance(uint32_t i) {
	
}

void avl::insert(uint32_t k, uint32_t v) {
	
}

uint32_t avl::lookup(uint32_t k) {
	
}

