# $NetBSD: buildlink3.mk,v 1.1 2004/04/18 12:59:10 johnrshannon Exp $

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH}+
GCC-3.4.0_BUILDLINK3_MK:=   ${GCC-3.4.0-ADA_BUILDLINK3_MK}+
 
.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=   gcc-3.4.0
.endif
 
BUILDLINK_PACKAGES:=  ${BUILDLINK_PACKAGES:Ngcc-3.4.0}
BUILDLINK_PACKAGES+=  gcc-3.4.0
 
.if !empty(GCC-3.4.0_BUILDLINK3_MK:M+)
.  if defined(GCC34_INSTALLTO_SUBPREFIX)
.    if ${GCC34_INSTALLTO_SUBPREFIX} != "gcc-3.4.0"
GCC34_PKGMODIF=			_${GCC34_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_DEPENDS.gcc-3.4.0+=       gcc-3.4.0
BUILDLINK_PKGSRCDIR.gcc-3.4.0?=     ../../wip/gcc-3.4
BUILDLINK_CONTENTS_FILTER.gcc-3.4.0= \
	${EGREP} '(gnat1|bin.*/|include.*/|\.h$$|\.pc$$|lib.*/lib[^/]*$$)'
 
# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc-3.4.0+=	full
.  else
BUILDLINK_DEPMETHOD.gcc-3.4.0?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
 
.endif  # GCC-3.4.0_BUILDLINK3_MK
 
BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
