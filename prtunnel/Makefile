# $NetBSD: Makefile,v 1.4 2004/04/26 14:45:01 adrian_p Exp $

DISTNAME=	prtunnel-0.2.0
CATEGORIES=	net
MASTER_SITES=	http://joshbeam.com/files/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://joshbeam.com/software/prtunnel.html
COMMENT=	Tunnels TCP connections through an HTTP or SOCKS5 proxy

USE_BUILDLINK3=	YES
ALL_TARGET=	# defined

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/prtunnel ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/prtunnel.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
