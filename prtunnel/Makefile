# $NetBSD: Makefile,v 1.10 2012/10/05 13:42:35 asau Exp $

DISTNAME=	prtunnel-0.2.0
CATEGORIES=	net
MASTER_SITES=	http://joshbeam.com/files/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://joshbeam.com/software/prtunnel.php
COMMENT=	Tunnels TCP connections through an HTTP or SOCKS5 proxy

BUILD_TARGET=	# defined

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/prtunnel ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/prtunnel.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
