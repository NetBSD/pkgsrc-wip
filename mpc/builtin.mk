# $NetBSD: builtin.mk,v 1.8 2023/01/09 13:25:11 wiz Exp $

BUILTIN_PKG:=	mpc

BUILTIN_FIND_HEADERS_VAR:=	H_MPC
BUILTIN_FIND_HEADERS.H_MPC=	mpc.h

BUILTIN_VERSION_SCRIPT.mpc=	${AWK} \
				'/\#define[ \t]*MPC_VERSION_STRING[ \t]/ { \
				v = substr($$3, 2, length($$3)-2) } \
				END { gsub("-p",".",v); print v }'

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.mpc)
IS_BUILTIN.mpc=		no
.  if empty(H_MPC:M__nonexistent__) && empty(H_MPC:M${LOCALBASE}/*)
IS_BUILTIN.mpc=		yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.mpc

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.mpc) && \
    ${IS_BUILTIN.mpc:tl} == yes && \
    empty(H_MPC:M__nonexistent__)
BUILTIN_VERSION.mpc!=	${BUILTIN_VERSION_SCRIPT.mpc} ${H_MPC}
BUILTIN_PKG.mpc=	mpc-${BUILTIN_VERSION.mpc}
.endif
MAKEVARS+=		BUILTIN_PKG.mpc

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.mpc)
.  if ${PREFER.mpc} == "pkgsrc"
USE_BUILTIN.mpc=	no
.  else
USE_BUILTIN.mpc=	${IS_BUILTIN.mpc}
.    if defined(BUILTIN_PKG.mpc) && ${IS_BUILTIN.mpc:tl} == yes
USE_BUILTIN.mpc=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.mpc}
.        if ${USE_BUILTIN.mpc:tl} == yes
USE_BUILTIN.mpc!=	\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.mpc:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.mpc
.endif
MAKEVARS+=		USE_BUILTIN.mpc

CHECK_BUILTIN.mpc?=	no
.if ${CHECK_BUILTIN.mpc:tl} == no
.  if ${USE_BUILTIN.mpc:tl} == yes
MPC_INCLUDE=		${H_MPC:H}
BUILDLINK_INCDIRS.mpc=	${MPC_INCLUDE}
BUILDLINK_LIBDIRS.mpc=	lib${LIBABISUFFIX}
CPPFLAGS+=		-I${MPC_INCLUDE}
CFLAGS+=		-I${MPC_INCLUDE}
.  endif
.endif # CHECK_BUILTIN.mpc
