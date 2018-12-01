#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool done = false;
char operation;
float value;

float calculate(char operation) {
    float constant;
    // Determine which operation it is then calculate
    switch(operation) {
        case 'a':
            printf("What do value you want to add to %f: ", value);
            scanf("%f",&constant);
            value += constant;
            break;
        case 's':
            printf("What value do you want to subtract from %f: ", value);
            scanf("%f",&constant);
            value -= constant;
            break;
        case 'm':
            printf("What value do you want to multiply by %f: ", value);
            scanf("%f",&constant);
            value *= constant;
            break;  
        case 'd':
            printf("What value do you want to multiply by %f: ", value);
            scanf("%f",&constant);
            value /= constant;
            break;
    }
    // sets operation to nothing
    
    return value;
}

main(void) {
    printf("Lets do some math!\n");
    printf("Enter a value to begin with: ");
    scanf("%f", &value);
    printf("\n");
    while(!done) {
        // While not valid operation
        while(operation != 's' && operation != 'd' && operation != 'a' && operation != 'm') {
            char input[10];
            printf("Do you want to add, subtract, divide, or multiply? or are you done?\n");
            scanf("%s", &input);
            // Make input lowercase
            for(int i = 0; input[i]; i++){
                input[i] = tolower(input[i]);
            }
            // Check if entered valid response then set an operation
            if(strcmp(input,"add") == 0) {
                operation = 'a';
            } else if(strcmp(input,"subtract") == 0) {
                operation = 's';
            } else if(strcmp(input,"multiply") == 0) {
                operation = 'm';
            } else if(strcmp(input,"divide") == 0) {
                operation = 'd';
            } else if(strcmp(input,"done") == 0) {
                return;
            }
            // calculate answer
        }
        float answer = calculate(operation);
        printf("\nResult is: %f\n", answer);
        operation = 'n';
    }
}