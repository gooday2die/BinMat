#include <iostream>
#include "BinMat.h"
#include <stdio.h>

int main(void) {
	BinMat a = BinMat(10000, 10000);
	for (uint32_t i = 0 ; i < 10000 ; i++){
		for (uint32_t j = 0 ; j < 10000 ; j++) a.set(j, i, 1);
	}
	return 0;
}
