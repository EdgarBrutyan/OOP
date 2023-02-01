#pragma once

class Bitvector {
private:
	unsigned int _size;
	unsigned int* _ptr;

public:
	explicit Bitvector(unsigned int size);

	void setBit(unsigned int pos);

	void resetBit(unsigned int pos);
	
	~Bitvector();
};