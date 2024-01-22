/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package n.lab4;
import java.util.Scanner;

/**
 *
 * @author Назар
 */

public class Lab4 {
   
    public static void main( String[] args) {
    Scanner scanner = new Scanner(System.in);
        int i = 0;
        System.setProperty("console.encoding", "Cp65001");
        System.out.println("Введите кол-во собственников (1-10): ");
        int n = scanner.nextInt();
        scanner.nextLine();
        while (n < 1 || n > 10) {
            System.out.println("Некорректное значение. Введите кол-во собственников (1-10): ");
            n = scanner.nextInt();
            scanner.nextLine();
        }
       
        System.out.println("Прочитать из файла? (1 - да, 2 - нет): ");
        int w = scanner.nextInt();
        scanner.nextLine();
 
    
        while (w != 1 && w != 2) {
            System.out.println("Некорректное значение. Прочитать из файла? (1 - да, 2 - нет): ");
            w = scanner.nextInt();
            scanner.nextLine();
        }
        sobst[] sbs = new sobst[n];
        for (i=0; i < n; i++) {
          sbs[i] = new sobst();
        }
        if (w == 1) {
            sbs[0].filein(sbs,n);
        } else {
            sbs[0].vvod(sbs,n);
        }
        w = 0;
        System.out.println("Записать в файл? (1 - да, 2 - нет): ");
        w = scanner.nextInt();
        scanner.nextLine();
        while (w != 1 && w != 2) {
            System.out.println("Некорректное значение. Записать в файл? (1 - да, 2 - нет): ");
            w = scanner.nextInt();
            scanner.nextLine();
        }
        if (w == 1) {
            sbs[0].fileout(sbs,n);
        }
        w = 0;
        do {
            System.out.println("Провести поиск? (1 - да, 2 - нет): ");
            w = scanner.nextInt();
            scanner.nextLine();
            while (w != 1 && w != 2) {
                System.out.println("Некорректное значение. Провести поиск? (1 - да, 2 - нет): ");
                w = scanner.nextInt();
                scanner.nextLine();
            }
            if (w == 1) {
                sbs[0].poisk(sbs,n);
            }
            System.out.println("Нажмите Enter, чтобы продолжить...");
            scanner.nextLine();
        } while (w == 1);
    }
}
