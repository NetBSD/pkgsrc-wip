# $NetBSD: Makefile,v 1.2 2015/06/30 02:29:52 cfkoch Exp $

DISTNAME=	sophia-version_${VERSION}
PKGNAME=	sophia-${VERSION}
VERSION=	2.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=pmwkaa/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://sophia.systems/
COMMENT=	Modern embeddable key-value database
LICENSE=	2-clause-bsd

USE_LANGUAGES+=	c
MAKE_FILE=	makefile
NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
EXTRACT_USING=	gtar

do-install:
	mkdir -p ${DESTDIR}${PREFIX}/include
	mkdir -p ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/sophia.h ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libsophia.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libsophia.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
