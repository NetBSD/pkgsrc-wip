# $NetBSD: Makefile,v 1.1.1.1 2008/01/02 13:37:58 marttikuparinen Exp $

DISTNAME=	shttpd-1.38
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=shttpd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://shttpd.sourceforge.net/
COMMENT=	Lightweight, easy to use web server
#LICENSE=	shttpd-license

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src

BUILD_TARGET=	unix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shttpd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/shttpd.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
