class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Tạo danh sách các "Xô" (Buckets)
        // Số lượng xô là n + 1 (để bao phủ trường hợp tần số từ 0 đến n)
        vector<vector<int>> buckets(n + 1);

        // Xếp các số vào xô tương ứng với tần số của nó
        for (auto it : freq) {
            int frequency = it.second;
            int number = it.first;
            buckets[frequency].push_back(number);
        }

        vector<int> result;
        
        // Duyệt ngược từ xô cao nhất (tần số lớn nhất) xuống
        for (int i = n; i >= 0; i--) {
            // Nếu xô này có chứa đồ
            for (int num : buckets[i]) {
                result.push_back(num);
                // Đủ k phần tử thì dừng toàn bộ và trả về
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result;
    }
};
