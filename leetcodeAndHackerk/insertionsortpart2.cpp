import java.io.*;
import java.util.*;

public class Solution {

    public static void insertionSortPart2(int[] ar)
    {       
           // Fill up the code for the required logic here
           // Manipulate the array as required
           // The code for Input/Output is already provided
        
        int s = 0;
		for (int x : ar)
			if (x != 0)
				s++;
		int to_sort = ar[s - 1];
		int i = 0;
		for(int j=1;j<=s-1;j++){
        to_sort=ar[j];
        for (i = j-1; i >= 0 && ar[i]> to_sort; i--)
			ar[i + 1] = ar[i];
		ar[i + 1] = to_sort;
		printArray(ar);
        }
        
    }  
    
    public static void insertIntoSorted(int[] ar) {
		int s = 0;
		for (int x : ar)
			if (x != 0)
				s++;
		int to_sort = ar[s - 1];
		int i = 0;
		for (i = s - 2; i >= 0 && ar[i] > to_sort; i--) {

			ar[i + 1] = ar[i];
			printArray(ar);
		}
		ar[i + 1] = to_sort;
		printArray(ar);
	}
      
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
       int s = in.nextInt();
       int[] ar = new int[s];
       for(int i=0;i<s;i++){
            ar[i]=in.nextInt(); 
       }
       insertionSortPart2(ar);    
                    
    }    
    private static void printArray(int[] ar) {
      for(int n: ar){
         System.out.print(n+" ");
      }
        System.out.println("");
   }
}

