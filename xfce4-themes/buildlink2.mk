# $NetBSD: buildlink2.mk,v 1.2 2003/06/25 06:52:46 marttikuparinen Exp $
#
# This Makefile fragment is included by packages that use xfce4-themes.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFCE4_THEMES_BUILDLINK2_MK)
XFCE4_THEMES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-themes
BUILDLINK_DEPENDS.xfce4-themes?=		xfce4-themes>=3.91.0
BUILDLINK_PKGSRCDIR.xfce4-themes?=		../../wip/xfce4-themes

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-themes=xfce4-themes
BUILDLINK_PREFIX.xfce4-themes_DEFAULT=	${X11PREFIX}

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../wip/xfce4-panel/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-themes-buildlink

xfce4-themes-buildlink: _BUILDLINK_USE

.endif	# XFCE4_THEMES_BUILDLINK2_MK
