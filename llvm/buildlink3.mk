# $NetBSD$

BUILDLINK_TREE+=	llvm

.if !defined(LLVM_BUILDLINK3_MK)
LLVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.llvm+=	llvm>=3.8.0rc1
BUILDLINK_PKGSRCDIR.llvm?=	../../wip/llvm

.include "../../devel/zlib/buildlink3.mk"
.endif	# LLVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-llvm
