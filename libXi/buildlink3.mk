# $NetBSD: buildlink3.mk,v 1.2 2004/05/09 04:16:07 minskim Exp $
#
# This Makefile fragment is included by packages that use libXi.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXI_BUILDLINK3_MK:=	${LIBXI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXi
.endif

.if !empty(LIBXI_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libXi
BUILDLINK_DEPENDS.libXi+=		libXi>=6.0.1
BUILDLINK_PKGSRCDIR.libXi?=		../../wip/libXi

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../x11/xextensions/buildlink3.mk"

.endif # LIBXI_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
