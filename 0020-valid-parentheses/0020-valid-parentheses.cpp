class Solution {
public:
    bool isValid(string s) {
    // Stack to store the opening brackets.
    stack<char> stk;
    // Loop over the string.
    for (char c : s) {
        // If the current character is an opening bracket, push it to the stack.
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        }
        // Else if the current character is a closing bracket, check if the stack is empty.
        else if (c == ')' || c == '}' || c == ']') {
            // If the stack is empty, the string is invalid.
            if (stk.empty()) {
                return false;
            }
            // Else, check if the top of the stack is the opening bracket for the current closing bracket.
            else {
                // If it is, pop the top of the stack.
                if ((c == ')' && stk.top() == '(') || (c == '}' && stk.top() == '{') || (c == ']' && stk.top() == '[')) {
                    stk.pop();
                }
                // Else, the string is invalid.
                else {
                    return false;
                }
            }
        }
    }
    // If the stack is empty, the string is valid.
    if (stk.empty()) {
        return true;
    }
    // Else, the string is invalid.
    return false;
}
};