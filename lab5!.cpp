#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
void Grade5_6(int N){
	int i;
	int c,C;
	char str;
	float count=0.0;
	float input;
	double score;
		for(i = 0; i < N; i++){
	    srand((unsigned)time(0));
		double x=(double)(rand())/RAND_MAX*100;
		double y=(double)(rand())/RAND_MAX*100;
        c = rand()%4;
          	
 switch(c){
            case 0:
                str = '+';
                count = x + y;
                break;
            case 1:
               str = '+';
                count = x + y;
                break;
            case 2:
               str = '*';
                count = x * y;
                break;
                
            case 3:
               str = '/';
                count = x / y;
                break;
        }
        
		cout<<x<<str<<y<<"=?";
		cin>>input;
		if(count==input){    /*justify correct or error*/ 
			cout<<"Right!"<<endl;
			count=count+1;
		}

		if(count == N){
        cout<<"end! All right, that's great! Your score is 100." <<endl;
    } else{
    	score = (count / N)*100;
    	cout << count << endl;
    	cout << N << endl;
    	cout << count/N << endl;
        cout<<"end! Wrong question, your score is"<<score<<endl;
    }
	    
	        
   cout<<"Your grade is:"<<count;
}
int main(){
	int grade;
    int N;
    cout << "please input grade:" ;
    cin >> grade;
    cout << "Please enter the number of questions:" ;
    cin >> N;
        if(grade == 5){
            Grade5_6(N);
        }
    return 0;
}

