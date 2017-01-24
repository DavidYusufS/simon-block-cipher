//   simonKey128_128(jumlah m,jumlah round, kunci)
void simonKey128_128(int SIMON_M,int SIMON_T,uint64_t *k)
{
  uint64_t tmp,tmp2;
//  printLLNumber(k[0],16);
//  Serial.println();
//  printLLNumber(k[1],16);
//  Serial.println();
    for ( i=SIMON_M ; i<SIMON_T ; i++ )
    {  
        tmp = ROR_64(k[i-1],3);       
        if(SIMON_M==4)tmp2 = tmp ^ k[i-3];
        else{tmp2=tmp;}  
        ROR_64(tmp2,1);
        tmp = tmp2 ^ ROR_64(tmp2,1);
        k[i] = ~k[i-SIMON_M] ^ tmp ^ z[2][(i-SIMON_M)%62] ^ 3;
//        printLLNumber(k[i],16);
//        Serial.println();
    }
}

void simonEnc128_128(int SIMON_M,int SIMON_T,uint64_t *key,uint64_t *cword)
{
  uint64_t crypt[1];
  uint64_t tmp;
  crypt[0]= cword[0];
  crypt[1]= cword[1];
//    Serial.println("enkripsi simon 128 128");
//    printLLNumber(crypt[0],16);
//    Serial.println();
//    printLLNumber(crypt[1],16);
//    Serial.println();
  for ( i=0 ; i<SIMON_T ; i++ )
    {
        tmp = crypt[0];
        crypt[0] = crypt[1] ^ ((ROL_64(crypt[0],1)) & (ROL_64(crypt[0],8))) ^ (ROL_64(crypt[0],2)) ^ key[i];
        crypt[1] = tmp;
//        printLLNumber(crypt[0],16);
//        Serial.print(" ");
//        printLLNumber(crypt[1],16);
//        Serial.println();
    }
    pt128[0]=crypt[0];
    pt128[1]=crypt[1];
}
