#ifndef argv_122
#define argv_122



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

#include "..\\Lib\\argv_117.hpp"
//#include "..\\Lib\\queue.hpp"
//#include "..\\Lib\\rt_queue.hpp"



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ constants declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
enum argv_543 {
    argv_527,
    argv_596,
    argv_182,
    argv_133,
    argv_176,
    argv_526,
};



const int argv_494 = 256;


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_157
// @@
// @@ DESCRIPTION:
// @@ This object permits to open a log file,
// @@ save argv_174 into it, and close it.
// @@ It can be thread safe depending on the compilation
// @@ flags you choose.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class argv_157
{
	private:
		string  argv_566;
		FILE *	argv_190;
		bool	argv_492;
#if defined (THREAD_SAFE_LOG)
		CRITICAL_SECTION argv_168;
#endif
		char argv_582[argv_494];
		SYSTEMTIME argv_583;
		void argv_592 (bool _large_mode=false);
		void insert_date ();
		void insert_level (argv_586);

	public:
		argv_157();
		virtual ~argv_157();
		bool argv_537 (string, bool _in_file=true);
		void argv_158 ();
		void argv_493 (argv_586, const char *, bool _no_eol=false);
		void argv_493 (argv_586, const char *, argv_571);
		void argv_493 (argv_586, const char *, argv_586);
		void argv_493 (argv_584);
		void argv_493 (argv_586, argv_586, argv_586);
		void argv_493 (argv_586, const char *, const char *);
		void argv_493 (argv_586, const char *, const char *, const char *);
		void argv_493 (argv_586, const char *, const char *, const char *, const char *);
		void argv_493 (argv_586, const char *, unsigned long);

		void argv_493 (argv_586, argv_586);
		void argv_493 (const char *, bool _no_eol=false);
		void argv_493 (const char *, argv_571);
		void argv_493 (const char *, argv_586);
		void argv_493 (const char *, const char *);
		void argv_493 (const char *, const char *, const char *);
		void argv_493 (const char *, const char *, const char *, const char *);
		void argv_493 (const char *, unsigned long);
		void argv_491 (const char *);
};


#endif // argv_122



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
