# $NetBSD: buildlink3.mk,v 1.22 2023/04/19 08:08:27 adam Exp $

BUILDLINK_TREE+=	clang

.if !defined(CLANG_BUILDLINK3_MK)
CLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clang+=	clang>=20.0.0
BUILDLINK_ABI_DEPENDS.clang+=	clang>=20.0.0
BUILDLINK_PKGSRCDIR.clang?=	../../wip/clang

BUILDLINK_FILES.clang+=		bin/amdgpu-arch
BUILDLINK_FILES.clang+=		bin/analyze-build
BUILDLINK_FILES.clang+=		bin/c-index-test
BUILDLINK_FILES.clang+=		bin/clang
BUILDLINK_FILES.clang+=		bin/clang++
BUILDLINK_FILES.clang+=		bin/clang-20
BUILDLINK_FILES.clang+=		bin/clang-check
BUILDLINK_FILES.clang+=		bin/clang-cl
BUILDLINK_FILES.clang+=		bin/clang-cpp
BUILDLINK_FILES.clang+=		bin/clang-extdef-mapping
BUILDLINK_FILES.clang+=		bin/clang-format
BUILDLINK_FILES.clang+=		bin/clang-installapi
BUILDLINK_FILES.clang+=		bin/clang-linker-wrapper
BUILDLINK_FILES.clang+=		bin/clang-nvlink-wrapper
BUILDLINK_FILES.clang+=		bin/clang-offload-bundler
BUILDLINK_FILES.clang+=		bin/clang-offload-packager
BUILDLINK_FILES.clang+=		bin/clang-refactor
BUILDLINK_FILES.clang+=		bin/clang-repl
BUILDLINK_FILES.clang+=		bin/clang-scan-deps
BUILDLINK_FILES.clang+=		bin/clang-sycl-linker
BUILDLINK_FILES.clang+=		bin/diagtool
BUILDLINK_FILES.clang+=		bin/git-clang-format
BUILDLINK_FILES.clang+=		bin/hmaptool
BUILDLINK_FILES.clang+=		bin/intercept-build
BUILDLINK_FILES.clang+=		bin/nvptx-arch
BUILDLINK_FILES.clang+=		bin/scan-build
BUILDLINK_FILES.clang+=		bin/scan-build-py
BUILDLINK_FILES.clang+=		bin/scan-view

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/llvm/buildlink3.mk"
.endif	# CLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-clang
