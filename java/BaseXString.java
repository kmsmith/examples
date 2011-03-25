/*
 * 6 in base 3 is 20
 *
 * Usage:  java BaseString 6 3
 * 
 * Only handles positive integers
 *
 */

public class BaseXString {
    private String baseXString;

    public BaseXString(int dec, int base) {
        baseXString = decimalToBaseX(dec, base);
    }

    public String getString() {
        return baseXString;
    }

    public static String decimalToBaseX(int dec, int base) {
        // we only handle bases 2 - 10
        base = base % 10;
        if (base < 2) base = 2;

        if (dec < base) return Integer.toString(dec);
        return decimalToBaseX((dec / base), base) + Integer.toString(dec % base);
    }

    public static void main(String[] args) {
        int dec = 2147483647;
        int base = 2;
        if (args.length == 2) {
            try {
                dec = Integer.parseInt(args[0]);
                base = Integer.parseInt(args[1]);
            } catch (NumberFormatException e) {
                dec = 2147483647;
                base = 2;
            }
        }
        BaseXString bString = new BaseXString(dec, base);
        System.out.println(bString.getString());

        System.out.println(decimalToBaseX(dec, base));
    }
}
