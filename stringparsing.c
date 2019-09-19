/*
----------------------------DESCRIPTION---------------------
Problem Specification
We will implement a shell program soon. To that end, you should firstly make the shell program to understand user inputs and commands.

In this project, the framework passes input strings, and your task is to split the input strings into command tokens. A string is defined as a sequence of characters which is terminated with \0. A command token is defined as a sequence of characters without whitespaces, where the whitespaces include spaces(' ') and tab characters('\t').

For example, if the input string is " Hello world ", the command tokes are "Hello" and "world". Note that the tokens do not include any space characters. Another example is for an input string " cp a.out pa0.c /tmp "; it should be broken into "cp", "a.out", "pa0.c", and "/tmp".

This feature should be implemented in parse_command() function. The user input is passed through command. After parsing command into tokens, the tokens should be assigned to tokens[] in order, which is passed as the argument of the parse_command() function. Also, the number of tokens should be assigined to *nr_tokens which will be used by the framework.

Below diagram illustrates a correct result for an input string " ls -al /home/sanghoon ". Note that each token is also a string which is terminated with \0.

char *command   --> "  ls  -al   /home/sanghoon "
 
*nr_tokens = 3
tokens[0]  -->  "ls"
tokens[1]  -->  "-al"
tokens[2]  -->  "/home/sanghoon"
tokens[3]... = NULL
Skeleton Code
You can start this program assignment by cloning this repository at https://github.com/sslab-ajou/sce213-pa0-2019f. Everything is in pa0.c. Please do not modify the main() function, but implement your code in parse_command() function.

All submission and grading are done automatically through https://sslab.ajou.ac.kr/pasubmit. Please follow the instruction explained in the class. Note that input file in the provided code contains the input sequence for the grading.

Restrictions
You should not use any string manipulation functions from any libraries. The banned functions include strtok, strtok_r, strlen, fscanf and/or similars. This implies that you should implement your own string manipulation functions if it is needed. You will get 0 point if you use any of them. Note that malloc() and free() are not string manipulation functions and OK to use.
Do not fprintf(stderr ...) otherwise the grading system cannot grade your submission properly.
-----------------------------------END----------------------------------------------
*/

/**********************************************************************
 * Copyright (c) 2019
 *  Sang-Hoon Kim <sanghoonkim@ajou.ac.kr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include<string.h>

#define MAX_NR_TOKENS 32	/* Maximum number of tokens in a command */
#define MAX_TOKEN_LEN 64	/* Maximum length of single token */
#define MAX_COMMAND	256		/* Maximum length of command string */


static int parse_command(char *command, int *nr_tokens, char *tokens[])
{
	/* TODO
	 * Followings are example code. You should delete them and implement 
	 * your own code here
	 */
	
  
	    int set=0;
		int fof=0;
		
	  	while(*command!='\0'){ //문자열의 끝인지 확인 끝이 아니라면 반복문 돌자.
		  if(*command=='\n'||*command=='\t'||*command==' '){  //탭 개행 스페이스 일 경우 
			  
			if(set==1){
				
			*command='\0';
			
			(*nr_tokens)=(*nr_tokens)+1; // 다음 토큰으로 넘어가기 
			
			set=0; //탭,개행,스페이스 에 널 대입하고 다음 문자열 시작을 알린다.
			
			
		  }
		  
		  }
		else if(set==0){           //문자열이 시작 
			if(fof==0){ //널 나오기 전까지 대입  
			
			tokens[*nr_tokens]=command; //토큰 넘어가면서 저장한다.
			
			}
			set=1; //문자열 시작하고 탭 만나면  그 부분에 널 넣어주기   
			
			

		}
		
		command++; //조건 에 부합한 경우 탭 ,개행, 스페이스바를 넘기자. 아닌경우 널 까지 다음문자 저장. 하나씩 이동.
		
		  }
	return 0;


}



/***********************************************************************
 * The main function of this program. SHOULD NOT CHANGE THE CODE BELOW
 */
int main(int argc, const char *argv[])
{
	char line[MAX_COMMAND] = { '\0' };
	FILE *input = stdin;

	if (argc == 2) {
		input = fopen(argv[1], "r");
		if (!input) {
			fprintf(stderr, "No input file %s\n", argv[1]);
			return -EINVAL;
		}
	}

	while (fgets(line, sizeof(line), input)) {
		char *tokens[MAX_NR_TOKENS] = { NULL };
		int nr_tokens= 0;


		parse_command(line, &nr_tokens, tokens);

		fprintf(stderr, "nr_tokens = %d\n", nr_tokens);
		for (int i = 0; i < nr_tokens; i++) {
			fprintf(stderr, "tokens[%d] = %s\n", i, tokens[i]);
		}
		printf("\n");
	}

	if (input != stdin) fclose(input);

	return 0;
}
