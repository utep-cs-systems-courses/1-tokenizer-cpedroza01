#include "stdio.h"
#include "tokenizer.h"

void main() {
  char inStr[30];
  puts("Please input your string:");
  scanf("%[^\n]s", inStr);
  printf("%s\n", inStr);

 int count = count_words(inStr);
 printf("%d\n", count);

 char *copy;
 copy = &(*copy_str(inStr, sizeof(inStr)));
 printf("%s\n)", copy);

 char **tokens[10];
 *tokens = (tokenize(inStr));
 print_tokens(*tokens);
}

