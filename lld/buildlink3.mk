# $NetBSD$

BUILDLINK_TREE+=	lld

.if !defined(LLD_BUILDLINK3_MK)
LLD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lld+=	lld>=20.1.0
BUILDLINK_PKGSRCDIR.lld?=	../../wip/lld

.include "../../wip/llvm/buildlink3.mk"
.endif	# LLD_BUILDLINK3_MK

BUILDLINK_TREE+=	-lld
