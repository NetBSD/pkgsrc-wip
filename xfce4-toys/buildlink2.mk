# $NetBSD: buildlink2.mk,v 1.5 2003/07/21 08:26:58 marttikuparinen Exp $
#
# This Makefile fragment is included by packages that use xfce4-toys.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFCE4_TOYS_BUILDLINK2_MK)
XFCE4_TOYS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-toys
BUILDLINK_DEPENDS.xfce4-toys?=		xfce4-toys>=3.99.2
BUILDLINK_PKGSRCDIR.xfce4-toys?=		../../wip/xfce4-toys

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-toys=xfce4-toys
BUILDLINK_PREFIX.xfce4-toys_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-toys+=	lib/xfce4/panel-plugins/libeyes.*

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../wip/xfce4-panel/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-toys-buildlink

xfce4-toys-buildlink: _BUILDLINK_USE

.endif	# XFCE4_TOYS_BUILDLINK2_MK
