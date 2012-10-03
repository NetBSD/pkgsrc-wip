# $NetBSD: Makefile,v 1.8 2012/10/03 09:03:16 asau Exp $
#

DISTNAME=		luasql-2.0b
PKGNAME=		lua-pgsql-2.0b
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		http://www.keplerproject.org/luasql/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.keplerproject.org/luasql/
COMMENT=		PostgreSQL bindings for LUA


BUILD_TARGET=		pglinux

INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/libluasqlpostgres.2.0b.so \
		${DESTDIR}${PREFIX}/lib/libluasqlpostgres.2.0b.so
	${INSTALL_DATA} ${WRKSRC}/libluasqlpostgres.2.0b.a \
		${DESTDIR}${PREFIX}/lib/libluasqlpostgres.2.0b.a

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
