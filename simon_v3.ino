int i;
uint64_t enc[2];
uint64_t pt128[2];
uint32_t pt64[2];
uint32_t skrng,nanti;
 static const unsigned z[5][62] ={{1,1,1,1,1,0,1,0,0,0,1,0,0,1,0,1,0,1,1,0,0,0,0,1,1,1,0,0,1,1,0,1,1,1,1,1,0,1,0,0,0,1,0,0,1,0,1,0,1,1,0,0,0,0,1,1,1,0,0,1,1,0},
                                 {1,0,0,0,1,1,1,0,1,1,1,1,1,0,0,1,0,0,1,1,0,0,0,0,1,0,1,1,0,1,0,1,0,0,0,1,1,1,0,1,1,1,1,1,0,0,1,0,0,1,1,0,0,0,0,1,0,1,1,0,1,0},
                                 {1,0,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,1,0,1,1,0,1,1,0,0,1,1},
                                 {1,1,0,1,1,0,1,1,1,0,1,0,1,1,0,0,0,1,1,0,0,1,0,1,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,1,1,1,0,0,1,1,0,1,0,0,0,0,1,1,1,1},
                                 {1,1,0,1,0,0,0,1,1,1,1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,1,1,0,0,1,0,1,0,0,1,0,0,1,1,1,0,1,1,1,1}};


#define ROL_16(x,n) ( ((x) << (n)) | ((x) >> (16-(n))) )
#define ROR_16(x,n) ( ((x) >> (n)) | ((x) << (16-(n))) )
#define ROL_32(x,n) ( ((x) << (n)) | ((x) >> (32-(n))) )
#define ROR_32(x,n) ( ((x) >> (n)) | ((x) << (32-(n))) )
#define ROL_64(x,n) ( ((x) << (n)) | ((x) >> (64-(n))) )
#define ROR_64(x,n) ( ((x) >> (n)) | ((x) << (64-(n))) )
#define ROL_24(x,n) ( (((x) << (n))&0x00ffffff) | ((x) >> (24-(n))) )
#define ROR_24(x,n) ( ((x) >> (n)) | (((x) << (24-(n)))&0x00ffffff) )
#define ROL_48(x,n) ( (((x) << (n))&0x0000ffffffffffff) | ((x) >> (48-(n))) )
#define ROR_48(x,n) ( ((x) >> (n)) | ((x << (48-n))&0x0000ffffffffffff) )

void setup(){
  //setup awal 
  uint16_t key32[32];
  uint32_t key64[44];
  uint64_t key128[72];
  uint32_t u65[1];
  uint64_t pt96[1];
  uint16_t simon32[1];
  Serial.begin(9600);
  
  //simon 32_64 key
  key32[0]=0x0100;
  key32[1]=0x0908;
  key32[2]=0x1110;
  key32[3]=0x1918;
  Serial.println("simon 32/64");
  skrng = micros();
  //key expansion
  simonKey32_64(4,32,key32);
  //enkripsi simon 
  simonEnc32_64(4,32,key32,0x65656877);
  //simonEnc32_64(4,32,key32,0);
  nanti = micros();
  Serial.println(nanti - skrng);
//  Serial.println("1.simon 32_64");
//  printLLNumber(enc[0],16);
//  Serial.print(" ");
//  printLLNumber(enc[1],16);
//  Serial.println();
//  //mulai dekripsi 
//  simon32[0] = enc[0];
//  simon32[1] = enc[1];
//  simonKey32_64(4,32,key32);
//  simonDec32_64(4,32,key32,simon32);
//  
//  Serial.println("1.simon dekripsi 32_64");
//  printLLNumber(enc[0],16);
//  Serial.print(" ");
//  printLLNumber(enc[1],16);
//  Serial.println();



//  //simon48_72
  key64[0]=0x020100;
  key64[1]=0x0a0908;
  key64[2]=0x121110;
  
  pt64[0]=0x612067;
  pt64[1]=0x6e696c;

  Serial.println("7.simon 48_72");
  skrng = micros();
  //key expansion
  simonKey48_72(3,36,key64);
  //enkripsi
  simonEnc48_72(3,36,key64,pt64);
  nanti = micros();
  Serial.println(nanti - skrng);
//
//  //simon48_96
  key64[0]=0x020100;
  key64[1]=0x0a0908;
  key64[2]=0x121110;
  key64[3]=0x1a1918;
  
  u65[0]=0x726963;
  u65[1]=0x20646e;

  Serial.println("8.simon 48_96");
   skrng = micros();
   //key expansion
  simonKey48_96(4,36,key64);
  //enkripsi
  simonEnc48_96(4,36,key64,u65);
  nanti = micros();
  Serial.println(nanti - skrng);

//  //simon 64_96
  key64[0]=0x03020100;
  key64[1]=0x0b0a0908;
  key64[2]=0x13121110;

  Serial.println("simon 64/96");
  skrng = micros();
  //key expansion
  simonKey64_96(3,42,key64);
  //enkripsi
  simonEnc64_96(3,42,key64,0x6f7220676e696c63);
  nanti = micros();
  Serial.println(nanti - skrng);
  
//  printLLNumber(enc[0],16);
//  Serial.print(" ");
//  printLLNumber(enc[1],16);
//  Serial.println();
//
//  //simon 64_128
  key64[0]=0x03020100;
  key64[1]=0x0b0a0908;
  key64[2]=0x13121110;
  key64[3]=0x1b1a1918;

  Serial.println("simon 64/128");
  skrng = micros();
  //key expansion
  simonKey64_128(4,44,key64);
  //enkripsi
  simonEnc64_128(4,44,key64,0x656b696c20646e75);
  nanti = micros();
  Serial.println(nanti - skrng);
  
//  Serial.println("3.simon 64_128");
//  printLLNumber(enc[0],16);
//  Serial.print(" ");
//  printLLNumber(enc[1],16);
//  Serial.println();
//

//simon96_96
    key128[0]=0x050403020100;
    key128[1]=0x0d0c0b0a0908;
    
    pt96[0]=0x2072616c6c69;
    pt96[1]=0x702065687420;
    Serial.println("9.simon 96_96");
    skrng = micros();
    //key expansion
    simonKey96_96(2,52,key128);
    //enkripsi
    simonEnc96_96(2,52,key128,pt96);    
    nanti = micros();
     Serial.println(nanti - skrng);
     
      //simon96_144
      key128[0]=0x050403020100;
      key128[1]=0x0d0c0b0a0908;
      key128[2]=0x151413121110;
  
      pt96[0]=0x746168742074;
      pt96[1]=0x73756420666f;
      Serial.println("10. simon 96_144");
      skrng = micros();
     //key expansion
      simonKey96_144(3,54,key128);
      //enkripsi
      simonEnc96_144(3,54,key128,pt96);
      nanti = micros();
      Serial.println(nanti - skrng);


//  //simon 128_128
  //key
  key128[0]=0x0706050403020100;
  key128[1]=0x0f0e0d0c0b0a0908;
  //plaintext
  pt128[0]=0x6373656420737265;
  pt128[1]=0x6c6c657661727420;
  Serial.println("simon 128/128");
  skrng = micros();
  //key expansion
  simonKey128_128(2,68,key128);
  //enkripsi
  simonEnc128_128(2,68,key128,pt128);
  nanti = micros();
  Serial.println(nanti - skrng);
//  Serial.println("4.simon 128_128");
//  
//  printLLNumber(pt128[0],16);
//  Serial.print(" ");
//  printLLNumber(pt128[1],16);
//  Serial.println();
//
//  //simon 128_192
  key128[0]=0x0706050403020100;
  key128[1]=0x0f0e0d0c0b0a0908;
  key128[2]=0x1716151413121110;

  pt128[0]=0x206572656874206e;
  pt128[1]=0x6568772065626972;

  Serial.println("5.simon 128_192");
  skrng = micros();
  //key expansion
  simonKey128_192(3,69,key128);
  //enkripsi
  simonEnc128_192(3,69,key128,pt128);
  nanti = micros();
  Serial.println(nanti - skrng);
  
//  
//  printLLNumber(pt128[0],16);
//  Serial.print(" ");
//  printLLNumber(pt128[1],16);
//  Serial.println();
//
//  //simon 128_256
  key128[0]=0x0706050403020100;
  key128[1]=0x0f0e0d0c0b0a0908;
  key128[2]=0x1716151413121110;
  key128[3]=0x1f1e1d1c1b1a1918;
  
  //plain text 
  pt128[0]=0x74206e69206d6f6f;
  pt128[1]=0x6d69732061207369;

  Serial.println("6.simon 128_256");
  skrng = micros();
    //key expansion
  simonKey128_256(4,72,key128);
  //enkripsi
  simonEnc128_256(4,72,key128,pt128);
  nanti = micros();
  Serial.println(nanti - skrng);
    
//  printLLNumber(pt128[0],16);
//  Serial.print(" ");
//  printLLNumber(pt128[1],16);
//  Serial.println();

    
}

void loop() {

}
