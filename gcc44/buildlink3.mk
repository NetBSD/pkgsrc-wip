# $NetBSD: buildlink3.mk,v 1.1 2009/05/27 14:17:01 corecode Exp $

BUILDLINK_PREFIX.gcc44:=${LOCALBASE}/gcc44

BUILDLINK_TREE+=	gcc44

.if !defined(GCC44_BUILDLINK3_MK)
GCC44_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc44+=	gcc44>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc44?=	gcc44>=4.4.0
BUILDLINK_PKGSRCDIR.gcc44?=	../../wip/gcc44
.  if exists(${BUILDLINK_PREFIX.gcc44}/bin/gcc)
_GNAT1!=${BUILDLINK_PREFIX.gcc44}/bin/gcc -print-prog-name=gnat1
.    if exists(${_GNAT1})
BUILDLINK_ENV+=	ADAC=${BUILDLINK_PREFIX.gcc44}/bin/gcc
.    endif
BUILDLINK_LIBDIRS.gcc44+=	lib
_GCC_ARCHDIR!=	${DIRNAME} `${BUILDLINK_PREFIX.gcc44}/bin/gcc --print-libgcc-file-name`
.    if empty(_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc44+=	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc44}\///}/
.      if exists(${_GNAT1})
BUILDLINK_LIBDIRS.gcc44+=	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc44}\///}/adalib
.      endif
BUILDLINK_INCDIRS.gcc44+=	include ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc44}\///}/include
.    endif
.  endif

BUILDLINK_FILES_CMD.gcc44=	\
	(cd  ${BUILDLINK_PREFIX.gcc44} &&	\
	${FIND} bin libexec lib \( -type f -o -type l \) -print)
BUILDLINK_FNAME_TRANSFORM.gcc44=	-e s:\buildlink:buildlink/gcc44:

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc+=	full
.  else
BUILDLINK_DEPMETHOD.gcc?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # GCC44_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc44
