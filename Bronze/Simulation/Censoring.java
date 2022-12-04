import java.io.*;
import java.util.*;

public class Censoring {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

        String textOg = r.readLine();
        List<String> text = new ArrayList<>(Arrays.asList(textOg.split("")));
        String word = r.readLine();

        while(textOg.contains(word)) {
            int index = textOg.indexOf(word);
            for(int i = 0; i < word.length(); i++) {
                text.remove(index);
            }
            textOg = String.join("", Arrays.copyOf(text.toArray(), text.size(), String[].class));
        }

        System.out.println(String.join("", Arrays.copyOf(text.toArray(), text.size(), String[].class)));
    }
}