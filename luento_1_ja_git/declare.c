#include <stdint.h>
#include <stdlib.h>

#include "declare.h"


// Function demonstrating const
void example_function(const int *a, const int *b)
{
    printf("integer a was: %d, interger b was %d\n", a, b);
    return;
}


void loops()
{
    int x = 0;
    while (x < 10) {
        printf("%d\n");
    }

    for (;;) {

    }

    for (int i = 0; i <= 100; i++) {

    }

    int var_1 = 0;
    switch (var_1)
    {
    case 0:
        /* code */
        printf("Oli 0.\n");
        break;
    case 1:
        printf("Oli 1.\n");
        break;
    case 2:
        printf("Oli 2.\n");
        break;
    default:
        printf("Oli jotain muuta.\n");
        break;
    }
}


uint8_t get_mask(uint8_t old_mask)
{
    // 01100000
    0b00000011 << 5;

    // Force bits 5th and 8th bits to true 00001001
    return old_mask | 0b00001001;
}


int main(void)
{
    uint32_t age = 0;
    // Next types are closely equivalent
    char n_1 = 127;
    int8_t n_2 = -127;
    unsigned char n_3 = 41;
    uint8_t n_4 = 123;

    char *string_1 = malloc(100 * sizeof(char));
    if (string_1 == NULL) {
        printf("Muistin osoitus epäonnistui.\n");
    }

    uint64_t *string_2 = calloc(sizeof(uint64_t), 100 * sizeof(uint64_t));

    int n_a = 11;
    int n_b = 22;
    example_function(&n_a, &n_b);

    return 0;
}
