# $NetBSD: builtin.mk,v 1.2 2004/10/25 09:54:06 ppostma Exp $

.if !defined(IS_BUILTIN.pflkm)
IS_BUILTIN.pflkm=	no
.  if exists(/usr/include/net/pfvar.h)
IS_BUILTIN.pflkm=	yes
.  endif
.endif  # IS_BUILTIN.pflkm

USE_BUILTIN.pflkm?=	${IS_BUILTIN.pflkm}
