# $NetBSD: Makefile,v 1.4 2012/09/28 22:34:30 asau Exp $
#

DISTNAME=		flc
PKGNAME=		flc-0.1
CATEGORIES=		lang
MASTER_SITES=		ftp://coombs.anu.edu.au/pub/net/firewall/ip-filter/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		ftp://coombs.anu.edu.au/pub/net/firewall/ip-filter/
COMMENT=		Filter Language Compiler

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flc ${DESTDIR}${PREFIX}/bin/flc

.include "../../mk/bsd.pkg.mk"
