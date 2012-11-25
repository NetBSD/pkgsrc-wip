# $NetBSD: Makefile,v 1.5 2012/11/25 23:32:12 othyro Exp $
#

DISTNAME=		flc
PKGNAME=		flc-0.1
CATEGORIES=		lang
MASTER_SITES=		ftp://coombs.anu.edu.au/pub/net/firewall/ip-filter/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://coombs.anu.edu.au/pub/net/firewall/ip-filter/
COMMENT=		Filter Language Compiler

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flc ${DESTDIR}${PREFIX}/bin/flc

.include "../../mk/bsd.pkg.mk"
