public class Find {
    public static int Find(int[] input, int num) {
        return FindBinary(input, num, 0, input.length-1);
    }

    public static int FindBinary(int[] input, int num, int beg, int end) {
        if (input.length == 0) return -1;
        if (beg >= end) {
            if (input[beg] == num) {
                return beg;
            }
            else {
                return -1;
            }
        }
        int m = beg + ((end-beg)/2);
        if (input[m] == num)
            return m;
        else if (num < input[m])
            return FindBinary(input, num, beg, m-1);
        else
            return FindBinary(input, num, m+1, end);
    }

    public static void main(String[] args) {
        System.out.println(Find(new int[] {1,2,3,5,8,13,21}, 5));
        System.out.println(Find(new int[] {}, 5));
    }
}
