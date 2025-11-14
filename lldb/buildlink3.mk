# $NetBSD: buildlink3.mk,v 1.15 2023/04/19 08:08:18 adam Exp $

BUILDLINK_TREE+=	lldb

.if !defined(LLDB_BUILDLINK3_MK)
LLDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lldb+=	lldb>=21.1.0
BUILDLINK_ABI_DEPENDS.lldb+=	lldb>=21.1.0
BUILDLINK_PKGSRCDIR.lldb?=	../../wip/lldb

.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/clang/buildlink3.mk"
.include "../../wip/llvm/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LLDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-lldb
