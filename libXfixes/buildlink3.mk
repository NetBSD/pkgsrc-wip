# $NetBSD: buildlink3.mk,v 1.2 2004/08/17 21:26:57 thomasklausner Exp $
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
BUILDLINK_DEPENDS.libXfixes?=		libXfixes>=2.0.0
BUILDLINK_PKGSRCDIR.libXfixes?=		../../wip/libXfixes

.include "../../wip/libX11/buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"

.endif # LIBXFIXES_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
