#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
	uint32_t buffer[] = {0};
	uint32_t data, first, second;

	FILE *f = fopen(argv[1], "rb");

	fread(buffer, sizeof(uint32_t), 4, f);
	first = data = htonl(*buffer);
	printf("%d(0x%x) + ", data, data);
	fclose(f);

	f = fopen(argv[2], "rb");
	fread(buffer, sizeof(uint32_t), 4, f);
	second = data = htonl(*buffer);
	printf("%d(0x%x) = %d(0x%x)\n", data, data, first+second, first+second);
	fclose(f);
}
