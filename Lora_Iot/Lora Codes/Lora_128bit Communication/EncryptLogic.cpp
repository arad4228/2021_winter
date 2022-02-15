#include <cstdint>
#include <iostream>
#include <cstring>

#include "BUILD/NUCLEO_F446RE/ARMC6/mbed_config.h"
#include "fhss_api.h"
#include "mbedtls/sha256.h"
#include "mbedtls/aes.h"

using namespace std;

class Security{
    public:
    mbedtls_sha256_context AesKey;
    mbedtls_aes_context Ac;
    Security()
    {
        // IV와 AesKey에 대한 hash값들을 위한 초기화.
        // AES(CTR) 모드 init.
        mbedtls_sha256_init(&AesKey);
        mbedtls_sha256_starts(&AesKey, 0);
        mbedtls_aes_init(&Ac);
    }

    uint32_t Read(const int32_t value)
    {
        // SHA256에 넣을 값들을 buffer에 삽입.
        for(int i =0; i < 32 ; i++)
        {
            this->buffer[i] = (unsigned char)appskey[i];
            this->buffer[i+16] = (unsigned char)nwkskey[i];
        }
       
        // SHA256에 buffer의 값을 삽입.
        mbedtls_sha256_update(&AesKey, this->buffer, 32);

        // Buffer로 통해 만들어진 해쉬값을 IV에 복사
        mbedtls_sha256_finish(&AesKey, Aesk);
        mbedtls_sha256_free(&AesKey);

        // 암호화 부분의 ket를 256bi로 저장하고 값은 hash를 통해 구한 Akey를 사용한다.
        mbedtls_aes_setkey_enc(&Ac, Aesk, 256);

        // IV를 설정하기.
        for(int i = 7; i> 0; i--)
            IV[i] = deveui[i];

        // uint32 -> unsigned char로 변경하는 것으로 작성.
        // 4byte to unsigned char 4개에 변경로직 작성이 필요.
        // 128bit로 만들기위해 해당 배열은 미리 초기화를 진행.
        char data[16] = {0,};
        char odata[16] = {0,};
        data[3] = value>>24;
        data[2] = value>>16;
        data[1] = value>>8;
        data[0] = value;

        //mbedtls_aes_crypt_ctr(&Ac, 128, nc , IV, sb,data, odata);

        
        return Ci;
    }

    private:
    unsigned char buffer[32];
    unsigned char Aesk[32];
    uint8_t nwkskey[16] = MBED_CONF_LORA_NWKSKEY;
    uint8_t appskey[16] = MBED_CONF_LORA_APPSKEY;
    uint8_t deveui[7] = MBED_CONF_LORA_DEVICE_EUI;
    unsigned char IV[16];
    uint32_t Ci;
};
