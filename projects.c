#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//for simple print scan etc
#include <stdlib.h>//for q sort fun
#include <string.h>//for str func
#define wordlen 20
#define total 15

int readline(char str[], int n);
int compare(const void* p, const void* q);
int main() {
	char* wordsarr[total], words[wordlen + 1]; int num_words = 0, d;
	for (;;) {
		if (num_words == total)break;

		printf("\nEnter Cars Name %d: ",num_words+1);
		readline(words, wordlen); if (strlen(words) == 0)break;

		wordsarr[num_words] = malloc(strlen(words) + 1);
		if (wordsarr[num_words] == NULL) { printf("\n ------ERROR----\n not enough space left."); break; }
		strcpy(wordsarr[num_words], words);
		num_words++;
	}
	qsort(wordsarr, num_words, sizeof(char *), compare);
	printf("\nnumber of words entered before sorting are %d", num_words);
	printf("\n ------Cars Name In Sorted Order-----\n");
	for (d = 0; d < num_words; d++) {
		printf("%d. %s   (with word length of : %zu)\n", d+1, wordsarr[d],strlen(wordsarr[d]));
	}
	return 0;

}
int readline(char str[], int n) {
	int i = 0, ch;
	
		while ((ch = getchar()) != '\n') 
			if (i < n)
			str[i++] = ch;
			str[i] = '\0';
			return i;
			
}
int compare(const void* p, const void* q) {
	char* str1 = *(char**)p;
	char* str2 = *(char**)q;
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	if (len1 != len2)return len1-len2;
	return strcmp(str1, str2);


}