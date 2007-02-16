# $NetBSD: Makefile,v 1.4 2007/02/16 12:13:13 lkundrak Exp $

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
	${INSTALL_DATA}	${WRKSRC}/libargp.a ${PREFIX}/lib
	${INSTALL_DATA}	${WRKSRC}/argp.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
