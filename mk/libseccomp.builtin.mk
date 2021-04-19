# $NetBSD$
#

BUILTIN_PKG:=	libseccomp

BUILTIN_FIND_LIBS:=		seccomp
BUILTIN_FIND_HEADERS_VAR:=	H_SECCOMP
BUILTIN_FIND_HEADERS.H_SECCOMP=	seccomp.h seccomp-syscalls.h

BUILTIN_FIND_PKGCONFIG_FILES_VAR=		LIBSECCOMP
BUILTIN_FIND_PKGCONFIG_FILES.LIBSECCOMP=	libseccomp.pc

.include "../../mk/buildlink3/bsd.builtin.mk"

.if empty(H_SECCOMP:M__nonexistent__) && \
    !empty(BUILTIN_LIB_FOUND.seccomp:M[yY][eE][sS])
IS_BUILTIN.libseccomp=		yes
BUILTIN_LIBNAME.libseccomp=	seccomp
BUILTIN_INCDIRS.libseccomp=	${H_SECCOMP:H}
.else
IS_BUILTIN.libseccomp=		no
.endif

MAKEVARS+=	IS_BUILTIN.libseccomp

.if !defined(USE_BUILTIN.libseccomp)
USE_BUILTIN.libseccomp=	${IS_BUILTIN.libseccomp}
.endif

CHECK_BUILTIN.libseccomp?=	no
.if empty(CHECK_BUILTIN.libseccomp:M[Nn][Oo])
.  if !empty(USE_BUILTIN.libseccomp:M[Yy][Ee][Ss])
BUILDLINK_LIBNAME.libseccomp=	${BUILTIN_LIBNAME.libseccomp}
BUILDLINK_INCDIRS.libseccomp=	${BUILTIN_INCDIRS.libseccomp}
.  endif

BUILDLINK_TARGETS+=	buildlink-libseccomp
.PHONY:	buildlink-libseccomp
buildlink-libseccomp:
	${RUN}
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig
	${LN} -s /usr/lib/pkgconfig/libseccomp.pc ${BUILDLINK_DIR}/lib/pkgconfig/libseccomp.pc

.endif #CHECK_BUILTIN.libseccomp
