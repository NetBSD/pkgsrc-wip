# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/06/05 08:09:42 marttikuparinen Exp $
#
# This Makefile fragment is included by packages that use xfce4-gtk2-engines.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFCE4_GTK2_ENGINES_BUILDLINK2_MK)
XFCE4_GTK2_ENGINES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-gtk2-engines
BUILDLINK_DEPENDS.xfce4-gtk2-engines?=		xfce4-gtk2-engines>=3.90.20030604
BUILDLINK_PKGSRCDIR.xfce4-gtk2-engines?=		../../wip/xfce4-gtk2-engines

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-gtk2-engines=xfce4-gtk2-engines
BUILDLINK_PREFIX.xfce4-gtk2-engines_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-gtk2-engines+=	lib/gtk-2.0/2.2.0/engines/libxfce.*

.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-gtk2-engines-buildlink

xfce4-gtk2-engines-buildlink: _BUILDLINK_USE

.endif	# XFCE4_GTK2_ENGINES_BUILDLINK2_MK
