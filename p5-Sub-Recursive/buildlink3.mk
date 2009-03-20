# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	p5-Sub-Recursive

.if !defined(P5_SUB_RECURSIVE_BUILDLINK3_MK)
P5_SUB_RECURSIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-Sub-Recursive+=	p5-Sub-Recursive>=0.03
BUILDLINK_PKGSRCDIR.p5-Sub-Recursive?=	../../wip/p5-Sub-Recursive
.endif # P5_SUB_RECURSIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-Sub-Recursive
