#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 *Location:      Temple University Computer Science
 *Programmer:    Ji Hyun Lee
 *Class:         Introduction to C Programming 1057 Fall 2018 Section 005
 *Assignment:    Lab 9 - CSV and Github
 *Date:          November 14, 2018
 *Version:       1
 *Description:   This function will read in two files and compare the IDs to match the test answers to
 *		 the student's name and merge the two files together to write out one complete file.
*/

void openfiles ( char *fileone, char *filetwo );
int look_in_file ( int, char *file );

#define NUMBER_OF_QUESTIONS 11

int main ( )
{
	openfiles ("newomr.txt", "test_taker_names.txt");

	return EXIT_SUCCESS;
}


/*
* Function:            openfiles ( char *fileone, char *filetwo )
* Description:         Reads in two files, compares the ID, and matches the ID to the student's name and 
*			answers to create a third file.
* Author:              Ji Hyun Lee
* Date:                November 14, 2018
* Inputs:              *fileone - file with answers
		       *filetwo - file with names
* Outputs:             None.
* Globals:             NUMBER_OF_QUESTIONS - number of questions of the test
* Returns:             None.
*/

void openfiles ( char *fileone, char *filetwo )
{
	FILE *ANSWER = fopen(fileone, "r" );
	FILE *NAME = fopen(filetwo, "r");
	FILE *OUT = fopen("full_data.csv", "w");

	int id, count, out, file2, a,i;
	char result[50], answer[NUMBER_OF_QUESTIONS];
	char zero[ ]= "Key";
	char *title[] = {"ID", "Name", "Q1", "Q2", "Q3", "Q4", "Q5", "Q6", "Q7", "Q8", "Q9", "Q10", "Q11"};

	for(i = 0; i < 13; i++){
		if( i == 12 ){
			fprintf(OUT, "%s\n", title[ i ]);
			printf("%s\n", title[i] );
		}
		else {
			fprintf(OUT, "%s, ", title[ i ] );
			printf("%s, ", title[ i ]);
		}
	}

	while (fscanf( ANSWER, "%d", &id ) == 1){

			printf("ID: %5d ", id );
			fprintf( OUT, "%5d,", id);

			fscanf( NAME, "%d", &file2);
	
			if( id == file2 ){
				fscanf( NAME, "%s", result);
				fprintf( OUT, "%s ", result );
				printf("Name: %s ", result);


				fscanf( NAME, "%s", result);
	                        fprintf( OUT, "%s,", result );
				printf("%s, Answers:", result );
	
			}
			else{
				printf("%s, Answers:", zero );
				fprintf( OUT, "%s,", zero);
			}

			for( count = 0; count < NUMBER_OF_QUESTIONS; count++ ){
				fscanf( ANSWER, "%c", &answer[count] );
				printf("%c ", answer[count]);
				if (count == 10 ){
					fprintf( OUT, "%c\n", answer[count]);
				}
				else{
					fprintf( OUT, "%c,", answer[count]);
				}
			}

		puts("");
	}

	return;
}


