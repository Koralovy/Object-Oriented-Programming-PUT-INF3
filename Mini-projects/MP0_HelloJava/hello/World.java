package hello;

import java.util.Scanner;

public class World {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        String fellow = "World";
        System.out.printf("Hello␣%s \n", fellow);
        while (fellow != "exit") {
            System.out.printf("Introduce_yourself:_");
            fellow = s.nextLine();
            System.out.printf("Hello_%s\n", fellow);
        }
        s.close();
    }
}