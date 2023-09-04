
import java.util.Arrays;

public class LEETCODE_Minimum_Eating_Speed {
    
    public static void main(String[] args) {
        int []piles = {805306368,805306368,805306368};
        int h = 1000000000;
        LEETCODE_Minimum_Eating_Speed MyClass = new LEETCODE_Minimum_Eating_Speed();
        System.out.print(MyClass.minEatingSpeed(piles,h));
    }

    public int minEatingSpeed(int[] piles, int h) {
        
        int low = 1; // minimum banana/hr eating speed
        int high  = Arrays.stream(piles).max().getAsInt();
        int answer = high;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(Ispossible(piles,h,mid)){
                answer = mid;
                high =  mid-1;
            }
            else {
                low = mid+1;
            }
        }

        return answer;
    }

    public boolean Ispossible(int[] piles, int h,int k){
        int count = 0;
        for(int i=0;i<piles.length;i++){
            if(count > h) return false;
            count  = count + (piles[i]/k) + ((piles[i]%k==0) ? 0 : 1);
        }
      

        return count <= h;
    }

}
