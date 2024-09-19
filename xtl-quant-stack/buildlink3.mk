# $NetBSD$

BUILDLINK_TREE+=	xtl-quant-stack

.if !defined(XTL_QUANT_STACK_BUILDLINK3_MK)
XTL_QUANT_STACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xtl-quant-stack+=	xtl-quant-stack>=0.6.1
BUILDLINK_PKGSRCDIR.xtl-quant-stack?=	../../wip/xtl-quant-stack
.endif	# XTL_QUANT_STACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-xtl-quant-stack
