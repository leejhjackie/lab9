#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMES_FILE "names.txt"
#define OMR_FILE   "newomr.txt"
#define OUTPUT_FILE "full.csv"

int main()
{

	FILE *NAMES = fopen( NAMES_FILE, "r" );
	FILE *NEWOMR = fopen( OMR_FILE, "r" );
	FILE *OUT_CSV = fopen( OUTPUT_FILE, "w" );

	char namein[ 300 ][ 50 ];


	// store all the names in the array
	int i = 0;
	while ( fgets( namein[ i ], 50, NAMES ) != NULL ) {
		// namein[ i ][ strlen( namein[ i ] ) - 1 ] = '\0';
		i++;
	}
	printf( "Done.  Count = %d.\n", i );
	fclose( NAMES );

	char gradein[ 50 ];

	// skip the first line, because it's just the answer key
	fgets( gradein, 50, NEWOMR );
	i = 0;
	while( fgets( gradein, 50, NEWOMR ) != NULL ) {
		int j;
		for( j = 0; j < 5; j++ )
			fprintf( OUT_CSV, "%c", gradein[ j ] );
		fputc( ',', OUT_CSV );
		namein[ i ][ strlen( namein[ i ] ) - 1 ] = '\0';
		fputs( namein[i++], OUT_CSV );
		fputc( ',', OUT_CSV );
		for( j = 0; j < 11; j++ ) {
			fputc( gradein[ j + 5 ], OUT_CSV );
			fputc( ',', OUT_CSV );
		}
		fputc( '\n', OUT_CSV );
	}

	return EXIT_SUCCESS;
}
