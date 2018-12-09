import jdk.nashorn.internal.scripts.JD;

import static java.lang.System.out;

import java.awt.*;
import java.io.File;
import java.net.URI;
import java.net.URL;
import java.util.Scanner;
import javax.swing.*;

public class Input {


    enum COLOR{
        DEFAUT(-1),
        RED(0),
        ORANGE(1),
        YELLOW(2),
        GREEN(3),
        BLUE(4),
        PURPLE(5),
        PINK(6);

        public int colorID;


        COLOR(int num) {
           colorID = num;
        }


        public String getColor(int id) {
            switch (id) {
                case 0: {
                    return "red";
                }
                case 1: {
                    return "orange";
                }
                case 2: {
                    return "yellow";
                }
                case 3: {
                    return "green";
                }
                case 4: {
                    return "blue";
                }
                case 5: {
                    return "purple";
                }
                case 6: {
                    return "pink";
                }
                default: {
                    return "";
                }
            }
        }
    }

    //public native void coloredGraph();

    static {
        System.loadLibrary("Print");
    }


    public static native int MapPrint(int[] adj_matrix);

    //public native void hello();

    public static void main(String... args){
        //System.out.println("hello");
        //System.out.println(System.getProperty("java.library.path"));
        //String str = System.getProperty("java.library.path");
        //File file = new File(str);
        //File [] files = file.listFiles();
        //System.out.println(files[0].getName());
        //System.out.println(System.mapLibraryName("Hello"));



        //JDialog dialog = new JDialog("Counting")

        /*JFrame frame = new JFrame("Counting ");
        frame.setSize(400, 500);
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        JPanel panel = new JPanel(new FlowLayout());
        JTextPane pane = new JTextPane(20, 20);
        pane.setEditable(false);
        panel.add(pane);
        frame.add(panel);
        frame.setVisible(true);*/

        //frame.getGraphics().drawLine();
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
            JFrame frame = new JFrame("Counting ");
            frame.setSize(400, 500);
            frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
            JPanel panel = new JPanel(new FlowLayout());
            JTextPane pane = new JTextPane();
            pane.setEditable(false);
            panel.add(pane);
            frame.add(panel);
            frame.setVisible(true);

            int chronatic_number = MapPrint(adj_matrix);
            //out.println(chronatic_number);

            //pane.append("[ The Chromtic Number Of The Graph Given Is ]\n" + chronatic_number);
            String header = "[ The Chromtic Number Of The Graph Given Is ]\n" + chronatic_number + "\n\n";
            pane.getDocument().insertString(pane.getDocument().getLength(), header, pane.getStyle("normal"));

            int index;
            for (index = 0;index < chronatic_number;index++) {
                String display = "The Color Of Vertex " + (index + 1) + " Is " + COLOR.DEFAUT.getColor(index) + "\n\n";
                pane.getDocument().insertString(pane.getDocument().getLength(), display, pane.getStyle("red"));
            }


        } catch (Exception e) {
            e.printStackTrace();
        }

        in.close();
    }



}
