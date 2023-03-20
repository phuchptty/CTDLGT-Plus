def permute(nums):
    def backtrack(first=0):
        if first == n:
            res.append(nums[:])
        for i in range(first, n):
            nums[first], nums[i] = nums[i], nums[first]
            backtrack(first+1)
            nums[first], nums[i] = nums[i], nums[first]

    n = len(nums)
    res = []
    backtrack()
    return res


input_str = "60 42 13 50"
nums = list(map(int, input_str.split()))
perms = permute(nums)
for perm in perms:
    print(*perm)