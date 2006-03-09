# $NetBSD: Makefile,v 1.2 2006/03/09 14:54:04 lkundrak Exp $

DISTNAME=		argp-standalone-1.3
PKGNAME=		libargp-1.3
CATEGORIES=		devel
MASTER_SITES=		http://www.lysator.liu.se/~nisse/misc/

MAINTAINER=		lkundrak@skosi.org
COMMENT=		Standalone version of GNU libc's argument parsing interface

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_LIB}	${WRKSRC}/libargp.a ${PREFIX}/lib
	${INSTALL}	${WRKSRC}/argp.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
