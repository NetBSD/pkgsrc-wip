# $NetBSD$

BUILDLINK_TREE+=	coreclr

.if !defined(CORECLR_BUILDLINK3_MK)
CORECLR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.coreclr+=	coreclr>=0.0.0nb20160222
BUILDLINK_PKGSRCDIR.coreclr?=	../../wip/coreclr-git

.include "../../textproc/icu/buildlink3.mk"
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../wip/lldb-git/buildlink3.mk"
.include "../../wip/clang-git/buildlink3.mk"
.include "../../wip/libunwind-git/buildlink3.mk"
.endif	# CORECLR_BUILDLINK3_MK

BUILDLINK_TREE+=	-coreclr
