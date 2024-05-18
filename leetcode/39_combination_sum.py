import copy
class Solution:

    def do_computation_sum(self,index,target,current_list,candidates,ans_list):
        # termination condition
        #print(index, target ,current_list)
        if target==0:
            ans_list.append(copy.deepcopy(current_list))
            return
        if target <0:
            return
        if index >= len(candidates):
            return
        target = target - candidates[index]
        current_list.append(candidates[index])
        self.do_computation_sum(index,target,current_list,candidates,ans_list)

        # backtrack
        target = target + candidates[index]
        current_list.pop()
        self.do_computation_sum(index+1,target,current_list,candidates,ans_list)

        return



        
    def combinationSum(self, candidates, target):
        ans_list = []
        self.do_computation_sum(0,target,[],candidates,ans_list)
        return ans_list
        
s = Solution()
print(s.combinationSum([2,3,5],8))
