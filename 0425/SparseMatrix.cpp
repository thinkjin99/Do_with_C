#include <stdio.h>
#include<iostream>
// void smTranspose(term a[], term b[]) {
//     int i, j, currentb;

//     b[0].col = a[0].row;                 // 전치행렬 b의 행 수 = 희소행렬 a의 행 수
//     b[0].row = a[0].col;                 // 전치행렬 b의 열 수= 희소행렬 a의 열 수
//     b[0].value = a[0].value;             // 전치행렬 b의 원소 수 = 희소행렬 a에서 0이 아닌 원소수

//     if (a[0].value > 0) {                  //0이 아닌 원소가 있는 경우에만 전치 연산 수행
//         currentb = 1;
//         for (i = 0; i < a[0].col; i++)            //희소행렬 a의 열별로 전치 반복 수행
//             for (j = 1; j <= a[0].value; j++)   //0이 아닌 원소 수에 대해서만 반복 수행
//             if (a[j].col == i) {                    //현재의 열에 속하는 원소가 있으면 b[]에 삽입
//                 b[currentb].row = a[j].col;
//                 b[currentb].col = a[j].row;
//                 b[currentb].value = a[j].value;
//                 currentb++;
//             }
//     }
// }

typedef struct {                         //행렬 원소를 저장하기 위한 구조체 term 정의
    int row;
    int col;
    int value;
} term;

int const term_size = 11;
const int row = 8;
const int col = 8;

void fast_tranpose(term a[],term b[]){
    int row_terms[term_size] = {0};
    int starting_pos[col];
    starting_pos[0] = 1;
    // int num_col = a[0].col;
    // int num_terms = a[0].value;
    // b[0].row = num_col;
    // b[0].col = a[0].row;
    // b[0].value = num_terms;
    int start_pos;
    for(int i = 0; i < term_size; i++){
        row_terms[a[i].col]++;
    }

    for(int i = 0; i < col; i++){//colmn만큼
        starting_pos[i] = starting_pos[i-1]+row_terms[i];
    }
    for(int i = 0; i < term_size; i++){
        start_pos = starting_pos[a[i].col]++;
        b[start_pos].row = a[i].col;
        b[start_pos].col = a[i].row;
        b[start_pos].value = a[i].value;
    }
}

int main(void){
    term original[term_size] = { 
         {0,2,2}, {0,6,12}, 
        {1,4,7}, {2,0,23},  {3,3,31}, 
        {4,1,14}, {4,5,25}, {5,6,6},
         {6,0,52}, {7,4,11} };
    term tranposed[term_size];

    int temp_arr[row][col] = {0}; //arr for print
    for (int i = 0; i < term_size; i++) temp_arr[original[i].row][original[i].col] = original[i].value;
    for (int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
           printf("  %d",temp_arr[i][j]);
        }
         printf("\n");
    }
    printf("\n\n");
    fast_tranpose(original,tranposed);
    // smTranspose(A, B);

    printf("Transpose processing has been finished.\n");
    printf("\n\n");
    for (int i = 0; i < term_size; i++) temp_arr[tranposed[i].row][tranposed[i].col] = tranposed[i].value;
    for (int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
           printf("  %d",temp_arr[i][j]);
        }
         printf("\n");
    }
   return 0;
}