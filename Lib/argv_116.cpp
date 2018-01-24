


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "..\\Lib\\argv_118.hpp"


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ global declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_157
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ Normal constructor of the argv_157 object.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_157::argv_157() {
	argv_190			= NULL;
	argv_492	= true;
#if defined (THREAD_SAFE_LOG)
	InitializeCriticalSection (&argv_168);	
#endif
}

argv_157::~argv_157() {
	argv_158 ();
#if defined (THREAD_SAFE_LOG)
	// DeleteCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_537
// @@
// @@ INPUT:
// @@ _filename: string : name of the log file to open.
// @@ _in_file: bool: tells whether the log should be written to a
// @@                 file, or to a window.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE:
// @@ bool: true if log file was succesfully argv_539.
// @@       false otherwise.
// @@
// @@ DESCRIPTION:
// @@ This function permits to open the log file whose name is given
// @@ as a parameter.
// @@ Notice that as soon as the log file was argv_539, the opening date
// @@ and time is logged to this log file automatically.
// @@ 
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_157::argv_537 (string _filename, bool _in_file) {
	bool bret = true;

	if (_in_file == true) {
		if (argv_190 != NULL) { // file already argv_539
			bret = false;
		}
		else {
			// modify the drive if necessary
			char tmp[256];
			GetSystemDirectory (tmp, 256);
			_filename[0] = tmp[0];

			argv_190 = fopen (_filename.c_str(), "wb");
			if (!argv_190) {
				char tmp[256];
				argv_573 (tmp, 256, "fopen failed for file : %s (errno=%d: %s)", _filename.c_str(), errno, strerror(errno));
				tmp[255] = '\0';
				bret = false;
			}
			else { // log argv_539 ok
				argv_566 = _filename;
				argv_592 (true);
				string stmp = "Log file creation date : ";
				stmp = stmp + argv_582;
				argv_493 (argv_133, stmp.c_str());
			}
		}
	}
	else {
		argv_492 = false;
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_592
// @@
// @@ INPUT:
// @@ _large_mode: bool: true if we want a large argv_178 of argv_173 date and time
// @@                    false otherwise.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function permits to obtain the argv_173 date and time
// @@ formatted to either a condensed string, or to a developped
// @@ string.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_592 (bool _large_mode) {
	GetLocalTime (&argv_583);
	if (_large_mode == false) {
		argv_573 (argv_582, argv_494, "%02d/%02d-%02dh%02dm%02ds ", argv_583.wMonth, argv_583.wDay, argv_583.wHour, argv_583.wMinute, argv_583.wSecond);
	}
	else {
		argv_573 (argv_582, argv_494, "argv_520 %d the %dth at %d argv_216 %d minutes and %d seconds", argv_583.wMonth, argv_583.wDay, argv_583.wHour, argv_583.wMinute, argv_583.wSecond);
	}
	argv_582[argv_494 - 1] = '\0';
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: insert_date
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function permits to update the argv_173 time and to
// @@ insert it into the header of a new line of the log file.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::insert_date () {
    if (argv_190) {
        argv_592 ();
        fputs (argv_582, argv_190);
    }
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: insert_level
// @@
// @@ INPUT:
// @@ _level: argv_586: level to be displayed.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function permits to insert the level given as a parameter
// @@ to the header of a new line of the log file.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::insert_level (argv_586 _level) {
    string level = "|???| ";
    switch (_level) {
        case argv_527:
            level = "|NOR| ";
            break;
        case argv_596:
            level = "|WRN| ";
            break;
        case argv_182:
            level = "|ERR| ";
            break;
        case argv_133:
            level = "|ADM| ";
            break;
        case argv_176:
            level = "|DBG| ";
            break;
        case argv_526:
            level = "     ";
            break;
    }
    if (argv_190) {
        fputs (level.c_str(), argv_190);
    }
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_158
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function just flushes the argv_174 and close the previously
// @@ argv_539 log file.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_158() {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if ((argv_492 == true) && (argv_190)) {
		fclose (argv_190);
		argv_190 = NULL;
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _level: argv_586: the severity level associated with the message to log.
// @@ _cptr: char *: the message to log
// @@ _no_eol: bool: true if an end of line should be appended at the end of the
// @@                message, false otherwise.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (argv_586 _level, const char * _cptr, bool _no_eol) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_190);
			if (_no_eol == false) { 
				fputs ("\r\n", argv_190);
			}
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}

void argv_157::argv_491 (const char * _cptr) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			fputs (_cptr, argv_190);
			fputs ("\r\n", argv_190);
			fclose (argv_190);
			argv_190 = fopen (argv_566.c_str(), "ab");
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to log
// @@ _no_eol: bool: true if an end of line should be appended at the end of the
// @@                message, false otherwise.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (const char * _cptr, bool _no_eol) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			fputs (_cptr, argv_190);
			if (_no_eol == false) { 
				fputs ("\r\n", argv_190);
			}
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _level: argv_586  : the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (argv_586 _level, const char * _cptr, const char * _cptr2) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_190);
			fputs (_cptr2, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (const char * _cptr, const char * _cptr2) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			fputs (_cptr, argv_190);
			fputs (_cptr2, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _level: argv_586: the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (argv_586 _level, const char * _cptr, const char * _cptr2, const char * _cptr3) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_190);
			fputs (_cptr2, argv_190);
			fputs (_cptr3, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (const char * _cptr, const char * _cptr2, const char * _cptr3) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			fputs (_cptr, argv_190);
			fputs (_cptr2, argv_190);
			fputs (_cptr3, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _level: argv_586: the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
// @@ _cptr4: char *: the fourth message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (argv_586 _level, const char * _cptr, const char * _cptr2, const char * _cptr3, const char * _cptr4) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_190);
			fputs (_cptr2, argv_190);
			fputs (_cptr3, argv_190);
			fputs (_cptr4, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
// @@ _cptr4: char *: the fourth message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (const char * _cptr, const char * _cptr2, const char * _cptr3, const char * _cptr4) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			fputs (_cptr, argv_190);
			fputs (_cptr2, argv_190);
			fputs (_cptr3, argv_190);
			fputs (_cptr4, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _c: argv_584: the character to write to log file.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (argv_584 _c) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			char tmp[128];
			if (_c != 0) {
				sprintf (tmp, "%c", _c);
			}
			else {
				sprintf (tmp, "<0>");
			}
			fputs (tmp, argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)	
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _level: argv_586: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: argv_571: the value to log after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (argv_586 _level, const char * _cptr, argv_571 _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_190);
			char tmp[128];
			sprintf (tmp, "%d", _val);
			fputs (tmp, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to write to log file.
// @@ _val: argv_571: the value to log after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (const char * _cptr, argv_571 _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			fputs (_cptr, argv_190);
			char tmp[128];
			sprintf (tmp, "%d", _val);
			fputs (tmp, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _level: argv_586: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: argv_586: the value to write to log file after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (argv_586 _level, const char * _cptr, argv_586 _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_190);
			char tmp[128];
			sprintf (tmp, "%u", _val);
			fputs (tmp, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to write to log file.
// @@ _val: argv_586: the value to write to log file after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (const char * _cptr, argv_586 _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			fputs (_cptr, argv_190);
			char tmp[128];
			sprintf (tmp, "%u", _val);
			fputs (tmp, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _level: argv_586: the severity level associated with the message to log.
// @@ _val_zero: argv_586: the first value to write to log file.
// @@ _val_un: argv_586: the second value to write to log file.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (argv_586 _level, argv_586 _val_zero, argv_586 _val_un) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			insert_level (_level);
			char tmp[128];
			sprintf (tmp, "%u ", _val_zero);
			fputs (tmp, argv_190);
			sprintf (tmp, "%u", _val_un);
			fputs (tmp, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _val_zero: argv_586: the first value to write to log file.
// @@ _val_un: argv_586: the second value to write to log file.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (argv_586 _val_zero, argv_586 _val_un) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			char tmp[128];
			sprintf (tmp, "%u ", _val_zero);
			fputs (tmp, argv_190);
			sprintf (tmp, "%u", _val_un);
			fputs (tmp, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _level: argv_586: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: unsigned long: the value to log after the message.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (argv_586 _level, const char * _cptr, unsigned long _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_190);
			char tmp[128];
			sprintf (tmp, "%u", _val);
			fputs (tmp, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ FUNCTION: argv_493
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to write to log file.
// @@ _val: unsigned long: the value to log after the message.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_173 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_157::argv_493 (const char * _cptr, unsigned long _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_168);
#endif
	if (argv_492 == true) {
		if (argv_190) {
			insert_date ();
			fputs (_cptr, argv_190);
			char tmp[128];
			sprintf (tmp, "%u", _val);
			fputs (tmp, argv_190);
			fputs ("\r\n", argv_190);
			fflush (argv_190);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_168);
#endif
}





