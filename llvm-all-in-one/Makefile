# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

LLVM_VERSION=	6.0.0

CATEGORIES=	lang devel

LLVM_SVN_REV=		312394

SVN_REPOSITORIES=		llvm
SVN_REPO.llvm=			http://llvm.org/svn/llvm-project/llvm/trunk
SVN_REVISION.llvm=		${LLVM_SVN_REV}

SVN_REPOSITORIES+=		clang
SVN_REPO.clang=			http://llvm.org/svn/llvm-project/cfe/trunk
SVN_REVISION.clang=		${LLVM_SVN_REV}

SVN_REPOSITORIES+=		compiler-rt
SVN_REPO.compiler-rt=		http://llvm.org/svn/llvm-project/compiler-rt/trunk
SVN_REVISION.compiler-rt=	${LLVM_SVN_REV}

SVN_REPOSITORIES+=		lldb
SVN_REPO.lldb=			http://llvm.org/svn/llvm-project/lldb/trunk
SVN_REVISION.lldb=		${LLVM_SVN_REV}

SVN_REPOSITORIES+=		lld
SVN_REPO.lld=			http://llvm.org/svn/llvm-project/lld/trunk
SVN_REVISION.lld=		${LLVM_SVN_REV}

SVN_REPOSITORIES+=		libunwind
SVN_REPO.libunwind=		http://llvm.org/svn/llvm-project/libunwind/trunk
SVN_REVISION.libunwind=		${LLVM_SVN_REV}

SVN_REPOSITORIES+=		libcxx
SVN_REPO.libcxx=		http://llvm.org/svn/llvm-project/libcxx/trunk
SVN_REVISION.libcxx=		${LLVM_SVN_REV}

SVN_REPOSITORIES+=		libcxxabi
SVN_REPO.libcxxabi=		http://llvm.org/svn/llvm-project/libcxxabi/trunk
SVN_REVISION.libcxxabi=		${LLVM_SVN_REV}

SVN_REPOSITORIES+=		openmp
SVN_REPO.openmp=		http://llvm.org/svn/llvm-project/openmp/trunk
SVN_REVISION.openmp=		${LLVM_SVN_REV}

SVN_REPOSITORIES+=		polly
SVN_REPO.polly=			http://llvm.org/svn/llvm-project/polly/trunk
SVN_REVISION.polly=		${LLVM_SVN_REV}

SVN_REPOSITORIES+=		test-suite
SVN_REPO.test-suite=		http://llvm.org/svn/llvm-project/test-suite/trunk
SVN_REVISION.test-suite=	${LLVM_SVN_REV}

SVN_REPOSITORIES+=		clang-tools-extra
SVN_REPO.clang-tools-extra=	http://llvm.org/svn/llvm-project/clang-tools-extra/trunk
SVN_REVISION.clang-tools-extra=	${LLVM_SVN_REV}

SVN_REPOSITORIES+=		llgo
SVN_REPO.llgo=			http://llvm.org/svn/llvm-project/llgo/trunk
SVN_REVISION.llgo=		${LLVM_SVN_REV}

WRKSRC=			${WRKDIR}/llvm

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

# XXX perl is not added as a tool as it does not seem to be required
REPLACE_PERL+=		utils/*.pl
REPLACE_PERL+=		utils/codegen-diff
REPLACE_PERL+=		utils/llvm-native-gxx

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	*/*.py
REPLACE_PYTHON+=	*/*/*.py
REPLACE_PYTHON+=	*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*.py
REPLACE_PYTHON+=	utils/Misc/zkill
REPLACE_PYTHON+=	utils/bisect
REPLACE_PYTHON+=	utils/clang-parse-diagnostics-file
REPLACE_PYTHON+=	utils/git/find-rev
REPLACE_PYTHON+=	utils/lit/tests/Inputs/googletest-format/DummySubDir/OneTest
REPLACE_PYTHON+=	utils/llvm-build/llvm-build
REPLACE_PYTHON+=	utils/llvm-compilers-check
REPLACE_PYTHON+=	utils/llvm-lit/llvm-lit.in

PKGNAME=	llvm-${LLVM_VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
LICENSE=	modified-bsd

USE_TOOLS+=		perl
USE_LANGUAGES=		c c++11
USE_CMAKE=		yes
GCC_REQD+=		4.8
PYTHON_FOR_BUILD_ONLY=	yes

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_LINK_FLAGS=${LDFLAGS:Q}
CMAKE_ARGS+=	-DLLVM_BUILD_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DLLVM_INSTALL_UTILS=ON
#CMAKE_ARGS+=	-DLLVM_LINK_LLVM_DYLIB=ON

# Enable tests
CMAKE_ARGS+=	-DLLVM_INCLUDE_TESTS=ON
CMAKE_ARGS+=	-DCLANG_INCLUDE_TESTS=ON
CMAKE_ARGS+=	-DCOMPILER_RT_INCLUDE_TESTS=ON
CMAKE_ARGS+=	-DLIBCXX_INCLUDE_TESTS=ON

CMAKE_ARGS.Darwin+=	-DCMAKE_LIBTOOL=/usr/bin/libtool

.include "../../mk/compiler.mk"

.if ${OPSYS} == "NetBSD" && !empty(PKGSRC_COMPILER:Mclang)
# command to check if clang is using libc++ or libstdc++
LIBCPP_CHECK_SH=	printf "\#include <ciso646>\n\#ifdef _LIBCPP_VERSION\nYES\n\#endif" | ${CLANGBASE}/bin/clang++ -x c++ -E - 2>&1 | grep YES || true
.else
LIBCPP_CHECK_SH=	echo NO
.endif

# patch NetBSD::GetCXXStdlibType
.if ${OPSYS} == "NetBSD" && empty(LIBCPP_CHECK_SH:sh:MYES)
SUBST_CLASSES+=			libcxx
SUBST_STAGE.libcxx=		pre-configure
SUBST_MESSAGE.libcxx=		Patching toolchain to use libstdc++ (matching the host compiler)
SUBST_FILES.libcxx+=		${WRKDIR}/clang/lib/Driver/ToolChains/NetBSD.cpp
SUBST_SED.libcxx=		-e 's,(Major >= 7 || Major == 0),(false),'

CMAKE_ARGS+=			-DCLANG_DEFAULT_CXX_STDLIB:STRING="libstdc++"
.endif

TEST_ENV+=		LD_LIBRARY_PATH=${WRKDIR}/build/lib
TEST_ENV+=		VERBOSE=1

# Not complete, not everything works
.for _test_ in check-llvm check-clang check-lldb check-compiler-rt check-lld \
	check-libcxx check-unwind check-polly check-libomptarget \
	check-sanitizer check-interception check-tsan check-asan check-msan \
	check-ubsan check-all check-asan-dynamic check-safestack \
	check-profile check-fuzzer
${_test_}: build
	${RUN}${_ULIMIT_CMD} cd ${TEST_DIRS} && ${TEST_MAKE_CMD} -j${MAKE_JOBS} ${_test_}
.endfor

check-check: build
	${RUN}${_ULIMIT_CMD} cd ${TEST_DIRS} && ${TEST_MAKE_CMD} -j${MAKE_JOBS} ${_test_}

do-test: check-llvm check-clang check-lldb check-compiler-rt check-lld check-libcxx check-unwind check-polly check-libomptarget
	${RUN} echo "Running tests"

# It may be that the Solaris linker is more strict here and they can be removed on
# all platforms.  Change this to a patch if verified.
SUBST_CLASSES.SunOS+=	lto
SUBST_STAGE.lto=	pre-configure
SUBST_FILES.lto=	tools/lto/lto.exports
SUBST_SED.lto=		-e '/^LLVM/d'

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	notdylib
.if ${_OPSYS_SHLIB_TYPE} == "dylib"
SOEXT=		dylib
.else
SOEXT=		so
PLIST.notdylib=	yes
.endif
PLIST_SUBST+=	SOEXT=${SOEXT}

# needs std::atomic with 64-bit CAS
.if ${MACHINE_ARCH} == "i386"
CXXFLAGS+=	-march=i586
.endif

.include "options.mk"

# replacing config.guess is required even for cmake.
# It is used to detect correct LLVM_HOST_TRIPLE, e.g. for NetBSD/evbarm.
post-extract:
	${RUN} mkdir -p ${WRKDIR}/build
.for f in config.guess config.sub
	cp ../../mk/gnu-config/${f} ${WRKSRC}/cmake/${f}
.endfor
	${RUN} ln -sf ${WRKDIR}/compiler-rt ${WRKDIR}/llvm/projects/compiler-rt
	${RUN} ln -sf ${WRKDIR}/libcxx ${WRKDIR}/llvm/projects/libcxx
	${RUN} ln -sf ${WRKDIR}/libcxxabi ${WRKDIR}/llvm/projects/libcxxabi
	${RUN} ln -sf ${WRKDIR}/libunwind ${WRKDIR}/llvm/projects/libunwind
	${RUN} ln -sf ${WRKDIR}/test-suite ${WRKDIR}/llvm/projects/test-suite
	${RUN} ln -sf ${WRKDIR}/openmp ${WRKDIR}/llvm/projects/openmp
	${RUN} ln -sf ${WRKDIR}/libcxx ${WRKDIR}/llvm/projects/libcxx
	${RUN} ln -sf ${WRKDIR}/clang ${WRKDIR}/llvm/tools/clang
# Currently errors for missing includes (wrong setup?)
#	${RUN} ln -sf ${WRKDIR}/llgo ${WRKDIR}/llvm/tools/llgo
	${RUN} ln -sf ${WRKDIR}/lld ${WRKDIR}/llvm/tools/lld
	${RUN} ln -sf ${WRKDIR}/lldb ${WRKDIR}/llvm/tools/lldb
# Currently broken in this setup too - missing includes
#	${RUN} ln -sf ${WRKDIR}/clang-tools-extra ${WRKDIR}/llvm/tools/extra
# Missing X flag?
#	${RUN} chmod +x ${WRKDIR}/llgo/third_party/gofrontend/install-sh

.include "../../wip/mk/svn-package.mk"
.include "../../devel/libatomic_ops/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
