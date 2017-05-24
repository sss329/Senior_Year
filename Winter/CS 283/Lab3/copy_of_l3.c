#include <sys/types.h>
#include <dirent.h>
#include<stdio.h> 
#include "csapp.h"
#include<time.h> 

void CheckDelete(char *arg1, char *arg2);
void copy(char *src_f, char *dst_f);

int main(int argc, char *argv[])
{



	DIR *DIR1, *DIR2;
	struct dirent *de1,*de2;
	struct stat stat1, stat2;
	char *path1, *path2;
	int fd1, fd2;

	char *arg1 = argv[1];
	char *arg2 = argv[2];
	DIR1 = opendir(argv[1]);
//	DIR2 = opendir(argv[2]);
	
	while (0 != (de1 = readdir(DIR1))) {


		path2 = malloc(strlen(arg2 + strlen(de1->d_name) +2));
		strcpy(path2, arg2); 
		strcat(path2,"/");
		strcat(path2, de1->d_name); 
		

		if(stat(path2, &stat2) == -1 )
		{

		    path1 = malloc(strlen(arg1 + strlen(de1->d_name) +2));
		    strcpy(path1, arg1); 
		    strcat(path1,"/");
		    strcat(path1, de1->d_name); 
	
		    if(fd1 = open(path1, O_RDONLY) == -1)printf("error1\n");
		    if(fd2 = open(path2, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR) == -1)printf("error4\n");
			    copy(path1,path2); 
			    printf("Found file: %s\n", de1->d_name);
		    free(path1);
		}
		if(!strcmp(de1->d_name, ".") || !strcmp(de1->d_name, ".."))
		{ 	
			// do nothing
		}
		else 
		{
	
		    path1 = malloc(strlen(arg1 + strlen(de1->d_name) +2));
		    strcpy(path1, arg1); 
		    strcat(path1,"/");
		    strcat(path1, de1->d_name); 
		    stat(path1, &stat1);
		
			if(difftime(stat1.st_mtime,stat2.st_mtime) < 0){
	
	
			    printf("file: %s is the most recent from DIR2\n", de1->d_name);
		         	copy(path2,path1); 
			}
			if(difftime(stat1.st_mtime,stat2.st_mtime) > 0){

			    printf("file: %s is the most recent from DIR1\n", de1->d_name);
			 	copy(path1,path2); 
			}

	//		    printf("Found file time: %s\n", de1->d_name);
	
		    free(path1);
		}
		
	   	
	
		free(path2);
	}
			
		CheckDelete(argv[1], argv[2]);
	




	 
	

	closedir(DIR1);
	//closedir(DIR2);




}

void CheckDelete(char *arg1, char *arg2)
{

	struct stat stat1, stat2;
	struct dirent *de1,*de2;
	char *path, *path2;
	DIR *DIR1, *DIR2;
	DIR2 = opendir(arg2);
	
	while (0 != (de2 = readdir(DIR2))) {
		path = malloc(strlen(arg1 + strlen(de2->d_name) +2));
		strcpy(path, arg1); 
		strcat(path,"/");
		strcat(path, de2->d_name); 
		
		if(stat(path, &stat2) == -1 ){

		    path2 = malloc(strlen(arg2 + strlen(de2->d_name) +2));
		    strcpy(path2, arg2); 
		    strcat(path2,"/");
		    strcat(path2, de2->d_name); 
	
		   int ret =  remove(path2);
		   if(ret == 0)printf("deleted\n"); else printf("error\n"); 
			    printf("file deleted: %s\n", de2->d_name);
		    free(path2);
		}
		free(path);
	} 

	closedir(DIR2);
}
void copy(char *src_f, char *dst_f) 
{
   char ch;
   FILE *source, *target;
 
 
   source = fopen(src_f, "r");
 
   if( source == NULL )
   {
      printf("You failed...\n");
      
   }
 
   target = fopen(dst_f, "w");
 
   if( target == NULL )
   {
      fclose(source);
      printf("failed again\n");
   }
 
   while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, target);
 
   printf("File copied successfully.\n");
 
   fclose(source);
   fclose(target);
 
}

