#include <stdio.h>
#include <string.h>

int isCorrectBrackets(char * seq, char bracket, int is_closing){
    int seq_len = strlen(seq);
    
    for (int i = 0; i < seq_len; i++){
        if (seq[i] == bracket){
            if (is_closing) return 1;

            if (isCorrectBrackets(&seq[i], ')', 1)){
                return 1;
            }

            else{
                return 0;
            }
            break;
        }
        
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    char * s = "J ACK 1022  ICS (E sad) n dsw <";
    int j = isCorrectBrackets(s, '(', 0);
    printf("%d\n", j);
    return 0;
}
