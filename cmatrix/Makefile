# $NetBSD: Makefile,v 1.2 2004/04/25 06:52:40 blef Exp $
#

DISTNAME=		cmatrix-1.2a
CATEGORIES=		games
MASTER_SITES=		http://www.asty.org/cmatrix/dist/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.asty.org/cmatrix/
COMMENT=		Make your console feel like Nadbuchonazor's bridge

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmatrix ${PREFIX}/bin/cmatrix
	${INSTALL_MAN} ${WRKSRC}/cmatrix.1 ${PREFIX}/man/man1/cmatrix.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/cmatrix
	${INSTALL_DATA} ${WRKSRC}/mtx.pcf ${PREFIX}/share/cmatrix/mtx.pcf

.include "../../mk/bsd.pkg.mk"
