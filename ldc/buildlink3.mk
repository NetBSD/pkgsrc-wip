# $NetBSD$

BUILDLINK_TREE+=	ldc

.if !defined(LDC_BUILDLINK3_MK)
LDC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ldc+=	ldc>=1.21.0nb2
BUILDLINK_PKGSRCDIR.ldc?=	../../wip/ldc

.include "../../lang/llvm/buildlink3.mk"
.endif	# LDC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ldc
