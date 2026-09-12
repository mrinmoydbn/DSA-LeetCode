class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}
        for ch in strs:
            key = ''.join(sorted(ch))

            if key not in mp:
                mp[key] = []

            mp[key].append(ch)

        ans = []

        for group in mp.values():
            ans.append(group)
        return ans