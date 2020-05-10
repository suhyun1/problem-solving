#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	   
	for(test_case = 1; test_case <= T; ++test_case)
	{
      	int length;
        cin >> length;
        int brackets_cnt[4]={0};	//'()', '[]', '{}', '<>' 
        char tmp;
        for(int i=0; i<length;i++){
            cin >> tmp;
            if(tmp == '(')
                brackets_cnt[0] ++;
            else if(tmp == ')')
                brackets_cnt[0] --; 
           	else if(tmp == '[')
                brackets_cnt[1] ++;
            else if(tmp == ']')
                brackets_cnt[1] --; 
            else if(tmp == '{')
                brackets_cnt[2] ++;
            else if(tmp == '}')
                brackets_cnt[2] --; 
            else if(tmp == '<')
                brackets_cnt[3] ++;
            else if(tmp == '>')
                brackets_cnt[3] --; 
        }
        bool valid = true;
        for(int i=0; i<4; i++){
            if(brackets_cnt[i] != 0){
                valid = false;
                break;
            }
        }
        cout << "#" << test_case<< " " << valid << endl;
        

	}
	return 0;
}