# $NetBSD: buildlink3.mk,v 1.9 2004/04/20 21:49:38 johnrshannon Exp $

BUILDLINK_DEPTH:=       ${BUILDLINK_DEPTH}+
GCCADA_BUILDLINK3_MK:=  ${GCCADA_BUILDLINK3_MK}+
BUILDLINK_PREFIX.gccAda-3.4.0:=${LOCALBASE}/gccAda-3.4.0

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     gccAda
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:NgccAda}
BUILDLINK_PACKAGES+=    gccAda

.if !empty(GCCADA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gccAda+=      gccAda>=3.4.0
BUILDLINK_PKGSRCDIR.gccAda?=    ../../wip/gcc-3.4-ada
.endif  # GCCADA_BUILDLINK3_MK

BUILDLINK_PKGSRCDIR.gccAda?=     ../../wip/gcc-3.4-ada
BUILDLINK_CONTENTS_FILTER.gccAda= \
	${EGREP} '(libexec.*|bin.*/|include.*/|\.h$$|\.pc$$|lib.*/lib[^/]*$$)'
BUILDLINK_ENV+=$PATH:=${BUILDLINK_PREFIX.gccAda-3.4.0}:${PATH}

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gccAda+=	full
.  else
BUILDLINK_DEPMETHOD.gccAda?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
