class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string s: strs)
        {
            string t = s;
            sort(t.begin(), t.end());

            groups[t].push_back(s);
        }

        vector<vector<string>> res;
        for (auto vec: groups)
        {
            res.push_back(vec.second);
        }

        return res;
    }
};
