# $NetBSD$

DISTNAME=	runcpm-0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=MockbaTheBorg/}
GITHUB_PROJECT=	RunCPM
GITHUB_TAG=	3a908dfd3b41702cc1c887371464641da7f8b35b

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/MockbaTheBorg/RunCPM
COMMENT=	Z80 CP/M 2.2 emulator
LICENSE=	mit

NO_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	gmake unzip

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}/RunCPM
MAKE_FILE=	Makefile.posix

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/RunCPM ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
