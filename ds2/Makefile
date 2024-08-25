# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	ds2-0.0.0
CATEGORIES=	lang devel

GIT_REPOSITORIES=	ds2
GIT_REPO.ds2=		https://github.com/facebook/ds2.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facebook/ds2
COMMENT=	Debug server for LLDB
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/${PKGBASE}
CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
GCC_REQD+=		4.8

CMAKE_CONFIGURE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_CONFIGURE_ARGS+=	-DLLDB_USE_SYSTEM_SIX:BOOL=TRUE

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
