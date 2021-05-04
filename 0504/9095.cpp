#include<iostream>
using namespace std;
int factorial(int num, int r)
{
    int result = 1;
    for (int i = 0; i < r; i++)
    {
        result = result * (num - i);
    }
    return result;
}
int OverPermute(int num, int n){
    //num은 기존의 쪼개야 하는 수 n은 몇으로 쪼갤 것 인지를 나타낸다
    //즉 여기서 1,2 혹은 1,3만을 이용해 수를 표현하는 경우를 모두 추출한다.
    //num을 기준으로만 숫자를 묶어서 추출한다.
    int sum = 0;
    //k는 묶이는 1의 항의 개수를 의미한다. 여러개의 1의 항이 묶여 i개의 항으로 취급된다.
    for(int i = 1, k = n; k <= num; i++,k = i * n){
        sum += factorial(num - k + i,i) / factorial(i,i); 
    }
    return sum;
}

int main(){
    int cnt;
    scanf("%d",&cnt);
    for(int n = 0; n < cnt; n++){
        int num;
        int sum = 1;
        scanf("%d",&num);
        /* main에서 처리하는 부분은 2와 3과 1로 이뤄진 경우이다.
        이외의 경우는 위에 함수를 통해 처리가 가능하기 때문이다.*/
        for(int i = 1 ,k = 2; k <= num; i++, k = i * 2){
            for(int j = 1, l = 3; k + l <= num; j++, l = j * 3){
                int differentTerms = num - (k + l) + i + j; 
                /* num은 결국 num개의 1로 구성돼있다. 이를 2개 3개 씩 묶는 경우를 생각해보는 것이 문제의 핵심이다.
                2와 3을 통해 묶을 시 서로 다른 n개의 항을 가진 수로 num을 표현 할 수 있다
                예를 들어 num이 4라면
                1 1 1 1
                2 1 1
                3 1 
                등으로 표현하는 것이 가능하다는 것이다. 2 1 1의 경우를 생각해보면 3개의 항과 2개의 공통항을 가진 순열을 생각해보면 된다
                그렇다면 2를 1개 사용하고 num을 표현하는 방법의 수는 3! / 2! * 1! 이 된다 (중복 순열의 공식)
                이런 방식으로 
                num을 2와 1로만 표현하는 경우
                num을 3과 1로만 표현하는 경우
                num을 2와 3과 1로만 표현하는 경우
                로 나눠서 구하면 우리는 num을 1,2,3으로 표현하는 경우를 모두 구할 수 있다.
                */
                sum += factorial(differentTerms, i + j) / (factorial(i,i) * factorial(j,j));
                /* diffrentTerms! / ((differentTerms - (k +l)! * i! * j!) => 본래의 공식
                (differentTerms - (k +l) = 중복되는 1의 개수
                단순화 시켜서 위의 공식 처럼 변한다) */
            }
        }
        sum = sum + OverPermute(num,2) + OverPermute(num,3);
        cout << sum << endl;
    }
}