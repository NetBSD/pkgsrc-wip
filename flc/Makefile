# $NetBSD: Makefile,v 1.6 2012/12/04 01:39:02 othyro Exp $
#

DISTNAME=	flc
PKGNAME=	flc-0.1
CATEGORIES=	lang
MASTER_SITES=	ftp://coombs.anu.edu.au/pub/net/firewall/ip-filter/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://coombs.anu.edu.au/~avalon/flc.html
COMMENT=	Filter Language Compiler

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flc ${DESTDIR}${PREFIX}/bin/flc

.include "../../mk/bsd.pkg.mk"
