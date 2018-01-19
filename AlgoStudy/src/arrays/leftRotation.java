package arrays;

import java.util.Scanner;

public class leftRotation {
	//�ð����⵵ : O(n)
	//�������⵵ : O(n)
	//���ο� �迭�� rotate�� ��ŭ �մ�� �����ϰ� �� ���� ������ �ڿ� ����
	static int[] LR(int[] a, int d) {
		int size = a.length;
        int[] r=new int[size];
        for(int i=0;i<d;i++) {
        	r[size-d+i]=a[i];
        }
        for(int i=d;i<size;i++) {
        	r[i-d]=a[i];
        }
		return r;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int d = in.nextInt();
        int[] a = new int[n];
        for(int a_i = 0; a_i < n; a_i++){
            a[a_i] = in.nextInt();
        }
        int[] result = LR(a, d);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + (i != result.length - 1 ? " " : ""));
        }
        System.out.println("");


        in.close();
    }
}
