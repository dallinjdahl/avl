//needs vector, cstdint, and cstdlib

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
		void dump();
		bool error();
	private:
		bool error_p;
		std::vector<node> v;
		uint32_t ck;
		uint32_t cv;
		bool cvalid;
		uint32_t rrotate(uint32_t i);
		uint32_t lrotate(uint32_t i);
		uint32_t balance(uint32_t i);
		uint8_t genheight(uint32_t i);
		uint32_t recuri(uint32_t i, uint32_t k, uint32_t v);
		uint32_t recurl(uint32_t i, uint32_t k);
		void setroot(uint32_t i);
		void printtree(uint32_t i, uint8_t spaces);
		int8_t bf(uint32_t i);
};
