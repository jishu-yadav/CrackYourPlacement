class Solution {
public:
    int maxProduct(vector<string>& words) {
         int maxP=0;
         vector<int> check(words.size());
        for(int i=0;i<words.size();i++){
            int num = 0;
            for(int j=0;j<words[i].size();j++){
                int x = words[i][j] - 'a';
                num |=  1<<x;
                check[i] = num;
            }
            for (int j=0; j<i; ++j)
                if (!(check[i] & check[j]))
                maxP = max(maxP, int(words[i].size() * words[j].size()));
            // check[i] = num;
        }
//         for(int i=0;i<words.size();i++){
//             for(int j=i+1;j<words.size();j++){
                
//                 if( (check[i] & check[j]) == 0){
//                     maxP = max(maxP, int(check[i].size())*int( check[j].size() ) );
//                 }
//             }
//         }
        return maxP;
        //issue with arrays plz resolve it...
//         int maxP=0;
//         int check[1000] = {0}; 
//         for(int i=0;i<words.size();i++){
//             int num = 0;
//             for(int j=0;j<words[i].size();j++){
//                 int x = words[i][j] - 'a';
//                 num |=  1<<x;
//             }
//             check[i] = num;
//         }
//         for(int i=0;i<words.size();i++){
//             for(int j=i+1;j<words.size();j++){
                
//                 if( (check[i] & check[j]) == 0){
//                     int i1 = sizeof(check[i])/sizeof(check[0]);
//                     int i2 = sizeof(check[j])/sizeof(check[0]);
//                     maxP = max(maxP, i1*i2);
//                 }
//             }
//         }
//         return maxP;
    }
};//maximum product of word lengths
