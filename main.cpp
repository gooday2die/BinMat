#include <iostream>
#include "BinMat.h"

int main(void) {
	BinMat a = BinMat(10, 10);
	for (uint8_t i = 0 ; i < 10 ; i++){
		for (uint32_t j = 0 ; j < 10 ; j++) a.set(j, i, 1);
	}
	for (uint8_t i = 0 ; i < 10 ; i++){
		for (uint32_t j = 0; j < 10 ; j++) 
			printf("%d ", a.get(j, i));
		printf("\n");
	}
	return 0;
}
