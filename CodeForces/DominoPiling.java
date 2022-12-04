import java.io.*;

public class DominoPiling {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        String[] dims = r.readLine().split(" ");
        System.out.println((int)Math.floor((Integer.parseInt(dims[0])*Integer.parseInt(dims[1]))/2));
    }
}
