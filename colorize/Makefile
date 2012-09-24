# $NetBSD: Makefile,v 1.3 2012/09/24 18:26:55 asau Exp $

DISTNAME=	colorize-0.1-src
PKGNAME=	colorize-0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://deic.uab.cat/~iblanes/

MAINTAINER=	ivaniclixx@gmail.com
HOMEPAGE=	http://deic.uab.cat/~iblanes/
COMMENT=	Command colorizer useful to distinguish remote shells
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/colorize

post-patch:
	cp ${FILESDIR}/error.h ${WRKSRC}

NO_CONFIGURE=		YES
USE_LANGUAGES=		c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/colorize ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
