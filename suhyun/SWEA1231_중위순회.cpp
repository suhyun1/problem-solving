#include<iostream>
#include <vector>
using namespace std;

string word;
void in_order(vector<char>& arr, int num){
    if(arr[num]==0){
        return;
    }
    in_order(arr, num*2);
    word += arr[num];
	in_order(arr, num*2+1);
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin >> N;
        int num, child1, child2;
        char alphabet;
        vector<char> node_alphabet(200,0);
        for(int i=1;i<=N;i++){
            cin>> num >> alphabet;
            node_alphabet[num] = alphabet;
            if(N % 2 == 0 && N / 2 > i || N % 2 == 1 && N / 2 >= i){
                cin  >> child1 >> child2;
            } else if(N % 2 == 0 && N / 2 == i) {
                cin >> child1;
            }
        }

        word="";
        in_order(node_alphabet, 1);
        cout << "#" << test_case << " " << word<< endl;

	}
	return 0;
}