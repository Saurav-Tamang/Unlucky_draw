/* Purpose: To generate numbers randomly and put the generated number into a file.
 * Written by: Saurav Tamang
 * Regd no.: 221208
 * Date: 02/04/2025
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define m 100
#define l 100


int main()
   {
    FILE *f1,*outf2;

    char names[m][l];

    int totalnames=0;


    // To read names from the file file_input
    f1=fopen("file_input","r");
    if(f1==NULL)

        {

         printf("Cannot open the file\n");

         return 1;

	}

    while(fgets(names[totalnames],l,f1))
       
       {
	
	 names[totalnames][strcspn(names[totalnames],"\n")]='\0';   // To remove newline
								   
	 totalnames++;

       }

    fclose(f1);   

    if(totalnames==0)
       
       {
       
         printf("No names found in the fil_input\n");

         return 1;

	}

    srand(time(NULL));

    int randomIndex=rand()%totalnames;  
     
    time_t now = time(NULL);

    struct tm *t = localtime(&now);

    char timestamp[100];

    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", t);	  

    printf("THE UNLUCKY NUMBER AND BHAI IS :\n");      // Display and write to file

    printf("%s\n",names[randomIndex]);

    printf("Selected on: %s\n",timestamp);

    outf2 = fopen("file_output", "a");     // Open output file to save results
					   
    if(outf2==NULL) 

       {

        printf("Cannot create output file!\n");

	return 1;

       } 

    fprintf(outf2, "%2d → %s\n", randomIndex + 1, names[randomIndex]);  

    fclose(outf2);

    printf("\nResults saved to file_output\n");

    return 0;

   }

