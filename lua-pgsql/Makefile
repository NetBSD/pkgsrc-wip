# $NetBSD: Makefile,v 1.1.1.1 2004/02/26 15:03:07 poppnk Exp $
#

DISTNAME=		luasql-2.0b
PKGNAME=		lua-pgsql-2.0b
CATEGORIES=		wip
MASTER_SITES=		http://www.keplerproject.org/luasql/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.keplerproject.org/luasql/
COMMENT=		PostgreSQL bindings for LUA

USE_BUILDLINK2=		yes

ALL_TARGET=		pglinux

do-install:
	${INSTALL_DATA} ${WRKSRC}/libluasqlpostgres.2.0b.so \
		${PREFIX}/lib/libluasqlpostgres.2.0b.so
	${INSTALL_DATA} ${WRKSRC}/libluasqlpostgres.2.0b.a \
		${PREFIX}/lib/libluasqlpostgres.2.0b.a

.include "../../lang/lua/buildlink2.mk"
.include "../../wip/postgresql74-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
