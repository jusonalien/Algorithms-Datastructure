//2016 2-23 14:57pm

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int p1 = 0, p2 = 0;
    int count = 0;
    int achieve = (nums1Size + nums2Size + 1) / 2;
    double ans;
    while (p1 < nums1Size && p2 < nums2Size) {
        if (nums1[p1] < nums2[p2]) {
             p1++;
             count++;
            if (count == achieve) {
                ans = nums1[p1 - 1];
                goto get_ans;
            }
        }
        else {
             p2++;
             count++;
            if (count == achieve) {
                ans =  nums2[p2 - 1];
                goto get_ans;
            }
        }
    }
    if (p1 < nums1Size)
      ans = nums1[p1 + (achieve - count) - 1];
    else 
      ans = nums2[p2 + (achieve - count) - 1];
      
    get_ans:
      if ((nums1Size + nums2Size + 1) % 2 == 0) // 如果元素总数为奇数
        return ans;
      if (p1 >= nums1Size)
        return (ans + nums2[p2 + (achieve - count)]) / 2;
      if (p2 >= nums2Size)
        return (ans + nums1[p1 + (achieve - count)]) / 2;
      double last = nums1[p1 + (achieve - count)] < nums2[p2 + (achieve - count)] ? nums1[p1 + (achieve - count)] : nums2[p2 + (achieve - count)];
      return (ans +last) / 2;
}
