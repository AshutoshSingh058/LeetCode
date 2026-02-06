class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        boolean flag = true;

        int[] arr = new int[26];

        int n = magazine.length();
        for(int i=0; i<n; i++){

            arr[magazine.charAt(i)-'a']++;
            
        }
        for(int c=0; c<ransomNote.length(); c++){
            arr[ransomNote.charAt(c)-'a']--;
            if(arr[ransomNote.charAt(c)-'a']<0) flag = false;
        }

        return flag;
    }
}