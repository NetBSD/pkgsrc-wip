# $NetBSD: Makefile,v 1.1.1.1 2003/04/06 02:16:27 jeremy-c-reed Exp $

DISTNAME=		byacc-20001120
CATEGORIES=		devel
MASTER_SITES=		ftp://invisible-island.net/byacc/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://dickey.his.com/byacc/byacc.html
COMMENT=		Berkeley Yacc

post-install:
	${INSTALL_MAN} ${WRKSRC}/yacc.1 ${PREFIX}/man/man1/byacc.1

.include "../../mk/bsd.pkg.mk"
