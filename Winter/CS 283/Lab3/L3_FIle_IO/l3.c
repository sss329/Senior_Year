
/*  Author: Sunny Shah 
 *  Tile: CS283 Lab3 directory sync 
 *  File name: l3.c  
 *****************************************************************************************
 *  Given two directories ./a and ./b, passed as parameters to your program, you are     *
 *  to synchronize them, as follows:                                                     *
 *	-If a file in a does not exist in b, you should replicate it in b.               *
 *	-If a file in b does not exist in a, it should be deleted from b.                *
 *	-If a file exists in both a and b, the file with the most recent modified date / *
 *	 time should be copied from one directory to the other.                          *
 *  Print a log of your program's activities to stdout or stderr.                        *
 *****************************************************************************************
 */
#include <sys/types.h>
#include <dirent.h>
#include<stdio.h> 
#include "csapp.h"
#include<time.h> 
//function prototypes 
void CheckDelete(char *arg1, char *arg2);
void copy(char *src_f, char *dst_f);
void FileCheck(char *arg1, char *arg2);
//main 
int main(int argc, char *argv[])
{
	//check the files from DIR1 to DIR2
	FileCheck(argv[1],argv[2]);
	//Check and Delete file nots in DIR1 but in DIR2
	CheckDelete(argv[1], argv[2]);

}
//FileCheck Funtion 
void FileCheck(char *arg1, char *arg2)
{

	DIR *DIR1;
	struct dirent *de1;
	struct stat stat1, stat2;
	char *path1, *path2;
	int fd1, fd2;
	//open DIR1
	DIR1 = opendir(arg1);
	//read through DIR1 until empty 
	while (0 != (de1 = readdir(DIR1))) {
		//contruct DIR2 path 
		path2 = malloc(strlen(arg1 + strlen(de1->d_name) +2));
		strcpy(path2, arg2); 
		strcat(path2,"/");
		strcat(path2, de1->d_name); 
		//construct DIR1 path 
		path1 = malloc(strlen(arg2 + strlen(de1->d_name) +2));
		strcpy(path1, arg1); 
		strcat(path1,"/");
		strcat(path1, de1->d_name);
		stat(path1,&stat1); 
	//only continue if the path points to a regular file 
	if(S_ISREG(stat1.st_mode)) 
	{
		//if the file does not exits in DIR2 copy it from DIR1
		if(stat(path2, &stat2) == -1 )
		{
	
		    if(fd1 = open(path1, O_RDONLY) == -1)printf("error opening path\n");
		    if(fd2 = open(path2, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR) == -1)printf("error opening file or creating file\n");
			    copy(path1,path2); 
			    printf("Found file: %s\n", de1->d_name);
		}
		//do nothing if name is .. or .
		if(!strcmp(de1->d_name, ".") || !strcmp(de1->d_name, ".."))
		{ 	
			// do nothing
		}
		//compare the file modfied date copy the most recent 
		else 
		{
		
			if(difftime(stat1.st_mtime,stat2.st_mtime) < 0){
	
			    printf("file: %s is the most recent from DIR2 coping to DIR1\n", de1->d_name);
		         	copy(path2,path1); 
			}
			if(difftime(stat1.st_mtime,stat2.st_mtime) > 0){

			    printf("file: %s is the most recent from DIR1 coping to DIR2\n", de1->d_name);
			 	copy(path1,path2); 
			}
		}
		
	   }
	  else
	  {
	    //do nothing 
	  }
	
	}

	free(path1);
	free(path2);
	closedir(DIR1);
}
//Delete function from DIR2 thats not in DIR1
void CheckDelete(char *arg1, char *arg2)
{

	struct stat stat1, stat2;
	struct dirent *de2;
	char *path1, *path2;
	DIR  *DIR2;

	DIR2 = opendir(arg2);
	
	while (0 != (de2 = readdir(DIR2))) {	
		//construct DIR2 path 
		path2 = malloc(strlen(arg1 + strlen(de2->d_name) +2));
		strcpy(path2, arg2); 
		strcat(path2,"/");
		strcat(path2, de2->d_name); 
		//construct DIR1 path 
		path1 = malloc(strlen(arg2 + strlen(de2->d_name) +2));
		strcpy(path1, arg1); 
		strcat(path1,"/");
		strcat(path1, de2->d_name);
		stat(path2,&stat2); 
	  //continue if is a regular file 
	  if(S_ISREG(stat2.st_mode)) 
	  {  

		if(stat(path1, &stat1) == -1 ){
		   int ret =  remove(path2);
		   if(ret == 0) printf("file deleted: %s\n", path2);
		   else printf("error while deleting file: %s\n", de2->d_name); 
		}
       	   } 
	}	
	free(path1);
	free(path2);
	closedir(DIR2);
}
//Copy file function from source to destination target 
void copy(char *src_f, char *dst_f) 
{
   char ch;
   FILE *src, *dst;
 
   //open the source file for reading
   src = fopen(src_f, "r");
   //check if open file failed 
   if(src == NULL )
   {
      printf("You failed on source path\n");
      
   }
   //open destination for write
   dst = fopen(dst_f, "w");
   //if destination failed or not 
   if(dst == NULL )
   {
      fclose(src);
      printf("failed on target path\n");
   }
   //copy to desitination 
   while( ( ch = fgetc(src) ) != EOF )
      fputc(ch, dst);
 
   printf("File copied successfully.\n");
 
   fclose(src);
   fclose(dst);
 
}

