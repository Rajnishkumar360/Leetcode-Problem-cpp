class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // int n = tokens.size();
        // stack<int> st;
        // for(int i=0;i<n;i++){
        //         if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
        //             int a = st.top();
        //             st.pop();
        //             int b = st.top();
        //             st.pop();
        //          if(tokens[i] =="+") st.push(a+b);
        //          else if(tokens[i]=="-") st.push(a-b);
        //          else if(tokens[i]=="*")st.push(a*b);
        //          else st.push(a/b);
        //         }
        //         else{
        //             st.push(stoi(tokens[i]));
        //         }
        // }
        //     return st.top();

        stack<int>st;
        for(string &t : tokens){
            if(t=="+" || t=="-" || t=="*" || t=="/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(t=="+") st.push(a+b);
                else if(t=="-") st.push(a-b);
                else if(t=="*") st.push(a*b);
                else st.push(a/b);
            }else{
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};