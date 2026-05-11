class Solution {
public:
    string decodeString(string s) {

        stack<int> numStack;
        stack<string> strStack;

        string curr = "";
        int num = 0;

        for(int i=0; i<s.size(); i++) {

            if(isdigit(s[i])) {

                num = num * 10 + (s[i] - '0');
            }

            else if(s[i] == '[') {

                numStack.push(num);
                strStack.push(curr);

                num = 0;
                curr = "";
            }

            else if(s[i] == ']') {

                int times = numStack.top();
                numStack.pop();

                string prev = strStack.top();
                strStack.pop();

                string temp = "";

                while(times--) {
                    temp += curr;
                }

                curr = prev + temp;
            }

            else {

                curr += s[i];
            }
        }

        return curr;
    }
};