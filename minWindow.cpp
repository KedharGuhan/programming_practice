class Solution {
public:
    string minWindow(string s, string t) {
         // T holds all characters in string t and found has the one which was found
        map <char, int > T; 
        map <char, int> found;
        map <char,int>::iterator it;
        int start = -1, end;
        int len=0;
        for (int i = 0; i < t.length(); i++ )
            T[t[i]]++;
        int nextpos;
        char prev = ' ';
        int minWindow;
        // traverse the array s and try to find if present in T.
        
        
        it = T.begin();
        
        while (  s.length()  - nextpos >= 0){
            for (int i = nextpos; i< s.length(); i++ )
            {
                if (len!=0)
                    len++;
                // tries to find if it is present in the map and updates start
                if (T.size() > 0) {
                    it = T.find (s[i]);
                    if ( it!= T.end() ) {
                    
                        if (prev != ' ' ){
                            nextpos = i;
                            prev = ' '; 
                        }                        
                        if (T[s[i]] == 1 )
                            T.erase (s[i]);
                        else
                            T[s[i]]--;
                        cout << "size of T :" << T.size();
                        if (start == -1){
                            start = i;
                            len = 1;
                            prev = s[i];
                        }
                    }
                }
                if (T.size() == 0) {
                    end = i;
                    string str = s.substr(start, len);
                    cout <<str;
                    break;
                }
                
            }
            start = -1;
            len = 0;
            for (int i = 0; i < t.length(); i++ )
                T[t[i]]++;
            
        }
        cout << "start: "<< start << "end : " << end << "len : " << len;
        // substr( pos, len)
        string str = s.substr(start, len);
        cout << str;
        return      str;  
    }
};
