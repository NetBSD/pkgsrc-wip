# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	lldb-7.0.0
CATEGORIES=	lang devel

SVN_REPOSITORIES=	lldb
SVN_REPO.lldb=		http://llvm.org/svn/llvm-project/lldb/trunk
SVN_REVISION.lldb=	324234

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lldb.org/
COMMENT=	Next generation, high-performance debugger
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

WRKSRC=			${WRKDIR}/${PKGBASE}
CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

USE_LANGUAGES=		c c++11
USE_CMAKE=		yes
GCC_REQD+=		4.8
PY_PATCHPLIST=		yes

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # compilation failure in 3.8.1 (3.8.0 worked)

CMAKE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_ARGS+=	-DHAVE_CXX_ATOMICS64_WITHOUT_LIB=ON
CMAKE_ARGS+=	-DLLDB_USE_SYSTEM_SIX:BOOL=TRUE

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

REPLACE_PERL+=		*.pl
REPLACE_PERL+=		*/*.pl
REPLACE_PERL+=		*/*/*.pl
REPLACE_PERL+=		*/*/*/*.pl
REPLACE_PERL+=		*/*/*/*/*.pl
REPLACE_PERL+=		*/*/*/*/*/*.pl
REPLACE_PERL+=		scripts/sed-sources

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	*/*.py
REPLACE_PYTHON+=	*/*/*.py
REPLACE_PYTHON+=	*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*/*/*.py
REPLACE_PYTHON+=	scripts/shush

TEST_TARGET=		check-lldb
#TEST_TARGET=		check-lldb-unit # doesn't work in standalone build
#TEST_TARGET=		check-lldb-single # check-lldb -j1
#TEST_TARGET=		check-lldb-expr # unknown
TEST_ENV+=		LD_LIBRARY_PATH=${WRKDIR}/build/lib

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		posix
.if ${OPSYS} != "Darwin"
PLIST.posix=		yes
.endif

.if ${OPSYS} == "NetBSD"
.  if exists(/usr/include/panel.h)
CMAKE_ARGS+=	-DLLDB_DISABLE_CURSES:BOOL=FALSE
.  else
CMAKE_ARGS+=	-DLLDB_DISABLE_CURSES:BOOL=TRUE
.  endif
.endif

#_WRAP_EXTRA_ARGS.CXX+=	-fno-omit-frame-pointer -O0 -g -ggdb -U_FORTIFY_SOURCE -fsanitize=address -fsanitize=undefined -lasan -lubsan -U__SANITIZE_ADDRESS__
#CWRAPPERS_APPEND.cxx+=	-fno-omit-frame-pointer -O0 -g -ggdb -U_FORTIFY_SOURCE -fsanitize=address -fsanitize=undefined -lasan -lubsan -U__SANITIZE_ADDRESS__

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../wip/mk/svn-package.mk"
#.include "../../devel/googletest/buildlink3.mk" # check-lldb-unit
.include "../../devel/libatomic_ops/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
#DEPENDS+=	clang-${PKGVERSION_NOREV}{,nb*}:../../wip/clang-netbsd
#.include "../../wip/clang-netbsd/buildlink3.mk"
#DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../wip/llvm-netbsd
#.include "../../wip/llvm-netbsd/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
