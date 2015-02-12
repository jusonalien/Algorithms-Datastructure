#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
char s[110];
bool if_vowels(char k ){
    if(k == 'A'||k == 'a'||k == 'o'||k == 'O'||k == 'Y'||k == 'y'||k == 'E'||k == 'e'||k == 'U'||k == 'u'||k == 'I'||k =='i')
        return true;
    else return false;
}
int main()
{
    while(scanf("%s",s) != EOF){
        int i = 0;
        while(s[i]) {
            if( ! if_vowels(s[i])) printf(".%c",tolower(s[i]));
            i++;
        }
        printf("\n");
    }
    return 0;
}
