# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	llvm-3.9.0
CATEGORIES=	lang devel

GIT_REPOSITORIES=	llvm
GIT_REPO.llvm=		git://github.com/llvm-mirror/llvm.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
GCC_REQD+=		4.8
PY_PATCHPLIST=		yes

WRKSRC=			${WRKDIR}/${PKGBASE}
CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=g++
# Try to optimize building LLVM for now.
CMAKE_ARGS+=	-DLLVM_TARGETS_TO_BUILD="X86"

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

REPLACE_PERL+=		${WRKDIR}/llvm/utils/GenLibDeps.pl
REPLACE_PERL+=		${WRKDIR}/llvm/utils/UpdateCMakeLists.pl
REPLACE_PERL+=		${WRKDIR}/llvm/utils/codegen-diff
REPLACE_PERL+=		${WRKDIR}/llvm/utils/findsym.pl
REPLACE_PERL+=		${WRKDIR}/llvm/utils/llvm-native-gxx
REPLACE_PERL+=		${WRKDIR}/llvm/utils/test_debuginfo.pl

REPLACE_PYTHON+=	${WRKDIR}/llvm/examples/Kaleidoscope/MCJIT/cached/genk-timing.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/examples/Kaleidoscope/MCJIT/cached/split-lib.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/examples/Kaleidoscope/MCJIT/complete/genk-timing.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/examples/Kaleidoscope/MCJIT/complete/split-lib.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/examples/Kaleidoscope/MCJIT/lazy/genk-timing.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/test/BugPoint/compile-custom.ll.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/test/tools/llvm-readobj/Inputs/relocs.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/Misc/zkill
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/Target/ARM/analyze-match-table.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/bisect
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/clang-parse-diagnostics-file
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/create_ladder_graph.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/git/find-rev
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lint/common_lint.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lint/cpp_lint.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lint/generic_lint.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lit/lit.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lit/lit/ProgressBar.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lit/lit/main.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lit/tests/Inputs/googletest-format/DummySubDir/OneTest
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/llvm-build/llvm-build
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/llvm-compilers-check
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/llvm-lit/llvm-lit.in
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/release/findRegressions-nightly.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/release/findRegressions-simple.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/schedcover.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/shuffle_fuzz.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/sort_includes.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/testgen/mc-bundling-x86-gen.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/update_llc_test_checks.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/wciia.py

TEST_TARGET=		check-lldb
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/lib

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
