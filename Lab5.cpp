#include <iostream> 
#include <stdlib.h>
#include <time.h>
using namespace std;
void Grade1_to_Grade2(int questionNum){
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
void Grade3_to_Grade4(int questionNum){
	int a,b,c,i,score=0;
    double result,result1;  
    char str; 
	for(i=0;i<questionNum;i++){
		srand((unsigned)time(NULL));
        a=rand()%100;
        b=rand()%100;
        c=rand()%4;
        switch(c)  
        {  
        case 0:  
            str='+';  
            result=a+b;  
            break;  
        case 1:  
            str='-';  
            result=a-b;  
            break;  
        case 2:  
            str='*';  
            result=a*b;  
            break;  
        case 3:  
            str='/';
            result=a/b;
            while(result<1){
            	a=rand()%100;
                b=rand()%100;
                result=a/b;
			}
            break;
        }
        cout<<a<<str<<b<<"=?"<<endl;  
        cin>>result1;  
        if(result1==result){
        	score=100/questionNum+score;
        }
    }
    if(score==100){
    	cout<<"end! All right, that's great! Your score is 100."<<endl; 
	}
    else{
    	cout<<"end! Wrong question, your score is "<<score<<" ."<<endl;
	}
}
void Grade5_to_Grade6(int questionNum){
	int i;
	int num=0;
	int c;
	char str;
	float result=0.0,result1;
	int score=0;
		for(i = 0; i <questionNum; i++){
	    srand((unsigned)time(0));
		double x=(double)(rand())/RAND_MAX*100;
		double y=(double)(rand())/RAND_MAX*100;
        c = rand()%4;     	
 switch(c){
            case 0:
                str = '+';
                result = x + y;
                break;
            case 1:
               str = '+';
                result = x + y;
                break;
            case 2:
               str = '*';
                result = x * y;
                break;
                
            case 3:
               str = '/';
                result = x / y;
                break;
        }
		cout<<x<<str<<y<<"=?"<<endl;
		cin>>result1;
		if(result==result1){
		    score=score+100/questionNum;
		}
    }
	if(score==100){
        cout<<"end! All right, that's great! Your score is 100." <<endl;
    } 
	else{
        cout<<"end! Wrong question, your score is:"<<score<<endl;
    }
}
int main(){
	int grade,num;
	cout<<"please enter your grade?"<<endl;
	cin>>grade;
	cout<<"please enter the number of questions?"<<endl;
	cin>>num;
	if(grade==1||grade==2){
		Grade1_to_Grade2(num);
	}
	else if(grade==3||grade==4){
		Grade3_to_Grade4(num);
	}
	else if(grade==5||grade==6){
		Grade5_to_Grade6(num);
	}
	return 0;
}
