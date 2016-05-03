# $NetBSD$

BUILDLINK_TREE+=	coreclr

.if !defined(CORECLR_BUILDLINK3_MK)
CORECLR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.coreclr+=	coreclr>=0.0.0nb20160222
BUILDLINK_PKGSRCDIR.coreclr?=	../../wip/coreclr-git

BUILDLINK_INCDIRS.coreclr+=	CoreCLR/inc
BUILDLINK_INCDIRS.coreclr+=	CoreCLR/gcinfo
BUILDLINK_FILES.coreclr+=	CoreCLR/gcinfo/gcinfoencoder.cpp
BUILDLINK_FILES.coreclr+=	CoreCLR/inc/*.h
BUILDLINK_FILES.coreclr+=	CoreCLR/inc/*.def

.include "../../textproc/icu/buildlink3.mk"
# Stable LLVM
#.include "../../lang/llvm/buildlink3.mk"
#.include "../../devel/lldb/buildlink3.mk"
#.include "../../lang/clang/buildlink3.mk"
#.include "../../lang/libunwind/buildlink3.mk"
# Devel LLVM
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../wip/lldb-git/buildlink3.mk"
.include "../../wip/clang-git/buildlink3.mk"
.include "../../wip/libunwind-git/buildlink3.mk"
.endif	# CORECLR_BUILDLINK3_MK

BUILDLINK_TREE+=	-coreclr
