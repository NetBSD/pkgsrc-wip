# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	compiler-rt-6.0.0
CATEGORIES=	lang devel

GIT_REPOSITORIES=	compiler-rt
GIT_REPO.compiler-rt=	https://github.com/llvm-mirror/compiler-rt.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiler-rt.llvm.org/
COMMENT=	LLVM runtime libraries
LICENSE=	modified-bsd OR mit

WRKSRC=			${WRKDIR}/build

USE_LANGUAGES=		c c++11
USE_CMAKE=		yes
GCC_REQD+=		4.8

WRKSRC=			${WRKDIR}/${PKGBASE}
CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_ARGS+=	-DCOMPILER_RT_OS_DIR:STRING=${LOWER_OPSYS}${OS_VERSION:R}
CMAKE_ARGS+=	-DCOMPILER_RT_INSTALL_PATH:STRING=lib/clang/${PKGVERSION_NOREV}
#CMAKE_ARGS+=	-DCOMPILER_RT_INCLUDE_TESTS:BOOL=ON
# Not supported in standalone build
CMAKE_ARGS+=	-DCOMPILER_RT_INCLUDE_TESTS:BOOL=OFF

PLIST_SUBST+=	COMPILER_RT_OS_DIR=${LOWER_OPSYS}${OS_VERSION:R}

#TEST_TARGET=		check-compiler-rt
#TEST_ENV+=		LD_LIBRARY_PATH=${WRKDIR}/build/lib

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../wip/mk/git-package.mk"
.include "../../devel/googletest/buildlink3.mk"
DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../wip/llvm-git
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
