void printLLNumber(uint64_t n, uint8_t base)
{
unsigned char buf[64];
unsigned int i = 0;

if (n == 0){
Serial.print((char)'0');
return;
}
while (n > 0) 
{
buf[i++] = n % base;
n /= base;
}
for (; i > 0; i--)
Serial.print((char) (buf[i - 1] < 10 ?
'0' + buf[i - 1] :
'A' + buf[i - 1] - 10));
}
