# $NetBSD: buildlink2.mk,v 1.8 2003/09/12 13:08:19 marttikuparinen Exp $
#
# This Makefile fragment is included by packages that use xfce4-fm-icons.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFCE4_FM_ICONS_BUILDLINK2_MK)
XFCE4_FM_ICONS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-fm-icons
BUILDLINK_DEPENDS.xfce4-fm-icons?=		xfce4-fm-icons>=3.99.4
BUILDLINK_PKGSRCDIR.xfce4-fm-icons?=		../../wip/xfce4-fm-icons

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-fm-icons=xfce4-fm-icons
BUILDLINK_PREFIX.xfce4-fm-icons_DEFAULT=	${X11PREFIX}

.include "../../wip/xfce4-fm/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-fm-icons-buildlink

xfce4-fm-icons-buildlink: _BUILDLINK_USE

.endif	# XFCE4_FM_ICONS_BUILDLINK2_MK
