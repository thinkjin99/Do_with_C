#include <iostream>
#include<cmath>
int main(){
    int test_num;
    std::cin >> test_num;
    double* over_avg_ratio = new double [test_num];
    
    for (int i = 0; i < test_num; i ++){
        int student_num;
        std::cin >> student_num;
        int* student_scores = new int [student_num];
        int sum_score = 0;

        for (int j = 0; j < student_num; j++){
            std::cin >> student_scores[j];
            sum_score += student_scores[j];
        }

        int counts = 0;
        for(int k = 0; k < student_num; k++){
            int average = sum_score / student_num;
            if (student_scores[k] > average){
                counts++;
            }
        }

        over_avg_ratio[i] = round(((double)counts / (double)student_num)*pow(10,5))/pow(10,3);
        delete[] student_scores;
    }
    
    for(int i = 0; i < test_num; i++){
        std::cout << std:: fixed;
        std::cout.precision(3);
        std::cout<<over_avg_ratio[i]<<"%"<< std::endl;
    } 
    delete[] over_avg_ratio;
    return 0;
}