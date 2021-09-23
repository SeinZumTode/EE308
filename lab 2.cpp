#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

string& replace_all(string& src, const string& old_value, const string& new_value) {
	for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
		if ((pos = src.find(old_value, pos)) != string::npos) {
			src.replace(pos, old_value.length(), new_value);
		}
		else break;
	}
	return src;
}

string& trim(string &s){
//delet the space in code
	if (s.empty()) 
	{
		return s;
	}
	s.erase(0,s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	return s;
}

int main(){
	ifstream inFile;
	string file_add,word;
	string kw="auto	break case char const continue default do double else enum extern float for goto if int long register return short signed sizeof static struct switch typedef union unsigned void volatile while";
    int level;
	int switch_num=0;
	int total=0;
	int case_num=0;
	int if_else_num=0;
	int if_elseif_if_num=0;
    vector<string> KW;
    vector<string> code;
    vector<int> casenum;
    stack<int> mystack;
    
    
    stringstream stringin(kw);
    while(stringin>>word){
    	KW.push_back(word);
	}
//	for(int q=0; q<KW.size();q++){
//		cout<<q<<KW[q]<<endl;
//	}
	
	cout << "Please enter the address of the file: ";
    cin >> file_add;
    cout << "Enter the level: ";
    cin >> level;
	//cout<<file_add.c_str();
	inFile.open(file_add.c_str(), ios::in);
	
	string str,str1,result;
	if (inFile){
        cout<<"File open scessful"<<endl;
        while(getline(inFile,str))
        {
        	if(str.find("switch") != string::npos){
        	switch_num++;
        	case_num=0;
		}
		    if(str.find("case") != string::npos){
		    	case_num++;
			}
			else if(str.find("default") != string::npos){
				casenum.push_back(case_num);
			}
			
			
			
   		if(str.find("else if")!=string::npos){
   			mystack.push(2);
   		}else if(str.find("if")!=string::npos){
   			mystack.push(1);
   		}else if(str.find("else")!=string::npos){
            if(mystack.top() == 1){
                mystack.pop();
                if_else_num++;
                continue;
            }
            while(mystack.top() == 2) {
                mystack.pop();
            }
            mystack.pop();
            if_elseif_if_num++;
		}
				
		
        	str1=replace_all(str, "{", " ");
        	str1=replace_all(str, "}", " ");
        	str1=replace_all(str, "(", " ");
        	str1=replace_all(str, ")", " ");
        	str1=replace_all(str, ";", " ");
        	str1=replace_all(str, ":", " ");
        	str1=trim(str);
        	//cout<<str1<<endl;
        	stringstream input(str1);
        	while(input >> result){
        		code.push_back(result);
			}
	}
		for(int i=0; i<code.size(); i++)
        {
		    for(int t=0;t<KW.size();t++){
		    	if(code[i]==KW[t]){
		    		total++;
				}
			}
		}
	
        	
		
        if (level == 1) {
            cout << "Total num: " << total << "\n";
        }	
        if(level==2){
			cout<< "Total num: "<< total <<"\n"
			<<"Switch num: " << switch_num <<"\n"
			<<"Case num: ";
		    for(int n=0;n<casenum.size();n++){
		    	cout<<casenum[n]<<" ";
			}
		
		}
		if(level==3){
			cout<< "Total num: "<< total <<"\n"
			<<"Switch num: " << switch_num <<"\n"<<"Case num: ";
		    for(int n=0;n<casenum.size();n++){
		    	cout<<casenum[n]<<" ";
			}
			cout <<endl<< "if else num: " << if_else_num << endl;
		}
		
		if(level==4){
			cout<< "Total num: "<< total <<"\n"
			<<"Switch num: " << switch_num <<"\n"<<"Case num: ";
		    for(int n=0;n<casenum.size();n++){
		    	cout<<casenum[n]<<" ";
			}
			cout <<endl<< "if else num: " << if_else_num << endl;
	        cout << "if else-if else num: " << if_elseif_if_num << endl;
		}

}

    else
        cout << "File doesn't exit. " << endl;
        
    inFile.close();
    return 0;
	
}
