# $NetBSD: buildlink2.mk,v 1.4 2003/06/25 06:52:46 marttikuparinen Exp $
#
# This Makefile fragment is included by packages that use xfce4-wm-themes.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFCE4_WM_THEMES_BUILDLINK2_MK)
XFCE4_WM_THEMES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-wm-themes
BUILDLINK_DEPENDS.xfce4-wm-themes?=		xfce4-wm-themes>=3.91.0
BUILDLINK_PKGSRCDIR.xfce4-wm-themes?=		../../wip/xfce4-wm-themes

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-wm-themes=xfce4-wm-themes
BUILDLINK_PREFIX.xfce4-wm-themes_DEFAULT=	${X11PREFIX}

.include "../../wip/xfce4-wm/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-wm-themes-buildlink

xfce4-wm-themes-buildlink: _BUILDLINK_USE

.endif	# XFCE4_WM_THEMES_BUILDLINK2_MK
