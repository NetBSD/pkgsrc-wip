# $NetBSD: Makefile,v 1.9 2012/11/25 23:32:27 othyro Exp $

GITHUB_PROJECT=	luasql
DISTNAME=	luasql-2.3.2
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/luasql/sql-mysql/}
CATEGORIES=	databases lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.keplerproject.org/luasql/
COMMENT=	MySQL bindings for Lua

USE_TOOLS=		gmake
BUILD_TARGET=		mysql

INSTALLATION_DIRS=	lib
MAKE_FLAGS+=		DRIVER_LIBS_mysql="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib -L${BUILDLINK_PREFIX.mysql-client}/lib -lmysqlclient"
MAKE_FLAGS+=		DRIVER_INCS_mysql=-I${BUILDLINK_PREFIX.mysql-client}/include/mysql
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	LUA_LIBDIR=${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
