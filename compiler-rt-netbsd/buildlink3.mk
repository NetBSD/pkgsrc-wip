# $NetBSD$

BUILDLINK_TREE+=	compiler-rt

.if !defined(COMPILER_RT_BUILDLINK3_MK)
COMPILER_RT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compiler-rt+=	compiler-rt>=5.0.0
BUILDLINK_PKGSRCDIR.compiler-rt?=	../../wip/compiler-rt-netbsd

.include "../../wip/llvm-netbsd/buildlink3.mk"
.endif	# COMPILER_RT_BUILDLINK3_MK

BUILDLINK_TREE+=	-compiler-rt
