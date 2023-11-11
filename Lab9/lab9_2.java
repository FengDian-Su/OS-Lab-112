class Hello1 extends Thread{
	String name;
	public Hello1(String n){
		name=n;
	}
	
	public void run(){
		for(int i=1; i<=10; i++){
			System.out.println(name+"Hello"+i);
		}
	}
}

class Hello2 implements Runnable{
	String name;
	public Hello2(String n){
		name=n;
	}
	
	public void run(){
		for(int i=1; i<=10; i++){
			System.out.println(name+"Hello"+i);
		}
	}
}

class add implements Runnable {
	int sum = 0;
	public void run() {
		for (int i = 1; i <= 10; i++) {
			sum += 1;
		}
		printThread h1 = new printThread(sum);
		Thread t_print = new Thread(h1);
		t_print.start();
		
		try {
			t_print.join();
		} catch (InterruptedException ie) {
			System.err.println(ie);
		}
	
		System.out.println("exit add thread");
	}
}

class printThread implements Runnable {
	int sum = 0;
	public printThread(int num) {
		sum = num;
	}
	public void run() {
		for (int i = 1; i <= 10; i++) {
			sum += 1;
		}
		System.out.println("First print sum:" + sum);
	}
}
	
public class lab9_2 {
	public static void main(String argv[]) {
		add t = new add();
		Thread t_add = new Thread(t);
		t_add.start();
	}
}
