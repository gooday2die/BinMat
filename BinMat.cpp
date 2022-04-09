//
// @file : BinMat.cpp
// @author : Gooday2die (Isu Kim)
// @Contacts : edina00@naver.com
// @brief : A file that implements everything for class BinMat
// 

#include "BinMat.h"

BinMat::BinMat(uint32_t argX, uint32_t argY){
	uint32_t totalElements = argX * argY;
	uint32_t totalDataCount = totalElements / 32 + 1;
	this->x = argX;
	this->y = argY;
	this->data = (uint32_t*) malloc (sizeof(uint32_t) * totalDataCount);
	for (uint32_t i = 0 ; i < totalDataCount ; i++) this->data[i] = 0x00000000;
}

uint8_t BinMat::get(uint32_t argX, uint32_t argY){	
	uint32_t dataIndex = (this->x * argY + argX) / 32;
	uint32_t dataSegmentIndex (this->x * argY + argX) % 32;
	uint32_t tmpData = this->data[dataIndex];
	return ((tmpData >> dataSegmentIndex) & 0x1);
}

void BinMat::set(uint32_t argX, uint32_t argY, uint8_t value){
	uint32_t dataIndex = (this->x * argY + argX) / 32;
	uint32_t dataSegmentIndex (this->x * argY + argX) % 32;
	uint32_t tmpData = (value << dataSegmentIndex);
	uint32_t tmpData2 = !(0x1 << dataSegmentIndex);
	this->data[dataIndex] = tmpData2 | tmpData;
}
