#!/usr/bin/python
import hashlib, binascii, random
Community_Psedu_Random_Seeds = "4wGLF3DbC0SZs779DMZJQJlxgW8I5SyDSc0nGoMJE2"
Derative = hashlib.pbkdf2_hmac('sha256', Community_Psedu_Random_Seeds, b'Kill All ASICs', 100000)

Splitter = []
Builder = []
Registers = []
RegistersOrder = []
RegistersIndex = []
NumOfRegisters = []
PotencialOperands = ["+","-","^"]
random.seed(Derative)


for i in range(0,32):
   Builder.append(i)

for i in range(0,32):
   Splitter.append(i)

   
for i in range(0,32):
   RegistersOrder.append(i)

   

for i in range(0,32):
   NumOfRegisters.append(random.randint(4, 8)*2)
   Derative = hashlib.pbkdf2_hmac('sha256', Derative, b'Kill All ASICs', 1000)
   random.seed(Derative)
      
random.shuffle(Builder)
Derative = hashlib.pbkdf2_hmac('sha256', Derative, b'Kill All ASICs', 1000)
random.seed(Derative)
random.shuffle(Splitter)
Derative = hashlib.pbkdf2_hmac('sha256', Derative, b'Kill All ASICs', 1000)
random.seed(Derative)
random.shuffle(RegistersOrder)


for i in range(0,32):
   TmpList = []
   for y in range(0,NumOfRegisters[i]):
     while True:
      Tmp = random.randint(0,32)
      Derative = hashlib.pbkdf2_hmac('sha256', Derative, b'Kill All ASICs', 1000)
      random.seed(Derative)
      if (Tmp != RegistersOrder[i]):
         break 
     TmpList.append(Tmp)
   RegistersIndex.append(TmpList)
    

Line = []

for a in range(0,32):
   TmpLine = ("\tRegister[%d] ^= ("%RegistersOrder[a])
   for i in range(0,NumOfRegisters[a],2):
      TmpLine += ("(Register[%s] %c Register[%s]) %c "%(RegistersIndex[a][i],random.choice(PotencialOperands),RegistersIndex[a][i+1],random.choice(PotencialOperands)))
   Derative = hashlib.pbkdf2_hmac('sha256', Derative, b'Kill All ASICs', 1000)
   random.seed(Derative)
   Line.append(TmpLine)
      

Output = """#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void ShiftCipherText(unsigned char* Target,unsigned char* Base)
{
   int i;
   unsigned char Register[32];\n"""

Output += "\tunsigned char Splitter[32] = { "
for i in Splitter:
   Output += ("%s,"%i)
Output = Output[:-1]+" };\n"
Output += "\tunsigned char Builder[32] = { "
for i in Builder:
   Output += ("%s,"%i)
Output = Output[:-1]+" };\n"
Output += """\tfor (i = 0 ; i < 32 ; i++)
   {
      Register[i] = Base[Splitter[i]];
   }\n"""
for a in range(0,32):
   Output += Line[a]
   Output = Output[:-2]+(");\n")
Output +="""\tfor (i = 0 ; i < 32 ; i++)
   {
      Target[i] = Register[Builder[i]];
   }\n}"""
   
#-------------------------------------------Reverse Function---------------
Output += """\n\n\nvoid UnShiftCipherText(unsigned char* Target,unsigned char* Base)
{
   int i;
   unsigned char Register[32];\n"""

Output += "\tunsigned char Splitter[32] = { "
for i in Splitter:
   Output += ("%s,"%i)
Output = Output[:-1]+" };\n"
Output += "\tunsigned char Builder[32] = { "
for i in Builder:
   Output += ("%s,"%i)
Output = Output[:-1]+" };\n"
Output += """\tfor (i = 0 ; i < 32 ; i++)
   {
      Register[Builder[i]] = Base[i];
   }\n"""
for a in range(31,-1,-1):
   Output += Line[a]
   Output = Output[:-2]+(");\n")
Output +="""\tfor (i = 0 ; i < 32 ; i++)
   {
      Target[Splitter[i]] = Register[i];
   }\n}"""

with open("Variant256.h","w") as f:
   f.write(Output)
   
