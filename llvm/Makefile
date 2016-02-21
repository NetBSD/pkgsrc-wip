# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

DISTNAME=	llvm-3.8.0rc1.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel
MASTER_SITES=	http://llvm.org/pre-releases/3.8.0/rc1/
#MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
GCC_REQD+=		4.8
PY_PATCHPLIST=		yes

CONFIGURE_DIRS=         ${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=g++

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

REPLACE_PERL+=		utils/GenLibDeps.pl
REPLACE_PERL+=		utils/UpdateCMakeLists.pl
REPLACE_PERL+=		utils/codegen-diff
REPLACE_PERL+=		utils/findsym.pl
REPLACE_PERL+=		utils/llvm-native-gxx
REPLACE_PERL+=		utils/test_debuginfo.pl

REPLACE_PYTHON+=	examples/Kaleidoscope/MCJIT/cached/genk-timing.py
REPLACE_PYTHON+=	examples/Kaleidoscope/MCJIT/cached/split-lib.py
REPLACE_PYTHON+=	examples/Kaleidoscope/MCJIT/complete/genk-timing.py
REPLACE_PYTHON+=	examples/Kaleidoscope/MCJIT/complete/split-lib.py
REPLACE_PYTHON+=	examples/Kaleidoscope/MCJIT/lazy/genk-timing.py
REPLACE_PYTHON+=	test/BugPoint/compile-custom.ll.py
REPLACE_PYTHON+=	test/tools/llvm-readobj/Inputs/relocs.py
REPLACE_PYTHON+=	utils/Misc/zkill
REPLACE_PYTHON+=	utils/Target/ARM/analyze-match-table.py
REPLACE_PYTHON+=	utils/bisect
REPLACE_PYTHON+=	utils/clang-parse-diagnostics-file
REPLACE_PYTHON+=	utils/create_ladder_graph.py
REPLACE_PYTHON+=	utils/git/find-rev
REPLACE_PYTHON+=	utils/lint/common_lint.py
REPLACE_PYTHON+=	utils/lint/cpp_lint.py
REPLACE_PYTHON+=	utils/lint/generic_lint.py
REPLACE_PYTHON+=	utils/lit/lit.py
REPLACE_PYTHON+=	utils/lit/lit/ProgressBar.py
REPLACE_PYTHON+=	utils/lit/lit/main.py
REPLACE_PYTHON+=	utils/lit/tests/Inputs/googletest-format/DummySubDir/OneTest
REPLACE_PYTHON+=	utils/llvm-build/llvm-build
REPLACE_PYTHON+=	utils/llvm-compilers-check
REPLACE_PYTHON+=	utils/llvm-lit/llvm-lit.in
REPLACE_PYTHON+=	utils/release/findRegressions-nightly.py
REPLACE_PYTHON+=	utils/release/findRegressions-simple.py
REPLACE_PYTHON+=	utils/schedcover.py
REPLACE_PYTHON+=	utils/shuffle_fuzz.py
REPLACE_PYTHON+=	utils/sort_includes.py
REPLACE_PYTHON+=	utils/testgen/mc-bundling-x86-gen.py
REPLACE_PYTHON+=	utils/update_llc_test_checks.py
REPLACE_PYTHON+=	utils/wciia.py

TEST_TARGET=		check
TEST_ENV+=		LD_LIBRARY_PATH=${WRKDIR}/build/lib

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
