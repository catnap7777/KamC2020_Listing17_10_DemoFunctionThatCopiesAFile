
//Listing 17.10 A function that copies a file; page 448

//How to specify path?

#include <stdio.h>

int file_copy(char *kamoldname, char *kamnewname);

int main(void)
{
    char source[80];
    char destination[80];

    //get the source and destination names
    // ...use kamfile2.txt for "old file" to copy from ...
    // ...use kamListing17_10.txt
    printf("\nEnter the source file (full filename with txt extension): \n");
    gets(source);
    printf("\nThe file you entered is: ");
    printf(source);
    printf("\n");
    printf("\nEnter the destination file (full filename with txt extension): \n");
    gets(destination);

    if(file_copy(source,destination) == 0)
        puts("Copy operation successful!\n\n");
    else
        fprintf(stderr,"Error during copy operation..\n\n");

    return 0;

}

int file_copy(char *kamoldname, char *kamnewname)
{
    FILE *fold, *fnew;
    int c;

    //open the source file for reading in binary mode
    if((fold = fopen(kamoldname, "rb")) == NULL)
        return -1;
    //open the destination file for writing in binary mode
    if((fnew = fopen(kamnewname, "wb")) == NULL)
    {
        fclose(fold);
        return -1;
    }

    //read one byte at a time from the source; if end of file
    //  has not been reached, write the byte to the destination

    while(1)
    {
        c = fgetc(fold);
        if(!feof(fold))
            fputc(c,fnew);
        else
            break;
    }

    fclose(fold);
    fclose(fnew);

    return 0;
}
