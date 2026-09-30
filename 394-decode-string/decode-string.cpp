class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;

        string curr = "";
        int num = 0;

        for(char ch : s) {

            // Build number
            if(isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // Starting a new bracket
            else if(ch == '[') {
                nums.push(num);
                strs.push(curr);

                num = 0;
                curr = "";
            }

            // Normal character
            else if(isalpha(ch)) {
                curr += ch;
            }

            // Ending bracket
            else if(ch == ']') {
                int times = nums.top();
                nums.pop();

                string prev = strs.top();
                strs.pop();

                string temp = "";

                for(int i = 0; i < times; i++) {
                    temp += curr;
                }

                curr = prev + temp;
            }
        }

        return curr;
    }
};