import static java.lang.System.out;

import java.awt.*;
import java.util.Scanner;
import javax.swing.*;

public class Input {

    public static final int VEXDISTANCE = 100;
    public static final int VEXRADIUS = 11;

    public static final int MAXLEN = 10;

    public static int vex_num;
    public static String[] params;
    public static int[] adj_matrix;


    static {
        System.loadLibrary("Print");        // Load The Library
    }


    /**
     * @param params Infomation given by the backend
     * @param index  The index of vertex
     * @return The color of that vertex
     */
    public static Color visitColor(String[] params, int index) {
        int i;

        String result_color = "";

        for (i = 1; i < params.length; i += 2) {
            if (index == Integer.valueOf(params[i])) {
                result_color = params[i + 1];
            }
        }

        switch (result_color) {
            case "green": {
                return Color.GREEN;
            }
            case "red": {
                return Color.RED;
            }
            case "blue": {
                return Color.BLUE;
            }
            case "yellow": {
                return Color.YELLOW;
            }
            case "orange": {
                return Color.ORANGE;
            }
            case "black": {
                return Color.BLACK;
            }
            case "cyan": {
                return Color.CYAN;
            }
            case "magenta": {
                return Color.MAGENTA;
            }
            case "grey": {
                return Color.GRAY;
            }
            case "pink": {
                return Color.PINK;
            }
            default: {
                return Color.BLACK;
            }
        }

    }


    /**
     * @param adj_matrix Adjacent matrix given to backend
     * @return Indfomation containing chromatic number and the colors of all vertices
     */
    public static native String getColorInfo(int[] adj_matrix);


    public static void main(String... args) {

        Scanner in = new Scanner(System.in);


        boolean input_flag = false;

        out.println("[ Please Input The Number Of Vertices ] ( FYI : The Maximum Amount Of Vertices We Support Now Is 10 )");
        while (!input_flag) {
            vex_num = in.nextInt();
            if (vex_num > 0 && vex_num <= 10) {
                input_flag = true;
            } else {
                JOptionPane.showMessageDialog(null, "Input Error! Please Try Again!");
            }
        }

        adj_matrix = new int[vex_num * vex_num];


        int i;


        out.println("[ Please Input The Adjasent Matrix ]");

        for (i = 0; i < vex_num * vex_num; i++) {
            adj_matrix[i] = in.nextInt();
        }


        try {
            JFrame frame = new JFrame("Counting...");
            frame.setSize(500, 500);
            frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);


            String res = getColorInfo(adj_matrix);

            params = res.split("-");
            int chronatic_number = Integer.valueOf(params[0]);


            //System.out.println("[ Parameters Are As Follows ] : ");
            //System.out.println("********************************");
            /*for (i = 0;i < params.length;i++) {                              // If you want to see the explicit parameters, just uncomment the phase.
                System.out.print("Params[" + i + "]  ");
                System.out.println(params[i]);
            }*/

            String header = ("[ The Chromatic Number Is ] : " + chronatic_number);

            System.out.println(header);


            VisualGraph vg = new VisualGraph(250, 250);


            frame.add(vg);

            frame.setVisible(true);
            Thread.sleep(1000);

            JOptionPane.showMessageDialog(null, header);


        } catch (Exception e) {
            e.printStackTrace();
        }

        in.close();
    }


}


class VisualGraph extends JLabel {
    int x, y;

    public VisualGraph(int x, int y) {
        this.x = x;
        this.y = y;
    }


    public void paint(Graphics g) {
        int i, j;
        int conunter = 0;


        /**
         *  Drawing Colored Vertices
         */
        for (i = 0; i < Input.vex_num; i++) {
            double X = Input.VEXDISTANCE * Math.cos((i + 1) * 2 * Math.PI / Input.vex_num) + x;
            double Y = Input.VEXDISTANCE * Math.sin((i + 1) * 2 * Math.PI / Input.vex_num) + y;
            g.setColor(Input.visitColor(Input.params, (i + 1)));
            ;
            g.fillOval((int) X, (int) Y, 11, 11);


        }


        /**
         *  Drawing Edges
         */
        int[][] reconstruct_matrix = new int[Input.vex_num][];
        for (i = 0; i < Input.vex_num; i++) {
            reconstruct_matrix[i] = new int[Input.vex_num];
        }

        for (i = 0; i < Input.vex_num; i++) {
            for (j = 0; j < Input.vex_num; j++) {
                reconstruct_matrix[i][j] = Input.adj_matrix[conunter++];

            }
        }

        for (i = 0; i < Input.vex_num; i++) {
            for (j = 0; j < Input.vex_num; j++) {
                if (reconstruct_matrix[i][j] == 1) {
                    reconstruct_matrix[j][i] = 1;
                }

            }
        }


        for (i = 0; i < Input.vex_num; i++) {
            for (j = 0; j < Input.vex_num; j++) {
                if (reconstruct_matrix[i][j] == 1 && i != j) {
                    double X = Input.VEXDISTANCE * Math.cos((i + 1) * 2 * Math.PI / Input.vex_num) + x;
                    double Y = Input.VEXDISTANCE * Math.sin((i + 1) * 2 * Math.PI / Input.vex_num) + y;

                    double X2 = Input.VEXDISTANCE * Math.cos((j + 1) * 2 * Math.PI / Input.vex_num) + x;
                    double Y2 = Input.VEXDISTANCE * Math.sin((j + 1) * 2 * Math.PI / Input.vex_num) + y;
                    g.setColor(Color.BLACK);

                    g.drawLine((int) (X + 6.5), (int) (Y + 6.5), (int) (X2 + 6.5), (int) (Y2 + 6.5));
                }
            }
        }

    }

}







