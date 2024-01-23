/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package n.lab7;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 *
 * @author Назар
 */

public class Lab7 {
   
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
        
        
        List<tovar> tovarList = new ArrayList<>();

        tovar tov1 = new tovar();
        tov1.tovnum = 2;
        tov1.tovname = "пшено";
        tov1.tkol = 20;

        tovar tov2 = new tovar();
        tov2.tovnum = 1;
        tov2.tovname = "рис";
        tov2.tkol = 30;

        tovar tov3 = new tovar();
        tov3.tovnum = 3;
        tov3.tovname = "овсянка";
        tov3.tkol = 40;

        tovarList.add(tov1);
        tovarList.add(tov2);
        tovarList.add(tov3);

        Collections.sort(tovarList, new Comparator<tovar>() {
            @Override
            public int compare(tovar a, tovar b) {
                return Integer.compare(a.tkol, b.tkol);
            }
        });

        System.out.println("\nРезультат сортировки по количеству товара (tkol):");
        for (tovar t : tovarList) {
            System.out.println("\ntovnum: " + t.tovnum + ", tovname: " + t.tovname + ", tkol: " + t.tkol);
        }

        int tovnumToFind = 3;
        tovar foundTovar = null;
        for (tovar t : tovarList) {
            if (t.tovnum == tovnumToFind) {
                foundTovar = t;
                break;
            }
        }

        if (foundTovar != null) {
            System.out.println("\nНайдено имя товара с номером 3: " + foundTovar.tovname);
        } else {
            System.out.println("\nИмя товара с номером 3 не найдено");
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
