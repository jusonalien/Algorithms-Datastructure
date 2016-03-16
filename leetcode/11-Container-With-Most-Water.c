/* TLE O(n^2)
int maxArea(int* height, int heightSize) {
    int i,j;
    int res = 0;
    for(i = 0;i < heightSize;++i) {
        for(j = 0; j < i;++j) {
            int hig = height[i] < height[j] ? height[i] : height[j];
            int vol = hig * (i - j);
            res = res > vol ? res : vol;
        }
    }
    return res;
}
*/
/*AC  O(n)*/
int maxArea(int* height, int heightSize) {
   int i = 0,j = heightSize - 1;
   int res = 0;
   while(i < j ) {
       int hig = height[i] < height[j] ? height[i] : height[j];
       int vol = hig * (j - i);
       res = res > vol ? res : vol;
       if(height[i] < height[j]) 
        i++;
       else 
        j--;
   }
   return res;
}
