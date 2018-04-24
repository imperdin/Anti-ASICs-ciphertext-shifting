#include "Variant256.h"


void HexToBytes(unsigned char* Target,unsigned char* Base) // No Error Checking
{
   int i;
   unsigned char Tmp;
   unsigned char c;
   for (i = 0 ; i < strlen(Base)-1; i += 2)
   {
      c = Base[i];
      if(c >= '0' && c <= '9')
            Tmp = ((c - '0')<< 4);
        else if (c >= 'A' && c <= 'F') 
            Tmp = ((10 + (c - 'A'))<< 4);
        else if (c >= 'a' && c <= 'f')
             Tmp = ((10 + (c - 'a'))<< 4);
             
      c = Base[i+1];
      if(c >= '0' && c <= '9')
            Tmp += (c - '0');
        else if (c >= 'A' && c <= 'F') 
            Tmp += (10 + (c - 'A'));
        else if (c >= 'a' && c <= 'f')
             Tmp += (10 + (c - 'a'));
      Target[(i==0)? 0 : i/2 ] = Tmp;
   }
}

void main()
{
   unsigned char Buffer[65];
   unsigned char CipherText[32];
   unsigned char ShiftedCipherText[32];
   int i;
   strcpy(Buffer,"834267f3ba3914325f7b218a9c69c9550e7a2f1f69690b0b4d48bbcc3fea3b0b");
   HexToBytes(CipherText,Buffer);
   for (i = 0 ; i < 32 ; i++)
   {
      printf("%02x",CipherText[i]);
   }
   printf("\n");
   ShiftCipherText(Buffer,CipherText);
   UnShiftCipherText(CipherText,Buffer);
   for (i = 0 ; i < 32 ; i++)
   {
      printf("%02x",CipherText[i]);
   }
   printf("\n");
}
