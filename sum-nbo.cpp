#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

int processFile(const char *filename, uint32_t *values, int *count, uint32_t *total) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("파일 오류로 열리지 않음.");
        return 0;
    }

    uint32_t buf;
    size_t read = fread(&buf, sizeof(uint32_t), 1, fp);
    fclose(fp);

    if (read != 1) {
        printf("파일의 크기가 4바이트보다 작음.");
        return 0;
    }

    uint32_t host_order = ntohl(buf);
    values[*count] = host_order;
    *total += host_order;
    (*count)++;
    return 1;
}

int main(int argc, char *argv[]) {
    uint32_t total = 0;
    uint32_t values[argc - 1];
    int count = 0;

    for (int i = 1; i < argc; ++i) {
        if (!processFile(argv[i], values, &count, &total)) {
            return 1;
        }
    }

    for (int i = 0; i < count; ++i) {
        printf("%u(0x%08x)", values[i], values[i]);
        if (i < count - 1) printf(" + ");
    }
    printf(" = %u(0x%08x)\n", total, total);
    return 0;
}
