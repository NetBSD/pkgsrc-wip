# $NetBSD$

BUILDLINK_TREE+=	llvm

.if !defined(LLVM_BUILDLINK3_MK)
LLVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.llvm+=	llvm>=5.0.0
BUILDLINK_PKGSRCDIR.llvm?=	../../wip/llvm-git

LLVM_CONFIG_PATH?=		${BUILDLINK_PREFIX.llvm}/bin/llvm-config

pkgbase := llvm
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.llvm:Mterminfo)
.include "../../mk/terminfo.buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.endif	# LLVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-llvm
