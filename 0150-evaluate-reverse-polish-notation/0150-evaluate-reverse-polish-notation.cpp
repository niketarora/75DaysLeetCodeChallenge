class Solution {
public:
    int evalRPN(vector<string>& tok) {
        stack<int> st;
        int n = tok.size();
        for(int i=0; i<n; i++){
            if(tok[i] != "+" && tok[i] != "-" && tok[i] != "*" && tok[i] != "/"){
                st.push(stoi(tok[i]));
            }
            else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int result = 0;
                if(tok[i] == "+"){
                    result = b + a;
                }
                else if(tok[i] == "-"){
                    result = b - a;
                }
                else if(tok[i] == "*"){
                    result = b * a;
                }
                else
                    result = b/a;

                st.push(result);
            }
        }
        int ans = st.top();
        return ans;
    }
};