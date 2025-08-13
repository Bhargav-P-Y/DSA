#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    string getKey(string& s)
    {
        /*stringstream uses an 
          internal buffer that grows more efficiently.
          It avoids repeated memory allocations and copies.
          It's optimized for building strings from multiple parts.
        */

        stringstream ss;
        vector<int> lets(26, 0);
        for(char ch : s)
            lets[ch-'a']++;

        // >> for reading
        // << for building or writing
        for(auto f: lets)
            ss<<'#'<<f;
        //str() is valid
        //Extracts the string from 
        // the stringstream
        return ss.str();
            
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //Traverse the vector of strings
        //Get the key of the word
        //Insert the word into the map

        //Traverse through the map
        //Push all the vector of strings
        //Into the resultant list

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        string key = "";

        for(auto word : strs)
        {
            key = getKey(word);
            mp[key].push_back(word);
        }

        for(auto entry: mp)
            res.push_back(entry.second);
        return res;
        
    }
};

