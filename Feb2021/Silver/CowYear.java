
//package random;

import java.io.*;
import java.util.*;

class CowYear {

	public static void main(String[] args) throws IOException {

		CowYear obj = new CowYear();

		obj.doStuff();

	}

	int nums, reps;
	int[] allnums;
	int maxlength;
	int[] dists;
	private void doStuff() throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		nums = Integer.parseInt(st.nextToken());
		reps = Integer.parseInt(st.nextToken());
		allnums = new int[nums+2];
		int max = 0;
		for (int i = 0; i < nums; i++) {
			allnums[i] = Integer.parseInt(br.readLine());
			max = Math.max(max, allnums[i]);
		}
		allnums[nums] = max+(max%12==0?0:(12-(max%12)));
		br.close();

		Arrays.sort(allnums);
		maxlength = allnums[allnums.length-1];
		dists = new int[allnums.length-1];
		for (int i = 0; i < dists.length; i++) {
			int top = allnums[i+1] - (allnums[i+1]%12);
			int bot = allnums[i]+(allnums[i]%12==0?0:(12-(allnums[i]%12)));
			dists[i] = Math.max(0, top-bot);
		}
		
		Arrays.sort(dists);
		for (int i = 0; i < reps-1; i++) {
			maxlength -= dists[dists.length-1-i];
		}
		System.out.println(maxlength);

	}

}