class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int totalSize = m + n;
        
        // Target index where the median resides
        int targetIdx = totalSize / 2; 
        
        int i = 0, j = 0; // Pointers for nums1 and nums2
        int current = 0, previous = 0; // To keep track of the last two visited numbers
        
        // Loop until we reach the middle of the combined arrays
        for (int count = 0; count <= targetIdx; count++) {
            previous = current; // Save the last number before moving forward
            
            // Pick the smaller element between the two arrays
            if (i < m && (j >= n || nums1[i] <= nums2[j])) {
                current = nums1[i];
                i++;
            } else {
                current = nums2[j];
                j++;
            }
        }
        
        // If total size is odd, return the middle element
        if (totalSize % 2 != 0) {
            return current;
        }
        
        // If total size is even, return the average of the two middle elements
        return (previous + current) / 2.0;
    }
};
