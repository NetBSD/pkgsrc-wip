# $NetBSD: buildlink3.mk,v 1.10 2004/05/12 20:23:03 johnrshannon Exp $

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
BUILDLINK_ENV+=	PATH=${PATH}:${LOCALBASE}/gcc-3.4.0/bin
BUILDLINK_ENV+=	ADA_INCLUDE_PATH=${LOCALBASE}/gcc-3.4.0/lib/gcc/i386--netbsdelf2.0/3.4.0/adainclude
BUILDLINK_ENV+=	ADA_OBJECT_PATH=${LOCALBASE}/gcc-3.4.0/lib/gcc/i386--netbsdelf2.0/3.4.0/adalib
BUILDLINK_RPATHDIRS.gcc+=	${LOCALBASE}/gcc-3.4.0/lib
BUILDLINK_RPATHDIRS.gcc+=	${LOCALBASE}/lib/gcc/i386--netbsdelf2.0/3.4.0/adalib
BUILDLINK_RPATHDIRS.gcc+=	${LOCALBASE}/lib/gcc/i386--netbsdelf2.0/3.4.0
.endif  # GCC34_BUILDLINK3_MK

BUILDLINK_PKGSRCDIR.gcc34?=     ../../wip/gcc-3.4
BUILDLINK_CONTENTS_FILTER.gcc34= \
	${EGREP} '(bin.*/|include.*/|\.h$$|\.idl$$|\.pc$$|/lib[^/]*\.[^/]*$$)'
BUILDLINK_TRANSFORM.gcc34=	-e s,/gcc-3.4.0/bin/gnat,/bin/gnat,

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc34?=	full
.  else
BUILDLINK_DEPMETHOD.gcc34?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
