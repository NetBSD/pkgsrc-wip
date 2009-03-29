
/*
 * LIB/CONFIG.H
 *
 *
 * USE_BSTRING	- define if <bstring.h> must be included to get bcopy() and
 *		  related prototypes.
 *
 *
 * NOTE REGARDING USE_SMALL_HASH .. If you wish to set this to continue to
 * use small 1 million entry hash tables, set it in lib/vendor.h.  As of
 * Diablo V1.10, the default dhistory hash table size will be 4 million
 * entries.
 *
 * NOTE REGARDING CHANGING FEATURES:  Change these features in LIB/VENDOR.H,
 * do *NOT* change these features here unless you are editing this file for
 * submission back to me.  When adding special features as defaults, the 
 * operating system version must be explicitly tested.
 *
 * General notes:
 *
 *	IRIX 6.2 or greater, FreeBSD 2.2 or greater, and Sun/Solaris should
 *	be able to handle most mmap/shm features, but they have only been tested
 *	on FreeBSD.  Due to the way the code uses READ+WRITE maps, msync() 
 *	is irrelevant so you don't have to worry about that.
 *
 *	All versions of BSDI including 3.0 are known to have serious mmap
 *	problems even for read-only maps and Diablo may crash the kernel.
 *
 * Special Features:
 *
 *	USE_PCOMMIT_RW_MAP	if mmap() supports shared r+w mmaps, this
 *				causes diablo to update the precommit cache
 *			   	directly rather then with an lseek/write,
 *				which can reduce filesystem contention.
 *
 *	USE_PCOMMIT_SHM		Diablo will use SYSV shared memory for the
 *				precommit cache.  USE_PCOMMIT_RW_MAP is also
 *				required if you set this option (but it will
 *				use SYSV shared memory rather then mmap())
 *
 *	USE_SPAM_RW_MAP		if mmap() supports shared r+w mmaps, this
 *				causes diablo to update the spam cache
 *			   	directly rather then with an lseek/write,
 *				which can reduce filesystem contention.
 *
 *	USE_SPAM_SHM		Diablo will use SYSV shared memory for the
 *				spam cache.  USE_SPAM_RW_MAP is also required
 *				if you set this option (but it will use
 *				SYSV shared memory rather then mmap()).
 *
 *	USE_CANCEL_SHM		Diablo reader will use a shared memory segment
 *				to cache cancels that occur prior to article
 *				reception.
 *
 *	DO_PCOMMIT_POSTCACHE	use the precommit cache as a recent-history
 *				cache.  Suggested only if USE_PCOMMIT_RW_MAP
 *				or USE_PCOMMIT_SHM are set.
 *
 *	USE_KP_RW_MAP		Use a read+write mmap for key-pair database
 *				operations.
 *
 *	USE_ANON_MMAP		lib/alloc.c uses MAP_ANON mmap's to allocate 
 *				private memory.
 *
 *	USE_ZERO_MMAP		lib/alloc.c uses MAP_PRIVATE on /dev/zero to
 *				allocate private memory.
 *
 *	USE_FALL_MMAP		lib/alloc.c uses MAP_PRIVATE mmaps on a
 *				temporary file to allocate private memory.
 *				(note: the memory winds up being swap-backed
 *				just like MAP_ANON).
 *
 *				If neither option is set, memory is allocated
 *				with malloc()/free() but this is not 
 *				recommended if you run more then 10 feeds.
 *
 *	USE_MADVISE		article mappings call madvise() to premap
 *				pages.  MADV_WILLNEED must be supported.
 *
 *	DIABLO_FILTER		Enable/Disable Joe Greco's diablo-filter 
 *				support (it is off by default).
 *
 *	MMAP_DOES_NOT_UPDATE_ATIME Enable a single read to update cache atime
 *
 */

/*
 * Edit here
 */

/********************************************************
 * 			FREEBSD				*
 ********************************************************
 *
 * FreeBSD-3.0 or greater has depreciated sys/dir.h.  Since all FreeBSD 
 * versions support dirent.h we just use it.
 */

#ifdef __FreeBSD__
#if __FreeBSD__ >= 2
#include <osreldate.h>
#if __FreeBSD_version >= 222001
#define USE_MADVISE		1	/* new (test) - premap article pte's */
#define USE_SYSV_DIR		1	/* use more portable dirent.h (1)*/
#define USE_PCOMMIT_SHM		1	/* use sharedmem r/w map vs file map */
#define USE_PCOMMIT_RW_MAP	1	/* use r/w map for pcommit cache */
#define USE_SPAM_SHM		1	/* use sharedmem r/w map vs file map */
#define USE_SPAM_RW_MAP		1	/* use r/w map for spam cache	 */
#define USE_KP_RW_MAP		1	/* use r/w map for KPDB		 */
#define USE_ANON_MMAP		1	/* use anonymous mmap for alloc  */
#define DO_PCOMMIT_POSTCACHE	1	/* do precommit post caching	 */
#define HAS_UTIMES		1	/* human readability only	 */
#define HAS_USLEEP		1	/* < 1 second sleeps		 */
#define HAS_PROC_TITLE		1
#define HAS_SA_LEN		1
#define MMAP_DOES_NOT_UPDATE_ATIME 1	/* use read to update atime	 */
#if __FreeBSD_version >= 300003
#define USE_POLL		1	/* poll() syscall		 */
#endif
#if __FreeBSD_version < 400000
#define USE_POLLEXTEND		1	/* poll() syscall		 */
#endif
#endif
#endif
#endif

/********************************************************
 * 			BSDI				*
 ********************************************************
 *
 */

#ifdef __bsdi__
#include <sys/param.h>
#if _BSDI_VERSION >= 199701
#define USE_KP_RW_MAP		1	/* use r/w map for KPDB		 */
#define USE_SPAM_SHM            1
#define USE_SPAM_RW_MAP         1
#define USE_PCOMMIT_SHM         1
#define USE_PCOMMIT_RW_MAP      1
#define DO_PCOMMIT_POSTCACHE    1
#define USE_ANON_MMAP           1
#define HAS_USLEEP           	1
#else
#error "Upgrade to BSDI3.0 and the first jumbo patch.  mmap is broken on earlier releases"
#endif  /* _BSDI_VERSION >= 199701 */
#endif  /* __bsdi__ */

/********************************************************
 * 			SGI				*
 ********************************************************
 *
 */

#ifdef sgi

#define FDPASS_USES_CMSG	0	/* SGI's fd passing is simplistic*/
#define USE_PCOMMIT_SHM		1	/* precommit cache in sysv shared mem*/
#define DO_PCOMMIT_POSTCACHE	1	/* do precommit post caching	 */
#define USE_BSTRING_H		1
#define USE_SYSV_SETPGRP	1
#define USE_SYSV_STATFS		1
#define HAVE_SNPRINTF		0

#define USE_ANON_MMAP		0
#define USE_FALL_MMAP		1

#endif

/********************************************************
 * 			SUNOS/SOLARIS			*
 ********************************************************
 *
 */

#ifdef sun

#if !defined(__SVR4)

/*
 * sunos
 */

#undef  USE_SYSV_SETPGRP
#undef  USE_SYSV_STATFS
#define USE_SYSV_SIGNALS        0

#define USE_SYSV_DIR            1
#define USE_SYS_VFS         	1
#define NEED_TERMIOS            1       /* for TIOCNOTTY */
#define USE_ANON_MMAP           0
#define USE_FALL_MMAP           1
#define USE_STRERROR            1
#define USE_MEMMOVE             1
#define HAVE_SNPRINTF           0

#else

/*
 * solaris
 */

#define FDPASS_USES_CMSG	0	/* solaris uses a different	*/
#define FDPASS_USES_ACC		1	/* structural field names	*/

#define USE_PCOMMIT_SHM		1	/* precommit cache in sysv shmem */
#define DO_PCOMMIT_POSTCACHE	1	/* do precommit post caching	 */
#define USE_PCOMMIT_RW_MAP	1
#define USE_SPAM_SHM		1	/* use sharedmem r/w map vs file map */
#define USE_SPAM_RW_MAP		1	/* use r/w map for spam cache	 */
#define USE_SYSV_DIR		1
#define USE_SYSV_SETPGRP	1
#define USE_SUN_STATVFS		1
#define USE_SYSV_SIGNALS	1
#define USE_STRINGS_H		1
#define HAVE_SNPRINTF		1
#define HAVE_STRSEP		0
#define NEED_TERMIOS		1	/* for TIOCNOTTY */
#define USE_POLL		1	/* poll() syscall		 */
#define HAS_USLEEP		1	/* < 1 second sleeps		 */

#define USE_ANON_MMAP		0
#define USE_ZERO_MMAP		1

#define SENDMAIL_PATH         "/usr/lib/sendmail"

#endif
#endif

/********************************************************
 * 			    LINUX			*
 ********************************************************
 *
 */

#ifdef __linux__
#include <linux/version.h>
#ifdef LINUX_VERSION_CODE

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,4,0)
#define USE_MADVISE           1       /* new (test) - premap article pte's */
#endif  /* _KERNEL_VERSION >= 2.4.0 */

#else
#warning "linux/versionh was not found, perhaps you will have to set options"
#warning "by hand in lib/config.h"
#endif
#define USE_SYSV_SETPGRP	1
#define USE_SYS_VFS		1
#define USE_PCOMMIT_SHM		1	/* use sharedmem r/w map vs file map */
#define USE_PCOMMIT_RW_MAP	1	/* use r/w map for pcommit cache */
#define USE_SPAM_SHM		1	/* use sharedmem r/w map vs file map */
#define USE_SPAM_RW_MAP		1	/* use r/w map for spam cache   */
#define USE_KP_RW_MAP		1	/* use r/w map for KPDB		 */
#define DO_PCOMMIT_POSTCACHE	1	/* do precommit post caching    */
#define USE_ANON_MMAP		1
#define USE_FALL_MMAP		0
#define HAVE_SNPRINTF		1
#define USE_POLL		1	/* poll() syscall		 */
#define HAS_USLEEP		1	/* < 1 second sleeps		 */

#endif

/********************************************************
 * 			     AIX			*
 ********************************************************
 *
 */

/* AIX notes: snprintf() exists in 4.2 and later. */

#ifdef _AIX
#define USE_INTERNAL_VSYSLOG	1
#define USE_BSTRING_H           0
#define USE_SYSV_DIR		1
#define USE_SYSV_SETPGRP        1
#define USE_SYSV_STATFS         0
#define USE_SYSV_SIGNALS        1
#define HAVE_SNPRINTF           1
#define	HAVE_STRSEP		0
#define USE_ANON_MMAP           1
#define USE_FALL_MMAP           0
#endif

/********************************************************
 * 			HPUX				*
 ********************************************************
 *
 */

#ifdef __hpux

#define USE_INTERNAL_VSYSLOG	1
#define USE_SUN_STATVFS		1
#define USE_SYSV_SETPGRP	1
#define NEED_TERMIOS            1
#define USE_TIOCNOTTY		0
#define FDPASS_USES_CMSG	0
#define FDPASS_USES_ACC		1

/*
 * HPUX B.11.00 A 9000/813 2007703786, at least, has a totally
 * broken non-blocking listen()/accept().  If you set a listen descriptor
 * for non-blocking, any descriptors returned from an accept() on that
 * socket WILL BE SET NON-BLOCKING *AND* CANNOT BE CHANGED BACK TO BLOCKING
 * WITH FCNTL()!!!
 */

#define NONBLK_ACCEPT_BROKEN	1


#endif

/********************************************************
 * 			OSF/Tru64			*
 ********************************************************
 *
 */

#ifdef __osf__

#include <sys/bitypes.h>

uint64_t		i;

#define FDPASS_USES_CMSG	0	/* solaris uses a different	*/
#define FDPASS_USES_ACC		1	/* structural field names	*/
#define USE_MADVISE		1	/* new (test) - premap article pte's */
#define USE_SYSV_DIR		1	/* use more portable dirent.h (1)*/
#define USE_PCOMMIT_SHM		1	/* use sharedmem r/w map vs file map */
#define USE_PCOMMIT_RW_MAP	1	/* use r/w map for pcommit cache */
#define USE_SPAM_SHM		1	/* use sharedmem r/w map vs file map */
#define USE_SPAM_RW_MAP		1	/* use r/w map for spam cache	 */
#define USE_KP_RW_MAP		1	/* use r/w map for KPDB		 */
#define USE_ANON_MMAP		1	/* use anonymous mmap for alloc  */
#define	USE_INTERNAL_VSYSLOG	1
#define DO_PCOMMIT_POSTCACHE	1	/* do precommit post caching	 */
#define HAS_UTIMES		1	/* human readability only	 */
#define HAS_USLEEP		1	/* < 1 second sleeps		 */
#define HAVE_STRSEP		0
#define USE_POLL		1	/* poll() syscall		 */
#endif

/********************************************************
 * 			NETBSD				*
 ********************************************************
 *
 * Experimental NetBSD support.
 */

#ifdef __NetBSD__
#define USE_MADVISE		1	/* new (test) - premap article pte's */
#define USE_SYSV_DIR		1	/* use more portable dirent.h (1)*/
#define USE_PCOMMIT_SHM		1	/* use sharedmem r/w map vs file map */
#define USE_PCOMMIT_RW_MAP	1	/* use r/w map for pcommit cache */
#define USE_SPAM_SHM		1	/* use sharedmem r/w map vs file map */
#define USE_SPAM_RW_MAP		1	/* use r/w map for spam cache	 */
#define USE_KP_RW_MAP		1	/* use r/w map for KPDB		 */
#define USE_ANON_MMAP		1	/* use anonymous mmap for alloc  */
#define USE_SUN_STATVFS		1
#define DO_PCOMMIT_POSTCACHE	1	/* do precommit post caching	 */
#define HAS_USLEEP		1	/* < 1 second sleeps		 */
#define HAS_SA_LEN		1
#define HAVE_SNPRINTF           1
#define	HAVE_STRSEP		1
#define USE_POLL		1	/* poll() syscall		 */

#include "lib/vendor.h"

/************************************************************************
 *		CLEANUP - set defaults for unspecified options		*
 *			(DO NOT EDIT BELOW THIS LINE)			*
 ************************************************************************/

#ifndef USE_BSTRING_H
#define USE_BSTRING_H		0
#endif
#ifndef USE_SYSV_DIR
#define USE_SYSV_DIR		0
#endif
#ifndef USE_SYSV_SIGNALS
#define USE_SYSV_SIGNALS	0
#endif
#ifndef USE_SYSV_SETPGRP
#define USE_SYSV_SETPGRP	0
#endif
#ifndef USE_SYSV_STATFS
#define USE_SYSV_STATFS		0
#endif
#ifndef USE_SYS_VFS
#define USE_SYS_VFS		0
#endif
#ifndef USE_STRINGS_H
#define USE_STRINGS_H		0
#endif
#ifndef USE_SUN_STATVFS
#define USE_SUN_STATVFS		0
#endif
#ifndef HAVE_SNPRINTF
#define HAVE_SNPRINTF		1
#endif
#ifndef HAVE_STRSEP
#define HAVE_STRSEP		1
#endif
#ifndef USE_ANON_MMAP
#define USE_ANON_MMAP		0
#endif
#ifndef USE_FALL_MMAP
#define USE_FALL_MMAP		1
#endif
#ifndef USE_MADVISE
#define USE_MADVISE		0
#endif
#ifndef USE_ZERO_MMAP
#define USE_ZERO_MMAP		0
#endif
#ifndef USE_STRERROR
#define USE_STRERROR		0
#endif
#ifndef NEED_TERMIOS
#define NEED_TERMIOS		0
#endif
#ifndef USE_PCOMMIT_RW_MAP
#define USE_PCOMMIT_RW_MAP	0
#endif
#ifndef USE_PCOMMIT_SHM
#define USE_PCOMMIT_SHM		0
#endif
#ifndef USE_SPAM_RW_MAP
#define USE_SPAM_RW_MAP		0
#endif
#ifndef USE_KP_RW_MAP
#define USE_KP_RW_MAP		0
#endif
#ifndef HAS_PROC_TITLE
#define HAS_PROC_TITLE		0
#endif
#ifndef HAS_SA_LEN
#define HAS_SA_LEN		0
#endif
#ifndef USE_SPAM_SHM
#define USE_SPAM_SHM		1	/* required for lib/seq.c */
#endif
#ifndef USE_CANCEL_SHM
#define USE_CANCEL_SHM		1	/* default enabled	  */
#endif
#ifndef DO_PCOMMIT_POSTCACHE
#define DO_PCOMMIT_POSTCACHE	0
#endif
#ifndef COMPILE_DREADERD
#define COMPILE_DREADERD	1
#endif

/*
 * Default file descriptor passing uses standard cmsghdr structure.  If this
 * structure does not exist and the proper defines have not been set above,
 * I'd rather we get a compile-time error then have it not work at run time.
 */

#ifndef FDPASS_USES_CMSG
#define FDPASS_USES_CMSG	1
#endif

#ifndef FDPASS_USES_ACC
#define FDPASS_USES_ACC		0
#endif

#ifndef NONBLK_ACCEPT_BROKEN
#define NONBLK_ACCEPT_BROKEN	0
#endif

#ifndef ACCEPT_ARG3_TYPE
#define ACCEPT_ARG3_TYPE	int
#endif
#ifndef HAS_UTIMES
#define HAS_UTIMES		0
#endif
#ifndef HAS_USLEEP
#define HAS_USLEEP		0
#endif

#ifndef USE_INTERNAL_SNPRINTF
#define USE_INTERNAL_SNPRINTF	0
#endif
#ifndef USE_MEMCOPY
#define USE_MEMCOPY		0
#endif
#ifndef USE_MEMMOVE
#define USE_MEMMOVE		0
#endif
#ifndef USE_INTERNAL_VSYSLOG
#define USE_INTERNAL_VSYSLOG	0
#endif
#ifndef USE_TIOCNOTTY
#define USE_TIOCNOTTY		1
#endif
#ifndef USE_POLL
#define USE_POLL		0
#endif
#ifndef DIABLO_FILTER
#define DIABLO_FILTER		0
#endif

/*
 * Crypto Support
 *
 *	PGP	pgpverify control infrastructure support
 *	DGP	experimental attempt at a new standard
 */

#ifndef DIABLO_PGP_SUPPORT
#define DIABLO_PGP_SUPPORT	1
#endif

#ifndef DIABLO_DGP_SUPPORT
#define DIABLO_DGP_SUPPORT	1
#endif

/*
 * location of pgpverify
 */

#ifndef PGP_VERIFY_PATH
#define PGP_VERIFY_PATH		"%s/dbin/pgpverify"
#endif
#ifndef PGP_VERIFY_ARG0
#define PGP_VERIFY_ARG0		"pgpverify"
#endif
#ifndef PGP_PATH
#define PGP_PATH		"/usr/local/bin/pgp"
#endif
#ifndef PGP_ARG0
#define PGP_ARG0		"pgp"
#endif
#ifndef SENDMAIL_PATH
#define SENDMAIL_PATH		"/usr/sbin/sendmail"
#endif
#ifndef SENDMAIL_ARG0
#define SENDMAIL_ARG0		"sendmail"
#endif
#ifndef NEWSMASTER
#define NEWSMASTER		"usenet"
#endif

/*
 * force r+w maps if sysv shared memory is used
 * for the caches.  Code won't work otherwise.
 */

#if USE_SPAM_SHM
#undef USE_SPAM_RW_MAP
#define USE_SPAM_RW_MAP		1
#endif

#if USE_PCOMMIT_SHM
#undef USE_PCOMMIT_RW_MAP
#define USE_PCOMMIT_RW_MAP	1
#endif

#ifndef USE_ZLIB
#define	gzFile	int
#endif
