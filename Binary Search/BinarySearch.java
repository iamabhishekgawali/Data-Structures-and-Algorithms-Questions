public class BinarySearch {


    public static void main(String[] args) {

        // Example of Binary Search
         System.out.print(Solve());

    }

    public static boolean Solve() {

        int[] arr = {1, 2, 3, 4, 5, 6};

        int low = 0;
        int high = arr.length-1;
        int K = 15;

        while (low <= high) {
            int mid = low + ((high - low) / 2); // To avoid Overflow
            if (arr[mid] == K) return true;
            if (arr[mid] < K) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
}