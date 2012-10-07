# $NetBSD: Makefile,v 1.2 2012/10/07 15:12:59 asau Exp $

DISTNAME=	shttpd-1.38
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=shttpd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://shttpd.sourceforge.net/
COMMENT=	Lightweight, easy to use web server
#LICENSE=	shttpd-license

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src

BUILD_TARGET=	unix

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shttpd ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/shttpd.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
