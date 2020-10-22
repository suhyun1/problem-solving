class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagram_map;
        for(int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            anagram_map[word].push_back(strs[i]);
        }
        vector<vector<string>> anagrams;
        for(auto a : anagram_map) {
            anagrams.push_back(a.second);
        }
        return anagrams;
    }   
};