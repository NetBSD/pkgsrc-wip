# $NetBSD: builtin.mk,v 1.1 2004/06/24 22:11:45 ppostma Exp $

.if !defined(IS_BUILTIN.pf-lkm)
IS_BUILTIN.pf-lkm=	no
.  if exists(/usr/include/net/pfvar.h)
IS_BUILTIN.pf-lkm=	yes
.  endif
.endif  # IS_BUILTIN.pf-lkm

USE_BUILTIN.pf-lkm?=	${IS_BUILTIN.pf-lkm}
