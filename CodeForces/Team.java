import java.util.*;
import java.io.*;

public class Team {
    
    public static int implement(String op) {
        String[] vals = op.split(" ");
        int total = 0;
        for(String element : vals) {
            total += Integer.parseInt(element);
        }

        return total >= 2 ? 1 : 0;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(r.readLine());
        int ret = 0;

        for(int i = 0; i < count; i++) {
            ret += implement(r.readLine());
        }

        System.out.println(ret);
    }
}