# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	libcxx-3.9.0
CATEGORIES=	lang devel

GIT_REPOSITORIES=	libcxx
GIT_REPO.libcxx=		https://github.com/llvm-mirror/libcxx.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libcxx.llvm.org/
COMMENT=	C++ Standard Library
LICENSE=	modified-bsd OR mit

WRKSRC=			${WRKDIR}/build

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
GCC_REQD+=		4.8

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=g++

CMAKE_ARG_PATH=	${WRKDIR}/libcxx

post-extract:
	${RUN} mkdir -p ${WRKSRC}

.include "../../wip/mk/git-package.mk"
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
