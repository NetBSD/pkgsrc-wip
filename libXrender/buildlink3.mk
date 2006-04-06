# $NetBSD: buildlink3.mk,v 1.3 2006/04/06 07:17:35 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXrender.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXRENDER_BUILDLINK3_MK:=	${LIBXRENDER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXrender
.endif

.if !empty(LIBXRENDER_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libXrender
BUILDLINK_API_DEPENDS.libXrender+=		libXrender>=0.9.0
BUILDLINK_PKGSRCDIR.libXrender?=		../../wip/libXrender

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/renderproto/buildlink3.mk"

.endif # LIBXRENDER_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
