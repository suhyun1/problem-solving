#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int palindrome_len;
        cin >> palindrome_len;
        
        char arr[8][8];
        for(int i=0; i<8;i++){
            for(int j=0;j<8;j++){
            	cin >> arr[i][j];        
           	}
        }

        int cnt = 0;
        bool check = false;
        //가로
        for(int i=0; i<8;i++){
            for(int j=0;j<8-palindrome_len+1;j++){
                check = false;
                for(int k=0; k<palindrome_len/2; k++){
                    if(arr[i][j+k] !=arr[i][j+palindrome_len-k-1]){
                        check = true;
                        break;
                    }
                }
                if(!check){
                    cnt++;
                }
            }
        }
				
        //세로
        for(int i=0; i<8;i++){
            for(int j=0;j<8-palindrome_len+1;j++){
                check =false;
                 for(int k=0; k<palindrome_len/2; k++){
                     if(arr[j+k][i]!=arr[j+palindrome_len-k-1][i]){
                        check = true;
                        break;
                    }
                 }
                 if(!check){
                    cnt++;
                }
            }
        }
        cout << "#" << test_case <<" "<< cnt << endl;

	}
	return 0;
}