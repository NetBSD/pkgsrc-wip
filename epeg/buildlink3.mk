# $NetBSD: buildlink3.mk,v 1.1 2004/09/16 16:13:17 airhead Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EPEG_BUILDLINK3_MK:=	${EPEG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	epeg
.endif

BUILDLINK_PACKAGES+=	epeg

.if !empty(EPEG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.epeg+=	epeg>=0.9.0
BUILDLINK_PKGSRCDIR.epeg?=	../../wip/epeg
.endif	# EPEG_BUILDLINK3_MK

.include "../../devel/libtool/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
