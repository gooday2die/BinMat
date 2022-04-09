//
// @file : BinMat.h
// @author : Gooday2die (Isu Kim)
// @Contacts : edina00@naver.com
// @brief : A file that declares everything for class BinMat
// 

#pragma once

#include <cstdint>
#include <cstdlib>


class BinMat{
private:
	uint32_t x;
	uint32_t y;
	uint32_t* data;
public:
	BinMat(uint32_t, uint32_t);
	uint8_t get(uint32_t, uint32_t);
	void set(uint32_t, uint32_t, uint32_t);
}


