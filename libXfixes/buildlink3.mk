# $NetBSD: buildlink3.mk,v 1.6 2006/04/18 18:27:50 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXfixes.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXFIXES_BUILDLINK3_MK:=	${LIBXFIXES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXfixes
.endif

.if !empty(LIBXFIXES_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libXfixes
BUILDLINK_API_DEPENDS.libXfixes?=		libXfixes>=3.0.0
BUILDLINK_PKGSRCDIR.libXfixes?=		../../wip/libXfixes

.include "../../x11/fixesproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"

.endif # LIBXFIXES_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
