package stack;

import java.util.Scanner;
import java.util.Stack;

public class LargestRectangle {
	 static long largestRectangle(int[] h) {
	        Stack<Integer> s=new Stack<>();
	        long max=0;
	        /* h.length==n+1
	         * h[n]==0
	         * s���� h�� 0 ~ i �� ���� ���̰� ���� ��ȣ���� i��° ���� ���̰� ���ų� ���� ��ȣ�� ��ȣ����� �����.
	         */
	        for(int i=0;i<h.length;i++) {
	        	while(!s.isEmpty()) {
	        		if(h[s.peek()]<=h[i]) break;
	        		int k=s.pop();
	        		int left=-1;
	        		if(!s.isEmpty()) {
	        			left=s.peek();
	        			if(h[k]==h[left]) continue;
	        		}
	        		long temp=h[k]*(i-left-1);
	        		if(temp>max) max=temp;
	        		System.out.println(k+" "+max);
	        	}
	        	s.add(i);
	        }
	        
	        return max;
	    }

	    public static void main(String[] args) {
	        Scanner in = new Scanner(System.in);
	        int n = in.nextInt();
	        int[] h = new int[n+1];
	        for(int h_i = 0; h_i < n; h_i++){
	            h[h_i] = in.nextInt();
	        }
	        long result = largestRectangle(h);
	        System.out.println(result);
	        in.close();
	    }
}
