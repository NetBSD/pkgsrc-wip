# $NetBSD: buildlink3.mk,v 1.17 2004/05/26 22:02:12 johnrshannon Exp $

BUILDLINK_DEPTH:=       ${BUILDLINK_DEPTH}+
GCC34_BUILDLINK3_MK:=  ${GCC34_BUILDLINK3_MK}+
BUILDLINK_PREFIX.gcc-3.4:=${LOCALBASE}/gcc-3.4.0

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     gcc-3.4
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:Ngcc-3.4}
BUILDLINK_PACKAGES+=    gcc-3.4

.if !empty(GCC34_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gcc-3.4+=      gcc-3.4.0
BUILDLINK_PKGSRCDIR.gcc-3.4?=    ../../wip/gcc-3.4
_GNAT1!=${LOCALBASE}/gcc-3.4.0/bin/gcc -print-prog-name=gnat1
.  if exists(${_GNAT1})
BUILDLINK_ENV+=	ADAC=${LOCALBASE}/gcc-3.4.0/bin/gcc
.  endif
_GCC_ARCHDIR!=	${DIRNAME} `${LOCALBASE}/gcc-3.4.0/bin/gcc --print-libgcc-file-name`
.  if empty(_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc-3.4+=	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc-3.4.0}\///}/
.    if exists(${_GNAT1})
BUILDLINK_LIBDIRS.gcc-3.4+=	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc-3.4.0}\///}/adalib
.    endif
BUILDLINK_INCDIRS.gcc-3.4+=	include ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc-3.4.0}\///}/include
.  endif
.endif  # GCC34_BUILDLINK3_MK

BUILDLINK_PKGSRCDIR.gcc-3.4?=     ../../wip/gcc-3.4
BUILDLINK_CONTENTS_FILTER.gcc-3.4= \
	${EGREP} '(libexec.*|bin.*/|include.*/|\.h$$|\.pc$$|lib.*/lib[^/]*$$|ada.*path)'

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc-3.4?=	full
.  else
BUILDLINK_DEPMETHOD.gcc-3.4?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
