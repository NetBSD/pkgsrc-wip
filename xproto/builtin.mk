# $NetBSD: builtin.mk,v 1.1 2004/06/13 19:07:50 xtraeme Exp $

.if !defined(IS_BUILTIN.xproto)
IS_BUILTIN.xproto=	no
.  if exists(${X11BASE}/include/X11/xproto.h)
IS_BUILTIN.xproto=	yes
.  endif
.endif  # IS_BUILTIN.xproto

USE_BUILTIN.xproto?=	${IS_BUILTIN.xproto}
