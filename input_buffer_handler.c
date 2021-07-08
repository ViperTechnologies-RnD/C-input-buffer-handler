#include <stdio.h>
#include <string.h> // to take advantage of the strlen() function
//this is a normal approach, it flushes the input buffer until
//it sees the new line character, this is not the best solution
//for flushing input because when you hit enter (return key), the new 
//line character will be skipped and you have to press enter 
//n times, n ==> e.g. if you have to inputs that takes first name and 
//last name, you have to press Enter Twice!
void flush_input() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
//this is a custom readline function, that utilizes again getchar
//to clear the input buffer, also it is fool-proofed approach to 
//safegaurd the input and avoid buffer overflow 
//(when user enters more than allowed characters), it will truncate it
//and only takes the max allowed size of characters 
//the function it self is self-explanatory 
int c_readln(char str[], int allowed_len) {
    char ch;
    int i = 0;
    int chars_remained=1;
    double input_len = strlen(str);
    
    while (chars_remained) {
        ch = getchar();
        if ( input_len > allowed_len) {
        printf("Illegal length truncating\n");
    }
        if ((ch == '\n') || (ch == EOF)) {
            chars_remained = 0;
        }else if (i < allowed_len - 1) {
            str[i] = ch;
            i++;
        }
    }
    //add null terminator to the end of string
    str[i] = '\0';
    return i;
}
int main () {
    char name[10];
    char lastname[12];
    char option[2]; //single character in string format need to be of lenght 2 because element 1 is the character itself and element 2 is the terminator '\0'
    printf("Enter your name: ");
    c_readln(name, 10);
    printf("Enter your Last name: ");
    c_readln(lastname, 10);
    printf("Enter an option CHARACTER:");
    c_readln(option, 2);
    printf("hello %s, %s your selected option: %s \n ", name, lastname,option);
    printf("Length of Name: %lu, Length of lastname: %lu, Length of OPTION: %lu\n", strlen(name), strlen(lastname), strlen(option));
return 0;
}