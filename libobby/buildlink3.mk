# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/09/11 05:26:43 udontknow Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OBBY_BUILDLINK3_MK:=	${OBBY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	obby
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nobby}
BUILDLINK_PACKAGES+=	obby

.if !empty(OBBY_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.obby+=	obby>=0.2.0
BUILDLINK_PKGSRCDIR.obby?=	../../wip/obby
.endif	# OBBY_BUILDLINK3_MK

.include "../../wip/net6/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
