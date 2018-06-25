# N-queens
n皇后问题。即n*n的棋盘格上，共放置n个“皇后”，使得每个“皇后”所在的行和列以及斜行均没有其他“皇后”。

问题：给定n，求出放置的所有可能，以及可能的个数。

思路：类似问题“数独”。典型的回溯问题。
     从第一行第一列开始放棋子，并判断该位置放棋子是否成立。
     是否成立：需要传入该棋子的行与列。判断其行在其之前是否有棋子，其列在其之上是否有棋子，其左斜上方以及右斜上方是否有棋子。（只判断之前，
     是因为后面还没放，遍历是按照顺序的）
     若成立，就将该位置为‘Q’，再次调用回溯函数，参数为 行数+1。若该回溯函数返回，则说明此路不通，就将该位置回为‘.’。