# $NetBSD: Makefile,v 1.1.1.1 2004/04/23 09:03:30 poppnk Exp $
#

DISTNAME=		flc
CATEGORIES=		wip
MASTER_SITES=		ftp://coombs.anu.edu.au/pub/net/firewall/ip-filter/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		ftp://coombs.anu.edu.au/pub/net/firewall/ip-filter/
COMMENT=		Filter Language Compiler

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flc ${PREFIX}/bin/flc

.include "../../mk/bsd.pkg.mk"
