package strings;

import java.util.Scanner;


//	�ð����⵵: O(n^2)
//	�������⵵: O(n)
//  ����: ���ڰ� �ߺ����� ������ �� String������ ���ϰ�, �ߺ��Ǹ� 2��° ���� ���ڸ� �˻���
//       StringBuilder �Ǵ� StringBuffer �̿��� �ߺ����ڸ� delete�ϴ� ����� �ð��� �� �پ�� �� ����. 
public class SuperReduced {
	static String super_reduced_string(String s){
		String reduced="";
		int p=0;
		while(p<s.length()){
			if(p==s.length()-1||s.charAt(p)!=s.charAt(p+1)) {
				reduced+=Character.toString(s.charAt(p++));
			}else {
				p+=2;
			}
		}		
		return reduced;
    }

    public static void main(String[] args) {
    	Scanner in = new Scanner(System.in);
        String s = in.next();
         while(true) {
        	String reduced=super_reduced_string(s);
        	if(!s.equals(reduced)) s=reduced;
        	else break;
        }           
        if(s=="") s="Empty String";
        System.out.println(s);
        in.close();
    }
}
