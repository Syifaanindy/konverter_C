#include <stdio.h>
#include <string.h>


char* namaBase(int x) {
    switch(x) {
        case 1: return "BINER";
        case 2: return "OKTAL";
        case 3: return "DESIMAL";
        case 4: return "HEXA";
        default: return "UNKNOWN";
    }
}


// Biner ke Desimal
int fromBinary(char *bin) {
    int result = 0;
    int len = strlen(bin);
    int power = 1;

    printf("\n--- LANGKAH BINER -> DESIMAL ---\n");

    for(int i = len - 1; i >= 0; i--) {
        int digit = bin[i] - '0';
        printf("%c X %d = %d\n", bin[i], power, digit * power);
        result += digit * power;
        power *= 2;
    }
    return result;
}

// Oktal ke Desimal
int fromOctal(char *oct) {
    int result = 0;
    int len = strlen(oct);
    int power = 1;

    printf("\n--- LANGKAH OKTAL -> DESIMAL ---\n");

    for(int i = len - 1; i >= 0; i--) {
        int digit = oct[i] - '0';
        printf("%c × %d = %d\n", oct[i], power, digit * power);
        result += digit * power;
        power *= 8;
    }
    return result;
}

// Manual konversi string ke integer (Desimal)
int fromDecimal(char *str) {
    int result = 0;

    printf("\n--- LANGKAH DESIMAL ---\n");

    for(int i = 0; str[i] != '\0'; i++) {
        printf("%d -> result = %d * 10 + %d\n", 
            str[i] - '0', result, str[i] - '0');

        result = result * 10 + (str[i] - '0');
    }
    return result;
}

// Hexa ke Desimal
int fromHexa(char *hex) {
    int result = 0;
    int len = strlen(hex);
    int power = 1;

    printf("\n--- LANGKAH HEXA -> DESIMAL ---\n");

    for(int i = len - 1; i >= 0; i--) {
        char c = hex[i];
        int value;

        if(c >= '0' && c <= '9') value = c - '0';
        else if(c >= 'A' && c <= 'F') value = c - 'A' + 10;
        else value = c - 'a' + 10;

        printf("%c (%d) × %d = %d\n", c, value, power, value * power);

        result += value * power;
        power *= 16;
    }
    return result;
}

// Desimal ke Biner
void toBinary(int dec) {
    printf("\n--- LANGKAH DESIMAL -> BINER ---\n");

    if(dec == 0) { printf("0"); return; }

    int arr[64], i = 0, temp = dec;

    while(temp > 0) {
        printf("%d / 2 = %d, sisa = %d\n",
            temp, temp / 2, temp % 2);

        arr[i++] = temp % 2;
        temp /= 2;
    }

    for(int j = i - 1; j >= 0; j--) printf("%d", arr[j]);
}

// Desimal ke Oktal
void toOctal(int dec) {
    printf("\n--- LANGKAH DESIMAL -> OKTAL ---\n");

    if(dec == 0) { printf("0"); return; }

    int arr[64], i = 0, temp = dec;

    while(temp > 0) {
        printf("%d / 8 = %d, sisa = %d\n",
            temp, temp / 8, temp % 8);

        arr[i++] = temp % 8;
        temp /= 8;
    }

    for(int j = i - 1; j >= 0; j--) printf("%d", arr[j]);
}


void toHexa(int dec) {
    printf("\n--- LANGKAH DESIMAL -> HEXA ---\n");

    if(dec == 0) { printf("0"); return; }

    char arr[64];
    int i = 0, temp = dec;

    while(temp > 0) {
        int r = temp % 16;
        char digit = (r < 10) ? (r + '0') : (r - 10 + 'A');

        printf("%d / 16 = %d, sisa = %c\n",
            temp, temp / 16, digit);

        arr[i++] = digit;
        temp /= 16;
    }

    for(int j = i - 1; j >= 0; j--) printf("%c", arr[j]);
}

int main() {
    char input[100];
    int base, target;
    int decimal = 0;

    printf("=== PROGRAM KONVERSI BILANGAN ===\n");
    printf("1. Biner\n");
    printf("2. Oktal\n");
    printf("3. Desimal\n");
    printf("4. Hexadesimal\n");

    printf("\nInput basis bilangan asal (1-4): ");
    scanf("%d", &base);

    printf("Masukkan angka: ");
    scanf("%s", input);

    printf("Input basis bilangan tujuan (1-4): ");
    scanf("%d", &target);

   
    printf("\n==============================================\n");
    printf("      PROSES %s -> %s\n", namaBase(base), namaBase(target));
    printf("==============================================\n");

    switch(base) {
        case 1: decimal = fromBinary(input); break;
        case 2: decimal = fromOctal(input); break;
        case 3: decimal = fromDecimal(input); break;
        case 4: decimal = fromHexa(input); break;
        default: printf("Base asal tidak valid!"); return 0;
    }

    printf("\nHASIL DESIMAL = %d\n", decimal);

    printf("\nHASIL AKHIR (%s): ", namaBase(target));

 
    switch(target) {
        case 1: toBinary(decimal); break;
        case 2: toOctal(decimal); break;
        case 3: printf("%d", decimal); break;
        case 4: toHexa(decimal); break;
        default: printf("Base tujuan tidak valid!");
    }

    printf("\n\n");
    return 0;
}
