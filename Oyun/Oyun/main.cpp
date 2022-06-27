#include"glew.h"
#include"freeglut.h"
#include<iostream>
#include<sstream>  
using namespace std;

struct dusman {
	int id, x1, y1;
	struct dusman* link;
};


struct dusman* hayattaki_dusmanlar_liste = NULL;
struct dusman* yildizlar_liste = NULL;

int karekter_hareket_x = 0;
int mermi_y = 0;
int istenen_dusman_sayisi = 10;
int istenenden_kalan_dusman_sayisi = istenen_dusman_sayisi;
int olusan_dusmanlar = 0;
int son_id = -1;
int oyun_durumu = 0;
int dusman_hizi=30;
int level = 1;
int dondur_x=0;
int yildiz_sayisi = 5;
int yildiz_son_id = -1;
int olusan_yildizlar=0;
int yildiz_hizi = 10;
int yildiz_kaydir_hiz = 50;
string text;
string kalan_dusman_adedi;
string level_text;

void dusman_ekle(struct dusman** x, int* id, int x1, int y1) {
	struct dusman* yeni_dusman = new dusman;
	struct dusman* son = *x;
	yeni_dusman->id = ((int)*id) + 1;
	*id = *id + 1;
	yeni_dusman->x1 = x1;
	yeni_dusman->y1 = y1;
	yeni_dusman->link = NULL;
	if (*x == NULL) {
		*x = yeni_dusman;
	}
	else {
		while (son->link != NULL)
		{
			son = son->link;
		}
		son->link = yeni_dusman;
	}


}
void dusman_sil(struct dusman** x, int id) {
	//kok degistir
	if ((*x) != NULL) {
		if ((*x)->id == id) {
			struct dusman* silinecek = (*x);
			(*x) = (*x)->link;
			free(silinecek);
			return;
		}
		struct dusman* iter = (*x);
		if (iter->link != NULL) {
			while (iter->link->link != NULL && iter->link->id != id) {
				iter = iter->link;
			}
			if (iter->link->id == id) {
				struct dusman* silinecek = iter->link;
				iter->link = silinecek->link;
				free(silinecek);
			}
		}

	}

}
void dusmanlari_lislete(struct dusman* x) {
	while (x != NULL)
	{
		cout << "id : " << x->id << " x: " << x->x1 << " y: " << x->y1 << endl;
		x = x->link;
	}
}
void dusman_deger_degistir(struct dusman* x, int id,  int y1) {
	while (x != NULL)
	{
		if (x->id == id) {
			x->y1 = y1;
		}
		x = x->link;
	}
}
struct dusman* dusman_deger_dondur(struct dusman* x, int id) {
	struct dusman* istenen_dusman = NULL;
	while (x != NULL)
	{
		if (x->id == id) {
			istenen_dusman = (struct dusman*)malloc(sizeof(struct dusman));
			istenen_dusman->id = x->id;
			istenen_dusman->x1 = x->x1;
			istenen_dusman->y1 = x->y1;
			istenen_dusman->link = x->link;
			break;
		}
		x = x->link;
	}
	return istenen_dusman;
}
int dusman_sayisi(struct dusman* x) {
	int sayac = 0;
	while (x != NULL)
	{
		sayac = sayac + 1;
		x = x->link;
	}
	return sayac;
}
void yaz(const char* text, int lenght,float r,float g ,float b, int x, int y,int font) {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, 600, 0, 600, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(r,g,b);
	glRasterPos2i(x, y);
	for (int i = 0; i < lenght; i++)
		if (font == 0) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int)text[i]);
		}
		else if (font == 1) {
			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, (int)text[i]);
		}
		
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
void display(void) {
	if (oyun_durumu == 1) {
		text = "KAZANDIN";

		yaz(text.data(), text.size(), 0, 1, 0, 250, 300,0);
		glFlush();
		glutPostRedisplay();//pencerenin  normal düzlemi yeniden görüntülemesi için ekran geri çaðýrýcýsýný gerçekleþtirir
		glutSwapBuffers();
	}
	if (oyun_durumu == -1) {
		text = "KAYBETTIN";
		yaz(text.data(), text.size(), 1, 0, 0, 250, 300,0);
		glFlush();
		glutPostRedisplay();//pencerenin  normal düzlemi yeniden görüntülemesi için ekran geri çaðýrýcýsýný gerçekleþtirir
		glutSwapBuffers();
	}
	if (oyun_durumu == 0) {
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(5.0f);
		//	YILDIZ 
		struct dusman* temp_yildiz = yildizlar_liste;
		while (temp_yildiz != NULL)
		{
			int x1 = temp_yildiz->x1;
			int y1 = temp_yildiz->y1;
			glBegin(GL_TRIANGLES);
				glColor3f(1, 1, 1);
				glVertex2f(x1,y1);				//	x1		,		y1
				glVertex2f(x1+14,y1);			//	x1+14	,		y1
				glVertex2f(x1+7, y1+12);		//	x1+7	,		y1+12

				glVertex2f(x1+7, y1-4);			//	x1+7	,		y1-4
				glVertex2f(x1+14, y1+7);		//	x1+14	,		y1+7
				glVertex2f(x1, y1+7);			//	x1		,		y1+7
			glEnd();
			temp_yildiz = temp_yildiz->link;
		}


		
		//	YILDIZ BITTI

		//	Karakter
		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 0.2);
		glVertex2f(275 + karekter_hareket_x, 20);
		glVertex2f(325 + karekter_hareket_x, 20);
		glVertex2f(325 + karekter_hareket_x, 30);
		glVertex2f(275 + karekter_hareket_x, 30);
		glEnd();

		glBegin(GL_TRIANGLES);
		glVertex2f(290 + karekter_hareket_x, 30);
		glVertex2f(310 + karekter_hareket_x, 30);
		glVertex2f(300 + karekter_hareket_x, 55.98);	//	NAMLU
		glEnd();
		//	KAREKTER BÝTTÝ

		//	KORUNACAK BOLGE					
		glBegin(GL_QUADS);
			glColor3f(0.0, 1.0, 0.0);
			glVertex2f(0, 0);
			glVertex2f(600, 0);			
			glVertex2f(600, 20);
			glVertex2f(0, 20);
		glEnd();
		//	KORUNACAK BOLGE BITTI		

		//	YAMUK KARE
		glPushMatrix();								//	SINIR BASLANGICI
		glRotatef(dondur_x%360, 300, 10.0, 0.0);
		
		glBegin(GL_QUADS);
			glColor3f(1,0.5,0);
			glVertex3f(290, 10,0);
			glVertex3f(300, 0,0);
			glVertex3f(310, 10,0);
			glVertex3f(300, 20,0);
		glEnd();

		glPopMatrix();								//	SINIR BITISI
		
		//	YAMUK KARE BITIS

		//	MERMI
		glBegin(GL_QUADS);
		glColor3f(1, 0.4, 1);
			glVertex2f(295 + karekter_hareket_x, 45.98 + mermi_y); //sol alt
			glVertex2f(305 + karekter_hareket_x, 45.98 + mermi_y); //sag alt
			glVertex2f(305 + karekter_hareket_x, 55.98 + mermi_y); //sag ust
			glVertex2f(295 + karekter_hareket_x, 55.98 + mermi_y); //sol ust
		glEnd();
		//	MERMI BITTI

		//	DUSMANLARI CIZ
		struct dusman* temp = hayattaki_dusmanlar_liste;
		while (temp != NULL)
		{
			int sol_alt_x = temp->x1;
			int sol_alt_y = temp->y1;
			if (295 + karekter_hareket_x >= sol_alt_x && 295 + karekter_hareket_x <= sol_alt_x + 30 && 45.98 + mermi_y >= sol_alt_y && 45.98 + mermi_y <= sol_alt_y + 30) {
				dusman_sil(&hayattaki_dusmanlar_liste, temp->id);
				istenenden_kalan_dusman_sayisi = istenenden_kalan_dusman_sayisi - 1;
				mermi_y = 0;
				break;
			}

			/*
			* if (295 + karekter_hareket_x >= sol_alt_x && 295 + karekter_hareket_x <= sol_alt_x + 30 && 45.98 + mermi_y >= sol_alt_y && 45.98 + mermi_y <= sol_alt_y + 30) {
				dusman_sil(&hayattaki_dusmanlar_liste, temp->id);
				mermi_y = 0;
				break;
			}

			*/
			
			glBegin(GL_QUADS);
			glColor3f(1, 0, 0);
			glVertex2f(sol_alt_x, sol_alt_y);
			glVertex2f(sol_alt_x + 30, sol_alt_y);
			glVertex2f(sol_alt_x + 30, sol_alt_y + 30);
			glVertex2f(sol_alt_x, sol_alt_y + 30);
			glEnd();
	
			temp = temp->link;
		}
		//	DUSMANLARI CIZ BITTI
		
		//	YAZ
		kalan_dusman_adedi = "Kalan Dusman : " ;
		level_text = "Level : ";
		int dusman_adedi = istenenden_kalan_dusman_sayisi;
		stringstream ss;
		ss << dusman_adedi;
		string n;
		ss >> n;
		ss.clear();
		kalan_dusman_adedi = kalan_dusman_adedi.append(n);
		ss << level;
		ss >> n;
		level_text = level_text.append(n);
		yaz(kalan_dusman_adedi.data(), kalan_dusman_adedi.size(), 0, 0, 1, 440, 570,1);
		yaz(level_text.data(), level_text.size(), 0, 0, 1, 440, 550, 1);
		//	YAZ BITTI
		
		glFlush();
		glutPostRedisplay();//pencerenin  normal düzlemi yeniden görüntülemesi için ekran geri çaðýrýcýsýný gerçekleþtirir
		glutSwapBuffers();
	}	
}

//	TEKRARLANACAK FONKSIYONLAR 
void ates_et(int x) {
	if (mermi_y > 625) {
		mermi_y = 0;
	}	
	mermi_y = mermi_y + 25;
	glutPostRedisplay();
	glutTimerFunc(15, ates_et, 0);
}
void dusman_olustur(int x) {
	if (olusan_dusmanlar < istenen_dusman_sayisi) {
		int x = 30 + rand() % 540;
		dusman_ekle(&hayattaki_dusmanlar_liste, &son_id, x, 640);
		olusan_dusmanlar = olusan_dusmanlar + 1;
	}

	glutPostRedisplay();
	glutTimerFunc(1000, dusman_olustur, 0);
}
void dusmanlari_hareket_ettir(int x) {
	if (oyun_durumu == 0) {
		if (dusman_sayisi(hayattaki_dusmanlar_liste)) {
			struct dusman* temp = hayattaki_dusmanlar_liste;
			while (temp != NULL)
			{

				if (temp->y1 <= 20) {
					oyun_durumu = -1;
					yildiz_kaydir_hiz = 50;
					level = 1;
				}


				temp->y1 = (temp->y1) - dusman_hizi;
				temp = temp->link;
			}
		}
		else {
			oyun_durumu = 1;
			yildiz_kaydir_hiz = yildiz_kaydir_hiz * 0.80;
			level = level + 1;
		}

		
	}
	glutPostRedisplay();
	glutTimerFunc(1000, dusmanlari_hareket_ettir, 0);
	
}
void kareyi_dondur(int x) {
	dondur_x = dondur_x + 1;
	glutPostRedisplay();
	glutTimerFunc(15, kareyi_dondur, 0);
}
void yildizlari_olustur(int x) {
	if (olusan_yildizlar < yildiz_sayisi) {
		int x = rand() % 586;
		int y = rand() % 100;
		dusman_ekle(&yildizlar_liste, &yildiz_son_id, x, -y);
		olusan_yildizlar = olusan_yildizlar + 1;
	}
	glutPostRedisplay();
	glutTimerFunc(500, yildizlari_olustur, 0);
}
void yildizlari_kaydir(int x) {
	if (oyun_durumu == 0) {
		struct dusman* temp = yildizlar_liste;
		while (temp != NULL)
		{
			if (temp->y1 >= 600) {

				temp->y1 = -(rand() % 150);
			}
			temp->y1 = (temp->y1) + yildiz_hizi;
			temp = temp->link;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(yildiz_kaydir_hiz, yildizlari_kaydir, 0);
}
//	TEKRARLANACAK FONKSIYONLAR BITI

void SpecialKey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT: // SOL OK
		if (karekter_hareket_x > -270) {
			karekter_hareket_x = karekter_hareket_x - 10;
		}		
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT: //	SAG OK
		if(karekter_hareket_x<270){
			karekter_hareket_x = karekter_hareket_x + 10;
		}
		
		glutPostRedisplay();
		break;
	}
}
void klavye_tuslari(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // ESC
		exit(0);
		break;
	case 32: // Space 
		if (oyun_durumu == 1) {
			istenen_dusman_sayisi =istenen_dusman_sayisi*1.35;
			dusman_hizi = dusman_hizi * 1.35;
			istenenden_kalan_dusman_sayisi = istenen_dusman_sayisi;
			oyun_durumu = 0;
			son_id = 0;
			olusan_dusmanlar = 0;
		}
		if (oyun_durumu == -1) {
			istenen_dusman_sayisi = 10;
			dusman_hizi = 30;
			istenenden_kalan_dusman_sayisi = istenen_dusman_sayisi;
			hayattaki_dusmanlar_liste = NULL;
			oyun_durumu = 0;
			son_id = 0;
			olusan_dusmanlar = 0;
		}
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Oyun");
	glClearColor(0.0, 0.0, 0.0, 1.0);	//ARKA PLAN RENGI

	glPointSize(5.0f);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
	
	glutDisplayFunc(display);
	glutSpecialFunc(SpecialKey);
	glutKeyboardFunc(klavye_tuslari);
	glutTimerFunc(0, ates_et, 0);
	glutTimerFunc(0, dusman_olustur, 0);
	glutTimerFunc(0, dusmanlari_hareket_ettir, 0);
	glutTimerFunc(0, kareyi_dondur, 0);
	glutTimerFunc(0, yildizlari_olustur, 0);
	glutTimerFunc(0, yildizlari_kaydir, 0);

	glutMainLoop();
	return EXIT_SUCCESS;
}