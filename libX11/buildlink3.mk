# $NetBSD: buildlink3.mk,v 1.1 2004/02/01 19:12:46 minskim Exp $
#
# This Makefile fragment is included by packages that use libX11.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBX11_BUILDLINK3_MK:=	${LIBX11_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libX11
.endif

.if !empty(LIBX11_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libX11
BUILDLINK_DEPENDS.libX11?=		libX11>=6.2.1
BUILDLINK_PKGSRCDIR.libX11?=		../../wip/libX11

.include "../../wip/xextensions/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"

.endif # LIBX11_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
