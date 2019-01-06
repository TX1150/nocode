#include<stdio.h>
#include<aes.h>
#pragma comment(lib,"mbedTLS.lib")

int main(void)
{
	mbedtls_aes_context aes_ctx;
	//��Կ��ֵ  
	unsigned char key[16] = { 0x01,0x02,0x03,0x04,0x06,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x00 };
	//���Ŀռ�  
	unsigned char plain[16] = "aaaaaaaaaa";
	//���ܺ����ĵĿռ�  
	unsigned char dec_plain[16] = { 0 };
	//���Ŀռ�  
	unsigned char cipher[16] = { 0 };
	mbedtls_aes_init(&aes_ctx);
	//���ü�����Կ  
	mbedtls_aes_setkey_enc(&aes_ctx, key, 256);
	printf("\n*********** ����ǰ��%s\n", plain);
	mbedtls_aes_crypt_ecb(&aes_ctx, MBEDTLS_AES_ENCRYPT, plain, cipher);
	//printf("\n*********** ���ܺ�%s\n", cipher);
	printf("\n");
	for (size_t i = 0; i < 10; i++)
		printf("%x\t", cipher[i]);
	printf("\n");
	//���ý�����Կ  
	mbedtls_aes_setkey_dec(&aes_ctx, key, 256);
	mbedtls_aes_crypt_ecb(&aes_ctx, MBEDTLS_AES_DECRYPT, cipher, dec_plain);
	printf("\n*********** ���ܺ�%s\n", dec_plain);
	mbedtls_aes_free(&aes_ctx);
	system("pause");
	return 0;
}