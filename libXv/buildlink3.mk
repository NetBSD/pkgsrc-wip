# $NetBSD: buildlink3.mk,v 1.2 2004/03/18 15:40:56 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXv.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXV_BUILDLINK3_MK:=	${LIBXV_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXv
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXv}
BUILDLINK_PACKAGES+=	libXv

.if !empty(LIBXV_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libXv?=		libXv>=2.2.1
BUILDLINK_PKGSRCDIR.libXv?=		../../wip/libXv
.endif # LIBXV_BUILDLINK3_MK

.include "../../wip/libX11/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
