# $NetBSD$

BUILDLINK_TREE+=	clang

.if !defined(CLANG_BUILDLINK3_MK)
CLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clang+=	clang>=5.0.0
BUILDLINK_PKGSRCDIR.clang?=	../../wip/clang-netbsd

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/llvm-netbsd/buildlink3.mk"
.endif	# CLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-clang
