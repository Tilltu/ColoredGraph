import static java.lang.System.out;

import java.io.File;
import java.net.URI;
import java.net.URL;
import java.util.Scanner;

public class Input {


    //public native void coloredGraph();


    public static native void MapPrint(int[] adj_matrix);

    //public native void hello();

    public static void main(String... args){
        //System.out.println("hello");
        System.out.println(System.getProperty("java.library.path"));
        //String str = System.getProperty("java.library.path");
        //File file = new File(str);
        //File [] files = file.listFiles();
        //System.out.println(files[0].getName());
        //System.out.println(System.mapLibraryName("Hello"));
        System.loadLibrary("Print");

        Scanner in = new Scanner(System.in);

        out.println("[ Please Input The Number Of Vertices ]");
        int vex_num = in.nextInt();
        int [] adj_matrix = new int[vex_num * vex_num];

        int i, j, val;
        /*for (i = 0;i < vex_num ;i++) {
            adj_matrix[i] = new int[vex_num];
        }*/
        out.println("[ Please Input The Adjasent Matrix ]");

        for (i = 0;i < vex_num * vex_num;i++) {
            adj_matrix[i] = in.nextInt();
        }

        try {
            MapPrint(adj_matrix);
        } catch (Exception e) {
            e.printStackTrace();
        }

        in.close();
    }



}
