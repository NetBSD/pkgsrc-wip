# $NetBSD: buildlink2.mk,v 1.4 2004/01/12 03:45:29 blef Exp $
#
# This Makefile fragment is included by packages that use gimp-current.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(GIMP_CURRENT_BUILDLINK2_MK)
GIMP_CURRENT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gimp-current
BUILDLINK_DEPENDS.gimp-current?=		gimp-current>=2.0pre1
BUILDLINK_PKGSRCDIR.gimp-current?=		../../wip/gimp-current

EVAL_PREFIX+=	BUILDLINK_PREFIX.gimp-current=gimp-current
BUILDLINK_PREFIX.gimp-current_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gimp-current+=	include/gimp-1.3/libgimp/*.h
BUILDLINK_FILES.gimp-current+=	lib/libgimp-1.3.*
BUILDLINK_FILES.gimp-current+=	lib/libgimpbase-1.3.*
BUILDLINK_FILES.gimp-current+=	lib/libgimpcolor-1.3.*
BUILDLINK_FILES.gimp-current+=	lib/libgimpmath-1.3.*
BUILDLINK_FILES.gimp-current+=	lib/libgimpmodule-1.3.*
BUILDLINK_FILES.gimp-current+=	lib/libgimpthumb-1.3.*
BUILDLINK_FILES.gimp-current+=	lib/libgimpui-1.3.*
BUILDLINK_FILES.gimp-current+=	lib/libgimpwidgets-1.3.*

.include "../../devel/glib2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	gimp-current-buildlink

gimp-current-buildlink: _BUILDLINK_USE

.endif	# GIMP_CURRENT_BUILDLINK2_MK
