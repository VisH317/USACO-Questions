import java.util.*;
import java.io.*;

public class BovineGenomics {

    public static int bovineGenomes(String[] spotty, String[] plain) {
        int count = 0;
        for(int a = 0; a < spotty[0].length()-2; a++) {
            for(int b = a + 1; b < spotty[0].length()-1; b++) {
                for(int c = b + 1; c < spotty[0].length(); c++) {
                    for(String element : plain) {
                        for(String elem2 : spotty) {
                            if(element.charAt(a)!=elem2.charAt(a) || element.charAt(b)!=elem2.charAt(b) || element.charAt(c)!=elem2.charAt(c)) {
                                count++;
                            }
                        }
                    }
                }
            }
        }

        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(r.readLine().split(" ")[0]);
        String[] spotty = new String[count];
        String[] plain = new String[count];
        for(int i = 0; i < count; i++) spotty[i]=r.readLine();
        for(int j = 0; j < count; j++) plain[j]=r.readLine();

        System.out.println(bovineGenomes(spotty, plain));
    }
}
