#include <string.h>
#include <stdio.h>
#include "tokenizer.h"
#include "malloc.h"

int space_char(char c){
  if(c == ' ' || c == '\t'){
    return 1;
  }else{
    return 0;
  }
}

int non_space_char(char c){
  return !space_char(c);
}

char *word_start(char *str){
  while(*str != '\0'){
    if(non_space_char(*str)){
      return str;
    }else if(*str == '\0'){
      return str;
    }else{
      str++;
      continue;
    }
  }
}

char *word_terminator(char *word){
  while(*word != '\0'){
    if(space_char(*word)){
       return word;
      }else{
	word++;
      }
  }
}

int count_words(char *str){
  int count=0;
  while(*str != '\0'){
    if(strlen(str) == 0){
      return 0;
      break;
    }else if(non_space_char(*str)){
      str++;
    }else if(space_char(*str)){
      count++;
      str++;
    }
    if(*str == '\0'){
      count++;
      break;
    }
  }

  return count;
}

char *copy_str(char *inStr, short len){
  char *scopy = malloc((len + 1) * sizeof(char)), c;
  int sindex = 0;

  do{
    c = *(scopy + sindex) = *(inStr + sindex);
    sindex++;
  } while(c);
    return scopy;
}

char **tokenize(char *str){
  int count = count_words(str);
  char **tokens[count];
  int tindex = 0;
  while(*str != '\0'){
    char *start = word_start(str);
    if(*start != '\0'){
      char *copy = start;
      copy = word_terminator(copy);
      int len = copy - start;
      **(tokens+tindex) = copy_str(str, len);
      tindex++;
    }
  }
  return *tokens;
}

void print_tokens(char **tokens){
  if(tokens != 0){
    printf("%[^\n]s", tokens);
  }
}

