#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char *haystack, char *needle)
{
	if (needle[0] == '\0')
		return 0;
	if (haystack[0] == '\0')
		return -1;

	int lh, ln, i, m, pos, find;

	lh = strlen(haystack);
	ln = strlen(needle);

	pos = -1;
	find = 0;
	for (i = 0; i < lh - ln + 1; i++) {
		if (haystack[i] == needle[0]) {
			for (m = 0; m < ln; m++) {
				find = 1;
				if (haystack[i+m] == needle[m])
					continue;
				else {
					find = 0;
					break;
				}
			}
			if (find == 1) {
				pos = i;
				break;
			}
		}
	}

	return pos;
}


void main(void)
{
	char *s1 = "({}[)";
	char *s2 = "]";
	char *s3 = "[)";

	printf("res: %d\n", strStr(s1, s2));
	printf("res: %d\n", strStr(s1, s3));
}
