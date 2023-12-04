class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        chars_dic = {chr(i+96):0 for i in range(1,27)}
        result = 0
        for char in chars:
                chars_dic[char] += 1

        for word in words:
            flag = 0
            for char in word:
                if chars_dic[char] < word.count(char):
                    flag = 1
                    break
            result += len(word) if flag == 0 else 0
        return result
        