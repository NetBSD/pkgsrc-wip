# $NetBSD: buildlink2.mk,v 1.1 2003/06/04 07:20:38 marttikuparinen Exp $
#
# This Makefile fragment is included by packages that use gtk2-engines-xfce.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(GTK2_ENGINES_XFCE_BUILDLINK2_MK)
GTK2_ENGINES_XFCE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gtk2-engines-xfce
BUILDLINK_DEPENDS.gtk2-engines-xfce?=		gtk2-engines-xfce>=2.1.0
BUILDLINK_PKGSRCDIR.gtk2-engines-xfce?=		../../wip/gtk2-engines-xfce

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtk2-engines-xfce=gtk2-engines-xfce
BUILDLINK_PREFIX.gtk2-engines-xfce_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtk2-engines-xfce+=	lib/gtk-2.0/2.2.0/engines/libxfce.*

.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	gtk2-engines-xfce-buildlink

gtk2-engines-xfce-buildlink: _BUILDLINK_USE

.endif	# GTK2_ENGINES_XFCE_BUILDLINK2_MK
