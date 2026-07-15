class Solution {
public:
    bool ispal(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void dfs(string &s, int i, vector<string> &temp,
             vector<vector<string>> &res) {

        if (i == s.size()) {
            res.push_back(temp);
            return;
        }
   // to take all
        for (int j = i; j < s.size(); j++) {

            string c = s.substr(  i, j - i + 1);

            if ( ispal(c)) {

                temp.push_back(c);

                dfs( s, j + 1, temp, res);

                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> res;
        vector<string> temp;

        dfs( s, 0, temp, res);

        return res;
    }
};