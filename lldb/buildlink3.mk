# $NetBSD$

BUILDLINK_TREE+=	lldb

.if !defined(LLDB_BUILDLINK3_MK)
LLDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lldb+=	lldb>=3.8.0
BUILDLINK_PKGSRCDIR.lldb?=	../../wip/lldb

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/llvm/buildlink3.mk"
.include "../../wip/clang/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.endif	# LLDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-lldb
