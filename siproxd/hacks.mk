# $NetBSD: hacks.mk,v 1.1 2007/01/21 09:18:22 gschwarz Exp $

.if !defined(SIPROXD_HACKS_MK)
SIPROXD_HACKS_MK=	# defined

### [Sunday January  7 15:09:27 MET 2007 : schwarz]
### Solaris (prior to Solaris 9) has inet_ntop in llib-lresolv,
### but proper header files and some defines are missing
###
.if ${OPSYS} == "SunOS"
.  if ${OS_VERSION} < 5.9
PKG_HACKS+=	no-proper-inet_ntop
CONFIGURE_ENV+=	ac_cv_func_inet_ntop="no"
.  endif
.endif

.endif
