#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	char str[1000] = {0};
	int i = 0;

	char num[100] = {0};
	int j = 0;

	int min_len = 3;
	int max_val = 0;
	int blocks_cnt = 0;

	int c;
	while ((c = getchar()) != EOF) {
		if (isdigit(c)) {
			str[i++] = num[j++] = c;
		} else {
			blocks_cnt++;
			int n = atoi(num);

			if (n > max_val) {
				max_val = n;
			}

			if (j + 1 < min_len) {
				min_len = j + 1;
			}
			
			if (c == '.') {
				str[i++] = c;
			} else {
				if (blocks_cnt == 4 && ((max_val <= 255) || (min_len == 3))) {
					printf("%s\n", str);
				}

				blocks_cnt = 0;
				min_len = 3;
				max_val = 0;
				i = 0;
				memset(str, 0, 1000);
			}

			j = 0;
			memset(num, 0, 100);
		}
	}

	return 0;
}
