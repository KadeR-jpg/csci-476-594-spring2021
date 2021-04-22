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

BIGNUM *enc(BIGNUM *toEnc, BIGNUM *mod, BIGNUM *key)
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *encoding = BN_new();
    BN_mod_exp(encoding, toEnc, mod, key, ctx);
    BN_CTX_free(ctx);
    return enc;
}

BIGNUM *dec(BIGNUM *toDec, BIGNUM *mod, BIGNUM *priKey, BIGNUM *pubKey)
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *decoded = BN_new();
    BN_mod_exp(decoded, toDec, priKey, pubKey, ctx);
    BN_CTX_free(ctx);
    return decoded;
}

int main()
{
    //p = F7E75FDC469067FFDC4E847C51F452DF
    //q = E85CED54AF57E53E092113E62F436F4F
    //e = 0D88C3
    //Task 1 stuff
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *p = BN_new();
    BIGNUM *q = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *res = BN_new();
    BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
    BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
    BN_hex2bn(&n, "0D88C3");
    BIGNUM *task1_key = eulers(p, q, n);
    printBN("task 1 private Key is: ", task1_key);
    //End of task one stuff
    //Task 2
    BIGNUM *priKey = BN_new();
    BIGNUM *pubKey = BN_new();
    BIGNUM *mod = BN_new();
    BIGNUM *msg = BN_new();
    BIGNUM *encryption = BN_new();
    BIGNUM *decryption = BN_new();
    BN_hex2bn(&priKey, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
    BN_hex2bn(&pubKey, "DCBFFEE51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&mod, "010001");
    BN_hex2bn(&msg, "74686973206973206120736563726574202d204b616465");
    encryption = enc(msg, mod, pubKey);
    printBN("Encrypted message is: ", encryption);
    decryption = dec(encryption, priKey, pubKey);
    decMsg = BN_bn2hex(decryption);
    printf("Decrypted message");
    printHX(decMsg);

    return 0;
    //Provided Code from Travis.
    // // Initialize a, b, n
    // BN_generate_prime_ex(a, NBITS, 1, NULL, NULL, NULL);
    // BN_dec2bn(&b, "273489463796838501848592769467194369268");
    // BN_rand(n, NBITS, 0, 0);
    // //res = a*b
    // BN_mul(res, a, b, ctx);
    // printBN("a * b = ", res);
    // //res = a^b mod n
    // BN_mod_exp(res, a, b, n, ctx);
    // printBN("ac mod n = ", res);
    // return 0;
}