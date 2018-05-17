#include <stdio.h>

unsigned char FSR(unsigned char x) {
   unsigned char oldbit0 = x & 0x1; /* extract bit 0 */
   unsigned char r = x >> 1;        /* shift right   */
   unsigned char newbit7 = oldbit0 << 7; /* move bit0 to the bit7 pos */
   r = r | newbit7; /* rotate the old value of bit 0 into the bit 7 pos */
   return r;
}
unsigned char prng(unsigned char x, unsigned char pattern) {
        unsigned char new = FSR(x);
        return new ^ pattern;

}

int crypt(char *data,unsigned int size,unsigned char password) {
        if (password == 0 || size <= 0) {
                return -1;

        }
        int i;
        unsigned char tmp = password;
        for (i = 0; i<size; i++){
                tmp = prng(tmp,0xb8);
                data[i] = (data[i]) ^ tmp;


        }
        return 0;
}
