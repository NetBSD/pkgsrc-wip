# $NetBSD$

BUILDLINK_TREE+=	compiler-rt

.if !defined(COMPILER_RT_BUILDLINK3_MK)
COMPILER_RT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compiler-rt+=	compiler-rt>=4.0.0nb20160924
BUILDLINK_PKGSRCDIR.compiler-rt?=	../../wip/compiler-rt-git

.include "../../wip/llvm-git/buildlink3.mk"
.endif	# COMPILER_RT_BUILDLINK3_MK

BUILDLINK_TREE+=	-compiler-rt
