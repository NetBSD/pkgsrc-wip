# $NetBSD: buildlink3.mk,v 1.18 2004/05/26 22:00:19 johnrshannon Exp $

BUILDLINK_DEPTH:=       ${BUILDLINK_DEPTH}+
GCCADA_BUILDLINK3_MK:=  ${GCCADA_BUILDLINK3_MK}+
BUILDLINK_PREFIX.gccAda-3.4.0:=${LOCALBASE}/gccAda-3.4.0

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     gccAda-3.4.0
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:NgccAda-3.4.0}
BUILDLINK_PACKAGES+=    gccAda-3.4.0

.if !empty(GCCADA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gccAda-3.4.0+=      gccAda>=3.4.0
BUILDLINK_PKGSRCDIR.gccAda-3.4.0?=    ../../wip/gcc-3.4-ada
BUILDLINK_ENV+= ADAC=${LOCALBASE}/gccAda-3.4.0/bin/gcc
_GCC_ARCHDIR!=	${DIRNAME} `${LOCALBASE}/gccAda-3.4.0/bin/gcc --print-libgcc-file-name`
.  if empty(_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gccAda-3.4.0+=       lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gccAda-3.4.0}\///}
BUILDLINK_LIBDIRS.gccAda-3.4.0+=       ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gccAda-3.4.0}\///}/adalib
BUILDLINK_INCDIRS.gccAda-3.4.0+=       include ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gccAda-3.4.0}\///}/adainclude
.  endif
.endif  # GCCADA_BUILDLINK3_MK

BUILDLINK_PKGSRCDIR.gccAda-3.4.0?=     ../../wip/gccAda-3.4.0
BUILDLINK_CONTENTS_FILTER.gccAda-3.4.0= \
	${EGREP} '(libexec.*|bin.*/|include.*/|\.h$$|\.pc$$|lib.*/lib[^/]*$$|ada.*path)'

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gccAda-3.4.0?=	full
.  else
BUILDLINK_DEPMETHOD.gccAda-3.4.0?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
