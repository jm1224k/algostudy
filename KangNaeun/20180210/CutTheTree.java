package search;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;


public class CutTheTree {
	
	static List<Integer>[] tree;		//�� vertex�� ����� vertex���
	static int[] data;					//�� vertex�� ��
	static PriorityQueue<Integer> pq;	//edge�� difference ����
	
	//cut ����Լ�
	static int cut(int from, int vertex, int sum){
		int s=data[vertex];
		for(int i=0;i<tree[vertex].size();i++) {			
			int to = tree[vertex].get(i);
			if(to==from) continue;
			s += cut(vertex, to, sum);
		}
		if(from==vertex) return 0; 
		int dif=Math.abs(sum-s*2);
		pq.add(dif);
		return s;
	}	
	
	
    @SuppressWarnings("unchecked")
	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        data = new int[n];
        pq = new PriorityQueue<>();
        int sum=0;
        for(int data_i = 0; data_i < n; data_i++){
            data[data_i] = in.nextInt();
            sum += data[data_i];
        }
        tree =(List<Integer>[]) new List[n];
        for(int vertex_i=0;vertex_i<n;vertex_i++) {
        	tree[vertex_i]=new ArrayList<Integer>();
        }
        for(int edge_i=0;edge_i<n-1;edge_i++) {
        	int vertex1=in.nextInt()-1;
        	int vertex2=in.nextInt()-1;
        	tree[vertex1].add(vertex2);
        	tree[vertex2].add(vertex1);
        }    
        
        //0���� cut ����
        cut(0, 0,sum);	
        //���� ���� ��
        System.out.println(pq.peek());
        in.close();
    }
}
