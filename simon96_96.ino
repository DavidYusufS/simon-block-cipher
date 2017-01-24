//   simonKey64_128(jumlah m,jumlah round, kunci)
void simonKey96_96(int SIMON_M,int SIMON_T,uint64_t *k)
{
  uint64_t tmp,tmp2;
    for ( i=SIMON_M ; i<SIMON_T ; i++ )
    {  
        tmp = ROR_48(k[i-1],3);       
        if(SIMON_M==4)tmp2 = tmp ^ k[i-3];
        else{tmp2=tmp;}  
        ROR_48(tmp2,1);
        tmp = tmp2 ^ ROR_48(tmp2,1);
        k[i] = (~k[i-SIMON_M]&0x0000ffffffffffff) ^ tmp ^ z[2][i-SIMON_M] ^ 3;
//        Serial.print(i);Serial.print(". ");
//        printLLNumber(k[i],16);
//        Serial.println();
    }
}

void simonEnc96_96(int SIMON_M,int SIMON_T,uint64_t *key,uint64_t *cword)
{
  uint64_t crypt[1];
  uint64_t tmp;
  crypt[0]= cword[0];
  crypt[1]= cword[1];
//        Serial.println("plain text ");
//        printLLNumber(crypt[0],16);
//        Serial.print(" ");
//        printLLNumber(crypt[1],16);
//        Serial.println();
  for ( i=0 ; i<SIMON_T ; i++ )
    {
        tmp = crypt[0];
        crypt[0] = crypt[1] ^ ((ROL_48(crypt[0],1)) & (ROL_48(crypt[0],8))) ^ (ROL_48(crypt[0],2)) ^ key[i];
        crypt[1] = tmp;
//        Serial.print(i);Serial.print(". ");
//        printLLNumber(crypt[0],16);
//        Serial.print(" ");
//        printLLNumber(crypt[1],16);
//        Serial.println();
    }


}
