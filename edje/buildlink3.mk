# $NetBSD: buildlink3.mk,v 1.12 2008/08/06 10:52:22 yazzy Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EDJE_BUILDLINK3_MK:=	${EDJE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	edje
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nedje}
BUILDLINK_PACKAGES+=	edje
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}edje

.if ${EDJE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.edje+=	edje>=0.9.9.043
BUILDLINK_ABI_DEPENDS.edje?=	edje>=0.9.9.043nb1
BUILDLINK_PKGSRCDIR.edje?=	../../wip/edje
.endif	# EDJE_BUILDLINK3_MK

.include	"../../wip/eet/buildlink3.mk"
.include	"../../wip/ecore/buildlink3.mk"
.include	"../../wip/evas/buildlink3.mk"
.include	"../../wip/embryo/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
