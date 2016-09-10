# $NetBSD$

BUILDLINK_TREE+=	lld

.if !defined(LLD_BUILDLINK3_MK)
LLD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lld+=	lld>=4.0.0nb20160910
BUILDLINK_PKGSRCDIR.lld?=	../../wip/lld-git

.include "../../wip/llvm-git/buildlink3.mk"
.endif	# LLD_BUILDLINK3_MK

BUILDLINK_TREE+=	-lld
