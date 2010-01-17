# $NetBSD: Makefile,v 1.9 2010/01/17 12:03:23 thomasklausner Exp $
#

DISTNAME=		cclive-0.5.6
PKGREVISION=		1
CATEGORIES=		net multimedia www
MASTER_SITES=		http://cclive.googlecode.com/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER= 		zecrazytux@zecrazytux.net
HOMEPAGE=		http://code.google.com/p/cclive/
COMMENT=		Command line video extraction tool for user-uploaded video hosts

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c++ c
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cclive ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cclive.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../www/curl/buildlink3.mk"
.include "../../devel/pcre++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
