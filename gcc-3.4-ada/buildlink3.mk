# $NetBSD: buildlink3.mk,v 1.1 2004/02/26 17:05:27 johnrshannon Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCC-3.4-ADA_BUILDLINK3_MK:=	${GCC-3.4-ADA_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gcc-3.4-ada
.endif

.if !empty(GCC-3.4-ADA_BUILDLINK3_MK:M+)
.  if defined(GCC3_INSTALLTO_SUBPREFIX)
#
# "gcc-3.4-ada" is the directory named in pkgsrc/wip/gcc-3.4-ada/Makefile"
# as GCC3_DEFAULT_SUBPREFIX.
#
.    if ${GCC3_INSTALLTO_SUBPREFIX} != "gcc-3.4-ada"
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_PACKAGES+=		gcc-3.4-ada
BUILDLINK_DEPENDS.gcc-3.4-ada+=	gcc-${GCC_VERSION}-ada
BUILDLINK_PKGSRCDIR.gcc-3.4-ada?=	../../wip/gcc-3.4-ada
BUILDLINK_LIBDIRS.gcc-3.4-ada?=	\
	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc-3.4-ada}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc-3.4-ada+=	full
.  else
BUILDLINK_DEPMETHOD.gcc-3.4-ada?=	build
.  endif
.endif	# GCC-3.4-ADA_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
