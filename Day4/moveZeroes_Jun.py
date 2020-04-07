def moveZeroes(self, nums: List[int]) -> None:
    i = 0
    countZero = 0
    while(i < len(nums)):
        if nums[i] == 0:
            countZero += 1
            for j in range(i, len(nums)):
                if j < len(nums) - 1:
                    temp = nums[j]
                    nums[j] = nums[j+1]
                    nums[j+1] = temp
        if(i == len(nums) - 1 or len(nums) - countZero == 0):
            break
        elif(nums[i] != 0):
            i += 1