# $NetBSD: buildlink3.mk,v 1.8 2007/12/02 14:50:13 hoka_adam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EDJE_BUILDLINK3_MK:=	${EDJE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	edje
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nedje}
BUILDLINK_PACKAGES+=	edje
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}edje

.if ${EDJE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.edje+=	edje>=0.5.0.041
BUILDLINK_PKGSRCDIR.edje?=	../../wip/edje
.endif	# EDJE_BUILDLINK3_MK

.include	"../../wip/ecore/buildlink3.mk"
.include	"../../wip/embryo/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
