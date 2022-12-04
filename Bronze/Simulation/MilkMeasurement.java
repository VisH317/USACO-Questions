import java.io.*;
import java.util.*;

public class MilkMeasurement {

    public static int milkMeasurement(String[] changes) {
        int count = 0;
        int max = 7;
        HashMap<String, Integer> cows = new HashMap<String, Integer>();
        HashSet<Integer> days = new HashSet<Integer>();
        for(String element : changes) days.add(Integer.parseInt(element.split(" ")[0]));
        List<Integer> daysList = new ArrayList<Integer>(days);
        List<String> leadCows = new ArrayList<String>();
        Collections.sort(daysList);

        for(int i = 0; i < daysList.size(); i++) {
            for(String element : changes) {
                if(Integer.parseInt(element.split(" ")[0])==daysList.get(i)) {
                    int key = cows.get(element.split(" ")[1]) != null ? cows.get(element.split(" ")[1]) : 7;
                    int value = element.split(" ")[2].split("")[0].equals("+") ? Integer.parseInt(element.split(" ")[2].split("")[1]) : 
                        -1*Integer.parseInt(element.split(" ")[2].split("")[1]);
                    cows.put(element.split(" ")[1], key+value);
                }
            }

            boolean addedCount = false;

            for(String element : cows.keySet()) {
                if(leadCows.contains(element)==false && cows.get(element)>= max) {
                    if(addedCount==false) {
                        addedCount = true;
                        count++;
                    }
                    max = cows.get(element);
                    leadCows.add(element);
                } else if(leadCows.contains(element)==true && cows.get(element) < max) {
                    if(addedCount==false) {
                        addedCount = true;
                        count++;
                    }
                    max = Collections.max(cows.values());
                    leadCows.remove(element);
                }
            }
        }

        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(r.readLine());
        String[] changes = new String[count];
        for(int i = 0; i < count; i++) {
            changes[i] = r.readLine();
        }

        System.out.println(milkMeasurement(changes));
    }
}

// for(int i = 0; i < 100; i++) {
//     for(String element : changes) {
//         if(i==Integer.parseInt(element.split(" ")[0])) {
//             int key = cows.get(element.split(" ")[1]);
//             int value = Integer.parseInt(element.split(" ")[2].split("")[1]);
//             cows.put(element.split(" ")[1], element.split(" ")[2].split("")[0]=="-" ? key-value : key+value)
//         }
//     }
// }
