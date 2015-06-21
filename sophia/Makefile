# $NetBSD: Makefile,v 1.1 2015/06/21 20:43:50 cfkoch Exp $

DISTNAME=	sophia-version_${VERSION}
PKGNAME=	sophia-${VERSION}
VERSION=	1.2.2
CATEGORIES=	databases
MASTER_SITES=	-https://codeload.github.com/pmwkaa/sophia/tar.gz/version_${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pmwkaa/sophia
COMMENT=	Modern embeddable key-value database
LICENSE=	2-clause-bsd

USE_LANGUAGES+=	c
MAKE_FILE=	makefile
NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

do-install:
	mkdir -p ${DESTDIR}${PREFIX}/include
	mkdir -p ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/sophia.h ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libsophia.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libsophia.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
