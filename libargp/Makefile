# $NetBSD: Makefile,v 1.3 2007/01/24 07:46:55 lkundrak Exp $

DISTNAME=		argp-standalone-1.3
PKGNAME=		libargp-1.3
CATEGORIES=		devel
MASTER_SITES=		http://www.lysator.liu.se/~nisse/misc/

MAINTAINER=		lkundrak@skosi.org
COMMENT=		Standalone version of argument parsing interface from GNU libc

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_LIB}	${WRKSRC}/libargp.a ${PREFIX}/lib
	${INSTALL}	${WRKSRC}/argp.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
