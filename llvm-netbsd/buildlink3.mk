# $NetBSD$

BUILDLINK_TREE+=	llvm

.if !defined(LLVM_BUILDLINK3_MK)
LLVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.llvm+=	llvm>=5.0.0
BUILDLINK_PKGSRCDIR.llvm?=	../../wip/llvm-netbsd

LLVM_CONFIG_PATH?=		${BUILDLINK_PREFIX.llvm}/bin/llvm-config

.include "../../devel/zlib/buildlink3.mk"
.endif	# LLVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-llvm
