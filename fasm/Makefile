# $NetBSD: Makefile,v 1.3 2008/08/15 19:15:14 hoka_adam Exp $
#

DISTNAME=		fasm-1.67.27
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://flatassembler.net/

MAINTAINER=		athaba@inode.at
HOMEPAGE=		http://flatassembler.net/
COMMENT=		Open source assembly language compiler

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/fasm
USE_LANGUAGES=		c
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin share/example/fasm share/doc/fasm

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} fasm.o -o fasm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fasm ${DESTDIR}${PREFIX}/bin
	cp -R ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/share/example/fasm
	${INSTALL_DATA} ${WRKSRC}/fasm.txt ${DESTDIR}${PREFIX}/share/doc/fasm

.include "../../mk/bsd.pkg.mk"
