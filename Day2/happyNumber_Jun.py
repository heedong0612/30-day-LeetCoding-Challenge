def isHappy(self, n: int) -> bool:
    dupSet = set()
    return self.isHappyHelper(n, dupSet)

def isHappyHelper(self, n: int, dup: set) ->bool:
    numList = []
    sum = 0
    while(n > 0):
        numList.append(n % 10)
        n = n // 10
    for num in numList:
        sum += num**2
    if sum == 1:
        return True
    elif sum in dup:
        return False
    else:
        dup.add(sum)
        return self.isHappyHelper(sum,dup)