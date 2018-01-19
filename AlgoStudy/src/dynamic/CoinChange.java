package dynamic;

import java.util.Arrays;
import java.util.Scanner;

public class CoinChange {
	//�ð����⵵ : O(nm)
	//�������⵵ : O(nm)
	//d[i][j] : i��° �������� ����� j���� ����� ����� ��
	static long getWays(int n, int[] c){
        int size=c.length;
        Arrays.sort(c);
        long[][] d=new long[size+1][n+1];
        d[0][0]=1;
        for(int i=1;i<=size;i++) {
        	for(int j=0;j<=n;j++) {
        		d[i][j]=d[i-1][j];	//i��° ���� ������� ����
        		if(j-c[i-1]>=0) {
        			d[i][j] += d[i][j-c[i-1]];	//i��° ���� ���
        		}
        	}
        }
        return d[size][n];
    }
/*
 * ���� 2������ 1�������� ����  
 * static long getWays(int n, int[] c){
        int size=c.length;
        Arrays.sort(c);
        long[] d=new long[n+1];
        d[0]=1;
        for(int i=1;i<=size;i++) {
        	for(int j=0;j<=n;j++) {
        		if(j-c[i-1]>=0) {
        			d[j] += d[j-c[i-1]];	//i��° ���� ���
        		}
        	}
        }
        return d[size][n];
    }
 * 
 * */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] c = new int[m];
        for(int c_i=0; c_i < m; c_i++){
            c[c_i] = in.nextInt();
        }
        // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
        long ways = getWays(n, c);
        System.out.println(ways);
    }
}
