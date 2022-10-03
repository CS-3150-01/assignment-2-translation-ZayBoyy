#include <stdio.h>
#include <stdbool.h>

char map[20][100];

map[2][2] = "P";

bool proceed = true;
bool argsCheck = false;

int argsRunIndex = 0;

char directions[4][5] = {"North", "East","South", "West"};
int directionX[4] = {0, -1, 0, 1};
int directionY[4] = {1, 0, -1, 0};

int currentDirection = 0;

int currentPosition[] = {2,2};


int args = 0;

if(args > 0) {
    argsCheck = true;
}

while(proceed == true) {

    for(int i=0; i<20; i++) {
        for(int j=0; j<100; j++) {
            if (map[i][j] == null) {
                printf("░");
            }
            else {
                printf("%d", map[i][j]);
            }
        }
        printf("\n");
    }

    printf("Please travers the world and explore using these commands: \n W - Walk Forward\n  A - Turn Left\n  D - Turn Right\n  E - Check Direction\n  Q - Quit the Game");

char input;

if(!argsCheck) {
    scanf("%c", &input);
    args++;   
}
else {
    if (argsRunIndex == args) {
        argsCheck = false;
        input = "e";
    }
    else {
       // input 
       argsRunIndex++;
    }
}


switch(input) {
    case "w":
        map[currentPosition[1][currentPosition[0]] = "#";
        //saves the trail of where you have been
        if(!((currentPosition[0] - directionX[currentDirection] < 0) || (currentPosition[0] - directionX[currentDirection] > 100)||(currentPosition[1] - directionY[currentDirection] < 0) || (currentPosition[1] - directionY[currentDirection] > 20))){
            //checks if you're bumping into the edge
            currentPosition[0] = currentPosition[0] - directionX[currentDirection];
            currentPosition[1] = currentPosition[1] - directionY[currentDirection];
        }                     


        map[currentPosition[1]][currentPosition[0]] = "P";
        //puts your player icon down
        break;
    case "a":
        currentDirection--;
        //moves your index up or down the 3 arrays listed above
        if(currentDirection < 0){
            currentDirection = 3;
        }
        break;
    case "d":
        currentDirection++;
        //moves your index up or down the 3 arrays listed above

        if(currentDirection > 3){
            currentDirection = 0;
        }
        break;
    case "e":
        System.out.println("You are facing in the "+directions[currentDirection]+"ward direction!");
        break;
    case "q":

        proceed = false;
        break;
                
    default:
        System.out.println("You must enter one of the commands!");

            }


}







int main() {
    return 0;
}