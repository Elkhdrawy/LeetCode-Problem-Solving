class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Use min-heap to keep k most frequent elements
        // Priority queue with custom comparator (min-heap based on frequency)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (auto& p : freq) {
            pq.push({p.second, p.first}); // {frequency, element}
            
            // Keep only k elements in heap
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // Step 3: Extract elements from heap
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};

// Alternative solution using bucket sort for O(n) time complexity
class SolutionBucketSort {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Count frequencies
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Bucket sort by frequency
        vector<vector<int>> buckets(n + 1);
        for (auto& p : freq) {
            buckets[p.second].push_back(p.first);
        }
        
        // Step 3: Collect k most frequent elements
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        
        return result;
    }
};
