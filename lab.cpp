#include <iostream>

#include <time.h>

using namespace std;


void Grade1_to_Gade2(int questionNum){
    int a,b,c;     //to get the random valuables
    char str;      //to show what the symbol of the answer
    int result;    // count the result of the answer
    int result_comparation;  //to compare the answer within input and correct answer
    int i;
    float count = 0.0;
    double answer_score;
    for(i = 0; i < questionNum; i++){
        srand((unsigned)time(0));
        a = rand()%100;
        b = rand()%100;
        c = rand()%2;
        
        switch(c){
            case 0:
                str = '+';
                result = a + b;
                break;
            case 1:
                str = '-';
                result = a - b;
                break;
        }
        cout << a << str << b << "= ? " << endl;
   		cin >> result_comparation;
        
        if(result == result_comparation){
       		count++;
    	}
    }
    if(count == questionNum){
        cout <<"end! All right, that's great! Your score is 100." << endl;
    } else{
    	answer_score = (count / questionNum)*100;
        cout << "end! Wrong question, your score is " << answer_score << endl;
    }
}


int main(){
    int grade;
    int question_num;
    cout << "please input grade? " << endl;
    cin >> grade;
    cout << "Please enter the number of questions?" << endl;
    cin >> question_num;
        if(grade == 2){
            Grade1_to_Gade2(question_num);
        }
    return 0;
}
