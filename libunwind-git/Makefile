# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	libunwind-3.9.0
CATEGORIES=	lang devel

GIT_REPOSITORIES=	libunwind
GIT_REPO.libunwind=		https://github.com/llvm-mirror/libunwind.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libunwind.llvm.org/
COMMENT=	LLVM libunwind
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}
CONFIGURE_DIRS=		${WRKDIR}/build

USE_LANGUAGES=		c c++
USE_CMAKE+=		yes
GCC_REQD+=		4.8

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=g++

CMAKE_ARG_PATH=	${WRKDIR}/libunwind

post-extract:
	${RUN} mkdir -p ${WRKSRC}/build

post-install:
	${RUN} mkdir -p ${DESTDIR}${PREFIX}/include/libunwind
	${RUN} cp -r ${WRKSRC}/libunwind/include/* ${DESTDIR}${PREFIX}/include/libunwind


.include "../../wip/mk/git-package.mk"
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
