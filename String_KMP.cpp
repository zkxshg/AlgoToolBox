// Knuth–Morris–Pratt string-searching algorithm 
// https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm

class Solution {
public:

    int KMP(string haystack, string needle) {
        int lenh = haystack.size();
        int lens = needle.size();
        
        if (!lens) return 0;
        else if (lenh < lens) return -1;
        
        if (lenh == lens){
            for (int j = 0; j < lens; j++)
                if (haystack[j] != needle[j]) 
                    return -1;
            return 0;
        }
        
        vector<int> Ti(lens+1, 0); Ti[0] = -1;
        
        int i = 1;
        while (i < lens) {
            if (needle[i] == needle[0]){
                int j = 0, count = 1;
                if (Ti[i+1] < 1) Ti[i+1] = 1;
                while (i + count < lens - 1 && needle[j + count] == needle[i + count]) {
                    if (count + 1 > Ti[i + count + 1]) Ti[i + count + 1] = count + 1;
                    count++;
                }
            }
            i++;
        }
        
        int result = -1;
        i = 0;
        while (i < lenh){
            if (haystack[i] == needle[0]){
                if (lens == 1) return i;
                int count = 1;
                while (haystack[i + count] == needle[count]) {
                    count++;
                    if (count == lens) return i;
                    else if (i + count >= lenh) return -1;
                }
                i = i + count - Ti[count];
            }
            else i++;
        }
        return result;    
    }
};
