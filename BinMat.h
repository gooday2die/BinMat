//
// @file : BinMat.h
// @author : Gooday2die (Isu Kim)
// @Contacts : edina00@naver.com
// @brief : A file that declares everything for class BinMat
// 

#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <exception>


class BinMat{
private:
	uint32_t x;
	uint32_t y;
	uint32_t* data;
public:
	BinMat(uint32_t, uint32_t);
	uint8_t get(uint32_t, uint32_t);
	void set(uint32_t, uint32_t, uint8_t);
	class OutOfRangeException : public std::exception{
		;
	};
};


