# $NetBSD$

BUILTIN_PKG:=		libatomic

BUILTIN_FIND_LIBS:=	atomic

.include "../../mk/buildlink3/bsd.builtin.mk"

.if !empty(BUILTIN_LIB_FOUND.atomic:M[yY][eE][sS])
BUILTIN_LIBNAME.libatomic=	atomic
USE_BUILTIN.libatomic=		yes
.endif
