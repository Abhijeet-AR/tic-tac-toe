#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void homeScreen();
void singlePlayer();
void twoPlayers();
void howToPlay();
void grid(int, char);
void emptyGrid();
void playerNames(char*, char*);
int winner();
void choiceX(char*);
void choiceO(char*);
void choiceC();
int comp();
int winMove();
int block();

char a[9], b[9], c[9];
int i = 0, l = 0, flag;

int main(){
    
    srand(time(0));
    
    homeScreen();
    
    printf("\n\n");
    return 0;
}


void homeScreen(){
    
    int choice;
    
    system("clear");
    
    printf("\v\vTic-Tac-Toe");
    printf("\n1. Single Player\n2. Two Players\n3. How to Play\n4. Quit\n\nEnter Choice : ");
    scanf(" %d", &choice);
    
    system("clear");
    
    if(choice == 1)
        singlePlayer();
    
    else if(choice == 2)
        twoPlayers();
    
    else if(choice == 3)
        howToPlay();
    
    else
        exit(0);
}


void singlePlayer(){
    
    char player[10] = "Your";
    int count = 0;
    
    emptyGrid();
    
    choiceX(player);
    while(!winner() && count < 4){
        
        choiceC();
        
        if(winner())
            break;
        
        choiceX(player);
        count++;
    }
    
    if(winner() == 1)
        printf("\nYou Win!");
    
    else if(winner() == 2)
        printf("\nYou Lose!");
    
    else
        printf("\nIt's tie");
    
}


void twoPlayers(){
    
    char playerX[10], playerO[10];
    int count = 0;
    
    playerNames(playerX, playerO);
    
    emptyGrid();
    
    choiceX(playerX);
    while(!winner() && count < 4){
        
        choiceO(playerO);
        
        if(winner())
            break;
        
        choiceX(playerX);
        count++;
    }
    
    if(winner() == 1)
        printf("\n%s wins", playerX);
    
    else if(winner() == 2)
        printf("\n%s wins", playerO);
    
    else
        printf("\nIt's tie");
    
}


void emptyGrid(){
    
    for(int i = 0; i < 9; i++)
        a[i] = ' ';
    
    system("clear");
}


void grid(int i, char c){
    
    a[i] = c;
    
    printf("\v\v\v");
    printf("\t\t\t %c | %c | %c \n", a[0], a[1], a[2]);
    printf("\t\t\t===========\n");
    printf("\t\t\t %c | %c | %c \n", a[3], a[4], a[5]);
    printf("\t\t\t===========\n");
    printf("\t\t\t %c | %c | %c \n", a[6], a[7], a[8]);
    printf("\v\v\v");
    
}


void howToPlay(){
    
    printf("\n1. The game is played on a grid that's 3 squares by 3 squares.\n2. You are X, your friend is O. \n3. Players take turns putting their marks in empty squares. Select a number from the grid to mark.\n\n");
    
    for(int i = 0, j = 48; i < 9; i++, j++)
        a[i] = j;
    
    grid(0, 48);
    
    printf("\n\n4. The first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner.\n5. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.");
    
    printf("\n\nPress Enter to go back");
    getchar();getchar();
    
    homeScreen();
}


void playerNames(char* playerX, char* playerO){
    
    printf("\nEnter Your names\n");
    
    printf("\nPlayer X : ");
    scanf(" %s", playerX);
    
    printf("\nPlayer O : ");
    scanf(" %s", playerO);
    
}


void choiceX(char* playerX){
    
    int pos;
    
    do{
        printf("\n%s's turn : ", playerX);
        scanf("%d", &pos);
        
        if(a[pos-1] == 'X' || a[pos-1] == 'O')
            printf("\nAlready occupied");
        
        else
            break;
    }while(1);
    
    c[l++] = pos;
    
    system("clear");
 //   printf("\nX\n");
    grid(pos-1, 'X');
    
}


void choiceO(char* playerO){
    
    int pos;
    
    do{
        printf("\n%s's turn : ", playerO);
        scanf("%d", &pos);
        
        if(a[pos-1] == 'X' || a[pos-1] == 'O')
            printf("\nAlready occupied");
        
        else
            break;
    }while(1);
    
    system("clear");
    grid(pos-1, 'O');
    
}


void choiceC(){
    
    int pos, qw = 0;
    
    flag = 0;
    
    do{
        pos = comp();
        
        flag++;

        if(pos < 0 || pos > 9)
            continue;
        
        if(a[pos-1] != 'X' && a[pos-1] != 'O')
            break;
        
    }while(1);
    
    b[i++] = pos;
    
    system("clear");
 //   printf("\nC\n");
    grid(pos-1, 'O');
}


int comp(){
    
    int pos;
    
    if(i == 0)
        return (1+rand()%9);
    
    else if((flag == 0) && ((pos = winMove()) != 0))
        return pos;
    
    
    else if((flag == 0) && (pos = block()) != 0)
        return pos;
    
    
    else
        for(int ind = 0; ind < 10; ind++){
        
            pos = 1+rand()%9;
            
            if((pos == b[i-1]-3) || (pos == b[i-1]-1) || (pos == b[i]-1+1) || (pos == b[i-1]+3) )
                return pos;
            
        }
    
    return pos;
}

/*int winMove(){
    
    int j;
    
    for(j = 0; j < i; j++)
        for(int k = j+1; k < i; k++){
            if(b[j]+1 == b[k])
                return b[j]+2;
            
            else if(b[j]-1 == b[k])
                return b[j]-2;
            
            else if(b[j]+2 == b[k]){
                if(b[j] == 3)
                    return b[j]+4;
                else
                    return b[j]+1;
            }
            
            else if(b[j]-2 == b[k])
                return b[j]-1;
            
            else if(b[j]-3 == b[k])
                return b[k]-6;
            
            else if(b[j]-6 == b[k])
                return b[k]-3;
            
            else if(b[j]+3 == b[k])
                return b[k]+6;
            
            else if(b[j]+6 == b[k])
                return b[k]+3;
            
            else if(b[j]+4 == b[k])
                return b[k]+8;
            
            else if(b[j]+8 == b[k])
                return b[k]+4;
            
        }
    
    return 0;
}*/


int winMove(){
    
    int ind;
    
    for(ind = 0; ind < 9; ind++){
        if(a[ind] != 'X' && a[ind] != 'O'){
            a[ind] = 'O';
            if(winner() == 2){
                a[ind] = ' ';
                return ind+1;
            }
            a[ind] = ' ';
        }
    }
    return 0;
}


/*int block(){
    
    int j;
    
    for(j = 0; j < l; j++)
        for(int k = j+1; k < l; k++){
            if(c[j]+1 == c[k])
                return c[j]+2;
            
            else if(c[j]-1 == c[k])
                return c[j]-2;
            
            else if(c[j]+2 == c[k]){
                if(c[j] == 3)
                    return c[j]+4;
                else
                    return c[j]+1;
            }
            
            else if(c[j]-2 == c[k])
                return c[j]-1;
            
            else if(c[j]-3 == c[k])
                return c[k]-6;
            
            else if(c[j]-6 == c[k])
                return c[k]-3;
            
            else if(b[j]+3 == b[k])
                return c[k]+6;
            
            else if(c[j]+6 == c[k])
                return c[k]+3;
            
            else if(c[j]+4 == c[k])
                return c[k]+8;
            
            else if(c[j]+8 == c[k])
                return c[k]+4;
            
        }
    
    return 0;
}*/

int block(){
    
    int ind;
    
    for(ind = 0; ind < 9; ind++){
        if(a[ind] != 'X' && a[ind] != 'O'){
            a[ind] = 'X';
            if(winner() == 1){
                a[ind] = ' ';
                return ind+1;
            }
            a[ind] = ' ';
        }
    }
    return 0;
}


int winner(){
    
    if(a[0] == 'X'){
        if((a[0] == a[1] && a[0] == a[2]) || (a[0] == a[3] && a[0] == a[6]) || (a[0] == a[4] && a[0] == a[8]))
            return 1;
    }
    
    if(a[3] == 'X'){
        if(a[3] == a[4] && a[3] == a[5])
            return 1;
    }
    
    if(a[6] == 'X'){
        if(a[6] == a[7] && a[6] == a[8])
            return 1;
    }
    
    if(a[1] == 'X'){
        if(a[1] == a[4] && a[1] == a[7])
            return 1;
    }
    
    if(a[2] == 'X'){
        if((a[2] == a[5] && a[2] == a[8]))
            return 1;
    }
    
    if(a[2] == 'X'){
        
        
        if(a[2] == a[4] && a[2] == a[6])
            return 1;
    }
    
    
    if(a[0] == 'O'){
        if((a[0] == a[1] && a[0] == a[2]) || (a[0] == a[3] && a[0] == a[6]) || (a[0] == a[4] && a[0] == a[8]))
            return 2;
    }
    
    if(a[3] == 'O'){
        if(a[3] == a[4] && a[3] == a[5])
            return 2;
    }
    
    else if(a[6] == 'O'){
        if(a[6] == a[7] && a[6] == a[8])
            return 2;
    }
    
    if(a[1] == 'O'){
        if(a[1] == a[4] && a[1] == a[7])
            return 2;
    }
    
    if(a[2] == 'O'){
        if((a[2] == a[5] && a[2] == a[8]))
            return 2;
    }
    
    if(a[2] == 'O'){
        if(a[2] == a[4] && a[2] == a[6])
            return 2;
    }
    
    return 0;
    
}


































