# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/07 15:59:57 keckhardt Exp $

BUILDLINK_TREE+=	gcc47

.if !defined(GCC47_BUILDLINK3_MK)
GCC47_BUILDLINK3_MK:=

FIND_PREFIX:=	BUILDLINK_PREFIX.gcc47=gcc47
.include "../../mk/find-prefix.mk"

_GCC47_SUBDIR=	gcc47
_GCC47_PREFIX=	${BUILDLINK_PREFIX.gcc47}/${_GCC47_SUBDIR}

BUILDLINK_API_DEPENDS.gcc47+=	gcc47>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc47?=	gcc47>=4.7.0
BUILDLINK_PKGSRCDIR.gcc47?=	../../lang/gcc47

.if exists(${_GCC47_PREFIX}/bin/gcc)

# logic for detecting the ADA compiler (not yet supported)
#gcc47_GNAT1!=${_GCC47_PREFIX}/bin/gcc -print-prog-name=gnat1
#.  if exists(${gcc47_GNAT1})
#CONFIGURE_ENV+=	ADAC=${_GCC47_PREFIX}/bin/gcc
#MAKE_ENV+=	ADAC=${_GCC47_PREFIX}/bin/gcc
#.  endif

# add libraries
BUILDLINK_LIBDIRS.gcc47+=	${_GCC47_SUBDIR}/lib

# find the gcc architecture
gcc47_GCC_ARCHDIR!=	${DIRNAME} `${_GCC47_PREFIX}/bin/gcc --print-libgcc-file-name`

# add the architecture dep libraries
.  if empty(gcc47_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc47+=	${gcc47_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc47}\///}/

# add the ada libraries (not yet supported)
#.    if exists(${gcc47_GNAT1})
#BUILDLINK_LIBDIRS.gcc47+=	${gcc47_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc47}\///}/adalib
#.    endif

# add the header files
BUILDLINK_INCDIRS.gcc47+=	${_GCC47_SUBDIR}/include ${gcc47_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc47}\///}/include
.  endif
.endif

BUILDLINK_FILES_CMD.gcc47=	\
	(cd  ${BUILDLINK_PREFIX.gcc47} &&	\
	${FIND} ${_GCC47_SUBDIR}/bin ${_GCC47_SUBDIR}/libexec ${_GCC47_SUBDIR}/lib \( -type f -o -type l \) -print)
BUILDLINK_FNAME_TRANSFORM.gcc47=	-e s:buildlink:buildlink/gcc47:

# Packages that link against shared libraries need a full dependency.
.if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc47+=	full
.else
BUILDLINK_DEPMETHOD.gcc47?=	build
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # GCC47_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc47
