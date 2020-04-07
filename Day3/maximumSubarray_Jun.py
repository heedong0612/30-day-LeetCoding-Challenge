def maxSubArray(self, nums: List[int]) -> int:
    if len(nums) == 1:
        return nums[0]
    result = -9999
    sum = 0
    for num in nums:
        sum += num
        if sum <= 0:
            sum = 0
        result = max(sum, result)
    nums.sort(reverse=True)
    if result == 0:
        return nums[0]
    return result

def maxSubArrayDnC(self, nums: List[int]) -> int:
    if(len(nums) == 1):
        return nums[0]
    mid = (len(nums) // 2)
    L = self.maxSubArrayDnC(nums[0:mid])
    R = self.maxSubArrayDnC(nums[mid:len(nums)])
    M = self.getSum(nums, mid - 1, -1) + self.getSum(nums, mid, len(nums))
    return max(M,R,L)

def getSum(self, nums, start, end):
    result = -9999
    sum = 0
    if(start > end):
        for i in range(start, end, -1):
            sum += nums[i]
            result = max(sum, result)
    else:
        for i in range(start, end):
            sum += nums[i]
            result = max(sum, result)
    return result