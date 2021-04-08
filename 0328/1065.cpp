#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int count = 0;
    for (int i = 1; i <= num; i++)
    {
        int digit_nums[4] = {0, 0, 0, 0};
        int differ;
        bool is_progress = true;
        int j_num = i;
        
        for (int j = 0; j_num > 0; j_num /= 10, j++)
        {
            digit_nums[j] = j_num % 10;
            if (j > 0)
            {
                if (j == 1)
                {
                    differ = digit_nums[j] - digit_nums[j - 1];
                    continue;
                }
                if (differ != digit_nums[j] - digit_nums[j - 1])
                {
                    is_progress = false;
                    break;
                }
            }
        }
        if (is_progress)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}