//
// Created by Colin Cassens on 2019-04-01.
//

#include "sorting.h"

//Initialize Files
int main(int argc, char ** argv);
long * Load_Into_Array(char * Filename, int * size);

int main(int argc, char ** argv)
{
    if(argc != 4)
    {
        return EXIT_FAILURE;
    }

    char * q = "-q";
    char * m = "-m";
    char * input1 = argv[1];

    //Determine the size of the file
    FILE * infile = fopen(argv[2],"rb");
    fseek(infile, 0, SEEK_END);
    int file_len = ftell(infile);
    int size = file_len / sizeof(long);
    fclose(infile);

    //load the unsorted array from the file
    long * array = Load_Into_Array(argv[2], &size);
    if(strcmp(input1,q) == 0){
        //Invoke Quicksort

    }
    else if(strcmp(input1,m) == 0){
        //Invoke MergeSort
        Merge_Sort(array, size);
    }
    //Save the array to the output file
    //long * Save_From_Array(argv[3], array, size);

    return EXIT_SUCCESS;
}


long * Load_Into_Array(char * Filename, int * size)
{
    //initialize the array
    long * array = calloc(*size,sizeof(long));
    FILE * infile = fopen(Filename,"rb");   //Open the file
    int i;
    for(i = 0; i < *size; i++){
        fread(&array[i],sizeof(long),1,infile); //Save the long ints to the array
    }
    fclose(infile); //Close the file
    return array;   //Return the array
}