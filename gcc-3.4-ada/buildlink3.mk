# $NetBSD: buildlink3.mk,v 1.7 2004/03/13 20:44:56 minskim Exp $

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH}+
GCC-3.4-ADA_BUILDLINK3_MK:=   ${GCC-3.4-ADA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=   gccAda-3.4
.endif

BUILDLINK_PACKAGES:=  ${BUILDLINK_PACKAGES:NgccAda-3.4}
BUILDLINK_PACKAGES+=  gccAda-3.4

.if !empty(GCC-3.4-ADA_BUILDLINK3_MK:M+)
.  if defined(GCC34_INSTALLTO_SUBPREFIX)
.    if ${GCC34_INSTALLTO_SUBPREFIX} != "gccAda-3.4"
GCC34_PKGMODIF=			_${GCC34_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_DEPENDS.gccAda-3.4+=       gccAda-3.4
BUILDLINK_PKGSRCDIR.gccAda-3.4?=     ../../wip/gcc-3.4-ada
BUILDLINK_CONTENTS_FILTER.gccAda-3.4= \
	${EGREP} '(gnat1|bin.*/|include.*/|\.h$$|\.pc$$|lib.*/lib[^/]*$$)'

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gccAda-3.4+=	full
.  else
BUILDLINK_DEPMETHOD.gccAda-3.4?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"

.endif  # GCC-3.4-ADA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
