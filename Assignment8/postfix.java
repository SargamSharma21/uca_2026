import java.util.*;

class balanceParanthesis{
    public static int postfixOperation(String s) {
        Stack<Integer> st = new Stack<>();
        for(int i = 0 ; i < s.length() ; i++) {
            char c = s.charAt(i);
            if (c >= '0' && c <= '9') {
                st.push(Character.getNumericValue(c));
            }
            else if (c == '+') {
                int a = st.pop();
                int b = st.pop();
                int ans = a + b;
                st.push(ans);
            }
            else if (c == '-') {
                int a = st.pop();
                int b = st.pop();
                int ans = b - a;
                st.push(ans);
            }
            else if (c == '/') {
                int a = st.pop();
                int b = st.pop();
                int ans = b / a;
                st.push(ans);
            }
            else if (c == '*') {
                int a = st.pop();
                int b = st.pop();
                int ans = b * a;
                st.push(ans);
            }
            else {
                return -1;
            }
        }
        if (st.size() != 0) return st.pop();
        return -1;
    }

    public static void main(String[] args) {
        String check = "231*+9-";
        int ans = postfixOperation(check);
        System.out.println(ans);
    }
}