# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/27 01:48:57 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libICE.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBICE_BUILDLINK2_MK)
LIBICE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libICE
BUILDLINK_DEPENDS.libICE?=		libICE>=6.3.1
BUILDLINK_PKGSRCDIR.libICE?=		../../wip/libICE

EVAL_PREFIX+=	BUILDLINK_PREFIX.libICE=libICE
BUILDLINK_PREFIX.libICE_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libICE+=	include/X11/ICE/ICE.h
BUILDLINK_FILES.libICE+=	include/X11/ICE/ICEconn.h
BUILDLINK_FILES.libICE+=	include/X11/ICE/ICElib.h
BUILDLINK_FILES.libICE+=	include/X11/ICE/ICEmsg.h
BUILDLINK_FILES.libICE+=	include/X11/ICE/ICEproto.h
BUILDLINK_FILES.libICE+=	include/X11/ICE/ICEtrans.h
BUILDLINK_FILES.libICE+=	include/X11/ICE/ICEutil.h
BUILDLINK_FILES.libICE+=	lib/libICE.*

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXau/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/xtrans/buildlink2.mk"

BUILDLINK_TARGETS+=	libICE-buildlink

libICE-buildlink: _BUILDLINK_USE

.endif	# LIBICE_BUILDLINK2_MK
