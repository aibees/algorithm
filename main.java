import java.util.Scanner;
import java.util.Date;
import java.util.Calendar;
import java.text.SimpleDateFormat;
class Main {
    public static void main(String[] args) {
        String name;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your name : ");
        name = sc.nextLine();
        System.out.println(name);
        
        System.out.println("date in calendar : " + Calendar.getInstance().DAY_OF_MONTH);
        Date day = new Date();
        SimpleDateFormat format = new SimpleDateFormat("yy-MM-dd");
        System.out.println("date in Date : " + day.toString());
        System.out.println("date in Date formatting : " + format.format(day));
        Calendar cal = Calendar.getInstance();
        cal.setTime(day);
        cal.add(Calendar.DATE, 14);
        day = cal.getTime();
        System.out.println("date in Date after 14th : " + format.format(day));
        System.out.print("just enter : ");
        String enter = sc.nextLine();
        System.out.println(enter);
        if(enter == "\n")
            System.out.println("true");
        sc.close();
    }
}