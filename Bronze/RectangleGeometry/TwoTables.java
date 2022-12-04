import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class TwoTables {

    public int findChange(int[] table, int[] size, int[] room) {
        if((size[0]+(table[2]-table[0]) > room[0]) && (size[1]+(table[3]-table[1])>room[1])) return -1;
        int up = room[1] - table[3] >= table[1] ? room[1]-table[3] : table[1];
        int right = room[0] - table[2] >= table[0] ? room[0]-table[2] : table[0];
        int vertVal = size[1]+(table[3]-table[1])>room[1] ? -1 : size[1]-up;
        int horizVal = size[0]+(table[2]-table[0])>room[0] ? -1 : size[0]-right;

        return vertVal >= horizVal ? vertVal : horizVal;

    }

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        
    }
}
