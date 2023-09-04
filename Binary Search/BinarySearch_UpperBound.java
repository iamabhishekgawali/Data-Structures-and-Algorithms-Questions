
import java.util.Arrays;

public class BinarySearch_UpperBound {
    
    public static void main(String[] args){

        int []arr = {10,12,45,13,26,100};
        int K = 19;
        int higher_bound= -1;

        Arrays.sort(arr);

        int low = 0;
        int high = arr.length-1;

        while(low <= high){
            int mid = low + ((high-low)/2);
            if(arr[mid] >= K) {   // Got potential higher bound now move right
                higher_bound = arr[mid];  // Potential answer for higher bound
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        System.out.print(higher_bound);

    }

}
