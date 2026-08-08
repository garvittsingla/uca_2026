#include "iostream"
#include "vector"

void setZeroes(std::vector<std::vector<int>>& matrix) {
    //set rows x columns of matrix zeroes where there is a zero

    int m = matrix.size();
    int n = matrix[0].size();

    std::vector<bool> rows(m,false);
    std::vector<bool> cols(n,false);

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(matrix[i][j] == 0){
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for(int i = 0 ; i < m ; i++){
        //check if current row is set to be zero
        if(rows[i]){
            for(int j = 0 ; j < n ; j++){
                matrix[i][j] = 0;
            }
        }
    }

    for(int j = 0 ; j < n ; j++){
        //check if current row is set to be zero
        if(cols[j]){
            for(int i = 0 ; i < m ; i++){
                matrix[i][j] = 0;
            }
        }
    }

}
void print(std::vector<std::vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main(){
    std::vector<std::vector<int>> testcase1 = {{1,1,1},{1,0,1},{1,1,1}};
    std::vector<std::vector<int>> testcase2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};


    setZeroes(testcase1);
    setZeroes(testcase2);
    print(testcase1);
    print(testcase2);

}