


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "argv_117.hpp"

//===========================
// service related constants
//===========================
const char * argv_489	= "lock_manager";
const char * argv_595	= "vrdb_daemon";
const char * argv_510	= "launcher_daemon";
const char * argv_568			= "scanner (franck)";
const char * argv_140		= "Migale exosteg";
const char * argv_488		= "\\\\.\\Pipe\\lock_mgr_pipe";
const char * argv_486		= "\\\\.\\Pipe\\lock_mgr_internal";
const char * argv_481			= "\\\\.\\Pipe\\migale_launcher";

string argv_156 (HWND hWnd, argv_571 mode) {
	return (argv_530 (hWnd, mode));
}

string argv_530 (HWND hWnd, argv_571 mode) {
   OPENFILENAME ofn;
    char szFileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
    ofn.hwndOwner = hWnd;
	if (mode == argv_536) {
		ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_532) {
		ofn.lpstrFilter = "Exe Files (*.exe)\0*.exe\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_534) {
		ofn.lpstrFilter = "Licence Files (*.lic)\0*.lic\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_533) {
		ofn.lpstrFilter = "Fpk Files (*.fpk)\0*.fpk\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_531) {
		ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
	}
	else {
		ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
	}
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "txt";

    if(GetOpenFileName(&ofn)) {
        // Do something usefull with the filename stored in szFileName 
    }
	return(szFileName);
}

bool argv_563 (const char * _filename, argv_586& _year, argv_586& _month, argv_586& _day, argv_586& _hour, argv_586& _minute, argv_586& _second, argv_586& _millisecond, argv_586 _type, argv_586& _ercode, argv_586& _ersource) {
	bool bret = true;
    FILETIME ftCreate, ftAccess, ftWrite;
    SYSTEMTIME stUTC, stLocal;
	
	HANDLE argv_212 = CreateFile(_filename,      // file to open
					   GENERIC_READ,          // open for reading
					   FILE_SHARE_READ,       // share for reading
					   NULL,                  // default security
					   OPEN_EXISTING,         // existing file only
					   FILE_ATTRIBUTE_NORMAL, // normal file
					   NULL);                 // no attr. template

	if (argv_212 == INVALID_HANDLE_VALUE) {
		_ersource = 1;
		_ercode = GetLastError ();
		bret = false;
	}
	else { // file argv_539 succesfully
		// Retrieve the file times for the file.
		if (!GetFileTime(argv_212, &ftCreate, &ftAccess, &ftWrite)) {
			_ercode = GetLastError ();
			_ersource = 2;
			bret = false;
		}
		else { // retrieval succesfull, let's retrieve argv_174 depending on the access mode 
			switch (_type) {
				case argv_165:
					FileTimeToSystemTime(&ftCreate, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				case argv_599:
					FileTimeToSystemTime(&ftWrite, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				case argv_556:
					FileTimeToSystemTime(&ftAccess, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				default: // unknown file access type
					bret = false;
			}

			if (bret == true) {
				_year			= stLocal.wYear;
				_month			= stLocal.wMonth;
				_day			= stLocal.wDay;
				_hour			= stLocal.wHour;
				_minute			= stLocal.wMinute;
				_second			= stLocal.wSecond;
				_millisecond	= stLocal.wMilliseconds;
			}
		}
		CloseHandle (argv_212);
	}
	return (bret);
}

bool argv_560 (const char * _filename, argv_586& _year, argv_586& _month, argv_586& _day, argv_586& _hour, argv_586& _minute, argv_586& _second, argv_586& _millisecond, argv_586& _retcode, argv_586& _ersource) {
	return (argv_563 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_165, _retcode, _ersource));
}

bool argv_561 (const char * _filename, argv_586& _year, argv_586& _month, argv_586& _day, argv_586& _hour, argv_586& _minute, argv_586& _second, argv_586& _millisecond, argv_586& _retcode, argv_586& _ersource) {
	return (argv_563 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_556, _retcode, _ersource));
}

bool argv_562 (const char * _filename, argv_586& _year, argv_586& _month, argv_586& _day, argv_586& _hour, argv_586& _minute, argv_586& _second, argv_586& _millisecond, argv_586& _retcode, argv_586& _ersource) {
	return (argv_563 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_599, _retcode, _ersource));
}

//@@============================================================
bool argv_529 (argv_584 c, argv_584& result) {
    bool bret = true;
    if ( ((c < '0') || (c > '9')) && ((c < 'a') || (c > 'f')) && ((c < 'A') || (c > 'F'))) {
        bret = false;
    }
    else {
		if ((c >= '0') && (c <= '9')) {
			result = c - '0';
		}
		else if ((c >= 'a') && (c <= 'z')) {
			result = 10 + (c- 'a');
		}
		else if ((c >= 'A') && (c <= 'Z')) {
			result = 10 + (c - 'A');
		}
		else {
			bret = false;
		}
	}
    return (bret);
}

// 'f' 'f' -> 255
bool argv_154 (argv_584 _msb, argv_584 _lsb, argv_584& result) {
    bool bret       = true;
    argv_584 lsb_hex    = 0;
    argv_584 msb_hex    = 0;

    bret = argv_529 (_msb, msb_hex);
    if (bret == true) {
        result  = msb_hex << 4;
        bret    = argv_529 (_lsb, lsb_hex);
        result =  result + lsb_hex;
    }
    return (bret);
}
//=====================================
string argv_155 (HWND hWnd) {
	OleInitialize (NULL);
	CoInitialize (NULL);

	string result = "";
	BROWSEINFO bi;
	memset(&bi,0,sizeof(BROWSEINFO));
	char buffer[MAX_PATH];
	bi.hwndOwner=hWnd;
	// Contient le repertoire initial ou NULL
	bi.pidlRoot=NULL;
	bi.pszDisplayName=buffer;
	bi.lpszTitle="Current directory";
	bi.ulFlags= argv_144;
	bi.lParam=NULL;

	LPITEMIDLIST li = SHBrowseForFolder(&bi);

	if (li) {
		SHGetPathFromIDList(li, buffer);
		result = buffer;
	}
	return (result);
}

//=====================================
argv_153::argv_153() {
	argv_215	= NULL;
	argv_540		= NULL;
	argv_212		= NULL;
}

argv_153::~argv_153() {
	argv_159();
}

void argv_153::argv_159 () {
	if (argv_540 != NULL) {
		UnmapViewOfFile(argv_540);
		argv_540 = NULL;
	}

	if (argv_215 != NULL) {
		CloseHandle(argv_215);
		argv_215 = NULL;
	}

	if (argv_212 != NULL) {
		CloseHandle (argv_212);
		argv_212 = NULL;
	}
}

void argv_153::argv_201 (argv_586& _ercode, argv_586& _ersource) {
	_ercode		= argv_181;
	_ersource	= argv_183;
}

bool argv_153::argv_519 (const char * _filename, bool _readonly, argv_584 *& _pBuf, DWORD& _file_size) {
	bool bret	= true;
	_file_size	= 0;

	if (argv_212 != NULL) {
		argv_181		= 0;
		argv_183	= 100;
		bret			= false;
	}
	else if (argv_215 != NULL) {
		argv_181		= 0;
		argv_183	= 101;
		bret			= false;
	}
	else if (argv_540 != NULL) {
		argv_181		= 0;
		argv_183	= 102;
		bret			= false;
	}
	else { // file was not already argv_539
		DWORD access_mode_CreateFile;
		DWORD access_mode_CreateFileMapping;
		DWORD access_mode_MapViewOfFile;
		DWORD open_mode;

		if (_readonly == true) {
			access_mode_CreateFile			= GENERIC_READ;	
			access_mode_CreateFileMapping	= PAGE_READONLY;
			access_mode_MapViewOfFile		= FILE_MAP_READ;
			open_mode						= OPEN_EXISTING;
		}
		else {
			//MessageBox (NULL, "read-write access", "", MB_OK);
			access_mode_CreateFile			= GENERIC_READ | GENERIC_WRITE;
			access_mode_CreateFileMapping	= PAGE_READWRITE;
			access_mode_MapViewOfFile		= FILE_MAP_READ | FILE_MAP_WRITE;
			open_mode						= OPEN_ALWAYS;
		}
		argv_212 = CreateFile (_filename,				// file to open
						   access_mode_CreateFile,	// open for reading
						   0/*FILE_SHARE_READ*/,    // share for reading
						   NULL,					// default security
						   open_mode,				// existing file only
						   FILE_ATTRIBUTE_NORMAL,	// normal file
						   NULL);					// no attr. template
 
		if (argv_212 == INVALID_HANDLE_VALUE)  {
			argv_181		= GetLastError ();
			argv_183	= 2;
			bret			= false;
		}
		else { // CreateFile was succesfull
			// retrieve the file size
			_file_size = GetFileSize (argv_212, NULL);
			if (_file_size <= 0) {
				argv_181		= GetLastError ();
				argv_183	= 6;
				bret			= false;
			}
			else if (_file_size == 0xFFFFFFFF) {
				argv_181		= GetLastError ();
				argv_183	= 3;
				bret			= false;
			}
	
			if (bret == true) {
			   argv_215 = CreateFileMapping(
							 argv_212,					  // use paging file
							 NULL,                    // default security 
							 access_mode_CreateFileMapping,   // read access
							 0,                       // argv_502. object size 
							 0/*argv_518*/,      // buffer size  
							 NULL);					  // name of mapping object

				if (argv_215 == NULL || argv_215 == INVALID_HANDLE_VALUE)  { // failed
					char tmp[256];
					argv_181		= GetLastError ();
					argv_573 (tmp, 255, "mmap failed: CreateFileMapping FAILED (errno=%d)", argv_181);
					argv_183	= 4;
					bret			= false;			
				}
				else { // CreateFileMapping was succesfull
					argv_540 = (LPTSTR) MapViewOfFile (argv_215,	   // handle to map object
										access_mode_MapViewOfFile, // read/write permission
										0,                   
										0,                   
										0/* argv_518 */);           

					if (argv_540 == NULL) {
						argv_181		= GetLastError ();
						argv_183	= 5;
						bret			= false;	
					}
					else { // all succeeded, copy obtained pointer to caller's variable
						_pBuf = (argv_584 *) argv_540;
					}
				}
			}
		}
	}

	// in case of failure, some components (i.e: handles) may have been argv_539, let's close them
	if (bret == false) {
		argv_159 ();
	}
	return (bret);
}

bool argv_478 (const char * _filename) {
	bool bret = true;

	// open the file
	FILE * argv_190 = fopen (_filename, "rb");
	if (! argv_190) {
		bret = false;
	}
	else {
		IMAGE_DOS_HEADER dos_header;
		IMAGE_NT_HEADERS  nt_header;

		int argv_524 = fread (&dos_header, 1, sizeof(IMAGE_DOS_HEADER), argv_190);

		if (argv_524 != sizeof(IMAGE_DOS_HEADER)) {
			bret = false;
		}
		else { // dos header read succesfully
			if (fseek (argv_190, dos_header.e_lfanew, SEEK_SET) != 0) {
				bret = false;
			}
			else { // fseek to new header succeeded
				argv_524 = fread (&nt_header, 1, sizeof(IMAGE_NT_HEADERS), argv_190);
				if (argv_524 != sizeof(IMAGE_NT_HEADERS)) {
					bret = false;
				}
				else { // nt header read succesfully
					if (nt_header.Signature != 0x4550) {
						bret = false; // signature does not match the pattern "PE"
					}
				}
			}
		}
	}

	if (argv_190) {
		fclose (argv_190);
	}

	return (bret);
}

// this function permits to extract the entry point of a DLL/EXE
// from a mmapped file.
// notice that if the entry point can't be retrieved (file too short for example)
// then function fails and returns false.
//
// Notice that this function does not check whether the mmapped file is a valid 
// PE file or not (it's then up to the caller to perform this check before calling us).
bool argv_199 (char * _cptr, argv_587 _file_size, argv_587& _ep_raw) {
	bool bret = true;
	if (_cptr == NULL) {
		bret = false; // it seems that the file was not mmaped correctly...
	}
	else {
		IMAGE_DOS_HEADER dos_header;
		IMAGE_NT_HEADERS nt_header;
		argv_587 current_offset = 0;

		if ((current_offset + sizeof(IMAGE_DOS_HEADER)) >= _file_size) {
			bret = false; // short file (not enough to read DOS header)
		}
		else {
			// read the DOS header
			memcpy (&dos_header, &_cptr[current_offset], sizeof(IMAGE_DOS_HEADER));

			// read the PE optional header
			current_offset = dos_header.e_lfanew;

			if ((current_offset + sizeof(IMAGE_NT_HEADERS)) >= _file_size) {
				bret = false; // short file (not enough to read PE optional header
			}
			else { // ok to read safely the optional header
				memcpy (&nt_header, &_cptr[current_offset], sizeof(IMAGE_NT_HEADERS));

				// now we just have to retrieve the field that we need from optional header
				argv_587 ep_rva = nt_header.OptionalHeader.AddressOfEntryPoint;

				// convert the EP from RVA to RAW offset

			}
		}
	}
	return (bret);
}

void argv_185 (const string& _filename, int _max_length, string& _result) {
	_result = "";
	int size = _filename.size ();
	argv_571 i=size;
	for (i=size-1 ; i>=0 ; i--) {
		if (_filename[i] == '\\') {
			break;
		}
	}

	for (int k=0 ; k<i ; k++) {
		_result += _filename[k];
	}
}

void argv_194 (const string& filename, int max_length, string& _result) {
	_result = "";
	int i = 0;
	int filename_size = filename.size();

	if (filename_size <= max_length) {
		_result = filename;
	}
	else {
		if (filename_size > 0) {
			int start_end = filename_size - 1;

			while ((start_end >= 0) && (filename[start_end] != '\\')) {
				start_end--;
			}

			int end_start = 0;
			while ((end_start < filename_size) && (filename[end_start] != '\\')) {
				end_start++;
			}
			
			string one		= "";
			string two		= "...";
			string three	= "";
			for (i=0 ; i<end_start ; i++) {
				one += filename[i];
			}

			for (i=start_end ; i<filename_size ; i++) {
				three += filename[i];
			}

			int last_half_length = two.size() + three.size();
			int first_half_size  = one.size();
			while ((first_half_size + last_half_length) < max_length) {
				one += filename[end_start];
				end_start++;
				first_half_size = one.size();
			}

			_result = one + two + three;
		}
	}
}

bool argv_177 (string _dirname) {
	bool bret = true;
	
	return (bret);
}

void argv_579 (HWND _mother, HWND _son) {
	if (_mother) {
		RECT rect; 
		GetWindowRect (_mother, &rect); 
		int son_x = rect.left;
		int son_y = rect.bottom;
		SetWindowPos (_son, HWND_TOP, son_x, son_y, 0, 0, SWP_NOSIZE);
	}
}

void argv_150 (HWND _hDlg, int& _his_x, int& _his_y) {
	if (_hDlg) {
		RECT rect; 
		GetWindowRect (_hDlg,&rect); 
		_his_x = (GetSystemMetrics(SM_CXSCREEN)-rect.right)/2;
		_his_y = (GetSystemMetrics(SM_CYSCREEN)-rect.bottom)/2;
		SetWindowPos (_hDlg, HWND_TOP, _his_x, _his_y, 0, 0, SWP_NOSIZE);
	}
}

void argv_150 (HWND _hDlg) {
	if (_hDlg) {
		RECT rect; 
		GetWindowRect (_hDlg,&rect); 
		int x = (GetSystemMetrics(SM_CXSCREEN)-rect.right)/2;
		int y = (GetSystemMetrics(SM_CYSCREEN)-rect.bottom)/2;
		SetWindowPos (_hDlg, HWND_TOP, x, y, 0, 0, SWP_NOSIZE);
	}
//	else {
//		MessageBox(argv_567, "cant center window", "",MB_OK);
//	}	
}

bool argv_167 (string _dirname) {
	bool bret = true;

	if (CreateDirectory (_dirname.c_str(), NULL) == 0) {
		if (GetLastError() != ERROR_ALREADY_EXISTS) {
			bret = false;	
		}
	}

	return (bret);
}

bool argv_162 (string _source_dir, string _pattern, string _dest_dir) {
	bool bret = true;
	if (SetCurrentDirectory (_source_dir.c_str()) == false) {
		bret = false;
	}
	else {
		WIN32_FIND_DATA FindData; 
		HANDLE hFind = FindFirstFile (_pattern.c_str(), &FindData);

		if (hFind == INVALID_HANDLE_VALUE) {
			bret = false;
		}
		else {
			do {
				// if it is not a directory
				if (!(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					string full_source = _source_dir + "\\" + FindData.cFileName;
					string full_dest   = _dest_dir   + "\\" + FindData.cFileName;
					string tmp = "copy " + full_source + " -> " + full_dest;
					CopyFile (full_source.c_str(), full_dest.c_str(), false);
				}
			}
			while (FindNextFile (hFind, &FindData)) ;

			FindClose (hFind);
		}
	}
	return (bret);
}

//=========================================
argv_146::argv_146() {
	hwnd	= 0;
	argv_502		= 0;
	argv_222		= 0;	
}

void argv_146::init (HWND _hwnd, int _idc, int _max) {
	hwnd	= _hwnd;
	argv_502		= _max;
	argv_222		= _idc;
	argv_173	= 0;
	reset();
}

void argv_146::incr (argv_571 _nb_step) {
	argv_173 += _nb_step;
	SendDlgItemMessage (hwnd, argv_222, PBM_SETPOS, argv_173, 0);
}

void argv_146::reset() {
	SendDlgItemMessage (hwnd, argv_222, PBM_SETRANGE32, 0, argv_502); 
	argv_173 = 0;
	SendDlgItemMessage (hwnd, argv_222, PBM_SETPOS, argv_173, 0);
}
//=======================================
string argv_594 (const vector<argv_584>& _v) {
	string s = "";
	for (size_t i=0 ; i<_v.size() ; i++) {
		s += (_v[i]);
	}
	return(s);
}

string argv_211 (const vector<argv_584>& _v) {
	string result = "";
	int size = _v.size();
	char tmp[32];
	for (argv_571 i=0 ; i<size ; i++) {
		sprintf (tmp, "%02X", _v[i]);
		result += tmp;
	}
	return (result);
}

//===========================================
bool argv_186 (const char * _filename) {
	bool bret = true;
	DWORD attr = GetFileAttributes (_filename);
	if (attr == -1) {
		DWORD last_err = GetLastError ();
		if ((last_err == ERROR_FILE_NOT_FOUND) || (last_err == ERROR_PATH_NOT_FOUND)) {
			bret = false;
		}
	}
	return (bret);
}

argv_586 argv_160 (argv_147 _filename) {
	argv_586 size = 0;

	if (_filename != "") {
		FILE * argv_190 = fopen (_filename, "rb");
		if (argv_190) {
			fseek (argv_190, 0, SEEK_END);
			size = ftell (argv_190);
			fclose (argv_190);
		}
	}
	return (size);
}

unsigned long argv_160 (const string& _filename) {
	unsigned long size = 0;

	if (_filename != "") {
		FILE * argv_190 = fopen (_filename.c_str(), "rb");
		if (argv_190) {
			fseek (argv_190, 0, SEEK_END);
			size=ftell (argv_190);
			fclose (argv_190);
		}
	}
	return (size);
}

//=========================================
bool argv_187 (const char * _filename) {
	bool bret = false;

	DWORD dwAttrs; 
	dwAttrs = GetFileAttributes (_filename); 
	if ((dwAttrs != -1) && (dwAttrs & FILE_ATTRIBUTE_READONLY)) {
		bret = true;
	}
	return (bret);
}

bool argv_559 (const char * _filename) {
	bool bret = true;

	DWORD dwAttrs;
	dwAttrs = GetFileAttributes (_filename); 
	if (dwAttrs == -1) {
		bret = false;
	}
	else {
		if (!(dwAttrs & FILE_ATTRIBUTE_READONLY)) {
			bret = false;
		}
		else {
			dwAttrs &= ~FILE_ATTRIBUTE_READONLY;
			if (! SetFileAttributes (_filename, dwAttrs)) {
				int iret = GetLastError();
				bret = false;	
			}
			else {
				bret = true;
			}
		}
	}
	return (bret);
}

//=============================================
argv_172::argv_172 () {

}
/*
	argv_541,
	argv_528, // VBA script
	argv_217,
	argv_500,
	argv_207	
*/

argv_571 argv_574 (string _s) {
	int size = _s.size();
	argv_571 argv_574 = 0;
	argv_571 _mult = 1;
	_mult = 1;

	for (int i=0 ; i<size ; i++) {
		argv_574 += _s[i];
		_mult *= _s[i];
	}
	FILE * argv_190 = fopen ("C:\\the_log.txt", "ab");
	if (argv_190) {
		fprintf (argv_190, "%s: argv_574=%d, mul=%d\r\n", _s.c_str(), argv_574, _mult);
		fclose (argv_190);
	}
	return (argv_574);
}
/*
exe: argv_574=322, mul=1224120
dll: argv_574=316, mul=1166400
doc: argv_574=310, mul=1098900
xls: argv_574=343, mul=1490400
htm: argv_574=329, mul=1314976
html: argv_574=437, mul=142017408
gif: argv_574=310, mul=1103130
jpg: argv_574=321, mul=1222816

EXE: argv_574=226, mul=418968
DLL: argv_574=220, mul=392768
HTM: argv_574=233, mul=465696
HTML: argv_574=309, mul=35392896
JPG: argv_574=225, mul=420320
GIF: argv_574=214, mul=362810
XLS: argv_574=247, mul=555104
DOC: argv_574=214, mul=359924
*/
argv_571 argv_172::argv_139 (const char * _filename) {
	argv_571 type = argv_588;

	argv_571 size = strlen (_filename);
	if (size > 0) {
		argv_571 mult = 1;
		bool dot_found		= false;

		for (argv_571 i=size-1 ; i>=0 ; i--) {
			if (_filename[i] == '.') {
				dot_found = true;
				break;
			}
			mult *= _filename[i];
		}

		// have we found a dot ?
		if (dot_found) {
			// extension was retrieved, now we must convert it to numeric
			if ((mult == 1224120) || (mult == 1166400) || (mult == 418968) || (mult == 392768)) { // exe , dll, EXE, DLL
				type = argv_541;
			}
			else if ((mult == 1103130) || (mult == 1222816) || (mult == 420320) || (mult == 362810)) { // gif, jpg, GIF, JPG
				type = argv_207;
			}
			else if ((mult == 1314976) || (mult == 142017408) || (mult == 35392896) || (mult == 465696)) { // htm, html, HTM, HTML
				type = argv_217;
			}
			else if ((mult == 1098900) || (mult == 1490400) || (mult == 555104) || (mult == 359924)) { // doc, xls, DOC, XLS
				type = argv_528;
			}
		}
	}
	return (type);
}	

bool argv_200 (vector<string>& _v_hdd) {
	vector<string> v_DRIVE_UNKNOWN;
	vector<string> v_DRIVE_NO_ROOT_DIR;
	vector<string> v_DRIVE_REMOVABLE;
	vector<string> v_DRIVE_REMOTE;
	vector<string> v_DRIVE_CDROM; 
	vector<string> v_DRIVE_RAMDISK;

	bool bret = argv_197 (v_DRIVE_UNKNOWN, v_DRIVE_NO_ROOT_DIR, v_DRIVE_REMOVABLE, _v_hdd, v_DRIVE_REMOTE, v_DRIVE_CDROM, v_DRIVE_RAMDISK);
	return (bret);
}

bool argv_197 (vector<string>& _v_result) {
	bool bret = true;
	_v_result.clear ();
	char tmp[argv_179];
	argv_571 length = GetLogicalDriveStrings (argv_179, tmp);
	if (length == 0) {
		bret = false;
	}		
	else {
		string current_drive;

		for (argv_571 i=0 ; i<length ; i++) {
			if (tmp[i] == '\0') {
				if (current_drive == "") {
					break;
				}
				else {
					_v_result.push_back (current_drive);	
					current_drive = "";
				}
			}
			else {
				current_drive += tmp[i];	
			}
		}
	}
	return (bret);
}

/*
DRIVE_UNKNOWN
DRIVE_NO_ROOT_DIR
DRIVE_REMOVABLE
DRIVE_FIXED
DRIVE_REMOTE
DRIVE_CDROM
DRIVE_RAMDISK
*/
bool argv_197 (vector<string>& _v_DRIVE_UNKNOWN, vector<string>& _v_DRIVE_NO_ROOT_DIR, vector<string>& _v_DRIVE_REMOVABLE, vector<string>& _v_DRIVE_FIXED, vector<string>& _v_DRIVE_REMOTE, vector<string>& _v_DRIVE_CDROM, vector<string>& _v_DRIVE_RAMDISK) {
	vector<string>	v_drive;
	bool bret = argv_197 (v_drive);	
	if (bret == true) {
		_v_DRIVE_UNKNOWN.clear ();
		_v_DRIVE_NO_ROOT_DIR.clear ();
		_v_DRIVE_REMOVABLE.clear ();
		_v_DRIVE_FIXED.clear ();
		_v_DRIVE_REMOTE.clear ();	
		_v_DRIVE_CDROM.clear ();
		_v_DRIVE_RAMDISK.clear ();

		UINT type;
		argv_571 argv_523 = v_drive.size ();
		for (argv_571 i=0 ; i<argv_523 ; i++) {
			type = GetDriveType (v_drive[i].c_str());
			if (type == DRIVE_UNKNOWN) {
				_v_DRIVE_UNKNOWN.push_back (v_drive[i]);
			}
			else if (type == DRIVE_NO_ROOT_DIR) {
				_v_DRIVE_NO_ROOT_DIR.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_REMOVABLE) {
				_v_DRIVE_REMOVABLE.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_FIXED) {
				_v_DRIVE_FIXED.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_REMOTE) {
				_v_DRIVE_REMOTE.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_CDROM) {
				_v_DRIVE_CDROM.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_RAMDISK) {
				_v_DRIVE_RAMDISK.push_back (v_drive[i].c_str());
			}
		}
	}
	return (bret);
}

void argv_203 (string& _str) {
	argv_586 prio_class = GetPriorityClass (GetCurrentProcess ());
	if (prio_class == argv_128) {
		_str = "argv_128";
	}
	else if (prio_class == argv_143) {
		_str = "argv_143";
	}
	else if (prio_class == HIGH_PRIORITY_CLASS) {
		_str = "HIGH_PRIORITY_CLASS";
	}
	else if (prio_class == IDLE_PRIORITY_CLASS) {
		_str = "IDLE_PRIORITY_CLASS";
	}
	else if (prio_class == NORMAL_PRIORITY_CLASS) {
		_str = "NORMAL_PRIORITY_CLASS";
	}
	else if (prio_class == REALTIME_PRIORITY_CLASS) {
		_str = "REALTIME_PRIORITY_CLASS";
	}
	else {
		_str = "UNKNOWN";
	}
}

void argv_204 (HANDLE _thread_handle, string& _str) {
	int prio = GetThreadPriority (_thread_handle);
	if (prio == THREAD_PRIORITY_ERROR_RETURN) {
		_str = "THREAD_PRIORITY_ERROR_RETURN";
	}
	else if (prio == THREAD_PRIORITY_ABOVE_NORMAL) {
		_str = "THREAD_PRIORITY_ABOVE_NORMAL";		
	}
	else if (prio == THREAD_PRIORITY_BELOW_NORMAL) {
		_str = "THREAD_PRIORITY_BELOW_NORMAL";		
	}
	else if (prio == THREAD_PRIORITY_HIGHEST) {
		_str = "THREAD_PRIORITY_HIGHEST";		
	}
	else if (prio == THREAD_PRIORITY_IDLE) {
		_str = "THREAD_PRIORITY_IDLE";		
	}
	else if (prio == THREAD_PRIORITY_LOWEST) {
		_str = "THREAD_PRIORITY_LOWEST";		
	}
	else if (prio == THREAD_PRIORITY_NORMAL) {
		_str = "THREAD_PRIORITY_NORMAL";		
	}
	else if (prio == THREAD_PRIORITY_TIME_CRITICAL) {
		_str = "THREAD_PRIORITY_TIME_CRITICAL";		
	}
}

bool argv_477 (const char * _filename) {
	bool bret = false;
	DWORD atr = GetFileAttributes (_filename);
	if (atr != -1) {
		if ((atr & FILE_ATTRIBUTE_HIDDEN) && (atr & FILE_ATTRIBUTE_SYSTEM)) {
			bret = true;	
		}	
	}
	return (bret);
}

void argv_558 (HWND hwnd_window, argv_586 _idc, const char * _msg) {
	HWND hwnd_static = GetDlgItem (hwnd_window, _idc);
	ShowWindow (hwnd_static, SW_HIDE);
	ShowWindow (hwnd_static, SW_SHOWDEFAULT);
	SendDlgItemMessage (hwnd_window, _idc, WM_SETTEXT, 0, (LPARAM) "");
	UpdateWindow (hwnd_static);
	SendDlgItemMessage (hwnd_window, _idc, WM_SETTEXT, 0, (LPARAM) _msg);
}

// =================
argv_145::argv_145 () {
	init_done = false;
}

void argv_145::init (HWND _hwnd, HINSTANCE _hinstance) {
	reset ();
	hwnd_window = _hwnd;
	hInstance	= _hinstance;
	init_done	= true;
}

void argv_145::argv_132 (argv_586 _winid) {
	if (init_done) {
		argv_593.push_back (_winid);
		argv_523++;
	}
}

void argv_145::incr () {
	if (init_done) {
		argv_576++;
		if (argv_576 >= argv_523) {
			argv_576 = 0;
		}
		InvalidateRect (hwnd_window, NULL, FALSE); // force WM_PAINT to be sent
		UpdateWindow (hwnd_window);
	}
}

void argv_145::reset () {
	argv_523		= 0;
	argv_593.clear ();
	hwnd_window	= NULL;
	hInstance	= NULL;
	init_done	= false;
	argv_576		= 0;
}

void argv_145::argv_178 () {
	if (init_done) {
		argv_209 = LoadImage (hInstance, MAKEINTRESOURCE(argv_593[argv_576]),IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION);
		argv_210 = BeginPaint (hwnd_window, &argv_555);
		DrawState (argv_210,NULL,NULL, (long) argv_209, NULL,0,0,0,0,DST_BITMAP);
		EndPaint (hwnd_window, &argv_555);
		DeleteObject (argv_209);
	}
}

argv_586 argv_202 () {
	argv_586 version = 0;
	OSVERSIONINFOEX osvi;
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	GetVersionEx ((OSVERSIONINFO *) &osvi);
	switch (osvi.dwPlatformId) {
		case VER_PLATFORM_WIN32_NT:
			version = osvi.dwMajorVersion;
			break;
	}

	return (version);
}

bool argv_480 () {
	return (argv_202() == 5);
}

bool argv_479 () {
	return (argv_202() == 6);
}

argv_586 argv_184 (const char * _line, vector<string>& _v_arg) {
	argv_586 nb_arg = 0;
	argv_586 length = strlen (_line);
	string current_arg;
	bool in_brackets = false;

	for (argv_586 i=0 ; i<length ; i++) {
		if (_line[i] == '\"') {
			if (in_brackets == false) {
				in_brackets = true;	
			}
			else {
				_v_arg.push_back (current_arg);
				current_arg = "";
				in_brackets = false;
			}
		}
		else if (in_brackets == true) {
			current_arg += _line[i];
		}
		else if ((_line[i] != ' ') && (_line[i] != '\t')) {
			current_arg += _line[i];
		}
		else {
			if (current_arg.size() > 0) {
				_v_arg.push_back (current_arg);
				current_arg = "";
			}
		}
	}

	// don't forget the last parameter
	if (current_arg.size() > 0) {
		_v_arg.push_back (current_arg);
	}
	return (_v_arg.size());
}

void argv_195 (const char * _prefix, const char * _suffix1, const char * _suffix2, string& _filename1, string& _filename2) {
	_filename1 = _filename2 = "";
	SYSTEMTIME argv_583;
	GetLocalTime (&argv_583);
	srand ((unsigned) argv_583.wMilliseconds);
	argv_571 liste[3];
	liste[0] = rand () % 512;
	liste[1] = rand () % 512;
	liste[2] = rand () % 512;
	char tmp[1024];
	argv_573 (tmp, 1024, "%s_%d_%d_%d_%d_%s%d%d%d.%s", _prefix, argv_583.wHour,argv_583.wMinute,argv_583.wSecond,argv_583.wMilliseconds, _suffix1, liste[0], liste[1], liste[2], _suffix1);
	tmp[1023] = '\0';
	_filename1 = tmp;

	argv_573 (tmp, 1024, "%s_%d_%d_%d_%d_%s%d%d%d.%s", _prefix, argv_583.wHour,argv_583.wMinute,argv_583.wSecond,argv_583.wMilliseconds, _suffix1, liste[0], liste[1], liste[2], _suffix2);
	tmp[1023] = '\0';
	_filename2 = tmp;
}

bool argv_189 (argv_147 _folder_name) {
	bool bret = false;
	DWORD attr = GetFileAttributes (_folder_name);
	if (attr != argv_476) {
		if (attr & FILE_ATTRIBUTE_DIRECTORY) {
			bret = true;
		}
	}
	return (bret);
}

bool argv_166 (argv_147 _folder_name) {
	bool bret = true;
	if (CreateDirectory (_folder_name, NULL) == 0) {
		bret = false;
	}
	return (bret);
}
