#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 256 // ax string length this program can handle
#define MAX_REVIEWS 19000

struct game {
    char title[60];
    char platform[20];
    int score;
    int release_year;
};

// swap function to swap game reviews in the struct array
void swap(struct game *g1, struct game *g2) {
    struct game temp = *g1;
    *g1 = *g2;
    *g2 = temp;
}

// sorts games in ascending order based on the game's score
void quick_Sort(struct game games_Sort[MAX_REVIEWS], int low, int high)
{
    if (low < high)
    {
        int pivot = games_Sort[high].score; // pivot
        int i = (low - 1); // index of smaller element and indicates the right position of pivot found so far

        for (int j = low; j <= high - 1; j++) //
        {
            if (games_Sort[j].score < pivot)
            {
                i++; // increment index of smaller element
                swap(&games_Sort[i], &games_Sort[j]);
            }
        }
        swap(&games_Sort[i + 1], &games_Sort[high]);

        int partition_index = i + 1;

        /*sort the numbers before
        partition and after partition separately*/
        quick_Sort(games_Sort, low, partition_index - 1);
        quick_Sort(games_Sort, partition_index + 1, high);
    }
}


int main(  int argc, char *argv[] )
{
  FILE *game_Reviews_File; // declare file object

  // if no input file detected print error message and exit
  if( argc < 2 ) {
		printf("usage: csv FILE\n");
		return EXIT_FAILURE;
	}

  // Try to open the input file. If there is a problem, report failure and quit
  game_Reviews_File = fopen(argv[1], "r");
  if(!game_Reviews_File) {
     printf("unable to open %s\n", argv[1]);
     return EXIT_FAILURE;
	}

  struct game games[MAX_REVIEWS]; // struct array of type game called games
  char current_Game[MAX_BUFFER]; // char array to store current char array being processed
  char* delim = ","; // , is the delimiter
  int reviews_Processed = 0; // store number of games processed

  fgets(current_Game, MAX_BUFFER, game_Reviews_File); // Read in and discard title line

  // reads in file and assigns data to the members of each element of the struct array
  while(fgets(current_Game, MAX_BUFFER, game_Reviews_File) != NULL){

        strcpy(games[reviews_Processed].title, strtok(current_Game, delim )); // assign title

        strcpy(games[reviews_Processed].platform, strtok(NULL, delim )); // assign platform

        games[reviews_Processed].score = atoi(strtok(NULL, delim )); // convert score from string to int and assign to the struct

        games[reviews_Processed].release_year = atoi(strtok(NULL, delim )); // convert game's release year from string to int and assign to the struct

        reviews_Processed++; // increment the number of games which have been processed
    }

    fclose(game_Reviews_File); // close the game reviews file

    quick_Sort(games, 0, reviews_Processed - 1); // sort the games in ascending order based on their scores

    int game_Index = reviews_Processed;
    int num_Top_Games_Desired = 10;
    int num_Games_Printed = 0;

    while( num_Games_Printed < num_Top_Games_Desired ){
            if (games[game_Index].release_year > 2001){
                printf("%-60s %-20s %-1i %i\n", games[game_Index].title, games[game_Index].platform, games[game_Index].score, games[game_Index].release_year);
                num_Games_Printed++;
            }
            game_Index--;
    }

  return 0;
}

