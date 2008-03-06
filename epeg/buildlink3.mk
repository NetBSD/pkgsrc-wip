# $NetBSD: buildlink3.mk,v 1.6 2008/03/06 14:54:08 thomasklausner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EPEG_BUILDLINK3_MK:=	${EPEG_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	epeg
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nepeg}
BUILDLINK_PACKAGES+=	epeg
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}epeg

.if ${EPEG_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.epeg+=	epeg>=0.9.0.011
BUILDLINK_ABI_DEPENDS.epeg?=	epeg>=0.9.0.011nb2
BUILDLINK_PKGSRCDIR.epeg?=	../../wip/epeg
.endif	# EPEG_BUILDLINK3_MK

.include	"../../wip/ecore/buildlink3.mk"
.include	"../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
