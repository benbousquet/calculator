#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool done = false;
float value;

main() {
    printf("Lets do some math!\n");
    printf("Enter a value to begin with: ");
    float value;
    scanf("%f", &value);
    printf("\n");
    while(!done) {
        char operation;
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
                return 0;
            }

        }
        float constant;
        switch(operation) {
            case 'a':
                printf("What do value you want to add to %f: ", value);
                scanf("%f",&constant);
                value += constant;
                printf("\nResult is: %f\n", value);
                break;
            case 's':
                printf("What value do you want to subtract from %f: ", value);
                scanf("%f",&constant);
                value -= constant;
                printf("\nResult is: %f\n", value);
                break;
            case 'm':
                printf("What value do you want to multiply by %f: ", value);
                scanf("%f",&constant);
                value *= constant;
                printf("\nResult is: %f\n", value);
                break;
            case 'd':
                printf("What value do you want to multiply by %f: ", value);
                scanf("%f",&constant);
                value /= constant;
                printf("\nResult is: %f\n", value);
                break;
        }
        operation = NULL;
    }
}
