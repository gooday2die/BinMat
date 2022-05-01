//
// @file : BinMat.cpp
// @author : Gooday2die (Isu Kim)
// @Contacts : edina00@naver.com
// @brief : A file that implements everything for class BinMat
// 

#include "BinMat.h"

/**
 * A constructor member function for class BinMAt
 * @param argX the uint32_t that represents width of binary matrix
 * @param argY the uint32_t that represents height of binary matrix
 */
BinMat::BinMat(uint32_t argX, uint32_t argY){
	uint32_t totalElements = argX * argY;
	uint32_t totalDataCount = (totalElements / 32) + 1;

	this->x = argX;
	this->y = argY;
	this->data = (uint32_t*) malloc (sizeof(uint32_t) * totalDataCount);

	for (uint32_t i = 0 ; i < totalDataCount ; i++) this->data[i] = 0x00000000;
}

/**
 * A member function that retrieves specific value from matrix
 * @param argX the uint32_t that represents x of binary matrix
 * @param argY the uint32_t that represents y of binary matrix
 * @return returns uint8_t value that represents binary value from matrix
 */
uint8_t BinMat::get(uint32_t argX, uint32_t argY){	
	if ((argX >= this->x) || (argY >= this->y)) throw BinMat::OutOfRangeException(); 
	uint32_t dataIndex = (this->x * argY + argX) / 32;
	uint32_t dataSegmentIndex = ((this->x * argY + argX) % 32);
	uint32_t tmpData = this->data[dataIndex];
	return ((tmpData >> dataSegmentIndex) & 0x1);
}

/**
 * A member function that sets specific value from matrix
 * @param argX the uint32_t that represents x of binary matrix
 * @param argY the uint32_t that represents y of binary matrix
 * @param value the uint8_t that represents value of binary matrix
 * @return returns uint8_t value that represents binary value from matrix
 */
void BinMat::set(uint32_t argX, uint32_t argY, uint8_t value){
	if ((argX >= this->x) || (argY >= this->y)) throw BinMat::OutOfRangeException(); 
	uint32_t dataIndex = (this->x * argY + argX) / 32;
	uint32_t dataSegmentIndex = ((this->x * argY + argX) % 32);
	value = value != 0;
	uint32_t tmpData = (value << dataSegmentIndex);
	uint32_t tmpData2 = ~(1 << dataSegmentIndex);
	this->data[dataIndex] = ((this->data[dataIndex] & tmpData2) | tmpData);
}
