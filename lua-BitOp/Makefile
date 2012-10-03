# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:44 asau Exp $

PKGNAME=	${DISTNAME:S/Lua/${LUA_PKGPREFIX}-/}
DISTNAME=	LuaBitOp-1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://bitop.luajit.org/download/

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://bitop.luajit.org/download/
COMMENT=	Lua module which adds bitwise operations on numbers
LICENSE=	mit

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FLAGS+=	LUA_CDIR=${LUA_CDIR}
MAKE_FLAGS+=	LUA_INC=${BUILDLINK_PREFIX.lua}/include

INSTALLATION_DIRS+=	${LUA_CDIR}

TEST_TARGET=	test

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
