import java.io.*;
import java.util.*;

public class CowGymnastics {

    public static int pairs(String[] ranks) {
        int count = 0;
        for(int i = 1; i <= ranks[0].length(); i++) {
            List<String> below = Arrays.asList(Arrays.copyOfRange(ranks[0].split(""), ranks[0].indexOf(Integer.toString(i))+1, ranks[0].length()));
            // for(String element : below) System.out.println(element);
            for(int j = 1; j < ranks.length; j++) {
                List<Integer> toRemove = new ArrayList<Integer>();
                for (int k = 0; k < below.size(); k++) {
                    if(Arrays.asList(Arrays.copyOfRange(ranks[j].split(""), ranks[j].indexOf(Integer.toString(i)), ranks[j].length()-1)).contains(below.get(k))==false) {
                        toRemove.add(k);
                    }
                }
                for(int element : toRemove) below.remove(element);
            }
            for(String element : below) System.out.println(element);
            System.out.println("\n");
            count += below.size();
        }

        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        String[] kn = r.readLine().split(" ");
        String[] ranks = new String[Integer.parseInt(kn[0])];
        for(int i = 0; i < Integer.parseInt(kn[0]); i++) ranks[i] = r.readLine().replace(" ", "");

        System.out.println(pairs(ranks));
    }
}

//Arrays.copyOfRange(ranks[j].split(""), ranks[j].indexOf(Integer.toString(i)), ranks[j].length()-1)