package dynamic;

import java.util.Scanner;
import java.util.ArrayList;


/*
 * �ð����⵵ : O(n)
 * 
 * ������ ���� ���� �� ���� ���θ� �� �� �̵��� �ִ밡 �ȴ�.
 * 
 * max : �̵��� �ִ�  
 * sell: (�ڿ��� ���� )���� ���� ����
 * 
 * prices�� �ڿ��� ���� Ȯ���ϸ� sell ������ ������ ���� ��� sell���� �����ϰ�,
 * ���� ���� continue;
 * ���� ��쿡 sell���� �ش� ������ ���� max�� ���Ѵ�.
 * 
 */

public class StockMaximize {
	
	static long stockmax(int[] prices) {   
	 	int l = prices.length;
	 	long max=0;
		int sell=0;
        for(int i=l-1;i>=0;i--) {
        	if(sell<prices[i]) {
        		sell = prices[i];
        	}else if(sell>prices[i]) {
        		max += sell - prices[i];
        	}
        }
        return max; 	
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int[] prices = new int[n];
            for(int prices_i = 0; prices_i < n; prices_i++){
                prices[prices_i] = in.nextInt();
            }
            System.out.println(stockmax(prices));
        }
        in.close();
    }
}
