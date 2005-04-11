# $NetBSD: Makefile,v 1.4 2005/04/11 21:13:56 tvierling Exp $
#

DISTNAME=		luasql-2.0b
PKGNAME=		lua-pgsql-2.0b
CATEGORIES=		wip databases
MASTER_SITES=		http://www.keplerproject.org/luasql/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.keplerproject.org/luasql/
COMMENT=		PostgreSQL bindings for LUA


BUILD_TARGET=		pglinux

do-install:
	${INSTALL_DATA} ${WRKSRC}/libluasqlpostgres.2.0b.so \
		${PREFIX}/lib/libluasqlpostgres.2.0b.so
	${INSTALL_DATA} ${WRKSRC}/libluasqlpostgres.2.0b.a \
		${PREFIX}/lib/libluasqlpostgres.2.0b.a

.include "../../lang/lua/buildlink3.mk"
.include "../../databases/postgresql74-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
