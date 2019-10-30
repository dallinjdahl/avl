//needs avl, vector, cstdint
class symtable {
	public:
		symtable();
		void intern(char c);
		uint32_t commit();
		uint32_t outtern(uint32_t);
		std::vector<char> bank;
	private:
		uint32_t hash;
		uint32_t end;
		avl table;
};

