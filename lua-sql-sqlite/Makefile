# $NetBSD: Makefile,v 1.9 2012/11/25 23:32:27 othyro Exp $

GITHUB_PROJECT=	luasql
DISTNAME=	luasql-2.3.2
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/luasql/sql-sqlite/}
CATEGORIES=	databases lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.keplerproject.org/luasql/
COMMENT=	SQLite 2.x bindings for Lua

USE_TOOLS=		gmake
BUILD_TARGET=		sqlite

INSTALLATION_DIRS=	lib
MAKE_FLAGS+=		DRIVER_LIBS_sqlite="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite}/lib -L${BUILDLINK_PREFIX.sqlite}/lib -lsqlite"
MAKE_FLAGS+=		DRIVER_INCS_sqlite=-I${BUILDLINK_PREFIX.sqlite}/includel
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	LUA_LIBDIR=${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
