# $NetBSD: Makefile,v 1.1 2015/02/05 23:58:03 makoto Exp $

DISTNAME=	1.104
PKGNAME=	connect-1.104
CATEGORIES=	net security
MASTER_SITES=   -https://bitbucket.org/gotoh/connect/get/1.104.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/gotoh/connect/wiki/Home
COMMENT=	Open a TCP connection using a SOCKS4/5 or HTTP proxy server
LICENSE=	gnu-gpl-v2

CONFLICTS=	azara-[0-9]*

DIST_SUBDIR=	${PKGBASE}
WRKSRC=		${WRKDIR}/gotoh-connect-fd6f352325d4
USE_TOOLS=	gmake

LIBS.Darwin+=	-lresolv
LIBS.SunOS+=	-lresolv -lsocket -lnsl

INSTALLATION_DIRS=	bin share/doc/connect

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/connect ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/manual.html ${DESTDIR}${PREFIX}/share/doc/connect
	${INSTALL_DATA} ${WRKSRC}/doc/manual.txt ${DESTDIR}${PREFIX}/share/doc/connect

.include "../../mk/bsd.pkg.mk"
