# $NetBSD: Makefile,v 1.9 2012/11/25 23:32:27 othyro Exp $

GITHUB_PROJECT=	luasql
DISTNAME=	luasql-2.3.2
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/luasql/sql-postgres/}
CATEGORIES=	databases lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

#https://github.com/keplerproject/luasql/archive/v2.3.2.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.keplerproject.org/luasql/
COMMENT=	PostgreSQL bindings for Lua

USE_TOOLS=		gmake
BUILD_TARGET=		postgres

INSTALLATION_DIRS=	lib
MAKE_FLAGS+=		DRIVER_LIBS_postgres="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib -L${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib"
MAKE_FLAGS+=		DRIVER_INCS_postgres=-I${BUILDLINK_PREFIX.${PGSQL_TYPE}}/include
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	LUA_LIBDIR=${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
