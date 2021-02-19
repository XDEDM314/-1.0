#define row 32
#define lin 32
void start();
void initialize(char board[row][lin]);
void display(char board[row][lin]);
int iswrong(char board[row][lin],int x,int y);
int iswin(char board[row][lin], int x, int y);
