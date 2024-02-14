class Solution:

    def convert(self, s: str, numRows: int) -> str:
        n = len(s)
        if n==1 or numRows==1:
            return s
        result = []
        for i in range(numRows):
            current_str_index = i
            alternate = True
            while current_str_index < n:
                result.append(s[current_str_index])
                if i==0:
                    current_str_index = (2 * (numRows-i-1)) + current_str_index
                elif i==(numRows-1):
                    current_str_index = 2*i + current_str_index
                else:
                    if alternate:
                        current_str_index = (2 * (numRows-i-1)) + current_str_index
                        alternate = False
                    else:
                        alternate= True
                        current_str_index = 2*i + current_str_index

        return "".join(result)