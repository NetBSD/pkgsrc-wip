# $NetBSD: Makefile,v 1.4 2004/04/17 00:49:15 rillig Exp $

DISTNAME=	same-1.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.bitwizard.nl/same/

MAINTAINER=	roland.illig@gmx.de
HOMEPAGE=	http://www.bitwizard.nl/
COMMENT=	Find identical files and link(2) them to save disk space

MAKEFILE=	${FILESDIR}/Makefile

post-patch:
	@${CP} ${FILESDIR}/same.1 ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
