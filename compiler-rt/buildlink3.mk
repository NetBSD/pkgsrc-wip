# $NetBSD$

BUILDLINK_TREE+=	compiler-rt

.if !defined(COMPILER_RT_BUILDLINK3_MK)
COMPILER_RT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compiler-rt+=	compiler-rt>=21.1.0
BUILDLINK_PKGSRCDIR.compiler-rt?=	../../wip/compiler-rt

.include "../../wip/llvm/buildlink3.mk"
.endif	# COMPILER_RT_BUILDLINK3_MK

BUILDLINK_TREE+=	-compiler-rt
