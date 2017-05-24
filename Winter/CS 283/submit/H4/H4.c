
/*  Author: Sunny Shah 
 *  Tile: CS283 H4 
 *  File name: H4.c  
 *****************************************************************************************
 *****************************************************************************************
 */
#include <sys/types.h>
#include <dirent.h>
#include<stdio.h> 
#include "csapp.h"
#include<string.h>
#include<time.h> 
//function prototypes 
void FileCheck(char *arg1, char *arg2, char *arg3, char *arg4);
void doit(char *path, char *arg1, char *arg2, char *arg3);
//main 
int main(int argc, char *argv[])
{
	//check the files from DIR1 to DIR2
	FileCheck(argv[1],argv[2],argv[3],argv[4]);

}
//FileCheck Funtion 
void FileCheck(char *arg1, char *arg2, char *arg3, char *arg4)
{

	DIR *DIR1;
	FILE *fp;
	struct dirent *de1;
	struct stat stat1, stat2;
	char *path, *path2;
	int fd1, fd2;
	int n;	
	rio_t rio; 
	char buf[MAXLINE], newbuff[MAXLINE];

	//open DIR1
	DIR1 = opendir(arg1);
	//read through DIR1 until empty 
	while (0 != (de1 = readdir(DIR1))) {
		//contruct DIR2 path 
		
		char path3[1024];
		int len = snprintf(path3, sizeof(path3)-1, "%s/%s",arg1,de1->d_name);
		path3[len] =0;	
		stat(path3,&stat1);
 
	//only continue if the path points to a regular file 
	if(S_ISREG(stat1.st_mode) && strstr(de1->d_name, ".txt")) 
	{
	
	
		printf("Found file: %s\n", de1->d_name);
		doit(path3, arg2, arg3, arg4); 
		
	 }
	
	}

	free(path);
	closedir(DIR1);
}
//function that reaplces the strings or places the strings int he args 
void doit( char *path, char *arg1, char *arg2, char *arg3) 
{
	//varaibles 
	FILE *fp1, *fp2; 
	char *word,*word2, *fname;
	char string[MAXLINE]; 
	char *replace; 
	char temp[] = "temp.txt", *ptr1, *ptr2; 
	fname = path; 
	word = arg1;
	replace = arg2; 
	word2 = arg3;
 	//open files one that the path is given and the temp to swap to
	fp1 = fopen(path, "r"); 
	fp2 = fopen(temp, "w");
	
	//until we reach the end of file do what needs to be done
        while (!feof(fp1)) {
                strcpy(string, "\0");
	//read each line in the file 
         fgets(string, MAXLINE, fp1);

		//function that will replace the string if found using pointers and strstr 
                if (strstr(string, word)) 
		{
                        ptr2 = string;
                        while (ptr1 = strstr(ptr2, word)) {
                                while (ptr2 != ptr1) {
                                        fputc(*ptr2, fp2);
                                        ptr2++;
                                }
                                ptr1 = ptr1 + strlen(word);
				printf("replacing %s\n" , word);  
				printf("with %s\n" , replace);  
                                fprintf(fp2, "%s", replace);
                                ptr2 = ptr1;
                        }

                        while (*ptr2 != '\0') {
                                fputc(*ptr2, fp2);
                                ptr2++;
                        }
                }
		//this function will place the string infront of the third argument given  
                if (strstr(string, word2)) 
		{
                        ptr2 = string;
			fputs(word, fp2); 
                        while (ptr1 = strstr(ptr2, word2)) {
                                while (ptr2 != ptr1) {
                                        fputc(*ptr2, fp2);
                                        ptr2++;
                                }
                                //ptr1 = ptr1 ++;
                                fprintf(fp2, "%s", word);
                                ptr2 = ptr1;
                        }

                        while (*ptr2 != '\0') {
                                fputc(*ptr2, fp2);
                                ptr2++;
                        }
                }

		else 
		{
                        fputs(string, fp2);
                }
        }

        fclose(fp1);
        fclose(fp2);
	//Replace the file 
        remove(fname);
        rename(temp, fname);

}
