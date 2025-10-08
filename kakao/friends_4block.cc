#include <vector>
#include <string>
#include <algorithm>
#include <set>

#define Y first
#define X second

using std::set;
using std::string;
using std::pair;
using std::vector;
/**

2x2 형태의 동일 블록이 붙어있을 경우 사라지면서 점수 획득
2x2 형태의 블록이 여러개가 있으면 모두 지워짐
예를 들어 1칸 또는 2칸을 공유하더라도 모두 지워짐 -> 상, 하, 좌, 우 2칸 공유 또는 대각선 4방향 1칸 공유

블록이 지워진 후에는 블록은 모두 아래로 당겨짐
빈 공간을 채운 후 다시 2x2 형태의 블록을 검사

블록 -> 하나의 문자
R, M, A, F, N, T, J, C
첫 배치가 주어졌을 때 지워지는 블로긍ㄴ 모두 몇 개인지 판단하라.


<삭제되는 문자의 개수를 리턴하라>

보드 높이: 2 <=m <= 30
보드 폭: 2<= n <= 30


*/

// 변수
int width,height,answer = 0;
vector<vector<char>> board;
set<pair<int, int>> pos;
// 함수

// 입력
void allocateCharVector(vector<string>& board){
    vector<vector<char>> b(height,vector<char>(width));
    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width; j++){
            b[i][j] = board[i][j];
        }
    }
   	::board = b;
}

// 2x2 블록 탐색
bool retrieveSqaureBlock(){
    pos.clear();
    for(int i = 0 ; i < height- 1 ; i++){
        for(int j = 0 ; j < width - 1 ; j++){
            if( board[i][j] != '.' && // CHEKC: 가장 중요한 부분을 놓친거...
                board[i][j] == board[i][j+1] &&
               board[i][j] == board[i+1][j+1] &&
			   board[i][j] == board[i+1][j]){
               	pos.insert(std::make_pair(i,j)) ;
               	pos.insert(std::make_pair(i+1,j)) ;
               	pos.insert(std::make_pair(i,j+1)) ;
               	pos.insert(std::make_pair(i+1,j+1)) ;
            }
        }
    }
    return !pos.empty();
}

// 2x2 블록 제거 함수
void deleteSquareBlock(){
    for(const auto& p: pos){
        board[p.Y][p.X] = '.';
        answer++;
    }
}

void sortDownSwap(){
   for(int c = 0 ; c < width ; c++) {
       for(int r = height-1 ; r >= 0 ; --r){
           int temp_r = r;
           if(board[r][c] == '.') {continue;}
           while(temp_r < height - 1 &&
                board[temp_r+1][c] == '.'){
               std::swap(board[temp_r][c],board[temp_r+1][c]);
               temp_r++;
           }
       }
   }
}
// 아래로 정렬하는 함수(열을 기준으로 . 이 있다면 모두 내림)
void sortDown(){
   for(int c = 0 ; c < width ; c++) {
       int temp_height = height - 1;
       for(int r = height-1 ; r >= 0 ; --r){
           if(board[r][c] != '.'){
               board[temp_height][c] = board[r][c];
               if(temp_height  != r) board[r][c] ='.';
               --temp_height;
           }
       }
   }
}

// 블록 제거 후 아래로 정렬이 블록이 더이상 제거되지 않을 때 까지 반복
void iterateDeleation(){
    while(retrieveSqaureBlock()){
        deleteSquareBlock();
        sortDownSwap();
    }
}

int solution(int m, int n, vector<string> board) {
    height = m;
    width = n;
    
    allocateCharVector(board);
    iterateDeleation();
    return answer;
}

