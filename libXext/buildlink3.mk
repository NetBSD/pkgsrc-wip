# $NetBSD: buildlink3.mk,v 1.3 2004/05/09 04:16:07 minskim Exp $
#
# This Makefile fragment is included by packages that use libXext.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXEXT_BUILDLINK3_MK:=	${LIBXEXT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXext
.endif

.if !empty(LIBXEXT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libXext
BUILDLINK_DEPENDS.libXext+=		libXext>=6.4.1
BUILDLINK_PKGSRCDIR.libXext?=		../../wip/libXext

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../x11/xextensions/buildlink3.mk"

.endif # LIBXEXT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
