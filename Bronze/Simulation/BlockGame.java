import java.io.*;
import java.util.*;

public class BlockGame {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

        int count = Integer.parseInt(r.readLine());
        int[] abArr = new int[26];

        for(int i = 0; i < count; i++) {
            String[] letters = r.readLine().split(" ");

            for(int j = 0; j < letters[0].length(); j++) {
                abArr[letters[0].charAt(j)-97]++;
            }
            for(int k = 0; k < letters[1].length(); k++) {
                if(Arrays.asList(letters[0].split("")).contains(Character.toString(letters[1].charAt(k)))) continue;
                abArr[letters[1].charAt(k)-97]++;
            }
        }

        for(int element : abArr) {
            System.out.println(Integer.toString(element));
        }
    }
}