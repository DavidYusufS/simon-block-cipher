//   simonKey64_128(jumlah m,jumlah round, kunci)
void simonKey48_72(int SIMON_M,int SIMON_T,uint32_t *k)
{
  uint32_t tmp,tmp2;
    for ( i=SIMON_M ; i<SIMON_T ; i++ )
    {  
        tmp = ROR_24(k[i-1],3);       
        if(SIMON_M==4)tmp2 = tmp ^ k[i-3];
        else{tmp2=tmp;}  
        ROR_24(tmp2,1);
        tmp = tmp2 ^ ROR_24(tmp2,1);
        k[i] = (~k[i-SIMON_M]&0x00ffffff) ^ tmp ^ z[0][i-SIMON_M] ^ 3;
//        Serial.print(i);Serial.print(". ");
//        Serial.println(k[i],HEX);
    }
}

void simonEnc48_72(int SIMON_M,int SIMON_T,uint32_t *key,uint32_t *cword)
{
  uint32_t crypt[1];
  u32 tmp;
  crypt[0]= pt64[0];
  crypt[1]= pt64[1];
//        Serial.print(crypt[0],HEX);
//        Serial.print(" ");
//        Serial.println(crypt[1],HEX);
  for ( i=0 ; i<SIMON_T ; i++ )
    {
        tmp = crypt[0];
        crypt[0] = crypt[1] ^ ((ROL_24(crypt[0],1)) & (ROL_24(crypt[0],8))) ^ (ROL_24(crypt[0],2)) ^ key[i];
        crypt[1] = tmp;
    }
//        Serial.print(crypt[0],HEX);
//        Serial.print(" ");
//        Serial.println(crypt[1],HEX);
}
