#include "class Bitvector.h"
#include<iostream>
#include<cmath>

Bitvector::Bitvector(unsigned int size) :_size(size)
{
	if (_size % 32 == 0)
	{
	    _ptr = new unsigned[_size / 32]();
	}
	else
	{
		int new_size = _size / 32 + 1;
		_ptr = new unsigned[new_size]();
	}
}

void Bitvector::setBit(unsigned int pos)
{
	if (pos >= _size || pos < 0)
	{
		throw("Invalid argument");
	}

	int posInArray = pos / 32;  // element that contain that bit
    unsigned int pow_of_2 = (unsigned int)pow(2, (pos % 32));  // the bit which we want to set in 1 

	if (pos < 32 )
	{
		pow_of_2 = (unsigned int)pow(2, pos); // in case of pos < 32
	}

	_ptr[posInArray] = _ptr[posInArray] | pow_of_2; // set 1
}

void Bitvector::resetBit(unsigned int pos)
{
	if (pos >=  _size || pos < 0)
	{
		throw("Invalid argument");
	}

	int posInArray = pos / 32;  // element that contain that bit
	unsigned int pow_of_2 = (unsigned int)pow(2, (pos % 32));  // the bit which we want to set in 1 

	if (pos < 32)
	{
		pow_of_2 = (unsigned int) pow(2, pos); // in case of pos < 32
	}

	_ptr[posInArray] = _ptr[posInArray] ^ pow_of_2; // set 0 
}


Bitvector::~Bitvector()
{
	delete[] _ptr;
}