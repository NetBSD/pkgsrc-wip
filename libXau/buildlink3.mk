# $NetBSD: buildlink3.mk,v 1.1 2004/01/31 22:02:06 minskim Exp $
#
# This Makefile fragment is included by packages that use libXau.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXAU_BUILDLINK3_MK:=	${LIBXAU_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXau
.endif

.if !empty(LIBXAU_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libXau
BUILDLINK_DEPENDS.libXau?=		libXau>=0.1
BUILDLINK_PKGSRCDIR.libXau?=		../../wip/libXau

.include "../../wip/xproto/buildlink3.mk"

.endif # LIBXAU_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
