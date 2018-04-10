#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void ShiftCipherText(unsigned char* Target,unsigned char* Base)
{
   int i;
   unsigned char Register[32];
	unsigned char Splitter[32] = { 17,15,22,26,30,10,24,2,3,19,21,29,8,16,12,18,27,6,1,0,20,5,4,14,7,28,31,9,23,25,11,13 };
	unsigned char Builder[32] = { 16,0,27,3,25,7,17,4,11,8,20,31,26,22,30,15,14,23,13,9,19,2,18,24,21,6,5,10,1,12,28,29 };
	for (i = 0 ; i < 32 ; i++)
   {
      Register[i] = Base[Splitter[i]];
   }
	Register[20] ^= ((Register[8] - Register[14]) - (Register[9] - Register[29]) ^ (Register[25] ^ Register[15]) + (Register[29] + Register[16]) ^ (Register[6] + Register[5]) - (Register[28] ^ Register[21]) - (Register[27] + Register[7]) + (Register[5] + Register[11]) );
	Register[23] ^= ((Register[5] ^ Register[24]) ^ (Register[19] ^ Register[15]) + (Register[11] + Register[27]) + (Register[25] ^ Register[6]) - (Register[13] + Register[14]) + (Register[21] + Register[2]) - (Register[18] - Register[13]) - (Register[27] + Register[26]) );
	Register[9] ^= ((Register[30] + Register[20]) + (Register[8] ^ Register[30]) - (Register[6] + Register[28]) - (Register[2] + Register[13]) );
	Register[30] ^= ((Register[4] + Register[5]) + (Register[4] - Register[22]) ^ (Register[31] ^ Register[21]) + (Register[31] - Register[31]) ^ (Register[19] + Register[12]) + (Register[14] + Register[27]) - (Register[19] ^ Register[7]) );
	Register[8] ^= ((Register[27] ^ Register[26]) ^ (Register[20] ^ Register[9]) + (Register[22] + Register[7]) + (Register[0] + Register[14]) ^ (Register[0] ^ Register[11]) + (Register[31] ^ Register[13]) - (Register[19] + Register[31]) + (Register[21] ^ Register[31]) );
	Register[27] ^= ((Register[30] ^ Register[20]) + (Register[7] - Register[3]) ^ (Register[1] - Register[24]) - (Register[31] ^ Register[12]) ^ (Register[28] + Register[21]) ^ (Register[9] ^ Register[8]) - (Register[21] - Register[28]) );
	Register[26] ^= ((Register[32] - Register[18]) - (Register[19] - Register[1]) ^ (Register[0] + Register[11]) - (Register[32] - Register[31]) - (Register[18] + Register[21]) );
	Register[19] ^= ((Register[30] - Register[27]) ^ (Register[20] - Register[23]) ^ (Register[15] - Register[6]) ^ (Register[29] ^ Register[27]) ^ (Register[18] - Register[26]) - (Register[3] - Register[24]) - (Register[5] - Register[3]) );
	Register[4] ^= ((Register[14] - Register[19]) + (Register[13] ^ Register[31]) + (Register[9] + Register[5]) - (Register[20] + Register[19]) );
	Register[7] ^= ((Register[3] + Register[20]) + (Register[23] + Register[26]) - (Register[20] - Register[19]) - (Register[16] - Register[11]) );
	Register[14] ^= ((Register[6] + Register[6]) ^ (Register[23] + Register[21]) - (Register[2] - Register[10]) ^ (Register[32] + Register[26]) ^ (Register[3] + Register[7]) );
	Register[13] ^= ((Register[5] ^ Register[20]) - (Register[23] - Register[10]) + (Register[3] ^ Register[9]) ^ (Register[0] ^ Register[0]) + (Register[29] ^ Register[4]) );
	Register[11] ^= ((Register[19] + Register[26]) - (Register[9] - Register[25]) + (Register[6] ^ Register[6]) ^ (Register[19] + Register[26]) ^ (Register[30] - Register[12]) );
	Register[25] ^= ((Register[7] + Register[14]) ^ (Register[32] - Register[18]) + (Register[21] - Register[16]) + (Register[1] + Register[1]) - (Register[22] + Register[28]) );
	Register[6] ^= ((Register[18] + Register[9]) + (Register[15] ^ Register[3]) ^ (Register[14] ^ Register[20]) + (Register[8] + Register[11]) );
	Register[17] ^= ((Register[14] ^ Register[29]) ^ (Register[11] + Register[1]) ^ (Register[21] ^ Register[24]) + (Register[9] + Register[28]) ^ (Register[18] + Register[25]) + (Register[20] + Register[29]) + (Register[29] ^ Register[3]) );
	Register[1] ^= ((Register[27] + Register[17]) + (Register[14] - Register[29]) + (Register[23] - Register[30]) - (Register[32] + Register[13]) ^ (Register[16] ^ Register[12]) );
	Register[31] ^= ((Register[29] - Register[17]) ^ (Register[11] ^ Register[19]) + (Register[5] - Register[20]) - (Register[20] + Register[17]) + (Register[21] ^ Register[25]) ^ (Register[28] - Register[0]) );
	Register[16] ^= ((Register[21] - Register[14]) ^ (Register[26] ^ Register[17]) ^ (Register[15] ^ Register[7]) ^ (Register[19] + Register[13]) - (Register[14] ^ Register[24]) - (Register[17] + Register[18]) ^ (Register[15] - Register[8]) );
	Register[21] ^= ((Register[7] + Register[13]) - (Register[28] - Register[2]) ^ (Register[27] + Register[5]) + (Register[24] + Register[19]) );
	Register[15] ^= ((Register[10] + Register[22]) ^ (Register[19] ^ Register[11]) ^ (Register[22] - Register[2]) + (Register[0] - Register[25]) + (Register[17] - Register[17]) );
	Register[28] ^= ((Register[30] ^ Register[0]) - (Register[29] - Register[16]) ^ (Register[15] ^ Register[32]) ^ (Register[4] ^ Register[20]) ^ (Register[18] ^ Register[23]) - (Register[22] ^ Register[23]) - (Register[13] - Register[26]) );
	Register[18] ^= ((Register[19] + Register[22]) ^ (Register[9] ^ Register[16]) - (Register[12] + Register[32]) + (Register[15] - Register[9]) );
	Register[12] ^= ((Register[32] - Register[0]) ^ (Register[24] ^ Register[8]) - (Register[24] ^ Register[14]) ^ (Register[4] ^ Register[7]) - (Register[4] + Register[11]) );
	Register[0] ^= ((Register[5] ^ Register[11]) ^ (Register[24] + Register[23]) ^ (Register[29] + Register[23]) ^ (Register[29] - Register[17]) + (Register[12] + Register[16]) ^ (Register[29] - Register[8]) );
	Register[3] ^= ((Register[2] + Register[15]) + (Register[5] + Register[30]) + (Register[8] - Register[21]) - (Register[0] - Register[2]) - (Register[23] + Register[22]) ^ (Register[2] + Register[16]) ^ (Register[19] - Register[14]) + (Register[19] + Register[11]) );
	Register[22] ^= ((Register[1] ^ Register[2]) ^ (Register[17] - Register[11]) ^ (Register[28] - Register[0]) ^ (Register[20] + Register[9]) );
	Register[29] ^= ((Register[4] + Register[0]) + (Register[5] + Register[23]) - (Register[9] + Register[7]) - (Register[6] - Register[1]) - (Register[7] + Register[7]) - (Register[9] + Register[15]) + (Register[31] ^ Register[17]) );
	Register[24] ^= ((Register[12] - Register[15]) + (Register[1] ^ Register[16]) ^ (Register[12] ^ Register[32]) ^ (Register[19] - Register[10]) );
	Register[5] ^= ((Register[26] - Register[31]) + (Register[26] + Register[14]) - (Register[25] - Register[27]) + (Register[23] ^ Register[11]) - (Register[31] + Register[20]) );
	Register[2] ^= ((Register[10] - Register[5]) - (Register[5] - Register[29]) + (Register[5] - Register[9]) - (Register[14] ^ Register[17]) ^ (Register[17] ^ Register[0]) ^ (Register[27] + Register[25]) + (Register[26] - Register[30]) );
	Register[10] ^= ((Register[5] + Register[5]) - (Register[21] + Register[24]) - (Register[26] ^ Register[6]) ^ (Register[5] - Register[22]) ^ (Register[1] - Register[32]) ^ (Register[24] - Register[27]) );
	for (i = 0 ; i < 32 ; i++)
   {
      Target[i] = Register[Builder[i]];
   }
}


void UnShiftCipherText(unsigned char* Target,unsigned char* Base)
{
   int i;
   unsigned char Register[32];
	unsigned char Splitter[32] = { 17,15,22,26,30,10,24,2,3,19,21,29,8,16,12,18,27,6,1,0,20,5,4,14,7,28,31,9,23,25,11,13 };
	unsigned char Builder[32] = { 16,0,27,3,25,7,17,4,11,8,20,31,26,22,30,15,14,23,13,9,19,2,18,24,21,6,5,10,1,12,28,29 };
	for (i = 0 ; i < 32 ; i++)
   {
      Register[Builder[i]] = Base[i];
   }
	Register[10] ^= ((Register[5] + Register[5]) - (Register[21] + Register[24]) - (Register[26] ^ Register[6]) ^ (Register[5] - Register[22]) ^ (Register[1] - Register[32]) ^ (Register[24] - Register[27]) );
	Register[2] ^= ((Register[10] - Register[5]) - (Register[5] - Register[29]) + (Register[5] - Register[9]) - (Register[14] ^ Register[17]) ^ (Register[17] ^ Register[0]) ^ (Register[27] + Register[25]) + (Register[26] - Register[30]) );
	Register[5] ^= ((Register[26] - Register[31]) + (Register[26] + Register[14]) - (Register[25] - Register[27]) + (Register[23] ^ Register[11]) - (Register[31] + Register[20]) );
	Register[24] ^= ((Register[12] - Register[15]) + (Register[1] ^ Register[16]) ^ (Register[12] ^ Register[32]) ^ (Register[19] - Register[10]) );
	Register[29] ^= ((Register[4] + Register[0]) + (Register[5] + Register[23]) - (Register[9] + Register[7]) - (Register[6] - Register[1]) - (Register[7] + Register[7]) - (Register[9] + Register[15]) + (Register[31] ^ Register[17]) );
	Register[22] ^= ((Register[1] ^ Register[2]) ^ (Register[17] - Register[11]) ^ (Register[28] - Register[0]) ^ (Register[20] + Register[9]) );
	Register[3] ^= ((Register[2] + Register[15]) + (Register[5] + Register[30]) + (Register[8] - Register[21]) - (Register[0] - Register[2]) - (Register[23] + Register[22]) ^ (Register[2] + Register[16]) ^ (Register[19] - Register[14]) + (Register[19] + Register[11]) );
	Register[0] ^= ((Register[5] ^ Register[11]) ^ (Register[24] + Register[23]) ^ (Register[29] + Register[23]) ^ (Register[29] - Register[17]) + (Register[12] + Register[16]) ^ (Register[29] - Register[8]) );
	Register[12] ^= ((Register[32] - Register[0]) ^ (Register[24] ^ Register[8]) - (Register[24] ^ Register[14]) ^ (Register[4] ^ Register[7]) - (Register[4] + Register[11]) );
	Register[18] ^= ((Register[19] + Register[22]) ^ (Register[9] ^ Register[16]) - (Register[12] + Register[32]) + (Register[15] - Register[9]) );
	Register[28] ^= ((Register[30] ^ Register[0]) - (Register[29] - Register[16]) ^ (Register[15] ^ Register[32]) ^ (Register[4] ^ Register[20]) ^ (Register[18] ^ Register[23]) - (Register[22] ^ Register[23]) - (Register[13] - Register[26]) );
	Register[15] ^= ((Register[10] + Register[22]) ^ (Register[19] ^ Register[11]) ^ (Register[22] - Register[2]) + (Register[0] - Register[25]) + (Register[17] - Register[17]) );
	Register[21] ^= ((Register[7] + Register[13]) - (Register[28] - Register[2]) ^ (Register[27] + Register[5]) + (Register[24] + Register[19]) );
	Register[16] ^= ((Register[21] - Register[14]) ^ (Register[26] ^ Register[17]) ^ (Register[15] ^ Register[7]) ^ (Register[19] + Register[13]) - (Register[14] ^ Register[24]) - (Register[17] + Register[18]) ^ (Register[15] - Register[8]) );
	Register[31] ^= ((Register[29] - Register[17]) ^ (Register[11] ^ Register[19]) + (Register[5] - Register[20]) - (Register[20] + Register[17]) + (Register[21] ^ Register[25]) ^ (Register[28] - Register[0]) );
	Register[1] ^= ((Register[27] + Register[17]) + (Register[14] - Register[29]) + (Register[23] - Register[30]) - (Register[32] + Register[13]) ^ (Register[16] ^ Register[12]) );
	Register[17] ^= ((Register[14] ^ Register[29]) ^ (Register[11] + Register[1]) ^ (Register[21] ^ Register[24]) + (Register[9] + Register[28]) ^ (Register[18] + Register[25]) + (Register[20] + Register[29]) + (Register[29] ^ Register[3]) );
	Register[6] ^= ((Register[18] + Register[9]) + (Register[15] ^ Register[3]) ^ (Register[14] ^ Register[20]) + (Register[8] + Register[11]) );
	Register[25] ^= ((Register[7] + Register[14]) ^ (Register[32] - Register[18]) + (Register[21] - Register[16]) + (Register[1] + Register[1]) - (Register[22] + Register[28]) );
	Register[11] ^= ((Register[19] + Register[26]) - (Register[9] - Register[25]) + (Register[6] ^ Register[6]) ^ (Register[19] + Register[26]) ^ (Register[30] - Register[12]) );
	Register[13] ^= ((Register[5] ^ Register[20]) - (Register[23] - Register[10]) + (Register[3] ^ Register[9]) ^ (Register[0] ^ Register[0]) + (Register[29] ^ Register[4]) );
	Register[14] ^= ((Register[6] + Register[6]) ^ (Register[23] + Register[21]) - (Register[2] - Register[10]) ^ (Register[32] + Register[26]) ^ (Register[3] + Register[7]) );
	Register[7] ^= ((Register[3] + Register[20]) + (Register[23] + Register[26]) - (Register[20] - Register[19]) - (Register[16] - Register[11]) );
	Register[4] ^= ((Register[14] - Register[19]) + (Register[13] ^ Register[31]) + (Register[9] + Register[5]) - (Register[20] + Register[19]) );
	Register[19] ^= ((Register[30] - Register[27]) ^ (Register[20] - Register[23]) ^ (Register[15] - Register[6]) ^ (Register[29] ^ Register[27]) ^ (Register[18] - Register[26]) - (Register[3] - Register[24]) - (Register[5] - Register[3]) );
	Register[26] ^= ((Register[32] - Register[18]) - (Register[19] - Register[1]) ^ (Register[0] + Register[11]) - (Register[32] - Register[31]) - (Register[18] + Register[21]) );
	Register[27] ^= ((Register[30] ^ Register[20]) + (Register[7] - Register[3]) ^ (Register[1] - Register[24]) - (Register[31] ^ Register[12]) ^ (Register[28] + Register[21]) ^ (Register[9] ^ Register[8]) - (Register[21] - Register[28]) );
	Register[8] ^= ((Register[27] ^ Register[26]) ^ (Register[20] ^ Register[9]) + (Register[22] + Register[7]) + (Register[0] + Register[14]) ^ (Register[0] ^ Register[11]) + (Register[31] ^ Register[13]) - (Register[19] + Register[31]) + (Register[21] ^ Register[31]) );
	Register[30] ^= ((Register[4] + Register[5]) + (Register[4] - Register[22]) ^ (Register[31] ^ Register[21]) + (Register[31] - Register[31]) ^ (Register[19] + Register[12]) + (Register[14] + Register[27]) - (Register[19] ^ Register[7]) );
	Register[9] ^= ((Register[30] + Register[20]) + (Register[8] ^ Register[30]) - (Register[6] + Register[28]) - (Register[2] + Register[13]) );
	Register[23] ^= ((Register[5] ^ Register[24]) ^ (Register[19] ^ Register[15]) + (Register[11] + Register[27]) + (Register[25] ^ Register[6]) - (Register[13] + Register[14]) + (Register[21] + Register[2]) - (Register[18] - Register[13]) - (Register[27] + Register[26]) );
	Register[20] ^= ((Register[8] - Register[14]) - (Register[9] - Register[29]) ^ (Register[25] ^ Register[15]) + (Register[29] + Register[16]) ^ (Register[6] + Register[5]) - (Register[28] ^ Register[21]) - (Register[27] + Register[7]) + (Register[5] + Register[11]) );
	for (i = 0 ; i < 32 ; i++)
   {
      Target[Splitter[i]] = Register[i];
   }
}