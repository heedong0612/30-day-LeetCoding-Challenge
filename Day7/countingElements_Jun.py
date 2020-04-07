def countElements(self, arr: List[int]) -> int:
    numSet = set()
    arrSorted = sorted(arr, reverse = True)
    count = 0
    for num in arrSorted:
        numSet.add(num)
        if num + 1 in numSet:
            count += 1
    return count

def countElements2(self, arr: List[int]) -> int:
    numSet = set()
    count = 0
    for num in arr:
        numSet.add(num)
    for num in arr:
        if num + 1 in numSet:
            count += 1
    return count