#ifndef argv_121
#define argv_121

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define argv_597		// Exclude rarely-used stuff from Windows headers

#pragma warning(disable:4800) // forcing value to bool 'true' or 'false' (performance warning)
#pragma warning(disable:4291) // void *__cdecl operator new(unsigned int,const struct std::nothrow_t &
#pragma warning(disable:4244) // '=' : conversion from 'double' to 'long', possible loss of argv_174
#pragma warning(disable:4267)
#pragma warning(disable:4311)
#pragma warning(disable:4302)
#pragma warning(disable:4996)

#include <Windows.h>
#include <winnt.h>
#include <Commdlg.h>
#include <commctrl.h>
#include <Commdlg.h>
#include <shellapi.h>
#include <fcntl.h>
#include <shlobj.h>
#include <Mmsystem.h>

#include <string>
#include <vector>
#include <cassert>
#include <cstdio>
#include <stack>
#include <list>
#include <io.h>
#include <aclapi.h>
#include <lmerr.h>

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;

#define argv_193 -1
#define argv_584 unsigned char
#define argv_569 signed char
#define argv_585 unsigned short
#define argv_570 signed short
#define argv_571 signed int
#define argv_586 unsigned int
#define argv_587 unsigned long
#define argv_564 float
#define argv_565 double
#define argv_147 const char *
#define argv_509 -1 // -1 for infinite size
#define argv_475 655360
#define argv_504 10
#define argv_179 4096
#define argv_218 2048
#define argv_476 ((DWORD)-1)

#define argv_128 0x00008000
#define argv_143 0x00004000

#define argv_573 _snprintf

enum argv_138 {
	argv_538,
};

enum argv_137 {
	argv_515,
	argv_511,
	argv_514,
	argv_513,
	argv_512,
};

enum argv_136 {
	argv_165=54,
	argv_599,
	argv_556,
};

#ifndef argv_144
#define argv_144 0x0040
#endif // !argv_144

#ifndef argv_302 // hand cursor argv_178
#define argv_302 MAKEINTRESOURCE(32649)
#endif


bool argv_154 (argv_584 c1, argv_584 c2, argv_584& result);
const argv_571 argv_518 = 256;
string argv_594 (const vector<argv_584>&);
string argv_211 (const vector<argv_584>&);
bool argv_563 (const char *, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586, argv_586&, argv_586&);
bool argv_560 (const char *, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&);
bool argv_561 (const char *, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&);
bool argv_562 (const char *, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&, argv_586&);


enum argv_535 {
	argv_531=0,
	argv_536,
	argv_532,
	argv_534,
	argv_533,
};

string argv_530 (HWND, argv_571 mode);
string argv_156 (HWND, argv_571 mode);

// beware: this routine does not use file mmaping, thus you can have
// a performance penalty here...
bool argv_478 (const char *); 
bool argv_186 (const char *);
unsigned long argv_160 (const string&);
argv_586 argv_160 (argv_147);
string argv_155 (HWND hWnd);

// ==== performance checker ========
class argv_149
{
protected:
	LARGE_INTEGER argv_496;
	LARGE_INTEGER argv_497;

	LONGLONG argv_499;
	LONGLONG argv_498;

public:
	argv_149(void);

	void argv_575(void);
	void argv_577(void);
	double argv_198(void) const;
	string argv_578 ();
};

inline argv_149::argv_149(void) {
	LARGE_INTEGER liFrequency;

	QueryPerformanceFrequency(&liFrequency);
	argv_499 = liFrequency.QuadPart;

	// Calibration
	argv_575();
	argv_577();

	argv_498 = argv_497.QuadPart-argv_496.QuadPart;
}

inline void argv_149::argv_575(void) {
	// Ensure we will not be interrupted by any other thread for a while
//	Sleep(0);
	QueryPerformanceCounter(&argv_496);
}

inline void argv_149::argv_577(void) {
	QueryPerformanceCounter(&argv_497);
}

inline double argv_149::argv_198(void) const {
	return (double)(argv_497.QuadPart-argv_496.QuadPart-argv_498)*1000000.0 / argv_499;
}

inline string argv_149::argv_578 () {
	argv_577 ();
	double elapsed = argv_198 ();
	char tmp[1024];
	if (elapsed > 1000000.0) {
		elapsed = elapsed / 1000000.0;
		//if (elapsed > 60.0) {
		//	elapsed = elapsed / 60.0;
		//	argv_573 (tmp, 1024, "elapsed time : %.02lf minutes", elapsed);
		//}
		//else {
			argv_573 (tmp, 1024, "elapsed time : %.02lf seconds", elapsed);
		//}
	}
	else {
		argv_573 (tmp, 1024, "elapsed time : %.02lf microseconds", elapsed);
	}
	tmp[1024 - 1] = '\0';
	return tmp;
}

//==============================
// permits to mmap a given file
//==============================
class argv_153
{
	private:
		string	argv_501;
		HANDLE	argv_212;
		HANDLE	argv_215;
		LPCTSTR argv_540;
		argv_586	argv_181;
		argv_586	argv_183;

	public:
		argv_153();
		~argv_153();
		bool argv_519 (const char *, bool, argv_584 *&, DWORD&);
		void argv_159 ();
		void argv_201 (argv_586&, argv_586&);
};

bool argv_199 (char *, argv_587, argv_587&);
void argv_194 (const string&, int, string&);
void argv_195 (const char *, const char *, const char *, string&, string&);

bool argv_177 (string);
void argv_150 (HWND);
void argv_150 (HWND, int&, int&);
bool argv_167 (string _dirname);
bool argv_162 (string, string, string);

class argv_146
{
private:
	int argv_173;
	int argv_502;
	HWND hwnd;
	int	argv_222;

public:
	argv_146();
	void init (HWND, int, int);
	void incr (argv_571 _nb_step=1);
	void reset();
	int argv_196 () {
		return (argv_173);
	}
};

//==========================
template <class T>
class argv_152
{
private:
	vector<T>	v;
	int			top_index;
	int			argv_523; // number of allocated elements
	int			argv_505;

public:
	argv_152();
	void		push (T);
	void		pop  ();
	T			top  ();
	int			size ();
	bool		empty ();
	void		reset ();
	void		clear ();
	void		rewind ();
};

template <class T>
argv_152<T>::argv_152 () {
	top_index	= 0;
	argv_523		= 0;
	argv_505	= 0;
}

// erase all argv_174 from container
template <class T>
void argv_152<T>::clear () {
	vector<T>().swap (v); // force vector's memory free
	argv_523	  = 0;
	top_index = 0;
	argv_505 = 0;	
}

// just set pointer to the bottom of the stack
template <class T>
void argv_152<T>::reset () {
	top_index = 0;
	argv_505 = 0;
}

// rewind the stack to the top as if all elements had just been pushed
template <class T>
void argv_152<T>::rewind () {
	top_index = argv_505;
}

template <class T>
void argv_152<T>::push (T _elem) {
	if (argv_523 < (top_index+1)) {
		v.push_back (_elem);
		argv_523++;
	}
	else { // already allocated => no need to push_back
		v[top_index] = _elem;
	}
	top_index++;
	if (top_index > argv_505) {
		argv_505 = top_index;
	}
}


template <class T>
void argv_152<T>::pop () {
	assert (top_index > 0);
	top_index--;
}

template <class T>
T argv_152<T>::top () {
	assert (top_index > 0);
	return (v[top_index - 1]);
}

template <class T>
int argv_152<T>::size () {
	return (top_index);
}

template <class T>
bool argv_152<T>::empty () {
	return (top_index == 0);	
}

//=======================
bool argv_187 (const char *);
bool argv_559 (const char *);
//========================================

class argv_151
{
private:
	CRITICAL_SECTION argv_168;   // Windows' basic mutex object.
	stack<string>	argv_542;

public:
	argv_151 () {
		InitializeCriticalSection(&argv_168);		
	}

	~argv_151 () {
		DeleteCriticalSection(&argv_168);
	}

	bool argv_545 (string& _str) {
		bool bret = true;
		EnterCriticalSection (&argv_168);
			argv_542.push (_str);
		LeaveCriticalSection(&argv_168);	
		return (bret);
	}

	bool argv_161 (string& _str) {
		bool bret = false;
		EnterCriticalSection (&argv_168);
			if (! argv_542.empty()) {
				_str = argv_542.top();
				argv_542.pop();
				bret = true;
			}
		LeaveCriticalSection(&argv_168);	
		return (bret);
	}
};

//=====================================
// thread safe piece of argv_174
//=====================================
template <class T>
class argv_171
{
private:
	T argv_174;
	CRITICAL_SECTION argv_168;   // Windows' basic mutex object.

public:
	argv_171 ();
	T get ();
	void set (T);
	void incr ();
	~argv_171();
};

template <class T>
argv_171<T>::argv_171 () {
	InitializeCriticalSection(&argv_168);	
}

template <class T>
argv_171<T>::~argv_171 () {
	DeleteCriticalSection(&argv_168);
}

template <class T>
T argv_171<T>::get () {
	T retrieved_data;
	EnterCriticalSection (&argv_168);
		retrieved_data = argv_174;	
	LeaveCriticalSection(&argv_168);
	return (retrieved_data);
}

template <class T>
void argv_171<T>::set (T _elem) {
	EnterCriticalSection (&argv_168);
		argv_174 = _elem;
	LeaveCriticalSection(&argv_168);
}

template <class T>
void argv_171<T>::incr () {
	EnterCriticalSection (&argv_168);
		argv_174++;
	LeaveCriticalSection(&argv_168);
}

//=====================================
// anonymous pipes C++ implementation
//=====================================
class argv_163 { 
protected:
	HANDLE				argv_557;
	HANDLE				argv_600;
	bool				argv_539;
	unsigned long		argv_524;
	unsigned long		argv_525;
	int					current_offset;
	int					argv_508;
	HANDLE				argv_208;
	unsigned long		argv_522;
	bool				argv_192;

	virtual void		argv_490() { ; }
	virtual void		argv_590 () { ; }
	virtual void		argv_487() { ; }
	virtual void		argv_589 () { ; }

public:
	argv_163 () {
		argv_522 = 0;
		argv_539 = false;
		if (! CreatePipe(&argv_557, &argv_600, /*&saAttr*/NULL, 0)) {
//				MessageBox(argv_567, "CreatePipe failed !", "Error", MB_OK);	
		}
		else {
			argv_539			= true;
			current_offset	= 0;
		}
	}

	virtual ~argv_163 () {
		if (argv_539) {
			CloseHandle (argv_557);
			CloseHandle (argv_600);
			argv_539 = false;
		}
	}

	bool argv_545 (string& _str) {
		argv_490 ();
		bool bret = true;
		if (argv_539) {
			BOOL reti = WriteFile (argv_600, _str.c_str(), _str.size()+1, &argv_525, NULL);
			if (! reti) {
//				MessageBox(argv_567, "pipe: WriteFile failed !", "Error", MB_OK);	
				bret = false;
			}
			else {
				argv_522 += argv_525;
			}
		}
		else {
			bret = false;
		}
		argv_590 ();
		return (bret);
	}

	bool argv_161 (string& _str) {
		bool bret = true;
		argv_487 ();
		if (argv_539) {
			char c;
			while (1) {
				if (argv_192) {
					_str = "";
					argv_192 = false;
				}
				BOOL reti = ReadFile (argv_557, &c, 1, &argv_524, NULL);
				if ((! reti) || (argv_524 == 0)) {
					bret = false;
				}
				else {
					if (c == '\0') {
						argv_192 = true;
						break;
					}
					else {
						_str += c;
					}
				}
			}
		}
		else { // pipe not argv_539 yet
			bret = false;
		}
		argv_589 ();
		return (bret);
	}

	void reset () {
		if (argv_539) {
			CloseHandle (argv_557);
			CloseHandle (argv_600);
			argv_539 = false;
		}
		if (CreatePipe(&argv_557, &argv_600, NULL, 0)) {
			argv_539 = true;
		}
	}
};

// same object as argv_163, but thread safe version
class argv_164 : public argv_163
{
private:
	CRITICAL_SECTION argv_170;   // Windows' basic mutex object.
	CRITICAL_SECTION argv_169;   // Windows' basic mutex object.

	void argv_490 () {
		EnterCriticalSection (&argv_170);		
	}

	void argv_590 () {
		LeaveCriticalSection (&argv_170);
	}

	void argv_487 () {
		EnterCriticalSection (&argv_169);		
	}

	void argv_589 () {
		LeaveCriticalSection (&argv_169);
	}

public:
	argv_164 () {
		InitializeCriticalSection (&argv_170);	
		InitializeCriticalSection (&argv_169);	
	}

	~argv_164 () {
		DeleteCriticalSection(&argv_170);
		DeleteCriticalSection(&argv_169);
	}
};

//===== FILE TYPE AUTOMATIC ANALYZER ============== 
enum argv_544 {
	argv_588=-1,
	argv_141,
	argv_541,
	argv_528, // VBA script
	argv_217,
	argv_500,
	argv_207,
	argv_180,
	argv_142,
};

// - knows only types recognized by clamav signatures
// - uses only extension of the file to determine the type
class argv_172
{
private:

public:
	argv_172 ();
	argv_571 argv_139 (const char *);
};

bool argv_200 (vector<string>&);
bool argv_197 (vector<string>&);
bool argv_197 (vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&);
void argv_203 (string&);
void argv_204 (HANDLE, string&);

class argv_148
{
public:
	argv_586				argv_601;
	argv_586				argv_520;
	argv_586				argv_175;
	argv_586				argv_216;
	argv_586				argv_517;
	argv_586				second;
	argv_586				argv_516;

	void				reset () {
		argv_601 = argv_520 = argv_175 = argv_216 = argv_517 = 0;	
	}

	argv_148 () {
		reset ();
	}

	void init (argv_586 _year, argv_586 _month, argv_586 _day, argv_586 _hour, argv_586 _minute, argv_586 _second, argv_586 _millisecond) {
		argv_601		= _year;
		argv_520		= _month;
		argv_175			= _day;
		argv_216		= _hour;
		argv_517		= _minute;
		second		= _second;
		argv_516 = _millisecond;
	}
};

class argv_145 
{
private:
	bool			init_done;
	HDC				argv_210;
	PAINTSTRUCT		argv_555;
	HINSTANCE		hInstance;
	int				argv_576;
	HANDLE			argv_209;
	HWND			hwnd_window;
	vector<argv_586>	argv_593;
	argv_571			argv_523;

public:
	argv_145 ();
	void			init (HWND, HINSTANCE);
	void			argv_132 (argv_586);
	void			incr ();
	void			reset ();
	void			argv_178 ();
};

bool argv_477 (const char *);
void argv_558 (HWND hwnd_window, argv_586 _idc, const char * _msg);
void argv_185 (const string&, int, string&);

enum argv_485 {
	argv_482,
	argv_483,
	argv_484,
};

enum argv_131 {
	argv_129 = 124,
	argv_130,
};

bool argv_479 ();
bool argv_480 ();
argv_586 argv_184 (const char *, vector<string>&);
bool argv_189 (argv_147);
bool argv_166 (argv_147);


#endif // argv_121



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
