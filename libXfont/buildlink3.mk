# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 18:24:38 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXfont.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXFONT_BUILDLINK3_MK:=	${LIBXFONT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXfont
.endif

.if !empty(LIBXFONT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libXfont
BUILDLINK_DEPENDS.libXfont+=		libXfont>=1.4.1
BUILDLINK_PKGSRCDIR.libXfont?=		../../wip/libXfont

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"

.endif # LIBXFONT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
