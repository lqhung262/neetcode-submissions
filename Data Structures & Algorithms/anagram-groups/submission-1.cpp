class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string s: strs)
        {
            string count_key = string(26, 0);

            for (char c: s)
            {
                count_key[c - 'a']++;
            }

            groups[count_key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto pair: groups)
        {
            res.push_back(pair.second);
        }

        return res;
    }
};
