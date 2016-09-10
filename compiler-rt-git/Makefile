# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	compiler-rt-4.0.0
CATEGORIES=	lang devel

GIT_REPOSITORIES=	compiler-rt
GIT_REPO.compiler-rt=	https://github.com/llvm-mirror/compiler-rt.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiler-rt.llvm.org/
COMMENT=	LLVM runtime libraries
LICENSE=	modified-bsd OR mit

WRKSRC=			${WRKDIR}/build

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
GCC_REQD+=		4.8

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

CMAKE_ARG_PATH=	${WRKDIR}/compiler-rt

post-extract:
	${RUN} mkdir -p ${WRKSRC}

.include "../../wip/mk/git-package.mk"
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
