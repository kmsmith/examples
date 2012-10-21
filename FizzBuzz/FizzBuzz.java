public class FizzBuzz
{
    public static void main(String args[])
    {
        for (int i = 1; i < 101; i++)
        {
            String line = "";
            if (i % 3 == 0)
                line += "Fizz";
            if (i % 5 == 0)
                line += "Buzz";
            if (line.equals(""))
                line = Integer.toString(i);
            System.out.println(line);
        }
    }
}
