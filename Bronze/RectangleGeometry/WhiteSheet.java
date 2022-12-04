import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class WhiteSheet {
    
    public static int interArea(int[] rect1, int[] rect2) {
        int length = Math.min(rect1[2], rect2[2]) - Math.max(rect1[0], rect2[0]);
        int width = Math.min(rect1[3], rect2[3]) - Math.max(rect1[1], rect2[1]);
        return length*width;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer s;

        int[][] read = new int[3][4];

        for(int i = 0; i < 3; i++) {
            s = new StringTokenizer(r.readLine());
            read[i][0] = Integer.parseInt(s.nextToken());
            read[i][1] = Integer.parseInt(s.nextToken());
            read[i][2] = Integer.parseInt(s.nextToken());
            read[i][3] = Integer.parseInt(s.nextToken());
        }

        int area = (read[0][2]-read[0][0])*(read[0][3]-read[0][1]);

        System.out.println(interArea(read[0], read[1]));

        System.out.println(interArea(read[0], read[1]) + interArea(read[0], read[2]) - interArea(read[1], read[2]) > area);

    }
}
