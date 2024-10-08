import java.util.*;

class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] arr = new int[num_people];
        int i=0;
        int x=1;
        while(candies!=0){
            if(candies<x){
                x = candies;
            }
            arr[i] += x; 
            candies-= x;
            x++;
            i++;
            if(i == num_people){
                i=0;
            }

        }
        return arr;
    }
}