# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 18:16:17 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libICE.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBICE_BUILDLINK3_MK:=	${LIBICE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libICE
.endif

.if !empty(LIBICE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libICE
BUILDLINK_DEPENDS.libICE+=		libICE>=6.3.1nb1
BUILDLINK_PKGSRCDIR.libICE?=		../../wip/libICE

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"

.endif # LIBICE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
