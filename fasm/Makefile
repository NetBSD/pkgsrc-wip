# $NetBSD: Makefile,v 1.9 2009/07/15 22:12:44 athaba Exp $
#

DISTNAME=		fasm-1.68
CATEGORIES=		devel
MASTER_SITES=		http://flatassembler.net/

MAINTAINER=		athaba@inode.at
HOMEPAGE=		http://flatassembler.net/
COMMENT=		Open source assembly language compiler

LICENSE=		modified-bsd

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/fasm
USE_LANGUAGES=		c
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin share/doc/fasm

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} fasm.o -o fasm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fasm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fasm.txt ${DESTDIR}${PREFIX}/share/doc/fasm

.include "../../mk/bsd.pkg.mk"
