import regex as re

f = open("testinput.txt")
lines = f.read().strip().splitlines()

#part 1 and 2
def f(nums, string):
     if len(nums) == 0:
        return 1 * '#' not in string
     elif len(string) == 0 or ('?' not in string and '#' not in string):
        return 0
     else:
        first_candidate = re.match(f"^\.*[?#]{{{nums[0]}}}(?!#)", string)
        prefix = re.match("^\.*#+|^\.*\?", string)
        if first_candidate is None:
            if re.match("^\.*#", string):
                return 0
            return f(nums, string[len(prefix[0]):])
        
        first_candidate = first_candidate[0]
        
        # use first candidate
        res = f(nums[1:], string[len(first_candidate)+1:])
        
        # dont use first candidate
        res2 = 0
        if not re.match("^\.*#", string):
            res2 = f(nums, string[len(prefix[0]):])
        return res + res2

def solve(m=None):
    s = 0
    for i, line in enumerate(lines):
        l = line.strip()
        string, nums = l.split()
        nums = [int(x) for x in re.findall("\d+", nums)]
        
        if m is not None:
            nums *= 5
            string = ((string + '?')*5)[:-1]
        
        s += f(tuple(nums), string)
    return s


print(solve())
# print(solve(5))