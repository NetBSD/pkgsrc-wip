# $NetBSD: buildlink3.mk,v 1.2 2012/04/05 13:34:09 thomasklausner Exp $

BUILDLINK_TREE+=	ppl

.if !defined(PPL_BUILDLINK3_MK)
PPL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ppl+=	ppl>=0.11.2
BUILDLINK_PKGSRCDIR.ppl?=	../../wip/ppl

.endif # PPL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ppl
