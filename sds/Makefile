# $NetBSD$

PKGNAME=	sds-2.0.0
CATEGORIES=	devel
GIT_REPO=	https://github.com/antirez/sds
GIT_REVISION=	fb463145c9c245636feb28b5aac0fc897e16f67e

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://github.com/antirez/sds/
COMMENT=	Simple dynamic strings library for C
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c99
TEST_TARGET=	test

INSTALLATION_DIRS=	lib include

do-install:
	${INSTALL_LIB} ${WRKSRC}/libsds.so ${DESTDIR}${PREFIX}/lib/libsds.so
	${INSTALL_DATA} ${WRKSRC}/sds.h ${DESTDIR}${PREFIX}/include/sds.h

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
