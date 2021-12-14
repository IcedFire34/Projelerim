import java.util.Random;

class Avatar{
	private String tur;
	private int guc;
	
	public String Get_Tur() {return tur;}
	public int Get_Guc() {return guc;}
	
	public Avatar(String x,int y) {
		tur=x;
		guc=y;
	}

}
class Oyuncu{
	Avatar[] kartlar;
	int puan=0;
}
class Avatar_Uret{
	private String tur []= {"Çiftçi","Savaşçı"};
	public Avatar[] uret(int adet) {
		Avatar [] deste = new Avatar[adet];
		Random rnd = new Random();
		for (int i =0;i<adet;i++) {
			int guc_deger= 1+rnd.nextInt(10);
			int tur_deger = rnd.nextInt(2);
			Avatar avtr = new Avatar(tur[tur_deger],guc_deger);
			deste[i]=avtr;
		}
		return deste;
	}	
}

public class Main {
	public static void main(String[] args) {	
		Avatar_Uret urt = new Avatar_Uret();
		Oyuncu o1 = new Oyuncu();
		Oyuncu o2 = new Oyuncu();
		
		o1.kartlar=urt.uret(5);
		o2.kartlar=urt.uret(5);
		
		for(int i=0;i<o1.kartlar.length;i++) {
			System.out.println("Oyuncu 1 : "+o1.kartlar[i].Get_Tur() + " " + o1.kartlar[i].Get_Guc() + " Oyuncu 2 : "+o2.kartlar[i].Get_Tur() + " " + o2.kartlar[i].Get_Guc());
			if(o1.kartlar[i].Get_Tur()=="Savaşçı" && o2.kartlar[i].Get_Tur()=="Çiftçi") {
				o1.puan=o1.puan+10;
				System.out.println("1.Oyuncu 10 puan aldı !");
			}
			else if(o2.kartlar[i].Get_Tur()=="Savaşçı" && o1.kartlar[i].Get_Tur()=="Çiftçi") {
				o2.puan=o2.puan+10;
				System.out.println("2.Oyuncu 10 puan aldı !");
			}
			else{
				if(o1.kartlar[i].Get_Guc() >o2.kartlar[i].Get_Guc()) {
					o1.puan=o1.puan+(o1.kartlar[i].Get_Guc()-o2.kartlar[i].Get_Guc());
					System.out.println("1.Oyuncu " + (o1.kartlar[i].Get_Guc()-o2.kartlar[i].Get_Guc()) + " puan aldı !");
				}
				else if(o1.kartlar[i].Get_Guc() < o2.kartlar[i].Get_Guc()){
					o2.puan=o2.puan+(o2.kartlar[i].Get_Guc()-o1.kartlar[i].Get_Guc());
					System.out.println("2.Oyuncu " + (o2.kartlar[i].Get_Guc()-o1.kartlar[i].Get_Guc()) + " puan aldı !");					
				}else {
					System.out.println("Kartlar birbirine denk BERABERE");
				}
			}
		}
		System.out.println("Oyuncu 1 : "+ o1.puan + " puan Oyuncu 2 : " + o2.puan + "puan aldı.");
		if(o1.puan>o2.puan) {
			System.out.println("Oyuncu 1 kazandı !");
		}else if(o1.puan<o2.puan) {
			System.out.println("Oyuncu 2 kazandı !");
		}else {
			System.out.println("BERABERE !");
		}
	}
}


