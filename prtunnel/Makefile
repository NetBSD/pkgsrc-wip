# $NetBSD: Makefile,v 1.1.1.1 2003/08/23 20:03:21 adrian_p Exp $

DISTNAME=	prtunnel-0.2.0
CATEGORIES=	net
MASTER_SITES=	http://joshbeam.com/files/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://joshbeam.com/software/prtunnel.html
COMMENT=	Tunnels TCP connections through an HTTP or SOCKS5 proxy

USE_BUILDLINK2=	YES

do-build:
	cd ${WRKSRC} && make

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/prtunnel ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/prtunnel.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
