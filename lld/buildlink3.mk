# $NetBSD$

BUILDLINK_TREE+=	lld

.if !defined(LLD_BUILDLINK3_MK)
LLD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lld+=	lld>=3.8.1
BUILDLINK_PKGSRCDIR.lld?=	../../wip/lld

.include "../../lang/llvm/buildlink3.mk"
.endif	# LLD_BUILDLINK3_MK

BUILDLINK_TREE+=	-lld
