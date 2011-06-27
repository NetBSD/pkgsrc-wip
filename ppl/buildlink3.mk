# $NetBSD: buildlink3.mk,v 1.1 2011/06/27 16:10:18 keckhardt Exp $

BUILDLINK_TREE+=	ppl

.if !defined(PPL_BUILDLINK3_MK)
PPL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ppl+=	ppl>=0.11.2
BUILDLINK_ABI_DEPENDS.ppl?=	ppl>=0.11.2
BUILDLINK_PKGSRCDIR.ppl?=	../../wip/ppl

.endif # PPL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ppl
