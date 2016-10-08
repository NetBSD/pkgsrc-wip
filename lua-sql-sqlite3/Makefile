# $NetBSD: Makefile,v 1.9 2012/11/25 23:32:27 othyro Exp $

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/luasql/sql-sqlite3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SQLite 3.x bindings for Lua

BUILD_TARGET=	sqlite3

MAKE_FLAGS+=	DRIVER_LIBS_sqlite="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib -L${BUILDLINK_PREFIX.sqlite3}/lib -lsqlite3"
MAKE_FLAGS+=	DRIVER_INCS_sqlite=-I${BUILDLINK_PREFIX.sqlite3}/includel

.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
