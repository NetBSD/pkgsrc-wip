# $NetBSD$

PKGNAME=	ldc-1.21.0
GITHUB_PROJECT=	ldc
DISTNAME=	${PKGNAME_NOREV}-src
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=ldc-developers/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
PKGREVISION=	2

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/ldc-developers/ldc/
COMMENT=	LLVM D Compiler
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH= ${WRKSRC}

CMAKE_ARGS+=	-GNinja
CMAKE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH}

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

do-build:
	cd ${WRKDIR}/build && \
	${SETENV} ${MAKE_ENV} \
		ninja -j ${MAKE_JOBS:U1}

do-install:
	cd ${WRKDIR}/build && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} ninja install

.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
