public class PrimeChecker {
    public static boolean isPrime(int value) {
        if (value < 2) {
            return false;
        }
        if (value % 2 == 0) {
            return value == 2;
        }
        for (int i = 3; i * i <= value; i += 2) {
            if (value % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        for (int value = 1; value <= 30; value++) {
            System.out.printf("%d -> %s%n", value, isPrime(value));
        }
    }
}
