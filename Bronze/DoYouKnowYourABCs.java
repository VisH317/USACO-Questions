import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class DoYouKnowYourABCs {

    public static String findABC(int[] vals) {
        int[] newVals = vals.clone();
        Arrays.sort(newVals);
        String a = Integer.toString(vals[0]);
        String b = Integer.toString(vals[1]);
        String c = Integer.toString(newVals[6] - Integer.valueOf(a) - Integer.valueOf(b));

        return a + " " + b + " " + c;

    }

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

        int[] input = new int[7];
        StringTokenizer st = new StringTokenizer(r.readLine());
        for(int i = 0; i < st.countTokens(); i++) {
            input[i] = Integer.parseInt(st.nextToken());
        }

        System.out.println(findABC(input));

    }
}