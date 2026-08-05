class Solution {
public:

    int nextIndex(vector<int>& nums, bool forward, int current)
    {
        bool direction = nums[current] > 0;

        if (direction != forward)
            return -1;
        
        int n = nums.size();
        int next = ((current + nums[current]) % n + n) % n;

        if (next == current)
            return -1;

        return next; 
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i=0;i<n;i++){

            if(nums[i] == 0)
                continue;
            
            bool forward = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true){
                slow = nextIndex(nums, forward, slow);
                if(slow == -1)
                    break;
                
                fast = nextIndex(nums, forward, fast);
                if(fast == -1)
                    break;
                
                fast = nextIndex(nums, forward, fast);
                if(fast == -1)
                    break;
                
                if(slow == fast)
                    return true;
            }


            int index = i;

            while(true) {
                bool direction = nums[index] > 0;
                if(direction != forward)
                    break;
                int next = ((index + nums[index]) % n + n)%n;
                nums[index] = 0;

                if(next == index)
                    break;
                index = next;
            }
        }
        return false;
    }
};