class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for st in s:
            if (st == '(' or st == '[' or st == '{'):
                stack.append(st)
            else:
                if not stack: return False
                top = stack.pop()
                if ((st == ')' and top != '(') or
                    (st == ']' and top != '[') or
                    (st == '}' and top != '{') ):
                    return False
        
        return not stack