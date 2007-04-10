/*
 * Compatibility hooks.
 */

/*
 * NetBSD support.
 */ 
#ifdef __NetBSD__
#define CGETENT(b, d, n)	cgetent(b, (const char * const *)d, n)
#endif	/* __NetBSD__ */

/*
 * FreeBSD support.
 */
#ifdef __FreeBSD__
#define CGETENT(b, d, n)	cgetent(b, d, n)
#endif /* __FreeBSD__ */

/*
 * DragonFly BSD support.
 */
#ifdef __DragonFly__
#define _HAVE_STRTONUM_

#define CGETENT(b, d, n)	cgetent(b, d, n)
#endif /* __DragonFly__ */

/*
 * OpenBSD support.
 */
#ifdef __OpenBSD__
#define _HAVE_STRTONUM_
#define _HAVE_SYSLOG_R_

#define CGETENT(b, d, n)	cgetent(b, d, n)
#endif	/* __OpenBSD__ */

/*
 * Missing functions.
 */
#ifndef _HAVE_STRTONUM_
static inline long long strtonum(const char *, long long, long long,
    const char **);
#include "compat/strtonum.c"
#endif /* _HAVE_STRTONUM_ */

#ifndef _HAVE_SYSLOG_R_
#define openlog_r(i, l, f, s)	openlog(i, l, f)
#define syslog_r(l, s, args...)	syslog(l, args)

#define SYSLOG_DATA_INIT	{}

struct syslog_data { char dummy; };
#endif /* _HAVE_SYSLOG_R_ */
