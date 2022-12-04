import java.util.*;
import java.io.*;

public class NextRound {
    public static int nextRound(int place, int[] scores) {
        int count = place;
        Arrays.sort(scores);
        int desScore = scores[scores.length-place];

        if(desScore<=0) {
            int zeroCount = 0;
            for(int j = scores.length-1; j > -1; j--) {
                if(scores[j]<=0) return zeroCount;
                zeroCount++;
            }
        }

        for(int i = scores.length-place-1; i > -1; i--) {
            if(scores[i]!=desScore) return count;
            count++;
        }

        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        int place = Integer.parseInt(r.readLine().split(" ")[1]);
        String[] scores = r.readLine().split(" ");
        int[] newScores = new int[scores.length];
        for(int i = 0; i < scores.length; i++) {
            newScores[i] = Integer.parseInt(scores[i]);
        }

        System.out.println(nextRound(place, newScores));
    }
}
