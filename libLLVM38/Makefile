# $NetBSD: Makefile,v 1.5 2016/08/03 09:07:39 wiz Exp $
#
# when updating this, please also update:
# devel/libunwind
# devel/lldb
# lang/clang
# lang/libLLVM

DISTNAME=	llvm-${PKGVERSION_NOREV}.src
PKGNAME=	libLLVM38-3.8.1
CATEGORIES=	lang devel
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
#MASTER_SITES=	http://llvm.org/pre-releases/3.8.0/rc2/
EXTRACT_SUFX=	.tar.xz
PKGREVISION=	2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure (old version)
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
GCC_REQD+=		4.8
PYTHON_FOR_BUILD_ONLY=	yes

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=g++
CMAKE_ARGS+=	-DLLVM_INCLUDE_UTILS=OFF
CMAKE_ARGS+=	-DLLVM_INSTALL_UTILS=OFF
CMAKE_ARGS+=	-DLLVM_INCLUDE_TESTS=OFF

.for tool in 	bugpoint bugpoint_passes dsymutil gold llc lli llvm_ar	\
	llvm_as llvm_as_fuzzer llvm_bcanalyzer llvm_c_test llvm_cat	\
	llvm_cov llvm_cxxdump llvm_cxxfilt llvm_diff llvm_dis		\
	llvm_dwarfdump llvm_dwp llvm_extract llvm_go llvm_jitlistener	\
	llvm_link llvm_lto llvm_lto2 llvm_mc llvm_mc_fuzzer		\
	llvm_mcmarkup llvm_modextract llvm_nm llvm_objdump		\
	llvm_opt_report llvm_pdbdump llvm_profdata llvm_readobj		\
	llvm_rtdyld llvm_size llvm_split llvm_stress llvm_strings	\
	llvm_symbolizer llvm_xray lto msbuild obj2yaml opt sancov	\
	sanstats verify_uselistorder xcode_toolchain yaml2obj

CMAKE_ARGS+=	-DLLVM_TOOL_${tool:tu}_BUILD=OFF
.endfor

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

# XXX perl is not added as a tool as it does not seem to be required
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

SUBST_CLASSES+=		fix-pfx
SUBST_STAGE.fix-pfx=	pre-configure
SUBST_MESSAGE.fix-pfx=	Adjusting installation directories to avoid conflict with clang
SUBST_FILES.fix-pfx=	Makefile.config.in
SUBST_FILES.fix-pfx+=	cmake/modules/Makefile
SUBST_FILES.fix-pfx+=	configure
SUBST_SED.fix-pfx=	-e 's,(PROJ_prefix)/bin$$,(PROJ_prefix)/libexec/libLLVM38,g'
SUBST_SED.fix-pfx+=	-e 's,(PROJ_prefix)/lib$$,(PROJ_prefix)/lib/libLLVM38,g'
SUBST_SED.fix-pfx+=	-e 's,(PROJ_prefix)/include$$,(PROJ_prefix)/include/libLLVM38,g'
SUBST_SED.fix-pfx+=	-e 's,(PROJ_prefix)/share/llvm/cmake$$,(PROJ_prefix)/share/libLLVM38/cmake,g'
SUBST_SED.fix-pfx+=	-e 's,$${exec_prefix}/lib,$${exec_prefix}/lib/libLLVM38,g'
SUBST_SED.fix-pfx+=	-e 's,$${exec_prefix}/bin,$${exec_prefix}/libexec/libLLVM38,g'
SUBST_SED.fix-pfx+=	-e 's,$${prefix}/bin,$${prefix}/libexec/libLLVM38,g'
SUBST_SED.fix-pfx+=	-e 's,$${prefix}/include,$${prefix}/include/libLLVM38,g'
SUBST_SED.fix-pfx+=	-e 's,$${prefix}/share/llvm,$${prefix}/share/libLLVM38,g'

SUBST_CLASSES+=		fix-cnf
SUBST_STAGE.fix-cnf=	pre-configure
SUBST_MESSAGE.fix-cnf=	Fixing llvm-config paths
SUBST_FILES.fix-cnf=	tools/llvm-config/llvm-config.cpp
SUBST_SED.fix-cnf=	-e 's|ActivePrefix + "/include"|"${PREFIX}/include/libLLVM38"|g'
SUBST_SED.fix-cnf+=	-e 's|ActivePrefix + "/lib"|std::string("${PREFIX}/lib/libLLVM38")|g'
SUBST_SED.fix-cnf+=	-e 's|"-L" << ActiveLibDir|"${COMPILER_RPATH_FLAG}" << ActiveLibDir << " " << &|g'

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/libLLVM38

INSTALLATION_DIRS+=	lib/libLLVM38

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
SOEXT=		dylib
.else
SOEXT=		so
.endif
PLIST_SUBST+=	SOEXT=${SOEXT}

.include "options.mk"

# replacing config.guess is required even for cmake.
# It is used to detect correct LLVM_HOST_TRIPLE, e.g. for NetBSD/evbarm.
post-extract:
	${RUN} mkdir -p ${WRKDIR}/build
.for f in config.guess config.sub
	cp ../../mk/gnu-config/${f} ${WRKSRC}/autoconf/${f}
.endfor

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
