# $NetBSD: Makefile,v 1.2 2004/10/16 12:08:04 rillig Exp $
#

DISTNAME=		aliados-0.1.1
CATEGORIES=		emulators
MASTER_SITES=		http://www.arrakis.es/~ninsesabe/aliados/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://www.arrakis.es/~ninsesabe/aliados/
COMMENT=		CP/M 80 emulator

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_BUILDLINK3=		YES
NO_CONFIGURE=		YES
USE_NCURSES=		YES

do-install:
	${INSTALL_PROGRAM_DIR} ${INSTALL_DIR_PROGRAM} ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/aliados ${PREFIX}/bin/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
