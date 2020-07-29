Backtracking is a general algorithm for finding all (or some) solutions to some computational problems, notably constraint satisfaction problems,
that incrementally builds candidates to the solutions, and abandons a candidate ("backtracks") as soon as it determines that the candidate cannot
possibly be completed to a valid solution.[1][2]

The classic textbook example of the use of backtracking is the eight queens puzzle, that asks for all arrangements of eight chess queens on a
standard chessboard so that no queen attacks any other. In the common backtracking approach, the partial candidates are arrangements of k queens
in the first k rows of the board, all in different rows and columns. Any partial solution that contains two mutually attacking queens can be abandoned.

Eight queens puzzle
From Wikipedia, the free encyclopedia

The only symmetrical solution to the eight queens puzzle (up to rotation and reflection)
The eight queens puzzle is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other; thus, a solution
requires that no two queens share the same row, column, or diagonal. The eight queens puzzle is an example of the more general n queens problem of
placing n non-attacking queens on an n×n chessboard, for which solutions exist for all natural numbers n with the exception of n = 2 and n = 3