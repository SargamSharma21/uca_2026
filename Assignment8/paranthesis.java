import java.util.*;

class balanceParanthesis{
    public static boolean validParanthesis(String s) {
        Stack<Character> st = new Stack<>();
        for(int i = 0 ; i < s.length() ; i++) {
            char c = s.charAt(i);
            if (c == '[' || c == '{' || c == '(') {
                st.push(c);
            }
            else if(!st.isEmpty() && c == '}' && st.peek() == '{') {
                st.pop();
            }
            else if(!st.isEmpty() && c == ']' && st.peek() == '[') {
                st.pop();
            }
            else if(!st.isEmpty() && c == ')' && st.peek() == '(') {
                st.pop();
            }
            else{
                return false;
            }
        }
        if (st.size() == 0) return true;
        return false;
    }

    public static void main(String[] args) {
        String check = "[()";
        boolean ans = validParanthesis(check);
        System.out.println(ans);
    }
}