//   simonKey32_64(jumlah m,jumlah round, kunci)
void simonKey32_64(int SIMON_M,int SIMON_T,uint16_t *k)
{
  uint16_t tmp,tmp2;
    for ( i=SIMON_M ; i<SIMON_T ; i++ )
    {  
        tmp = ROR_16(k[i-1],3);       
        if(SIMON_M==4)tmp2 = tmp ^ k[i-3];
        else{tmp2=tmp;} 
        ROR_16(tmp2,1);
        tmp = tmp2 ^ ROR_16(tmp2,1);
        k[i] = ~k[i-SIMON_M] ^ tmp ^ z[0][i-SIMON_M] ^ 3;
        //Serial.println(k[i],HEX);
    }
}

void simonEnc32_64(int SIMON_M,int SIMON_T,uint16_t *key,uint32_t cword)
{
  uint16_t crypt[1];
  u16 tmp;
  crypt[0]= cword >>16;
  crypt[1]= cword;
  for ( i=0 ; i<SIMON_T ; i++ )
    {
        tmp = crypt[0];
        crypt[0] = crypt[1] ^ ((ROL_16(crypt[0],1)) & (ROL_16(crypt[0],8))) ^ (ROL_16(crypt[0],2)) ^ key[i];
        crypt[1] = tmp;
    }
    enc[1]=crypt[1];
    enc[0]=crypt[0];
    
}



void simonDec32_64(int SIMON_M,int SIMON_T,uint16_t *key,uint16_t *cword)
{
  uint16_t crypt[1];
  u16 tmp;
  crypt[1]= cword[0];
  crypt[0]= cword[1];
  Serial.print(crypt[0],HEX);Serial.print(" ");
  Serial.println(crypt[1],HEX);
  Serial.println("dekripsi");
  for ( i=SIMON_T-1 ; i>=0; i-- )
    {
        tmp = crypt[0];
        crypt[0] = crypt[1] ^ ((ROL_16(crypt[0],1)) & (ROL_16(crypt[0],8))) ^ (ROL_16(crypt[0],2)) ^ key[i];
        crypt[1] = tmp;
        Serial.print(i);Serial.print(". ");
        Serial.print(crypt[0],HEX);Serial.print(" ");
        Serial.println(crypt[1],HEX);
    }
    enc[1]=crypt[1];
    enc[0]=crypt[0];
    
}

