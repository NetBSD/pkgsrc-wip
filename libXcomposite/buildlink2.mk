# $NetBSD: buildlink2.mk,v 1.1 2003/11/27 02:47:26 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libXcomposite.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBXCOMPOSITE_BUILDLINK2_MK)
LIBXCOMPOSITE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXcomposite
BUILDLINK_DEPENDS.libXcomposite?=		libXcomposite>=1.0.0
BUILDLINK_PKGSRCDIR.libXcomposite?=		../../wip/libXcomposite

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXcomposite=libXcomposite
BUILDLINK_PREFIX.libXcomposite_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXcomposite+=	include/X11/extensions/Xcomposite.h
BUILDLINK_FILES.libXcomposite+=	lib/libXcomposite.*

.include "../../wip/libXfixes/buildlink2.mk"
.include "../../wip/fixesext/buildlink2.mk"
.include "../../wip/compositeext/buildlink2.mk"

BUILDLINK_TARGETS+=	libXcomposite-buildlink

libXcomposite-buildlink: _BUILDLINK_USE

.endif	# LIBXCOMPOSITE_BUILDLINK2_MK
