# $NetBSD: Makefile,v 1.4 2009/03/27 09:39:44 thomasklausner Exp $
#

DISTNAME=	cclive-0.2.6
CATEGORIES=	net multimedia www
MASTER_SITES=	http://cclive.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER= 	zecrazytux@zecrazytux.net
HOMEPAGE=	http://code.google.com/p/cclive/
COMMENT= 	Command line video extraction tool for user-uploaded video hosts

PKG_DESTDIR_SUPPORT=    user-destdir

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cclive ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cclive.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
