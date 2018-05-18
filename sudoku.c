/*
Solve sudoku using backtracking method.
*/
#include<stdio.h>
#define N 9

int isValid(int sudoku[N][N], int value, int row, int col){
	int x,i,j;
	for(x=0;x<N;x++){
		if(sudoku[row][x]==value)
			return 0;
		else if(sudoku[x][col]==value)
			return 0;
	}
	if(row<3){
		if(col<3){
			for(i=0;i<3;i++)
				for(j=0;j<3;j++)
					if(sudoku[i][j]==value)
						return 0;
		}else if(col>=3 && col<6){
			for(i=0;i<3;i++)
                                for(j=3;j<6;j++)
                                        if(sudoku[i][j]==value)
                                                return 0;
		}else{
			for(i=0;i<3;i++)
                                for(j=6;j<9;j++)
                                        if(sudoku[i][j]==value)
                                                return 0;
		}
	}else if(row>=3 && row<6){
		if(col<3){
                        for(i=3;i<6;i++)
                                for(j=0;j<3;j++)
                                        if(sudoku[i][j]==value)
                                                return 0;
                }else if(col>=3 && col<6){
                        for(i=3;i<6;i++)
                                for(j=3;j<6;j++)
                                        if(sudoku[i][j]==value)
                                                return 0;
                }else{
                        for(i=3;i<6;i++)
                                for(j=6;j<9;j++)
                                        if(sudoku[i][j]==value)
                                                return 0;
                }
	}else{
		if(col<3){
                        for(i=6;i<9;i++)
                                for(j=0;j<3;j++)
                                        if(sudoku[i][j]==value)
                                                return 0;
                }else if(col>=3 && col<6){
                        for(i=6;i<9;i++)
                                for(j=3;j<6;j++)
                                        if(sudoku[i][j]==value)
                                                return 0;
                }else{
                        for(i=6;i<9;i++)
                                for(j=6;j<9;j++)
                                        if(sudoku[i][j]==value)
                                                return 0;
                }
	}
	return 1;
}

int solveSudoku(int sudoku[N][N]){
	int i,j,k;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(sudoku[i][j]!=0)    //Find the blank space to put a number
				continue;
			for(k=1;k<=9;k++){
				if(isValid(sudoku,k,i,j)){     //Checks if we can put number k at i,j location.
					sudoku[i][j]=k;
					if(solveSudoku(sudoku)==0){   //if result of putting this number doesn't lead to solution
						sudoku[i][j]=0;	      //then discard that number and try next number.
						continue;
					}else{
						break;                //if result is ok then keep the number and go ahead with next 
					}			      //blank space
				}
			}
			if(k==10)	//if none of the numbers are working for this spot then return error.
				return 0;
		}
	}
	return 1;	//if sudoku is solved then return 1
} 

void displaySudoku(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);

        printf("\n");
    }
    printf("\n");
}

int main()
{
    int mat[N][N] =
    {
        {0,0,0,0,0,0,0,0,2},
        {0,0,0,0,0,0,9,4,0},
        {0,0,3,0,0,0,0,0,5},
        {0,9,2,3,0,5,0,7,4},
	{8,4,0,0,0,0,0,0,0},
	{0,6,7,0,9,8,0,0,0},
	{0,0,0,7,0,6,0,0,0},
	{0,0,0,9,0,0,0,2,0},
	{4,0,8,5,0,0,3,6,0}
    };
    solveSudoku(mat);
    // Print solved sudoku
    displaySudoku(mat);
    return 0;
}
