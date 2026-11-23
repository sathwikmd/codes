import java.util.Scanner;
class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter units consumed: ");
        int units = sc.nextInt();
        double bill;

        if (units <= 100) {
            bill = units * 1.50;
        } else if (units <= 200) {
            bill = 100 * 1.50 + (units - 100) * 2.50;
        } else {
            bill = 100 * 1.50 + 100 * 2.50 + (units - 200) * 4.00;
        }

        System.out.printf("Total bill: %.2f", bill);
        sc.close();
    }
}
