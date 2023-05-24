#include "sudoku.h"

/*Ayan Deka: In this MP, I did five functions. The first function that I did was to see if the value was in the row. The second function that I did was to see if 
the value was in the column. The third function I did was to see if the value is in a three by three array based on the position inputed. The fourth function was to
 see if the value is valid, which uses the three functions that I did previously. The final function that I did was the solve sudoku function. I used the alogirthm 
that was given in the course wiki, and used recursive backtracking to successfully complete the function. 


*/


// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

  assert(i>=0 && i<9);

  // BEG TODO
  for (int column = 0;column<9;column++){

    if(sudoku[i][column]==val){//checks if value is in the row with i. 
      return 1;
    }

  }
  return 0;
  // END TODO
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9);

  // BEG TODO
  for (int row = 0;row<9;row++){

    if(sudoku[row][j]==val){//checks if the value is in the column with j
      return 1;
    }

  }
  
  return 0;
  // END TODO
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {
   
  assert(i>=0 && i<9);


  
  // BEG TODO

  int startOfThreeByThreeRow = (i/3) * 3;//this sets up the parameters for the three by three array, (we divide by three and then multiply so it starts from the 
                                         //top left
                                         
  int startOfThreeByThreeColumn = (j/3) * 3;

  int endOfThreeByThreeRow = startOfThreeByThreeRow + 3;//this sets up the end of the parameter.
  int endOfThreeByThreeColumn = startOfThreeByThreeColumn + 3;

  for(int x = startOfThreeByThreeRow; x < endOfThreeByThreeRow ;x++){//goes through the parameters and checks if it is equal to the value. 
    for(int y = startOfThreeByThreeColumn; y < endOfThreeByThreeColumn;y++){
      if(sudoku[x][y]==val){
	return 1;
      }
    }
  }
  
  return 0;
  // END TODO
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);

  // BEG TODO

  if(is_val_in_row(val,i,sudoku) == 1 || is_val_in_col(val,j,sudoku)==1 ||is_val_in_3x3_zone(val,i,j,sudoku) == 1){//is valid if any of these is true
    return 0;
  }else{

  
  return 1;

  }
  // END TODO
}



// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) {
  // BEG TODO

  int row,col;//row and column location of the empty location
  int checkIfAllAssigned = 1;//variable to see if all are assigned
  int foundZero=0;//checks to see if an empty location was found

  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      if (sudoku[i][j] == 0){
	checkIfAllAssigned = 0;//iterates through the whole sudoku, if it is zero, then sets checkIfAllAssigned to zero. 
      }
    }
  }


  if(checkIfAllAssigned==1){

    return 1;//returns one is checkIfAllAssigned is 1

  }else{


    for(row=0;row<9;row++){
      for(col=0;col<9;col++){
	if(sudoku[row][col] == 0){//goes through the whole sudoku, and checks for the zero
	  foundZero = 1;//set this to 1 once found, and break
	  break;
	}
       
      }
      if(foundZero == 1){//break out of the outer forloop
	break;
      }
    }
    
  }

 
  for (int num = 1; num <= 9; num++){
    if (is_val_valid(num, row, col, sudoku) == 1){
      sudoku[row][col] = num; //sets the empty location to number if any of the above recursive backtracking methods  equals 1. 
      if (solve_sudoku(sudoku) == 1){
        return 1;//returns 1 is all the empty locations are filled up
      }
      sudoku[row][col] = 0;//otherwsie set to zero
    }
  }
  return 0;
  // END TODO.
}


// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}





