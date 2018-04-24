# Anti ASICs cipher text shifting
PoC code to build a ciphertext shifting functions to prevent ASIC acceleration prior to publicationof the Derative used to build the shift mechanisms


The pytohon file builds a simple ciphertext shift functions that relies on the fact that Community_Psedu_Random_Seeds are already known.

Without knowing the Community_Psedu_Random_Seeds, It could take ASIC developers roughly 32! * 3 * 32^16^32 logic gates to properly shift ciphertexts without a more efficient mechanism being discovered

In addition it helps small coins to resist Nicehash hash attacks by being a unique algorithm

The idea is to use the simplicity of random function to modify the shifting code based on the initial seed, however without knowing the initial seed it's infeasible to build every potential outcome with logic gates



After running the python file a new Variant.c file is created with the psedu-random shift mechanism 


