# $NetBSD$

BUILTIN_PKG:=	libudev

BUILTIN_FIND_HEADERS_VAR:=	LIBUDEV_H
BUILTIN_FIND_HEADERS.LIBUDEV_H=	libudev.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libudev)
IS_BUILTIN.libudev=	no
.  if empty(LIBUDEV_H:M__nonexistent__) && empty(LIBUDEV_H:M${LOCALBASE}/*)
IS_BUILTIN.libudev=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.libudev

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.libudev) && \
    !empty(IS_BUILTIN.libudev:M[yY][eE][sS]) && \
    empty(LIBUDEV_H:M__nonexistent__)

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.  if !defined(USE_BUILTIN.libudev)
.    if ${PREFER.libudev} == "pkgsrc"
USE_BUILTIN.libudev=	no
.    else
USE_BUILTIN.libudev=	${IS_BUILTIN.libudev}
.      if defined(BUILTIN_PKG.libudev) && \
        !empty(IS_BUILTIN.libudev:M[yY][eE][sS])
USE_BUILTIN.libudev=	yes
.      endif
.    endif  # PREFER.libudev
.  endif
MAKEVARS+=		USE_BUILTIN.libudev
.endif
