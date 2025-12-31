/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(int target, MountainArray &mountainArr){
        int low = 0;
        int n = mountainArr.length();
        int high = n-1;

        //find peak
        while(low <= high){
            int mid = low + (high-low)/2;

            int prevMid = mid > 0 ? mountainArr.get(mid-1) : -1;
            int midEle = mountainArr.get(mid);
            int nextMid = mid < mountainArr.length()-1 ? mountainArr.get(mid+1) : -1;

            //if mid is peak
            if(prevMid < midEle && midEle > nextMid){
                return mid;
            }
            //mid lie on increasing slope
            else if(prevMid < midEle && midEle < nextMid){
                low = mid + 1;
            }
            //mid lie on decreasing slope
            else if(prevMid > midEle && midEle > nextMid){
                high = mid - 1;
            }
        }
        return -1;
    }

    int IBS(MountainArray &mountainArr, int low, int high, int target){
        while(low <= high){
            int mid = low + (high-low)/2;
            int midEle = mountainArr.get(mid);
            if(midEle == target)
                return mid;
            else if(midEle < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
    
    int DBS(MountainArray &mountainArr, int low, int high, int target){
        while(low <= high){
            int mid = low + (high-low)/2;
            int midEle = mountainArr.get(mid);
            if(midEle == target)
                return mid;
            else if(midEle < target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakInd = findPeak(target, mountainArr);
        int n = mountainArr.length();
        int leftHalf = IBS(mountainArr, 0, peakInd, target);
        if(leftHalf > -1) return leftHalf;

        int rightHalf = DBS(mountainArr, peakInd, n-1, target);
        if(rightHalf > -1) return rightHalf;

        return -1;
    }
};