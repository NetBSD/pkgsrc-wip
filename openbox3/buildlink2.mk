# $NetBSD: buildlink2.mk,v 1.3 2003/09/16 04:48:15 blef Exp $
#
# This Makefile fragment is included by packages that use openbox.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(OPENBOX_BUILDLINK2_MK)
OPENBOX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			openbox
BUILDLINK_DEPENDS.openbox?=		openbox>=3.0beta3
BUILDLINK_PKGSRCDIR.openbox?=		../../wip/openbox3

EVAL_PREFIX+=	BUILDLINK_PREFIX.openbox=openbox
BUILDLINK_PREFIX.openbox_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.openbox+=	include/openbox/3.0/openbox/*
BUILDLINK_FILES.openbox+=	lib/libobparser.*
BUILDLINK_FILES.openbox+=	lib/libobrender.*
BUILDLINK_FILES.openbox+=	lib/pkgconfig/obparser-3.0.pc
BUILDLINK_FILES.openbox+=	lib/pkgconfig/obrender-3.0.pc

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"

BUILDLINK_TARGETS+=	openbox-buildlink

openbox-buildlink: _BUILDLINK_USE

.endif	# OPENBOX_BUILDLINK2_MK
