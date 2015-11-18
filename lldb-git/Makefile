# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $
#
# This is a dummy package - only for lldb/llvm porting efforts
# It will conflict with clang and llvm packages

PKGNAME=	lldb-3.7.0
CATEGORIES=	lang devel

GIT_REPOSITORIES=	llvm lldb clang
GIT_REPO.llvm=		git://github.com/llvm-mirror/llvm.git
GIT_REPO.clang=		git://github.com/llvm-mirror/clang.git
GIT_REPO.lldb=		git://github.com/llvm-mirror/lldb.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lldb.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/build

USE_LANGUAGES=		c c++
USE_CMAKE+=		yes
GCC_REQD+=		4.8

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

TEST_TARGET=		check unittests

.if exists(/usr/include/panel.h)
CMAKE_ARGS+=	-DLLDB_DISABLE_CURSES:BOOL=FALSE
.else
CMAKE_ARGS+=	-DLLDB_DISABLE_CURSES:BOOL=TRUE
.endif

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=g++

CMAKE_ARG_PATH=	${WRKDIR}/llvm

post-extract:
	${RUN} mkdir -p ${WRKSRC}/build
	${RUN} mv ${WRKDIR}/clang/ ${WRKDIR}/llvm/tools
	${RUN} mv ${WRKDIR}/lldb/ ${WRKDIR}/llvm/tools

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
