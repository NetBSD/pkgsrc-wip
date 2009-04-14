# $NetBSD: Makefile,v 1.5 2009/04/14 22:23:04 zecrazytux Exp $
#

DISTNAME=	cclive-0.3.1
CATEGORIES=	net multimedia www
MASTER_SITES=	http://cclive.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER= 	zecrazytux@zecrazytux.net
HOMEPAGE=	http://code.google.com/p/cclive/
COMMENT= 	Command line video extraction tool for user-uploaded video hosts

PKG_DESTDIR_SUPPORT=    user-destdir

GNU_CONFIGURE=yes
USE_TOOLS+=pkg-config
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cclive ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cclive.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
