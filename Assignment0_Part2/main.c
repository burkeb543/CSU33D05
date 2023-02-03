#include <stdio.h>

int next_field( FILE *csv, char *buffer, int max_len );

int main(void) {
  FILE * pFile;
  char c;
  pFile=fopen ("students.csv","r");
  
  char word[30];
  int i = 0;
  int n = 0;
  int quote = 0;

  do {
      c = fgetc (pFile);
      if (c == '"'){
        quote++;
        if (quote == 2){
          printf("%s", word);
          quote = 0;
        }
      }
      else if (c != ','){
        word[i] = c;
        i++;
      }
      else if(c == ',' && word[0] == '"')
      {
        word[i] = c;
        i++;
      }
      else{
        n++;
        if (n >= 5 ){
          printf("%s", word);
          printf("\n");
        }
        while (i > 0){
          word[i] = ' ';
          i--;
        }
        word[0] = '\0';
      }
      
    } while (c != EOF);
    fclose (pFile);
  
  return 0;
}


  