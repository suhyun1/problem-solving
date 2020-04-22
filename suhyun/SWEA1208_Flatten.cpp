#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int T=10;
	int test_case;
    int dumpCount;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> dumpCount;
        vector<int> boxHeight;
        int tmp;
        for(int i=0; i<100;i++){
            cin >> tmp;
            boxHeight.push_back(tmp);
        }
        sort(boxHeight.begin(), boxHeight.end());

        for(int i=0; i<dumpCount;i++){
            boxHeight[0]++;
            boxHeight[99]--;
            
            for(int j=1; j<100;j++){
                if(boxHeight[0] <= boxHeight[j])
                    break;
                if(boxHeight[0] > boxHeight[j] && boxHeight[0] <= boxHeight[j+1]){
                    int tmp = boxHeight[0];
                    boxHeight[0] = boxHeight[j];
                    boxHeight[j] = tmp;
                }
            }
            for(int j=98; j>=0;j--){
                if(boxHeight[99] >= boxHeight[j])
                    break;
                if(boxHeight[99] < boxHeight[j] && boxHeight[99] >= boxHeight[j-1]){
                    int tmp = boxHeight[99];
                    boxHeight[99] = boxHeight[j];
                    boxHeight[j] = tmp;
                }
            }
        }
        cout << "#" << test_case <<" " << boxHeight[99]-boxHeight[0] << endl;
	}
	return 0;
}