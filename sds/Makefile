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
USE_LIBTOOL=	yes

TEST_TARGET=	test

INSTALLATION_DIRS=	lib/pkgconfig

post-extract:
	${CP} ${FILESDIR}/libsds-2.pc.in ${WRKDIR}
	cd ${WRKDIR} && ${SED} -e "s,@prefix@,${PREFIX},g" \
            -e "s,@release@,${PKGVERSION_NOREV},g" <libsds-2.pc.in >libsds-2.pc

post-install:
	cd ${WRKDIR} && ${INSTALL_DATA} libsds-2.pc \
            ${DESTDIR}${PREFIX}/lib/pkgconfig/libsds-2.pc

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
