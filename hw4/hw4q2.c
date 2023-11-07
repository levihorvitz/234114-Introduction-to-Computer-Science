#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 52
#define WORDS_ARRAY_SIZE 100
#define MAX_STR_LEN 50
#define LETTERS 26

char encrypt_char(unsigned char key[KEY_SIZE], char ch);
int read_words(char* words[], int size, int max_str_len);
void encrypt_words(char* words[], int num_words, unsigned char key[KEY_SIZE]);
void release_memory(char* words[], int num_words);

void print_words(char* words[], int num_words)
{
    int i;
    for ( i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }
}


int main()
{
    unsigned char key[KEY_SIZE] = {

            '>', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '~', 'S', 'D',
            'F', 'G', '*', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', '+', 'M',
            'm','b','n','v','z','c','@','q','r','u','i','e','r',
            't','o','p','w','$','j','g','d','%','s','f','h','k'
    };
    int num_words =0, i;
    char* words[WORDS_ARRAY_SIZE];

    for ( i = 0; i < WORDS_ARRAY_SIZE; i++) {
        words[i] = NULL;
    }

    num_words = read_words(words, WORDS_ARRAY_SIZE, MAX_STR_LEN);
    if (num_words == -1)
    {
        printf("Failed to read words.\n");
        return 0;
    }
    encrypt_words(words, num_words, key);
    print_words(words, num_words);
    release_memory(words, num_words);
    return 0;
}

//encrypt the char
char encrypt_char(unsigned char key[KEY_SIZE], char ch){
    int index;
    //Checks whether the letter is large or small
    if((ch>='A')&&ch<='Z'){
        index=ch-'A';
    }
    else{
        index=ch-'a'+LETTERS;
    }
    return key[index];
}

//scans and save the words
int read_words(char* words[], int size, int max_str_len){
    //Memory allocation for the word
    char* read=malloc(sizeof(char)*(max_str_len+1));
    //Checks if memory allocation failed
    if(read==NULL){
        return -1;
    }
    int counter=0;
    //Scans the words
    while(scanf("%s",read)!=EOF&&counter<size){
        //Memory allocation for the words in the fixed array
        words[counter]=malloc(sizeof(char)*(strlen(read)+1));
        //Checks if memory allocation failed
        if(words[counter]==NULL){
            release_memory(words,counter);
            return -1;
        }
        //copy and past the words from a temporary array to a fixed array
        strcpy(words[counter],read);
        counter++;
    }
    //Releases memory
    free(read);
    return counter;
}

//Encrypts the words
void encrypt_words(char* words[], int num_words, unsigned char key[KEY_SIZE]){
    //Passing on every word
    for(int i=0; i<num_words; i++){
        char* ptr=words[i];
        //Passing on every letter
        while(*ptr){
            *ptr=encrypt_char(key,*ptr);
            ptr++;
        }
    }
}

//Releases memory in the array
void release_memory(char* words[], int num_words){
    for(int i=0; i<num_words; i++) {
        free(words[i]);
    }
}
