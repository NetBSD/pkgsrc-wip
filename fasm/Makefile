# $NetBSD: Makefile,v 1.14 2012/09/28 23:21:47 asau Exp $
#

DISTNAME=		fasm-1.70.02
CATEGORIES=		devel
MASTER_SITES=		http://flatassembler.net/

MAINTAINER=		athaba@users.sourceforge.net
HOMEPAGE=		https://flatassembler.net/
COMMENT=		Open source assembly language compiler
LICENSE=		modified-bsd

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

WRKSRC=			${WRKDIR}/fasm
USE_LANGUAGES=		c
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin share/doc/fasm

do-build:
	cd ${WRKSRC} && ${CC} -m32 ${CFLAGS} fasm.o -o fasm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fasm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fasm.txt ${DESTDIR}${PREFIX}/share/doc/fasm

.include "../../mk/bsd.pkg.mk"
