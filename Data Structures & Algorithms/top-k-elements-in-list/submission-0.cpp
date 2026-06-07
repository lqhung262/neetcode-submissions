class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Khai báo Min-Heap lưu pair<Tần số, Giá trị>
        // Cú pháp C++ hơi dài để tạo Min-Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for (auto it : freq) {
            min_heap.push({it.second, it.first});
            // Nếu kích thước vượt quá k, loại bỏ phần tử nhỏ nhất
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return result;
    }
};
