def combinationSums(candidates, target, sum, path):
    if sum == target:
        print(path)
        return
    if sum > target:
        return 
    for i in range(len(candidates)):
        path.append(candidates[i])
        combinationSums(candidates[i:], target, sum + candidates[i], path)
        path.pop()


combinationSums([2, 3, 6, 7, 8], 8, 0, [])