# $NetBSD: buildlink2.mk,v 1.2 2003/06/09 06:30:49 marttikuparinen Exp $
#
# This Makefile fragment is included by packages that use xfce4-mixer.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFCE4_MIXER_BUILDLINK2_MK)
XFCE4_MIXER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-mixer
BUILDLINK_DEPENDS.xfce4-mixer?=		xfce4-mixer>=0.1
BUILDLINK_PKGSRCDIR.xfce4-mixer?=		../../wip/xfce4-mixer

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-mixer=xfce4-mixer
BUILDLINK_PREFIX.xfce4-mixer_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-mixer+=	lib/xfce4/panel-plugins/libmixer.*

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../wip/xfce4-panel/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-mixer-buildlink

xfce4-mixer-buildlink: _BUILDLINK_USE

.endif	# XFCE4_MIXER_BUILDLINK2_MK
