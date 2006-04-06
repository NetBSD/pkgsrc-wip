# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:18:40 jeremy-c-reed Exp $

BUILDLINK_DEPMETHOD.xineramaproto?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XINERAMAPROTO_BUILDLINK3_MK:=	${XINERAMAPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xineramaproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxineramaproto}
BUILDLINK_PACKAGES+=	xineramaproto

.if !empty(XINERAMAPROTO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xineramaproto+=	xineramaproto>=1.1.1
BUILDLINK_PKGSRCDIR.xineramaproto?=	../../wip/xineramaproto
.endif	# XINERAMAPROTO_BUILDLINK3_MK

.include "../../wip/libX11/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
