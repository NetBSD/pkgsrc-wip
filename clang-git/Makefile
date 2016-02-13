# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	clang-3.9.0
CATEGORIES=	lang devel

GIT_REPOSITORIES=	clang
GIT_REPO.clang=		git://github.com/llvm-mirror/clang.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://clang.llvm.org/
COMMENT=	C language family frontend for LLVM
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/build

USE_LANGUAGES=		c c++
USE_CMAKE+=		yes
GCC_REQD+=		4.8

REPLACE_PERL+=		${WRKDIR}/clang/test/make_test_dirs.pl
REPLACE_PERL+=		${WRKDIR}/clang/tools/scan-build/bin/scan-build
REPLACE_PERL+=		${WRKDIR}/clang/tools/scan-build/libexec/c++-analyzer
REPLACE_PERL+=		${WRKDIR}/clang/tools/scan-build/libexec/ccc-analyzer
REPLACE_PERL+=		${WRKDIR}/clang/utils/TestUtils/pch-test.pl
REPLACE_PERL+=		${WRKDIR}/clang/utils/analyzer/reducer.pl
REPLACE_PERL+=		${WRKDIR}/clang/utils/analyzer/update_plist_test.pl
REPLACE_PERL+=		${WRKDIR}/clang/www/demo/index.cgi

REPLACE_PYTHON+=	${WRKDIR}/clang/bindings/python/examples/cindex/cindex-dump.py
REPLACE_PYTHON+=	${WRKDIR}/clang/bindings/python/examples/cindex/cindex-includes.py
REPLACE_PYTHON+=	${WRKDIR}/clang/docs/tools/dump_ast_matchers.py
REPLACE_PYTHON+=	${WRKDIR}/clang/docs/tools/dump_format_style.py
REPLACE_PYTHON+=	${WRKDIR}/clang/tools/clang-format/clang-format-diff.py
REPLACE_PYTHON+=	${WRKDIR}/clang/tools/clang-format/git-clang-format
REPLACE_PYTHON+=	${WRKDIR}/clang/tools/scan-build/bin/set-xcode-analyzer
REPLACE_PYTHON+=	${WRKDIR}/clang/tools/scan-view/bin/scan-view
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/ABITest/ABITestGen.py
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/CIndex/completion_logger_server.py
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/CaptureCmd
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/CmpDriver
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/FindSpecRefs
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/FuzzTest
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/TestUtils/deep-stack.py
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/analyzer/CmpRuns.py
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/analyzer/SATestAdd.py
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/analyzer/SATestBuild.py
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/analyzer/SumTimerInfo.py
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/analyzer/ubiviz
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/check_cfc/check_cfc.py
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/check_cfc/obj_diff.py
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/check_cfc/test_check_cfc.py
REPLACE_PYTHON+=	${WRKDIR}/clang/utils/token-delta.py
REPLACE_PYTHON+=	${WRKDIR}/clang/www/builtins.py

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=g++

# Try to optimize building LLVM for now.
CMAKE_ARGS+=	-DLLVM_TARGETS_TO_BUILD="X86"

CMAKE_ARG_PATH=	${WRKDIR}/clang

.include "../../mk/compiler.mk"

# patch NetBSD::GetCXXStdlibType
.if ${OPSYS} == "NetBSD" && !empty(PKGSRC_COMPILER:Mgcc)
SUBST_CLASSES+=			libcxx
SUBST_STAGE.libcxx=		pre-configure
SUBST_MESSAGE.libcxx=		Patching toolchain to use libstdc++ as we're using GCC
SUBST_FILES.libcxx=		${WRKDIR}/clang/lib/Driver/ToolChains.cpp
SUBST_FILES.libcxx+=		${WRKDIR}/clang/lib/Driver/Tools.cpp
SUBST_SED.libcxx=		-e 's,(Major >= 7 || Major == 0),(false),'

CMAKE_ARGS+=			-DCLANG_DEFAULT_CXX_STDLIB:STRING="libstdc++"
.endif

post-extract:
	${RUN} mkdir -p ${WRKSRC}

.include "../../devel/googletest/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
