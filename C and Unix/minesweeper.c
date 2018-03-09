/*
This program plays the game Minesweeper

************************************************************************************************************************ */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Global variable for counting the dots each time a number or space is displayed. Set at 90 because there are 10 astericks hidden on the board*/
int dotCount = 90;

flood_fill(char bombBoard[10][10], char board[10][10], char specialBoard[10][10], int row, int column)
{
    int i, j, k, t, z;
    int mineCount = 0; //counts the number of mines surrounding a tile
    int flood_fill_Count = 0; //counts the number of mines surrounding a tile when mineCount = 0
               
    if (row > 9 || row < 0 || column > 9 || column < 0)
    {
        printf("Ivalid move! Try again!\n\n");
    }
    else if (board[row][column] == '0' || board[row][column] == '1' || board[row][column] == '2' || board[row][column] == '3'
       || board[row][column] == '4' || board[row][column] == '5' || board[row][column] == '6' || board[row][column] == '7'
       || board[row][column] == '8')
    {
        printf("You have already sweeped there! Try again!\n\n");
    } 
    else if (board[row][column] == ' ')
    {
        printf("That space has nothing in it! Try again!\n\n");
    }

    /*If the user loses the bombBoard prints with everything updated in it*/
    else
    {
        if (bombBoard[row][column] == '*')
        {
            printf("You lose! You hit a mine at row[%d]column[%d]\n\n", row, column);
            printf("  0 1 2 3 4 5 6 7 8 9\n");

            for (i = 0; i < 10; i++)
            {
                printf("%d" , i);
                  
                for (j = 0; j < 10; j++)
                {
                    printf("%2c", bombBoard[i][j]);  
                }
                printf("\n");
            }
            printf("\n");
            exit(0); //exit(0) because it's an infinite loop running through a function
        }

        /*If the user doesn't hit a mine, this counts the number of mines surrounding the tile*/
        if (bombBoard[row][column] == '.')
        {
            /*The specialBoard is used here and throughout the game. There is a bug where if the user chooses the first two or last
              two columns, then mineCount counts columns where it's not necessary for it to count. For example, if the user chooses row[0]column[0]
              the mineCount can also count row[0]column[9]. We are checking if the user picks any of those columns so a specific mineCount will
              be counted*/
            if (specialBoard[row][column] != 'w' || specialBoard[row][column] != 'x')
            {     
                if (bombBoard[row][column + 1] == '*')
                {
                    mineCount++;
                }
                if (bombBoard[row + 1][column] == '*')
                {
                    mineCount++;
                }
                if (bombBoard[row + 1][column + 1] == '*')
                {
                    mineCount++;
                }
                if (bombBoard[row - 1][column + 1] == '*')
                {
                    mineCount++;
                }
                if (bombBoard[row + 1][column - 1] == '*')
                {
                    mineCount++;
                }
                if (bombBoard[row][column - 1] == '*')
                {
                    mineCount++;
                }
                if (bombBoard[row - 1][column] == '*')
                {
                    mineCount++;
                }
                if (bombBoard[row - 1][column - 1] == '*')
                {
                    mineCount++;
                }                     
            }
            if (specialBoard[row][column] == 'w')
            {
                if (bombBoard[row][column - 1] == '*')
                {
                    mineCount -= 1;
                }
                if (bombBoard[row - 1][column - 1] == '*')
                {
                    mineCount -= 1;
                }
                if (bombBoard[row + 1][column - 1] == '*')
                {
                    mineCount -= 1;
                } 
            }
            if (specialBoard[row][column] == 'x')
            {
                if (bombBoard[row][column + 1] == '*')
                {
                    mineCount -= 1;
                }
                if (bombBoard[row + 1][column + 1] == '*')
                {
                    mineCount -= 1;
                }
                if (bombBoard[row - 1][column + 1] == '*')
                {
                    mineCount -= 1;
                }
            }
          
            /*If mineCount is any of the following numbers then it prints the board with that number in that tile*/
            if (mineCount == 1)
            {
                board[row][column] = '1';
                bombBoard[row][column] = '1';
                dotCount -= 1;
    
                printf("  0 1 2 3 4 5 6 7 8 9\n"); 

                for (i = 0; i < 10; i++)
                {         
                    printf("%d" , i);                 

                    for (j = 0; j < 10; j++) 
                    {
                        printf("%2c" , board[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            if (mineCount == 2)
            {
                board[row][column] = '2';
                bombBoard[row][column] = '2';
                dotCount -= 1;
    
                printf("  0 1 2 3 4 5 6 7 8 9\n"); 

                for (i = 0; i < 10; i++)
                {         
                    printf("%d" , i);                 

                    for (j = 0; j < 10; j++) 
                    {
                        printf("%2c" , board[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            if (mineCount == 3)
            {          
                board[row][column] = '3';
                bombBoard[row][column] = '3';
                dotCount -= 1;
    
                printf("  0 1 2 3 4 5 6 7 8 9\n"); 

                for (i = 0; i < 10; i++)
                {         
                    printf("%d" , i);                 

                    for (j = 0; j < 10; j++) 
                    {
                        printf("%2c" , board[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            if (mineCount == 4)
            {
                board[row][column] = '4';
                bombBoard[row][column] = '4';
                dotCount -= 1;
    
                printf("  0 1 2 3 4 5 6 7 8 9\n"); 

                for (i = 0; i < 10; i++)
                {         
                    printf("%d" , i);                 

                    for (j = 0; j < 10; j++) 
                    {
                        printf("%2c" , board[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            if (mineCount == 5)
            {
                board[row][column] = '5';
                bombBoard[row][column] = '5';
                dotCount -= 1;
    
                printf("  0 1 2 3 4 5 6 7 8 9\n"); 

                for (i = 0; i < 10; i++)
                {         
                    printf("%d" , i);                 

                    for (j = 0; j < 10; j++) 
                    {
                        printf("%2c" , board[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            if (mineCount == 6)
            {
                board[row][column] = '6';
                bombBoard[row][column] = '6';
                dotCount -= 1;
    
                printf("  0 1 2 3 4 5 6 7 8 9\n"); 

                for (i = 0; i < 10; i++)
                {         
                    printf("%d" , i);                 

                    for (j = 0; j < 10; j++) 
                    {
                        printf("%2c" , board[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            if (mineCount == 7)
            {
                board[row][column] = '7';
                bombBoard[row][column] = '7';
                dotCount -= 1;
    
                printf("  0 1 2 3 4 5 6 7 8 9\n"); 

                for (i = 0; i < 10; i++)
                {         
                    printf("%d" , i);                 

                    for (j = 0; j < 10; j++) 
                    {
                        printf("%2c" , board[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            if (mineCount == 8)
            {
                board[row][column] = '8';
                bombBoard[row][column] = '8';
                dotCount -= 1;
    
                printf("  0 1 2 3 4 5 6 7 8 9\n"); 

                for (i = 0; i < 10; i++)
                {         
                    printf("%d" , i);                 

                    for (j = 0; j < 10; j++) 
                    {
                        printf("%2c" , board[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }

            /*This is the big enchilada of the program. If mineCount == 0 then we have to check for special cases in the specialBoard,
            add a '0' to the tile, and find the surrounding mines and display those numbers. It's so large becuase of all the special cases
            involved and the specific logic for each case. Notice I subtract 1 for dotCount each time a 0 or a space is displayed*/
            if (mineCount == 0)
            { 
                dotCount -= 1;          

                if (specialBoard[row][column] == 'w')
                {
                    board[row][column] = '0';
                    bombBoard[row][column] = '0';

                    /*This for loop and the ones you will see after is checking if any of the surrounding tiles equals a number.
                    If so it tells the program to keep that number. There was a bug where if mineCount == 0 then a space would 
                    cover any number*/
                    for (i = 0; i < 9; i++)
                    {
                        if (board[row + 1][column] == i + '0')
                        {
                            board[row + 1][column] = i + '0';
                            bombBoard[row + 1][column] = i + '0';
                            break;                           
                        }
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row][column + 1] == i + '0')
                        {
                            board[row][column + 1] = i + '0';
                            bombBoard[row][column + 1] = i + '0';
                            break;
                        }
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row - 1][column] == i + '0')
                        {
                            board[row - 1][column] = i + '0';
                            bombBoard[row - 1][column] = i + '0';
                            break;
                        } 
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row + 1][column + 1] == 1 + '0')
                        {
                            board[row + 1][column + 1] = i + '0';
                            bombBoard[row + 1][column + 1] = i + '0';
                            break;
                        }
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row - 1][column + 1] == i + '0')
                        {
                            board[row - 1][column + 1] = i + '0';
                            bombBoard[row - 1][column + 1] = i + '0';
                            break;
                        }
                    }
                        /*This if statement and the ones you'll see after will count the surrounding mines
                        when the tiles expand and it displays the corresponding number*/
                        if (bombBoard[row + 1][column] == '.' && bombBoard[row + 2][column] == '*'
                           || bombBoard[row + 1][column] == '.' && bombBoard[row + 2][column + 1] == '*')
                        {
                           if (bombBoard[row + 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row + 1][column] = '1';
                               bombBoard[row + 1][column] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row + 1][column] = '2';
                               bombBoard[row + 1][column] = '2';
                               dotCount -= 1;
                           }
                        }
                        /*If there is not a mine when the tile expands then it simply puts a space*/
                        else if (board[row + 1][column] == '.')
                        {
                            board[row + 1][column] = ' ';
                            bombBoard[row + 1][column] = ' ';
                            dotCount -= 1;
                        }

                        if (bombBoard[row][column + 1] == '.' && bombBoard[row][column + 2] == '*'
                           || bombBoard[row][column + 1] == '.' && bombBoard[row + 1][column + 2] == '*'
                           || bombBoard[row][column + 1] == '.' && bombBoard[row - 1][column + 2] == '*')
                        {
                           flood_fill_Count = 0; //flood_fill_Count is reset to 0 each time
                           if (bombBoard[row][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 1][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 1][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row][column + 1] = '1';
                               bombBoard[row][column + 1] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row][column + 1] = '2';
                               bombBoard[row][column + 1] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row][column + 1] = '3';
                               bombBoard[row][column + 1] = '3';
                               dotCount -= 1;
                           }
                        }

                        else if (board[row][column + 1] == '.')
                        {
                            board[row][column + 1] = ' ';
                            bombBoard[row][column + 1] = ' ';
                            dotCount -= 1;
                        }

                        if (bombBoard[row - 1][column] == '.' && bombBoard[row - 2][column] == '*'
                           || bombBoard[row - 1][column] == '.' && bombBoard[row - 2][column + 1] == '*')
                        {
                           flood_fill_Count = 0;
                           if (bombBoard[row - 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row - 1][column] = '1';
                               bombBoard[row - 1][column] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row - 1][column] = '2';
                               bombBoard[row - 1][column] = '2';
                               dotCount -= 1;
                           }
                        }

                        else if (board[row - 1][column] == '.')
                        { 
                            board[row - 1][column] = ' ';
                            bombBoard[row - 1][column] = ' ';
                            dotCount -= 1;
                        }
                       
                        if (bombBoard[row + 1][column + 1] == '.' && bombBoard[row][column + 2] == '*'
                           || bombBoard[row + 1][column + 1] == '.' && bombBoard[row + 1][column + 2] == '*'
                           || bombBoard[row + 1][column + 1] == '.' && bombBoard[row + 2][column + 2] == '*'
                           || bombBoard[row + 1][column + 1] == '.' && bombBoard[row + 2][column + 1] == '*')
                        {
                           flood_fill_Count = 0;
                           if (bombBoard[row][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 1][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }

                           if (flood_fill_Count == 1)
                           {
                               board[row + 1][column + 1] = '1';
                               bombBoard[row + 1][column + 1] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row + 1][column + 1] = '2';
                               bombBoard[row + 1][column + 1] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row + 1][column + 1] = '3';
                               bombBoard[row + 1][column + 1] = '3';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 4)
                           {
                               board[row + 1][column + 1] = '4';
                               bombBoard[row + 1][column + 1] = '4';
                               dotCount -= 1;
                           }
                        }

                        else if (board[row + 1][column + 1] == '.')
                        {
                            board[row + 1][column + 1] = ' ';
                            bombBoard[row + 1][column + 1] = ' ';
                            dotCount -= 1;   
                        }
                     
                        if (bombBoard[row - 1][column + 1] == '.' && bombBoard[row - 2][column + 1] == '*'
                           || bombBoard[row - 1][column + 1] == '.' && bombBoard[row - 2][column + 2] == '*'
                           || bombBoard[row - 1][column + 1] == '.' && bombBoard[row - 1][column + 2] == '*'
                           || bombBoard[row -1][column + 1] == '.' && bombBoard[row][column + 2] == '*')
                        {
                           flood_fill_Count = 0;
                           if (bombBoard[row - 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 1][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row - 1][column + 1] = '1';
                               bombBoard[row - 1][column + 1] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row - 1][column + 1] = '2';
                               bombBoard[row - 1][column + 1] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row - 1][column + 1] = '3';
                               bombBoard[row - 1][column + 1] = '3';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 4)
                           {
                               board[row - 1][column + 1] = '4';
                               bombBoard[row - 1][column + 1] = '4';
                               dotCount -= 1;
                           }
                        }

                        else if (board[row - 1][column + 1] == '.')
                        {
                            board[row - 1][column + 1] = ' ';
                            bombBoard[row - 1][column + 1] = ' ';
                            dotCount -= 1;
                        }

                    printf("  0 1 2 3 4 5 6 7 8 9\n"); 

                    for (t = 0; t < 10; t++)
                    {         
                        printf("%d" , t);                 

                        for (j = 0; j < 10; j++) 
                        {
                            printf("%2c" , board[t][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
                                                                      
                /*And it just goes on and on with specific logic for each specific case checked by the specialBoard*/
                else if (specialBoard[row][column] == 'x')
                {
                    board[row][column] = '0';
                    bombBoard[row][column] = '0';

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row + 1][column] == i + '0')
                        {
                            board[row + 1][column] = i + '0';
                            bombBoard[row + 1][column] = i + '0';
                            break;
                        }
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row + 1][column - 1] == i + '0')
                        {
                            board[row + 1][column - 1] = i + '0';
                            bombBoard[row + 1][column - 1] = i + '0';
                            break;
                        }
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row - 1][column] == i + '0')
                        {
                            board[row - 1][column] = i + '0';
                            bombBoard[row - 1][column] = i + '0';
                            break;
                        } 
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row][column - 1] == i + '0')
                        {
                            board[row][column - 1] = i + '0';
                            board[row][column - 1] = i + '0';
                            break;
                        }
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row - 1][column - 1] == i + '0')
                        {
                            board[row - 1][column - 1] = i + '0';
                            bombBoard[row - 1][column - 1] = i + '0';
                            break;
                        }
                    }

                        if (bombBoard[row + 1][column] == '.' && bombBoard[row + 2][column] == '*'
                           || bombBoard[row + 1][column] == '.' && bombBoard[row + 2][column - 1] == '*')
                        {
                           if (bombBoard[row + 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row + 1][column] = '1';
                               bombBoard[row + 1][column] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row + 1][column] = '2';
                               bombBoard[row + 1][column] = '2';
                               dotCount -= 1;
                           }
                        }

                        else if (board[row + 1][column] == '.')
                        {
                            board[row + 1][column] = ' ';
                            bombBoard[row + 1][column] = ' ';
                            dotCount -= 1;
                        }

                        if (bombBoard[row - 1][column] == '.' && bombBoard[row - 2][column] == '*'
                           || bombBoard[row - 1][column] == '.' && bombBoard[row - 2][column - 1] == '*')
                        {
                           flood_fill_Count = 0;
                           if (bombBoard[row - 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row - 1][column] = '1';
                               bombBoard[row - 1][column] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row - 1][column] = '2';
                               bombBoard[row - 1][column] = '2';
                               dotCount -= 1;
                           }
                        }

                        else if (board[row - 1][column] == '.')
                        {
                            board[row - 1][column] = ' ';
                            bombBoard[row - 1][column] = ' ';
                            dotCount -= 1;
                        }
                    
                        if (bombBoard[row][column - 1] == '.' && bombBoard[row][column - 2] == '*'
                           || bombBoard[row][column - 1] == '.' && bombBoard[row - 1][column - 2] == '*'
                           || bombBoard[row][column - 1] == '.' && bombBoard[row + 1][column - 2] == '*')
                        {
                           flood_fill_Count = 0;
                           if (bombBoard[row][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 1][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 1][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row][column - 1] = '1';
                               bombBoard[row][column - 1] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row][column - 1] = '2';
                               bombBoard[row][column - 1] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row][column - 1] = '3';
                               bombBoard[row][column - 1] = '3';
                               dotCount -=  1;
                           }
                        }

                        else if (board[row][column - 1] == '.')
                        {
                            board[row][column - 1] = ' ';
                            bombBoard[row][column - 1] = ' ';
                            dotCount -= 1;
                        }
                                        

                        if (bombBoard[row - 1][column - 1] == '.' && bombBoard[row - 2][column - 2] == '*'
                           || bombBoard[row - 1][column - 1] == '.' && bombBoard[row - 2][column - 1] == '*'
                           || bombBoard[row - 1][column - 1] == '.' && bombBoard[row - 1][column - 2] == '*'
                           || bombBoard[row - 1][column - 1] == '.' && bombBoard[row][column - 2] == '*')
                        {
                           flood_fill_Count = 0;
                           if (bombBoard[row - 2][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 1][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row - 1][column - 1] = '1';
                               bombBoard[row - 1][column - 1] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row - 1][column - 1] = '2';
                               bombBoard[row - 1][column - 1] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row - 1][column - 1] = '3';
                               bombBoard[row - 1][column - 1] = '3';
                               dotCount -=  1;
                           }
                           if (flood_fill_Count == 4)
                           {
                               board[row - 1][column - 1] = '4';
                               bombBoard[row - 1][column - 1] = '4';
                               dotCount -= 1;
                           }
                        }

                        else if (board[row - 1][column - 1] == '.')
                        {
                            board[row - 1][column - 1] = ' ';
                            bombBoard[row - 1][column - 1] = ' ';
                            dotCount -= 1;
                        }

                        if (bombBoard[row + 1][column - 1] == '.' && bombBoard[row][column - 2] == '*'
                           || bombBoard[row + 1][column - 1] == '.' && bombBoard[row + 1][column - 2] == '*'
                           || bombBoard[row + 1][column - 1] == '.' && bombBoard[row + 2][column - 2] == '*'
                           || bombBoard[row + 1][column - 1] == '.' && bombBoard[row + 2][column - 1] == '*')
                        {  
                           flood_fill_Count = 0;            
                           if (bombBoard[row][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 1][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           } 
                           if (flood_fill_Count == 1)
                           {
                               board[row + 1][column - 1] = '1';
                               bombBoard[row + 1][column - 1] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row + 1][column - 1] = '2';
                               bombBoard[row + 1][column - 1] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row + 1][column - 1] = '3';
                               bombBoard[row + 1][column - 1] = '3';
                               dotCount -=  1;
                           }
                           if (flood_fill_Count == 4)
                           {
                               board[row + 1][column - 1] = '4';
                               bombBoard[row + 1][column - 1] = '4';
                               dotCount -=  1;
                           }
                        }

                        else if (board[row + 1][column - 1] == '.')
                        {
                            board[row + 1][column - 1] = ' ';
                            bombBoard[row + 1][column - 1] = ' ';
                            dotCount -= 1;
                        }

                    printf("  0 1 2 3 4 5 6 7 8 9\n"); 

                    for (t = 0; t < 10; t++)
                    {         
                        printf("%d" , t);                 

                        for (j = 0; j < 10; j++) 
                        {
                            printf("%2c" , board[t][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
               }
                          
               else if (specialBoard[row][column] == 't')
               {
                    board[row][column] = '0';
                    bombBoard[row][column] = '0';

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row + 1][column] == i + '0')
                        {
                            board[row + 1][column] = i + '0';
                            bombBoard[row + 1][column] = i + '0';
                            break;                           
                        }
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row][column + 1] == i + '0')
                        {
                            board[row][column + 1] = i + '0';
                            bombBoard[row][column + 1] = i + '0';
                            break;
                        }
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row - 1][column] == i + '0')
                        {
                            board[row - 1][column] = i + '0';
                            bombBoard[row - 1][column] = i + '0';
                            break;
                        } 
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row + 1][column + 1] == 1 + '0')
                        {
                            board[row + 1][column + 1] = i + '0';
                            bombBoard[row + 1][column + 1] = i + '0';
                            break;
                        }
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row - 1][column + 1] == i + '0')
                        {
                            board[row - 1][column + 1] = i + '0';
                            bombBoard[row - 1][column + 1] = i + '0';
                            break;
                        }
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row + 1][column - 1] == i + '0')
                        {
                            board[row + 1][column - 1] = i + '0';
                            bombBoard[row + 1][column - 1] = i + '0';
                            break;
                        }
                    }

                    for (i = 0; i < 9; i++)
                    {
                        if (board[row - 1][column - 1] == i + '0')
                        {
                            board[row - 1][column - 1] = i + '0';
                            bombBoard[row - 1][column - 1] = i + '0';
                            break;
                        }
                    }

                        if (bombBoard[row + 1][column] == '.' && bombBoard[row + 2][column] == '*'
                           || bombBoard[row + 1][column] == '.' && bombBoard[row + 2][column + 1] == '*'
                           || bombBoard[row + 1][column] == '.' && bombBoard[row + 2][column - 1] == '*')
                        {
                           if (bombBoard[row + 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row + 1][column] = '1';
                               bombBoard[row + 1][column] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row + 1][column] = '2';
                               bombBoard[row + 1][column] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row + 1][column] = '3';
                               bombBoard[row + 1][column] = '3';
                               dotCount -=  1;
                           }
                        }

                        else if (board[row + 1][column] == '.')
                        {
                            board[row + 1][column] = ' ';
                            bombBoard[row + 1][column] = ' ';
                            dotCount -= 1;
                        }

                        if (bombBoard[row][column + 1] == '.' && bombBoard[row][column + 2] == '*'
                           || bombBoard[row][column + 1] == '.' && bombBoard[row + 1][column + 2] == '*'
                           || bombBoard[row][column + 1] == '.' && bombBoard[row - 1][column + 2] == '*')
                        {
                           flood_fill_Count = 0;
                           if (bombBoard[row][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 1][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 1][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row][column + 1] = '1';
                               bombBoard[row][column + 1] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row][column + 1] = '2';
                               bombBoard[row][column + 1] = '2';
                               dotCount -= 1;
                           }

                           if (flood_fill_Count == 3)
                           {
                               board[row][column + 1] = '3';
                               bombBoard[row][column + 1] = '3';
                               dotCount -=  1;
                           }
                        }

                        else if (board[row][column + 1] == '.')
                        {
                            board[row][column + 1] = ' ';
                            bombBoard[row][column + 1] = ' ';
                            dotCount -= 1;
                        }


                        if (bombBoard[row - 1][column] == '.' && bombBoard[row - 2][column] == '*'
                           || bombBoard[row - 1][column] == '.' && bombBoard[row - 2][column + 1] == '*'
                           || bombBoard[row -1][column] == '.' && bombBoard[row - 2][column - 2] == '*')
                        {
                           flood_fill_Count = 0;
                           if (bombBoard[row - 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row - 1][column] = '1';
                               bombBoard[row - 1][column] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row - 1][column] = '2';
                               bombBoard[row - 1][column] = '2';
                               dotCount -= 1;
                           }

                           if (flood_fill_Count == 3)
                           {
                               board[row - 1][column] = '3';
                               bombBoard[row - 1][column] = '3';
                               dotCount -=  1;
                           }
                        }

                        else if (board[row - 1][column] == '.')
                        { 
                            board[row - 1][column] = ' ';
                            bombBoard[row - 1][column] = ' ';
                            dotCount -= 1;
                        }
                       
                        if (bombBoard[row + 1][column + 1] == '.' && bombBoard[row][column + 2] == '*'
                           || bombBoard[row + 1][column + 1] == '.' && bombBoard[row + 1][column + 2] == '*'
                           || bombBoard[row + 1][column + 1] == '.' && bombBoard[row + 2][column + 2] == '*'
                           || bombBoard[row + 1][column + 1] == '.' && bombBoard[row + 2][column + 1] == '*')
                        {
                           flood_fill_Count = 0;
                           if (bombBoard[row][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 1][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row + 1][column + 1] = '1';
                               bombBoard[row + 1][column + 1] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row + 1][column = 1] = '2';
                               bombBoard[row + 1][column + 1] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row + 1][column + 1] = '3';
                               bombBoard[row + 1][column + 1] = '3';
                               dotCount -=  1;
                           }
                           if (flood_fill_Count == 4) 
                           {
                               board[row + 1][column + 1] = '4';
                               bombBoard[row + 1][column + 1] = '4';
                               dotCount -= 1;
                           }
                        }

                        else if (board[row + 1][column + 1] == '.')
                        {
                            board[row + 1][column + 1] = ' ';
                            bombBoard[row + 1][column + 1] = ' ';
                            dotCount -= 1;   
                        }
                     
                        if (bombBoard[row - 1][column + 1] == '.' && bombBoard[row - 2][column + 1] == '*'
                           || bombBoard[row - 1][column + 1] == '.' && bombBoard[row - 2][column + 2] == '*'
                           || bombBoard[row - 1][column + 1] == '.' && bombBoard[row - 1][column + 2] == '*'
                           || bombBoard[row -1][column + 1] == '.' && bombBoard[row][column + 2] == '*')
                        {
                           flood_fill_Count = 0;
                           if (bombBoard[row - 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 1][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row - 1][column + 1] = '1';
                               bombBoard[row - 1][column + 1] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row - 1][column + 1] = '2';
                               bombBoard[row - 1][column + 1] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row - 1][column + 1] = '3';
                               bombBoard[row - 1][column + 1] = '3';
                               dotCount -=  1;
                           }
                           if (flood_fill_Count == 4)
                           {
                               board[row - 1][column + 1] = '4';
                               bombBoard[row - 1][column + 1] = '4';
                               dotCount -= 1;
                           }
                        }

                        else if (board[row - 1][column + 1] == '.')
                        {
                            board[row - 1][column + 1] = ' ';
                            bombBoard[row - 1][column + 1] = ' ';
                            dotCount -= 1;
                        }

                        if (bombBoard[row + 1][column - 1] == '.' && bombBoard[row + 2][column - 1] == '*'
                           || bombBoard[row + 1][column - 1] == '.' && bombBoard[row + 2][column] == '*')
                        {
                           flood_fill_Count = 0;
                           if (bombBoard[row + 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row + 1][column - 1] = '1';
                               bombBoard[row + 1][column - 1] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row + 1][column - 1] = '2';
                               bombBoard[row + 1][column - 1] = '2';
                               dotCount -= 1;
                           }
                        }

                        else if (board[row + 1][column - 1] == '.')
                        {
                            board[row + 1][column - 1] = ' ';
                            bombBoard[row + 1][column - 1] = ' ';
                            dotCount -= 1;
                        }

                        if (bombBoard[row - 1][column - 1] == '.' && bombBoard[row - 2][column - 1] == '*'
                           || bombBoard[row - 1][column - 1] == '.' && bombBoard[row - 2][column] == '*')
                        {
                           flood_fill_Count = 0;
                           if (bombBoard[row - 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row - 1][column - 1] = '1';
                               bombBoard[row - 1][column - 1] = '1';
                               dotCount -= 1;
                           }      
                           if (flood_fill_Count == 2)
                           {
                               board[row - 1][column - 1] = '2';
                               bombBoard[row - 1][column - 1] = '2';
                               dotCount -= 1;
                           }
                        }

                        else if (board[row - 1][column - 1] == '.')
                        {
                            board[row - 1][column - 1] = ' ';
                            bombBoard[row - 1][column - 1] = ' ';
	                    dotCount -= 1;
                        }
                          
                        if (board[row][column - 1] == '.')
                        {
                            board[row][column - 1] = ' ';
                            bombBoard[row][column - 1] = ' ';
                            dotCount -= 1;
                        }   

                    printf("  0 1 2 3 4 5 6 7 8 9\n"); 

                    for (t = 0; t < 10; t++)
                    {         
                        printf("%d" , t);                 

                        for (j = 0; j < 10; j++) 
                        {
                            printf("%2c" , board[t][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");

               }
               else if (specialBoard[row][column] == 's')
               {
                   board[row][column] = '0';
                   bombBoard[row][column] = '0';

                   for (i = 0; i < 9; i++)
                   {
                       if (board[row + 1][column - 1] == i + '0')
                       {
                           board[row + 1][column - 1] = i + '0';
                           bombBoard[row + 1][column - 1] = i + '0';
                           break;
                       }
                   }

                   for (i = 0; i < 9; i++)
                   {
                       if (board[row + 1][column] == i + '0')
                       {
                           board[row + 1][column] = i + '0';
                           bombBoard[row + 1][column] = i + '0';
                           break;
                       }
                   }

                   for (i = 0; i < 9; i++)
                   {
                       if (board[row - 1][column] == i + '0')
                       {
                           board[row - 1][column] = i + '0';
                           bombBoard[row - 1][column] = i + '0';
                           break;
                       }
                   }

                   for (i = 0; i < 9; i++)
                   {
                       if (board[row][column - 1] == i + '0')
                       {
                           board[row][column - 1] = i + '0';
                           bombBoard[row][column - 1] = i + '0';
                           break;
                       }
                   }

                   for (i = 0; i < 9; i++)
                   {
                       if (board[row + 1][column + 1] == 1 + '0')
                       {
                           board[row + 1][column + 1] = i + '0';
                           bombBoard[row + 1][column + 1] = i + '0';
                           break;
                       }
                   }

                   for (i = 0; i < 9; i++)
                   {
                       if (board[row - 1][column - 1] == i + '0')
                       {
                           board[row - 1][column - 1] = i + '0';
                           bombBoard[row - 1][column - 1] = i + '0';
                           break;
                       }
                   }

                   for (i = 0; i < 9; i++)
                   {
                       if (board[row - 1][column + 1] == i + '0')
                       {
                           board[row - 1][column + 1] = i + '0';
                           bombBoard[row - 1][column + 1] = i + '0';
                           break;
                       }
                   }
     
                       if (bombBoard[row + 1][column] == '.' && bombBoard[row + 2][column] == '*'
                          || bombBoard[row + 1][column] == '.' && bombBoard[row + 2][column - 1] == '*'
                          || bombBoard[row + 1][column] == '.' && bombBoard[row + 2][column + 1] == '*')
                       {
                           if (bombBoard[row + 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row + 1][column] = '1';
                               bombBoard[row + 1][column] = '1';
                               dotCount -= 1;
                           }      

                           if (flood_fill_Count == 2)
                           {
                               board[row + 1][column] = '2';
                               bombBoard[row + 1][column] = '2';
                               dotCount -= 1;
                           }

                           if (flood_fill_Count == 3)
                           {
                               board[row + 1][column] = '3';
                               bombBoard[row + 1][column] = '3';
                               dotCount -=  1;
                           }
                       }

                       else if (board[row + 1][column] == '.')
                       {
                           board[row + 1][column] = ' ';
                           bombBoard[row + 1][column] = ' ';
                           dotCount -= 1;
                       }
                  
                       if (board[row][column + 1] == '.')
                       {
                           board[row][column + 1] = ' ';
                           bombBoard[row][column + 1] = ' ';
                           dotCount -= 1;
                       }
                   
                       if (bombBoard[row - 1][column] == '.' && bombBoard[row - 2][column] == '*'
                          || bombBoard[row - 1][column] == '.' && bombBoard[row - 2][column - 1] == '*'
                          || bombBoard[row - 1][column] == '.' && bombBoard[row - 2][column + 1] == '*')
                       {
                           flood_fill_Count = 0;
                           if (bombBoard[row - 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row - 1][column] = '1';
                               bombBoard[row - 1][column] = '1';
                               dotCount -= 1;
                           }      

                           if (flood_fill_Count == 2)
                           {
                               board[row - 1][column] = '2';
                               bombBoard[row - 1][column] = '2';
                               dotCount -= 1;
                           }

                           if (flood_fill_Count == 3)
                           {
                               board[row - 1][column] = '3';
                               bombBoard[row - 1][column] = '3';
                               dotCount -=  1;
                           }
                       }

                       else if (board[row - 1][column] == '.')
                       {
                           board[row - 1][column] = ' ';
                           bombBoard[row - 1][column] = ' ';
                           dotCount -= 1;
                       }

                       if (bombBoard[row][column - 1] == '.' && bombBoard[row][column - 2] == '*'
                          || bombBoard[row][column - 1] == '.' && bombBoard[row - 1][column - 2] == '*'
                          || bombBoard[row][column - 1] == '.' && bombBoard[row + 1][column - 2] == '*')
                       {
                           flood_fill_Count = 0;
                           if (bombBoard[row][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 1][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 1][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row][column - 1] = '1';
                               bombBoard[row][column - 1] = '1';
                               dotCount -= 1;
                           }      

                           if (flood_fill_Count == 2)
                           {
                               board[row][column - 1] = '2';
                               bombBoard[row][column - 1] = '2';
                               dotCount -= 1;
                           }

                           if (flood_fill_Count == 3)
                           {
                               board[row][column - 1] = '3';
                               bombBoard[row][column - 1] = '3';
                               dotCount -=  1;
                           }
                       }

                       else if (board[row][column - 1] == '.')
                       {
                           board[row][column - 1] = ' ';
                           bombBoard[row][column - 1] = ' ';
                           dotCount -= 1;
                       }     
                    
                       if (bombBoard[row + 1][column + 1] == '.' && bombBoard[row + 2][column + 1] == '*'
                          || bombBoard[row + 1][column + 1] == '.' && bombBoard[row + 1][column] == '*')
                       {
                           flood_fill_Count = 0;
                           if (bombBoard[row + 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 1][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row + 1][column + 1] = '1';
                               bombBoard[row + 1][column + 1] = '1';
                               dotCount -= 1;
                           }      

                           if (flood_fill_Count == 2)
                           {
                               board[row + 1][column + 1] = '2';
                               bombBoard[row + 1][column + 1] = '2';
                               dotCount -= 1;
                           }
                       }

                       else if (board[row + 1][column + 1] == '.')
                       {
                           board[row + 1][column + 1] = ' ';   
                           bombBoard[row + 1][column + 1] = ' ';
                           dotCount -= 1;
                       }
                                        
                       if (bombBoard[row - 1][column - 1] == '.' && bombBoard[row - 2][column - 2] == '*'
                          || bombBoard[row - 1][column - 1] == '.' && bombBoard[row - 2][column - 1] == '*'
                          || bombBoard[row - 1][column - 1] == '.' && bombBoard[row - 1][column - 2] == '*'
                          || bombBoard[row - 1][column - 1] == '.' && bombBoard[row][column - 2] == '*')
                       {
                           flood_fill_Count = 0;
                           if (bombBoard[row - 2][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 1][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row - 1][column - 1] = '1';
                               bombBoard[row - 1][column - 1] = '1';
                               dotCount -= 1;
                           }      

                           if (flood_fill_Count == 2)
                           {
                               board[row - 1][column - 1] = '2';
                               bombBoard[row - 1][column - 1] = '2';
                               dotCount -= 1;
                           }

                           if (flood_fill_Count == 3)
                           {
                               board[row - 1][column - 1] = '3';
                               bombBoard[row - 1][column - 1] = '3';
                               dotCount -=  1;
                           }
                           if (flood_fill_Count == 4)
                           {
                               board[row - 1][column - 1] = '4';
                               bombBoard[row - 1][column - 1] = '4';
                               dotCount -= 1;
                           }
                       }

                       else if (board[row - 1][column - 1] == '.')
                       {
                           board[row - 1][column - 1] = ' ';
                           bombBoard[row - 1][column - 1] = ' ';
	                   dotCount -= 1;
                       }
                   
                       if (bombBoard[row - 1][column + 1] == '.' && bombBoard[row - 2][column + 1] == '*'
                          || bombBoard[row - 1][column + 1] == '.' && bombBoard[row - 2][column] == '*')
                       {
                           flood_fill_Count = 0;
                           if (bombBoard[row - 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row - 1][column + 1] = '1';
                               bombBoard[row - 1][column + 1] = '1';
                               dotCount -= 1;
                           }      

                           if (flood_fill_Count == 2)
                           {
                               board[row - 1][column + 1] = '2';
                               bombBoard[row - 1][column + 1] = '2';
                               dotCount -= 1;
                           }
                       }

                       else if (board[row - 1][column + 1] == '.')
                       {
                           board[row - 1][column + 1] = ' ';
                           bombBoard[row - 1][column + 1] = ' ';
                           dotCount -= 1;
                       }
                  
                       if (bombBoard[row + 1][column - 1] == '.' && bombBoard[row][column - 2] == '*'
                          || bombBoard[row + 1][column - 1] == '.' && bombBoard[row + 1][column - 2] == '*'
                          || bombBoard[row + 1][column - 1] == '.' && bombBoard[row + 2][column - 2] == '*'
                          || bombBoard[row + 1][column - 1] == '.' && bombBoard[row + 2][column - 1] == '*')
                       {
                           flood_fill_Count = 0;
                           if (bombBoard[row][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 1][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row + 1][column - 1] = '1';
                               bombBoard[row + 1][column - 1] = '1';
                               dotCount -= 1;
                           }      

                           if (flood_fill_Count == 2)
                           {
                               board[row + 1][column - 1] = '2';
                               bombBoard[row + 1][column - 1] = '2';
                               dotCount -= 1;
                           }

                           if (flood_fill_Count == 3)
                           {
                               board[row + 1][column - 1] = '3';
                               bombBoard[row + 1][column - 1] = '3';
                               dotCount -=  1;
                           }
                           if (flood_fill_Count == 4)
                           {
                               board[row + 1][column - 1] = '4';
                               bombBoard[row + 1][column - 1] = '4';
                               dotCount -=  1;
                           }
                       }

                       else if (board[row + 1][column - 1] == '.')
                       {
                           board[row + 1][column - 1] = ' ';
                           bombBoard[row + 1][column - 1] = ' ';
                           dotCount -= 1;
                       }
                   
                   printf("  0 1 2 3 4 5 6 7 8 9\n"); 

                   for (t = 0; t < 10; t++)
                   {         
                       printf("%d" , t);                 

                       for (j = 0; j < 10; j++) 
                       {
                           printf("%2c" , board[t][j]);
                       }
                       printf("\n");
                   }
                   printf("\n");
               }
               /*This else is if the user doens't choose the first two or last two columns. Basically if the user
               chooses a middle tile*/
               else
               {
                   board[row][column] = '0';
                   bombBoard[row][column] = '0';
 
                   for (i = 0; i < 9; i++)
                   {
                       if (board[row + 1][column] == i + '0')
                       {
                           board[row + 1][column] = i + '0';
                           bombBoard[row + 1][column] = i + '0';
                           break;
                       }
                   }      

                   for (i = 0; i < 9; i++)
                   {
                       if (board[row][column + 1] == i + '0')
                       {
                           board[row][column + 1] = i + '0';
                           bombBoard[row][column + 1] = i + '0';
                           break;
                       }
                   }

                   for (i = 0; i < 9; i++)
                   {
                       if (board[row - 1][column] == i + '0')
                       {
                           board[row - 1][column] = i + '0';
                           bombBoard[row - 1][column] = i + '0';
                           break;
                       }
                   }

                   for (i = 0; i < 9; i++)
                   {
                       if (board[row][column - 1] == i + '0')
                       {
                           board[row][column - 1] = i + '0';
                           bombBoard[row][column - 1] = i + '0';
                           break;
                       }
                   }

                   for (i = 0; i < 9; i++)
                   {
                       if (board[row + 1][column + 1] == 1 + '0')
                       {
                           board[row + 1][column + 1] = i + '0';
                           bombBoard[row + 1][column + 1] = i + '0';
                           break;
                       }
                   }

                   for (i = 0; i < 9; i++)
                   {
                       if (board[row - 1][column - 1] == i + '0')
                       {
                           board[row - 1][column - 1] = i + '0';
                           bombBoard[row - 1][column - 1] = i + '0';
                           break;
                       }
                   }

                   for (i = 0; i < 9; i++)
                   {
                       if (board[row - 1][column + 1] == i + '0')
                       {
                           board[row - 1][column + 1] = i + '0';
                           bombBoard[row - 1][column + 1] = i + '0';
                           break;
                       }
                   }
                  
                   for (i = 0; i < 9; i++)
                   {
                       if (board[row + 1][column - 1] == i + '0')
                       {
                           board[row + 1][column - 1] = i + '0';
                           bombBoard[row + 1][column - 1] = i + '0';
                           break;
                       }
                   }

                       if (bombBoard[row + 1][column] == '.' && bombBoard[row + 2][column] == '*'
                          || bombBoard[row + 1][column] == '.' && bombBoard[row + 2][column - 1] == '*'
                          || bombBoard[row + 1][column] == '.' && bombBoard[row + 2][column + 1] == '*')
                       {
                           if (bombBoard[row + 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row + 1][column] = '1';
                               bombBoard[row + 1][column] = '1';
                               dotCount -= 1;
                           }      

                           if (flood_fill_Count == 2)
                           {
                               board[row + 1][column] = '2';
                               bombBoard[row + 1][column] = '2';
                               dotCount -= 1;
                           }

                           if (flood_fill_Count == 3)
                           {
                               board[row + 1][column] = '3';
                               bombBoard[row + 1][column] = '3';
                               dotCount -=  1;
                           }
                       }

                       else if (board[row + 1][column] == '.')
                       {
                           board[row + 1][column] = ' ';
                           bombBoard[row + 1][column] = ' ';
                           dotCount -= 1;
                       }        
          
                       if (bombBoard[row][column + 1] == '.' && bombBoard[row][column + 2] == '*'
                          || bombBoard[row][column + 1] == '.' && bombBoard[row + 1][column + 2] == '*'
                          || bombBoard[row][column + 1] == '.' && bombBoard[row - 1][column + 2] == '*')
                       {
                           flood_fill_Count = 0;
                           if (bombBoard[row][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 1][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 1][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row][column + 1] = '1';
                               bombBoard[row][column + 1] = '1';
                               dotCount -= 1;
                           }                   
                           if (flood_fill_Count == 2)
                           {
                               board[row][column + 1] = '2';
                               bombBoard[row][column + 1] = '2';
                               dotCount -= 1;
                           }

                           if (flood_fill_Count == 3)
                           {
                               board[row][column + 1] = '3';
                               bombBoard[row][column + 1] = '3';
                               dotCount -= 1;
                           }   
                       }

                       else if (board[row][column + 1] == '.')
                       {
                           board[row][column + 1] = ' ';
                           bombBoard[row][column + 1] = ' ';
                           dotCount -= 1;
                       }

                       if (bombBoard[row - 1][column] == '.' && bombBoard[row - 2][column] == '*'
                          || bombBoard[row - 1][column] == '.' && bombBoard[row - 2][column - 1] == '*'
                          || bombBoard[row - 1][column] == '.' && bombBoard[row - 2][column + 1] == '*')
                       {
                           flood_fill_Count = 0;
                           if (bombBoard[row - 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row - 1][column] = '1';
                               bombBoard[row - 1][column] = '1';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 2)
                           {
                               board[row - 1][column] = '2';
                               bombBoard[row - 1][column] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row - 1][column] = '3';
                               bombBoard[row - 1][column] = '3';
                               dotCount -= 1;
                           }
                       }

                       else if (board[row - 1][column] == '.')
                       {
                           board[row - 1][column] = ' ';
                           bombBoard[row - 1][column] = ' ';
                           dotCount -= 1;
                       }

                       if (bombBoard[row][column - 1] == '.' && bombBoard[row][column - 2] == '*'
                          || bombBoard[row][column - 1] == '.' && bombBoard[row - 1][column - 2] == '*'
                          || bombBoard[row][column - 1] == '.' && bombBoard[row + 1][column - 2] == '*')
                       {  
                           flood_fill_Count = 0;
                           if (bombBoard[row][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 1][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 1][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row][column - 1] = '1';
                               bombBoard[row][column - 1] = '1';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 2)
                           {
                               board[row][column - 1] = '2';
                               bombBoard[row][column - 1] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row][column - 1] = '3';
                               bombBoard[row][column - 1] = '3';
                               dotCount -= 1;
                           }
                       }

                       else if (board[row][column - 1] == '.')
                       {
                           board[row][column - 1] = ' ';
                           bombBoard[row][column - 1] = ' ';
                           dotCount -= 1;
                       }  
                     
                       if (bombBoard[row + 1][column + 1] == '.' && bombBoard[row][column + 2] == '*'
                          || bombBoard[row + 1][column + 1] == '.' && bombBoard[row + 1][column + 2] == '*'
                          || bombBoard[row + 1][column + 1] == '.' && bombBoard[row + 2][column + 2] == '*'
                          || bombBoard[row + 1][column + 1] == '.' && bombBoard[row + 2][column + 1] == '*')
                       {
                           flood_fill_Count = 0;
                           if (bombBoard[row][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 1][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row + 1][column + 1] = '1';
                               bombBoard[row + 1][column + 1] = '1';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 2)
                           {
                               board[row + 1][column + 1] = '2';
                               bombBoard[row + 1][column + 1] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row + 1][column + 1] = '3';
                               bombBoard[row + 1][column + 1] = '3';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 4)
                           {
                               board[row + 1][column + 1] = '4';
                               bombBoard[row + 1][column + 1] = '4';
                               dotCount -= 1;
                           }
                       }

                       else if (board[row + 1][column + 1] == '.')
                       {
                           board[row + 1][column + 1] = ' ';   
                           bombBoard[row + 1][column + 1] = ' ';
                           dotCount -= 1;
                       }
                     
                       if (bombBoard[row - 1][column - 1] == '.' && bombBoard[row - 2][column - 2] == '*'
                          || bombBoard[row - 1][column - 1] == '.' && bombBoard[row - 2][column - 1] == '*'
                          || bombBoard[row - 1][column - 1] == '.' && bombBoard[row - 1][column - 2] == '*'
                          || bombBoard[row - 1][column - 1] == '.' && bombBoard[row][column - 2] == '*')
                       {
                           flood_fill_Count = 0;
                           if (bombBoard[row - 2][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 1][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row - 1][column - 1] = '1';
                               bombBoard[row - 1][column - 1] = '1';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 2)
                           {
                               board[row - 1][column - 1] = '2';
                               bombBoard[row - 1][column - 1] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row - 1][column - 1] = '3';
                               bombBoard[row - 1][column - 1] = '3';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 4)
                           {
                               board[row - 1][column-+ 1] = '4';
                               bombBoard[row - 1][column - 1] = '4';
                               dotCount -= 1;
                           }
                       }

                       else if (board[row - 1][column - 1] == '.')
                       {
                           board[row - 1][column - 1] = ' ';
                           bombBoard[row - 1][column - 1] = ' ';
	                   dotCount -= 1;
                       }
                   
                       if (bombBoard[row - 1][column + 1] == '.' && bombBoard[row - 2][column + 1] == '*'
                          || bombBoard[row - 1][column + 1] == '.' && bombBoard[row - 2][column + 2] == '*'
                          || bombBoard[row - 1][column + 1] == '.' && bombBoard[row - 1][column + 2] == '*'
                          || bombBoard[row -1][column + 1] == '.' && bombBoard[row][column + 2] == '*')
                       {
                           flood_fill_Count = 0;
                           if (bombBoard[row - 2][column + 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 2][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row - 1][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row][column + 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row - 1][column + 1] = '1';
                               bombBoard[row - 1][column + 1] = '1';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 2)
                           {
                               board[row - 1][column + 1] = '2';
                               bombBoard[row - 1][column + 1] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row - 1][column + 1] = '3';
                               bombBoard[row - 1][column + 1] = '3';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 4)
                           {
                               board[row - 1][column + 1] = '4';
                               bombBoard[row - 1][column + 1] = '4';
                               dotCount -= 1;
                           }
                       }

                       else if (board[row - 1][column + 1] == '.')
                       {
                           board[row - 1][column + 1] = ' ';
                           bombBoard[row - 1][column + 1] = ' ';
                           dotCount -= 1;
                       }
                   
                       if (bombBoard[row + 1][column - 1] == '.' && bombBoard[row][column - 2] == '*'
                          || bombBoard[row + 1][column - 1] == '.' && bombBoard[row + 1][column - 2] == '*'
                          || bombBoard[row + 1][column - 1] == '.' && bombBoard[row + 2][column - 2] == '*'
                          || bombBoard[row + 1][column - 1] == '.' && bombBoard[row + 2][column - 1] == '*'
                          || bombBoard[row + 1][column - 1] == '.' && bombBoard[row + 2][column] == '*')
                       {
                           flood_fill_Count = 0;
                           if (bombBoard[row][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 1][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column - 2] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column - 1] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (bombBoard[row + 2][column] == '*')
                           {
                               flood_fill_Count++;
                           }
                           if (flood_fill_Count == 1)
                           {
                               board[row + 1][column - 1] = '1';
                               bombBoard[row + 1][column - 1] = '1';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 2)
                           {
                               board[row + 1][column - 1] = '2';
                               bombBoard[row + 1][column - 1] = '2';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 3)
                           {
                               board[row + 1][column - 1] = '3';
                               bombBoard[row + 1][column - 1] = '3';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 4)
                           {
                               board[row + 1][column - 1] = '4';
                               bombBoard[row + 1][column - 1] = '4';
                               dotCount -= 1;
                           }
                           if (flood_fill_Count == 5)
                           {
                               board[row + 1][column - 1] = '5';
                               bombBoard[row + 1][column - 1] = '5';
                               dotCount -= 1;
                           }
                       }

                       else if (board[row + 1][column - 1] == '.')
                       {
                           board[row + 1][column - 1] = ' ';
                           bombBoard[row + 1][column - 1] = ' ';
                           dotCount -= 1;
                       }
                   
                   printf("  0 1 2 3 4 5 6 7 8 9\n"); 

                   for (t = 0; t < 10; t++)
                   {         
                       printf("%d" , t);                 

                       for (j = 0; j < 10; j++) 
                       {
                           printf("%2c" , board[t][j]);
                       }
                       printf("\n");
                   }
                   printf("\n");
               } //end else statement
           } //end if (mineCount == 0)
           /*The dotCount has been subracting from 90. If it equals 0 then the user has 
           uncovered all the spaces except the mines and they win*/
           if (dotCount == 0)
           {
               printf("You win!\n\n");
               exit(0);     
           }    
        } //end else if(bombBoard[row][column == '.')
    } //end else
} //end flood_fill
 
int main(int argc, char *argv[])
{
    char board[10][10]; //this is the board that will be displayed for the user
    char bombBoard[10][10]; //this is the board that holds all the bombs in it
    char specialBoard[10][10]; //this is the board that holds characters for the first two and last two columns
    int i;
    int j;
    int counter = 0;
    srand(time(NULL));
    int row;
    int column;
    char enter[1]; //this is for a scanf for the user to begin the game

    /* Putting dots in the display board and bombBoard*/
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            board[i][j] = '.';
            bombBoard[i][j] = '.';           
        }
    }

    /*This is putting characters in the first two and last two columns in the specialBoard*/
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (j == 0 && row < 9)
            {
                specialBoard[i][j] = 'w'; 
            }
            else if (j == 1 && row < 9)
            {
                specialBoard[i][j] = 't';
            }
            else if (j == 8 && row < 9)
            {
                specialBoard[i][j] = 's';
            }
            else if (j == 9 && row < 9)
            {
                specialBoard[i][j] = 'x';
            }
            else
            {
                specialBoard[i][j] = '.';
            }
        }
    }

    /*Putting 10 random astericks in the bombBoard*/
    while (counter < 10)
    {
        int rand1 = rand() % 10;
        int rand2 = rand() % 10;

        if (bombBoard[rand1][rand2] == '*')
        {
            int r1 = rand() % 10;
            int r2 = rand() % 10;

            bombBoard[r1][r2] = '*';
        }
        else
        {
            bombBoard[rand1][rand2] = '*';
        }
        counter++;
    }

    printf("\nWelcome to Minesweeper! Press enter when you are ready to play!");
    scanf("%c", &enter);
    printf("\n");
  
    printf("  0 1 2 3 4 5 6 7 8 9\n");

    for (i = 0; i < 10; i++)
    {
        printf("%d" , i);

        for (j = 0; j < 10; j++)
        {   
            printf("%2c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    /*Infinite loop for the game to be played until the user loses or wins. Notice it extends past the flood_fill function*/
    while(1)
    {
  
    printf("Enter a row and column (0-9): ");
    scanf("%d %d", &row, &column);

    printf("\n");

    flood_fill(bombBoard, board, specialBoard, row, column);

    }

    return 0;
}


