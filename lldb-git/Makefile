# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	lldb-5.0.0
CATEGORIES=	lang devel

GIT_REPOSITORIES=	lldb
GIT_REPO.lldb=		git://github.com/llvm-mirror/lldb.git

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
TEST_ENV+=		LD_LIBRARY_PATH=${WRKDIR}/build/lib

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../textproc/libxml2/buildlink3.mk"
DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../wip/llvm-git
.include "../../wip/llvm-git/buildlink3.mk"
DEPENDS+=	clang-${PKGVERSION_NOREV}{,nb*}:../../wip/clang-git
.include "../../wip/clang-git/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
PYTHON_VERSIONS_ACCEPTED=	27
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
