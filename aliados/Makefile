# $NetBSD: Makefile,v 1.1.1.1 2004/09/04 17:08:11 ivaniclixx Exp $
#

DISTNAME=		aliados-0.1.1
CATEGORIES=		emuliators wip
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
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/aliados ${PREFIX}/bin/aliados

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
