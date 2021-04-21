#include <stdio.h>
#include <string.h>

// Libreria AES obtenida desde: https://github.com/kokke/tiny-AES-c
#include "tiny-AES-c/aes.h"

int main() {
    // Inicializar el string para el mensaje y para la llave.
    uint8_t message[128]; // mensaje de 128 bytes.
    // La llave lleva valores iniciales, con 16 bytes es decir llave de 128 bits.
    uint8_t key[16] = { 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef };

    // Pedir el mensaje.
    printf("Cual es el mensaje?\n");
    fgets((char *) message, 128, stdin);

    // Pedir la llave.
    printf("Cual es la llave?\n");
    fgets((char *) key, 16, stdin);
    putchar('\n');

    // Imprimir el mensaje y la llave dadas.
    printf("Texto en claro:\n%sLlave:\n%s\n", (char *) message, (char *) key);

    // Crear el vector de inicializacion.
    uint8_t initialvector[16] = { 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11 };

    // Contexto usado por la libreria para realizar AES.
    struct AES_ctx ctx;

    // Inicializar la libreria con el vector inicial para ocupar Cypher Block Chaining.
    AES_init_ctx_iv(&ctx, key, initialvector);
    // Encriptar el mensaje e imprimir texto encriptado.
    AES_CBC_encrypt_buffer(&ctx, message, sizeof(message)); // aqui message se encripta.
    printf("El mensaje encriptado es:\n%s\n\n", (char *) message);

    // Inicializar de la libreria con el mismo vector inicial.
    AES_init_ctx_iv(&ctx, key, initialvector);
    // Desencriptar el mensaje e imprimir el texto desencriptado.
    AES_CBC_decrypt_buffer(&ctx, message, sizeof(message)); // message estaba encriptado
    printf("El mensaje desencriptado es:\n%s\n", (char *) message);

    // Terminar.
    return 0;
}
