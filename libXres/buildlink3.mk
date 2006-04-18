# $NetBSD: buildlink3.mk,v 1.6 2006/04/18 18:27:51 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXres.

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXRES_BUILDLINK3_MK:=	${LIBXRES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXres
.endif

.if !empty(LIBXRES_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libXres
BUILDLINK_API_DEPENDS.libXres+=		libXres>=1.0.0
BUILDLINK_PKGSRCDIR.libXres?=		../../wip/libXres

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.endif # LIBXRES_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
