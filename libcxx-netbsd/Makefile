# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	libcxx-7.0.0
CATEGORIES=	lang devel

SVN_REPOSITORIES=		libcxx
SVN_REPO.libcxx=		http://llvm.org/svn/llvm-project/libcxx/trunk
SVN_REVISION.libcxx=		340319

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libcxx.llvm.org/
COMMENT=	C++ Standard Library
LICENSE=	modified-bsd OR mit

WRKSRC=			${WRKDIR}/${PKGBASE}
CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
GCC_REQD+=		4.8

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../wip/mk/svn-package.mk"
#DEPENDS+=       llvm-${PKGVERSION_NOREV}{,nb*}:../../wip/llvm-netbsd
#.include "../../wip/llvm-netbsd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
