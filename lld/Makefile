# $NetBSD: Makefile,v 1.21 2023/03/14 11:25:56 fcambus Exp $

.include "../../wip/llvm/version.mk"

PKGNAME=	lld-${LLVM_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lld.llvm.org/
COMMENT=	The LLVM Linker
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
GCC_REQD+=		7

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

PYTHON_FOR_BUILD_ONLY=	yes

INSTALLATION_DIRS+=	libexec/lld

post-install:
	${LN} -sf ${PREFIX}/bin/lld ${DESTDIR}${PREFIX}/libexec/lld/ld

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../wip/llvm/buildlink3.mk"
.include "../../wip/libunwind/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
