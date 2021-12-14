import java.util.Scanner;

public class Main {
	public static int[] ZamanCevir(int data) {
		int sonuc[] = new int [3];
		int saniye = data%60;
		int dakika = data/60;
		int saat=dakika/60;
		dakika=dakika%60;
		saat=saat%24;
		
		sonuc[0]=saat;
		sonuc[1]=dakika;
		sonuc[2]=saniye;
		return sonuc;
	}

	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		
		System.out.printf("Saniye : ");
		int süre=inp.nextInt();
		int [] zaman = new int [3];
		zaman = ZamanCevir(süre);
		System.out.printf("Saat : %d Dakika : %d Saniye : %d",zaman[0],zaman[1],zaman[2]);

	}
}
