# $NetBSD$

DISTNAME=	ldoc-1.4.6
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=stevedonovan/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stevedonovan.github.io/ldoc/
COMMENT=	LuaDoc-compatible documentation generation system
LICENSE=	mit

MAKE_FLAGS+=	LUA=${LUA_INTERPRETER}
MAKE_FLAGS+=	LUA_BINDIR=${PREFIX}/bin
MAKE_FLAGS+=	LUA_SHAREDIR=${PREFIX}/${LUA_LDIR}
MAKE_FILE=	makefile
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/LDoc-${PKGVERSION_NOREV}

DEPENDS+=	${LUA_PKGPREFIX}-penlight-[0-9]*:../../wip/lua-penlight

.include "../../lang/lua/module.mk"

.include "../../mk/bsd.pkg.mk"
