# $NetBSD: Makefile,v 1.9 2006/10/29 08:32:53 shattered Exp $

DISTNAME=	prtunnel-0.2.0
CATEGORIES=	net
MASTER_SITES=	http://joshbeam.com/files/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://joshbeam.com/software/prtunnel.php
COMMENT=	Tunnels TCP connections through an HTTP or SOCKS5 proxy

BUILD_TARGET=	# defined

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/prtunnel ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/prtunnel.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
