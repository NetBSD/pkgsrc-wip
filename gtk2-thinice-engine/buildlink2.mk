# $NetBSD: buildlink2.mk,v 1.3 2003/09/11 19:10:18 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gtk2-thinice-engine.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(GTK2_THINICE_ENGINE_BUILDLINK2_MK)
GTK2_THINICE_ENGINE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gtk2-thinice-engine
BUILDLINK_DEPENDS.gtk2-thinice-engine?=		gtk2-thinice-engine>=2.0.2
BUILDLINK_PKGSRCDIR.gtk2-thinice-engine?=		../../wip/gtk2-thinice-engine

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtk2-thinice-engine=gtk2-thinice-engine
BUILDLINK_PREFIX.gtk2-thinice-engine_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtk2-thinice-engine+=	lib/gtk-2.0/2.2.0/engines/libthinice.*
BUILDLINK_FILES.gtk2-thinice-engine+=	lib/pkgconfig/gtk-thinice-engine-2.pc

.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	gtk2-thinice-engine-buildlink

gtk2-thinice-engine-buildlink: _BUILDLINK_USE

.endif	# GTK2_THINICE_ENGINE_BUILDLINK2_MK
