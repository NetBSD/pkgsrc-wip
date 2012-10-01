# $NetBSD: Makefile,v 1.5 2012/10/01 22:33:17 asau Exp $

DISTNAME=		argp-standalone-1.3
PKGNAME=		libargp-1.3
CATEGORIES=		devel
MASTER_SITES=		http://www.lysator.liu.se/~nisse/misc/

MAINTAINER=		lkundrak@skosi.org
COMMENT=		Standalone version of argument parsing interface from GNU libc

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	lib include

do-install:
	${INSTALL_DATA}	${WRKSRC}/libargp.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA}	${WRKSRC}/argp.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
