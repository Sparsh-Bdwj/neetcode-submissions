class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        hasset = set();
        
        for n in nums:
            if n in hasset:
                return True
            hasset.add(n)
        return False
        