/*
 * Usage:  java BinaryString 32
 * 
 * Only handles positive integers
 *
 */

public class BinaryString {
    private String binaryString;

    public BinaryString(int dec) {
        binaryString = decimalToBinary(dec);
    }

    public String getString() {
        return binaryString;
    }

    public static String decimalToBinary(int dec) {
        if (dec < 2) return Integer.toString(dec);
        return decimalToBinary(dec / 2) + Integer.toString(dec % 2);
    }

    public static void main(String[] args) {
        int dec = 2147483647;
        if (args.length == 1) {
            try {
                dec = Integer.parseInt(args[0]);
            } catch (NumberFormatException e) {
                dec = 2147483647;
            }
        }
        BinaryString bString = new BinaryString(dec);
        System.out.println(bString.getString());

        System.out.println(decimalToBinary(dec));
    }
}
