class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length(), c =0, maxc =0, x=n-1;
        s.trim();
        for(int i=n-1; i>=0; i--){
            if(s.charAt(i) == ' '){
                x--;
            }
            else break;
        }
        while(x >=0 && s.charAt(x)!=' '){
            c++;
            x--;
        }
        System.out.print(x);
        return c;
    }
}