#include <stdio.h>
#include <string.h>
int get_letter_score(char);
int get_word_score(char *);



int main(int argc, char *argv[])
{
	int i;
	int word_scores[1000];
	for(i=1;i<argc;i++)
	{
		word_scores[i]=get_word_score(argv[i]);
	}
	int max=word_scores[1];
	for(int k=1;k<=i;k++)
	{
		if(word_scores[k]>max)
		{
			max=word_scores[k];
		}	
	}
	printf("\n%d\n",max);
	

	return 0;

}

int get_letter_score(char letter)
{
	if(letter>='a'&&letter<='z')return letter-'a'+1;
	return letter-'A'+1;
}
int get_word_score(char str[])
{
	int score=0;
	for(int i=0;i<strlen(str);i++)
	{
		score=score+get_letter_score(str[i]);
	}
	return score;
}

