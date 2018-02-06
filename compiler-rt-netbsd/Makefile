# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	compiler-rt-7.0.0
CATEGORIES=	lang devel

SVN_REPOSITORIES=		compiler-rt
SVN_REPO.compiler-rt=		http://llvm.org/svn/llvm-project/compiler-rt/trunk
SVN_REVISION.compiler-rt=	324350

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiler-rt.llvm.org/
COMMENT=	LLVM runtime libraries
LICENSE=	modified-bsd OR mit

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


PLIST_SUBST+=	COMPILER_RT_OS_DIR=${LOWER_OPSYS}${OS_VERSION:R}

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../wip/mk/svn-package.mk"
#DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../wip/llvm-netbsd
#.include "../../wip/llvm-netbsd/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
