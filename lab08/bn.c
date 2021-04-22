#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256

void printBN(char *msg, BIGNUM *a)
{
    char *number_str = BN_bn2hex(a);
    printf("%s %s \n", msg, number_str);
    OPENSSL_free(number_str);
}

BIGNUM *eulers(BIGNUM *p, BIGNUM *q, BIGNUM *n)
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *pIn = BN_new();
    BIGNUM *qIn = BN_new();
    BIGNUM *this = BN_new();
    BIGNUM *totient = BN_new();
    BN_dec2bn(&this, "1");
    BN_sub(pIn, p, this);
    BN_sub(qIn, q, this);
    BN_mul(totient, pIn, qIn, ctx);
    BIGNUM *result = BN_new();
    BN_mod_inverse(result, n, totient, ctx);
    BN_CTX_free(ctx);
    return result;
}

int main()
{
    //Task 2
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *priKey = BN_new();
    BIGNUM *pubKey = BN_new();
    BIGNUM *newEnc = BN_new();
    BIGNUM *newDec = BN_new();
    BIGNUM *mod = BN_new();
    BIGNUM *msg = BN_new();
    BN_hex2bn(&priKey, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
    BN_hex2bn(&pubKey, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&mod, "010001");
    BN_hex2bn(&newEnc, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");
    //BN_mod_exp(newEnc, msg, mod, pubKey, ctx);
    // printBN("Encrypted msg: ", newEnc);
    BN_mod_exp(newDec, newEnc, priKey, pubKey, ctx);
    printBN("Decryption msg: ", newDec);
    //encryption = enc(msg, mod, pubKey);
    //printBN("Encrypted message is: ", encryption);
    //decryption = dec(encryption, priKey, pubKey);
    //printBN()
}