# $NetBSD: Makefile,v 1.2 2011/12/02 14:50:50 ivaniclixx Exp $

DISTNAME=	colorize-0.1-src
PKGNAME=	colorize-0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://deic.uab.cat/~iblanes/

MAINTAINER=	ivaniclixx@gmail.com
HOMEPAGE=	http://deic.uab.cat/~iblanes/
COMMENT=	Command colorizer useful to distinguish remote shells
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/colorize

post-patch:
	cp ${FILESDIR}/error.h ${WRKSRC}

NO_CONFIGURE=		YES
USE_LANGUAGES=		c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/colorize ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
