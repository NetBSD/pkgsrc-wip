# $NetBSD: buildlink3.mk,v 1.1 2004/05/10 21:34:51 blef Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
BOOST_BASE_BUILDLINK3_MK:=	${BOOST_BASE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	boost-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nboost-base}
BUILDLINK_PACKAGES+=	boost-base

.if !empty(BOOST_BASE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.boost-base+=	boost-base>=1.30.0
BUILDLINK_PKGSRCDIR.boost-base?=	../../wip/boost-base
.endif	# BOOST_BASE_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
