# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	lldb-5.0.0
CATEGORIES=	lang devel

SVN_REPOSITORIES=	lldb
SVN_REPO.lldb=		http://llvm.org/svn/llvm-project/lldb/trunk
SVN_REVISION.lldb=	293902

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lldb.org/
COMMENT=	Next generation, high-performance debugger
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/${PKGBASE}
CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
GCC_REQD+=		4.8
PY_PATCHPLIST=		yes

CMAKE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

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

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

#.include "../../devel/googletest/buildlink3.mk" # check-lldb-unit
.include "../../textproc/libxml2/buildlink3.mk"
DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../wip/llvm-netbsd
.include "../../wip/llvm-netbsd/buildlink3.mk"
DEPENDS+=	clang-${PKGVERSION_NOREV}{,nb*}:../../wip/clang-netbsd
.include "../../wip/clang-netbsd/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
PYTHON_VERSIONS_ACCEPTED=	27
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
