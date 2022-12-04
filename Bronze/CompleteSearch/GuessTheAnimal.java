import java.io.*;
import java.util.*;

public class GuessTheAnimal {

    public static int animalGuesser(List<List<String>> strList) {
        int count = 0;
        for(int i = 0; i < strList.size(); i++) {
            for(int j = 0; j < strList.size(); j++) {
                if(i==j) continue;
                if(strList.get(i).size()<strList.get(j).size()) continue;
                
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(r.readLine());
        List<List<String>> strList = new ArrayList<List<String>>();

        for(int i = 0; i < count; i++) {
            String str = r.readLine();
            List<String> current = new ArrayList<String>();
            for(int j = 0; j < Integer.parseInt(str.split(" ")[1]); j++) {
                current.add(str.split(" ")[j+2]);
            }
        }
    }
}
