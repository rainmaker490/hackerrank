//@author: Varun Patel
//Extra Long Factorials
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int n = reader.nextInt();
        
        BigInteger nBig = new BigInteger("1");
        for (int i = 2; i <= n; i++){
            nBig = nBig.multiply(BigInteger.valueOf(i));
        }
        System.out.println(nBig);
    }
}
