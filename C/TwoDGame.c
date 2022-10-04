#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//added arguments so they can be referenced later
int main(int argc, char* argv[]) {

//Multi-dimensional character array for a 2D plane
char map[20][100];

//points undefined values to zero
memset(&map, 0, 20*100*sizeof(char));

//starting location for the "player"
map[2][2] = 'P';

bool proceed = true;
bool argsCheck = false;

int argsRunIndex = 0;

//These arrays are for traversing the map
//Each correspond in the formatted order
char directions[][5] = {"North", "East", "South", "West"};
int directionX[4] =    {   0,      -1,      0,       1  };
int directionY[4] =    {   1,       0,     -1,       0  };


//The above arrays can all be controlled by using this as the index to choose direction
int currentDirection = 0;

int currentPosition[] = {2,2};


if(argc > 1) {
    argsCheck = true;
}

//this loops until you quit or kill the terminal
while(proceed == true) {

    //Nested for loops to show the map to the user
    for(int i=0; i<20; i++) {
        for(int j=0; j<100; j++) {
            if (map[i][j] == 0) {
                printf("%c", 9904);
                //Empty values are displayed as a symbol
            }
            else {
                //Displays any data inside the array
                printf("%c", map[i][j]);
            }
        }
        //new line
        printf("\n");
    }

    printf("\nPlease traverse the world and explore using these commands:\n  W - Walk Forward\n  A - Turn Left\n  D - Turn Right\n  E - Check Direction\n  Q - Quit the Game\n");

char input;

if(!argsCheck) {
    scanf(" %c", &input); 
}
else {
    if (argsRunIndex == argc) {
        argsCheck = false;
        input = 'e';
    }
    else {
       input = *argv[argsRunIndex];
       argsRunIndex++;
    }
}


switch(input) {
    case 'w':
        map[currentPosition[1]][currentPosition[0]] = '#';
        //saves the trail of where you have been
        if(!((currentPosition[0] - directionX[currentDirection] < 0) || (currentPosition[0] - directionX[currentDirection] > 100)||(currentPosition[1] - directionY[currentDirection] < 0) || (currentPosition[1] - directionY[currentDirection] > 20))){
            //checks if you're bumping into the edge
            currentPosition[0] = currentPosition[0] - directionX[currentDirection];
            currentPosition[1] = currentPosition[1] - directionY[currentDirection];
        } 
        else{
            printf("\nThat's the edge!\n\n");
        }                    


        map[currentPosition[1]][currentPosition[0]] = 'P';
        //puts your player icon down
        break;

    case 'a':
        currentDirection--;
        //moves your index up or down the 3 arrays listed above
        if(currentDirection < 0){
            currentDirection = 3;
        }
        break;

    case 'd':
        currentDirection++;
        //moves your index up or down the 3 arrays listed above

        if(currentDirection > 3){
            currentDirection = 0;
        }
        break;

    case 'e':
        printf("You are facing in the %sward direction!\n", directions[currentDirection]);
        break;
    case 'q':

        proceed = false;
        break;
                
    default:
        printf("You must enter one of the commands!");

            }


}

    return 0;
}