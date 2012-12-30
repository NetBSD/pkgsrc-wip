# $NetBSD: Makefile,v 1.12 2012/12/30 16:01:57 ryo-on Exp $
#

DISTNAME=	luaposix-5.1.23
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}-/}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/downloads/luaposix/luaposix/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://luaforge.net/projects/luaposix/
COMMENT=	POSIX library (including curses) for lua
LICENSE=	mit

DEPENDS+=	${LUA_PKGPREFIX}-BitOp-[0-9]*:../../wip/lua-BitOp

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--libdir=${PREFIX}/${LUA_CDIR}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/${PKGNAME_NOREV}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/${PKGNAME_NOREV}

.include "../../lang/lua/module.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
