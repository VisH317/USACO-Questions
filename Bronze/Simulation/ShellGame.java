import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ShellGame {
    
    public static int findCorrect(int[][] swaps) {

        int maxSwaps = 0;

        for(int i = 1; i <= 3; i++) {
            int current = i;
            int swapsCt = 0;
            for(int[] element : swaps) {
                if(element[0]==current || element[1]==current) {
                    current = element[0]==current ? element[1] : element[0];
                }

                if(current==element[2]) {
                    swapsCt++;
                }
            }

            if(maxSwaps<swapsCt) maxSwaps=swapsCt;
        }

        return maxSwaps;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

        int count = Integer.parseInt(r.readLine());
        int[][] arg = new int[count][3];

        for(int i = 0; i < count; i++) {
            String[] currentLine = r.readLine().split(" ");
            int[] toAdd = new int[3];
            for(int j = 0; j < 3; j++) {
                toAdd[j] = Integer.parseInt(currentLine[j]);
            }

            arg[i] = toAdd;
        }

        System.out.println(findCorrect(arg));

        r.close();

    }
}