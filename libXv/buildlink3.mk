# $NetBSD: buildlink3.mk,v 1.1 2004/02/01 22:24:15 minskim Exp $
#
# This Makefile fragment is included by packages that use libXv.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXV_BUILDLINK3_MK:=	${LIBXV_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXv
.endif

.if !empty(LIBXV_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libXv
BUILDLINK_DEPENDS.libXv?=		libXv>=2.2.1
BUILDLINK_PKGSRCDIR.libXv?=		../../wip/libXv

.include "../../wip/libX11/buildlink3.mk"

.endif # LIBXV_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
