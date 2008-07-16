# $NetBSD: Makefile,v 1.1.1.1 2008/07/16 22:52:53 athaba Exp $
#

DISTNAME=	fasm-1.67.27
CATEGORIES=	devel
MASTER_SITES=	http://flatassembler.net/

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://flatassembler.net/
COMMENT=	Open source assembly language compiler

PKG_DESTDIR_SUPPORT=user-destdir

WRKSRC=		${WRKDIR}/fasm
USE_LANGUAGES=	c
ONLY_FOR_PLATFORM=*-*-i386 *-*-amd64
NO_CONFIGURE=	yes

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} fasm.o -o fasm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fasm ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
