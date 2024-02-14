class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_dict = {}
        max_length_substring = 0
        i = 0
        for j in range(len(s)):
            if s[j] in char_dict:
                index = char_dict[s[j]]
                if index >=i:
                    i = index + 1
            print(i,j)
            if max_length_substring < (j-i+1):
                max_length_substring = (j-i+1)
            char_dict[s[j]] = j
        return max_length_substring

if __name__=='__main__':
    s = Solution()
    print(s.lengthOfLongestSubstring('abba'))