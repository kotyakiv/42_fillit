# 42_fillit
The aim of the project is to find a way to assemble a given Tetriminos set 
altogether in the smallest possible square. Tetriminos has the same shape as in the famous game **Tetris**
## Input
Pass as an argument file with the Tetriminos seperated by new line
```
####
....  
....  
....

....
..#.
.###
....

...#
...#
..##
....

##..
.##.
....
....
```
The shape of Tetriminos must consist of '**#**' and empty spaces with '**.**'
## Errors
If there is more than 4 columns or 4 rows in each Tetriminos input  
another characters than hash or dot  
not seperated with new line or too many new lines  
more than 26 Tetriminos  
no shapes as in the original **Tetris**
## Output
Combined set of Tetriminos in the one smallest possible square. All Tetriminos got letters from A to Z to identify them in the square in the order as they were passed.
