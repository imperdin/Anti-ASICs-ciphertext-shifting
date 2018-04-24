#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void ShiftAESCipherText(unsigned char* Target,unsigned char* Base)
{
   int i;
   unsigned char Register[16];
	unsigned char Splitter[16] = { 9,15,6,2,13,14,5,11,0,4,12,1,10,7,3,8 };
	unsigned char Builder[16] = { 8,4,11,0,15,10,12,13,7,5,9,6,1,14,2,3 };
	for (i = 0 ; i < 16 ; i++)
   {
      Register[i] = Base[Splitter[i]];
   }
	Register[10] ^= ((Register[14] ^ Register[3]) ^ (Register[4] - Register[13]) - (Register[2] - Register[4]) ^ (Register[7] - Register[15]) - (Register[2] ^ Register[11]) ^ (Register[2] + Register[6]) + (Register[8] ^ Register[15]) + (Register[7] ^ Register[5]) );
	Register[15] ^= ((Register[7] - Register[4]) - (Register[13] + Register[8]) - (Register[8] ^ Register[3]) + (Register[2] - Register[14]) - (Register[10] + Register[13]) ^ (Register[3] ^ Register[2]) + (Register[6] ^ Register[2]) + (Register[12] + Register[10]) );
	Register[4] ^= ((Register[8] ^ Register[6]) - (Register[14] ^ Register[13]) ^ (Register[3] - Register[6]) - (Register[7] ^ Register[11]) );
	Register[2] ^= ((Register[1] ^ Register[9]) + (Register[6] + Register[14]) - (Register[13] + Register[15]) + (Register[10] - Register[4]) + (Register[15] + Register[3]) ^ (Register[14] + Register[1]) ^ (Register[7] ^ Register[11]) );
	Register[14] ^= ((Register[16] + Register[10]) - (Register[16] + Register[16]) ^ (Register[10] ^ Register[6]) ^ (Register[7] ^ Register[10]) ^ (Register[3] - Register[13]) + (Register[10] - Register[4]) - (Register[11] ^ Register[3]) ^ (Register[0] - Register[7]) );
	Register[5] ^= ((Register[0] ^ Register[6]) + (Register[16] - Register[7]) - (Register[10] - Register[16]) + (Register[11] - Register[16]) ^ (Register[15] - Register[10]) ^ (Register[4] ^ Register[1]) ^ (Register[0] ^ Register[12]) );
	Register[6] ^= ((Register[16] - Register[14]) ^ (Register[11] + Register[4]) - (Register[4] + Register[11]) ^ (Register[14] + Register[16]) + (Register[9] - Register[9]) );
	Register[1] ^= ((Register[0] - Register[0]) ^ (Register[5] ^ Register[16]) + (Register[16] - Register[9]) ^ (Register[11] + Register[15]) ^ (Register[14] + Register[10]) ^ (Register[10] + Register[12]) ^ (Register[7] + Register[3]) );
	Register[3] ^= ((Register[15] ^ Register[14]) - (Register[9] + Register[13]) ^ (Register[1] + Register[12]) ^ (Register[2] - Register[1]) );
	Register[11] ^= ((Register[7] ^ Register[9]) + (Register[6] - Register[16]) + (Register[4] ^ Register[2]) - (Register[10] - Register[9]) );
	Register[13] ^= ((Register[1] ^ Register[10]) + (Register[11] ^ Register[10]) ^ (Register[10] + Register[8]) - (Register[6] + Register[3]) - (Register[3] + Register[12]) );
	Register[7] ^= ((Register[11] ^ Register[1]) - (Register[5] + Register[16]) ^ (Register[13] ^ Register[1]) - (Register[3] ^ Register[3]) - (Register[10] + Register[12]) );
	Register[9] ^= ((Register[5] - Register[1]) + (Register[4] - Register[0]) - (Register[0] + Register[15]) ^ (Register[2] - Register[10]) ^ (Register[13] - Register[5]) );
	Register[0] ^= ((Register[13] - Register[3]) - (Register[3] + Register[10]) - (Register[13] ^ Register[15]) - (Register[6] + Register[3]) + (Register[7] ^ Register[16]) );
	Register[8] ^= ((Register[9] - Register[11]) ^ (Register[0] + Register[0]) ^ (Register[11] + Register[14]) - (Register[9] + Register[4]) );
	Register[12] ^= ((Register[8] ^ Register[1]) - (Register[7] ^ Register[10]) - (Register[4] ^ Register[5]) ^ (Register[7] + Register[14]) + (Register[5] + Register[1]) + (Register[10] + Register[4]) + (Register[14] ^ Register[9]) );
	for (i = 0 ; i < 16 ; i++)
   {
      Target[i] = Register[Builder[i]];
   }
}


void UnShiftAESCipherText(unsigned char* Target,unsigned char* Base)
{
   int i;
   unsigned char Register[16];
	unsigned char Splitter[16] = { 9,15,6,2,13,14,5,11,0,4,12,1,10,7,3,8 };
	unsigned char Builder[16] = { 8,4,11,0,15,10,12,13,7,5,9,6,1,14,2,3 };
	for (i = 0 ; i < 16 ; i++)
   {
      Register[Builder[i]] = Base[i];
   }
	Register[12] ^= ((Register[8] ^ Register[1]) - (Register[7] ^ Register[10]) - (Register[4] ^ Register[5]) ^ (Register[7] + Register[14]) + (Register[5] + Register[1]) + (Register[10] + Register[4]) + (Register[14] ^ Register[9]) );
	Register[8] ^= ((Register[9] - Register[11]) ^ (Register[0] + Register[0]) ^ (Register[11] + Register[14]) - (Register[9] + Register[4]) );
	Register[0] ^= ((Register[13] - Register[3]) - (Register[3] + Register[10]) - (Register[13] ^ Register[15]) - (Register[6] + Register[3]) + (Register[7] ^ Register[16]) );
	Register[9] ^= ((Register[5] - Register[1]) + (Register[4] - Register[0]) - (Register[0] + Register[15]) ^ (Register[2] - Register[10]) ^ (Register[13] - Register[5]) );
	Register[7] ^= ((Register[11] ^ Register[1]) - (Register[5] + Register[16]) ^ (Register[13] ^ Register[1]) - (Register[3] ^ Register[3]) - (Register[10] + Register[12]) );
	Register[13] ^= ((Register[1] ^ Register[10]) + (Register[11] ^ Register[10]) ^ (Register[10] + Register[8]) - (Register[6] + Register[3]) - (Register[3] + Register[12]) );
	Register[11] ^= ((Register[7] ^ Register[9]) + (Register[6] - Register[16]) + (Register[4] ^ Register[2]) - (Register[10] - Register[9]) );
	Register[3] ^= ((Register[15] ^ Register[14]) - (Register[9] + Register[13]) ^ (Register[1] + Register[12]) ^ (Register[2] - Register[1]) );
	Register[1] ^= ((Register[0] - Register[0]) ^ (Register[5] ^ Register[16]) + (Register[16] - Register[9]) ^ (Register[11] + Register[15]) ^ (Register[14] + Register[10]) ^ (Register[10] + Register[12]) ^ (Register[7] + Register[3]) );
	Register[6] ^= ((Register[16] - Register[14]) ^ (Register[11] + Register[4]) - (Register[4] + Register[11]) ^ (Register[14] + Register[16]) + (Register[9] - Register[9]) );
	Register[5] ^= ((Register[0] ^ Register[6]) + (Register[16] - Register[7]) - (Register[10] - Register[16]) + (Register[11] - Register[16]) ^ (Register[15] - Register[10]) ^ (Register[4] ^ Register[1]) ^ (Register[0] ^ Register[12]) );
	Register[14] ^= ((Register[16] + Register[10]) - (Register[16] + Register[16]) ^ (Register[10] ^ Register[6]) ^ (Register[7] ^ Register[10]) ^ (Register[3] - Register[13]) + (Register[10] - Register[4]) - (Register[11] ^ Register[3]) ^ (Register[0] - Register[7]) );
	Register[2] ^= ((Register[1] ^ Register[9]) + (Register[6] + Register[14]) - (Register[13] + Register[15]) + (Register[10] - Register[4]) + (Register[15] + Register[3]) ^ (Register[14] + Register[1]) ^ (Register[7] ^ Register[11]) );
	Register[4] ^= ((Register[8] ^ Register[6]) - (Register[14] ^ Register[13]) ^ (Register[3] - Register[6]) - (Register[7] ^ Register[11]) );
	Register[15] ^= ((Register[7] - Register[4]) - (Register[13] + Register[8]) - (Register[8] ^ Register[3]) + (Register[2] - Register[14]) - (Register[10] + Register[13]) ^ (Register[3] ^ Register[2]) + (Register[6] ^ Register[2]) + (Register[12] + Register[10]) );
	Register[10] ^= ((Register[14] ^ Register[3]) ^ (Register[4] - Register[13]) - (Register[2] - Register[4]) ^ (Register[7] - Register[15]) - (Register[2] ^ Register[11]) ^ (Register[2] + Register[6]) + (Register[8] ^ Register[15]) + (Register[7] ^ Register[5]) );
	for (i = 0 ; i < 16 ; i++)
   {
      Target[Splitter[i]] = Register[i];
   }
}