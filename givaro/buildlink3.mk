# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:17:22 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GIVARO_BUILDLINK3_MK:=	${GIVARO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	givaro
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngivaro}
BUILDLINK_PACKAGES+=	givaro

.if !empty(GIVARO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.givaro+=	givaro>=3.1
BUILDLINK_PKGSRCDIR.givaro?=	../../wip/givaro
.endif	# GIVARO_BUILDLINK3_MK

.include "../../devel/gmp/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
