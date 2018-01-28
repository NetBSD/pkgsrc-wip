# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:41 jsonn Exp $

BUILDLINK_PREFIX.gcc43:=	${LOCALBASE}/gcc43

BUILDLINK_TREE+=	gcc43

.if !defined(GCC43_BUILDLINK3_MK)
GCC43_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc43+=	gcc43>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc43?=	gcc43>=4.3.0
BUILDLINK_PKGSRCDIR.gcc43?=	../../wip/gcc43
.if exists(${BUILDLINK_PREFIX.gcc43}/bin/gcc)
_GNAT1!=			${BUILDLINK_PREFIX.gcc43}/bin/gcc -print-prog-name=gnat1
.  if exists(${_GNAT1})
BUILDLINK_ENV+=			ADAC=${BUILDLINK_PREFIX.gcc43}/bin/gcc
.  endif
BUILDLINK_LIBDIRS.gcc43+=	lib
_GCC_ARCHDIR!=			${DIRNAME} `${BUILDLINK_PREFIX.gcc43}/bin/gcc --print-libgcc-file-name`
.  if empty(_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc43+=	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc43}\///}/
.    if exists(${_GNAT1})
BUILDLINK_LIBDIRS.gcc43+=	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc43}\///}/adalib
.    endif
BUILDLINK_INCDIRS.gcc43+=	include ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc43}\///}/include
.  endif
.endif

BUILDLINK_FILES_CMD.gcc43=	\
	(cd  ${BUILDLINK_PREFIX.gcc43} &&	\
	${FIND} bin libexec lib \( -type f -o -type l \) -print)
BUILDLINK_FNAME_TRANSFORM.gcc43=	-e s:\buildlink:buildlink/gcc43:

# Packages that link against shared libraries need a full dependency.
.if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc+=	full
.else
BUILDLINK_DEPMETHOD.gcc?=	build
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # GCC43_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc43
