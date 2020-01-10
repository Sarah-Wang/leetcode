/* https://leetcode.com/problems/roman-to-integer/ */
#include <stdio.h>
#include <string.h>

int romanToInt(char *s)
{
	int sum = 0;
	char *pc = NULL;
	char *pn = NULL;

	for (pc = s; *pc != 0; pc++) {
		switch (*pc) {
		case 'C':
			pn = pc + 1;
			if (*pn == 'M' || *pn == 'D')
				sum -= 100;
			else
				sum += 100;
			break;
		case 'X':
			pn = pc + 1;
			if (*pn == 'L' || *pn == 'C')
				sum -= 10;
			else
				sum += 10;
			break;
		case 'I':
			pn = pc + 1;
			if (*pn == 'X' || *pn == 'V')
				sum -= 1;
			else
				sum += 1;
			break;
		case 'M':
			sum += 1000;
			break;
		case 'D':
			sum += 500;
			break;
		case 'L':
			sum += 50;
			break;
		case 'V':
			sum += 5;
			break;
		default:
			break;
		}
	}
	return sum;
}

int main(void)
{
	char in[24] = "MCMXCIV"; //1994
	/* char in[24] = "IX"; //9 */
	/* char in[24] = "LVIII"; //58 */
	/* char in[24] = "IIII" //4 */
	int sum = -1;

	sum = romanToInt(in);
	printf("%s -> %d\n", in, sum);
}
