# $NetBSD: builtin.mk,v 1.1 2004/06/13 19:07:49 xtraeme Exp $

.if !defined(IS_BUILTIN.libXau)
IS_BUILTIN.libXau=	no
.  if exists(${X11BASE}/include/X11/Xauth.h)
IS_BUILTIN.libXau=	yes
.  endif
.endif  # IS_BUILTIN.libXau

USE_BUILTIN.libXau?=	${IS_BUILTIN.libXau}

.if !empty(IS_BUILTIN.libXau:M[Nn][Oo])
.  include "../../wip/xproto/buildlink3.mk"
.endif
