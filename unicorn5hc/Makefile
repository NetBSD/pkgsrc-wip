# $NetBSD: Makefile,v 1.1 2015/03/03 12:45:06 thomasklausner Exp $

DISTNAME=	unicorn5hc
PKGNAME=	unicorn5hc-5.7
CATEGORIES=	games
MASTER_SITES=	http://www.elf-emulation.com/rcs/unicorn5/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.elf-emulation.com/rcs/unicorn5/index.html
COMMENT=	Quest for the Unicorn version 5, a rogue-like game, Hard Core edition
#LICENSE=	no-commercial-use

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=			${WRKDIR}/unicorn5RL
USE_LANGUAGES=		c
BUILD_TARGET=		unicorn5
INSTALLATION_DIRS+=	bin share/doc/unicorn

post-extract:
	chmod 755 ${WRKSRC}
	chmod 644 ${WRKSRC}/*
	chmod 755 ${WRKSRC}/*/
	chmod 644 ${WRKSRC}/*/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unicorn5 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/unicorn.doc ${DESTDIR}${PREFIX}/share/doc/unicorn
	${INSTALL_DATA} ${WRKSRC}/copyright.txt ${DESTDIR}${PREFIX}/share/doc/unicorn

.include "../../mk/bsd.pkg.mk"
