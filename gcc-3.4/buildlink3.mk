# $NetBSD: buildlink3.mk,v 1.7 2004/04/23 22:06:15 johnrshannon Exp $

BUILDLINK_DEPTH:=       ${BUILDLINK_DEPTH}+
GCC34_BUILDLINK3_MK:=  ${GCC34_BUILDLINK3_MK}+
BUILDLINK_PREFIX.gcc-3.4.0:=${LOCALBASE}/gcc-3.4.0

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     gcc34
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:Ngcc34}
BUILDLINK_PACKAGES+=    gcc34

.if !empty(GCC34_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gcc34+=      gcc-3.4.0
BUILDLINK_PKGSRCDIR.gcc34?=    ../../wip/gcc-3.4
.endif  # GCC34_BUILDLINK3_MK

BUILDLINK_PKGSRCDIR.gcc34?=     ../../wip/gcc-3.4
BUILDLINK_CONTENTS_FILTER.gcc34= \
	${EGREP} '(libexec.*|bin.*/|include.*/|\.h$$|\.idl$$|\.pc$$|/lib[^/]*\.[^/]*$$)'
BUILDLINK_ENV+=PATH:=${BUILDLINK_PREFIX.gcc-3.4.0}:${PATH}

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc34?=	full
.  else
BUILDLINK_DEPMETHOD.gcc34?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
