//   simonKey64_96(jumlah m,jumlah round, kunci)
void simonKey64_96(int SIMON_M,int SIMON_T,uint32_t *k)
{
  uint32_t tmp,tmp2;
    for ( i=SIMON_M ; i<SIMON_T ; i++ )
    {  
        tmp = ROR_32(k[i-1],3);       
        if(SIMON_M==4)tmp2 = tmp ^ k[i-3];
        else{tmp2=tmp;}  
        ROR_32(tmp2,1);
        tmp = tmp2 ^ ROR_32(tmp2,1);
        k[i] = ~k[i-SIMON_M] ^ tmp ^ z[2][i-SIMON_M] ^ 3;
        //Serial.println(k[i],HEX);
    }
}

void simonEnc64_96(int SIMON_M,int SIMON_T,uint32_t *key,uint64_t cword)
{
  uint32_t crypt[1];
  u32 tmp;
  crypt[0]= cword >>32;
  crypt[1]= cword;
  for ( i=0 ; i<SIMON_T ; i++ )
    {
        tmp = crypt[0];
        crypt[0] = crypt[1] ^ ((ROL_32(crypt[0],1)) & (ROL_32(crypt[0],8))) ^ (ROL_32(crypt[0],2)) ^ key[i];
        crypt[1] = tmp;
    }
    enc[1]=crypt[1];
    enc[0]=crypt[0];
    
}
