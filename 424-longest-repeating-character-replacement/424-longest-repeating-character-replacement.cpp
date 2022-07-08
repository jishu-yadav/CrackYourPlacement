class Solution {
public:
    int characterReplacement(string str, int k) {
    int maxLength = 0;
    int maxRepeatLetterCount=0;
    unordered_map<char,int>letterFrequencyMap;
    int windowStart = 0;
    for(int windowEnd=0;windowEnd<str.size();windowEnd++){
      char rightChar = str[windowEnd];
      letterFrequencyMap[rightChar]++;
      maxRepeatLetterCount = max(maxRepeatLetterCount,letterFrequencyMap[rightChar] );
      if(windowEnd-windowStart+1 - maxRepeatLetterCount > k )//shrink the window
      {
        char leftChar = str[windowStart];
        letterFrequencyMap[leftChar]--;
        windowStart++;
      }
      maxLength = max(maxLength, windowEnd-windowStart+1);
    }

    return maxLength;
    }
};