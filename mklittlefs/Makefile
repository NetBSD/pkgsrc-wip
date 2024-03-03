# $NetBSD$

DISTNAME=	mklittlefs-${VERSION}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=earlephilhower/}
GITHUB_PROJECT=	mklittlefs
GITHUB_TAG=	${VERSION}

VERSION=		3.2.0
LITTLEFS_VERSION=	2.5.1

DISTFILES=	${DEFAULT_DISTFILES}

LITTLEFS=	littlefs-${LITTLEFS_VERSION}
DISTFILES+=	${LITTLEFS}.tar.gz
SITES.${LITTLEFS}.tar.gz= -https://github.com/littlefs-project/littlefs/archive/refs/tags/v${LITTLEFS_VERSION}.tar.gz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	https://github.com/earlephilhower/mklittlefs/
COMMENT=	Tool to build and unpack littlefs images
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

MAKE_ENV+=	TARGET_OS=${OPSYS} VERSION=${VERSION} LITTLEFS_VERSION=${LITTLEFS_VERSION}

INSTALLATION_DIRS=	bin

pre-build:
	${RM} -r ${WRKSRC}/littlefs
	${CP} -r ${WRKDIR}/${LITTLEFS} ${WRKSRC}/littlefs
	${SED} -i 's/VERSION :=/VERSION ?=/g' ${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC} && \
	    env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} dist
	cd ${WRKSRC} && \
	    env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} clean
	cd ${WRKSRC} && \
	    env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} dist \
		CPPFLAGS="${CPPFLAGS} -ULFS_NAME_MAX -DLFS_NAME_MAX=64" \
		BUILD_CONFIG_NAME="-esp32"

do-install:
.for i in esp32 generic
	${INSTALL_PROGRAM} ${WRKSRC}/mklittlefs-${VERSION}-${i}-${OPSYS}/mklittlefs ${DESTDIR}${PREFIX}/bin/mklittlefs-${i}
.endfor

.include "../../mk/bsd.pkg.mk"
