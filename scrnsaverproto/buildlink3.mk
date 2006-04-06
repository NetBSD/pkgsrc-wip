# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:18:30 jeremy-c-reed Exp $

BUILDLINK_DEPMETHOD.scrnsaverproto?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SCRNSAVERPROTO_BUILDLINK3_MK:=	${SCRNSAVERPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	scrnsaverproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nscrnsaverproto}
BUILDLINK_PACKAGES+=	scrnsaverproto

.if !empty(SCRNSAVERPROTO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.scrnsaverproto+=	scrnsaverproto>=1.0.1
BUILDLINK_PKGSRCDIR.scrnsaverproto?=	../../wip/scrnsaverproto
.endif	# SCRNSAVERPROTO_BUILDLINK3_MK

.include "../../wip/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
