# $NetBSD: buildlink3.mk,v 1.2 2004/04/20 23:24:01 johnrshannon Exp $

BUILDLINK_DEPTH:=       ${BUILDLINK_DEPTH}+
GCC_BUILDLINK3_MK:=     ${GCC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     gcc
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:Ngcc}
BUILDLINK_PACKAGES+=    gcc
BUILDLINK_PREFIX.gcc-3.4.0:=${LOCALBASE}/gcc-3.4.0

.if !empty(GCC_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gcc+= gcc>=3.4.0
BUILDLINK_PKGSRCDIR.gcc?=       ../../wip/gcc-3.4
.endif  # GCC_BUILDLINK3_MK

BUILDLINK_CONTENTS_FILTER.gcc= \
	${EGREP} '(libexec.*|bin.*/|include.*/|\.h$$|\.pc$$|lib.*/lib[^/]*$$)'
BUILDLINK_ENV+=$PATH:=${BUILDLINK_PREFIX.gcc-3.4.0}:${PATH}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc-3.4.0+= full
.  else
BUILDLINK_DEPMETHOD.gcc-3.4.0?= build
.  endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
