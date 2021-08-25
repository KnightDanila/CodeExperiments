/*
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <vector>

using namespace std;
*/
/*
class SeaWars
{
public:
	int Ships;

	SeaWars()
	{
		Ships = 10;
	}

	virtual ostream & operator << (ostream& out)=0;
};

class Player1 : public SeaWars
{
	public:
	int StillALive;
	Player1()
	{
		StillALive = 5;
	}

	ostream & operator << (ostream& out)
	{
		out<<"Игрок №1"<<endl;
		out<<"Кораблей Всего "<<Ships<<endl;
		out<<"Кораблей Осталось "<<StillALive<<endl;
		return out;
	}

};

class Player2 : public SeaWars
{
	public:
	int ShotShips;
	Player2()
	{
		ShotShips = 3;
	}
	ostream & operator << (ostream& out)
	{
		out<<"Игрок №2"<<endl;
		out<<"Кораблей Всего "<<Ships<<endl;
		out<<"Кораблей Утонуло "<<ShotShips<<endl;
		return out;
	}

};


	ostream & operator << (ostream & o , SeaWars& p)
	{
		o<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		p<<o;
		return o;
	}


int main()
{
	SetConsoleOutputCP(1251);
	SeaWars *P1 = new Player1();
	SeaWars *P2 = new Player2();
	(*P1)<<cout;
	(*P2)<<cout;
	
	cout<<endl<<endl<<endl<<endl;
	cout<<(*P1);
	cout<<(*P2);
	system("pause")
		/*
	printf("%d\n",0666);
	system("pause");
	return 0;*/
/*}*//*
typedef struct {
      WORD   bfType;         // 0x4d42 | 0x4349 | 0x5450
      int    bfSize;         // размер файла
      int    bfReserved;     // 0
      int    bfOffBits;      // смещение до поля данных,
                             // обычно 54 = 16 + biSize
      int    biSize;         // размер струкуры в байтах:
                             // 40(BITMAPINFOHEADER) или 108(BITMAPV4HEADER)
                             // или 124(BITMAPV5HEADER)
      int    biWidth;        // ширина в точках
      int    biHeight;       // высота в точках
      WORD   biPlanes;       // всегда должно быть 1
      WORD   biBitCount;     // 0 | 1 | 4 | 8 | 16 | 24 | 32
      int    biCompression;  // BI_RGB | BI_RLE8 | BI_RLE4 |
                             // BI_BITFIELDS | BI_JPEG | BI_PNG
                             // реально используется лишь BI_RGB
      int    biSizeImage;    // Количество байт в поле данных
                             // Обычно устанавливается в 0
      int    biXPelsPerMeter;// горизонтальное разрешение, точек на дюйм
      int    biYPelsPerMeter;// вертикальное разрешение, точек на дюйм
      int    biClrUsed;      // Количество используемых цветов
                             // (если есть таблица цветов)
      int    biClrImportant; // Количество существенных цветов.
                             // Можно считать, просто 0
}BMPheader;*/
/*
typedef struct
{
    unsigned int    bfType;
    unsigned long   bfSize;
    unsigned int    bfReserved1;
    unsigned int    bfReserved2;
    unsigned long   bfOffBits;
} BITMAPFILEHEADER;
 
typedef struct
{
    unsigned int    biSize;
    int             biWidth;
    int             biHeight;
    unsigned short  biPlanes;
    unsigned short  biBitCount;
    unsigned int    biCompression;
    unsigned int    biSizeImage;
    int             biXPelsPerMeter;
    int             biYPelsPerMeter;
    unsigned int    biClrUsed;
    unsigned int    biClrImportant;
} BITMAPINFOHEADER;
 
typedef struct
{
    int   rgbBlue;
    int   rgbGreen;
    int   rgbRed;
    int   rgbReserved;
} RGBQUAD;
 
 
static unsigned short read_u16(FILE *fp);
static unsigned int   read_u32(FILE *fp);
static int            read_s32(FILE *fp);
*//*
int main()
{
	vector<string> textMAS; 

//	FILE* in;
//	in = fopen("picture.bmp","rb");
//	char *a;
    int i;
    FILE* f = fopen("picture.bmp", "rb");
		FILE* out;
	out = fopen("OutFile.bmp","w");
    if(f == NULL)
        throw "Argument Exception";

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    cout << endl;
    cout << "  Name: " << "picture.bmp" << endl;
    cout << " Width: " << width << endl;
    cout << "Height: " << height << endl;

    int row_padded = (width*3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];
    unsigned char tmp;
	fread(data, sizeof(unsigned char), row_padded, f);

	//fprintf(out,"%s", data);
	//fprintf(out,"%s",mem);

	fwrite(info, sizeof(unsigned char), row_padded, out);
    for(int i = 0; i < height; i++)
    {
        fread(data, sizeof(unsigned char), row_padded, f);
		fwrite(data, sizeof(unsigned char), row_padded, out);


        for(int j = 0; j < width*3; j += 3)
        {
            // Convert (B, G, R) to (R, G, B)
            tmp = data[j];
            data[j] = data[j+2];
            data[j+2] = tmp;

            cout << "R: "<< (int)data[j] << " G: " << (int)data[j+1]<< " B: " << (int)data[j+2]<< endl;
        }
    }
		fclose(out);
    fclose(f);
	system("pause");}
    //return data;

	/*unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, in); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[32];
    int height = *(int*)&info[32];

    int size = 3 * width * height;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    fread(data, 1, size, in); // read the rest of the data at once*/
   // fclose(in);
	/*
    for(int i = 0; i < size; i += 3)
    {
            unsigned char tmp = data[i];
            data[i] = data[i+2];
            data[i+2] = tmp;
    }
	*/
	//string a;
	//cout<<*((*in)._ptr)<<endl;
	/*while(fscanf(in,"%",&a)!=EOF)
	{
		textMAS.push_back(a);
	}
	*//*
	BMPheader bh;    // File header sizeof(BMPheader) = 56
    size_t res;
    // читаем заголовок
    res = fread( &bh, 1, sizeof(BMPheader), in );

	fseek(in,0,SEEK_END);
	int file_size = ftell(in);
	fseek(in,0,SEEK_SET);
	//char head[10];
	//fread(head,1,10,in);
	//char * mem = (char*) malloc(sizeof( char ) *file_size);
	// Заголовок прочитан и проверен, тип - верный (BGR-24), размеры (mx,my) найдены
    int mx = bh.biWidth;
    int my = bh.biHeight;
    int mx3 = (3*mx+3) & (-4);    // Compute row width in file, including padding to 4-byte boundary
    unsigned char *tmp_buf = new unsigned  char[mx3*my];    // читаем данные
    res = fread( tmp_buf, 1, mx3*my, in);
	/*
	for(int i = 0; i <file_size; i++)
	{
	fread(&mem[i],1,1,in);
	}
	*/
//	fclose(in);
	/*
	ok, firstly you want to open the file in binary mode - by usinf "rb" instead of "r" in the fopen() 
	call, then you must use different I/O calls to read the data - fscanf is for reading ASCII data only
	fread() is probably the best one - to read a chunk of the file directly to a memory address
	Have you got info on the file format spec for BMP files? if not - I will post it for you...
	*/


/*
[20:21:26] john.constantine7775 john.constantine7775:  std::ifstream IS("in_char.txt");
 std::ofstream OS("out_char.txt");
 IS.unsetf(std::ios_base::skipws);
 istream_iterator<char> IT(IS), eos;
 ostream_iterator<char> OT(OS);
 for (; IT != eos; ++IT, ++OT) *OT = *IT;
 OS.close();
 IS.close();
[20:21:46] john.constantine7775 john.constantine7775: ifstream  - входной поток
[20:21:59] john.constantine7775 john.constantine7775: ofstream выход
[20:22:38] john.constantine7775 john.constantine7775: на 3 строке убираю флаг skipws (пробелы)
и еще:
[20:21] john.constantine7775 john.constantine7775: 

<<<  istream_iterator<char> IT(IS), eos;здесь объект IT принимает поток, а eos будет служить нам как указатель на конец файла
 IT != eosт.е цикл будет работать пока я полностью не перепишу из файла в файл
 здесь:
[20:21] john.constantine7775 john.constantine7775: 

<<<  ++IT, ++OTя перехожу к следующему символу
[20:27:45] john.constantine7775 john.constantine7775: а здесь:
[20:21] john.constantine7775 john.constantine7775: 

<<< *OT = *IT
[20:28:13] john.constantine7775 john.constantine7775: уже переписываю char из входного потока в выход
[20:28:34] john.constantine7775 john.constantine7775: и не забывай выходить из файла (rofl)
*/

//////////////////////////////////////////// FOR() cycle Expirement \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\++
/*
class a
{
	//void operator ( {}
};
int main()
{
	int i = 0;
	for(;i<5; i++){
		cout<<1<<endl;
		for(;;){continue;}
	}
	system("pause");
	return 0;
}
*/
/////////////////////////////////////// ANGLE SMILES
/*
#include <math.h>
#include <iostream>
#include <Windows.h>
//#include <stdio.h>
//#include <vector>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	double PI = atan((double)1)*4;

	cout<<"PI="<<PI<<endl;
	double angle = 0;
	cout<<endl;
	for(int checkPoint=0;angle<361;angle++)
	{
		cout<<"sin("<<angle<<")="<<sin(angle*PI/180.0)<<endl;
		cout<<"cos("<<angle<<")="<<cos(angle*PI/180.0)<<endl;
		//cout<<"sin("<<angle<<")="<<asin(sin(angle*PI/180.0))/PI*180.0<<endl;
		//cout<<"cos("<<angle<<")="<<acos(cos(angle*PI/180.0))/PI*180.0<<endl;
		if((angle == 90.0) || (angle == 180) || (angle == 270) || (angle == 360)){cout<<"Выведено с "<<checkPoint<<" до "<<angle<<endl;system("pause");checkPoint = angle;}
	}
	system("pause");
	return 0;
}
*/
// Число PI - в ANGLE SMILES является числом с конечной точностью, по этому оно и вычисляет sin и cos как число почти равные нулю sin(360)=-2.44929e-016=-2.44929*10^(-16) - типа близкое к 0
// Числа с правающей точкой Си - читать

///////////////////////////////// Find the angle in two line
/*
#include <math.h>
#include <iostream>
#include <Windows.h>
//#include <stdio.h>
//#include <vector>

using namespace std;
bool signbit(double x)
{
    return 1.0/x != 1.0/fabs(x);
}
int main()
{
	SetConsoleOutputCP(1251);
	double PI = atan((double)1)*4;

	cout<<"PI="<<PI<<endl;
	double angle = 0;
	cout<<endl;
	double OA[] = {-1,-1,0,		1};
	double OB[] = {-1,0,0,	1};
	double cosf;
	double XXX = OA[0] - OB[0]; 
	double YYY = OA[1] - OB[1];
	double ZZZ = OA[2] - OB[2];
	cosf = (		(OA[0]*OB[0]+OA[1]*OB[1]+OA[2]*OB[2])	/	( sqrt(OA[0]*OA[0]+OA[1]*OA[1]+OA[2]*OA[2]) * sqrt(OB[0]*OB[0]+OB[1]*OB[1]+OB[2]*OB[2]) )				);
	
	double aaa[] = {1,0};
	signbit(aaa[0]/aaa[1]);
	cout<<"Strang="<<ZZZ/XXX/YYY<<endl;
	if(!signbit(ZZZ/XXX/YYY)){
	cout<<"cosf="<<cosf<<endl;
	cout<<"f="<<acos(cosf)*180.0/PI<<endl;
	}
	else{
	cout<<"cosf="<<cosf<<endl;
	cout<<"f="<<360-acos(cosf)*180.0/PI<<endl;
	}

	system("pause");
	return 0;

}
*/

//Маленький прикол, только что нашел С++, кто сказал что на 0 это ноль, у него есть и знак
/*
#include <math.h>
#include <iostream>
#include <Windows.h>
//#include <stdio.h>
//#include <vector>

using namespace std;

/*
class a sealed
{
	a()
	{
	}
};

class b : a
{

}
*/
/*
bool signbit(double x)
{
    return 1.0/x != 1.0/fabs(x);
}

int main(){
 double aaa[] = {1,0,0};
 double bbb[] = {-1,0,0};
 double a = aaa[0];
 double aZero = aaa[1];
 double b = bbb[0];
 double bZero = bbb[1];

cout<<aZero/a<<endl;
cout<<bZero/b<<endl;

if(!signbit(aZero/a)){
	cout<<"+"<<endl;

	}
	else{
	cout<<"-"<<endl;
	}
if(!signbit(bZero/b)){
	cout<<"+"<<endl;

	}
	else{
	cout<<"-"<<endl;
	}

	//cout<<sg(aZero/a)<<endl;
	//cout<<sign(bZero/b)<<endl;
	
system("pause");
return 0;
}
*/
//Если чесно, ят тут просто немного шаманю :D. Но ведь работает

///////////////////////////////// LOG and LOGL

//да суть была, что вычислеения были ложными при стандартном log, 
//замена на logl сразу привела к правильным результатам. ты у влада спроси

// функции с переменным числом параметров c++
/*
#include <windows.h>
#include <stdio.h>
#define EMPTY

#define CHECK1(x,path, ...) if (!(x)) { printf(__VA_ARGS__); fprintf(path,__VA_ARGS__); }
#define CHECK2(x, ...) if ((x)) { printf(__VA_ARGS__); }
#define CHECK3(...) { printf(__VA_ARGS__); }
#define MACRO(s, ...) printf(s, __VA_ARGS__)

int main() {

	FILE * pFile;

	pFile = fopen ("myfile.txt","w");

    CHECK1(0, pFile, "here %s %s %s", "are", "some", "varargs1(1)\n");
	CHECK1(0, pFile, "here\n", "are", "some", "varargs1(1)\n");
    CHECK1(1, pFile, "here %s %s %s", "are", "some", "varargs1(2)\n");   // won't print

    CHECK2(0, "here %s %s %s", "are", "some", "varargs2(3)\n");   // won't print
    CHECK2(1, "here %s %s %s", "are", "some", "varargs2(4)\n");

    // always invokes printf in the macro
    CHECK3("here %s %s %s", "are", "some", "varargs3(5)\n");

    MACRO("hello, world\n");

    MACRO("error\n", EMPTY); // would cause error C2059, except VC++ 
                             // suppresses the trailing comma

	fclose(pFile);
	system("pause");
	return 0;
}
*/

// Small Version 
// C - program
/*
#include <Windows.h>
#include <stdio.h>

int main() {
	
	////////////////////////////////

	printf("HelloWorld\n");
	printf("HelloWorld\n");
	system("pause");
	return 0;
}
*/


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
	SLDFSDF;SDLFKDSLKFSKFSDJFLKSNDVSDVSSK;VN;ASDLV;ASKDV;JASDVS;DVKSDNVLSKNVIEJJFWIEGWEGARPKAP[RGKWEJO[POWJBORJB[PROJBWE[BKO[ARJB'BK'PBKPBFPPFBF
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
 * Advanced Encryption Standard
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 * Based on the document FIPS PUB 197
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * Addition in GF(2^8)
 * http://en.wikipedia.org/wiki/Finite_field_arithmetic
 */
uint8_t gadd(uint8_t a, uint8_t b) {
	return a^b;
}

/*
 * Subtraction in GF(2^8)
 * http://en.wikipedia.org/wiki/Finite_field_arithmetic
 */
uint8_t gsub(uint8_t a, uint8_t b) {
	return a^b;
}

/*
 * Multiplication in GF(2^8)
 * http://en.wikipedia.org/wiki/Finite_field_arithmetic
 * Irreducible polynomial m(x) = x8 + x4 + x3 + x + 1
 */
uint8_t gmult(uint8_t a, uint8_t b) {

	uint8_t p = 0, i = 0, hbs = 0;

	for (i = 0; i < 8; i++) {
		if (b & 1) {
			p ^= a;
		}

		hbs = a & 0x80;
		a <<= 1;
		if (hbs) a ^= 0x1b; // 0000 0001 0001 1011	
		b >>= 1;
	}

	return (uint8_t)p;
}

/*
 * Addition of 4 byte words
 * m(x) = x4+1
 */
void coef_add(uint8_t a[], uint8_t b[], uint8_t d[]) {

	d[0] = a[0]^b[0];
	d[1] = a[1]^b[1];
	d[2] = a[2]^b[2];
	d[3] = a[3]^b[3];
}

/*
 * Multiplication of 4 byte words
 * m(x) = x4+1
 */
void coef_mult(uint8_t *a, uint8_t *b, uint8_t *d) {

	d[0] = gmult(a[0],b[0])^gmult(a[3],b[1])^gmult(a[2],b[2])^gmult(a[1],b[3]);
	d[1] = gmult(a[1],b[0])^gmult(a[0],b[1])^gmult(a[3],b[2])^gmult(a[2],b[3]);
	d[2] = gmult(a[2],b[0])^gmult(a[1],b[1])^gmult(a[0],b[2])^gmult(a[3],b[3]);
	d[3] = gmult(a[3],b[0])^gmult(a[2],b[1])^gmult(a[1],b[2])^gmult(a[0],b[3]);
}

/*
 * The cipher Key.	
 */
int K;

/*
 * Number of columns (32-bit words) comprising the State. For this 
 * standard, Nb = 4.
 */
int Nb = 4;

/*
 * Number of 32-bit words comprising the Cipher Key. For this 
 * standard, Nk = 4, 6, or 8.
 */
int Nk;

/*
 * Number of rounds, which is a function of  Nk  and  Nb (which is 
 * fixed). For this standard, Nr = 10, 12, or 14.
 */
int Nr;

/*
 * S-box transformation table
 */
static uint8_t s_box[256] = {
	// 0     1     2     3     4     5     6     7     8     9     a     b     c     d     e     f
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, // 0
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, // 1
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, // 2
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, // 3
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, // 4
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, // 5
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8, // 6
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, // 7
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73, // 8
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, // 9
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, // a
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, // b
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, // c
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, // d
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, // e
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16};// f

/*
 * Inverse S-box transformation table
 */
static uint8_t inv_s_box[256] = {
	// 0     1     2     3     4     5     6     7     8     9     a     b     c     d     e     f
	0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb, // 0
	0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb, // 1
	0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e, // 2
	0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25, // 3
	0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92, // 4
	0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84, // 5
	0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06, // 6
	0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b, // 7
	0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73, // 8
	0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e, // 9
	0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b, // a
	0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4, // b
	0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f, // c
	0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef, // d
	0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61, // e
	0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d};// f


/*
 * Generates the round constant Rcon[i]
 */
uint8_t R[] = {0x02, 0x00, 0x00, 0x00};
 
uint8_t * Rcon(uint8_t i) {
	
	if (i == 1) {
		R[0] = 0x01; // x^(1-1) = x^0 = 1
	} else if (i > 1) {
		R[0] = 0x02;
		i--;
		while (i-1 > 0) {
			R[0] = gmult(R[0], 0x02);
			i--;
		}
	}
	
	return R;
}

/*
 * Transformation in the Cipher and Inverse Cipher in which a Round 
 * Key is added to the State using an XOR operation. The length of a 
 * Round Key equals the size of the State (i.e., for Nb = 4, the Round 
 * Key length equals 128 bits/16 bytes).
 */
void add_round_key(uint8_t *state, uint8_t *w, uint8_t r) {
	
	uint8_t c;
	
	for (c = 0; c < Nb; c++) {
		state[Nb*0+c] = state[Nb*0+c]^w[4*Nb*r+Nb*c+0];
		state[Nb*1+c] = state[Nb*1+c]^w[4*Nb*r+Nb*c+1];
		state[Nb*2+c] = state[Nb*2+c]^w[4*Nb*r+Nb*c+2];
		state[Nb*3+c] = state[Nb*3+c]^w[4*Nb*r+Nb*c+3];	
	}
}

/*
 * Transformation in the Cipher that takes all of the columns of the 
 * State and mixes their data (independently of one another) to 
 * produce new columns.
 */
void mix_columns(uint8_t *state) {

	uint8_t a[] = {0x02, 0x01, 0x01, 0x03}; // a(x) = {02} + {01}x + {01}x2 + {03}x3
	uint8_t i, j, col[4], res[4];

	for (j = 0; j < Nb; j++) {
		for (i = 0; i < 4; i++) {
			col[i] = state[Nb*i+j];
		}

		coef_mult(a, col, res);

		for (i = 0; i < 4; i++) {
			state[Nb*i+j] = res[i];
		}
	}
}

/*
 * Transformation in the Inverse Cipher that is the inverse of 
 * MixColumns().
 */
void inv_mix_columns(uint8_t *state) {

	uint8_t a[] = {0x0e, 0x09, 0x0d, 0x0b}; // a(x) = {0e} + {09}x + {0d}x2 + {0b}x3
	uint8_t i, j, col[4], res[4];

	for (j = 0; j < Nb; j++) {
		for (i = 0; i < 4; i++) {
			col[i] = state[Nb*i+j];
		}

		coef_mult(a, col, res);

		for (i = 0; i < 4; i++) {
			state[Nb*i+j] = res[i];
		}
	}
}

/*
 * Transformation in the Cipher that processes the State by cyclically 
 * shifting the last three rows of the State by different offsets. 
 */
void shift_rows(uint8_t *state) {

	uint8_t i, k, s, tmp;

	for (i = 1; i < 4; i++) {
		// shift(1,4)=1; shift(2,4)=2; shift(3,4)=3
		// shift(r, 4) = r;
		s = 0;
		while (s < i) {
			tmp = state[Nb*i+0];
			
			for (k = 1; k < Nb; k++) {
				state[Nb*i+k-1] = state[Nb*i+k];
			}

			state[Nb*i+Nb-1] = tmp;
			s++;
		}
	}
}

/*
 * Transformation in the Inverse Cipher that is the inverse of 
 * ShiftRows().
 */
void inv_shift_rows(uint8_t *state) {

	uint8_t i, k, s, tmp;

	for (i = 1; i < 4; i++) {
		s = 0;
		while (s < i) {
			tmp = state[Nb*i+Nb-1];
			
			for (k = Nb-1; k > 0; k--) {
				state[Nb*i+k] = state[Nb*i+k-1];
			}

			state[Nb*i+0] = tmp;
			s++;
		}
	}
}

/*
 * Transformation in the Cipher that processes the State using a non­
 * linear byte substitution table (S-box) that operates on each of the 
 * State bytes independently. 
 */
void sub_bytes(uint8_t *state) {

	uint8_t i, j;
	uint8_t row, col;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < Nb; j++) {
			row = (state[Nb*i+j] & 0xf0) >> 4;
			col = state[Nb*i+j] & 0x0f;
			state[Nb*i+j] = s_box[16*row+col];
		}
	}
}

/*
 * Transformation in the Inverse Cipher that is the inverse of 
 * SubBytes().
 */
void inv_sub_bytes(uint8_t *state) {

	uint8_t i, j;
	uint8_t row, col;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < Nb; j++) {
			row = (state[Nb*i+j] & 0xf0) >> 4;
			col = state[Nb*i+j] & 0x0f;
			state[Nb*i+j] = inv_s_box[16*row+col];
		}
	}
}

/*
 * Function used in the Key Expansion routine that takes a four-byte 
 * input word and applies an S-box to each of the four bytes to 
 * produce an output word.
 */
void sub_word(uint8_t *w) {

	uint8_t i;

	for (i = 0; i < 4; i++) {
		w[i] = s_box[16*((w[i] & 0xf0) >> 4) + (w[i] & 0x0f)];
	}
}

/*
 * Function used in the Key Expansion routine that takes a four-byte 
 * word and performs a cyclic permutation. 
 */
void rot_word(uint8_t *w) {

	uint8_t tmp;
	uint8_t i;

	tmp = w[0];

	for (i = 0; i < 3; i++) {
		w[i] = w[i+1];
	}

	w[3] = tmp;
}

/*
 * Key Expansion
 */
void key_expansion(uint8_t *key, uint8_t *w) {

	uint8_t tmp[4];
	uint8_t i, j;
	uint8_t len = Nb*(Nr+1);

	for (i = 0; i < Nk; i++) {
		w[4*i+0] = key[4*i+0];
		w[4*i+1] = key[4*i+1];
		w[4*i+2] = key[4*i+2];
		w[4*i+3] = key[4*i+3];
	}

	for (i = Nk; i < len; i++) {
		tmp[0] = w[4*(i-1)+0];
		tmp[1] = w[4*(i-1)+1];
		tmp[2] = w[4*(i-1)+2];
		tmp[3] = w[4*(i-1)+3];

		if (i%Nk == 0) {

			rot_word(tmp);
			sub_word(tmp);
			coef_add(tmp, Rcon(i/Nk), tmp);

		} else if (Nk > 6 && i%Nk == 4) {

			sub_word(tmp);

		}

		w[4*i+0] = w[4*(i-Nk)+0]^tmp[0];
		w[4*i+1] = w[4*(i-Nk)+1]^tmp[1];
		w[4*i+2] = w[4*(i-Nk)+2]^tmp[2];
		w[4*i+3] = w[4*(i-Nk)+3]^tmp[3];
	}
}

void cipher(uint8_t *in, uint8_t *out, uint8_t *w) {

	uint8_t state[4*Nb];
	uint8_t r, i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < Nb; j++) {
			state[Nb*i+j] = in[i+4*j];
		}
	}

	add_round_key(state, w, 0);

	for (r = 1; r < Nr; r++) {
		sub_bytes(state);
		shift_rows(state);
		mix_columns(state);
		add_round_key(state, w, r);
	}

	sub_bytes(state);
	shift_rows(state);
	add_round_key(state, w, Nr);

	for (i = 0; i < 4; i++) {
		for (j = 0; j < Nb; j++) {
			out[i+4*j] = state[Nb*i+j];
		}
	}
}

void inv_cipher(uint8_t *in, uint8_t *out, uint8_t *w) {

	uint8_t state[4*Nb];
	uint8_t r, i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < Nb; j++) {
			state[Nb*i+j] = in[i+4*j];
		}
	}

	add_round_key(state, w, Nr);

	for (r = Nr-1; r >= 1; r--) {
		inv_shift_rows(state);
		inv_sub_bytes(state);
		add_round_key(state, w, r);
		inv_mix_columns(state);
	}

	inv_shift_rows(state);
	inv_sub_bytes(state);
	add_round_key(state, w, 0);

	for (i = 0; i < 4; i++) {
		for (j = 0; j < Nb; j++) {
			out[i+4*j] = state[Nb*i+j];
		}
	}
}

#include <Windows.h>;
/*********************** FUNCTION DEFINITIONS ***********************/
void print_hex(BYTE str[], int len)
{
	int idx;

	for(idx = 0; idx < len; idx++)
		printf("%02x ", str[idx]);
}

void printWordKey(uint8_t str[], int len)
{
	int idx;

	for(idx = 0; idx < len; idx++)
		printf("%d ", str[idx]);
}


int main(int argc, char *argv[])
{
	/*
	BYTE bMessage[]="Hello World";	// len = 11
	BYTE bEncMessage[5];
	BYTE bEncMessage1[11];
	BYTE bKey[] = "1234"; 				// len = 3 		128 bit - 128/8 = 16//
	uint8_t wKey[128];

	KeyExpansion(bKey,          // The key, must be 128, 192, or 256 bits
                  wKey,          // Output key schedule to be used later
                  128);          // Bit length of the key, 128, 192, or 256


	printf("Message: %s\n", bMessage);	
	printf("Message HEX: ");	print_hex(bMessage, 11);	printf("\n");
	printf("Key: %s\n", bKey);
	printf("WORD Key: ");		printWordKey(wKey, 128);	printf("\n");
	printf("__________________________________\n");	

	aes_encrypt(bMessage, bEncMessage, wKey, 128);
	printf("Encrypted Message: %s\n", bEncMessage);	

	aes_decrypt(bEncMessage, bEncMessage1, wKey, 128);
	printf("Encrypted Message: %s\n", bEncMessage1);	
	*/
	uint8_t i;

	/*
	 * Appendix A - Key Expansion Examples
	 */
	 
	/* 128 bits */
	/* uint8_t key[] = {
		0x2b, 0x7e, 0x15, 0x16,
		0x28, 0xae, 0xd2, 0xa6,
		0xab, 0xf7, 0x15, 0x88,
		0x09, 0xcf, 0x4f, 0x3c}; */
	
	/* 192 bits */
	/* uint8_t key[] = {
		0x8e, 0x73, 0xb0, 0xf7,
		0xda, 0x0e, 0x64, 0x52,
		0xc8, 0x10, 0xf3, 0x2b,
		0x80, 0x90, 0x79, 0xe5,
		0x62, 0xf8, 0xea, 0xd2,
		0x52, 0x2c, 0x6b, 0x7b}; */
	
	/* 256 bits */
	/* uint8_t key[] = {
		0x60, 0x3d, 0xeb, 0x10,
		0x15, 0xca, 0x71, 0xbe,
		0x2b, 0x73, 0xae, 0xf0,
		0x85, 0x7d, 0x77, 0x81,
		0x1f, 0x35, 0x2c, 0x07,
		0x3b, 0x61, 0x08, 0xd7,
		0x2d, 0x98, 0x10, 0xa3,
		0x09, 0x14, 0xdf, 0xf4};
	*/
	
	/* uint8_t in[] = {
		0x32, 0x43, 0xf6, 0xa8,
		0x88, 0x5a, 0x30, 0x8d,
		0x31, 0x31, 0x98, 0xa2,
		0xe0, 0x37, 0x07, 0x34}; // 128
	*/

	/*
	 * Appendix C - Example Vectors
	 */

	/* 128 bit key */
	/* uint8_t key[] = {
		0x00, 0x01, 0x02, 0x03, 
		0x04, 0x05, 0x06, 0x07, 
		0x08, 0x09, 0x0a, 0x0b, 
		0x0c, 0x0d, 0x0e, 0x0f}; */
	
	/* 192 bit key */
	/* uint8_t key[] = {
		0x00, 0x01, 0x02, 0x03,
		0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0a, 0x0b,
		0x0c, 0x0d, 0x0e, 0x0f,
		0x10, 0x11, 0x12, 0x13,
		0x14, 0x15, 0x16, 0x17}; */
	
	/* 256 bit key */
	uint8_t key[] = {
		0x00, 0x01, 0x02, 0x03,
		0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0a, 0x0b,
		0x0c, 0x0d, 0x0e, 0x0f,
		0x10, 0x11, 0x12, 0x13,
		0x14, 0x15, 0x16, 0x17,
		0x18, 0x19, 0x1a, 0x1b,
		0x1c, 0x1d, 0x1e, 0x1f};

	uint8_t in[] = {
		0x00, 0x11, 0x22, 0x33,
		0x44, 0x55, 0x66, 0x77,
		0x88, 0x99, 0xaa, 0xbb,
		0xcc, 0xdd, 0xee, 0xff};
	
	uint8_t out[16]; // 128
	
	uint8_t *w; // expanded key

	switch (sizeof(key)) {
		default:
		case 16: Nk = 4; Nr = 10; break;
		case 24: Nk = 6; Nr = 12; break;
		case 32: Nk = 8; Nr = 14; break;
	}
	
	w = (uint8_t *) malloc(Nb*(Nr+1)*4);

	key_expansion(key, w);

	cipher(in /* in */, out /* out */, w /* expanded key */);

	printf("out:\n");
	
	for (i = 0; i < 4; i++) {
		printf("%x %x %x %x ", out[4*i+0], out[4*i+1], out[4*i+2], out[4*i+3]);
	}

	printf("\n");

	inv_cipher(out, in, w);

	printf("msg:\n");
	for (i = 0; i < 4; i++) {
		printf("%x %x %x %x ", in[4*i+0], in[4*i+1], in[4*i+2], in[4*i+3]);
	}

	printf("\n");


	system("pause");
	return(0);
}