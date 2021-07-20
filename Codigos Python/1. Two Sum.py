
def twoSum(nums, target):
    result = []

    for i in range(len(numbers)):
        for j in range(i+1, len(numbers)):
            if ((numbers[i] + numbers[j]) == target):
                result.append(i)
                result.append(j)

    return result


numbers = [2, 7, 11, 15]
target: int = 9
x = twoSum(numbers, 9)
print(x)
