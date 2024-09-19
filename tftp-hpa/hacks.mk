# $NetBSD: hacks.mk,v 1.2 2007/07/17 22:19:51 gschwarz Exp $

.if !defined(TFTP-HPA_HACKS_MK)
TFTP-HPA_HACKS_MK=	# defined

### [Mon Jan  1 17:13:15 CET 2007 : schwarz]
### configure script fails to detect presence of u_short and u_long on IRIX 5
###
.if ${OPSYS} == "IRIX"
PKG_HACKS+=	have-u_short-u_long
CONFIGURE_ENV+=	ac_cv_type_u_short=yes
CONFIGURE_ENV+=	ac_cv_type_u_long=yes
.endif

.endif
