# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/03/27 22:46:02 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libdv.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(LIBDV_BUILDLINK2_MK)
LIBDV_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libdv
BUILDLINK_DEPENDS.libdv?=		libdv>=0.101
BUILDLINK_PKGSRCDIR.libdv?=		../../developing/libdv

EVAL_PREFIX+=	BUILDLINK_PREFIX.libdv=libdv
BUILDLINK_PREFIX.libdv_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libdv+=	include/libdv/dv.h
BUILDLINK_FILES.libdv+=	include/libdv/dv1394.h
BUILDLINK_FILES.libdv+=	include/libdv/dv_types.h
BUILDLINK_FILES.libdv+=	lib/libdv.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	libdv-buildlink

libdv-buildlink: _BUILDLINK_USE

.endif	# LIBDV_BUILDLINK2_MK
