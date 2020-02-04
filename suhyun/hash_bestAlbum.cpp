//7점
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> genre_count;
    map<int, string, greater<int> >sorted_genre;  // (장르 총재생수, 장르명 )
    
    for(int i=0;i<genres.size();i++){
        genre_count[genres[i]] += plays[i];
    }
    for(auto g : genre_count){
        sorted_genre.insert(make_pair(g.second, g.first)); 
    }
    for(auto g: sorted_genre){   
        vector<pair<int, int> > song_play; // (재생수, index) 쌍
        for(int i=0; i < genres.size();i++){
            if(g.second == genres[i]){
                song_play.push_back(make_pair(plays[i],i));
            }
        }
        sort(song_play.begin(), song_play.end(),cmp);
        vector<pair<int, int> >::iterator it = song_play.begin();
        if(song_play.size()==1){
            answer.push_back(it->second);
        }    
        else{
            answer.push_back(it->second);
            it++;
            answer.push_back(it->second);  
        }
    }
        
    return answer;
}