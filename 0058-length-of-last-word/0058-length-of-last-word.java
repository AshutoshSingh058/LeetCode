class Solution {
    public int lengthOfLastWord(String s) {
        s=s.trim();
        int n = s.length(), c =0, maxc =0, x=n-1;
        while(x >=0 && s.charAt(x)!=' '){
            c++;
            x--;
        }
        // System.out.print(x);
        return c;
    }
}