# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/08/25 10:05:45 marttikuparinen Exp $
#
# This Makefile fragment is included by packages that use xfce4-minicmd-plugin.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFCE4_MINICMD_PLUGIN_BUILDLINK2_MK)
XFCE4_MINICMD_PLUGIN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-minicmd-plugin
BUILDLINK_DEPENDS.xfce4-minicmd-plugin?=		xfce4-minicmd-plugin>=0.1.1
BUILDLINK_PKGSRCDIR.xfce4-minicmd-plugin?=		../../wip/xfce4-minicmd-plugin

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-minicmd-plugin=xfce4-minicmd-plugin
BUILDLINK_PREFIX.xfce4-minicmd-plugin_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-minicmd-plugin+=	lib/xfce4/panel-plugins/libminicmd.*

.include "../../wip/xfce4-panel/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-minicmd-plugin-buildlink

xfce4-minicmd-plugin-buildlink: _BUILDLINK_USE

.endif	# XFCE4_MINICMD_PLUGIN_BUILDLINK2_MK
