# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:18:10 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
NATALI_BUILDLINK3_MK:=		${NATALI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	natali
.endif

BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Nnatali}
BUILDLINK_PACKAGES+=		natali

.if !empty(NATALI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.natali+=	natali>=1.25
BUILDLINK_PKGSRCDIR.natali?=	../../wip/natali
.endif	# NATALI_BUILDLINK3_MK

.include "../../net/netatalk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
