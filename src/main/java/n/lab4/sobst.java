/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

package n.lab4;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
/**
 *
 * @author Назар
 */


public class sobst {

   
    int sobstnum;
    String sobstname;
    sobstf sobstforma;
    stortype sttype;
    storage[] prodsp;
    int prodkol;
    storage[] hossp;
    int hoskol;
    int stkol;

    public static int sbs_max = 10;
    
    public enum sobstf {
    Firma,
    Gos,
    Fislitso
    }

    
    
    public sobst() {
        this.sobstnum = 0;
        this.sobstname = "";
        this.sobstforma = null;
        //this.prodsp = new storage[5];
        this.prodkol = 0;
        //this.hossp = new storage[5];
        this.hoskol = 0;
        this.stkol = 0;
    }

    public void printtype() {
        switch (this.sobstforma) {
            case Firma -> System.out.println("Фирма");
            case Gos -> System.out.println("Государственная");
            case Fislitso -> System.out.println("Физлицо");
        }
    }

    public void prodinfo() {
        System.out.println("\nНомер собственника: " + this.sobstnum);
        System.out.println("Наименование собственника: " + this.sobstname);
        System.out.println("Количество продовольственных складов собственника: " + this.prodkol);
        for (int ip = 0; ip < this.prodkol; ip++) {
            System.out.println("\n\n-Номер склада: " + this.prodsp[ip].stnum + "-");
            System.out.println("Количество видов товаров на " + this.prodsp[ip].stnum + " складе: " + this.prodsp[ip].tovkol);
            System.out.printf("\nКоличество сотрудников на складе: %d\n", this.prodsp[ip].Getkolsotr());

        }
    }

    public void hosinfo() {
        System.out.println("\nНомер собственника: " + this.sobstnum);
        System.out.println("Наименование собственника: " + this.sobstname);
        System.out.println("Количество хозяйственных складов собственника: " + this.hoskol);
        for (int ih = 0; ih < this.hoskol; ih++) {
            System.out.println("\n\n-Номер склада: " + this.hossp[ih].stnum + "-");
            System.out.println("Количество видов товаров на " + this.hossp[ih].stnum + " складе: " + this.hossp[ih].tovkol);
            System.out.printf("\nКоличество сотрудников на складе: %d\n", this.hossp[ih].Getkolsotr());
        }
    }

    public void printinfo() {
        System.out.println("\nНомер собственника: " + this.sobstnum);
        System.out.println("Наименование собственника: " + this.sobstname);
        System.out.print("Форма собственности: ");
        this.printtype();
        System.out.println("Количество продовольственных складов собственника: " + this.prodkol);
        System.out.println("Количество хозяйственных складов собственника: " + this.hoskol);
        System.out.println("Количество всех складов собственника: " + this.stkol);
        System.out.println("\n--Склады собственника--");
        for (int ip = 0; ip < this.prodkol; ip++) {
            System.out.println("\n\n-Номер склада: " + this.prodsp[ip].stnum + "-");
            System.out.print("Тип склада: ");
            this.prodsp[ip].printtype();
            System.out.println("Количество видов товаров на " + this.prodsp[ip].stnum + " складе: " + this.prodsp[ip].tovkol);
            System.out.println("=Товары склада " + this.prodsp[ip].stnum + "=");
            for (int it = 0; it < this.prodsp[ip].tovkol; it++) {
                System.out.println("Номер товара: " + this.prodsp[ip].tovars[it].tovnum);
                System.out.println("Наименование товара: " + this.prodsp[ip].tovars[it].tovname);
                System.out.println("Количество в наличии: " + this.prodsp[ip].tovars[it].tkol);
            }
        }
        for (int ih = 0; ih < this.hoskol; ih++) {
            System.out.println("\n\n-Номер склада: " + this.hossp[ih].stnum + "-");
            System.out.print("Тип склада: ");
            this.hossp[ih].printtype();
            System.out.println("Количество видов товаров на " + this.hossp[ih].stnum + " складе: " + this.hossp[ih].tovkol);
            System.out.println("=Товары склада " + this.hossp[ih].stnum + "=");
            for (int it = 0; it < this.hossp[ih].tovkol; it++) {
                System.out.println("Номер товара: " + this.hossp[ih].tovars[it].tovnum);
                System.out.println("Наименование товара: " + this.hossp[ih].tovars[it].tovname);
                System.out.println("Количество в наличии: " + this.hossp[ih].tovars[it].tkol);
            }
        }
    }

    public void vvod(sobst[] asbs, int n) {
        Scanner scanner = new Scanner(System.in);
        int i, d;
        /*do {
            System.out.print("\nВведите кол-во собственников (1-" + sbs_max + "): ");
            n = scanner.nextInt();
            scanner.nextLine();
        } while (n < 1 || n > sbs_max);*/
        for (i = 0; i < n; i++) {
            System.out.println("=== Ввод собственника: -" + (i + 1) + "- ===");
            System.out.print("\nВведите номер: ");
            this.sobstnum = scanner.nextInt();
            scanner.nextLine();
            System.out.print("\nВведите название: ");
            this.sobstname = scanner.nextLine();
            System.out.print("\nВведите форму собственности (1 - фирма, 2 - гос, 3 - физлицо): ");
            d = scanner.nextInt();
            scanner.nextLine();
            switch (d) {
                case 1 -> this.sobstforma = sobstf.Firma;
                case 2 -> this.sobstforma = sobstf.Gos;
                case 3 -> this.sobstforma = sobstf.Fislitso;
            }
            System.out.print("\nВведите кол-во продовольственных складов: ");
            this.prodkol = scanner.nextInt();
            System.out.print("\nВведите кол-во хозяйственных складов: ");
            this.hoskol = scanner.nextInt();
            scanner.nextLine();

            this.prodsp = new storage[this.prodkol];
            for (int ip = 0; ip < prodkol; ip++) {
                this.prodsp[ip] = new storage();
                System.out.println("--- Ввод прод склада: -" + (ip + 1) + "- ---");
                System.out.print("\nВведите номер: ");
                this.prodsp[ip].stnum = scanner.nextInt();
                scanner.nextLine();
                this.prodsp[ip].sttype = sttype.StProdov;
                System.out.print("\nВведите кол-во видов товара на складе " + this.prodsp[ip].stnum + ": ");
                this.prodsp[ip].tovkol = scanner.nextInt();
                scanner.nextLine();

                this.prodsp[ip].tovars = new tovar[this.prodsp[ip].tovkol];
                for (int it = 0; it < this.prodsp[ip].tovkol; it++) {
                    this.prodsp[ip].tovars[it] = new tovar();
                    System.out.print("\nВведите номер товара: ");
                    this.prodsp[ip].tovars[it].tovnum = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("\nВведите наименование товара: ");
                    this.prodsp[ip].tovars[it].tovname = scanner.nextLine();
                    System.out.print("\nВведите кол-во данного товара: ");
                    this.prodsp[ip].tovars[it].tkol = scanner.nextInt();
                    scanner.nextLine();
                }
            }
            /*System.out.print("\nВведите кол-во хозяйственных складов: ");
            this.hoskol = scanner.nextInt();
            scanner.nextLine();*/

            this.hossp = new storage[this.hoskol];
            for (int ih = 0; ih < this.hoskol; ih++) {
                this.hossp[ih] = new storage();
                System.out.println("--- Ввод хоз склада: -" + (ih + 1) + "- ---");
                System.out.print("\nВведите номер: ");
                this.hossp[ih].stnum = scanner.nextInt();
                scanner.nextLine();
                this.hossp[ih].sttype = sttype.StHosyast;
                System.out.print("\nВведите кол-во видов товара на складе " + this.hossp[ih].stnum + ": ");
                this.hossp[ih].tovkol = scanner.nextInt();
                scanner.nextLine();

                this.hossp[ih].tovars = new tovar[this.hossp[ih].tovkol];
                for (int it = 0; it < this.hossp[ih].tovkol; it++) {
                    this.hossp[ih].tovars[it] = new tovar();
                    System.out.print("\nВведите номер товара: ");
                    this.hossp[ih].tovars[it].tovnum = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("\nВведите наименование товара: ");
                    this.hossp[ih].tovars[it].tovname = scanner.nextLine();
                    System.out.print("\nВведите кол-во данного товара: ");
                    this.hossp[ih].tovars[it].tkol = scanner.nextInt();
                    scanner.nextLine();
                }
            }
            this.stkol = this.prodkol + this.hoskol;
        }
    }

    public void fileout(sobst[] asbs, int kol) {
        try {
            try (FileWriter writer = new FileWriter("sobst.txt")) {
                for (int i = 0; i < kol; i++) {
                    writer.write("=== Собственник -" + (i + 1) + "/" + kol + "- ===\n");
                    writer.write(asbs[i].sobstnum + "\n");
                    writer.write(asbs[i].sobstname + "\n");
                    writer.write(asbs[i].sobstforma + "\n");
                    writer.write(asbs[i].prodkol + "\n");
                    
                    for (int ip = 0; ip < asbs[i].prodkol; ip++) {
                        writer.write("--- Прод склад -" + (ip + 1) + "/" + asbs[i].prodkol + "- ---\n");
                        writer.write(asbs[i].prodsp[ip].stnum + "\n");
                        writer.write(asbs[i].prodsp[ip].sttype + "\n");
                        writer.write(asbs[i].prodsp[ip].tovkol + "\n");
                        
                        writer.write("- Список товаров (" + asbs[i].prodsp[ip].tovkol + ") -\n");
                        for (int it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
                            writer.write(asbs[i].prodsp[ip].tovars[it].tovnum + "\n");
                            writer.write(asbs[i].prodsp[ip].tovars[it].tovname + "\n");
                            writer.write(asbs[i].prodsp[ip].tovars[it].tkol + "\n");
                        }
                    }
                    writer.write(asbs[i].hoskol + "\n");
                    
                    for (int ih = 0; ih < asbs[i].hoskol; ih++) {
                        writer.write("--- Хоз склад -" + (ih + 1) + "/" + asbs[i].hoskol + "- ---\n");
                        writer.write(asbs[i].hossp[ih].stnum + "\n");
                        writer.write(asbs[i].hossp[ih].sttype + "\n");
                        writer.write(asbs[i].hossp[ih].tovkol + "\n");
                        
                        writer.write("- Список товаров (" + asbs[i].hossp[ih].tovkol + ") -\n");
                        for (int it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
                            writer.write(asbs[i].hossp[ih].tovars[it].tovnum + "\n");
                            writer.write(asbs[i].hossp[ih].tovars[it].tovname + "\n");
                            writer.write(asbs[i].hossp[ih].tovars[it].tkol + "\n");
                        }
                    }
                }
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
        }
    }

    public void poisk(sobst[] asbs, int kol) {
        Scanner scanner = new Scanner(System.in);
        int i, n = 0, ip = 0, ih = 0, it = 0;
        int pk, d,  z, q, stnum, sttypes, tovkol;        
        
        System.out.print("Выберите с какого уровня хотите провести поиск \n(1 уровень - Структура собственника, 2 уровень - структура склада, 3 уровень - структура товара): ");
        z = scanner.nextInt();
        switch (z) {
            case 1:
                System.out.print("\n\nВыберите поле по которому хотите провести поиск \n(1 - по номеру собственника, 2 - по имени собственника, 3 - по форме собственности): ");
                d = scanner.nextInt();
                switch (d) {
                    case 1:
                        System.out.print("\nВведите номер собственника: ");
                        sobstnum = scanner.nextInt();
                        for (i = 0; i < kol; i++) {
                            if (sobstnum == asbs[i].sobstnum) {
                                System.out.println("\n\n---Информация по " + (i + 1) + " собственнику---");
                                asbs[i].printinfo();
                            }
                        }
                        break;
                    case 2:
                        System.out.print("\nВведите имя собственника: ");
                        scanner.nextLine();
                        sobstname = scanner.nextLine();
                        for (i = 0; i < kol; i++) {
                            if (sobstname.equals(asbs[i].sobstname)) {
                                System.out.println("\n\n---Информация по " + (i + 1) + " собственнику---");
                                asbs[i].printinfo();
                            }
                        }
                        break;
                    case 3:
                        System.out.print("\nВведите форму собственности для поиска \n ( 1 - фирма, 2 - гос.предприятие, 3 - физическое лицо ): ");
                        q = scanner.nextInt();
                        for (i = 0; i < kol; i++) {
                            if (asbs[i].sobstforma.ordinal() == q - 1) {
                                System.out.println("\n\n---Информация по " + (i + 1) + " собственнику---");
                                asbs[i].printinfo();
                            }
                        }
                        q = 0;
                        break;
                    default:
                        System.out.println("\n\nТакого варианта нет!\n\n");
                        break;
                }
                break;
            case 2:
                System.out.print("\nВведите номер поля для поиска ( 1 - поиск по номеру склада, \n2 - вывод информации о продовольственных складах, 3 - вывод информации о хозяйственных складах): ");
                q = scanner.nextInt();
                switch (q) {
                    case 1 -> {
                        System.out.print("\nВведите тип склада для поиска ( 1 - продовольственный, 2 - хозяйственный ): ");
                        sttypes = scanner.nextInt();
                        switch (sttypes) {
                            case 1 -> {
                                System.out.print("\nВведите номер склада для поиска: ");
                                stnum = scanner.nextInt();
                                for (i = 0; i < kol; i++) {
                                    for (ip = 0; ip < asbs[i].prodkol; ip++) {
                                        if (stnum == asbs[i].prodsp[ip].stnum) {
                                            System.out.println("\n== Информация по складу: " + asbs[i].prodsp[ip].stnum + "==");
                                            System.out.println("Номер собственника: " + asbs[i].sobstnum);
                                            System.out.println("Наименование собственника: " + asbs[i].sobstname);
                                            asbs[i].prodsp[ip].tovinfo();
                                        }
                                    }
                                }
                }
                            case 2 -> {
                                System.out.print("Введите номер склада для поиска: ");
                                stnum = scanner.nextInt();
                                for (i = 0; i < kol; i++) {
                                    for (ih = 0; ih < asbs[i].hoskol; ih++) {
                                        if (stnum == asbs[i].hossp[ih].stnum) {
                                            System.out.println("\n== Информация по складу: " + asbs[i].hossp[ih].stnum + "==");
                                            System.out.println("Номер собственника: " + asbs[i].sobstnum);
                                            System.out.println("Наименование собственника: " + asbs[i].sobstname);
                                            asbs[i].hossp[ih].tovinfo();
                                        }
                                    }
                                }
                }
                        }
                }
                    case 2 -> {
                        for (i = 0; i < kol; i++) {
                            System.out.println("\n\n---Информация по " + (i + 1) + " собственнику---");
                            asbs[i].prodinfo();
                        }
                }
                    case 3 -> {
                        for (i = 0; i < kol; i++) {
                            System.out.println("\n\n---Информация по " + (i + 1) + " собственнику---");
                            asbs[i].hosinfo();
                        }
                }
                    default -> System.out.println("\n\nТакого варианта нет!\n\n");
                }

            case 3:
                break;
            default:
                System.out.println("\n\nТакого варианта нет!\n\n");
                break;
        }
        System.out.println("\n\nПоиск завершен\n\n");
    }

    public void filein(sobst[] asbs, int kol) {
        int i = 0, k=0, l=0, ip = 0, ih = 0, it = 0;
        BufferedReader reader;
        String line;
        try {
            reader = new BufferedReader(new FileReader("d:\\OOP\\lab4\\src\\main\\java\\n\\lab4\\sobst.txt"));
            while ((line = reader.readLine()) != null) {
                line = reader.readLine();
                asbs[i].sobstnum = Integer.parseInt(line);
                asbs[i].sobstname = reader.readLine();
                k = Integer.parseInt(reader.readLine());
                switch (k){
                    case 1 -> asbs[i].sobstforma = sobstf.Firma;
                    case 2 -> asbs[i].sobstforma = sobstf.Gos;
                    case 3 -> asbs[i].sobstforma = sobstf.Fislitso;
                }
                
                asbs[i].prodkol = Integer.parseInt(reader.readLine());
                l = asbs[i].prodkol;
                asbs[i].prodsp = new storage[l];
                for(k=0;k<l;k++) asbs[i].prodsp[k] = new storage();
                for (ip = 0; ip < asbs[i].prodkol; ip++) {
                    line = reader.readLine();
                    asbs[i].prodsp[ip].stnum = Integer.parseInt(reader.readLine());
                    line = reader.readLine();
                    /*k = Integer.parseInt(reader.readLine());
                    switch (k){
                      case 1 -> asbs[i].prodsp[ip].sttype = sttype.StProdov;
                      case 2 -> asbs[i].prodsp[ip].sttype = sttype.StHosyast;
                    }*/
                    asbs[i].prodsp[ip].tovkol = Integer.parseInt(reader.readLine());
                    l = asbs[i].prodsp[ip].tovkol;
                    asbs[i].prodsp[ip].tovars = new tovar[l];
                    for(k=0;k<l;k++) asbs[i].prodsp[ip].tovars[k] = new tovar();
                    line = reader.readLine();
                    for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
                        asbs[i].prodsp[ip].tovars[it].tovnum = Integer.parseInt(reader.readLine());
                        asbs[i].prodsp[ip].tovars[it].tovname = reader.readLine();
                        asbs[i].prodsp[ip].tovars[it].tkol = Integer.parseInt(reader.readLine());
                    }
                }
                asbs[i].hoskol = Integer.parseInt(reader.readLine());
                l = asbs[i].hoskol;
                asbs[i].hossp = new storage[l];
                for(k=0;k<l;k++) asbs[i].hossp[k] = new storage();
                for (ih = 0; ih < asbs[i].hoskol; ih++) {
                    line = reader.readLine();
                    asbs[i].hossp[ih].stnum = Integer.parseInt(reader.readLine());
                    line = reader.readLine();
                    /*k = Integer.parseInt(reader.readLine());
                    switch (k){
                      case 1 -> asbs[i].hossp[ih].sttype = sttype.StProdov;
                      case 2 -> asbs[i].hossp[ih].sttype = sttype.StHosyast;
                    } */
                    asbs[i].hossp[ih].tovkol = Integer.parseInt(reader.readLine());
                    l = asbs[i].hossp[ih].tovkol;
                    asbs[i].hossp[ih].tovars = new tovar[l];
                    for(k=0;k<l;k++) asbs[i].hossp[ih].tovars[k] = new tovar();
                    line = reader.readLine();
                    for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
                        asbs[i].hossp[ih].tovars[it].tovnum = Integer.parseInt(reader.readLine());
                        asbs[i].hossp[ih].tovars[it].tovname = reader.readLine();
                        asbs[i].hossp[ih].tovars[it].tkol = Integer.parseInt(reader.readLine());
                    }
                }
                asbs[i].stkol = asbs[i].prodkol + asbs[i].hoskol;
                i++;
            }
            reader.close();
        } catch (IOException e) {
            System.out.println("Ошибка открытия файла");
        }
    }
}
