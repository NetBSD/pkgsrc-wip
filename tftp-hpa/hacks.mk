# $NetBSD: hacks.mk,v 1.1.1.1 2007/01/01 18:40:20 gschwarz Exp $

.if !defined(TFTP-HPA_HACKS_MK)
TFTP-HPA_HACKS_MK=	# defined

### [Sat Dec 30 22:59:04 CET 2006 : schwarz]
### configure script fails to detect availability of socklen_t on MacOS X
### and Solaris
###
.  if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
PKG_HACKS+=	socken_t-presence
CONFIGURE_ENV+=	ac_cv_type_socklen_t=yes
.  endif

### [Mon Jan  1 17:13:15 CET 2007 : schwarz]
### configure script fails to detect presence of u_short and u_long on IRIX 5
###
.  if ${OPSYS} == "IRIX"
PKG_HACKS+=	have-u_short-u_long
CONFIGURE_ENV+=	ac_cv_type_u_short=yes
CONFIGURE_ENV+=	ac_cv_type_u_long=yes
.  endif

.endif
