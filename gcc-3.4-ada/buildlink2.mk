# $NetBSD: buildlink2.mk,v 1.1 2004/01/09 23:25:18 johnrshannon Exp $
#
# This Makefile fragment is included, indirectly, by packages that use gcc3-ada.
#

.if !defined(GCC34_ADA_BUILDLINK2_MK)
GCC34_ADA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gcc-3.4-ada
BUILDLINK_DEPENDS.gcc-3.4-ada?=		gcc-3.4-ada>=3.4
BUILDLINK_PKGSRCDIR.gcc-3.4-ada?=		../../wip/gcc-3.4-ada

EVAL_PREFIX+=	BUILDLINK_PREFIX.gcc-3.4-ada=gcc-3.4-ada
BUILDLINK_PREFIX.gcc-3.4-ada_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES_CMD.gcc-3.4-ada= (pkg_info -f gcc-3.4-ada |egrep "include|lib" -n |sed -n 's/^.*File:[        ]*//p')

BUILDLINK_TARGETS+=	gcc-3.4-ada-buildlink

gcc-3.4-ada-buildlink: _BUILDLINK_USE

.endif	# GCC3_ADA_BUILDLINK2_MK
