package hyundae;

import java.util.*;
import java.io.*;



public class Main
{

    private Map<String, List<Integer>> relation = new HashMap<String, List<Integer>>();

    public static void main(String args[]) throws Exception {
            Main main = new Main();
            main.process();
    }

    private void process() throws Exception {
            int result = 0;

            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String[] nm = br.readLine().split(" ");


            String [] weight = br.readLine().split(" ");
            
            for(int i = 0; i < Integer.parseInt(nm[1]); i++) {
                String[] ab = br.readLine().split(" ");

                // a
                if(relation.containsKey(ab[0])) {
                	// 이미 들어가있다면
                	List<Integer> tmpList = relation.get(ab[0]);
                	tmpList.add(Integer.parseInt(ab[1]));
                	relation.put(ab[0], tmpList);
                }
                else {
                	List<Integer> tmpList = new ArrayList<Integer>();
                	tmpList.add(Integer.parseInt(ab[1]));
                	relation.put(ab[0], tmpList);
                }
                
                // b
                if(relation.containsKey(ab[1])) {
                	// 이미 들어가있다면
                	List<Integer> tmpList = relation.get(ab[1]);
                	tmpList.add(Integer.parseInt(ab[0]));
                	relation.put(ab[1], tmpList);
                }
                else {
                	List<Integer> tmpList = new ArrayList<Integer>();
                	tmpList.add(Integer.parseInt(ab[0]));
                	relation.put(ab[1], tmpList);
                }
                // 양쪽 모두 넣어줘야 한다.
            }
            
            for(String key : relation.keySet()) {
            	//System.out.println("key : " + key);
            	boolean flag = false;
            	boolean change = false;
            	List<Integer> friend = relation.get(key);
            	
            	//System.out.println("friends size : " + friend.size());
            	if(friend.size() == 0) {
            		continue;
            	}
            	
            	for(int idx = 0; idx < friend.size(); idx++) {
            		int w = Integer.parseInt(weight[friend.get(idx)-1]);
            		int kw = Integer.parseInt(weight[Integer.parseInt(key)-1]);
            		
            		//System.out.println("w : " + w + " | key weight : " + Integer.parseInt(weight[Integer.parseInt(key)-1]));
            		
            		if(w > kw) {
            			flag = true;
            		}
            		else if(w < kw) {
            			change = true;
            		}
            	}
            	
            	if(!flag && change) {
            		//System.out.println("flag is false, result ++");
            		result++;
            	}
            } 


            System.out.println(result);
    }
}