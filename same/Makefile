# $NetBSD: Makefile,v 1.3 2004/02/12 20:59:16 rillig Exp $

DISTNAME=	same-1.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.bitwizard.nl/same/

MAINTAINER=	roland.illig@gmx.de
HOMEPAGE=	http://www.bitwizard.nl/
COMMENT=	Find identical files and link(2) them to save disk space

MAKEFILE=	${FILESDIR}/Makefile

post-patch:
	@${CP} -rP ${FILESDIR}/same.1 ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
