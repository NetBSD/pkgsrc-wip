# $NetBSD: buildlink3.mk,v 1.5 2004/03/03 22:39:58 johnrshannon Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCC-3.4-ADA_BUILDLINK3_MK:=	${GCC-3.4-ADA_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gcc-3.4-ada
.endif

.if !empty(GCC-3.4-ADA_BUILDLINK3_MK:M+)
.  if defined(GCC34_INSTALLTO_SUBPREFIX)
.    if ${GCC34_INSTALLTO_SUBPREFIX} != "gcc-3.4-ada"
GCC34_PKGMODIF=			_${GCC34_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_PACKAGES+=		gcc-3.4-ada
BUILDLINK_DEPENDS.gcc-3.4-ada+=	gcc-3.4-ada
BUILDLINK_PKGSRCDIR.gcc-3.4-ada?=	../../wip/gcc-3.4-ada
BUILDLINK_LIBDIRS.gcc-3.4-ada?=	\
	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc-3.4-ada}\///}
BUILDLINK_CONTENTS_FILTER.gcc-3.4-ada= \
	${EGREP} '(gnat1|bin.*/|include.*/|\.h$$|\.pc$$|lib.*/lib[^/]*$$)'

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc-3.4-ada+=	full
.  else
BUILDLINK_DEPMETHOD.gcc-3.4-ada?=	build
.  endif

.endif	# GCC-3.4-ADA_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
