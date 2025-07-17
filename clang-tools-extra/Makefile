# $NetBSD: Makefile,v 1.24 2023/04/19 08:10:34 adam Exp $

INSTALL_DIRS=	tools/extra
# due to INSTALL_DIRS
CMAKE_GENERATORS_INCOMPATIBLE=	ninja

.include "../../wip/clang/Makefile.common"

PKGNAME=	clang-tools-extra-${LLVM_VERSION}

COMMENT=	Extra Clang tools

DEPENDS+=	clang>=${LLVM_VERSION}:../../wip/clang

BUILD_TARGET=	clang-change-namespace clang-apply-replacements clang-doc
BUILD_TARGET+=	clang-include-fixer clang-move clang-query clang-reorder-fields
BUILD_TARGET+=	clang-tidy clangd modularize pp-trace tool-template

REPLACE_PYTHON+=	tools/extra/clang-include-fixer/find-all-symbols/tool/run-find-all-symbols.py
REPLACE_PYTHON+=	tools/extra/clang-tidy/tool/clang-tidy-diff.py
REPLACE_PYTHON+=	tools/extra/clang-tidy/tool/run-clang-tidy.py

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-Bsymbolic-functions

.PHONY: inject-clang-tools
post-extract: inject-clang-tools
inject-clang-tools:
	${LN} -s ${WRKSRC} ${WRKSRC}/../clang/tools/extra

.include "../../mk/bsd.pkg.mk"
